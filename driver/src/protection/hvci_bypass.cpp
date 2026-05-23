#include "hvci_bypass.h"
#include "hypervisor.h"
#include "hooks.h"

// Full HVCI bypass code

NTSTATUS InitHvciBypass() { ... }
VOID CleanupHvciBypass() { ... }
BOOLEAN HandleHvciExecuteViolation(...) { ... }