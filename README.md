# Smart Hydroponics / Automatic Valve Control System 🌱⚡

An automated smart agriculture irrigation system designed to optimize water usage in hydroponic systems. This project monitors moisture thresholds and manages a high-torque fluid control valve with integrated electrical hardware safety.

Developed by: **Goti Esmoris Tech**

---

## 🛠️ Hardware Component Architecture
The system topology features a precise virtual layout designed for bulletproof stability:
*   **MCU:** Arduino Uno R3
*   **Input Sensor:** Potentiometer (acting as an Analog Soil Moisture Sensor)
*   **Actuator 1:** Micro Servo Motor (acting as a 0-90° Fluid Control Valve)
*   **Actuator 2:** 5V Relay Module (acting as an Electrical Isolation Safety Line)

---

## ⚙️ Control Logic & Firmware Features
The embedded software written in optimized C++ features:
1.  **Analog Filtering:** Maps RAW sensor values (0-1023) directly to an intuitive moisture percentage (0-100%).
2.  **Safety Interlocking:** The water valve servo line is completely isolated through a relay. The power rail is physically cut off (`LOW`) when irrigation is not required, avoiding jitter, unnecessary power drain, or accidental fluid leakage.
3.  **Hysteresis Control:** Dual-threshold triggers prevent unstable oscillating loops:
    *   **Dry Threshold (<30%):** Triggers relay safety line high (`HIGH`) and opens the valve to 90 degrees.
    *   **Wet Threshold (>70%):** Closes the valve (0 degrees) and opens the safety relay circuit.

---

## 📂 Repository File Structure
*   `smart_hydroponics.ino`: Production-ready firmware source code.
*   `diagram.json`: Complete layout and color-coded hardware routing matrix for digital prototyping.

---

## 🚀 Virtual Lab Deployment
This project has been fully developed, wired, and verified in a virtual simulation environment. You can run and test the circuit logic live without physical hardware:

👉 **[CLICK HERE TO RUN THE SIMULATION LIVE IN WOKWI](https://wokwi.com/projects/475987542667790337)**

---
*Looking for customized firmware architecture or professional circuit design? Let's build your next embedded solution together.*
