# Embedded Firmware Framework Practice

This project simulates a modular embedded firmware architecture using C.

## Features
- GPIO driver abstraction
- UART driver abstraction
- Delay module
- Board configuration layer
- Multi-pin GPIO support
- Runtime telemetry
- Infinite firmware loop

## Modules
- gpio.c / gpio.h
- uart.c / uart.h
- delay.c / delay.h
- board.h

## Concepts Practiced
- Firmware architecture
- Abstraction layers
- Driver design
- State management
- Embedded debugging
- Modular firmware development

  ## Hardware Validation

Firmware was successfully flashed to the VSDSquadron Mini (CH32V003).

An external LED connected to PD4 was blinked using GPIO control and verified on hardware.
