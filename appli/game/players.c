#include "players.h"

static uint8_t players = (PLAYERS_MAX + PLAYERS_MIN) / 2;

uint8_t PLAYERS_Get(void) {
	return players;
}

void PLAYERS_Remove(void) {
	if (--players < PLAYERS_MIN) {
		players = PLAYERS_MAX;
	}
}

void PLAYERS_Add(void) {
	if (++players > PLAYERS_MAX) {
		players = PLAYERS_MIN;
	}
}
