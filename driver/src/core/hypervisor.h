#pragma once
#include "common.h"

typedef struct _VMX_CONTROLS {
    UINT64 VmcsRevisionId;
    UINT64 VmxonRegionPhys;
    UINT64 VmcsRegionPhys;
    UINT64 EptPml4Phys;
    PVOID EptPml4Va;
    BOOLEAN HypervisorActive;
} VMX_CONTROLS;

extern VMX_CONTROLS g_Vmx;

VOID EptHidePage(UINT64 PhysAddr, BOOLEAN Hide);
VOID EptSetFakePage(UINT64 PhysAddr, PVOID FakePageVa);

NTSTATUS InitHypervisor();
VOID CleanupHypervisor();