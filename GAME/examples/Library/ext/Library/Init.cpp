// $Id$

#include "stdafx.h"
#include "Impl_Factory.h"

namespace Library
{
  class Init
  {
    public:
    /// Default constructor.
    Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->impl_factory (GLOBAL_IMPL_FACTORY::instance ());
    }

    /// Destructor.
    ~Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->impl_factory (0);
    }
  };

  /// Extension class initialization.
  static Init init;
}

