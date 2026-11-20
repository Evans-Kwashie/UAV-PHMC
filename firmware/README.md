# UAV-PHMC Firmware

Early firmware foundation for the STM32G071KBUxN-based UAV-PHMC design.

## Current scope

- Reproducible CMake/Ninja cross-compilation with GNU Arm GCC
- Official CMSIS startup and system initialization for STM32G071
- STM32G071KBUxN memory map: 128 KiB flash, 36 KiB SRAM
- Fixed-point INA226 register conversion with host-side tests
- Portable camera-command state machine with host-side tests
- Build-only reset entry point; no peripheral control implemented yet

**Not validated on the physical PCB.** Successful compilation proves only that
this source builds and links for the target. It does not prove clock settings,
pin configuration, electrical behavior, sensor readings, or firmware operation.

## V1 camera-rail limitation

The camera buck regulator (U2) uses an active-high enable input connected to
PA12 [PA10], physical package pin 23. The current V1 hardware has no external
pull-down that guarantees a disabled camera rail before firmware initializes
that GPIO. The rail's power-on and reset behavior is therefore **unvalidated**
and must not be described as guaranteed OFF until software starts.

`CAMERA_ON_COMMANDED` represents only the requested output state. It is not
proof that the physical camera rail is enabled, disabled, or supplying its
intended voltage. The portable state machine does not read rail feedback.

**V2 improvement:** add an appropriately sized external pull-down on
`EN_RAILB`, then verify power-on, reset, enable, and disable behavior with
measurements on the physical board. This V1 limitation is accepted for design
exploration, not validated for flight or unattended power control.

## Build and test on the host

Prerequisites: CMake, Ninja, and a native C compiler.

```sh
cmake --preset host
cmake --build --preset host
ctest --preset host
```

## Build for STM32G071

Prerequisite: `arm-none-eabi-gcc` on `PATH`.

```sh
cmake --preset stm32-debug
cmake --build --preset stm32-debug
```

For an optimized build:

```sh
cmake --preset stm32-release
cmake --build --preset stm32-release
```

Artifacts are written to `firmware/build/<preset>/`:

- `phmc.elf`
- `phmc.bin`
- `phmc.hex`
- `phmc.map`

## Layout

```text
app/                    Portable application logic
board/                  Board-specific signal definitions
drivers/                Portable drivers and conversion functions
platform/stm32/         Reset entry, runtime, and target linker script
tests/                  Host-native tests
third_party/            Pinned, unmodified CMSIS files with notices
tools/fetch_cmsis.sh    Re-fetch the exact pinned CMSIS files
```

To refresh the vendored dependency files, run this from `firmware/`:

```sh
sh tools/fetch_cmsis.sh
```

The portable conversion module has no STM32 or CMSIS dependency. CMSIS code is
confined to the target build; host tests do not execute the reset handler.
