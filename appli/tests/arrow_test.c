#include "arrow_test.h"


void TEST_ARROW_Turn(void) {
    ARROW_Turn();

    while (TRUE) {

    }
}

void TEST_ARROW_GetAngle(void) {
    IHM_Init();

    IHM_Fill(IHM_COLOR_WHITE);
    IHM_Write(0, 0, 320, 240, "Appuyez\nsur l'écran", IHM_COLOR_BLACK, IHM_COLOR_WHITE);

    while (TRUE) {
        IHM_Update();
        ARROW_Update();

        if (IHM_IsClicking()) {
            IHM_Fill(IHM_COLOR_WHITE);

            char string[3];
            sprintf(string, "%d", ARROW_GetAngle());

            IHM_Write(0, 0, 320, 240, string, IHM_COLOR_BLACK, IHM_COLOR_WHITE);
        }
    }
}