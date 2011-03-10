// $Id$

#include "stdafx.h"
#include "SupportsInterfaces.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InheritableTypes/Supports.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SupportsInterfaces_Impl::metaname = "SupportsInterfaces";

  //
  // SupportsInterfaces_Impl
  //
  SupportsInterfaces_Impl::SupportsInterfaces_Impl (void)
  {
  }

  //
  // SupportsInterfaces_Impl
  //
  SupportsInterfaces_Impl::SupportsInterfaces_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SupportsInterfaces_Impl
  //
  SupportsInterfaces_Impl::~SupportsInterfaces_Impl (void)
  {
  }

  //
  // get_Supportss
  //
  size_t SupportsInterfaces_Impl::get_Supportss (std::vector <Supports> & items) const
  {
    return this->children (items);
  }
}

