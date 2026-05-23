#include "disk_spoofer.h"
#include "common.h"
#include "hypervisor.h"
#include "hooks.h"

static UINT64 g_DiskPhys = 0;
static UCHAR g_FakePage[4096] = {0};

static PDRIVER_OBJECT g_DiskDriver = NULL;
static PDRIVER_DISPATCH g_OriginalDiskDispatch = NULL;

static ULONG FindSerialOffset(PDEVICE_OBJECT DiskDevice, PCHAR RealSerial, ULONG SerialLen) { ... }
static NTSTATUS GetRealSerial(PDEVICE_OBJECT DiskDevice, PCHAR Buffer, ULONG BufferSize) { ... }

void InitDiskSpoofer() { ... }
void CleanupDiskSpoofer() { ... }