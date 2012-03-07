// $Id$

#include "StdAfx.h"
#include "ActionBase.h"

#if !defined (__GAME_INLINE__)
#include "ActionBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ActionBase_Impl::metaname ("ActionBase");

  //
  // src_Effect
  //
  size_t ActionBase_Impl::src_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
  }

  //
  // dst_Transition
  //
  size_t ActionBase_Impl::dst_Transition (std::vector <Transition> & items) const
  {
    return this->in_connections <Transition> (items);
  }

  //
  // dst_BranchTransition
  //
  size_t ActionBase_Impl::dst_BranchTransition (std::vector <BranchTransition> & items) const
  {
    return this->in_connections <BranchTransition> (items);
  }

  //
  // dst_LoopTransition
  //
  size_t ActionBase_Impl::dst_LoopTransition (std::vector <LoopTransition> & items) const
  {
    return this->in_connections <LoopTransition> (items);
  }

  //
  // get_Propertys
  //
  size_t ActionBase_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> ActionBase_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }
}

