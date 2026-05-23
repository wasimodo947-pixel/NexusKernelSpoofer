#include "common.h"
#include "hooks.h"
#include "hypervisor.h"
#include "adaptive_spoofer.h"
#include "tpm_spoofer.h"

// Includes de todos los módulos

// Globales
SPOOF_DATA g_SpoofData = {0};
PDEVICE_OBJECT g_DeviceObject = NULL;

// Hooks
HOOK_INFO g_DiskHook = {0};
// ... todos los hooks

// DriverEntry limpio con hypervisor primero
extern "C" NTSTATUS DriverEntry(...) { ... }

void DriverUnload(...) { ... }