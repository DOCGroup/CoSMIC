// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Exception.h"

#include "ace/Framework_Component.h"
#include "ace/OS_NS_unistd.h"

namespace GAME
{
namespace Mga
{
  /**
   * @class Init
   *
   * Initializer class for the Mga backend. Each instantiation of this
   * class will initialize the underlying COM architecture. Failure to
   * initialize the COM architecture will result in code that will not
   * execute correctly.
   */
  class Init
  {
  public:
    /// Default constructor.
    Init (void)
    {
      if (!Init::is_ready_)
      {
        VERIFY_HRESULT (::CoInitializeEx (0, COINIT_APARTMENTTHREADED));
        Init::is_ready_ = true;
      }
    }

    /// Destructor.
    ~Init (void)
    {
      if (Init::is_ready_)
      {
        ::CoUninitialize ();
        Init::is_ready_ = false;
      }
    }

  private:
    /// Flag that determine is backend is initialized.
    static bool is_ready_;
  };

  /// Initialization of the ready flag.
  bool Init::is_ready_ = false;

  /// Static variable that will initialize the backend for a library each
  /// time this library is loaded into memory.
  Mga::Init init;
}
}

