#include "action_screen.h"

static IHM_Rect cancelButton = { 10, 180, 155, 230 };
static IHM_Rect validateButton = { 165, 180, 310, 230 };

static bool_e nextScreen = FALSE;

static bool_e isHidden = TRUE;
static IHM_Rect showButton = { 260, 10, 310, 60 };


void ACTION_SCREEN_Init(void) {
    nextScreen = FALSE;
    isHidden = ACTIONS_GetCurrent()->hidden;
    PLAYERS_ChooseRandom();
    ACTION_SCREEN_Display();
}

void ACTION_SCREEN_Update(void) {
    if (IHM_IsClicking()) {
        if (isHidden) {
            if (IHM_Collide(&showButton)) {
                isHidden = FALSE;
                ACTION_SCREEN_Display();
            }
        }
        else {
            if (IHM_Collide(&cancelButton)) {
                nextScreen = TRUE;
            }
            else if (IHM_Collide(&validateButton)) {
                SCORES_Add(PLAYERS_GetCurrent(), ACTIONS_GetCurrent()->score);
                nextScreen = TRUE;
            }
        }
    }
}

void ACTION_SCREEN_Display(void) {
    IHM_Fill(IHM_COLOR_WHITE);

    char title[9];
    sprintf(title, "JOUEUR %d", PLAYERS_GetCurrent());

    IHM_DrawRoundedRectangle(10, 10, isHidden ? 240 : 200, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
    IHM_Write(10, 10, isHidden ? 240 : 200, 60, title, IHM_COLOR_RED, IHM_COLOR_WHITE);

    if (isHidden) {
        IHM_DisplayButton(&showButton, ">", IHM_COLOR_RED);

        IHM_DrawFilledRoundedRectangle(10, 70, 310, 230, IHM_COLOR_PURPLE_2, 25);
        IHM_Write(10, 70, 310, 230, "ATTENTION\n\nTu dois être\nle seul à\nvoir l'action !", IHM_COLOR_WHITE, IHM_COLOR_PURPLE_2);
    }
    else {
        char points[6];
        sprintf(points, ACTIONS_GetCurrent()->score > 1 ? "%d pts" : "%d pt", ACTIONS_GetCurrent()->score);

        IHM_DrawFilledRoundedRectangle(210, 10, 310, 60, IHM_COLOR_RED, 25);
        IHM_Write(210, 10, 310, 60, points, IHM_COLOR_WHITE, IHM_COLOR_RED);

        IHM_DrawFilledRoundedRectangle(10, 70, 310, 170, IHM_COLOR_PURPLE_3, 25);
        IHM_Write(10, 70, 310, 170, ACTIONS_GetCurrent()->description, IHM_COLOR_WHITE, IHM_COLOR_PURPLE_3);

        IHM_DisplayButton(&cancelButton, "Refusé", IHM_COLOR_RED);
        IHM_DisplayButton(&validateButton, "Validé", IHM_COLOR_BLUE);
    }
}

bool_e ACTION_SCREEN_NextScreen(void) {
    return nextScreen;
}
