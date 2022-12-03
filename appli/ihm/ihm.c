/**
 * @brief IHM (Interface Homme-Machine) qui permet de gérer l'affichage et le mode tactile de l'écran
 * @author Maxence & Aymeric
 */

#include "ihm.h"


/// Coordonné x de l'endroit où l'utilisateur clique sur l'écran
static int16_t xPointer = -1;
/// Coordonné y de l'endroit où l'utilisateur clique sur l'écran
static int16_t yPointer = -1;

/// Valeur indiquant si l'utilisateur est en train de cliquer sur l'écran
static bool_e isClicking = FALSE;


void IHM_Init(void) {
	// Initialisation de l'écran
	ILI9341_Init();
	// Orientation de l'écran au format paysage dans le bon sens
	ILI9341_Rotate(ILI9341_Orientation_Landscape_1);
	// Initialisation du mode tactile de l'écran
	XPT2046_init();
}

void IHM_Update(void) {
    // Variable qui va permettre d'ajouter un délai entre chaque clic
	static volatile uint8_t t = 0;
    // Décrémentation de t si il n'est pas nul
	if (t) {
		--t;
	}
    // Variables qui vont contenir les coordonnées de l'endroit où l'utilisateur clique sur l'écran
	int16_t x, y;

    // Remise à false pour avoir un clic instantané
	if (isClicking) {
		isClicking = FALSE;
	}
    // Vérification du clic de l'utilisateur (t doit être nul pour avoir un délai)
	if (XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE) && !t) {
        // Le délai correspond à 50ms (la fonction update est appelée chaque ms)
		t = 50;
		xPointer = x;
		yPointer = y;
		isClicking = TRUE;
	}
}

bool_e IHM_Collide(const IHM_Rect* rect) {
	return rect->x0 <= xPointer && xPointer <= rect->x1 &&
		   rect->y0 <= yPointer && yPointer <= rect->y1;
}

bool_e IHM_IsClicking(void) {
	return isClicking;
}

void IHM_Fill(uint16_t color) {
	ILI9341_Fill(color);
}

void IHM_DrawFilledRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) {
	ILI9341_DrawFilledRectangle(x0, y0, x1, y1, color);
}

void IHM_DrawFilledRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint16_t radius) {
    // Un rectangle à coins arrondis se dessine avec 4 cercles remplis (1 sur chaque coin)
    // ainsi que 3 rectangles pour combler les trous

    // Cercle en haut à gauche
    ILI9341_DrawFilledCircle(x0 + radius, y0 + radius, radius, color);
    // Cercle en haut à droite
    ILI9341_DrawFilledCircle(x1 - radius, y0 + radius, radius, color);
    // Cercle en bas à gauche
    ILI9341_DrawFilledCircle(x0 + radius, y1 - radius, radius, color);
    // Cercle en bas à droite
    ILI9341_DrawFilledCircle(x1 - radius, y1 - radius, radius, color);

    // Rectangle en haut
    ILI9341_DrawFilledRectangle(x0 + radius, y0, x1 - radius, y0 + 2 * radius, color);
    // Rectangle au centre
    ILI9341_DrawFilledRectangle(x0, y0 + radius, x1, y1 - radius, color);
    // Rectangle en bas
    ILI9341_DrawFilledRectangle(x0 + radius, y1 - 2 * radius, x1 - radius, y1, color);
}

void IHM_DrawRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint16_t borderColor, uint16_t radius) {
    // Un rectangle à coins arrondis non rempli se dessine avec un rectangle "arrondi" qu'on superpose par un autre
    // rectangle "arrondi" de taille légèrement inférieure qui a la couleur du fond

    // Rectangle qui joue le rôle de la bordure
	IHM_DrawFilledRoundedRectangle(x0, y0, x1, y1, borderColor, radius);
    // Rectangle qui joue le rôle du fond (légèrement plus petit)
	IHM_DrawFilledRoundedRectangle(x0 + 2, y0 + 2, x1 - 2, y1 - 2, color, radius - 2);
}

void IHM_DisplayButton(IHM_Rect* rect, char* title, uint16_t color) {
    // Un bouton est composé d'un rectangle à coins arrondis et d'un titre (texte)
	IHM_DrawFilledRoundedRectangle(rect->x0, rect->y0, rect->x1, rect->y1, color, (rect->y1 - rect->y0) / 2);
	IHM_Write(rect->x0, rect->y0, rect->x1, rect->y1, title, IHM_COLOR_WHITE, color);
}

void IHM_Write(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char* content, uint16_t color, uint16_t backgroundColor) {
	uint16_t contentHeight = 1;
	uint16_t i = 0;
	while (TRUE) {
		if (content[i] == '\0') {
			break;
		}
		if (content[i] == '\n') {
			++contentHeight;
		}
		++i;
	}

	i = 0;
	uint16_t x = 0;
	uint16_t y = 0;
	while (TRUE) {
		if (content[i] == '\0' || content[i] == '\n') {
			uint16_t xContent = ((x0 + x1) - 16 * (i - x)) / 2;
			uint16_t yContent = ((y0 + y1) - 26 * contentHeight) / 2 + 26 * y + 2;
			char subContent[i - x + 1];
			for (int j = 0; j < i - x; ++j) {
				subContent[j] = content[j + x];
			}
			subContent[i - x] = '\0';
			ILI9341_Puts(xContent, yContent, subContent, &Font_16x26, color, backgroundColor);
			x = i + 1;
			++y;
			if (content[i] == '\0') {
				break;
			}
		}
		++i;
	}
}

void IHM_DrawPlayer(uint16_t x, uint16_t y, uint16_t color) {
	ILI9341_DrawCircle(x, y - 7, 8, color);
	ILI9341_DrawCircle(x, y - 7, 7, color);

	ILI9341_DrawLine(x - 2, y + 2, x - 7, y + 14, color);
	ILI9341_DrawLine(x - 3, y + 2, x - 8, y + 14, color);

	ILI9341_DrawLine(x + 2, y + 2, x + 7, y + 14, color);
	ILI9341_DrawLine(x + 3, y + 2, x + 8, y + 14, color);

	ILI9341_DrawLine(x - 8, y + 14, x + 8, y + 14, color);
	ILI9341_DrawLine(x - 8, y + 13, x + 8, y + 13, color);
}

void IHM_DrawGameBoard(uint16_t x, uint16_t y, uint8_t playerIndex, uint16_t arrowColor) {
	uint16_t radius = 40;

	ILI9341_DrawFilledCircle(x, y, radius, IHM_COLOR_BLACK);
	ILI9341_DrawFilledCircle(x, y, radius - 2, IHM_COLOR_WHITE);

	for (uint8_t i = 0; i <= 1; ++i) {
		for (uint8_t j = 0; j <= 1; ++j) {
			ILI9341_DrawLine(
				x + i, y + j,
				x + i + (radius - 10) * cos(3.14 * 2 * playerIndex / PLAYERS_Get()),
				y + j + (radius - 10) * sin(3.14 * 2 * playerIndex / PLAYERS_Get()),
				arrowColor
			);
			ILI9341_DrawLine(
				x + i + (radius - 10) * cos(3.14 * 2 * playerIndex / PLAYERS_Get()),
				y + j + (radius - 10) * sin(3.14 * 2 * playerIndex / PLAYERS_Get()),
				x + i + (radius - 20) * cos(3.14 * 2 * playerIndex / PLAYERS_Get() - 0.4),
				y + j + (radius - 20) * sin(3.14 * 2 * playerIndex / PLAYERS_Get() - 0.4),
				arrowColor
			);
			ILI9341_DrawLine(
				x + i + (radius - 10) * cos(3.14 * 2 * playerIndex / PLAYERS_Get()),
				y + j + (radius - 10) * sin(3.14 * 2 * playerIndex / PLAYERS_Get()),
				x + i + (radius - 20) * cos(3.14 * 2 * playerIndex / PLAYERS_Get() + 0.4),
				y + j + (radius - 20) * sin(3.14 * 2 * playerIndex / PLAYERS_Get() + 0.4),
				arrowColor
			);
		}
	}

	for (uint8_t i = 0; i < PLAYERS_Get(); ++i) {
		IHM_DrawPlayer(
			x + (radius + 20) * cos(3.14 * 2 * i / PLAYERS_Get()),
			y + (radius + 20) * sin(3.14 * 2 * i / PLAYERS_Get()),
			i == playerIndex ? arrowColor : IHM_COLOR_BLACK
		);
	}
}
