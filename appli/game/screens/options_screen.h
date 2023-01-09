#pragma once

#include "../../ihm/ihm.h"
#include "../mode.h"
#include "../players.h"
#include <stdio.h>

void OPTIONS_SCREEN_Init(void);
void OPTIONS_SCREEN_Update(void);
void OPTIONS_SCREEN_Display(void);

bool_e OPTIONS_SCREEN_PreviousScreen(void);
bool_e OPTIONS_SCREEN_NextScreen(void);

static void OPTIONS_SCREEN_DisplayModeButton(void);
static void OPTIONS_SCREEN_DisplayPlayerCount(void);
