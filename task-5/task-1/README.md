# VSD Task 1 – Firmware Foundations & Environment Setup

## Overview

This repository contains my submission for Task 1 of the VSD RISC-V Embedded Firmware Internship.

The objective of this task was to understand firmware fundamentals, firmware libraries, APIs, modular code organization, and to set up a working Embedded C development environment before working with actual hardware.

---

## Repository Contents

```text
main.c
gpio.c
gpio.h
README.md
Task1_Explanation.pdf
Compilation_Output_Screenshot.png
```

---

## Concepts Learned

### Embedded Firmware

Embedded firmware is software that runs directly on a microcontroller or embedded system and controls hardware behavior. Firmware acts as an interface between application logic and hardware peripherals.

### Firmware Libraries

A firmware library is a collection of reusable functions that provide access to hardware features through well-defined APIs. Libraries simplify development by hiding low-level implementation details.

### APIs in Embedded Systems

Application Programming Interfaces (APIs) provide abstraction between application code and hardware implementation. APIs improve:

* Code readability
* Modularity
* Reusability
* Maintainability
* Debugging efficiency

### Modular Firmware Design

The lab demonstrated how firmware projects are structured using separate source and header files.

```text
gpio.h   -> API declarations
gpio.c   -> API implementation
main.c   -> Application code using the API
```

This separation allows application code to use functionality without requiring knowledge of internal implementation details.

---

## Lab Implementation

### GPIO API

The GPIO library exposes the following API:

```c
void gpio_write(int pin, int state);
```

### Application Flow

The application calls the GPIO API to simulate setting a GPIO pin HIGH and LOW.

Example:

```c
gpio_write(13, 1);
gpio_write(13, 0);
```

Expected output:

```text
GPIO Pin 13 set to 1
GPIO Pin 13 set to 0
```

---

## Build Instructions

Compile using GCC:

```bash
gcc main.c gpio.c -o firmware_demo
```

Run the application:

```bash
./firmware_demo
```

---

## Verification

Successful execution was verified by:

* Compiling the program using GCC.
* Running the executable without errors.
* Observing expected GPIO simulation output in the terminal.
* Capturing terminal output with the username visible as required.

---

## Learning Outcome

Through this task, I gained an understanding of:

* Firmware architecture fundamentals
* API-based software design
* Source and header file organization
* GCC compilation workflow
* Modular embedded software development practices

These concepts form the foundation for future firmware development tasks in the internship.
