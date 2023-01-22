/**
 * @brief Gestion de la flèche (moteur et codeur incrémental)
 * @author Maxence & Aymeric
 */


#pragma once

#include "stm32f1_pwm.h"
#include "stm32f1_timer.h"
#include "macro_types.h"
#include "../utils/random.h"
#include <stdint.h>
#include <math.h>


/**
 * @brief Initialise la flèche : le moteur à courant continu ainsi que le codeur incrémental qui y est associé
 * @pre Le codeur incrémental doit être relié à la broche A1 du microcontrolleur
 * @post La valeur de l'angle de la flèche va automatiquement être mise à jour toutes les ms
 */
void ARROW_Init(void);

/**
 * @brief Active ou désactive la rotation du moteur qui entraîne la flèche
 * @param power Puissance de rotation (0 pour aucune rotation, négatif pour une rotation dans le sens inverse)
 * @pre La puissance doit avoir une valeur absolue comprise entre 0 et 100
 * @pre Le moteur doit être relié, par l'intermédiaire d'un pont en H, aux broches PA8 et PA9 du microcontrolleur
 */
void ARROW_Turn(int8_t power);

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
void ARROW_TurnUntil(double_t angle, uint8_t nbLaps);

/**
 * @brief Renvoie un booléen indiquant si la flèche est arrivée à destination
 * @return True si la flèche est arrivée à destination, false sinon
 */
bool_e ARROW_IsAtDestination(void);