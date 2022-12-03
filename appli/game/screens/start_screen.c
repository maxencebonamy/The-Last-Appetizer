#include "start_screen.h"

static IHM_Rect previousButton = { 10, 10, 60, 60 };
static IHM_Rect nextButton = { 20, 150, 300, 210 };

static bool_e previousScreen = FALSE;
static bool_e nextScreen = FALSE;


void START_SCREEN_Init(void) {
	previousScreen = FALSE;
	nextScreen = FALSE;
	START_SCREEN_Display();
}

void START_SCREEN_Update(void) {
	IHM_Update();

    if (IHM_IsClicking()) {
        if (IHM_Collide(&previousButton)) {
            previousScreen = TRUE;
        }
        else if (IHM_Collide(&nextButton)) {
            nextScreen = TRUE;
        }
    }
}

void START_SCREEN_Display(void) {
	IHM_Fill(IHM_COLOR_WHITE);

    IHM_DisplayButton(&previousButton, "<", IHM_COLOR_RED);
    IHM_DrawRoundedRectangle(70, 10, 310, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
    IHM_Write(70, 10, 310, 60, "LANCEMENT", IHM_COLOR_RED, IHM_COLOR_WHITE);

    IHM_Write(20, 90, 300, 130, "Etes-vous prets ?", IHM_COLOR_BLACK, IHM_COLOR_WHITE);
    IHM_DisplayButton(&nextButton, "LANCER LA PARTIE", IHM_COLOR_BLUE);
}

bool_e START_SCREEN_PreviousScreen(void) {
	return previousScreen;
}

bool_e START_SCREEN_NextScreen(void) {
	return nextScreen;
}
