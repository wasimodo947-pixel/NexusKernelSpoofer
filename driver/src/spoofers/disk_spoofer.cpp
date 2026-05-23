#include "disk_spoofer.h"
#include "common.h"
#include "hooks.h"

static PDRIVER_OBJECT g_DiskDriver = NULL;
static PDRIVER_DISPATCH g_OriginalDiskDispatch = NULL;

NTSTATUS HookedDiskDeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    if (!g_SpoofData.Enabled) return g_OriginalDiskDispatch(DeviceObject, Irp);
    // ... (código sin definir HOOK_INFO aquí)
}

void InitDiskSpoofer() { ... }
void CleanupDiskSpoofer() { ... }