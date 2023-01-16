/**
 * @brief Gestion des joueurs
 * @author Maxence & Aymeric
 */

#include "players.h"


/// Nombre de joueurs dans la partie
static uint8_t players = PLAYERS_MIN;
/// Indice du joueur courant
static uint8_t current = 1;

static double_t positions[PLAYERS_MAX];


uint8_t PLAYERS_GetCount(void) {
	return players;
}

void PLAYERS_Remove(void) {
    // Met le nombre de joueurs au maximum si la limite minimale a été dépassée
	if (--players < PLAYERS_MIN) {
		players = PLAYERS_MAX;
	}
}

void PLAYERS_Add(void) {
    // Met le nombre de joueurs au minimum si la limite maximale a été dépassée
	if (++players > PLAYERS_MAX) {
		players = PLAYERS_MIN;
	}
}

uint8_t PLAYERS_GetCurrent(void) {
    return current;
}

void PLAYERS_Next(void) {
    if (++current > players) {
        current = 1;
    }
}

uint8_t PLAYERS_ChooseRandom(void) {
    current = RANDOM_Get(1, players);
    return current;
}

double_t PLAYERS_GetPosition(uint8_t player) {
    return positions[player];
}

uint8_t PLAYERS_SetPosition(uint8_t player, double_t position) {
    positions[player] = position;
}