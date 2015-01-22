// $Id$

#include "StdAfx.h"
#include "ComponentInstance.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/RequiredRequestPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/InEventPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/OutEventPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/MirrorPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ExtendedPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstanceType.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstance_Impl::metaname ("ComponentInstance");

  //
  // _create (const ComponentAssembly_in)
  //
  ComponentInstance ComponentInstance_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ComponentInstance > (parent, ComponentInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentInstance (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ComponentInstance_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // has_ComponentInstanceType
  //
  bool ComponentInstance_Impl::has_ComponentInstanceType (void) const
  {
    return this->children <ComponentInstanceType> ().count () == 1;
  }

  //
  // get_ComponentInstanceType
  //
  ComponentInstanceType ComponentInstance_Impl::get_ComponentInstanceType (void) const
  {
    return this->children <ComponentInstanceType> ().first ();
  }

  //
  // get_AttributeInstances
  //
  size_t ComponentInstance_Impl::get_AttributeInstances (std::vector <AttributeInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeInstances
  //
  ::GAME::Mga::Collection_T <AttributeInstance> ComponentInstance_Impl::get_AttributeInstances (void) const
  {
    return this->children <AttributeInstance> ();
  }

  //
  // get_RequiredRequestPortInstances
  //
  size_t ComponentInstance_Impl::get_RequiredRequestPortInstances (std::vector <RequiredRequestPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPortInstances
  //
  ::GAME::Mga::Collection_T <RequiredRequestPortInstance> ComponentInstance_Impl::get_RequiredRequestPortInstances (void) const
  {
    return this->children <RequiredRequestPortInstance> ();
  }

  //
  // get_InEventPortInstances
  //
  size_t ComponentInstance_Impl::get_InEventPortInstances (std::vector <InEventPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPortInstances
  //
  ::GAME::Mga::Collection_T <InEventPortInstance> ComponentInstance_Impl::get_InEventPortInstances (void) const
  {
    return this->children <InEventPortInstance> ();
  }

  //
  // get_ProvidedRequestPortInstances
  //
  size_t ComponentInstance_Impl::get_ProvidedRequestPortInstances (std::vector <ProvidedRequestPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPortInstances
  //
  ::GAME::Mga::Collection_T <ProvidedRequestPortInstance> ComponentInstance_Impl::get_ProvidedRequestPortInstances (void) const
  {
    return this->children <ProvidedRequestPortInstance> ();
  }

  //
  // get_OutEventPortInstances
  //
  size_t ComponentInstance_Impl::get_OutEventPortInstances (std::vector <OutEventPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutEventPortInstances
  //
  ::GAME::Mga::Collection_T <OutEventPortInstance> ComponentInstance_Impl::get_OutEventPortInstances (void) const
  {
    return this->children <OutEventPortInstance> ();
  }

  //
  // get_MirrorPortInstances
  //
  size_t ComponentInstance_Impl::get_MirrorPortInstances (std::vector <MirrorPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorPortInstances
  //
  ::GAME::Mga::Collection_T <MirrorPortInstance> ComponentInstance_Impl::get_MirrorPortInstances (void) const
  {
    return this->children <MirrorPortInstance> ();
  }

  //
  // get_ExtendedPortInstances
  //
  size_t ComponentInstance_Impl::get_ExtendedPortInstances (std::vector <ExtendedPortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortInstances
  //
  ::GAME::Mga::Collection_T <ExtendedPortInstance> ComponentInstance_Impl::get_ExtendedPortInstances (void) const
  {
    return this->children <ExtendedPortInstance> ();
  }

  //
  // get_SupportsInstances
  //
  size_t ComponentInstance_Impl::get_SupportsInstances (std::vector <SupportsInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_SupportsInstances
  //
  ::GAME::Mga::Collection_T <SupportsInstance> ComponentInstance_Impl::get_SupportsInstances (void) const
  {
    return this->children <SupportsInstance> ();
  }
}

