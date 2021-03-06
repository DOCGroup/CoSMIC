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
  // is_abstract
  //
  const bool QueryInputBase_Impl::is_abstract = true;

  //
  // src_of_QueryInput
  //
  size_t QueryInputBase_Impl::src_of_QueryInput (std::vector <QueryInput> & items) const
  {
    return this->in_connections <QueryInput> (items);
  }

  //
  // has_src_of_QueryInput
  //
  bool QueryInputBase_Impl::has_src_of_QueryInput (void) const
  {
    return this->in_connections <QueryInput> ("src").count () == 1;
  }

  //
  // src_of_QueryInput
  //
  QueryInput QueryInputBase_Impl::src_of_QueryInput (void) const
  {
    return this->in_connections <QueryInput> ("src").first ();
  }
}

