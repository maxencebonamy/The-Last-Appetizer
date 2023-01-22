/**
 * @brief Main
 * @author Maxence & Aymeric
 */

#include "stm32f1xx_hal.h"
#include "game/game.h"
#include "tests/tests.h"


int main(void) {
	// Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	HAL_Init();

 	// Tests
    TEST_DoAll();

    // Initialisation du jeu
    GAME_Init();

    // Boucle principale du jeu
    while (TRUE) {
        GAME_Update();
    }

}
