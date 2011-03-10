// $Id$

#include "stdafx.h"
#include "SimpleProperty.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SimpleProperty_Impl::metaname = "SimpleProperty";

  //
  // SimpleProperty_Impl
  //
  SimpleProperty_Impl::SimpleProperty_Impl (void)
  {
  }

  //
  // SimpleProperty_Impl
  //
  SimpleProperty_Impl::SimpleProperty_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SimpleProperty_Impl
  //
  SimpleProperty_Impl::~SimpleProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void SimpleProperty_Impl::accept (Visitor * v)
  {
    v->visit_SimpleProperty (this);
  }

  //
  // Value
  //
  void SimpleProperty_Impl::Value (const std::string & val)
  {
    static const std::string attr_Value ("Value");
    this->attribute (attr_Value)->string_value (val);
  }

  //
  // Value
  //
  std::string SimpleProperty_Impl::Value (void) const
  {
    static const std::string attr_Value ("Value");
    return this->attribute (attr_Value)->string_value ();
  }
}

