// $Id$

#include "stdafx.h"
#include "OperationBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/OperationTypes/InParameter.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OperationBase_Impl::metaname = "OperationBase";

  //
  // OperationBase_Impl
  //
  OperationBase_Impl::OperationBase_Impl (void)
  {
  }

  //
  // OperationBase_Impl
  //
  OperationBase_Impl::OperationBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OperationBase_Impl
  //
  OperationBase_Impl::~OperationBase_Impl (void)
  {
  }

  //
  // get_InParameters
  //
  size_t OperationBase_Impl::get_InParameters (std::vector <InParameter> & items) const
  {
    return this->children (items);
  }
}

