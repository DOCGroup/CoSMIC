// $Id$

#include "stdafx.h"
#include "QueryInputBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInputBase_Impl::metaname = "QueryInputBase";

  //
  // QueryInputBase_Impl
  //
  QueryInputBase_Impl::QueryInputBase_Impl (void)
  {
  }

  //
  // QueryInputBase_Impl
  //
  QueryInputBase_Impl::QueryInputBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QueryInputBase_Impl
  //
  QueryInputBase_Impl::~QueryInputBase_Impl (void)
  {
  }

  //
  // in_QueryInput_connections
  //
  size_t QueryInputBase_Impl::in_QueryInput_connections (std::vector <QueryInput> & conns) const
  {
    return this->in_connections (conns);
  }
}

