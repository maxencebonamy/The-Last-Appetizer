#pragma once

#include <stdint.h>
#include "mode.h"
#include "macro_types.h"
#include "../utils/random.h"
#include <assert.h>



typedef struct {
    char* description;
    Mode modes;
    bool_e hidden;
    uint8_t score;
} Action;

Action* ACTIONS_GetCurrent(void);

Action* ACTIONS_ChooseRandom(void);