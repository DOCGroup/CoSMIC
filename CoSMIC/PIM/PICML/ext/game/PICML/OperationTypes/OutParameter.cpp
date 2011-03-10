// $Id$

#include "stdafx.h"
#include "OutParameter.h"

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
  const std::string OutParameter_Impl::metaname = "OutParameter";

  //
  // OutParameter_Impl
  //
  OutParameter_Impl::OutParameter_Impl (void)
  {
  }

  //
  // OutParameter_Impl
  //
  OutParameter_Impl::OutParameter_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutParameter_Impl
  //
  OutParameter_Impl::~OutParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void OutParameter_Impl::accept (Visitor * v)
  {
    v->visit_OutParameter (this);
  }

  //
  // _create
  //
  OutParameter OutParameter_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create_object <OutParameter> (parent, OutParameter_Impl::metaname);
  }

  //
  // parent_TwowayOperation
  //
  TwowayOperation OutParameter_Impl::parent_TwowayOperation (void) const
  {
    return ::GAME::Mga::get_parent <TwowayOperation> (this->object_.p);
  }
}

