#include "gpu_spoofer.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*DXGKGETDEVICESTATE)(PVOID, PVOID, ULONG);
static DXGKGETDEVICESTATE g_OriginalDxgkGetDeviceState = NULL;

static NTSTATUS HookedDxgkGetDeviceState(PVOID DeviceContext, PVOID State, ULONG StateSize) {
    NTSTATUS status = g_OriginalDxgkGetDeviceState(DeviceContext, State, StateSize);
    if (g_SpoofData.Enabled && NT_SUCCESS(status) && State && StateSize >= 8) {
        *(ULONG*)State = 0x10DE;
        *(ULONG*)((PUCHAR)State + 4) = 0x1B06;
    }
    return status;
}

static PVOID FindDxgkGetDeviceState() {
    UNICODE_STRING dxgName;
    RtlInitUnicodeString(&dxgName, L"\\Driver\\dxgkrnl");
    PDRIVER_OBJECT dxgDrv = NULL;
    NTSTATUS st = ObReferenceObjectByName(&dxgName, OBJ_CASE_INSENSITIVE, NULL, 0,
        *IoDriverObjectType, KernelMode, NULL, (PVOID*)&dxgDrv);
    if (!NT_SUCCESS(st)) return NULL;
    PUCHAR base = (PUCHAR)dxgDrv->DriverStart;
    ULONG size = dxgDrv->DriverSize;
    ObDereferenceObject(dxgDrv);

    UCHAR pattern[] = "\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9";
    for (SIZE_T i = 0; i < size - sizeof(pattern); i++) {
        if (RtlCompareMemory(base + i, pattern, sizeof(pattern)-1) == sizeof(pattern)-1)
            return base + i;
    }
    return NULL;
}

void InitGpuSpoofer() {
    PVOID addr = FindDxgkGetDeviceState();
    if (addr) {
        g_OriginalDxgkGetDeviceState = (DXGKGETDEVICESTATE)addr;
        InstallHookX64(addr, HookedDxgkGetDeviceState, &g_GpuHook);
    }
}

void CleanupGpuSpoofer() {
    RemoveHookX64(&g_GpuHook);
}