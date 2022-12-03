/**
 * @brief Gestion des joueurs
 * @author Maxence & Aymeric
 */

#pragma once

#include <stdint.h>


/// Nombre minimal de joueurs dans une partie
#define PLAYERS_MIN 3
/// Nombre maximal de joueurs dans une partie
#define PLAYERS_MAX 8

/**
 * @brief Permet d'obtenir le nombre de joueurs de la partie
 * @return Le nombre de joueurs de la partie
 */
uint8_t PLAYERS_Get(void);

/**
 * @brief Enlève un joueur (met au maximum si la limite minimale a été dépassée)
 */
void PLAYERS_Remove(void);

/**
 * @brief Ajoute un joueur (met au minimum si la limite maximale a été dépassée)
 */
void PLAYERS_Add(void);
