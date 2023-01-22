/**
 * @brief Gestion de la partie
 * @author Maxence & Aymeric
 */

#include "game.h"


static State home =         { &HOME_SCREEN_Init,        &HOME_SCREEN_Update,        HOME };
static State options =      { &OPTIONS_SCREEN_Init,     &OPTIONS_SCREEN_Update,     OPTIONS };
static State selection =    { &SELECTION_SCREEN_Init,   &SELECTION_SCREEN_Update,   SELECTION };
static State start =        { &START_SCREEN_Init,       &START_SCREEN_Update,       START };
static State arrow =        { &ARROW_SCREEN_Init,       &ARROW_SCREEN_Update,       ARROW };
static State action =       { &ACTION_SCREEN_Init,      &ACTION_SCREEN_Update,      ACTION };
static State score =        { &SCORE_SCREEN_Init,       &SCORE_SCREEN_Update,       SCORE };
static State end =          { &END_SCREEN_Init,         &END_SCREEN_Update,         END };

/// État actuel de la machine à états
static State* currentState = &home;
/// Variable qui va permettre d'effectuer l'action d'initialisation d'un état une seule fois
static bool_e hasBeenInit = FALSE;


static void GAME_ChangeState(State* newState) {
    currentState = newState;
    hasBeenInit = FALSE;
}


void GAME_Init(void) {
	IHM_Init();
    ARROW_Init();
}

void GAME_Update(void) {
    IHM_Update();

    if (!hasBeenInit) {
        (*currentState->initFunction)();
        hasBeenInit = TRUE;
    }

    (*currentState->updateFunction)();

	switch (currentState->state) {

	case HOME:
		if (HOME_SCREEN_NextScreen())               GAME_ChangeState(&options);

	case OPTIONS:
		if (OPTIONS_SCREEN_NextScreen())            GAME_ChangeState(&selection);
		else if (OPTIONS_SCREEN_PreviousScreen())   GAME_ChangeState(&home);

	case SELECTION:
		if (SELECTION_SCREEN_NextScreen())          GAME_ChangeState(&start);
        else if (SELECTION_SCREEN_PreviousScreen()) GAME_ChangeState(&options);

    case START:
        if (START_SCREEN_NextScreen())              GAME_ChangeState(&arrow);
        else if (START_SCREEN_PreviousScreen())     GAME_ChangeState(&selection);

    case ARROW:
        if (ARROW_SCREEN_NextScreen())              GAME_ChangeState(&action);

    case ACTION:
        if (ACTION_SCREEN_NextScreen())             GAME_ChangeState(&score);

    case SCORE:
         if (SCORE_SCREEN_NextScreen())              GAME_ChangeState(SCORES_IsMaximumReached() ? &end : &arrow);

    case END:
        if (END_SCREEN_NextScreen())                GAME_ChangeState(&options);

	}
}
