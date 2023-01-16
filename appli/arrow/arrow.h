#pragma once

#include "stm32f1_pwm.h"
#include "stm32f1_timer.h"
#include "macro_types.h"
#include "../utils/random.h"
#include <stdint.h>
#include <math.h>

/**
 * @brief Active ou désactive la rotation du moteur qui entraîne la flèche
 * @param power Puissance de rotation (0 pour aucune rotation, négatif pour une rotation dans le sens inverse)
 */
void ARROW_Turn(int8_t power);

/**
 * @brief Met à jour la position de la flèche (à l'aide du codeur incrémental)
 */
void ARROW_Update(void);

/**
 * @brief Renvoie l'angle actuel de la flèche
 * @return L'angle actuel de la flèche
 */
double_t ARROW_GetAngle(void);

/**
 * @brief Remet l'angle de la flèche à 0
 */
void ARROW_Reset(void);

/**
 * @brief Active la rotation de la flèche jusqu'à ce qu'elle atteigne un certain angle (le nombre de tours effectués est aléatoire)
 * @param angle L'angle final que la flèche atteindra une fois sa rotation terminée
 */
void ARROW_TurnUntil(double_t angle);

/**
 * @brief Renvoie
 * @return
 */
bool_e ARROW_IsAtDestination(void);