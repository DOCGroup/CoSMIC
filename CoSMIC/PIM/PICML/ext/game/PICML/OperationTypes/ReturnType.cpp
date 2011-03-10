// $Id$

#include "stdafx.h"
#include "ReturnType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ReturnType_Impl::metaname = "ReturnType";

  //
  // ReturnType_Impl
  //
  ReturnType_Impl::ReturnType_Impl (void)
  {
  }

  //
  // ReturnType_Impl
  //
  ReturnType_Impl::ReturnType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReturnType_Impl
  //
  ReturnType_Impl::~ReturnType_Impl (void)
  {
  }

  //
  // accept
  //
  void ReturnType_Impl::accept (Visitor * v)
  {
    v->visit_ReturnType (this);
  }

  //
  // _create
  //
  ReturnType ReturnType_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create_object <ReturnType> (parent, ReturnType_Impl::metaname);
  }

  //
  // parent_TwowayOperation
  //
  TwowayOperation ReturnType_Impl::parent_TwowayOperation (void) const
  {
    return ::GAME::Mga::get_parent <TwowayOperation> (this->object_.p);
  }
}

