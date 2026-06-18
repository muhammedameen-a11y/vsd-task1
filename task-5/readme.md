# UART Software Oscilloscope (GPIO Sampling)

## Overview

UART Software Oscilloscope is an embedded firmware application developed for the VSDSquadron Mini (CH32V003) platform. The application demonstrates multi-driver integration by combining GPIO, Timer, and UART drivers to periodically sample a GPIO input signal and stream the sampled data over UART in CSV format. The project simulates the fundamental operation of a software oscilloscope by capturing digital signal transitions and transmitting them to a host computer for observation and analysis.

---

## Target Hardware

* Board: VSDSquadron Mini
* MCU: CH32V003F4P6
* Development Environment: MounRiver Studio
* Communication Interface: UART

---

## Supported Drivers

### GPIO Driver

Responsible for GPIO input sampling and GPIO output signal generation.

### Timer Driver

Provides fixed-interval timing and sampling control.

### UART Driver

Handles serial communication and transmission of sampled data.

---

## Project Structure

```text
task5/
└── documentation/
    ├── README.md
    ├── API_REFERENCE.md
    ├── ARCHITECTURE.md
    ├── APPLICATION_GUIDE.md
    ├── DEMO_GUIDE.md
    └── CHANGELOG.md
```

Firmware source structure:

```text
task4/
└── submission/
    ├── lib/
    │   ├── gpio.c
    │   ├── gpio.h
    │   ├── uart.c
    │   ├── uart.h
    │   ├── timer.c
    │   └── timer.h
    ├── app/
    │   └── main.c
    ├── README.md
    └── evidence.md
```

---

## Hardware Configuration

| Pin | Function                |
| --- | ----------------------- |
| PD4 | Signal Generator Output |
| PD3 | Signal Sampling Input   |

Connection:

```text
PD4 ----------> PD3
```

PD4 generates a digital square-wave signal which is sampled by PD3.

---

## UART Output Format

The application transmits sampled data using CSV format:

```text
Time_ms,Input
0,1
100,0
200,1
300,0
```

Where:

* Time_ms = Timestamp in milliseconds
* Input = Sampled GPIO state (0 or 1)

---

## Quick Start

1. Open the project in MounRiver Studio.
2. Build the firmware using F7.
3. Flash the firmware using the Download button.
4. Connect to the board using PuTTY at 115200 baud.
5. Observe CSV-formatted GPIO samples in the terminal.

---

## UART Configuration

| Parameter    | Value  |
| ------------ | ------ |
| Baud Rate    | 115200 |
| Data Bits    | 8      |
| Stop Bits    | 1      |
| Parity       | None   |
| Flow Control | None   |

---

## Expected Result

The firmware continuously samples the GPIO input at a fixed interval and streams the sampled values through UART. The output appears as a real-time CSV data stream that can be viewed in a serial terminal application.
