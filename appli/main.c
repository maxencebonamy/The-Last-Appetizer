/**
 * @brief Main
 * @author Maxence & Aymeric
 */

#include "stm32f1xx_hal.h"
#include "systick.h"
#include "game/game.h"
#include "tests/tests.h"
#include "stm32f1_adc.h"
#include "arrow/arrow.h"
#include "utils/random.h"

int main(void) {
	// Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
 	HAL_Init();

 	// Initialisation de l'ADC
	ADC_init();

	RANDOM_Init();

 	// Tests
    TEST_DoAll();

    // Initialisation du jeu
    GAME_Init();

    // Ajout de la fonction qui met à jour le jeu dans les fonctiones appelées automatiquement
    // chaque ms par la routine d'interruption du périphérique SYSTICK
    Systick_add_callback_function(&GAME_Update);

}
