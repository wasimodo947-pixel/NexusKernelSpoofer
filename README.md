# NexusKernelSpoofer

**Versión final limpia y funcional**

Sp oofer kernel profesional para Windows 11 (EAC / BattlEye).

## Estado actual
- Proyecto 100% funcional y compilable
- Sin humo, sin stubs, sin duplicados
- Estructura modular profesional

## Archivos principales
- driver/src/core/main.cpp (entry point real)
- driver/src/spoofers/ (disk, volume, registry, mac, smbios, gpu)
- driver/src/protection/ (hiding, anti_read, module_hiding, integrity)
- driver/src/mapper/manual_mapper.cpp (con ResolveImports y Relocations reales)

## Compilación
Usa el CMakeLists.txt incluido.

**Uso solo para fines educativos y de investigación.**