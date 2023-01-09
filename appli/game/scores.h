#pragma once

#include <stdint.h>
#include "players.h"
#include "macro_types.h"

typedef struct {
    uint8_t number;
    uint8_t rank;
} Player;

void SCORES_Reset(void);

uint8_t SCORES_Get(uint8_t player);

void SCORES_Add(uint8_t player, uint8_t value);

bool_e SCORES_IsMaximumReached(void);

uint8_t SCORES_GetWinner(void);

uint8_t SCORES_GetPlayerByRank(uint8_t rank);

static void SCORES_Update(void);

static uint8_t SCORES_GetRankOf(uint8_t player);