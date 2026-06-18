# Architecture

## System Overview

The UART Software Oscilloscope follows a layered embedded firmware architecture that separates hardware-specific functionality from application logic. This improves code readability, maintainability, and reusability.

The system is divided into:

1. Driver Layer
2. Application Layer

---

# High-Level Block Diagram

```text id="1i5v8c"
                +------------------+
                |   Application    |
                |      main.c      |
                +---------+--------+
                          |
        +-----------------+-----------------+
        |                 |                 |
        v                 v                 v
 +-------------+   +-------------+   +-------------+
 | GPIO Driver |   | Timer Driver|   | UART Driver |
 +------+------+   +------+------+   +------+------+
        |                 |                 |
        v                 v                 v
      PD3/PD4         SysTick           UART TX
```

---

# Driver Layer

## GPIO Driver

Responsibilities:

* Configure PD4 as signal output.
* Configure PD3 as signal input.
* Generate a digital test signal.
* Sample the input signal.

Provided APIs:

```c id="egvwyj"
gpio_input_init()
gpio_output_init()
gpio_read_input()
gpio_toggle_output()
```

---

## Timer Driver

Responsibilities:

* Provide fixed-rate sampling intervals.
* Maintain a software tick counter.
* Control application timing.

Provided APIs:

```c id="6fr31k"
timer_init()
timer_delay_ms()
timer_get_tick()
```

---

## UART Driver

Responsibilities:

* Initialize UART communication.
* Transmit sampled data.
* Stream CSV-formatted output.

Provided APIs:

```c id="e8gwmf"
uart_init()
uart_send_string()
```

---

# Application Layer

The application layer contains only high-level logic.

Responsibilities:

1. Initialize drivers.
2. Generate a test signal on PD4.
3. Sample PD3 at fixed intervals.
4. Format sampled data.
5. Transmit results over UART.

The application never accesses hardware registers directly.

All hardware interaction occurs through driver APIs.

---

# Data Flow

The following sequence occurs repeatedly:

```text id="f1bwfg"
PD4 Output
    |
    v
PD3 Input
    |
    v
GPIO Driver
    |
    v
Application
    |
    v
UART Driver
    |
    v
Serial Terminal
```

---

# Control Flow

System startup:

```text id="2h9r40"
main()
  |
  +--> uart_init()
  |
  +--> timer_init()
  |
  +--> gpio_output_init()
  |
  +--> gpio_input_init()
```

Runtime execution:

```text id="jgk3o5"
while(1)
{
    Toggle PD4
        |
        v
    Read PD3
        |
        v
    Format CSV Data
        |
        v
    Send UART Output
        |
        v
    Wait Sample Interval
}
```

---

# Design Rationale

This architecture was selected to follow industry-standard embedded software design practices.

Benefits include:

* Clear separation of concerns.
* Driver reusability.
* Simplified debugging.
* Easier maintenance.
* Improved scalability for future projects.

By isolating GPIO, Timer, and UART functionality into independent modules, the application remains independent of low-level hardware implementation details.
