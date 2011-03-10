// $Id$

#include "stdafx.h"
#include "InParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/OperationBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InParameter_Impl::metaname = "InParameter";

  //
  // InParameter_Impl
  //
  InParameter_Impl::InParameter_Impl (void)
  {
  }

  //
  // InParameter_Impl
  //
  InParameter_Impl::InParameter_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InParameter_Impl
  //
  InParameter_Impl::~InParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void InParameter_Impl::accept (Visitor * v)
  {
    v->visit_InParameter (this);
  }

  //
  // _create
  //
  InParameter InParameter_Impl::_create (const OperationBase_in parent)
  {
    return ::GAME::Mga::create_object <InParameter> (parent, InParameter_Impl::metaname);
  }

  //
  // parent_OperationBase
  //
  OperationBase InParameter_Impl::parent_OperationBase (void) const
  {
    return ::GAME::Mga::get_parent <OperationBase> (this->object_.p);
  }
}

