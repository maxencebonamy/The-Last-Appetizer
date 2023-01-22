/**
 * @brief État n°7 : Affichage des scores des trois premiers joueurs dans l'ordre (du premier au troisième)
 * @author Maxence & Aymeric
 */


#pragma once

#include "../../ihm/ihm.h"
#include "../players.h"
#include "../actions.h"
#include "../scores.h"
#include <stdio.h>

/**
 * @brief Initialisation
 * @post Toutes les autres fonctions du fichier peuvent être utilisées
 */
void SCORE_SCREEN_Init(void);

/**
 * @brief Mise à jour
 * @pre L'écran doit avoir été initialisé
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void SCORE_SCREEN_Update(void);

/**
 * @brief Affichage
 * @pre L'écran doit avoir été initialisé
 */
void SCORE_SCREEN_Display(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e SCORE_SCREEN_NextScreen(void);