cmake_minimum_required(VERSION 3.10)
project(NexusKernelSpoofer)

set(SOURCES
    src/core/main.cpp
    src/core/hooks.cpp
    src/spoofers/disk_spoofer.cpp
    src/spoofers/volume_spoofer.cpp
    src/spoofers/registry_spoofer.cpp
    src/spoofers/mac_spoofer.cpp
    src/spoofers/smbios_spoofer.cpp
    src/spoofers/gpu_spoofer.cpp
    src/protection/hiding.cpp
    src/protection/anti_read.cpp
    src/protection/module_hiding.cpp
    src/protection/integrity.cpp
    src/mapper/manual_mapper.cpp
)

add_driver(NexusKernelSpoofer ${SOURCES})
target_link_libraries(NexusKernelSpoofer ntoskrnl)