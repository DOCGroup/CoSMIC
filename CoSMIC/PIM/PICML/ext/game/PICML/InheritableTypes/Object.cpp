// $Id$

#include "stdafx.h"
#include "Object.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Supports.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Object_Impl::metaname = "Object";

  //
  // Object_Impl
  //
  Object_Impl::Object_Impl (void)
  {
  }

  //
  // Object_Impl
  //
  Object_Impl::Object_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Object_Impl
  //
  Object_Impl::~Object_Impl (void)
  {
  }

  //
  // accept
  //
  void Object_Impl::accept (Visitor * v)
  {
    v->visit_Object (this);
  }

  //
  // SupportsAsync
  //
  void Object_Impl::SupportsAsync (bool val)
  {
    static const std::string attr_SupportsAsync ("SupportsAsync");
    this->attribute (attr_SupportsAsync)->bool_value (val);
  }

  //
  // SupportsAsync
  //
  bool Object_Impl::SupportsAsync (void) const
  {
    static const std::string attr_SupportsAsync ("SupportsAsync");
    return this->attribute (attr_SupportsAsync)->bool_value ();
  }

  //
  // InterfaceSemantics
  //
  void Object_Impl::InterfaceSemantics (const std::string & val)
  {
    static const std::string attr_InterfaceSemantics ("InterfaceSemantics");
    this->attribute (attr_InterfaceSemantics)->string_value (val);
  }

  //
  // InterfaceSemantics
  //
  std::string Object_Impl::InterfaceSemantics (void) const
  {
    static const std::string attr_InterfaceSemantics ("InterfaceSemantics");
    return this->attribute (attr_InterfaceSemantics)->string_value ();
  }
}

