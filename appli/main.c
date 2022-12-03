/**
 * @brief Main
 * @author Maxence & Aymeric
 */

#include "stm32f1xx_hal.h"
#include "systick.h"
#include "game/game.h"


int main(void) {
	// Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
 	HAL_Init();

    // Initialisation du jeu
    GAME_Init();

    // Ajout de la fonction qui met à jour le jeu dans les fonctiones appelées automatiquement
    // chaque ms par la routine d'interruption du périphérique SYSTICK
    Systick_add_callback_function(&GAME_Update);
}
