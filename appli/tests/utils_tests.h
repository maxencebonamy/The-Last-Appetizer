/**
 * @brief Gestion des tests liés à la génération de nombres pseudo-aléatoires
 * @author Maxence & Aymeric
 */


#pragma once

/**
 * @brief Test de génération de nombre aléatoires (à chaque nouvel appui sur l'écran)
 * @pre Le test TEST_SCREEN_WriteText doit avoir été validé
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_UTILS_GenerateRandomNumbers(void);