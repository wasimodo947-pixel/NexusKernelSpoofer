#include "anti_read.h"
#include "common.h"
#include "hooks.h"

typedef NTSTATUS (*NTREADVIRTUALMEMORY)(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T);
static NTREADVIRTUALMEMORY g_Original = NULL;

static NTSTATUS Hooked(...) { ... }

void InitAntiRead() { ... }
void CleanupAntiRead() { ... }