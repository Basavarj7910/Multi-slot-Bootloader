cmake_minimum_required(VERSION 3.1)
project(bootloader LANGUAGES C ASM)
file(GLOB APP_SOURCES 
    "${CMAKE_SOURCE_DIR}/*.c"
    "${CMAKE_SOURCE_DIR}/*.s"
)
add_executable(bootloader.elf ${APP_SOURCES})
# Add include directories
target_link_options(bootloader.elf PRIVATE -nostartfiles)
target_link_options(bootloader.elf PRIVATE -T ${CMAKE_SOURCE_DIR}/linker.ld)
