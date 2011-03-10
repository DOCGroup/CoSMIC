// $Id$

#include "stdafx.h"
#include "QueryAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string QueryAction_Impl::metaname = "QueryAction";

  //
  // QueryAction_Impl
  //
  QueryAction_Impl::QueryAction_Impl (void)
  {
  }

  //
  // QueryAction_Impl
  //
  QueryAction_Impl::QueryAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QueryAction_Impl
  //
  QueryAction_Impl::~QueryAction_Impl (void)
  {
  }

  //
  // accept
  //
  void QueryAction_Impl::accept (Visitor * v)
  {
    v->visit_QueryAction (this);
  }
}

