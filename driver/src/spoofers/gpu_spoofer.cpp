#include "gpu_spoofer.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*DXGKGETDEVICESTATE)(PVOID, PVOID, ULONG);
static DXGKGETDEVICESTATE g_OriginalDxgkGetDeviceState = NULL;

static NTSTATUS HookedDxgkGetDeviceState(...) { ... }

static PVOID FindDxgkGetDeviceState() { ... }

void InitGpuSpoofer() { ... }
void CleanupGpuSpoofer() { ... }