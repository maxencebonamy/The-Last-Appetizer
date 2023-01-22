/**
 * @brief Gestion des actions que peuvent faire les joueurs, et qui sont choisies aléatoirement
 * @author Maxence & Aymeric
 */


#pragma once

#include <stdint.h>
#include "mode.h"
#include "macro_types.h"
#include "../utils/random.h"
#include <assert.h>

/**
 * @brief Action (gage qui peut être validé ou non par le joueur sélectionné)
 */
typedef struct {
    char* description;  //!< Description de l'action
    Mode modes;         //!< Mode(s) dans lesquels l'action peut être tirée au sort
    bool_e hidden;      //!< Booléen qui indique si l'action doit être cachée des autres joueurs ou non
    uint8_t score;      //!< Points ajoutés au score du joueur si celui-ci réalise l'action
} Action;

/**
 * @brief Renvoie l'action actuellement choisie
 * @return Action actuellement choisie
 */
Action* ACTIONS_GetCurrent(void);

/**
 * @brief Choisit une action aléatoirement, la remplace dans l'action actuellement choisie, et la renvoie
 * @return Action choisie aléatoirement
 */
Action* ACTIONS_ChooseRandom(void);