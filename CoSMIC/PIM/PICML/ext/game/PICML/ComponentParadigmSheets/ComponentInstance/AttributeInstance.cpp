// $Id$

#include "stdafx.h"
#include "AttributeInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeInstance_Impl::metaname = "AttributeInstance";

  //
  // AttributeInstance_Impl
  //
  AttributeInstance_Impl::AttributeInstance_Impl (void)
  {
  }

  //
  // AttributeInstance_Impl
  //
  AttributeInstance_Impl::AttributeInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeInstance_Impl
  //
  AttributeInstance_Impl::~AttributeInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeInstance_Impl::accept (Visitor * v)
  {
    v->visit_AttributeInstance (this);
  }
}

