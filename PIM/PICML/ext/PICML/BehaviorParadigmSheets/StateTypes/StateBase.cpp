// $Id$

#include "StdAfx.h"
#include "StateBase.h"

#if !defined (__GAME_INLINE__)
#include "StateBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StateBase_Impl::metaname ("StateBase");

  //
  // is_abstract
  //
  const bool StateBase_Impl::is_abstract (1);

  //
  // parent_BehaviorModel
  //
  BehaviorModel StateBase_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_of_Finish
  //
  size_t StateBase_Impl::src_of_Finish (std::vector <Finish> & items) const
  {
    return this->in_connections <Finish> (items);
  }

  //
  // src_of_Finish
  //
  GAME::Mga::Collection_T <Finish> StateBase_Impl::src_of_Finish (void) const
  {
    return this->in_connections <Finish> ("src");
  }

  //
  // dst_of_TerminalEffect
  //
  size_t StateBase_Impl::dst_of_TerminalEffect (std::vector <TerminalEffect> & items) const
  {
    return this->in_connections <TerminalEffect> (items);
  }

  //
  // dst_of_TerminalEffect
  //
  GAME::Mga::Collection_T <TerminalEffect> StateBase_Impl::dst_of_TerminalEffect (void) const
  {
    return this->in_connections <TerminalEffect> ("dst");
  }

  //
  // dst_of_InputEffect
  //
  size_t StateBase_Impl::dst_of_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // dst_of_InputEffect
  //
  GAME::Mga::Collection_T <InputEffect> StateBase_Impl::dst_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("dst");
  }

  //
  // dst_of_Effect
  //
  size_t StateBase_Impl::dst_of_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
  }

  //
  // dst_of_Effect
  //
  GAME::Mga::Collection_T <Effect> StateBase_Impl::dst_of_Effect (void) const
  {
    return this->in_connections <Effect> ("dst");
  }
}

