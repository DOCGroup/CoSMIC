// $Id$

#include "StdAfx.h"
#include "StateBase.h"

#if !defined (__GAME_INLINE__)
#include "StateBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StateBase_Impl::metaname ("StateBase");

  //
  // is_abstract
  //
  const bool StateBase_Impl::is_abstract = true;

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
  // has_src_of_Finish
  //
  bool StateBase_Impl::has_src_of_Finish (void) const
  {
    return this->in_connections <Finish> ("src").count () == 1;
  }

  //
  // src_of_Finish
  //
  Finish StateBase_Impl::src_of_Finish (void) const
  {
    return this->in_connections <Finish> ("src").first ();
  }

  //
  // dst_of_TerminalEffect
  //
  size_t StateBase_Impl::dst_of_TerminalEffect (std::vector <TerminalEffect> & items) const
  {
    return this->in_connections <TerminalEffect> (items);
  }

  //
  // has_dst_of_TerminalEffect
  //
  bool StateBase_Impl::has_dst_of_TerminalEffect (void) const
  {
    return this->in_connections <TerminalEffect> ("dst").count () == 1;
  }

  //
  // dst_of_TerminalEffect
  //
  TerminalEffect StateBase_Impl::dst_of_TerminalEffect (void) const
  {
    return this->in_connections <TerminalEffect> ("dst").first ();
  }

  //
  // dst_of_InputEffect
  //
  size_t StateBase_Impl::dst_of_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // has_dst_of_InputEffect
  //
  bool StateBase_Impl::has_dst_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("dst").count () == 1;
  }

  //
  // dst_of_InputEffect
  //
  InputEffect StateBase_Impl::dst_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("dst").first ();
  }

  //
  // dst_of_Effect
  //
  size_t StateBase_Impl::dst_of_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
  }

  //
  // has_dst_of_Effect
  //
  bool StateBase_Impl::has_dst_of_Effect (void) const
  {
    return this->in_connections <Effect> ("dst").count () == 1;
  }

  //
  // dst_of_Effect
  //
  Effect StateBase_Impl::dst_of_Effect (void) const
  {
    return this->in_connections <Effect> ("dst").first ();
  }
}

