# Application Guide

## Overview

The UART Software Oscilloscope application demonstrates periodic GPIO sampling using a timer-driven workflow. The application generates a digital signal on one GPIO pin and samples the signal on another GPIO pin at a fixed interval. Sampled values are transmitted over UART in CSV format for observation and analysis.

The application uses the following drivers:

* GPIO Driver
* Timer Driver
* UART Driver

---

# Application Purpose

The primary objective of the application is to simulate a simple software oscilloscope capable of:

* Sampling a digital signal.
* Producing timestamped measurements.
* Streaming measurements to a host computer.
* Demonstrating coordinated use of multiple embedded drivers.

---

# Application State Model

The application operates using a single continuous execution state.

```text id="zbbh3f"
+-----------+
|  Startup  |
+-----+-----+
      |
      v
+-----------+
| Initialize|
| Drivers   |
+-----+-----+
      |
      v
+-----------+
| Sampling  |
| Loop      |
+-----------+
```

No additional operating modes are used.

---

# Startup Sequence

During startup the application performs the following operations:

1. Initialize UART communication.
2. Initialize timer services.
3. Configure PD4 as output.
4. Configure PD3 as input.
5. Transmit CSV header.

Initialization order:

```text id="mppg7l"
uart_init()
timer_init()
gpio_output_init()
gpio_input_init()
```

---

# Signal Generation

PD4 is configured as a digital output pin.

The application periodically toggles PD4 between HIGH and LOW states:

```text id="j4rzfd"
HIGH
LOW
HIGH
LOW
...
```

This creates a square-wave test signal.

---

# Signal Sampling

PD3 is configured as a digital input pin.

A jumper wire connects:

```text id="9slh0j"
PD4 ---> PD3
```

The GPIO driver samples the signal level present on PD3.

Possible values:

| Value | Meaning |
| ----- | ------- |
| 0     | LOW     |
| 1     | HIGH    |

---

# Timing Behavior

The sampling interval is controlled by:

```c id="gx0i5v"
#define SAMPLE_RATE_MS 100
```

Current configuration:

| Parameter          | Value  |
| ------------------ | ------ |
| Sample Interval    | 100 ms |
| Samples per Second | 10     |

The timer driver enforces a fixed delay between samples.

---

# UART Streaming

Each sample is formatted as a CSV record:

```text id="cgt4zx"
Time_ms,Input
114400,1
114500,0
114600,1
```

Fields:

| Field   | Description        |
| ------- | ------------------ |
| Time_ms | Software timestamp |
| Input   | Sampled GPIO value |

This format allows the data to be imported into spreadsheets, plotting tools, or external analysis software.

---

# Driver Orchestration

The application coordinates all drivers using the following sequence:

```text id="z10gqo"
Toggle Output
      |
      v
Read Input
      |
      v
Get Timestamp
      |
      v
Transmit CSV Record
      |
      v
Delay Until Next Sample
```

Each driver performs a single responsibility while the application manages overall behavior.

---

# Edge Cases

## Startup State

The initial GPIO state may be HIGH or LOW depending on startup timing. This does not affect operation because continuous sampling begins immediately.

## UART Terminal Not Connected

The application continues executing normally even if no serial terminal is connected.

## Signal Connection Removed

If the PD4-to-PD3 jumper is disconnected, the sampled values may remain fixed or become undefined depending on the input state.

## Sample Rate Changes

Changing:

```c id="o1k9k9"
SAMPLE_RATE_MS
```

directly changes the sampling frequency without requiring driver modifications.

---

# Expected Behavior

During normal operation:

1. PD4 continuously toggles.
2. PD3 continuously samples the signal.
3. UART continuously streams CSV data.
4. Sampling occurs at a fixed interval.
5. Data appears in real time on the host terminal.

This demonstrates successful integration of GPIO, Timer, and UART drivers into a complete embedded application.
