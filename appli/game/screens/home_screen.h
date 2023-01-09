/**
 * @brief Écran d'accueil
 * @author Maxence & Aymeric
 */

#pragma once

#include "../../ihm/ihm.h"


/**
 * @brief Initialisation
 * @post Toutes les autres fonctions du fichier peuvent être utilisées
 */
void HOME_SCREEN_Init();

/**
 * @brief Mise à jour
 * @pre L'écran doit avoir été initialisé
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void HOME_SCREEN_Update();

/**
 * @brief Affichage
 * @pre L'écran doit avoir été initialisé
 */
void HOME_SCREEN_Display();

/**
 * @brief Permet de savoir si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant
 * @return True si si l'utilisateur a cliqué sur le bouton permettant de passer à l'écran suivant, false sinon
 * @pre L'écran doit avoir été initialisé
 */
bool_e HOME_SCREEN_NextScreen();
