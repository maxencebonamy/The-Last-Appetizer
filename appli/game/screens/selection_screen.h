/**
 * @brief État n°3 : Sélection successive de la position de chacun des joueurs avec la flèche pour initialiser la partie
 * @author Maxence & Aymeric
 */


#pragma once

#include "../../ihm/game_board.h"
#include "../players.h"
#include "../../arrow/arrow.h"
#include <stdio.h>

/**
 * @brief Initialisation
 * @post Toutes les autres fonctions du fichier peuvent être utilisées
 */
void SELECTION_SCREEN_Init(void);

/**
 * @brief Mise à jour
 * @pre L'écran doit avoir été initialisé
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void SELECTION_SCREEN_Update(void);

/**
 * @brief Affichage
 * @pre L'écran doit avoir été initialisé
 */
void SELECTION_SCREEN_Display(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran précédent
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran précédent, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e SELECTION_SCREEN_PreviousScreen(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e SELECTION_SCREEN_NextScreen(void);
