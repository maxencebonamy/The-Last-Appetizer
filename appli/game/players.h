#pragma once

#include <stdint.h>

#define PLAYERS_MIN 3
#define PLAYERS_MAX 8

uint8_t PLAYERS_Get(void);
void PLAYERS_Remove(void);
void PLAYERS_Add(void);
