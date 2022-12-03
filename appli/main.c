/**
 * @brief Main
 * @author Maxence & Aymeric
 */

#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "systick.h"
#include "game/game.h"


int main(void) {
	// Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	// Cette ligne doit rester la première étape de la fonction main().
 	HAL_Init();

	// Initialisation de l'UART2 à la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
	// Attention, les pins PA2 et PA3 ne sont pas reliées jusqu'au connecteur de la Nucleo.
	// Ces broches sont redirigées vers la sonde de débogage, la liaison UART étant ensuite encapsulée sur l'USB vers le PC de développement.
	// UART_init(UART2_ID,115200);

	// Indique que les printf sortent vers le périphérique UART2
	// SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	// Initialisation du port de la led Verte (carte Nucleo)
	// BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	// Initialisation du port du bouton bleu (carte Nucleo)
	// BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	// On ajoute la fonction process_ms à la liste des fonctions appelées automatiquement chaque ms par la routine d'interruption du périphérique SYSTICK
	// Systick_add_callback_function(&process_ms);

	GAME_Init();

	while (TRUE) {
		GAME_Update();
	}
}
