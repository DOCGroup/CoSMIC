// $Id$

#include "stdafx.h"
#include "MultiInputBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MultiInputBase_Impl::metaname = "MultiInputBase";

  //
  // MultiInputBase_Impl
  //
  MultiInputBase_Impl::MultiInputBase_Impl (void)
  {
  }

  //
  // MultiInputBase_Impl
  //
  MultiInputBase_Impl::MultiInputBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultiInputBase_Impl
  //
  MultiInputBase_Impl::~MultiInputBase_Impl (void)
  {
  }

  //
  // in_MultiInput_connections
  //
  size_t MultiInputBase_Impl::in_MultiInput_connections (std::vector <MultiInput> & conns) const
  {
    return this->in_connections (conns);
  }
}

