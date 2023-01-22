/**
 * @brief Gestion de l'affichage du plateau du jeu (bol, flèche et joueurs)
 * @author Maxence & Aymeric
 */

#pragma once

#include "ihm.h"
#include "../game/players.h"
#include <math.h>


/***
 * @brief Modifie la position du centre du plateau
 * @param x Coordonnée x du centre du plateau
 * @param y Coordonnée y du centre du plateau
 */
void GAME_BOARD_SetCenterPosition(uint16_t x, uint16_t y);

/**
 * @brief Modifie le joueur pointé par la flèche (en tournant cette dernière)
 * @param playerIndex Indice du joueur qui sera pointé par la flèche
 * @pre L'indice du joueur doit être compris entre 0 et le nombre de joueurs - 1
 */
void GAME_BOARD_SetPlayerPointed(uint8_t playerIndex);

/**
 * @brief Modifie la vitesse de rotation de la flèche (0 pour ne pas qu'elle tourne)
 * @param value Vitesse de rotation de la flèche (en rad / ms)
 * @post La flèche ne tournera que si la fonction GAME_BOARD_Update est appelée dans la boucle principale
 */
void GAME_BOARD_SetArrowRotationSpeed(double_t value);

/**
 * @brief Modifie directement l'angle de la flèche
 * @param value Angle de la flèche
 */
void GAME_BOARD_SetArrowAngle(double_t value);

/**
 * @brief Met à jour le plateau de jeu, en particulier la flèche lorsqu'elle tourne
 * @pre Cette fonction doit être appelée dans la boucle principale
 */
void GAME_BOARD_Update(void);

/**
 * @brief Dessine le plateau du jeu (bol, flèche et joueurs)
 */
void GAME_BOARD_Display();

/**
 * @brief Dessine la flèche dans le bol
 * @param color Couleur de la flèche
 * @pre L'IHM doit avoir été initialisée
 */
static void GAME_BOARD_DrawArrow(uint16_t color);

/**
 * @brief Dessine un joueur (triangle + cercle)
 * @param x Coordonnée x du centre du joueur
 * @param y Coordonnée y du centre du joueur
 * @param color Couleur du joueur
 */
static void GAME_BOARD_DrawPlayer(uint16_t x, uint16_t y, uint16_t color);