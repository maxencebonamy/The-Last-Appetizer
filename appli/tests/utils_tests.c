/**
 * @brief Gestion des tests liés à la génération de nombres pseudo-aléatoires
 * @author Maxence & Aymeric
 */


#include "utils_tests.h"

#include "../utils/random.h"
#include "../ihm/ihm.h"
#include <stdio.h>


void TEST_UTILS_GenerateRandomNumbers(void) {
	IHM_Init();

	IHM_Fill(IHM_COLOR_WHITE);
	IHM_Write(0, 0, 320, 240, "Appuyez\nsur l'écran", IHM_COLOR_BLACK, IHM_COLOR_WHITE);

	while (TRUE) {
		IHM_Update();
		if (IHM_IsClicking()) {
			IHM_Fill(IHM_COLOR_WHITE);

			char string[4];
			sprintf(string, "%d", RANDOM_Get(100, 999));

			IHM_Write(0, 0, 320, 240, string, IHM_COLOR_BLACK, IHM_COLOR_WHITE);
		}
	}
}
