// $Id$

#include "StdAfx.h"
#include "LoopState.h"

#if !defined (__GAME_INLINE__)
#include "LoopState.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LoopState_Impl::metaname ("LoopState");

  //
  // is_abstract
  //
  const bool LoopState_Impl::is_abstract = true;

  //
  // src_of_LoopTransition
  //
  size_t LoopState_Impl::src_of_LoopTransition (std::vector <LoopTransition> & items) const
  {
    return this->in_connections <LoopTransition> (items);
  }

  //
  // has_src_of_LoopTransition
  //
  bool LoopState_Impl::has_src_of_LoopTransition (void) const
  {
    return this->in_connections <LoopTransition> ("src").count () == 1;
  }

  //
  // src_of_LoopTransition
  //
  LoopTransition LoopState_Impl::src_of_LoopTransition (void) const
  {
    return this->in_connections <LoopTransition> ("src").first ();
  }
}

