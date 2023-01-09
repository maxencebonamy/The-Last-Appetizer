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
    // Décrémentation de t s'il n'est pas nul
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
		RANDOM_Update();
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

void IHM_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness) {
    // Pour dessiner une ligne plus épaisse, on dessine plusieurs lignes côte à côte
    for (int8_t i = 0; i < thickness; ++i) {
        for (int8_t j = 0; j < thickness; ++j) {
            ILI9341_DrawLine(x0 + i - thickness / 2, y0 + j - thickness / 2,
            				 x1 + i - thickness / 2, y1 + j - thickness / 2, color);
        }
    }
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
	uint16_t n = 0;
	while (TRUE) {
		if (content[n] == '\0') break;
		else if (content[n] == '\n') ++contentHeight;
		++n;
	}

    char newContent[n + 1];
    for (uint16_t i = 0; i <= n; ++i) {
        if (content[i] == 'é') newContent[i] = '{';
        else if (content[i] == 'è') newContent[i] = '}';
        else if (content[i] == 'à') newContent[i] = '@';
        else if (content[i] == 'ê') newContent[i] = '$';
        else newContent[i] = content[i];
    }

	uint16_t i = 0;
	uint16_t x = 0;
	uint16_t y = 0;
	while (TRUE) {
		if (newContent[i] == '\0' || newContent[i] == '\n') {
			uint16_t xContent = ((x0 + x1) - 16 * (i - x)) / 2;
			uint16_t yContent = ((y0 + y1) - 26 * contentHeight) / 2 + 26 * y + 2;
			char subContent[i - x + 1];
			for (int j = 0; j < i - x; ++j) {
				subContent[j] = newContent[j + x];
			}
			subContent[i - x] = '\0';
			ILI9341_Puts(xContent, yContent, subContent, &Font_16x26, color, backgroundColor);
			x = i + 1;
			++y;
			if (newContent[i] == '\0') {
				break;
			}
		}
		++i;
	}
}
