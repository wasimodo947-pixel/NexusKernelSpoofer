#include "smbios_spoofer.h"
#include "common.h"
#include "hooks.h"

static PDRIVER_OBJECT g_AcpiDriver = NULL;
static PDRIVER_DISPATCH g_OriginalSystemControl = NULL;

static NTSTATUS HookedAcpiSystemControl(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    NTSTATUS status = g_OriginalSystemControl(DeviceObject, Irp);
    if (!g_SpoofData.Enabled || !NT_SUCCESS(status)) return status;

    PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(Irp);
    PUCHAR outBuf = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
    ULONG outLen = stack->Parameters.DeviceIoControl.OutputBufferLength;

    if (outBuf && outLen >= 0x18 && g_SpoofData.SMBIOS_UUID[0] != '\0') {
        for (ULONG i = 0; i < outLen - 0x19; i++) {
            if (outBuf[i] == 0x01 && outBuf[i+1] >= 0x08) {
                RtlCopyMemory(outBuf + i + 8, g_SpoofData.SMBIOS_UUID, 16);
                break;
            }
        }
    }
    return status;
}

void InitSmbiosSpoofer() {
    UNICODE_STRING name;
    RtlInitUnicodeString(&name, L"\\Driver\\ACPI");
    PDRIVER_OBJECT driver;
    NTSTATUS st = ObReferenceObjectByName(&name, OBJ_CASE_INSENSITIVE, NULL, 0,
        *IoDriverObjectType, KernelMode, NULL, (PVOID*)&driver);
    if (!NT_SUCCESS(st)) return;
    g_AcpiDriver = driver;
    g_OriginalSystemControl = driver->MajorFunction[IRP_MJ_SYSTEM_CONTROL];
    InstallHookX64(g_OriginalSystemControl, HookedAcpiSystemControl, &g_SmbiosHook);
}

void CleanupSmbiosSpoofer() {
    RemoveHookX64(&g_SmbiosHook);
    if (g_AcpiDriver) ObDereferenceObject(g_AcpiDriver);
}