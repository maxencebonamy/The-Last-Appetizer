#include "tests.h"


void TEST_DoAll(void) {

	switch (currentTest) {
        case NONE:
            break;
		case SCREEN_WRITE_TEXT:
			TEST_SCREEN_WriteText();
		case SCREEN_DRAW_SHAPES:
			TEST_SCREEN_DrawShapes();
		case SCREEN_BUTTON_CLICK:
			TEST_SCREEN_ButtonClick();
        case SCREEN_GAME_BOARD:
            TEST_SCREEN_GameBoard();
        case UTILS_GENERATE_RANDOM_NUMBERS:
            TEST_UTILS_GenerateRandomNumbers();
        case ARROW_TURN:
        	TEST_ARROW_Turn();
        case ARROW_GET_ANGLE:
        	TEST_ARROW_GetAngle();
	}

}
