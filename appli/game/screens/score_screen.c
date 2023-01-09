#include "score_screen.h"


static IHM_Rect nextButton = { 260, 10, 310, 60 };

static bool_e nextScreen = FALSE;


void SCORE_SCREEN_Init(void) {
    nextScreen = FALSE;
    SCORE_SCREEN_Display();
}

void SCORE_SCREEN_Update(void) {
    if (IHM_IsClicking() && IHM_Collide(&nextButton)) {
        nextScreen = TRUE;
    }
}

void SCORE_SCREEN_Display(void) {
    IHM_Fill(IHM_COLOR_WHITE);

    IHM_DrawRoundedRectangle(10, 10, 250, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
    IHM_Write(10, 10, 250, 60, "SCORES", IHM_COLOR_RED, IHM_COLOR_WHITE);

    IHM_DisplayButton(&nextButton, ">", IHM_COLOR_RED);

    SCORE_SCREEN_DrawPlayerScore(80, SCORES_GetPlayerByRank(0), IHM_COLOR_PURPLE_3);
    SCORE_SCREEN_DrawPlayerScore(130, SCORES_GetPlayerByRank(1), IHM_COLOR_PURPLE_2);
    SCORE_SCREEN_DrawPlayerScore(180, SCORES_GetPlayerByRank(2), IHM_COLOR_PURPLE_1);
}

bool_e SCORE_SCREEN_NextScreen(void) {
    return nextScreen;
}

static void SCORE_SCREEN_DrawPlayerScore(uint16_t y, uint8_t player, uint16_t color) {
    char playerString[9];
    sprintf(playerString, "Joueur %d", player);

    char scoreString[8];
    uint8_t score = SCORES_Get(player);
    sprintf(scoreString, score < 10 ? " %d" : "%d", score);

    IHM_DrawFilledRoundedRectangle(10, y, 310, y + 40, color, 20);
    IHM_Write(20, y, 20 + 16*8, y + 40, playerString, IHM_COLOR_WHITE, color);
    IHM_Write(300 - 16*2, y, 300, y + 40, scoreString, IHM_COLOR_WHITE, color);
}