#include "integrity.h"
#include "common.h"
#include "hooks.h"

static KTIMER g_Timer;
static KDPC g_Dpc;

extern HOOK_INFO* g_AllHooks[];

static void DpcRoutine(...) { ... }

void InitIntegrityCheck() { ... }
void CleanupIntegrityCheck() { ... }