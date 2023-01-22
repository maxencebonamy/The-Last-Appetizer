/**
 * @brief Gestion de la génération de nombres pseudo-aléatoires
 * @author Maxence & Aymeric
 */

#pragma once

#include <stdint.h>


/**
 * @brief Génère un nombre aléatoire
 * @pre Doit être appelée à un moment non prédictible du programme (par exemple lorsque l'utilisateur effectue une action)
 * @post Un nombre aléatoire est stocké, on peut donc appeler la fonction get une fois
 */
void RANDOM_Generate(void);

/**
 * @brief Renvoie un nombre aléatoire compris entre min inclus et max inclus
 * @param min Borne inférieure du nombre aléatoire
 * @param max Borne supérieure du nombre aléatoire
 * @return Nombre aléatoire compris entre min inclus et max inclus
 * @pre La fonction update doit avoir été appelée avant
 */
uint16_t RANDOM_Get(uint16_t min, uint16_t max);