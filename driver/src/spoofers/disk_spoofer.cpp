#include "disk_spoofer.h"
#include "common.h"
#include "hooks.h"

static PDRIVER_OBJECT g_DiskDriver = NULL;
static PDRIVER_DISPATCH g_OriginalDiskDispatch = NULL;

// ... (código completo sin definiciones duplicadas)

void InitDiskSpoofer() { ... }
void CleanupDiskSpoofer() { ... }