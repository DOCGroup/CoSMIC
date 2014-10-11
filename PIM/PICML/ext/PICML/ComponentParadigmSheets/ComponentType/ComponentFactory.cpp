// $Id$

#include "StdAfx.h"
#include "ComponentFactory.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactory.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKey.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactory_Impl::metaname ("ComponentFactory");

  //
  // _create (const Package_in)
  //
  ComponentFactory ComponentFactory_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < ComponentFactory > (parent, ComponentFactory_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ComponentFactory ComponentFactory_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < ComponentFactory > (parent, ComponentFactory_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactory_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentFactory (this);
    else
      v->visit_Model (this);
  }

  //
  // src_ManagesComponent
  //
  size_t ComponentFactory_Impl::src_ManagesComponent (std::vector <ManagesComponent> & items) const
  {
    return this->in_connections <ManagesComponent> (items);
  }

  //
  // has_LookupKey
  //
  bool ComponentFactory_Impl::has_LookupKey (void) const
  {
    return this->children <LookupKey> ().count () == 1;
  }

  //
  // get_LookupKey
  //
  LookupKey ComponentFactory_Impl::get_LookupKey (void) const
  {
    return this->children <LookupKey> ().first ();
  }

  //
  // get_LookupOperations
  //
  size_t ComponentFactory_Impl::get_LookupOperations (std::vector <LookupOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_LookupOperations
  //
  ::GAME::Mga::Collection_T <LookupOperation> ComponentFactory_Impl::get_LookupOperations (void) const
  {
    return this->children <LookupOperation> ();
  }

  //
  // get_FactoryOperations
  //
  size_t ComponentFactory_Impl::get_FactoryOperations (std::vector <FactoryOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_FactoryOperations
  //
  ::GAME::Mga::Collection_T <FactoryOperation> ComponentFactory_Impl::get_FactoryOperations (void) const
  {
    return this->children <FactoryOperation> ();
  }
}

