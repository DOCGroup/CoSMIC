//UuidString.cpp
#include "UuidString.h"

namespace PICML
{

  CString MakeUuidString(UUID* pUUID)
  {
    CString sUUID = "";
    unsigned char* sTemp;
    BOOL bAllocated = FALSE;

    if (pUUID == 0)
      {
        pUUID      = new UUID;
        bAllocated = TRUE;
      }
    if (pUUID != 0)
      {
        HRESULT hr;
        hr = UuidCreate(pUUID);
        if (hr == RPC_S_OK)
          {
            hr = UuidToString(pUUID, &sTemp);
            if (hr == RPC_S_OK)
              {
                sUUID = sTemp;
                sUUID.MakeUpper();
                RpcStringFree(&sTemp);
              }
          }
        if (bAllocated)
          {
            delete pUUID;
            pUUID = 0;
          }
      }
    return sUUID;
  }
}
