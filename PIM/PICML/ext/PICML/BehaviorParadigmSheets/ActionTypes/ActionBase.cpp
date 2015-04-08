#include "StdAfx.h"
#include "ActionBase.h"

#if !defined (__GAME_INLINE__)
#include "ActionBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ActionBase_Impl::metaname ("ActionBase");

  //
  // is_abstract
  //
  const bool ActionBase_Impl::is_abstract = true;

  //
  // parent_BehaviorModel
  //
  BehaviorModel ActionBase_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_of_Effect
  //
  size_t ActionBase_Impl::src_of_Effect (std::vector <Effect> & items) const
  {
    return this->in_connections <Effect> (items);
  }

  //
  // has_src_of_Effect
  //
  bool ActionBase_Impl::has_src_of_Effect (void) const
  {
    return this->in_connections <Effect> ("src").count () == 1;
  }

  //
  // src_of_Effect
  //
  Effect ActionBase_Impl::src_of_Effect (void) const
  {
    return this->in_connections <Effect> ("src").first ();
  }

  //
  // dst_of_LoopTransition
  //
  size_t ActionBase_Impl::dst_of_LoopTransition (std::vector <LoopTransition> & items) const
  {
    return this->in_connections <LoopTransition> (items);
  }

  //
  // has_dst_of_LoopTransition
  //
  bool ActionBase_Impl::has_dst_of_LoopTransition (void) const
  {
    return this->in_connections <LoopTransition> ("dst").count () == 1;
  }

  //
  // dst_of_LoopTransition
  //
  LoopTransition ActionBase_Impl::dst_of_LoopTransition (void) const
  {
    return this->in_connections <LoopTransition> ("dst").first ();
  }

  //
  // dst_of_Transition
  //
  size_t ActionBase_Impl::dst_of_Transition (std::vector <Transition> & items) const
  {
    return this->in_connections <Transition> (items);
  }

  //
  // has_dst_of_Transition
  //
  bool ActionBase_Impl::has_dst_of_Transition (void) const
  {
    return this->in_connections <Transition> ("dst").count () == 1;
  }

  //
  // dst_of_Transition
  //
  Transition ActionBase_Impl::dst_of_Transition (void) const
  {
    return this->in_connections <Transition> ("dst").first ();
  }

  //
  // dst_of_BranchTransition
  //
  size_t ActionBase_Impl::dst_of_BranchTransition (std::vector <BranchTransition> & items) const
  {
    return this->in_connections <BranchTransition> (items);
  }

  //
  // has_dst_of_BranchTransition
  //
  bool ActionBase_Impl::has_dst_of_BranchTransition (void) const
  {
    return this->in_connections <BranchTransition> ("dst").count () == 1;
  }

  //
  // dst_of_BranchTransition
  //
  BranchTransition ActionBase_Impl::dst_of_BranchTransition (void) const
  {
    return this->in_connections <BranchTransition> ("dst").first ();
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
}

