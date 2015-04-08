#include "StdAfx.h"
#include "SingleInputBase.h"

#if !defined (__GAME_INLINE__)
#include "SingleInputBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SingleInputBase_Impl::metaname ("SingleInputBase");

  //
  // is_abstract
  //
  const bool SingleInputBase_Impl::is_abstract = true;

  //
  // src_of_Input
  //
  size_t SingleInputBase_Impl::src_of_Input (std::vector <Input> & items) const
  {
    return this->in_connections <Input> (items);
  }

  //
  // has_src_of_Input
  //
  bool SingleInputBase_Impl::has_src_of_Input (void) const
  {
    return this->in_connections <Input> ("src").count () == 1;
  }

  //
  // src_of_Input
  //
  Input SingleInputBase_Impl::src_of_Input (void) const
  {
    return this->in_connections <Input> ("src").first ();
  }
}

