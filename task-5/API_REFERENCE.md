# API Reference

## Overview

This document describes the public APIs exposed by the UART Software Oscilloscope firmware. The firmware is organized into three reusable driver modules:

* GPIO Driver
* Timer Driver
* UART Driver

All application logic interacts with hardware exclusively through these APIs.

---

# GPIO Driver

Files:

```text
gpio.h
gpio.c
```

## gpio_input_init()

```c
void gpio_input_init(void);
```

### Description

Initializes PD3 as a digital input pin used for GPIO signal sampling.

### Parameters

None.

### Return Value

None.

### Constraints

* PD3 is reserved as the oscilloscope input channel.
* Must be called before `gpio_read_input()`.

### Example

```c
gpio_input_init();
```

---

## gpio_output_init()

```c
void gpio_output_init(void);
```

### Description

Initializes PD4 as a digital output pin used to generate the test signal.

### Parameters

None.

### Return Value

None.

### Constraints

* PD4 is used as the signal source.
* Must be called before `gpio_toggle_output()`.

### Example

```c
gpio_output_init();
```

---

## gpio_read_input()

```c
uint8_t gpio_read_input(void);
```

### Description

Reads the current logic level present on PD3.

### Parameters

None.

### Return Value

| Value | Meaning    |
| ----- | ---------- |
| 0     | Logic LOW  |
| 1     | Logic HIGH |

### Example

```c
uint8_t sample;

sample = gpio_read_input();
```

---

## gpio_toggle_output()

```c
void gpio_toggle_output(void);
```

### Description

Toggles the state of PD4 between HIGH and LOW.

### Parameters

None.

### Return Value

None.

### Example

```c
gpio_toggle_output();
```

---

# Timer Driver

Files:

```text
timer.h
timer.c
```

## timer_init()

```c
void timer_init(void);
```

### Description

Initializes the timer subsystem and prepares the delay functionality.

### Parameters

None.

### Return Value

None.

### Example

```c
timer_init();
```

---

## timer_delay_ms()

```c
void timer_delay_ms(uint32_t ms);
```

### Description

Generates a blocking delay for the specified duration.

### Parameters

| Parameter | Description                    |
| --------- | ------------------------------ |
| ms        | Delay duration in milliseconds |

### Return Value

None.

### Example

```c
timer_delay_ms(100);
```

---

## timer_get_tick()

```c
uint32_t timer_get_tick(void);
```

### Description

Returns the current software tick count maintained by the timer module.

### Parameters

None.

### Return Value

Current tick value in milliseconds.

### Example

```c
uint32_t time_ms;

time_ms = timer_get_tick();
```

---

# UART Driver

Files:

```text
uart.h
uart.c
```

## uart_init()

```c
void uart_init(void);
```

### Description

Initializes UART communication at 115200 baud.

### Parameters

None.

### Return Value

None.

### Example

```c
uart_init();
```

---

## uart_send_string()

```c
void uart_send_string(char *str);
```

### Description

Transmits a null-terminated string through UART.

### Parameters

| Parameter | Description        |
| --------- | ------------------ |
| str       | String to transmit |

### Return Value

None.

### Constraints

* String must be null-terminated.
* Buffer ownership remains with the caller.

### Example

```c
uart_send_string("Hello World\r\n");
```

---

# Integration Example

```c
uart_init();
timer_init();

gpio_output_init();
gpio_input_init();

while(1)
{
    gpio_toggle_output();

    uint8_t sample = gpio_read_input();

    timer_delay_ms(100);
}
```

This example demonstrates how the GPIO, Timer, and UART drivers are combined to implement the UART Software Oscilloscope application.
