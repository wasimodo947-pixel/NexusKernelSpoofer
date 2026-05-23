# NexusKernelSpoofer

El spoofer de kernel más avanzado para Windows 10/11 (x64).

## Tecnologías principales

- Hypervisor de tipo 2 (VT-x/AMD-V) con EPT hooking.
- Ocultación de hardware vía EPT: SMBIOS, disco, GPU, MAC, RAM.
- Spoofing de CPUID (funciones básicas y extendidas, ocultación de VMX).
- Modificación dinámica de memoria física.
- Protección DKOM (ocultación de módulo, anti-lectura, ocultación de módulos del sistema).
- Cargador BYOVD / Manual mapper para persistencia sin firmar.
- Arquitectura modular (C++/ASM, WDK).

## Compilación

1. Instalar Visual Studio 2022 + WDK 11.
2. Clonar el repositorio.
3. Abrir `NexusKernelSpoofer.sln` o compilar con CMake.

## Uso

1. Deshabilitar Secure Boot y habilitar VT-x en BIOS.
2. Cargar `NexusKernelSpoofer.sys` con kdmapper o mediante el loader incluido.
3. Configurar los seriales falsos con `spoofer_client.exe` (o mediante IOCTL).
4. Activar spoofing (IOCTL_ENABLE).

## Aviso

Este proyecto es con fines educativos. No me hago responsable del mal uso.

## Créditos

Desarrollado por wasimodo947-pixel y Jack, con la asistencia de Fox (low-level architect).