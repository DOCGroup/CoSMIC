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
  // is_abstract
  //
  const bool AttributeInstance_Impl::is_abstract (0);

  //
  // _create (const ConnectorInstance_in)
  //
  AttributeInstance AttributeInstance_Impl::_create (const ConnectorInstance_in parent)
  {
    return ::GAME::Mga::create < AttributeInstance > (parent, AttributeInstance_Impl::metaname);
  }

  //
  // _create (const ComponentInstance_in)
  //
  AttributeInstance AttributeInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < AttributeInstance > (parent, AttributeInstance_Impl::metaname);
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
  // src_of_AttributeValue
  //
  size_t AttributeInstance_Impl::src_of_AttributeValue (std::vector <AttributeValue> & items) const
  {
    return this->in_connections <AttributeValue> (items);
  }

  //
  // src_of_AttributeValue
  //
  GAME::Mga::Collection_T <AttributeValue> AttributeInstance_Impl::src_of_AttributeValue (void) const
  {
    return this->in_connections <AttributeValue> ("src");
  }

  //
  // dst_of_AttributeDelegate
  //
  size_t AttributeInstance_Impl::dst_of_AttributeDelegate (std::vector <AttributeDelegate> & items) const
  {
    return this->in_connections <AttributeDelegate> (items);
  }

  //
  // dst_of_AttributeDelegate
  //
  GAME::Mga::Collection_T <AttributeDelegate> AttributeInstance_Impl::dst_of_AttributeDelegate (void) const
  {
    return this->in_connections <AttributeDelegate> ("dst");
  }

  //
  // ReadonlyAttribute_is_nil
  //
  bool AttributeInstance_Impl::ReadonlyAttribute_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ReadonlyAttribute
  //
  void AttributeInstance_Impl::refers_to_ReadonlyAttribute (ReadonlyAttribute_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ReadonlyAttribute
  //
  ReadonlyAttribute AttributeInstance_Impl::refers_to_ReadonlyAttribute (void) const
  {
    return ReadonlyAttribute::_narrow (this->refers_to ());
  }
}

