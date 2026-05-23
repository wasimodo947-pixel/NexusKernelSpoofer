#include <Uefi.h>
#include <Library/UefiLib.h>

// Updated with MutatePayload

VOID MutatePayload(UINT8 *Payload, UINTN Size) { ... }

EFI_STATUS InjectPayloadIntoBootmgfw(...) { ... }