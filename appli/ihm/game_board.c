/**
 * @brief Gestion de l'affichage du plateau du jeu (bol, flèche et joueurs)
 * @author Maxence & Aymeric
 */

#include "game_board.h"


/// Rayon du plateau (sans compter les joueurs)
#define RADIUS 40
/// Couleur de la flèche
#define ARROW_COLOR IHM_COLOR_BLUE

/// Coordonnée x du centre du plateau (au centre par défaut)
static uint16_t xCenter = 160;
/// Coordonnée y du centre du plateau (au centre par défaut)
static uint16_t yCenter = 120;
/// Angle de la flèche par rapport au centre du plateau (vers le bas par défaut)
static float_t arrowAngle = 0.f;
/// Vitesse de rotation de la flèche (en rad / ms)
static float_t arrowRotationSpeed = 0.f;


void GAME_BOARD_SetCenterPosition(uint16_t x, uint16_t y) {
    xCenter = x;
    yCenter = y;
}

void GAME_BOARD_SetPlayerPointed(uint8_t playerIndex) {
    // Rapport de l'indice du joueur sur le nombre de joueurs, multiplié par 2 * pi
    arrowAngle = 3.14 * 2 * playerIndex / PLAYERS_GetCount();
}

void GAME_BOARD_SetArrowRotationSpeed(float_t value) {
    arrowRotationSpeed = value;
}

void GAME_BOARD_Update(void) {
    // On tourne la flèche seulement lorsque la vitesse de rotation n'est pas nulle
    if (arrowRotationSpeed) {
        // Pour effacer la flèche, on en dessine une blanche
        GAME_BOARD_DrawArrow(IHM_COLOR_WHITE);
        // Incrémentation de l'angle
        arrowAngle += arrowRotationSpeed;
        // On dessine à nouveau la flèche
        GAME_BOARD_DrawArrow(ARROW_COLOR);
    }
}

void GAME_BOARD_Display() {
    // Affichage du plateau : cercle blanc par-dessus un cercle noir un peu plus grand
    // pour donner l'illusion d'un cercle vide avec une bordure
    ILI9341_DrawFilledCircle(xCenter, yCenter, RADIUS, IHM_COLOR_BLACK);
    ILI9341_DrawFilledCircle(xCenter, yCenter, RADIUS - 3, IHM_COLOR_WHITE);

    // Affichage de la flèche
    GAME_BOARD_DrawArrow(ARROW_COLOR);

    // Affichage de tous les joueurs
    // L'angle est calculé avec la formule des racines complexes n-ièmes de l'unité
    for (uint8_t i = 0; i < PLAYERS_GetCount(); ++i) {
        GAME_BOARD_DrawPlayer(
            xCenter + (RADIUS + 20) * sin(3.14 * 2 * i / PLAYERS_GetCount()),
            yCenter + (RADIUS + 20) * cos(3.14 * 2 * i / PLAYERS_GetCount()),
            IHM_COLOR_BLACK
        );
    }
}

static void GAME_BOARD_DrawArrow(uint16_t color) {
    // Ligne principale de la flèche
    IHM_DrawLine(
        xCenter, yCenter,
        xCenter + (RADIUS - 10) * sin(arrowAngle),
        yCenter + (RADIUS - 10) * cos(arrowAngle),
        color,
        2
    );

    // Lignes secondaires de la flèche
    IHM_DrawLine(
        xCenter + (RADIUS - 10) * sin(arrowAngle),
        yCenter + (RADIUS - 10) * cos(arrowAngle),
        xCenter + (RADIUS - 20) * sin(arrowAngle - 0.4),
        yCenter + (RADIUS - 20) * cos(arrowAngle - 0.4),
        color,
        2
    );
    IHM_DrawLine(
        xCenter + (RADIUS - 10) * sin(arrowAngle),
        yCenter + (RADIUS - 10) * cos(arrowAngle),
        xCenter + (RADIUS - 20) * sin(arrowAngle + 0.4),
        yCenter + (RADIUS - 20) * cos(arrowAngle + 0.4),
        color,
        2
    );
}

static void GAME_BOARD_DrawPlayer(uint16_t x, uint16_t y, uint16_t color) {
    // Un joueur est composé d'un cercle et d'un triangle (trois lignes)
    ILI9341_DrawFilledCircle(x, y - 7, 8, color);
    ILI9341_DrawFilledCircle(x, y - 7, 5, IHM_COLOR_WHITE);

    IHM_DrawLine(x - 2, y + 2, x - 8, y + 14, color, 3);
    IHM_DrawLine(x + 2, y + 2, x + 8, y + 14, color, 3);
    IHM_DrawLine(x - 8, y + 14, x + 8, y + 14, color, 3);
}
