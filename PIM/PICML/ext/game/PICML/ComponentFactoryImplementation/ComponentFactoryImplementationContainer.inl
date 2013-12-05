// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentFactoryImplementationContainer_Impl
  //
  GAME_INLINE ComponentFactoryImplementationContainer_Impl::ComponentFactoryImplementationContainer_Impl (void)
  {
  }

  //
  // ComponentFactoryImplementationContainer_Impl
  //
  GAME_INLINE ComponentFactoryImplementationContainer_Impl::ComponentFactoryImplementationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryImplementationContainer_Impl
  //
  GAME_INLINE ComponentFactoryImplementationContainer_Impl::~ComponentFactoryImplementationContainer_Impl (void)
  {
  }
}

