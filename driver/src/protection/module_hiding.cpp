#include "module_hiding.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*NTQUERYSYSTEMINFORMATION)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG);
static NTQUERYSYSTEMINFORMATION g_Original = NULL;

static NTSTATUS Hooked(...) { ... }

void InitModuleHiding() { ... }
void CleanupModuleHiding() { ... }