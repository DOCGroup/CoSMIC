// $Id$

#include "stdafx.h"
#include "ComponentContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentContainer_Impl::metaname = "ComponentContainer";

  //
  // ComponentContainer_Impl
  //
  ComponentContainer_Impl::ComponentContainer_Impl (void)
  {
  }

  //
  // ComponentContainer_Impl
  //
  ComponentContainer_Impl::ComponentContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentContainer_Impl
  //
  ComponentContainer_Impl::~ComponentContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentContainer_Impl::accept (Visitor * v)
  {
    v->visit_ComponentContainer (this);
  }

  //
  // _create
  //
  ComponentContainer ComponentContainer_Impl::_create (const ComponentTypes_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentContainer> (parent, ComponentContainer_Impl::metaname);
  }

  //
  // get_ComponentInfoPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentInfoPropertys (std::vector <ComponentInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentConfigPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentConfigPropertys (std::vector <ComponentConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t ComponentContainer_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRef
  //
  ComponentRef ComponentContainer_Impl::get_ComponentRef (void) const
  {
    // Get the collection of children.
    std::vector <ComponentRef> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentRef ();
  }

  //
  // get_ComponentPropertyDescriptions
  //
  size_t ComponentContainer_Impl::get_ComponentPropertyDescriptions (std::vector <ComponentPropertyDescription> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentPropertys (std::vector <ComponentProperty> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentTypes
  //
  ComponentTypes ComponentContainer_Impl::parent_ComponentTypes (void) const
  {
    return ::GAME::Mga::get_parent <ComponentTypes> (this->object_.p);
  }
}

