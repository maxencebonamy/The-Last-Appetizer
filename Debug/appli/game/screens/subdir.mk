################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../appli/game/screens/action_screen.c \
../appli/game/screens/arrow_screen.c \
../appli/game/screens/end_screen.c \
../appli/game/screens/home_screen.c \
../appli/game/screens/options_screen.c \
../appli/game/screens/score_screen.c \
../appli/game/screens/selection_screen.c \
../appli/game/screens/start_screen.c 

OBJS += \
./appli/game/screens/action_screen.o \
./appli/game/screens/arrow_screen.o \
./appli/game/screens/end_screen.o \
./appli/game/screens/home_screen.o \
./appli/game/screens/options_screen.o \
./appli/game/screens/score_screen.o \
./appli/game/screens/selection_screen.o \
./appli/game/screens/start_screen.o 

C_DEPS += \
./appli/game/screens/action_screen.d \
./appli/game/screens/arrow_screen.d \
./appli/game/screens/end_screen.d \
./appli/game/screens/home_screen.d \
./appli/game/screens/options_screen.d \
./appli/game/screens/score_screen.d \
./appli/game/screens/selection_screen.d \
./appli/game/screens/start_screen.d 


# Each subdirectory must supply rules for building sources it contributes
appli/game/screens/%.o: ../appli/game/screens/%.c appli/game/screens/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../lib/bsp -I../lib//middleware/MIDI/ -I../lib/bsp/VL53L0X -I../lib/bsp/MPU6050 -I../lib/bsp/iks01a1 -I../lib/bsp/iks01a1/Common -I../lib/bsp/iks01a1/hts221 -I../lib/bsp/iks01a1/lis3mdl -I../lib/bsp/iks01a1/lps22hb -I../lib/bsp/iks01a1/lps25hb -I../lib/bsp/iks01a1/lsm6ds0 -I../lib/bsp/iks01a1/lsm6ds3 -I../lib/bsp/tft_ili9341 -I../lib/bsp/tft_pcd8544 -I../lib/bsp/MCP23S17 -I../lib/hal/inc -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MLX90614 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/MatrixLed -I../lib/CMSIS/core -I../lib/CMSIS/device -I../lib/middleware/FatFs -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../appli -O0 -ffunction-sections -fdata-sections -Wall -Wextra -Wconversion -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

