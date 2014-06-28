// $Id$

#include "StdAfx.h"
#include "ActionBase.h"

#if !defined (__GAME_INLINE__)
#include "ActionBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ActionBase_Impl::metaname ("ActionBase");

  //
  // parent_BehaviorModel
  //
  BehaviorModel ActionBase_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_Effect
  //
  size_t ActionBase_Impl::src_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
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
  // dst_Transition
  //
  size_t ActionBase_Impl::dst_Transition (std::vector <Transition> & items) const
  {
    return this->in_connections <Transition> (items);
  }

  //
  // get_ComplexPropertys
  //
  size_t ActionBase_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> ActionBase_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t ActionBase_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> ActionBase_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }
}

