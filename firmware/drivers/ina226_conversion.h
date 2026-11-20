/*
 * SPDX-License-Identifier: MIT
 *
 * Fixed-point conversions for the INA226 ADC registers.
 * These functions perform arithmetic only; they do not access hardware.
 */
#ifndef INA226_CONVERSION_H
#define INA226_CONVERSION_H

#include <stdint.h>

/** Convert the signed shunt-voltage register to microvolts (2.5 uV/LSB). */
int32_t ina226_shunt_uv_from_raw(int16_t raw);

/** Convert the unsigned bus-voltage register to millivolts (1.25 mV/LSB). */
uint32_t ina226_bus_mv_from_raw(uint16_t raw);

#endif /* INA226_CONVERSION_H */
