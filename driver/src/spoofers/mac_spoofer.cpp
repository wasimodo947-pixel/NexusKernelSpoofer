#include "mac_spoofer.h"
#include "common.h"
#include "hooks.h"

#define OID_802_3_PERMANENT_ADDRESS 0x01010101
#define OID_802_3_CURRENT_ADDRESS   0x01010102

typedef struct _NDIS_OID_REQUEST { ... };
typedef VOID (*NDISOIDREQUEST)(PVOID, PVOID);
static NDISOIDREQUEST g_OriginalNdisOidRequest = NULL;

static VOID HookedNdisOidRequest(...) { ... }

static PVOID FindNdisOidRequest() { ... }

void InitMacSpoofer() { ... }
void CleanupMacSpoofer() { ... }