# Architecture Overview

The clock consists of three main subsystems:

1. Timekeeping logic
2. Display multiplexing
3. User input (buttons)

---

## Timekeeping

- Software-based time tracking
- Seconds increment every 1000 ms
- Minutes and hours cascade naturally
- Clock pauses during time-setting mode

---

## Display Multiplexing

- All segment pins are shared
- Each digit has a dedicated transistor
- Only one digit is active at a time
- Fast cycling creates persistence of vision

---

## User Input

- MODE button selects Hour / Minute / Run
- INC button increments selected field
- Internal pull-up resistors used
