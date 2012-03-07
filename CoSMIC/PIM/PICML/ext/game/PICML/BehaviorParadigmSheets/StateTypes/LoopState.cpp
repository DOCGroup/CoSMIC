// $Id$

#include "StdAfx.h"
#include "LoopState.h"

#if !defined (__GAME_INLINE__)
#include "LoopState.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LoopState_Impl::metaname ("LoopState");

  //
  // src_LoopTransition
  //
  size_t LoopState_Impl::src_LoopTransition (std::vector <LoopTransition> & items) const
  {
    return this->in_connections <LoopTransition> (items);
  }
}

