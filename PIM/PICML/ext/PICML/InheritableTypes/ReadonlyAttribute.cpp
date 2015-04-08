#include "StdAfx.h"
#include "ReadonlyAttribute.h"

#if !defined (__GAME_INLINE__)
#include "ReadonlyAttribute.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/InheritableTypes/AttributeMember.h"
#include "PICML/InheritableTypes/GetException.h"
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
  // is_abstract
  //
  const bool ReadonlyAttribute_Impl::is_abstract = false;

  //
  // _create (const ConnectorObject_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const Inheritable_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // _create (const PortType_in)
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create < ReadonlyAttribute > (parent, ReadonlyAttribute_Impl::metaname);
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
  // parent_ConnectorObject
  //
  ConnectorObject ReadonlyAttribute_Impl::parent_ConnectorObject (void)
  {
    return ConnectorObject::_narrow (this->parent ());
  }

  //
  // parent_Inheritable
  //
  Inheritable ReadonlyAttribute_Impl::parent_Inheritable (void)
  {
    return Inheritable::_narrow (this->parent ());
  }

  //
  // parent_Component
  //
  Component ReadonlyAttribute_Impl::parent_Component (void)
  {
    return Component::_narrow (this->parent ());
  }

  //
  // parent_PortType
  //
  PortType ReadonlyAttribute_Impl::parent_PortType (void)
  {
    return PortType::_narrow (this->parent ());
  }

  //
  // has_AttributeMember
  //
  bool ReadonlyAttribute_Impl::has_AttributeMember (void) const
  {
    return this->children <AttributeMember> ().count () == 1;
  }

  //
  // get_AttributeMember
  //
  AttributeMember ReadonlyAttribute_Impl::get_AttributeMember (void) const
  {
    return this->children <AttributeMember> ().first ();
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
  ::GAME::Mga::Collection_T <GetException> ReadonlyAttribute_Impl::get_GetExceptions (void) const
  {
    return this->children <GetException> ();
  }
}

