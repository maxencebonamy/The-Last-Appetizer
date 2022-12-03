#include "home_screen.h"

static IHM_Rect playButton = { 85, 140, 235, 190 };

static bool_e nextScreen = FALSE;


void HOME_SCREEN_Init() {
	nextScreen = FALSE;
	HOME_SCREEN_Display();
}

void HOME_SCREEN_Update() {
	IHM_Update();

	if (IHM_IsClicking() && IHM_Collide(&playButton)) {
		nextScreen = TRUE;
	}
}

void HOME_SCREEN_Display() {
	IHM_Fill(IHM_COLOR_BLACK);
	IHM_Write(30, 40, 290, 120, "THE LAST\nAPPETIZER", IHM_COLOR_WHITE, IHM_COLOR_BLACK);
	IHM_DisplayButton(&playButton, "Jouer", IHM_COLOR_BLUE);
}

bool_e HOME_SCREEN_NextScreen() {
	return nextScreen;
}
