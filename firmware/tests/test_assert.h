/* SPDX-License-Identifier: MIT */
#ifndef PHMC_TEST_ASSERT_H
#define PHMC_TEST_ASSERT_H

#include <stdio.h>

#define ASSERT_EQ_INT(expected, actual)                                      \
    do {                                                                     \
        const long expected_value = (long)(expected);                         \
        const long actual_value = (long)(actual);                             \
        if (expected_value != actual_value) {                                 \
            (void)fprintf(stderr, "%s:%d: expected %ld, got %ld\n",          \
                          __FILE__, __LINE__, expected_value, actual_value);   \
            return 1;                                                         \
        }                                                                    \
    } while (0)

#endif /* PHMC_TEST_ASSERT_H */
