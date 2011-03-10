// $Id$

#include "stdafx.h"
#include "SingleInputBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SingleInputBase_Impl::metaname = "SingleInputBase";

  //
  // SingleInputBase_Impl
  //
  SingleInputBase_Impl::SingleInputBase_Impl (void)
  {
  }

  //
  // SingleInputBase_Impl
  //
  SingleInputBase_Impl::SingleInputBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SingleInputBase_Impl
  //
  SingleInputBase_Impl::~SingleInputBase_Impl (void)
  {
  }

  //
  // in_Input_connections
  //
  size_t SingleInputBase_Impl::in_Input_connections (std::vector <Input> & conns) const
  {
    return this->in_connections (conns);
  }
}

