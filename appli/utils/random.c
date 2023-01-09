#include "random.h"


#define NB_VALUES 1000


static uint32_t values[NB_VALUES];
static uint16_t loadIndex = 0;


void RANDOM_Init(void) {
//    uint16_t seed = ADC_getValue(ADC_CHANNEL_1);
//    seed = ADC_getValue(ADC_CHANNEL_1);
//    srand(seed);
}

void RANDOM_Update(void) {
    if (loadIndex < NB_VALUES) {
        values[loadIndex++] = HAL_GetTick();
    }
}

uint16_t RANDOM_Get(uint16_t min, uint16_t max) {
    uint16_t value = values[0] % (max - min + 1) + min;

    for (uint16_t i = 0; i < loadIndex; ++i) {
        values[i] = values[i + 1];
    }
    --loadIndex;

    return value;
	// return HAL_GetTick() % (max - min + 1) + min;
    // return ADC_getValue(ADC_CHANNEL_1) % (max - min + 1) + min;
}
