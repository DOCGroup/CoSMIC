// $Id$

#include "stdafx.h"
#include "ActionBase.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/Common/Property.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ActionBase_Impl::metaname = "ActionBase";

  //
  // ActionBase_Impl
  //
  ActionBase_Impl::ActionBase_Impl (void)
  {
  }

  //
  // ActionBase_Impl
  //
  ActionBase_Impl::ActionBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ActionBase_Impl
  //
  ActionBase_Impl::~ActionBase_Impl (void)
  {
  }

  //
  // Duration
  //
  void ActionBase_Impl::Duration (long val)
  {
    static const std::string attr_Duration ("Duration");
    this->attribute (attr_Duration)->int_value (val);
  }

  //
  // Duration
  //
  long ActionBase_Impl::Duration (void) const
  {
    static const std::string attr_Duration ("Duration");
    return this->attribute (attr_Duration)->int_value ();
  }

  //
  // in_Effect_connections
  //
  size_t ActionBase_Impl::in_Effect_connections (std::vector <Effect> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_Propertys
  //
  size_t ActionBase_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }
}

