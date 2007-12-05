// $Id$

#include "stdafx.h"
#include "GME.h"
#include "Exception.h"

namespace GME
{
  //
  // init
  //
  void init (void)
  {
    VERIFY_HRESULT (::CoInitializeEx (0, COINIT_APARTMENTTHREADED));
  }

  //
  // fini
  //
  void fini (void)
  {
    ::CoUninitialize ();
  }
}
