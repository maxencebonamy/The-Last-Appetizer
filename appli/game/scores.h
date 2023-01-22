/**
 * @brief Gestion des scores des joueurs
 * @author Maxence & Aymeric
 */

#pragma once

#include <stdint.h>
#include "players.h"
#include "macro_types.h"


/**
 * @brief Joueur
 */
typedef struct {
    uint8_t number;  //!< Numéro du joueur
    uint8_t rank;  //!< Classement
} Player;

/**
 * @brief Remet les scores de tous les joueurs à 0
 */
void SCORES_Reset(void);

/**
 * @brief Renvoie le score du joueur dont le numéro a été précisé
 * @param player Numéro du joueur
 * @return Score du joueur dont le numéro a été précisé
 */
uint8_t SCORES_Get(uint8_t player);

/**
 * @brief Ajoute une valeur au score du joueur dont le numéro a été précisé
 * @param player Numéro du joueur
 * @param value Valeur ajoutée au joueur dont le numéro a été précisé
 */
void SCORES_Add(uint8_t player, uint8_t value);

/**
 * @brief Renvoie un booléen indiquant si la partie est terminée ou non (si le score maximal a été atteint)
 * @return True si le score maximal a été atteint, False sinon
 */
bool_e SCORES_IsMaximumReached(void);

/**
 * @brief Renvoie le numéro du joueur qui a gagné la partie
 * @return Le numéro du joueur qui a gagné la partie
 * @pre Le score maximal doit avoir été atteint
 */
uint8_t SCORES_GetWinner(void);

/**
 * @brief Renvoie le joueur dont le classement a été précisé
 * @param rank Classement du joueur cherché
 * @return Numéro du joueur dont le classement a été précisé
 * @pre Le classement doit être compris entre 1 et le nombre de joueurs de la partie inclus
 */
uint8_t SCORES_GetPlayerByRank(uint8_t rank);
