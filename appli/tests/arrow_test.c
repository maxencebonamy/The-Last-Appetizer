/**
 * @brief Gestion des tests liés à la flèche (moteur et codeur incrémental)
 * @author Maxence & Aymeric
 */


#include "arrow_test.h"

#include "../arrow/arrow.h"
#include "../ihm/game_board.h"
#include <stdio.h>


void TEST_ARROW_Turn(void) {
	IHM_Init();
	ARROW_Init();

	IHM_Rect start = { 20, 20, 300, 110 };
	IHM_Rect stop = { 20, 130, 300, 220 };

	IHM_DisplayButton(&start, "START", IHM_COLOR_BLUE);
	IHM_DisplayButton(&stop, "STOP", IHM_COLOR_RED);

	ARROW_Turn(0);

    while (TRUE) {
    	IHM_Update();

    	if (IHM_IsClicking()) {
    		if (IHM_Collide(&start)) {
    			ARROW_Turn(70);
    		}
    		else if (IHM_Collide(&stop)) {
				ARROW_Turn(0);
			}
    	}
    }
}

void TEST_ARROW_GetAngle(void) {
    IHM_Init();
    ARROW_Init();

    IHM_Fill(IHM_COLOR_WHITE);
    GAME_BOARD_Display();
    ARROW_Turn(50);

    while (TRUE) {
        GAME_BOARD_SetArrowAngle(ARROW_GetAngle());

        IHM_Update();
    }
}

void TEST_ARROW_TurnUntil(void) {
    IHM_Init();
    ARROW_Init();

    IHM_Fill(IHM_COLOR_WHITE);

    IHM_Rect button0 = { 20, 20, 150, 110 };
    IHM_Rect button90 = { 170, 20, 300, 110 };
    IHM_Rect button180 = { 20, 130, 150, 220 };
    IHM_Rect button270 = { 170, 130, 300, 220 };

    IHM_DisplayButton(&button0, "0 deg", IHM_COLOR_PURPLE_1);
	IHM_DisplayButton(&button90, "90 deg", IHM_COLOR_PURPLE_2);
	IHM_DisplayButton(&button180, "180 deg", IHM_COLOR_PURPLE_3);
	IHM_DisplayButton(&button270, "270 deg", IHM_COLOR_BLUE);

    while (TRUE) {
        IHM_Update();

        if (ARROW_IsAtDestination() && IHM_IsClicking()) {
        	if (IHM_Collide(&button0)) {
        		ARROW_TurnUntil(0, 1);
        	}
        	else if (IHM_Collide(&button90)) {
				ARROW_TurnUntil(90, 1);
			}
        	else if (IHM_Collide(&button180)) {
				ARROW_TurnUntil(180, 1);
			}
        	else if (IHM_Collide(&button270)) {
				ARROW_TurnUntil(270, 1);
			}
        }
    }
}
