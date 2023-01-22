/**
 * @brief État n°4 : Confirmation avant le lancement de la partie
 * @author Maxence & Aymeric
 */


#pragma once

#include "../../ihm/ihm.h"
#include "../scores.h"


/**
 * @brief Initialisation
 * @post Toutes les autres fonctions du fichier peuvent être utilisées
 */
void START_SCREEN_Init(void);

/**
 * @brief Mise à jour
 * @pre L'écran doit avoir été initialisé
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void START_SCREEN_Update(void);

/**
 * @brief Affichage
 * @pre L'écran doit avoir été initialisé
 */
void START_SCREEN_Display(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran précédent
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran précédent, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e START_SCREEN_PreviousScreen(void);

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e START_SCREEN_NextScreen(void);
