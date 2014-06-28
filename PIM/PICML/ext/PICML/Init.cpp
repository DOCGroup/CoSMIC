// $Id$

#include "stdafx.h"
#include "Impl_Factory.h"
#include "game/mga/Init_T.h"

namespace PICML
{
  class Init
  {
    public:
    /// Default constructor.
    Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->register_factory (&this->impl_factory_);
    }


    /// Destructor.
    ~Init (void)
    {
      ::GAME::Mga::GLOBAL_IMPL_FACTORY::instance ()->unregister_factory (&this->impl_factory_);
    }

    private:Impl_Factory impl_factory_;
  };


  /// Extension class initialization.
  static Init init;
}

