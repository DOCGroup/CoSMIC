// $Id$

#include "StdAfx.h"
#include "AttributeMapping.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMapping.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMapping_Impl::metaname ("AttributeMapping");

  //
  // _create (const ComponentAssembly_in)
  //
  AttributeMapping AttributeMapping_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AttributeMapping > (parent, AttributeMapping_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeMapping_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_AttributeMapping (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // src_AttributeDelegate
  //
  size_t AttributeMapping_Impl::src_AttributeDelegate (std::vector <AttributeDelegate> & items) const
  {
    return this->in_connections <AttributeDelegate> (items);
  }

  //
  // src_AttributeMappingValue
  //
  size_t AttributeMapping_Impl::src_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const
  {
    return this->in_connections <AttributeMappingValue> (items);
  }

  //
  // src_AttributeMappingDelegate
  //
  size_t AttributeMapping_Impl::src_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->in_connections <AttributeMappingDelegate> (items);
  }

  //
  // dst_AttributeMappingDelegate
  //
  size_t AttributeMapping_Impl::dst_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->in_connections <AttributeMappingDelegate> (items);
  }

  //
  // AttributeInstance_is_nil
  //
  bool AttributeMapping_Impl::AttributeInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_AttributeInstance
  //
  AttributeInstance AttributeMapping_Impl::get_AttributeInstance (void) const
  {
    return AttributeInstance::_narrow (this->refers_to ());
  }
}

