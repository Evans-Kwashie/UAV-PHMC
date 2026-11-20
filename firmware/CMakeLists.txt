cmake_minimum_required(VERSION 3.20)
project(phmc_firmware VERSION 0.1.0 LANGUAGES C)

if(CMAKE_CROSSCOMPILING)
    enable_language(ASM)

    add_executable(phmc
        drivers/ina226_conversion.c
        platform/stm32/main.c
        third_party/cmsis_device_g0/Source/Templates/gcc/startup_stm32g071xx.s
        third_party/cmsis_device_g0/Source/Templates/system_stm32g0xx.c
        app/camera_controller.c
    )

    target_compile_definitions(phmc PRIVATE STM32G071xx)
    target_include_directories(phmc PRIVATE
        board
        drivers
        third_party/CMSIS_5/CMSIS/Core/Include
        third_party/cmsis_device_g0/Include
    )

    separate_arguments(PHMC_CPU_FLAGS_LIST NATIVE_COMMAND "${PHMC_CPU_FLAGS}")
    target_compile_options(phmc PRIVATE
        ${PHMC_CPU_FLAGS_LIST}
        -ffreestanding
        -ffunction-sections
        -fdata-sections
        -Wall
        -Wextra
        -Werror
        $<$<CONFIG:Debug>:-Og>
        $<$<CONFIG:Release>:-Os>
    )

    set(PHMC_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/platform/stm32/stm32g071kbux.ld")
    target_link_options(phmc PRIVATE
        ${PHMC_CPU_FLAGS_LIST}
        "-T${PHMC_LINKER_SCRIPT}"
        -nostartfiles
        -nostdlib
        -Wl,--gc-sections
        -Wl,-Map=phmc.map
        -Wl,--cref
        -Wl,--print-memory-usage
    )
    set_target_properties(phmc PROPERTIES LINK_DEPENDS "${PHMC_LINKER_SCRIPT}")

    add_custom_command(TARGET phmc POST_BUILD
        COMMAND "${CMAKE_OBJCOPY}" -O ihex $<TARGET_FILE:phmc> phmc.hex
        COMMAND "${CMAKE_OBJCOPY}" -O binary $<TARGET_FILE:phmc> phmc.bin
        COMMAND "${CMAKE_SIZE}" --format=berkeley $<TARGET_FILE:phmc>
        COMMENT "Generating PHMC HEX/BIN artifacts and reporting memory usage"
    )
else()
    include(CTest)
    add_subdirectory(tests)
endif()
