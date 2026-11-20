/* SPDX-License-Identifier: MIT
 * Connections extracted from hardware/hardware.net for STM32G071KBUxN (U3).
 * The PA11/PA12 physical signals may also be named PA9/PA10 by pin remapping.
 */
#ifndef PHMC_V1_H
#define PHMC_V1_H

#define PHMC_STATUS_LED_PORT_LETTER  'A'
#define PHMC_STATUS_LED_PIN          5U
#define PHMC_ERROR_LED_PORT_LETTER   'A'
#define PHMC_ERROR_LED_PIN           6U

#define PHMC_UART2_TX_PIN            2U
#define PHMC_UART2_RX_PIN            3U

#define PHMC_CAMERA_ENABLE_PIN       12U

#define PHMC_I2C1_SCL_PHYSICAL_PIN   11U
#define PHMC_I2C1_SDA_PHYSICAL_PIN   12U

#define PHMC_SWDIO_PIN               13U
#define PHMC_SWCLK_BOOT0_PIN         14U

#endif /* PHMC_V1_H */
