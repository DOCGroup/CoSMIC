// $Id$

#include "StdAfx.h"
#include "MultiInputBase.h"

#if !defined (__GAME_INLINE__)
#include "MultiInputBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MultiInputBase_Impl::metaname ("MultiInputBase");

  //
  // is_abstract
  //
  const bool MultiInputBase_Impl::is_abstract = true;

  //
  // src_of_MultiInput
  //
  size_t MultiInputBase_Impl::src_of_MultiInput (std::vector <MultiInput> & items) const
  {
    return this->in_connections <MultiInput> (items);
  }

  //
  // has_src_of_MultiInput
  //
  bool MultiInputBase_Impl::has_src_of_MultiInput (void) const
  {
    return this->in_connections <MultiInput> ("src").count () == 1;
  }

  //
  // src_of_MultiInput
  //
  MultiInput MultiInputBase_Impl::src_of_MultiInput (void) const
  {
    return this->in_connections <MultiInput> ("src").first ();
  }
}

