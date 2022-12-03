#pragma once

#include "tft_ili9341/stm32f1_ili9341.h"
#include "tft_ili9341/stm32f1_xpt2046.h"
#include "../game/players.h"
#include <math.h>


/// Structure représentant un rectangle
typedef struct {
	uint16_t x0;
	uint16_t y0;
	uint16_t x1;
	uint16_t y1;
} IHM_Rect;

/// Couleurs pouvant être utilisées dans l'IHM (valeurs sur 16 bits)
#define IHM_COLOR_WHITE 		0xFFFF
#define IHM_COLOR_BLUE 			0x3936
#define IHM_COLOR_RED 			0xB8A2
#define IHM_COLOR_BLACK 		0x0000
#define IHM_COLOR_PURPLE_1 		0x78F1
#define IHM_COLOR_PURPLE_2 		0x60CE
#define IHM_COLOR_PURPLE_3 		0x4089

/**
 * @brief Initialise l'IHM
 * @post Toutes les autres fonctions de l'IHM peuvent être utilisées
 */
void IHM_Init(void);

/**
 * @brief Met à jour l'IHM (fonction qui doit être appelée à chaque frame)
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_Update(void);

/**
 * @brief Vérifie si l'utilisateur est en train d'appuyer sur l'écran
 * @ret True si l'utilisateur clique sur l'écran
 * @pre L'IHM doit avoir été initialisée au préalable
 */
bool_e IHM_IsClicking(void);

/**
 * @brief Vérifie si il y a une collision entre un rectangle et le pointeur
 * @param rect Rectangle dans lequel on vérifie une potentielle collision
 * @ret True si il y a une collision
 * @pre L'IHM doit avoir été initialisée au préalable
 */
bool_e IHM_Collide(const IHM_Rect* rect);

/**
 * @brief Rempli l'écran d'une couleur
 * @param color Couleur qui va remplir l'écran
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_Fill(uint16_t color);

/**
 * @brief Dessine un rectangle
 * @param x0 Coordonnée x du coin en haut à gauche
 * @param y0 Coordonnée y du coin en haut à gauche
 * @param x1 Coordonnée x du coin en bas à droite
 * @param y1 Coordonnée y du coin en bas à droite
 * @param color Couleur de la bordure
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DrawFilledRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);

/**
 * @brief Dessine un rectangle avec des coins arrondis
 * @param x0 Coordonnée x du coin en haut à gauche
 * @param y0 Coordonnée y du coin en haut à gauche
 * @param x1 Coordonnée x du coin en bas à droite
 * @param y1 Coordonnée y du coin en bas à droite
 * @param color Couleur de la bordure
 * @param radius Rayon des coins arrondis
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DrawRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint16_t borderColor, uint16_t radius);

/**
 * @brief Dessine un rectangle plein avec des coins arrondis
 * @param x0 Coordonnée x du coin en haut à gauche
 * @param y0 Coordonnée y du coin en haut à gauche
 * @param x1 Coordonnée x du coin en bas à droite
 * @param y1 Coordonnée y du coin en bas à droite
 * @param color Couleur de remplissage
 * @param radius Rayon des coins arrondis
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DrawFilledRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint16_t radius);

/**
 * @brief Dessine un bouton (rectangle à coins arrondis + texte par dessus)
 * @param Rect Rectangle qui encadre le bouton
 * @param color Couleur de remplissage
 * @param title Texte affiché
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DisplayButton(IHM_Rect* rect, char* title, uint16_t color);

/**
 * @brief Écrit du texte (sur une ou plusieurs lignes) centré automatiquement dans un rectangle
 * @param x0 Coordonnée x du coin en haut à gauche du rectangle autour
 * @param y0 Coordonnée y du coin en haut à gauche du rectangle autour
 * @param x1 Coordonnée x du coin en bas à droite du rectangle autour
 * @param y1 Coordonnée y du coin en bas à droite du rectangle autour
 * @param content Texte
 * @param color Couleur du texte
 * @param backgroundColor Couleur de fond
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_Write(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char* content, uint16_t color, uint16_t backgroundColor);

/**
 * @brief Dessine un joueur (triangle + cercle)
 * @param x Coordonnée x du centre du joueur
 * @param y Coordonnée y du centre du joueur
 * @param color Couleur du joueur
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DrawPlayer(uint16_t x, uint16_t y, uint16_t color);

/**
 * @brief Dessine un plateau de jeu (cercle + flèche + joueurs autour)
 * @param x Coordonnée x du centre du plateau
 * @param y Coordonnée y du centre du plateau
 * @param playerIndex Index du joueur selectionné
 * @param playerColor Couleur du joueur selectionné (et de la flèche)
 * @pre L'IHM doit avoir été initialisée au préalable
 */
void IHM_DrawGameBoard(uint16_t x, uint16_t y, uint8_t playerIndex, uint16_t playerColor);
