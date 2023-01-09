#include "arrow.h"
#include "stm32f1_adc.h"


static uint16_t angle = 0;


void ARROW_Turn(void) {
    PWM_run(TIMER1_ID, TIM_CHANNEL_1, FALSE, 1000, 50, FALSE);  // PA 8
    //  PWM_run(TIMER1_ID, TIM_CHANNEL_2, FALSE, 200, 0, FALSE);  // PA 9
}

uint16_t ARROW_Update(void) {
    uint16_t value = ADC_getValue(ADC_CHANNEL_1);
    if (value > 3800) {
        angle++;
    }
}

uint16_t ARROW_GetAngle(void) {
    return angle;
}
