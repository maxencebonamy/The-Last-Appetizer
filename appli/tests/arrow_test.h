/**
 * @brief Gestion des tests liés à la flèche (moteur et codeur incrémental)
 * @author Maxence & Aymeric
 */


#pragma once

/**
 * @brief Test de la rotation du moteur (activation ou désactivation dans un seul sens)
 * @pre Le test TEST_SCREEN_ButtonClick doit avoir été validé
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_ARROW_Turn(void);

/**
 * @brief Test du codeur incrémental (affichage de la position de la flèche sur l'écran)
 * @pre Le test TEST_SCREEN_GameBoard doit avoir été validé
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_ARROW_GetAngle(void);

/**
 * @brief Test de la rotation du moteur jusqu'à un angle précis
 * @pre Les tests TEST_ARROW_Turn et TEST_ARROW_GetAngle doivent avoir été validés
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_ARROW_TurnUntil(void);