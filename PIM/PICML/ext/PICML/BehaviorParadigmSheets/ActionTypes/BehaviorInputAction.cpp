// $Id$

#include "StdAfx.h"
#include "BehaviorInputAction.h"

#if !defined (__GAME_INLINE__)
#include "BehaviorInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorInputAction_Impl::metaname ("BehaviorInputAction");

  //
  // parent_BehaviorModel
  //
  BehaviorModel BehaviorInputAction_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_of_InputEffect
  //
  size_t BehaviorInputAction_Impl::src_of_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // src_of_InputEffect
  //
  GAME::Mga::Collection_T <InputEffect> BehaviorInputAction_Impl::src_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("src");
  }

  //
  // dst_of_Finish
  //
  size_t BehaviorInputAction_Impl::dst_of_Finish (std::vector <Finish> & items) const
  {
    return this->in_connections <Finish> (items);
  }

  //
  // dst_of_Finish
  //
  GAME::Mga::Collection_T <Finish> BehaviorInputAction_Impl::dst_of_Finish (void) const
  {
    return this->in_connections <Finish> ("dst");
  }

  //
  // get_ComplexPropertys
  //
  size_t BehaviorInputAction_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> BehaviorInputAction_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t BehaviorInputAction_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> BehaviorInputAction_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }
}

