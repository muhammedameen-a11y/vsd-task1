# Evidence – UART Software Oscilloscope (GPIO Sampling)

## UART Evidence

### Serial Output Capture

The application streams sampled GPIO input values over UART in CSV format.

UART Configuration:

* Baud Rate: 115200
* Data Bits: 8
* Stop Bits: 1
* Parity: None
* Flow Control: None

Output Format:

```text
Time_ms,Input
```

Example Output Captured from PuTTY:

```text
114400,1
114500,0
114600,1
114700,0
114800,1
114900,0
115000,1
115100,0
115200,1
115300,0
115400,1
115500,0
```

### Screenshot Evidence

 PuTTY screenshot showing at least 10 lines of UART output.

File:
![implementedSS](<Screenshot (110).png>)

---

## Hardware Evidence

### Hardware Setup

The software oscilloscope was implemented using the VSDSquadron Mini board.

GPIO Connections:

```text
PD4  ---------->  PD3
(Output)         (Input)
```

PD4 generates a square-wave signal that is sampled by PD3.

### Hardware Verification

The following behaviors were verified:

1. PD4 successfully toggles between HIGH and LOW states.
2. PD3 correctly samples the incoming signal from PD4.
3. Timer provides fixed-rate sampling.
4. UART continuously streams sampled values.
5. CSV output reflects the GPIO state transitions accurately.

### Hardware Photos

![Hardwaresetup](<WhatsApp Image 2026-06-18 at 22.34.57.jpeg>)

1. VSDSquadron Mini board connected to the breadboard.
2. PD4 to PD3 jumper connection.
3. LED connected to PD4 showing signal activity.
4. Complete hardware setup.

Files:

* board_setup.jpg
* gpio_connection.jpg
* led_output.jpg

---

## Application Explanation

### Library Usage

This project uses three custom drivers:

#### GPIO Driver

* Configures PD4 as digital output.
* Configures PD3 as digital input.
* Reads and writes GPIO states.

#### Timer Driver

* Provides fixed sampling intervals.
* Controls the sample rate through software delays.

#### UART Driver

* Initializes UART communication.
* Transmits sampled data to a serial terminal.

---

## Verification on Hardware

The application was successfully executed on the VSDSquadron Mini hardware.

proof video:
<video controls src="WhatsApp Video 2026-06-18 at 22.39.36.mp4" title="impvid"></video>

Verified Results:

* GPIO output generation working.
* GPIO input sampling working.
* Configurable sample rate implemented.
* UART communication working at 115200 baud.
* CSV output format verified.
* Continuous real-time streaming verified through PuTTY.

Result:

The UART Software Oscilloscope successfully samples a GPIO input at a fixed interval and streams the sampled values over UART in the required CSV format.
