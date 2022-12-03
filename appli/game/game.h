#pragma once

#include "../ihm/ihm.h"
#include "screens/home_screen.h"
#include "screens/options_screen.h"
#include "screens/selection_screen.h"
#include "screens/start_screen.h"

typedef enum {
	HOME = 0,
	OPTIONS,
	SELECTION,
	START,
	ARROW,
	ACTION,
	SCORE,
	END
} State;

void GAME_Init(void);
void GAME_Update(void);
