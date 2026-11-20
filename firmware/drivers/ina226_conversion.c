/* SPDX-License-Identifier: MIT */
#include "ina226_conversion.h"

int32_t ina226_shunt_uv_from_raw(int16_t raw)
{
    /* Five halves avoids rounding and cannot overflow int32_t. */
    return ((int32_t)raw * 5) / 2;
}

uint32_t ina226_bus_mv_from_raw(uint16_t raw)
{
    return ((uint32_t)raw * 5) / 4;
}
