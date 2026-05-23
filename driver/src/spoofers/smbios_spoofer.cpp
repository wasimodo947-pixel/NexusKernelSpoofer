#include "smbios_spoofer.h"
#include "common.h"
#include "hooks.h"

static PDRIVER_OBJECT g_AcpiDriver = NULL;
static PDRIVER_DISPATCH g_OriginalSystemControl = NULL;

static NTSTATUS HookedAcpiSystemControl(...) { ... }

void InitSmbiosSpoofer() { ... }
void CleanupSmbiosSpoofer() { ... }