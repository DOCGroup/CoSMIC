// $Id$

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
  // src_Input
  //
  size_t SingleInputBase_Impl::src_Input (std::vector <Input> & items) const
  {
    return this->in_connections <Input> (items);
  }
}

