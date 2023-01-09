#include "arrow_screen.h"


static bool_e nextScreen = FALSE;


void ARROW_SCREEN_Init(void) {
    nextScreen = FALSE;
    ARROW_SCREEN_Display();
    ACTIONS_ChooseRandom();
}

void ARROW_SCREEN_Update(void) {
    if (IHM_IsClicking()) {
        GAME_BOARD_SetArrowRotationSpeed(0);
        nextScreen = TRUE;
    }
}

void ARROW_SCREEN_Display(void) {
    IHM_Fill(IHM_COLOR_WHITE);

    IHM_DrawRoundedRectangle(10, 10, 310, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
    IHM_Write(10, 10, 310, 60, "ATTENTION", IHM_COLOR_RED, IHM_COLOR_WHITE);

    GAME_BOARD_SetCenterPosition(160, 150);
    GAME_BOARD_SetPlayerPointed(0);
    GAME_BOARD_SetArrowRotationSpeed(0.2);
    GAME_BOARD_Display();
}

bool_e ARROW_SCREEN_NextScreen(void) {
    return nextScreen;
}
