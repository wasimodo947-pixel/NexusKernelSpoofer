#include "volume_spoofer.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*NTQUERYVOLUMEINFORMATIONFILE)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FS_INFORMATION_CLASS);
static NTQUERYVOLUMEINFORMATIONFILE g_Original = NULL;

static NTSTATUS Hooked(...) { ... }

void InitVolumeSpoofer() { ... }
void CleanupVolumeSpoofer() { ... }