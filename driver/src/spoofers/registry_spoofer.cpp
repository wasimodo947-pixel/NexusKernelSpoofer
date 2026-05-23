#include "registry_spoofer.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*NTQUERYVALUEKEY)(HANDLE, PUNICODE_STRING, KEY_VALUE_INFORMATION_CLASS, PVOID, ULONG, PULONG);
static NTQUERYVALUEKEY g_Original = NULL;

static NTSTATUS Hooked(...) { ... }

void InitRegistrySpoofer() { ... }
void CleanupRegistrySpoofer() { ... }