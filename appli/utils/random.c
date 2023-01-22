/**
 * @brief Gestion de la génération de nombres pseudo-aléatoires
 * @author Maxence & Aymeric
 */

#include "random.h"


/// Capacité maximale du tableau
#define NB_VALUES 100

/// Tableau qui va contenir les valeurs aléatoires stockées
static uint32_t values[NB_VALUES];
/// Indice du dernier élément stocké dans le tableau
static uint16_t loadIndex = 0;


void RANDOM_Generate(void) {
    // On ajoute une valeur aléatoire au tableau si il n'est pas plein
    if (loadIndex < NB_VALUES) {
        // La valeur aléatoire correspond au nombre de millisecondes écoulées depuis la dernière mise à jour
        values[loadIndex++] = HAL_GetTick();
    }
}

uint16_t RANDOM_Get(uint16_t min, uint16_t max) {
    // On prend la première valeur du tableau qu'on adapte aux bornes voulues
    uint16_t value = values[0] % (max - min + 1) + min;

    // On décale toutes les autres valeurs du tableau vers le début
    for (uint16_t i = 0; i < loadIndex; ++i) {
        values[i] = values[i + 1];
    }
    // Le tableau a perdu une valeur, on décrémente donc l'indice du dernier élément
    --loadIndex;

    return value;
}
