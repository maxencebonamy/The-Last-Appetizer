/**
 * @brief Gestion de la flèche (moteur et codeur incrémental)
 * @author Maxence & Aymeric
 */


#include "arrow.h"
#include "stm32f1_adc.h"
#include "stm32f1_motorDC.h"
#include "systick.h"


/// Angle actuel de la flèche
static double_t angle = 0;
/// Booléen permettant de savoir si la valeur du codeur incrémental a été modifiée ou non
static bool_e trigger = FALSE;
/// Valeur de l'angle entre deux trous consécutifs du codeur incrémental
static double_t delta = 2.f;

/// Angle correspondant à la destination de la flèche lorsqu'une rotation a été lancée
static double_t destination = 0;
/// Nombre de tours restants à effectuer lors d'une rotation
static uint8_t nbRemainingLaps = 0;

static motor_id_e motor;


static void ARROW_Update(void);

static void ARROW_Update(void) {
    // On capte la valeur analogique du codeur incrémental
    uint16_t value = ADC_getValue(ADC_CHANNEL_1);

    // Le codeur incrémental est sur un trou lorsque la valeur analogique est proche de 0
    if (value < 4095.f / 2.f && !trigger) {
        angle += delta;
        if (angle >= 360.f) {
            angle -= 360.f;
        }
        else if (angle < 0.f) {
            angle += 360.f;
        }
        trigger = TRUE;
    }
    // Inversement, le codeur incrémental n'est pas sur un trou lorsque la valeur analogique est proche de 4095
    else if (value >= 4095.f / 2.f && trigger) {
        trigger = FALSE;
    }

    // Lorsque qu'une rotation a été lancée, on vérifie si la flèche est arrivée à destination
    if (nbRemainingLaps) {
        if (angle - delta / 2.f <= destination <= angle + delta / 2.f && !--nbRemainingLaps) {
            ARROW_Turn(0);
        }
    }
}

void ARROW_Turn(int8_t power) {
    MOTOR_set_duty(motor, power);
    //PWM_run(TIMER1_ID, TIM_CHANNEL_1, FALSE, 1000, power, FALSE);
}

void ARROW_Init(void) {
    // Initialisation de l'ADC (Convertisseur analogique vers numérique)
    ADC_init();
    motor = MOTOR_add(GPIOA, GPIO_PIN_8, GPIOB, GPIO_PIN_13);
    // Ajout de la fonction update aux fonctions appelées toutes les ms
    Systick_add_callback_function(&ARROW_Update);
}

double_t ARROW_GetAngle(void) {
    return angle;
}

void ARROW_Reset(void) {
    angle = 0;
}

void ARROW_TurnUntil(double_t angle, uint8_t nbLaps) {
    nbRemainingLaps = nbLaps;
    destination = angle;
    ARROW_Turn(40);
}

bool_e ARROW_IsAtDestination(void) {
    return !nbRemainingLaps;
}
