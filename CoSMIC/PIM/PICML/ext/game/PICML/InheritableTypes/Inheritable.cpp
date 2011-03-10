// $Id$

#include "stdafx.h"
#include "Inheritable.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InheritableTypes/Inherits.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Inheritable_Impl::metaname = "Inheritable";

  //
  // Inheritable_Impl
  //
  Inheritable_Impl::Inheritable_Impl (void)
  {
  }

  //
  // Inheritable_Impl
  //
  Inheritable_Impl::Inheritable_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Inheritable_Impl
  //
  Inheritable_Impl::~Inheritable_Impl (void)
  {
  }

  //
  // get_Inheritss
  //
  size_t Inheritable_Impl::get_Inheritss (std::vector <Inherits> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  size_t Inheritable_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }
}

