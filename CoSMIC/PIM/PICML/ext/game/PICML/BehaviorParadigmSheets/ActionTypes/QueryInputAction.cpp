// $Id$

#include "stdafx.h"
#include "QueryInputAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInputAction_Impl::metaname = "QueryInputAction";

  //
  // QueryInputAction_Impl
  //
  QueryInputAction_Impl::QueryInputAction_Impl (void)
  {
  }

  //
  // QueryInputAction_Impl
  //
  QueryInputAction_Impl::QueryInputAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QueryInputAction_Impl
  //
  QueryInputAction_Impl::~QueryInputAction_Impl (void)
  {
  }

  //
  // accept
  //
  void QueryInputAction_Impl::accept (Visitor * v)
  {
    v->visit_QueryInputAction (this);
  }

  //
  // get_Propertys
  //
  size_t QueryInputAction_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }
}

