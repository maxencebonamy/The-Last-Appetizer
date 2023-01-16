#include "arrow_test.h"


void TEST_ARROW_Turn(void) {
	IHM_Init();

	IHM_Rect left = { 20, 20, 150, 110 };
	IHM_Rect right = { 170, 20, 300, 110 };
	IHM_Rect stop = { 20, 130, 300, 220 };

	IHM_DisplayButton(&left, "LEFT", IHM_COLOR_BLUE);
	IHM_DisplayButton(&right, "RIGHT", IHM_COLOR_PURPLE_1);
	IHM_DisplayButton(&stop, "STOP", IHM_COLOR_RED);

	ARROW_Turn(0);

    while (TRUE) {
    	IHM_Update();

    	if (IHM_IsClicking()) {
    		if (IHM_Collide(&left)) {
    			ARROW_Turn(100);
    		}
    		else if (IHM_Collide(&right)) {
				ARROW_Turn(-100);
			}
    		else if (IHM_Collide(&stop)) {
				ARROW_Turn(0);
			}
    	}
    }
}

void TEST_ARROW_GetAngle(void) {
    IHM_Init();

    IHM_Fill(IHM_COLOR_WHITE);
    GAME_BOARD_Display();

    while (TRUE) {
        ARROW_Update();
        GAME_BOARD_SetArrowAngle(ARROW_GetAngle());

        IHM_Update();
    }
}
