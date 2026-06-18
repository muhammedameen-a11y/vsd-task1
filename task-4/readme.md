# UART Software Oscilloscope (GPIO Sampling)

## Overview

This project implements a simple UART-based software oscilloscope using the VSDSquadron Mini (CH32V003). A GPIO input pin is sampled at a fixed interval using a timer, and the sampled values are transmitted over UART in CSV format for visualization and analysis.

---

## Implemented Libraries

### GPIO Library

Provides GPIO initialization and input/output control functions.

### Timer Library

Provides timing and delay functionality required for fixed-rate sampling.

### UART Library

Provides UART initialization and serial communication functions.

---

## API List

### GPIO APIs

| Function               | Description                           |
| ---------------------- | ------------------------------------- |
| `gpio_output_init()`   | Initializes PD4 as GPIO output.       |
| `gpio_input_init()`    | Initializes PD3 as GPIO input.        |
| `gpio_toggle_output()` | Toggles the output state of PD4.      |
| `gpio_read_input()`    | Reads the current logic level of PD3. |

### Timer APIs

| Function                      | Description                            |
| ----------------------------- | -------------------------------------- |
| `timer_init()`                | Initializes the timer module.          |
| `timer_delay_ms(uint32_t ms)` | Generates a delay in milliseconds.     |
| `timer_get_tick()`            | Returns the current system tick count. |

### UART APIs

| Function                            | Description                     |
| ----------------------------------- | ------------------------------- |
| `uart_init()`                       | Initializes UART communication. |
| `uart_send_string(const char *str)` | Sends a string over UART.       |

---

## Demo Application

The application generates a square-wave signal on GPIO pin PD4 and connects it externally to GPIO pin PD3.

PD3 is sampled periodically at a configurable sampling interval and the sampled value is transmitted through UART in CSV format.

### GPIO Connections

| Pin | Function      |
| --- | ------------- |
| PD4 | Signal Output |
| PD3 | Signal Input  |

External Connection:

PD4 → PD3

---

## Sample Rate Configuration

The sampling interval is configurable through:

```c
#define SAMPLE_RATE_MS 100
```

Current sampling rate:

* 100 ms/sample
* 10 samples/second

---

## Output Format

CSV format is used.

Example:

```text
Time_ms,Input
0,1
100,0
200,1
300,0
```

Where:

* `Time_ms` = timestamp in milliseconds
* `Input` = sampled GPIO state (0 or 1)

---

## UART Configuration

| Parameter    | Value  |
| ------------ | ------ |
| Baud Rate    | 115200 |
| Data Bits    | 8      |
| Stop Bits    | 1      |
| Parity       | None   |
| Flow Control | None   |

COM Port is assigned by the operating system and may vary.

---

## Build Procedure

1. Open the project in MounRiver Studio.
2. Build the project using:

   * **F7** or
   * Project → Build Project
3. Verify successful generation of the `.hex` file.

---

## Flash Procedure

1. Connect the VSDSquadron Mini board via USB.
2. Click **Download** in MounRiver Studio.
3. Wait for:

   ```
   Download Finished
   ```
4. Open a serial terminal (PuTTY).
5. Select the assigned COM port.
6. Configure UART to 115200 baud.
7. Observe the streamed GPIO samples.
