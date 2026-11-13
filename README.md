# UAV-PHMC
### UAV Power, Hardware & Motor Controller

UAV-PHMC is an embedded hardware development project focused on designing a custom printed circuit board (PCB) for UAV control and power-management applications.

The project brings together power regulation, hardware interfaces, monitoring circuitry, and embedded-system integration on a custom four-layer PCB.

The repository contains the KiCad hardware design files alongside manufacturing outputs for PCB fabrication and assembly.

<p align="center">
  <img src="hardware/hardware.png" alt="UAV-PHMC PCB Hardware Design" width="850">
</p>

---

## Project Overview

The UAV-PHMC board is designed around the **STM32G071KBUx** microcontroller and provides the hardware foundation for interfacing with UAV subsystems.

Key design areas include:

- Custom four-layer PCB design.
- STM32G071KBUx microcontroller integration.
- Multi-rail power distribution.
- Voltage and current monitoring.
- Protected GPIO interfaces.
- Communication interfaces for external peripherals.
- PCB fabrication and assembly preparation.

## Hardware Features

| Feature | Description |
|---|---|
| Microcontroller | STM32G071KBUx |
| PCB | Custom four-layer design |
| Power regulation | TPS562202S-based regulation |
| Current monitoring | INA226 |
| Power rails | VBAT_RAW, 5V, 5V_CAM, 3V3 |
| Communication | UART, I²C, RS-485 |
| GPIO | Protected external GPIO interfaces |
| Design software | KiCad |

## Power Architecture

The hardware design incorporates multiple power domains to support the board and its connected peripherals.

| Power net | Purpose |
|---|---|
| VBAT_RAW | Raw battery input |
| 5V | Main regulated 5V supply |
| 5V_CAM | Camera power supply |
| 3V3 | Logic and microcontroller supply |

The design includes voltage and current monitoring using the INA226, supporting power-system observation and integration.

## Repository Structure

```text
UAV-PHMC/
│
├── hardware/
│   ├── bom/
│   │   └── hardware.csv
│   │
│   ├── gerbers/
│   │   ├── PHMC_gerbers.zip
│   │   ├── hardware-Front.gtl
│   │   ├── hardware-Back.gbl
│   │   ├── hardware-Edge_Cuts.gm1
│   │   └── ... fabrication layers and drill files
│   │
│   ├── pick_place/
│   │   └── hardware-all.pos
│   │
│   ├── hardware.kicad_pcb
│   ├── hardware.kicad_pro
│   └── hardware.glb
│
├── .gitignore
└── README.md
```

## Manufacturing Outputs

The repository includes the following manufacturing-related files:

**Bill of Materials (BOM)**
- `hardware/bom/hardware.csv`

**Gerber and Drill Files**
- `hardware/gerbers/`

**Pick-and-Place Data**
- `hardware/pick_place/hardware-all.pos`

**3D PCB Model**
- `hardware/hardware.glb`

**Gerber Archive**
- `hardware/gerbers/PHMC_gerbers.zip`

These files are provided to support PCB fabrication, component sourcing, assembly preparation, and design review.

Before manufacturing, verify that the Gerber outputs, drill files, BOM, and pick-and-place data correspond to the intended PCB revision.

## Opening the Hardware Design

1. Install [KiCad](https://www.kicad.org/).
2. Clone or download this repository.
3. Navigate to the `hardware/` directory.
4. Open `hardware.kicad_pro` in KiCad.
5. Inspect the schematic and PCB design as applicable.

The 3D model can also be inspected using a compatible 3D viewer.

## Project Status

**Hardware design and manufacturing outputs committed.**

The repository currently includes the PCB design, project configuration, BOM, Gerber fabrication files, drill data, pick-and-place coordinates, and 3D model.

The inclusion of manufacturing outputs does not imply that the board has been fabricated, assembled, electrically validated, or flight-tested.

## Tools & Technologies

- **KiCad** — PCB design and layout.
- **STM32** — Embedded microcontroller platform.
- **INA226** — Voltage and current monitoring.
- **TPS562202S** — Power regulation.
- **Gerber** — PCB fabrication data.
- **3D CAD** — PCB visualization and mechanical inspection.

## Licensing

### Hardware design

The hardware design files in this repository, including schematics, PCB layouts, manufacturing outputs and related hardware documentation, are licensed under the **CERN Open Hardware Licence Version 2 – Strongly Reciprocal (CERN-OHL-S-2.0)**. See [LICENSE](./LICENSE).

The complete source for this hardware design is available in this repository: https://github.com/Evans-Kwashie/UAV-PHMC

### Software

Any firmware, software or code in this repository that is explicitly identified as software is licensed under the **MIT License**. See [LICENSE-MIT](./LICENSE-MIT). Third-party components remain under their respective licences.

## Author

**Evans Klenam Kwashie-Seyram**

- GitHub: [@Evans-Kwashie](https://github.com/Evans-Kwashie)
- LinkedIn: [Evans Klenam Kwashie-Seyram](https://linkedin.com/in/evans-klenam-kwashie-seyram)
- Portfolio: [pcb-portfolio.vercel.app](https://pcb-portfolio.vercel.app)

---

*UAV-PHMC — Custom embedded hardware for UAV systems.*
