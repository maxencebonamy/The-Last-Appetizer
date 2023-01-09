#pragma once

#include "stm32f1_adc.h"
#include <stdint.h>


/**
 * @brief Initialise le random
 * @post Les autres fonctions peuvent être utilisées
 */
void RANDOM_Init(void);

void RANDOM_Update(void);

/**
 * @brief Renvoie un nombre aléaoire compris entre min et max inclus
 * @param min Borne inférieure du nombre aléatoire
 * @param max Borne supérieure du nombre aléatoire
 * @return Nombre aléatoire compris entre min et max inclus
 * @pre Le random doit avoir été initialisé
 */
uint16_t RANDOM_Get(uint16_t min, uint16_t max);