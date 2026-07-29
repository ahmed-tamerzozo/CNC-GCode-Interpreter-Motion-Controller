# ⚙️ CNC G-Code Interpreter & Motion Controller (C++)

An embedded motion control algorithm and G-Code parser designed for multi-axis CNC machines and 3D printers. Implements real-time linear (G1) and circular (G2/G3) interpolation with dynamic acceleration profile generation.

---

## 🛠️ System Features & Motion Control
- G-Code Parser: Real-time serial command stream parsing (supports G0, G1, G2, G3 commands).
- Interpolation Algorithms: Linear stepper coordination using Bresenham's algorithm principles.
- Hardware Abstraction: Pulse and direction generation for stepper motor drivers (A4988 / DRV8825 / TB6600).

---

## 📂 Project Structure
```text
├── src/
│   └── main.cpp    # Parser logic & step-pulse generation loop
└── README.md       # Project documentation

👤 Author
 Ahmed Tamer -[ LinkedIn Profile](https://linkedin.com/in/ahmed-tamer-eng)
