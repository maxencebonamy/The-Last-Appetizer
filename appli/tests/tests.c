/**
 * @brief Gestion de tous les tests
 * @author Maxence & Aymeric
 */


#include "tests.h"

#if SCREEN_WRITE_TEXT || SCREEN_DRAW_SHAPES || SCREEN_BUTTON_CLICK || SCREEN_GAME_BOARD
    #include "screen_tests.h"
#endif

#if UTILS_GENERATE_RANDOM_NUMBERS
    #include "utils_tests.h"
#endif

#if ARROW_TURN || ARROW_GET_ANGLE || ARROW_TURN_UNTIL
    #include "arrow_test.h"
#endif


void TEST_DoAll(void) {

#if SCREEN_WRITE_TEXT
    TEST_SCREEN_WriteText();
#endif

#if SCREEN_DRAW_SHAPES
    TEST_SCREEN_DrawShapes();
#endif

#if SCREEN_BUTTON_CLICK
    TEST_SCREEN_ButtonClick();
#endif

#if SCREEN_GAME_BOARD
    TEST_SCREEN_GameBoard();
#endif

#if UTILS_GENERATE_RANDOM_NUMBERS
    TEST_UTILS_GenerateRandomNumbers();
#endif

#if ARROW_TURN
    TEST_ARROW_Turn();
#endif

#if ARROW_GET_ANGLE
    TEST_ARROW_GetAngle();
#endif

#if ARROW_TURN_UNTIL
    TEST_ARROW_TurnUntil();
#endif

}
