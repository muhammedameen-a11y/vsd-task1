# Task 3 - Timer Module Library

## Overview

This task implements a custom timer library for the VSDSquadron Mini (CH32V003F4P6). The library provides simple APIs for timer initialization, delay generation, and system tick counting. A demo application uses the library to blink an external LED connected to PD4 and transmit status messages over UART.

---

## Implemented Library

**Timer Library**

Files:

* `timer.c`
* `timer.h`

The library uses the SysTick timer to generate millisecond delays and maintain a system tick counter.

---

## API List

### `void timer_init(void)`

Initializes the timer subsystem and configures SysTick.

### `void timer_delay_ms(uint32_t ms)`

Creates a blocking delay for the specified number of milliseconds.

### `uint32_t timer_get_tick(void)`

Returns the current system tick count in milliseconds since startup.

---

## Demo Application

The demo application performs the following operations:

1. Initializes the timer library.
2. Configures PD4 as a GPIO output.
3. Initializes UART communication at 115200 baud.
4. Toggles an external LED connected to PD4 every 500 ms.
5. Sends status messages to the serial terminal:

   * `LED ON`
   * `LED OFF`

This demonstrates the use of the timer library for periodic task execution.

---

## Hardware Connections

| VSDSquadron Mini | External Component                    |
| ---------------- | ------------------------------------- |
| PD4              | LED Anode (+)                         |
| GND              | LED Cathode (-) through 220Ω resistor |

---

## Build and Flash Instructions

1. Open the project in MounRiver Studio.
2. Build the project using:

   * **Project → Build Project** or **F7**
3. Connect the VSDSquadron Mini board via USB.
4. Flash the firmware using:

   * **Flash → Download** or **F8**
5. Verify successful download from the output console.

---

## UART Configuration

| Parameter | Value                  |
| --------- | ---------------------- |
| Interface | UART                   |
| Baud Rate | 115200                 |
| Data Bits | 8                      |
| Parity    | None                   |
| Stop Bits | 1                      |
| COM Port  | WCH-Link SERIAL (COM3) |

Terminal software used:

* PuTTY
* Serial connection
* COM3
* 115200 baud

---

## Expected Output

### LED

External LED connected to PD4 blinks continuously at 500 ms intervals.

### Serial Terminal

LED ON

LED OFF

LED ON

LED OFF

...
