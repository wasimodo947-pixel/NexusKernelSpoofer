#include "mac_spoofer.h"
#include "common.h"
#include "hypervisor.h"

static UINT64 g_MacPhys = 0;
static UCHAR g_FakePage[4096] = {0};

static ULONG ReadPciConfig(ULONG Bus, ULONG Slot, ULONG Func, ULONG Offset, ULONG Size) { ... }
static UINT64 FindNicMmioBase() { ... }

void InitMacSpoofer() { ... }
void CleanupMacSpoofer() { ... }