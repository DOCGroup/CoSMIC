// $Id$

#include "stdafx.h"
#include "LoopState.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LoopState_Impl::metaname = "LoopState";

  //
  // LoopState_Impl
  //
  LoopState_Impl::LoopState_Impl (void)
  {
  }

  //
  // LoopState_Impl
  //
  LoopState_Impl::LoopState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LoopState_Impl
  //
  LoopState_Impl::~LoopState_Impl (void)
  {
  }

  //
  // LoopingCondition
  //
  void LoopState_Impl::LoopingCondition (const std::string & val)
  {
    static const std::string attr_LoopingCondition ("LoopingCondition");
    this->attribute (attr_LoopingCondition)->string_value (val);
  }

  //
  // LoopingCondition
  //
  std::string LoopState_Impl::LoopingCondition (void) const
  {
    static const std::string attr_LoopingCondition ("LoopingCondition");
    return this->attribute (attr_LoopingCondition)->string_value ();
  }

  //
  // in_LoopTransition_connections
  //
  size_t LoopState_Impl::in_LoopTransition_connections (std::vector <LoopTransition> & conns) const
  {
    return this->in_connections (conns);
  }
}

