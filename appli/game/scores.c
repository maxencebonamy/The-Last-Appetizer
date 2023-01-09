#include "scores.h"

#define SCORE_MAX 20

static uint8_t ranking[PLAYERS_MAX];
static uint8_t scores[PLAYERS_MAX];
static bool_e isMaximumReached = FALSE;


void SCORES_Reset() {
    isMaximumReached = FALSE;
    for (uint8_t i = 0; i < PLAYERS_MAX; ++i) {
        ranking[i] = i + 1;
        scores[i] = 0;
    }
}

uint8_t SCORES_Get(uint8_t player) {
    return scores[player - 1];
}

void SCORES_Add(uint8_t player, uint8_t value) {
    scores[player - 1] += value;
    SCORES_Update();

    uint8_t playerRank = SCORES_GetRankOf(player);
    while (playerRank > 0) {
        if (SCORES_Get(ranking[playerRank]) > SCORES_Get(ranking[playerRank - 1])) {
            ranking[playerRank] = ranking[playerRank - 1];
            ranking[playerRank - 1] = player;
            playerRank--;
        }
        else {
            break;
        }
    }
}

bool_e SCORES_IsMaximumReached(void) {
    return isMaximumReached;
}

uint8_t SCORES_GetWinner(void) {
    for (uint8_t i = 0; i < PLAYERS_GetCount(); ++i) {
        if (scores[i] >= SCORE_MAX) {
            return i + 1;
        }
    }
}

uint8_t SCORES_GetPlayerByRank(uint8_t value) {
    return ranking[value];
}

static void SCORES_Update(void) {
    for (uint8_t i = 0; i < PLAYERS_GetCount(); ++i) {
        if (scores[i] >= SCORE_MAX) {
            isMaximumReached = TRUE;
            return;
        }
    }
}

static uint8_t SCORES_GetRankOf(uint8_t player) {
    for (uint8_t i = 0; i < PLAYERS_GetCount(); ++i) {
        if (player == ranking[i]) {
            return i;
        }
    }
}