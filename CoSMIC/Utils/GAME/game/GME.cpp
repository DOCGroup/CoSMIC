// $Id$

#include "stdafx.h"
#include "GME.h"
#include "Exception.h"

namespace GME
{
  class GME_Initializer
  {
  public:
    GME_Initializer (void)
    {
      if (!GME_Initializer::is_init_)
      {
        VERIFY_HRESULT (::CoInitializeEx (0, COINIT_APARTMENTTHREADED));
        GME_Initializer::is_init_ = true;
      }
    }

    /// Default constructor
    ~GME_Initializer (void)
    {
      if (GME_Initializer::is_init_)
      {
        ::CoUninitialize ();
        GME_Initializer::is_init_ = false;
      }
    }

  private:
    /// Flag that determine is GME is initialized.
    static int is_init_;
  };

  int GME_Initializer::is_init_ = false;
}

static GME::GME_Initializer init;
