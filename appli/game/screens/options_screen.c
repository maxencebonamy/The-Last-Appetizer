#include "options_screen.h"

static IHM_Rect previousButton = { 10, 10, 60, 60 };
static IHM_Rect nextButton = { 260, 10, 310, 60 };

static IHM_Rect modeButton = { 160, 90, 310, 140 };
static IHM_Rect removeButton = { 160, 160, 210, 210 };
static IHM_Rect addButton = { 260, 160, 310, 210 };

static bool_e previousScreen = FALSE;
static bool_e nextScreen = FALSE;


void OPTIONS_SCREEN_Init(void) {
	previousScreen = FALSE;
	nextScreen = FALSE;
	OPTIONS_SCREEN_Display();
}

void OPTIONS_SCREEN_Update(void) {
	IHM_Update();

	if (IHM_IsClicking()) {
		if (IHM_Collide(&removeButton)) {
			PLAYERS_Remove();
			OPTIONS_SCREEN_DisplayPlayerCount();
		}
		else if (IHM_Collide(&addButton)) {
			PLAYERS_Add();
			OPTIONS_SCREEN_DisplayPlayerCount();
		}
		else if (IHM_Collide(&modeButton)) {
			MODE_Change();
			OPTIONS_SCREEN_DisplayModeButton();
		}
		else if (IHM_Collide(&previousButton)) {
			previousScreen = TRUE;
		}
		else if (IHM_Collide(&nextButton)) {
			nextScreen = TRUE;
		}
	}
}

void OPTIONS_SCREEN_Display(void) {
	IHM_Fill(IHM_COLOR_WHITE);

	IHM_DrawRoundedRectangle(70, 10, 250, 60, IHM_COLOR_WHITE, IHM_COLOR_RED, 25);
	IHM_Write(70, 10, 250, 60, "OPTIONS", IHM_COLOR_RED, IHM_COLOR_WHITE);

	IHM_DisplayButton(&previousButton, "<", IHM_COLOR_RED);
	IHM_DisplayButton(&nextButton, ">", IHM_COLOR_RED);

	IHM_Write(10, 90, 150, 140, "Mode:   ", IHM_COLOR_BLACK, IHM_COLOR_WHITE);
	OPTIONS_SCREEN_DisplayModeButton();

	IHM_Write(10, 160, 150, 210, "Joueurs:", IHM_COLOR_BLACK, IHM_COLOR_WHITE);
	IHM_DisplayButton(&removeButton, "-", IHM_COLOR_BLUE);
	OPTIONS_SCREEN_DisplayPlayerCount();
	IHM_DisplayButton(&addButton, "+", IHM_COLOR_BLUE);
}

bool_e OPTIONS_SCREEN_PreviousScreen(void) {
	return previousScreen;
}

bool_e OPTIONS_SCREEN_NextScreen(void) {
	return nextScreen;
}

static void OPTIONS_SCREEN_DisplayModeButton(void) {
	IHM_DisplayButton(&modeButton, MODE_ToString(), IHM_COLOR_BLUE);
}

static void OPTIONS_SCREEN_DisplayPlayerCount(void) {
	IHM_DrawFilledRectangle(215, 160, 255, 210, IHM_COLOR_WHITE);
	char playerCountString[2];
	sprintf(playerCountString, "%d", PLAYERS_Get());
	IHM_Write(215, 160, 255, 210, playerCountString, IHM_COLOR_BLACK, IHM_COLOR_WHITE);
}
