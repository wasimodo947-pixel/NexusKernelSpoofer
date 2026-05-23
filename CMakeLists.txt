cmake_minimum_required(VERSION 3.10)
project(NexusKernelSpoofer LANGUAGES CXX)

set(SOURCES
    driver/src/core/main.cpp
    driver/src/core/hooks.cpp
    driver/src/spoofers/disk_spoofer.cpp
    driver/src/spoofers/volume_spoofer.cpp
    driver/src/spoofers/registry_spoofer.cpp
    driver/src/spoofers/mac_spoofer.cpp
    driver/src/spoofers/smbios_spoofer.cpp
    driver/src/spoofers/gpu_spoofer.cpp
    driver/src/protection/hiding.cpp
    driver/src/protection/anti_read.cpp
    driver/src/protection/module_hiding.cpp
    driver/src/protection/integrity.cpp
    driver/src/mapper/manual_mapper.cpp
)

add_library(NexusKernelSpoofer MODULE ${SOURCES})
target_link_libraries(NexusKernelSpoofer PRIVATE ntoskrnl)