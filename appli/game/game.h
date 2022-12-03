/**
 * @brief Gestion de la partie
 * @author Maxence & Aymeric
 */

#pragma once

#include "../ihm/ihm.h"
#include "screens/home_screen.h"
#include "screens/options_screen.h"
#include "screens/selection_screen.h"
#include "screens/start_screen.h"


/**
 * @brief Tous les états possibles de la machine à états
 */
typedef enum {
    // Écran d'accueil
	HOME = 0,
    // Configuration de la partie (mode et nombre de joueurs)
	OPTIONS,
    // Sélection manuelle de la position de chacun des joueurs
	SELECTION,
    // Écran de confirmation du lancement de la partie
	START,
    // Rotation de la flèche pour sélectionner un joueur
	ARROW,
    // Affichage de l'action que doit effectuer le joueur selectionné
	ACTION,
    // Affichage des scores
	SCORE,
    // Fin du jeu
	END
} State;

/**
 * @brief Initialisation du jeu
 * @post Le jeu peut être mis à jour
 */
void GAME_Init(void);

/**
 * @brief Mise à jour du jeu
 * @pre Le jeu doit avoir été initialisé
 */
void GAME_Update(void);
