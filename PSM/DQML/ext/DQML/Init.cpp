// $Id$

#include "stdafx.h"
#include "Impl_Factory.h"

namespace DQML
{
  class Init
  {
    public:
    /// Default constructor.
    Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->set_next (GLOBAL_IMPL_FACTORY::instance ());
    }

    /// Destructor.
    ~Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->remove (GLOBAL_IMPL_FACTORY::instance ());
    }
  };

  /// Extension class initialization.
  static Init init;
}

