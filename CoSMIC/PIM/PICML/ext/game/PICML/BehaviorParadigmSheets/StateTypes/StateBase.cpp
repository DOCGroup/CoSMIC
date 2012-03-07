// $Id$

#include "StdAfx.h"
#include "StateBase.h"

#if !defined (__GAME_INLINE__)
#include "StateBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StateBase_Impl::metaname ("StateBase");

  //
  // src_Finish
  //
  size_t StateBase_Impl::src_Finish (std::vector <Finish> & items) const
  {
    return this->in_connections <Finish> (items);
  }

  //
  // dst_Effect
  //
  size_t StateBase_Impl::dst_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
  }

  //
  // dst_InputEffect
  //
  size_t StateBase_Impl::dst_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // dst_TerminalEffect
  //
  size_t StateBase_Impl::dst_TerminalEffect (std::vector <TerminalEffect> & items) const
  {
    return this->in_connections <TerminalEffect> (items);
  }
}

