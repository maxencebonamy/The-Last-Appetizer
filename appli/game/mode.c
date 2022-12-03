#include "mode.h"

static Mode mode = FAMILLE;

Mode MODE_Get(void) {
	return mode;
}

void MODE_Change(void) {
	if (++mode > 2) {
		mode = 0;
	}
}

char* MODE_ToString(void) {
	switch (mode) {
		case FAMILLE:
			return "Famille";
		case APERO:
			return "Apero";
		case HARD:
			return "Hard";
		default:
			return "";
	}
}
