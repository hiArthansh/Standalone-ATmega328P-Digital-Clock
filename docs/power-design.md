# Power Supply Design

---

## Required Voltage

- ATmega328P @16 MHz requires ~5 V
- Display brightness depends on headroom

---

## Valid Options

| Option | Status |
|----|----|
| USB 5 V | Recommended |
| 9 V + 7805 | Works but inefficient |
| TP4056 only | Not valid |
| 18650 + Boost | Best portable |

---

## Important Note

TP4056 is a charger, not a voltage regulator.
