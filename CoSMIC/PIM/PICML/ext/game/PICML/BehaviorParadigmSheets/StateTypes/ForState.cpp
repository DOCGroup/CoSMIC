// $Id$

#include "stdafx.h"
#include "ForState.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ForState_Impl::metaname = "ForState";

  //
  // ForState_Impl
  //
  ForState_Impl::ForState_Impl (void)
  {
  }

  //
  // ForState_Impl
  //
  ForState_Impl::ForState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ForState_Impl
  //
  ForState_Impl::~ForState_Impl (void)
  {
  }

  //
  // accept
  //
  void ForState_Impl::accept (Visitor * v)
  {
    v->visit_ForState (this);
  }

  //
  // IncrementExpr
  //
  void ForState_Impl::IncrementExpr (const std::string & val)
  {
    static const std::string attr_IncrementExpr ("IncrementExpr");
    this->attribute (attr_IncrementExpr)->string_value (val);
  }

  //
  // IncrementExpr
  //
  std::string ForState_Impl::IncrementExpr (void) const
  {
    static const std::string attr_IncrementExpr ("IncrementExpr");
    return this->attribute (attr_IncrementExpr)->string_value ();
  }

  //
  // InitialCondition
  //
  void ForState_Impl::InitialCondition (const std::string & val)
  {
    static const std::string attr_InitialCondition ("InitialCondition");
    this->attribute (attr_InitialCondition)->string_value (val);
  }

  //
  // InitialCondition
  //
  std::string ForState_Impl::InitialCondition (void) const
  {
    static const std::string attr_InitialCondition ("InitialCondition");
    return this->attribute (attr_InitialCondition)->string_value ();
  }
}

