# The Last Appetizer

A party game on an STM32 microcontroller, played around a spinning arrow and a touch screen.

Players sit around the board, a motor-driven arrow picks one of them, and the touch screen gives that player a random dare to carry out. Points are awarded for completed dares until one player reaches the score limit. The firmware is written in C for an STM32F103 board.

## Table of contents

- [The Last Appetizer](#the-last-appetizer)
	- [Table of contents](#table-of-contents)
	- [How it works](#how-it-works)
	- [Tech stack](#tech-stack)
	- [Repository structure](#repository-structure)
	- [Prerequisites](#prerequisites)
	- [Installation](#installation)
	- [Configuration](#configuration)
	- [Running locally](#running-locally)
	- [Useful scripts](#useful-scripts)
	- [Tests and quality](#tests-and-quality)
	- [License](#license)

## How it works

1. **Home**: the home screen shows the title and a play button.
2. **Options**: choose the game mode (`FAMILLE`, `APERO` or `HARD`) and the number of players, from 3 to 8.
3. **Selection**: each player in turn touches the screen to register their position around the board, using the current angle of the arrow.
4. **Start**: a confirmation screen resets the scores and launches the game.
5. **Arrow**: the motor spins the arrow, which then points at a player chosen at random.
6. **Action**: the chosen player gets a random dare matching the current mode. Some dares are hidden from the other players until the player chooses to reveal them. The player validates or cancels the dare, and a validated dare adds its points to their score.
7. **Scores**: a score screen shows the ranking between rounds.
8. **End**: the game ends when a player reaches 20 points.

Screens are states of a state machine driven by `GAME_Update` in the main loop.

## Tech stack

| Layer | Technologies |
| --- | --- |
| Language | C (GNU11), ARM assembly |
| Microcontroller | STM32F103 (Cortex-M3): NUCLEO-F103RB or Bluepill |
| Libraries | STM32 HAL, CMSIS, BSP drivers (`lib/bsp`) |
| Display and input | ILI9341 TFT screen with XPT2046 touch controller (SPI) |
| Actuators and sensors | DC motor driven through an H-bridge (PWM), incremental encoder read on an ADC input |
| Tooling | STM32CubeIDE, `arm-none-eabi-gcc`, OpenOCD with ST-Link |

## Repository structure

STM32CubeIDE project: application code lives in `appli/`, vendor and board libraries in `lib/`.

```
.
├── appli/
│   ├── arrow/             Arrow control: motor, encoder, angle
│   ├── chars_images/      PNG images of the characters of the Retron font
│   ├── game/              Game logic: state machine, players, modes, actions, scores
│   │   └── screens/       One source file per screen
│   ├── ihm/               Display and touch handling, game board drawing
│   ├── tests/             Hardware tests, selected by macros
│   ├── utils/             Random number helpers
│   ├── assembleur.S       Assembly source
│   ├── config.h           Board selection, pins and enabled library modules
│   └── main.c             Entry point
├── lib/
│   ├── CMSIS/             ARM core and device headers
│   ├── bsp/               Board support drivers (screen, sensors, communication modules)
│   ├── hal/               STM32F1 HAL
│   ├── middleware/        FatFs, MIDI, FFT, dialog
│   ├── LinkerScript.ld    Linker script
│   └── startup_stm32f103xb.s
├── projet-f103 Debug.cfg      OpenOCD configuration
├── projet-f103 Debug.launch   STM32CubeIDE debug configuration
└── LICENSE
```

Source files carry a French Doxygen header and are encoded in ISO-8859-1. Function names are prefixed by their module (`GAME_`, `IHM_`, `ARROW_`, `PLAYERS_`, `SCORES_`).

## Prerequisites

- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html), which provides `arm-none-eabi-gcc` and the debug tools
- A NUCLEO-F103RB board (STM32F103RBTx), or a Bluepill
- An ILI9341 TFT screen with XPT2046 touch controller
- A DC motor with an H-bridge and an incremental encoder, wired as described in `appli/arrow/arrow.h`

## Installation

```bash
git clone git@github.com:maxencebonamy/The-Last-Appetizer.git
cd The-Last-Appetizer
```

Import the folder in STM32CubeIDE with `File > Open Projects from File System...`. The project is named `projet-f103`.

## Configuration

There is no `.env` file. The target is set in `appli/config.h`:

| Macro | Description | Example |
| --- | --- | --- |
| `MY_BLUEPILL_IS_COUNTERFEIT` | Target board, `NUCLEO` or `BLUEPILL` | `BLUEPILL` |
| `USE_SCREEN_TFT_ILI9341` | Enables the TFT screen driver | `1` |
| `USE_XPT2046` | Enables the touch controller | `1` |
| `USE_MOTOR_DC` | Enables the DC motor driver | `1` |
| `USE_ADC` | Enables the analog inputs used by the encoder | `1` |
| `TRACE` | Debugging on a QEMU simulator, keep at `0` | `0` |

The Debug build configuration declares `NUCLEO_F103RB` and `STM32F103RBTx`. The motor is wired to `PA8` and `PB13`, and the encoder to `PA1`.

## Running locally

1. Select the project in STM32CubeIDE.
2. Build the `Debug` configuration.
3. Connect the board through its ST-Link and run `projet-f103 Debug` to flash and debug.

## Useful scripts

The repository has no script. Commands are those of STM32CubeIDE:

| Command | Effect |
| --- | --- |
| `Project > Build Project` | Build the `Debug` configuration |
| `Project > Clean...` | Remove the build output in `Debug/` |
| `Run > Debug` | Flash the board and start a debug session |

## Tests and quality

Tests are hardware tests that run on the board. They are selected in `appli/tests/tests.h`: set one macro to `1`, then build and flash. Tests are blocking, so only the first enabled one runs, before the game starts.

| Macro | Test |
| --- | --- |
| `SCREEN_WRITE_TEXT` | Text display |
| `SCREEN_DRAW_SHAPES` | Shape drawing |
| `SCREEN_BUTTON_CLICK` | Button clicks |
| `SCREEN_GAME_BOARD` | Game board display |
| `UTILS_GENERATE_RANDOM_NUMBERS` | Random number generation |
| `ARROW_TURN` | Arrow rotation |
| `ARROW_GET_ANGLE` | Arrow angle reading |
| `ARROW_TURN_UNTIL` | Arrow rotation to a target angle |

The build uses `-Wall -Wextra -Wconversion`.

## License

This project is licensed under the [MIT License](LICENSE).
