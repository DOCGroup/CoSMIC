// $Id$

#include "StdAfx.h"
#include "BehaviorInputAction.h"

#if !defined (__GAME_INLINE__)
#include "BehaviorInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorInputAction_Impl::metaname ("BehaviorInputAction");

  //
  // src_InputEffect
  //
  size_t BehaviorInputAction_Impl::src_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // dst_Finish
  //
  size_t BehaviorInputAction_Impl::dst_Finish (std::vector <Finish> & items) const
  {
    return this->in_connections <Finish> (items);
  }

  //
  // get_Propertys
  //
  size_t BehaviorInputAction_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> BehaviorInputAction_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }
}

