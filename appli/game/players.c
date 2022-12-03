/**
 * @brief Gestion des joueurs
 * @author Maxence & Aymeric
 */

#include "players.h"


/// Nombre de joueurs dans la partie
static uint8_t players = (PLAYERS_MAX + PLAYERS_MIN) / 2;

uint8_t PLAYERS_Get(void) {
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
