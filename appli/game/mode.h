/**
 * @brief Gestion du mode de jeu
 * @author Maxence & Aymeric
 */

#pragma once


/**
 * @brief Tous les modes de jeu possibles
 */
typedef enum {
	FAMILLE = 1,      //!< Mode Famille (le plus soft)
	APERO = 1 << 1,   //!< Mode Apéro (en soirée)
	HARD = 1 << 2     //!< Mode Hard (le plus dur)
} Mode;

/**
 * @brief Permet d'obtenir le mode actuellement sélectionné
 * @return Mode acutellement selectionné
 */
Mode MODE_Get(void);

/**
 * @brief Change le mode en passant au suivant (puis retour au premier si le mode actuel est le dernier)
 */
void MODE_Change(void);

/**
 * @brief Permet d'obtenir le mode actuel sous forme de chaîne de caractères
 * @return Le mode actuel sous forme de chaîne de caractères
 */
char* MODE_ToString(void);
