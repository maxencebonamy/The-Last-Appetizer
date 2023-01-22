/**
 * @brief Gestion des tests liés à l'écran
 * @author Maxence & Aymeric
 */


#pragma once

/**
 * @brief Test d'affichage de texte sur l'écran
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_SCREEN_WriteText(void);

/**
 * @brief Test d'affichage de formes sur l'écran (rectangles à coins arrondis, lignes, ...)
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_SCREEN_DrawShapes(void);

/**
 * @brief Test d'affichage de bouton sur l'écran, et de détection d'appui sur le bouton
 * @pre Les tests TEST_SCREEN_WriteText et TEST_SCREEN_DrawShapes doivent avoir été validés
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_SCREEN_ButtonClick(void);

/**
 * @brief Test d'affichage du plateau de jeu sur l'écran, et de la rotation de la flèche dans le plateau
 * @post Le test TEST_SCREEN_DrawShapes doit avoir été validé
 * @post Une boucle blocante est intégrée à la fin de la fonction
 */
void TEST_SCREEN_GameBoard(void);
