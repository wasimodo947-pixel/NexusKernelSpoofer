#include "gpu_spoofer.h"
#include "common.h"
#include "hypervisor.h"

static UINT64 g_GpuPhys = 0;
static UCHAR g_FakePage[4096] = {0};

static ULONG ReadPciConfig(ULONG Bus, ULONG Slot, ULONG Func, ULONG Offset, ULONG Size) { ... }
static UINT64 FindGpuMmioBase() { ... }

void InitGpuSpoofer() { ... }
void CleanupGpuSpoofer() { ... }