//UuidString.cpp
#include "stdafx.h"
#include "rpcdce.h"
#include "UuidString.h"

CString MakeUuidString(UUID* pUUID/*=NULL*/)
{
   CString sUUID = "";
   unsigned char* sTemp;
   BOOL bAllocated = FALSE;

   if (pUUID == NULL)
   {
      pUUID      = new UUID;
      bAllocated = TRUE;
   }
   if (pUUID != NULL)
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
         pUUID = NULL;
      }
   }
   return sUUID;
}
