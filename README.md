# Standalone Digital Clock using ATmega328P

A fully standalone digital clock built using the ATmega328P microcontroller and four individual 7-segment displays.  
This project avoids Arduino boards and display driver ICs to deeply understand multiplexing, timing, and embedded hardware design.

---

## 🔹 Overview

- Microcontroller: ATmega328P-PU (standalone)
- Display: 4 × individual 7-segment displays (Common Cathode)
- Format: HH:MM
- Time setting: 2 tactile buttons (MODE + INC)
- Clock source: External 16 MHz crystal
- Display driving: Transistor-based multiplexing
- No RTC module used

---

## 🔹 Features

| Feature | Status |
|------|------|
| Standalone ATmega328P | ✅ |
| 4-digit multiplexing | ✅ |
| HH:MM time format | ✅ |
| Manual time setting | ✅ |
| Blinking separator | ✅ |
| External crystal | ✅ |
| No Arduino board | ✅ |
| No display driver IC | ✅ |

---

## 🔹 What This Project Is NOT

- ❌ Not Arduino Uno based
- ❌ No TM1637 / MAX7219
- ❌ No RTC module
- ❌ No external libraries
- ❌ No ready-made display modules

---

## 🔹 Hardware Used

- ATmega328P-PU
- 4 × 7-segment displays (Common Cathode)
- 4 × BC547 transistors
- Resistors (220 Ω, 1 kΩ, 10 kΩ)
- 16 MHz crystal
- 22 pF capacitors (2×)
- Tactile push buttons (2×)
- LEDs for colon indicator
- Zero PCB / perfboard

---

## 🔹 Pin Mapping Summary

### Segment Pins (Shared)

| Segment | Arduino Pin | ATmega328P Pin |
|-------|-------------|----------------|
| a | D2 | 4 |
| b | D3 | 5 |
| c | D4 | 6 |
| d | D5 | 11 |
| e | D6 | 12 |
| f | D7 | 13 |
| g | D9 | 15 |

(All segment lines go through current-limiting resistors)

---

### Digit Enable Pins

| Digit | Meaning | Arduino Pin | ATmega Pin |
|-----|--------|------------|------------|
| d1 | Hour tens | D10 | 16 |
| d2 | Hour ones | D11 | 17 |
| d3 | Minute tens | D12 | 18 |
| d4 | Minute ones | A0 (D14) | 23 |

(Each pin drives a BC547 transistor via 1 kΩ base resistor)

---

### Other Pins

| Function | Arduino Pin | ATmega Pin |
|------|------------|------------|
| Colon / Blink LED | D13 | 19 |
| MODE button | A1 | 24 |
| INC button | A2 | 25 |

Buttons are wired to **GND** and use `INPUT_PULLUP`.

---

## 🔹 Power Supply Options

| Method | Works | Notes |
|----|----|----|
| USB 5 V adapter | ✅ | Recommended |
| 9 V + 7805 | ⚠️ | Short battery life |
| TP4056 only | ❌ | Charger only |
| 18650 + Boost | ✅ | Best portable |

⚠️ ATmega328P @16 MHz requires a stable **5 V** supply.

---

## 🔹 How to Build

1. Assemble ATmega328P standalone circuit
2. Add crystal and capacitors close to MCU
3. Connect segment resistors to segment pins
4. Use BC547 transistors for digit multiplexing
5. Wire buttons using internal pull-ups
6. Power via regulated 5 V
7. Upload firmware
8. Test digit by digit before final soldering

---

## 🔹 Programming the MCU

- Program using Arduino as ISP or USB-TTL
- Board setting: **Arduino Uno**
- External crystal: 16 MHz
- Bootloader optional

---

## 🔹 Known Limitations

- Time drift without RTC
- High current draw with 7-segment LEDs
- Battery operation needs boost converter

---

## 🔹 Future Improvements

- RTC (DS3231)
- EEPROM time save
- Alarm / buzzer
- Brightness control
- Low-power sleep mode

---

## 🔹 Credits

Designed and built as a learning-focused embedded systems project.
