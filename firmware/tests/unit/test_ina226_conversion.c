/* SPDX-License-Identifier: MIT */
#include "ina226_conversion.h"
#include "test_assert.h"

#include <stdint.h>

int main(void)
{
    ASSERT_EQ_INT(0, ina226_shunt_uv_from_raw(0));
    ASSERT_EQ_INT(20000, ina226_shunt_uv_from_raw(8000));
    ASSERT_EQ_INT(-20000, ina226_shunt_uv_from_raw(-8000));
    ASSERT_EQ_INT(81917, ina226_shunt_uv_from_raw(INT16_MAX));
    ASSERT_EQ_INT(-81920, ina226_shunt_uv_from_raw(INT16_MIN));

    ASSERT_EQ_INT(0, ina226_bus_mv_from_raw(0));
    ASSERT_EQ_INT(11980, ina226_bus_mv_from_raw(9584));
    ASSERT_EQ_INT(81918, ina226_bus_mv_from_raw(UINT16_MAX));

    return 0;
}
