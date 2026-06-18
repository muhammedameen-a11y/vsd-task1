# Demo Guide

## Purpose

This guide explains how to build, flash, execute, and verify the UART Software Oscilloscope application on the VSDSquadron Mini platform.

---

# Hardware Requirements

* VSDSquadron Mini Board
* USB Cable
* Jumper Wire
* PC with MounRiver Studio
* PuTTY (or equivalent serial terminal)

---

# Hardware Connections

Connect the GPIO pins as follows:

```text id="w8dfaq"
PD4 ----------> PD3
```

Where:

* PD4 = Signal Generator Output
* PD3 = Signal Sampling Input

---

# Build Procedure

1. Open the project in MounRiver Studio.
2. Verify all source files are present.
3. Press **F7** to build the project.
4. Confirm successful compilation.

Expected result:

```text id="ejem4n"
Build Finished
```

---

# Flash Procedure

1. Connect the VSDSquadron Mini board via USB.
2. Click the Download button in MounRiver Studio.
3. Wait for programming to complete.

Expected result:

```text id="u1ydvn"
Download Finished
Verify Finished
```

---

# UART Configuration

Configure PuTTY using:

| Parameter    | Value                   |
| ------------ | ----------------------- |
| Serial Port  | COM3 (or assigned port) |
| Baud Rate    | 115200                  |
| Data Bits    | 8                       |
| Stop Bits    | 1                       |
| Parity       | None                    |
| Flow Control | None                    |

---

# Running the Demo

1. Open PuTTY.
2. Connect to the configured serial port.
3. Reset the board if required.
4. Observe the UART output stream.

Expected CSV format:

```text id="rbw9hf"
Time_ms,Input
114400,1
114500,0
114600,1
114700,0
```

---

# Verification Checklist

Verify the following:

* GPIO output generation on PD4.
* GPIO sampling on PD3.
* UART communication functioning.
* CSV output format maintained.
* Fixed sampling interval observed.

---

# Expected Hardware Behavior

The application continuously:

1. Generates a square-wave signal on PD4.
2. Samples the signal on PD3.
3. Streams sampled values over UART.

The UART terminal should display alternating HIGH and LOW values corresponding to the generated signal.

---

# Success Criteria

The demo is considered successful when:

* UART continuously displays CSV-formatted samples.
* Sampled values alternate between 0 and 1.
* The system operates without errors or crashes.
* The GPIO signal is correctly captured and transmitted.
