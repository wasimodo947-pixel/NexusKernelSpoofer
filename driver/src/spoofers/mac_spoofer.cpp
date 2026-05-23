#include "mac_spoofer.h"
#include "common.h"
#include "hooks.h"

#define OID_802_3_PERMANENT_ADDRESS 0x01010101
#define OID_802_3_CURRENT_ADDRESS   0x01010102

typedef struct _NDIS_OID_REQUEST {
    UCHAR RequestType;
    union {
        struct {
            ULONG Oid;
            PVOID InformationBuffer;
            ULONG InformationBufferLength;
            ULONG BytesWritten;
            ULONG BytesNeeded;
        } QUERY_INFORMATION;
    } DATA;
} NDIS_OID_REQUEST;

typedef VOID (*NDISOIDREQUEST)(PVOID, PVOID);
static NDISOIDREQUEST g_OriginalNdisOidRequest = NULL;

static VOID HookedNdisOidRequest(PVOID BindingHandle, PVOID Request) {
    if (g_SpoofData.Enabled) {
        NDIS_OID_REQUEST* req = (NDIS_OID_REQUEST*)Request;
        if (req && req->RequestType == 1) {
            ULONG oid = req->DATA.QUERY_INFORMATION.Oid;
            if (oid == OID_802_3_PERMANENT_ADDRESS || oid == OID_802_3_CURRENT_ADDRESS) {
                g_OriginalNdisOidRequest(BindingHandle, Request);
                RtlCopyMemory(req->DATA.QUERY_INFORMATION.InformationBuffer, g_SpoofData.MacAddress, 6);
                return;
            }
        }
    }
    g_OriginalNdisOidRequest(BindingHandle, Request);
}

static PVOID FindNdisOidRequest() {
    UNICODE_STRING ndisName;
    RtlInitUnicodeString(&ndisName, L"\\Driver\\NDIS");
    PDRIVER_OBJECT ndisDriver = NULL;
    NTSTATUS st = ObReferenceObjectByName(&ndisName, OBJ_CASE_INSENSITIVE, NULL, 0,
        *IoDriverObjectType, KernelMode, NULL, (PVOID*)&ndisDriver);
    if (!NT_SUCCESS(st)) return NULL;
    PUCHAR base = (PUCHAR)ndisDriver->DriverStart;
    ULONG size = ndisDriver->DriverSize;
    ObDereferenceObject(ndisDriver);

    UCHAR pattern[] = "\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57";
    for (SIZE_T i = 0; i < size - sizeof(pattern); i++) {
        if (RtlCompareMemory(base + i, pattern, sizeof(pattern)-1) == sizeof(pattern)-1)
            return base + i;
    }
    return NULL;
}

void InitMacSpoofer() {
    PVOID addr = FindNdisOidRequest();
    if (addr) {
        g_OriginalNdisOidRequest = (NDISOIDREQUEST)addr;
        InstallHookX64(addr, HookedNdisOidRequest, &g_MacHook);
    }
}

void CleanupMacSpoofer() {
    RemoveHookX64(&g_MacHook);
}