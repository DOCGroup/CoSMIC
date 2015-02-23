// $Id$

#include "StdAfx.h"
#include "AttributeMapping.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMapping.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
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
  // is_abstract
  //
  const bool AttributeMapping_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  AttributeMapping AttributeMapping_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < AttributeMapping > (parent, AttributeMapping_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeMapping_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeMapping (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AttributeMapping_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // src_of_AttributeDelegate
  //
  size_t AttributeMapping_Impl::src_of_AttributeDelegate (std::vector <AttributeDelegate> & items) const
  {
    return this->in_connections <AttributeDelegate> (items);
  }

  //
  // src_of_AttributeDelegate
  //
  GAME::Mga::Collection_T <AttributeDelegate> AttributeMapping_Impl::src_of_AttributeDelegate (void) const
  {
    return this->in_connections <AttributeDelegate> ("src");
  }

  //
  // src_of_AttributeMappingDelegate
  //
  size_t AttributeMapping_Impl::src_of_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->in_connections <AttributeMappingDelegate> (items);
  }

  //
  // src_of_AttributeMappingDelegate
  //
  GAME::Mga::Collection_T <AttributeMappingDelegate> AttributeMapping_Impl::src_of_AttributeMappingDelegate (void) const
  {
    return this->in_connections <AttributeMappingDelegate> ("src");
  }

  //
  // src_of_AttributeMappingValue
  //
  size_t AttributeMapping_Impl::src_of_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const
  {
    return this->in_connections <AttributeMappingValue> (items);
  }

  //
  // has_src_of_AttributeMappingValue
  //
  bool AttributeMapping_Impl::has_src_of_AttributeMappingValue (void) const
  {
    return this->in_connections <AttributeMappingValue> ("src").count () == 1;
  }

  //
  // src_of_AttributeMappingValue
  //
  AttributeMappingValue AttributeMapping_Impl::src_of_AttributeMappingValue (void) const
  {
    return this->in_connections <AttributeMappingValue> ("src").first ();
  }

  //
  // dst_of_AttributeMappingDelegate
  //
  size_t AttributeMapping_Impl::dst_of_AttributeMappingDelegate (std::vector <AttributeMappingDelegate> & items) const
  {
    return this->in_connections <AttributeMappingDelegate> (items);
  }

  //
  // has_dst_of_AttributeMappingDelegate
  //
  bool AttributeMapping_Impl::has_dst_of_AttributeMappingDelegate (void) const
  {
    return this->in_connections <AttributeMappingDelegate> ("dst").count () == 1;
  }

  //
  // dst_of_AttributeMappingDelegate
  //
  AttributeMappingDelegate AttributeMapping_Impl::dst_of_AttributeMappingDelegate (void) const
  {
    return this->in_connections <AttributeMappingDelegate> ("dst").first ();
  }

  //
  // AttributeInstance_is_nil
  //
  bool AttributeMapping_Impl::AttributeInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_AttributeInstance
  //
  void AttributeMapping_Impl::refers_to_AttributeInstance (AttributeInstance_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_AttributeInstance
  //
  AttributeInstance AttributeMapping_Impl::refers_to_AttributeInstance (void) const
  {
    return AttributeInstance::_narrow (this->refers_to ());
  }
}

