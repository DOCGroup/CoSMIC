// $Id$

#include "stdafx.h"
#include "HasExceptions.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/OperationTypes/ExceptionRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string HasExceptions_Impl::metaname = "HasExceptions";

  //
  // HasExceptions_Impl
  //
  HasExceptions_Impl::HasExceptions_Impl (void)
  {
  }

  //
  // HasExceptions_Impl
  //
  HasExceptions_Impl::HasExceptions_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~HasExceptions_Impl
  //
  HasExceptions_Impl::~HasExceptions_Impl (void)
  {
  }

  //
  // get_ExceptionRefs
  //
  size_t HasExceptions_Impl::get_ExceptionRefs (std::vector <ExceptionRef> & items) const
  {
    return this->children (items);
  }
}

