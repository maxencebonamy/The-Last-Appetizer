/**
 * @brief Gestion de la partie
 * @author Maxence & Aymeric
 */

#include "game.h"


/// État actuel de la machine à états
static State state = OPTIONS;
/// Variable qui va permettre d'effectuer l'action d'initialisation d'un état une seule fois
static bool_e hasBeenInit = FALSE;

void GAME_Init(void) {
	IHM_Init();
}

void GAME_Update(void) {
	switch (state) {

	case HOME:
		if (!hasBeenInit) {
			HOME_SCREEN_Init();
			hasBeenInit = TRUE;
		}

		HOME_SCREEN_Update();

		if (HOME_SCREEN_NextScreen()) {
			state = OPTIONS;
			hasBeenInit = FALSE;
		}

		break;

	case OPTIONS:
		if (!hasBeenInit) {
			OPTIONS_SCREEN_Init();
			hasBeenInit = TRUE;
		}

		OPTIONS_SCREEN_Update();

		if (OPTIONS_SCREEN_NextScreen()) {
			state = SELECTION;
			hasBeenInit = FALSE;
		}
		else if (OPTIONS_SCREEN_PreviousScreen()) {
			state = HOME;
			hasBeenInit = FALSE;
		}

		break;

	case SELECTION:
		if (!hasBeenInit) {
			SELECTION_SCREEN_Init();
			hasBeenInit = TRUE;
		}

		SELECTION_SCREEN_Update();

		if (SELECTION_SCREEN_NextScreen()) {
			state = START;
			hasBeenInit = FALSE;
		}
        else if (SELECTION_SCREEN_PreviousScreen()) {
            state = OPTIONS;
            hasBeenInit = FALSE;
        }

		break;

    case START:
        if (!hasBeenInit) {
            START_SCREEN_Init();
            hasBeenInit = TRUE;
        }

        START_SCREEN_Update();

        if (START_SCREEN_PreviousScreen()) {
            state = OPTIONS;
            hasBeenInit = FALSE;
        }

        break;

	default:
		break;

	}
}
