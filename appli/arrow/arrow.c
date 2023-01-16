#include "arrow.h"
#include "stm32f1_adc.h"


static double_t angle = 0;
static bool_e trigger = FALSE;
static double_t delta = 5.4f;

static double_t destination = 0;
static bool_e isAtDestination = TRUE;

static uint16_t values[1000];
static uint16_t index = 0;


void ARROW_Turn(int8_t power) {
    PWM_run(TIMER1_ID, TIM_CHANNEL_1, FALSE, 1000, power > 0 ? power : 0, FALSE);   // PA 8
    PWM_run(TIMER1_ID, TIM_CHANNEL_2, FALSE, 1000, power < 0 ? -power : 0, FALSE);  // PA 9
}

void ARROW_Update(void) {
    uint16_t value = ADC_getValue(ADC_CHANNEL_1);
    values[index++] = value;
    if (value < 2000 && !trigger) {
        angle += delta;
        if (angle >= 360.f) {
            angle -= 360.f;
        }
        else if (angle < 0.f) {
            angle += 360.f;
        }
        trigger = TRUE;
    }
    else if (value >= 2000 && trigger) {
    	trigger = FALSE;
    }

    if (!isAtDestination) {
        if (angle - delta / 2.f <= destination <= angle + delta / 2.f && !RANDOM_Get(0, 3)) {
            isAtDestination = TRUE;
            ARROW_Turn(0);
        }
    }
}

double_t ARROW_GetAngle(void) {
    return angle;
}

void ARROW_Reset(void) {
    angle = 0;
}

void ARROW_TurnUntil(double_t angle) {
    isAtDestination = FALSE;
    destination = angle;
    ARROW_Turn(50);
}

bool_e ARROW_IsAtDestination(void) {
    return isAtDestination;
}