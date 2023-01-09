#include "end_screen.h"


static IHM_Rect nextButton = { 40, 140, 280, 200 };

static bool_e nextScreen = FALSE;


void END_SCREEN_Init(void) {
    nextScreen = FALSE;
    END_SCREEN_Display();
}

void END_SCREEN_Update(void) {
    if (IHM_IsClicking() && IHM_Collide(&nextButton)) {
        nextScreen = TRUE;
    }
}

void END_SCREEN_Display(void) {
    IHM_Fill(IHM_COLOR_BLACK);

    char message[21];
    sprintf(message, "BRAVO AU\nJOUEUR %d !", SCORES_GetWinner());

    IHM_Write(20, 40, 300, 120, message, IHM_COLOR_WHITE, IHM_COLOR_BLACK);
    IHM_DisplayButton(&nextButton, "Rejouer", IHM_COLOR_BLUE);
}

bool_e END_SCREEN_NextScreen(void) {
    return nextScreen;
}