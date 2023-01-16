#pragma once

#include "screen_tests.h"
#include "utils_tests.h"
#include "arrow_test.h"


typedef enum {
	NONE = 0,
	SCREEN_WRITE_TEXT,
	SCREEN_DRAW_SHAPES,
	SCREEN_BUTTON_CLICK,
    SCREEN_GAME_BOARD,
    UTILS_GENERATE_RANDOM_NUMBERS,
    ARROW_TURN,
	ARROW_GET_ANGLE
} Test;


static Test currentTest = ARROW_TURN;


void TEST_DoAll(void);
