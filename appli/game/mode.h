/**
 * @brief Gestion du mode de jeu
 * @author Maxence & Aymeric
 */

#pragma once

/**
 * @brief Tous les modes de jeu possibles
 */
typedef enum {
	FAMILLE = 0,
	APERO,
	HARD
} Mode;

Mode MODE_Get(void);
void MODE_Change(void);
char* MODE_ToString(void);
