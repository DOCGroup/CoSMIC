// $Id$

#include "StdAfx.h"
#include "QueryInputBase.h"

#if !defined (__GAME_INLINE__)
#include "QueryInputBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInputBase_Impl::metaname ("QueryInputBase");

  //
  // src_QueryInput
  //
  size_t QueryInputBase_Impl::src_QueryInput (std::vector <QueryInput> & items) const
  {
    return this->in_connections <QueryInput> (items);
  }
}

