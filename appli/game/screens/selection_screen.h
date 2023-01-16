#pragma once

#include "../../ihm/game_board.h"
#include "../players.h"
#include "../../arrow/arrow.h"
#include <stdio.h>

void SELECTION_SCREEN_Init(void);
void SELECTION_SCREEN_Update(void);
void SELECTION_SCREEN_Display(void);

bool_e SELECTION_SCREEN_PreviousScreen(void);
bool_e SELECTION_SCREEN_NextScreen(void);
