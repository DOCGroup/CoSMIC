// $Id$

#include "StdAfx.h"
#include "AttributeInstance.h"

#if !defined (__GAME_INLINE__)
#include "AttributeInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeInstance_Impl::metaname ("AttributeInstance");

  //
  // _create (const ConnectorInstance_in)
  //
  AttributeInstance AttributeInstance_Impl::_create (const ConnectorInstance_in parent)
  {
    return ::GAME::Mga::create_object < AttributeInstance > (parent, AttributeInstance_Impl::metaname);
  }

  //
  // _create (const ComponentInstance_in)
  //
  AttributeInstance AttributeInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < AttributeInstance > (parent, AttributeInstance_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ConnectorInstance
  //
  ConnectorInstance AttributeInstance_Impl::parent_ConnectorInstance (void)
  {
    return ConnectorInstance::_narrow (this->parent ());
  }

  //
  // src_AttributeValue
  //
  size_t AttributeInstance_Impl::src_AttributeValue (std::vector <AttributeValue> & items) const
  {
    return this->in_connections <AttributeValue> (items);
  }

  //
  // dst_AttributeDelegate
  //
  size_t AttributeInstance_Impl::dst_AttributeDelegate (std::vector <AttributeDelegate> & items) const
  {
    return this->in_connections <AttributeDelegate> (items);
  }

  //
  // ReadonlyAttribute_is_nil
  //
  bool AttributeInstance_Impl::ReadonlyAttribute_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ReadonlyAttribute
  //
  void AttributeInstance_Impl::set_ReadonlyAttribute (ReadonlyAttribute_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ReadonlyAttribute
  //
  ReadonlyAttribute AttributeInstance_Impl::get_ReadonlyAttribute (void) const
  {
    return ReadonlyAttribute::_narrow (this->refers_to ());
  }
}

