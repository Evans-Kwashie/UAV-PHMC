# Third-party notices

Only the dependency files used by this project are vendored to make clean
builds reproducible. `tools/fetch_cmsis.sh` retrieves the same pinned files.
They are unmodified and retain their original copyright and license notices.
They are not part of the project's MIT-licensed original firmware.

| Dependency | Source | Revision | License |
|---|---|---|---|
| Arm CMSIS_5 | https://github.com/ARM-software/CMSIS_5 | 5.9.0 | Apache-2.0 (`CMSIS_5/LICENSE.txt`) |
| ST CMSIS Device G0 | https://github.com/STMicroelectronics/cmsis_device_g0 | v1.4.5 (`f576c24e123edf3332988ecd49512c0f35f85186`) | Apache-2.0 (`cmsis_device_g0/LICENSE.md`) |

Only CMSIS core/device headers, the STM32G071 startup file, and the generic
system initialization implementation are compiled by the initial target build.
