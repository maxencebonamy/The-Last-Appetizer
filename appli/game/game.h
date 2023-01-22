/**
 * @brief Gestion de la partie
 * @author Maxence & Aymeric
 */

#pragma once

#include "../ihm/ihm.h"
#include "scores.h"
#include "screens/home_screen.h"
#include "screens/options_screen.h"
#include "screens/selection_screen.h"
#include "screens/start_screen.h"
#include "screens/arrow_screen.h"
#include "screens/action_screen.h"
#include "screens/score_screen.h"
#include "screens/end_screen.h"


/**
 * @brief Tous les états possibles de la machine à états
 */
typedef enum {
    HOME = 0,       //!< Écran d'accueil
    OPTIONS,        //!< Configuration de la partie (mode et nombre de joueurs)
    SELECTION,      //!< Sélection manuelle de la position de chacun des joueurs
    START,          //!< Écran de confirmation du lancement de la partie
    ARROW,          //!< Rotation de la flèche pour sélectionner un joueur
    ACTION,         //!< Affichage de l'action que doit effectuer le joueur selectionné
    SCORE,          //!< Affichage des scores
    END             //!< Fin du jeu
} GameState;

/**
 * @brief Agrégat de données représentant un état (avec son état dans
 *        l'énumération et ses fonctions d'initialisation et de mise à jour)
 */
typedef struct {
    void (*initFunction)(void);     //!< Fonction d'initialisation
    void (*updateFunction)(void);   //!< Fonction de mise à jour
    GameState state;                //!< État correspondant dans l'énumération
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
