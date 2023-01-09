#include "selection_screen.h"

static IHM_Rect previousButton = { 10, 10, 60, 60 };
static IHM_Rect nextButton = { 260, 10, 310, 60 };

static uint8_t currentPlayer = 0;

static bool_e previousScreen = FALSE;
static bool_e nextScreen = FALSE;


void SELECTION_SCREEN_Init(void) {
	previousScreen = FALSE;
	nextScreen = FALSE;
	SELECTION_SCREEN_Display();
}

void SELECTION_SCREEN_Update(void) {
	if (IHM_IsClicking()) {
		if (IHM_Collide(&previousButton)) {
			if (currentPlayer == 0) {
                GAME_BOARD_SetArrowRotationSpeed(0);
				previousScreen = TRUE;
			}
			else {
				--currentPlayer;
				SELECTION_SCREEN_Display();
			}
		}
		else if (IHM_Collide(&nextButton)) {
			if (currentPlayer == PLAYERS_GetCount()) {
                GAME_BOARD_SetArrowRotationSpeed(0);
				nextScreen = TRUE;
			}
			else {
				++currentPlayer;
				SELECTION_SCREEN_Display();
			}
		}
	}
}

void SELECTION_SCREEN_Display(void) {
	IHM_Fill(IHM_COLOR_WHITE);

    char title[9] = "REGLAGE";
    char instruction[45] = "Orientez \nla fl}che\nvers     \nl'{cran. ";
    if (currentPlayer) {
        sprintf(title, "JOUEUR %d", currentPlayer);
        sprintf(instruction, "Orientez \nla fl}che\nvers le  \njoueur %d.", currentPlayer);
    }

	IHM_DrawRoundedRectangle(70, 10, 250, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
	IHM_Write(70, 10, 250, 60, title, IHM_COLOR_RED, IHM_COLOR_WHITE);

    GAME_BOARD_SetCenterPosition(80, 150);
    GAME_BOARD_SetPlayerPointed(currentPlayer ? currentPlayer - 1 : 0);
    GAME_BOARD_SetArrowRotationSpeed(currentPlayer ? 0 : 0.2);
    GAME_BOARD_Display();
	IHM_Write(160, 70, 310, 230, instruction, IHM_COLOR_BLACK, IHM_COLOR_WHITE);

	IHM_DisplayButton(&previousButton, "<", IHM_COLOR_RED);
	IHM_DisplayButton(&nextButton, ">", IHM_COLOR_RED);
}

bool_e SELECTION_SCREEN_PreviousScreen(void) {
	return previousScreen;
}

bool_e SELECTION_SCREEN_NextScreen(void) {
	return nextScreen;
}
