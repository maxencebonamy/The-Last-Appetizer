#include "screen_tests.h"


void TEST_SCREEN_WriteText(void) {
    IHM_Init();
    IHM_Fill(IHM_COLOR_WHITE);
    IHM_Write(20, 20, 300, 220, "Ce texte est\ncentré sur\nplusieurs lignes\net contient\ndes accents !",
              IHM_COLOR_BLACK, IHM_COLOR_WHITE);
    while (TRUE) {}
}

void TEST_SCREEN_DrawShapes(void) {
    IHM_Init();
    IHM_Fill(IHM_COLOR_WHITE);
    IHM_DrawRoundedRectangle(10, 10, 310, 60, IHM_COLOR_RED, IHM_COLOR_WHITE, 25);
    IHM_DrawFilledRoundedRectangle(10, 70, 310, 150, IHM_COLOR_PURPLE_1, 25);
    IHM_DrawLine(10, 160, 310, 230, IHM_COLOR_BLUE, 5);
    while (TRUE) {}
}

void TEST_SCREEN_ButtonClick(void) {
    IHM_Init();

    IHM_Fill(IHM_COLOR_WHITE);

    IHM_Rect button = {40, 90, 280, 150};
    IHM_DisplayButton(&button, "Clique ici !", IHM_COLOR_RED);

    while (TRUE) {
    	IHM_Update();
        if (IHM_IsClicking() && IHM_Collide(&button)) {
            IHM_Fill(IHM_COLOR_WHITE);
            IHM_Write(40, 90, 280, 150, "Bravo !", IHM_COLOR_BLUE, IHM_COLOR_WHITE);
        }
    }
}

void TEST_SCREEN_GameBoard(void) {
    IHM_Init();

    while (PLAYERS_GetCount() < 6) {
    	PLAYERS_Add();
    }

    GAME_BOARD_SetCenterPosition(160, 120);
    GAME_BOARD_SetPlayerPointed(0);
    GAME_BOARD_SetArrowRotationSpeed(0.2);
    GAME_BOARD_Display();

    while (TRUE) {
        IHM_Update();
        GAME_BOARD_Update();
    }
}
