/**
 * @brief Gestion des joueurs
 * @author Maxence & Aymeric
 */

#pragma once

#include "../utils/random.h"
#include <stdint.h>


/// Nombre minimal de joueurs dans une partie
#define PLAYERS_MIN 3
/// Nombre maximal de joueurs dans une partie
#define PLAYERS_MAX 8

/**
 * @brief Permet d'obtenir le nombre de joueurs de la partie
 * @return Le nombre de joueurs de la partie
 */
uint8_t PLAYERS_GetCount(void);

/**
 * @brief Enlève un joueur (met au maximum si la limite minimale a été dépassée)
 */
void PLAYERS_Remove(void);

/**
 * @brief Ajoute un joueur (met au minimum si la limite maximale a été dépassée)
 */
void PLAYERS_Add(void);

/**
 * @brief Permet d'obtenir le numéro du joueur courant
 * @return Le numéro du joueur courant
 */
uint8_t PLAYERS_GetCurrent(void);

/**
 * @brief Passe au joueur suivant (revient au premier si le tour est terminé)
 */
void PLAYERS_Next(void);

/**
 * @brief Choisis un joueur aléatoirement et le renvoie
 * @return Le joueur courant qui a été choisi aléatoirement
 * @pre Le random doit avoir été initialisé
 */
uint8_t PLAYERS_ChooseRandom(void);