// $Id$

#include "StdAfx.h"
#include "ReadonlyAttribute.h"

#if !defined (__GAME_INLINE__)
#include "ReadonlyAttribute.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/GetException.h"
#include "PICML/InheritableTypes/AttributeMember.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ReadonlyAttribute_Impl::metaname ("ReadonlyAttribute");

  //
  // _create (const ConnectorObject_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const PortType_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create_object < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const Inheritable_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create_object < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // accept
  //
  void ReadonlyAttribute_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ReadonlyAttribute (this);
    else
      v->visit_Model (this);
  }

  //
  // get_AttributeMember
  //
  AttributeMember ReadonlyAttribute_Impl::get_AttributeMember (void) const
  {
    return this->children <AttributeMember> ().item ();
  }

  //
  // get_GetExceptions
  //
  size_t ReadonlyAttribute_Impl::get_GetExceptions (std::vector <GetException> & items) const
  {
    return this->children (items);
  }

  //
  // get_GetExceptions
  //
  ::GAME::Mga::Iterator <GetException> ReadonlyAttribute_Impl::get_GetExceptions (void) const
  {
    return this->children <GetException> ();
  }
}

