/**
 * @brief Gestion de tous les tests
 * @author Maxence & Aymeric
 */


#pragma once


#define SCREEN_WRITE_TEXT               0
#define SCREEN_DRAW_SHAPES              0
#define SCREEN_BUTTON_CLICK             0
#define SCREEN_GAME_BOARD               0
#define UTILS_GENERATE_RANDOM_NUMBERS   0
#define ARROW_TURN                      0
#define ARROW_GET_ANGLE                 0
#define ARROW_TURN_UNTIL                0


/**
 * @brief Lance le premier test dont la macro a été fixée à 1 (les suivants ne seront pas lancés car les tests sont bloquants)
 */
void TEST_DoAll(void);
