#pragma once

#include "stm32f1_pwm.h"
#include "stm32f1_timer.h"
#include "macro_types.h"


void ARROW_Turn(void);

uint16_t ARROW_Update(void);

uint16_t ARROW_GetAngle(void);