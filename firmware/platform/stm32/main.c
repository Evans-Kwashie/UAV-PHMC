/* SPDX-License-Identifier: MIT
 * Build-only application entry point. Peripheral behavior is not implemented
 * or validated on the physical UAV-PHMC board yet.
 */
#include <stdint.h>

static volatile uint32_t build_marker;

/* This C-only, freestanding build has no static constructors to run. */
void __libc_init_array(void)
{
}

int main(void)
{
    build_marker = 0x50484D43U; /* "PHMC": proves BSS writes at link time. */

    for (;;) {
        /* No GPIO, I2C, UART, or power-rail control until those drivers exist. */
    }
}
