#!/usr/bin/env sh
# Download only the pinned CMSIS files used by the STM32G071 target build.
set -eu

BASE_URL_ST='https://raw.githubusercontent.com/STMicroelectronics/cmsis_device_g0/f576c24e123edf3332988ecd49512c0f35f85186'
BASE_URL_ARM='https://raw.githubusercontent.com/ARM-software/CMSIS_5/5.9.0/CMSIS/Core/Include'

fetch() {
    url=$1
    output=$2
    mkdir -p "$(dirname "$output")"
    curl -fLsS "$url" -o "$output"
}

fetch "$BASE_URL_ARM/core_cm0plus.h" third_party/CMSIS_5/CMSIS/Core/Include/core_cm0plus.h
fetch "$BASE_URL_ARM/cmsis_compiler.h" third_party/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h
fetch "$BASE_URL_ARM/cmsis_gcc.h" third_party/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h
fetch "$BASE_URL_ARM/cmsis_version.h" third_party/CMSIS_5/CMSIS/Core/Include/cmsis_version.h
fetch "$BASE_URL_ARM/mpu_armv7.h" third_party/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h
fetch 'https://raw.githubusercontent.com/ARM-software/CMSIS_5/5.9.0/LICENSE.txt' third_party/CMSIS_5/LICENSE.txt

fetch "$BASE_URL_ST/Include/stm32g0xx.h" third_party/cmsis_device_g0/Include/stm32g0xx.h
fetch "$BASE_URL_ST/Include/stm32g071xx.h" third_party/cmsis_device_g0/Include/stm32g071xx.h
fetch "$BASE_URL_ST/Include/system_stm32g0xx.h" third_party/cmsis_device_g0/Include/system_stm32g0xx.h
fetch "$BASE_URL_ST/Source/Templates/system_stm32g0xx.c" third_party/cmsis_device_g0/Source/Templates/system_stm32g0xx.c
fetch "$BASE_URL_ST/Source/Templates/gcc/startup_stm32g071xx.s" third_party/cmsis_device_g0/Source/Templates/gcc/startup_stm32g071xx.s
fetch "$BASE_URL_ST/LICENSE.md" third_party/cmsis_device_g0/LICENSE.md

printf '%s\n' 'Pinned CMSIS files downloaded successfully.'
