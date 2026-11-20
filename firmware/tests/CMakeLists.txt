if(NOT BUILD_TESTING)
    return()
endif()

add_library(test_assert INTERFACE)
target_include_directories(test_assert INTERFACE .)

function(phmc_add_unit_test name source_file)
    add_executable(${name}
        unit/${name}.c
        ${PROJECT_SOURCE_DIR}/${source_file}
    )
    get_filename_component(directory ${source_file} DIRECTORY)
    target_include_directories(${name} PRIVATE "${PROJECT_SOURCE_DIR}/${directory}")
    target_link_libraries(${name} PRIVATE test_assert)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

phmc_add_unit_test(test_ina226_conversion drivers/ina226_conversion.c)
phmc_add_unit_test(test_camera_controller app/camera_controller.c)
