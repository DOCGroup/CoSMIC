// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentFactory_Impl
  //
  GAME_INLINE ComponentFactory_Impl::ComponentFactory_Impl (void)
  {
  }

  //
  // ComponentFactory_Impl
  //
  GAME_INLINE ComponentFactory_Impl::ComponentFactory_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactory_Impl
  //
  GAME_INLINE ComponentFactory_Impl::~ComponentFactory_Impl (void)
  {
  }
}

