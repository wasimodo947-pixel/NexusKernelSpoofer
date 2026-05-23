#pragma once
#include "common.h"

NTSTATUS InitHypervisor();
VOID CleanupHypervisor();

typedef struct _VMX_CONTROLS {
    UINT64 VmcsRevisionId;
    UINT64 VmxonRegionPhys;
    UINT64 VmcsRegionPhys;
    UINT64 EptPml4Phys;
    UINT64 EptPml4Va;
    BOOLEAN HypervisorActive;
} VMX_CONTROLS;

extern VMX_CONTROLS g_Vmx;