// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Addon_Impl_Base
//
GAME_INLINE
Addon_Impl_Base::
Addon_Impl_Base (const std::string & name,
                 const std::string & paradigm,
                 const std::string & progid)
: ComponentEx_Impl_Base (name, paradigm, progid, false)
{

}

//
// ~Addon_Impl_Base
//
GAME_INLINE
Addon_Impl_Base::~Addon_Impl_Base (void)
{

}

}
}
