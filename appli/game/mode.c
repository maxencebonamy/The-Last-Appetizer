/**
 * @brief Gestion du mode de jeu
 * @author Maxence & Aymeric
 */

#include "mode.h"


/// Mode actuellement selectionné
static Mode mode = FAMILLE;

Mode MODE_Get(void) {
	return mode;
}

void MODE_Change(void) {
    // retour au premier si le mode actuel est le dernier
    switch (mode) {
        case FAMILLE:
            mode = APERO;
            break;
        case APERO:
            mode = HARD;
            break;
        case HARD:
            mode = FAMILLE;
            break;
    }
}

char* MODE_ToString(void) {
	switch (mode) {
		case FAMILLE:
			return "Famille";
		case APERO:
			return "Apéro";
		case HARD:
			return "Hard";
	}
}
