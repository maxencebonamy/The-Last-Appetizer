/**
 * @brief État n°5 : Écran où la flèche tourne jusqu'à choisir un joueur aléatoirement
 * @author Maxence & Aymeric
 */

#pragma once

#include "../../ihm/ihm.h"
#include "../../utils/random.h"
#include "../actions.h"
#include "../players.h"
#include "../../arrow/arrow.h"


/**
 * @brief Initialisation
 * @post Toutes les autres fonctions du fichier peuvent être utilisées
 */
void ARROW_SCREEN_Init(void);

/**
 * @brief Mise à jour
 * @pre L'écran doit avoir été initialisé
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void ARROW_SCREEN_Update(void);

/**
 * @brief Affichage
 * @pre L'écran doit avoir été initialisé
 */
void ARROW_SCREEN_Display(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e ARROW_SCREEN_NextScreen(void);
