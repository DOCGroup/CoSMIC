// $Id$

#include "stdafx.h"
#include "InoutParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/TwowayOperation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InoutParameter_Impl::metaname = "InoutParameter";

  //
  // InoutParameter_Impl
  //
  InoutParameter_Impl::InoutParameter_Impl (void)
  {
  }

  //
  // InoutParameter_Impl
  //
  InoutParameter_Impl::InoutParameter_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InoutParameter_Impl
  //
  InoutParameter_Impl::~InoutParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void InoutParameter_Impl::accept (Visitor * v)
  {
    v->visit_InoutParameter (this);
  }

  //
  // _create
  //
  InoutParameter InoutParameter_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create_object <InoutParameter> (parent, InoutParameter_Impl::metaname);
  }

  //
  // parent_TwowayOperation
  //
  TwowayOperation InoutParameter_Impl::parent_TwowayOperation (void) const
  {
    return ::GAME::Mga::get_parent <TwowayOperation> (this->object_.p);
  }
}

