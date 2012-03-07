// $Id$

#include "StdAfx.h"
#include "AttributeInstance.h"

#if !defined (__GAME_INLINE__)
#include "AttributeInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_AttributeInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
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
  // AttributeInstance_is_nil
  //
  bool AttributeInstance_Impl::AttributeInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_AttributeInstance
  //
  AttributeInstance AttributeInstance_Impl::get_AttributeInstance (void) const
  {
    return AttributeInstance::_narrow (this->refers_to ());
  }

  //
  // ReadonlyAttribute_is_nil
  //
  bool AttributeInstance_Impl::ReadonlyAttribute_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ReadonlyAttribute
  //
  ReadonlyAttribute AttributeInstance_Impl::get_ReadonlyAttribute (void) const
  {
    return ReadonlyAttribute::_narrow (this->refers_to ());
  }
}

