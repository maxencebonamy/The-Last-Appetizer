#pragma once

#include "../../ihm/ihm.h"
#include "../players.h"
#include "../actions.h"
#include "../scores.h"
#include <stdio.h>


void SCORE_SCREEN_Init(void);

void SCORE_SCREEN_Update(void);

void SCORE_SCREEN_Display(void);

bool_e SCORE_SCREEN_NextScreen(void);

static void SCORE_SCREEN_DrawPlayerScore(uint16_t y, uint8_t player, uint16_t color);