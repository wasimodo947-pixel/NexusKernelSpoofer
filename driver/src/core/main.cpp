#include "common.h"
#include "hooks.h"

#include "../spoofers/disk_spoofer.h"
#include "../spoofers/volume_spoofer.h"
#include "../spoofers/registry_spoofer.h"
#include "../spoofers/mac_spoofer.h"
#include "../spoofers/smbios_spoofer.h"
#include "../spoofers/gpu_spoofer.h"
#include "../protection/hiding.h"
#include "../protection/anti_read.h"
#include "../protection/module_hiding.h"
#include "../protection/integrity.h"
#include "../mapper/manual_mapper.h"

SPOOF_DATA g_SpoofData = { 0 };
PDEVICE_OBJECT g_DeviceObject = NULL;

HOOK_INFO g_DiskHook = {0};
HOOK_INFO g_VolHook = {0};
HOOK_INFO g_RegHook = {0};
HOOK_INFO g_MacHook = {0};
HOOK_INFO g_SmbiosHook = {0};
HOOK_INFO g_GpuHook = {0};
HOOK_INFO g_AntiReadHook = {0};
HOOK_INFO g_ModuleHideHook = {0};

HOOK_INFO* g_AllHooks[] = {
    &g_DiskHook, &g_VolHook, &g_RegHook, &g_MacHook,
    &g_SmbiosHook, &g_GpuHook, &g_AntiReadHook, &g_ModuleHideHook, NULL
};

NTSTATUS DeviceIoControl(PDEVICE_OBJECT, PIRP Irp) { ... }

void DriverUnload(PDRIVER_OBJECT DriverObject) { ... }

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) { ... }