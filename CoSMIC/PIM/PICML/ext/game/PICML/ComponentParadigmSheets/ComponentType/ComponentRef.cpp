// $Id$

#include "StdAfx.h"
#include "ComponentRef.h"

#if !defined (__GAME_INLINE__)
#include "ComponentRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentRef_Impl::metaname ("ComponentRef");

  //
  // _create (const ComponentContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const ComponentImplementationContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  ComponentRef ComponentRef_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ComponentRef ComponentRef_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  ComponentRef ComponentRef_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  ComponentRef ComponentRef_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < ComponentRef > (parent, ComponentRef_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // src_ComponentProperty
  //
  size_t ComponentRef_Impl::src_ComponentProperty (std::vector <ComponentProperty> & items) const
  {
    return this->in_connections <ComponentProperty> (items);
  }

  //
  // src_ComponentConfigProperty
  //
  size_t ComponentRef_Impl::src_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const
  {
    return this->in_connections <ComponentConfigProperty> (items);
  }

  //
  // src_ComponentInfoProperty
  //
  size_t ComponentRef_Impl::src_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const
  {
    return this->in_connections <ComponentInfoProperty> (items);
  }

  //
  // dst_Implements
  //
  size_t ComponentRef_Impl::dst_Implements (std::vector <Implements> & items) const
  {
    return this->in_connections <Implements> (items);
  }

  //
  // dst_PackageInterface
  //
  size_t ComponentRef_Impl::dst_PackageInterface (std::vector <PackageInterface> & items) const
  {
    return this->in_connections <PackageInterface> (items);
  }

  //
  // Component_is_nil
  //
  bool ComponentRef_Impl::Component_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Component
  //
  Component ComponentRef_Impl::get_Component (void) const
  {
    return Component::_narrow (this->refers_to ());
  }
}

