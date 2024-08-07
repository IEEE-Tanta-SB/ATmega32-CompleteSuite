# ATmega32 CompleteSuite
![image](https://github.com/IEEE-Tanta-SB/ATmega32-CompleteSuite/assets/174888441/a562623b-c1ba-4ec3-916b-456c17706c27)

Explore projects and code examples for the ATmega32 microcontroller.

## Our Complete Suite
1. ATmega32 Drivers like: GPIO, Timers,.. 
2. HAL interfacing like LEDs, Motors, LCDs,..
3. Common interesting applications using ATmega32
4. Mega Projects Soon :)

## How to Use the Repository

### Prerequisites
- AVR-GCC
- Make
- avrdude (for flashing the microcontroller)
- Eclipse IDE (preferred)

### Directory Structure (Open the repo as workspace in Eclipse)
- `0_DOCs/`
- `1_MCAL/`
- `2_HAL/`
- `3_APP/`
- `4_Common/`
- `main/`

### Setting Up the Development Environment
1. Install AVR-GCC:
    - On Debian/Ubuntu: `sudo apt-get install gcc-avr avr-libc`
    - On macOS: `brew tap osx-cross/avr && brew install avr-gcc`
    - On Windows: Install [AVR-GCC](http://blog.zakkemble.net/avr-gcc-builds/)
        - Download and install the AVR-GCC package from the link.
        - Ensure the AVR-GCC binaries are added to your system PATH.
2. Install Make:
    - On Debian/Ubuntu: `sudo apt-get install make`
    - On macOS: `brew install make`
    - On Windows: Install [Make for Windows](http://gnuwin32.sourceforge.net/packages/make.htm):
      - Download and install Make from the link.
      - Ensure the Make binaries are added to your system PATH.
3. Clone the repository:
    ```
    git clone https://github.com/IEEE-Tanta-SB/ATmega32-CompleteSuite
    cd ATmega32-CompleteSuite
    ```
4. Build the project:
    ```
    make
    ```
5. Flash the firmware:
    ```
    make flash
    ```
