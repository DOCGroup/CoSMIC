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
  // src_MultiInput
  //
  size_t MultiInputBase_Impl::src_MultiInput (std::vector <MultiInput> & items) const
  {
    return this->in_connections <MultiInput> (items);
  }
}

