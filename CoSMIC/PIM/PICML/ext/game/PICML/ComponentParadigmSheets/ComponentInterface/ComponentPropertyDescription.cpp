// $Id$

#include "stdafx.h"
#include "ComponentPropertyDescription.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/Common/DataType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPropertyDescription_Impl::metaname = "ComponentPropertyDescription";

  //
  // ComponentPropertyDescription_Impl
  //
  ComponentPropertyDescription_Impl::ComponentPropertyDescription_Impl (void)
  {
  }

  //
  // ComponentPropertyDescription_Impl
  //
  ComponentPropertyDescription_Impl::ComponentPropertyDescription_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPropertyDescription_Impl
  //
  ComponentPropertyDescription_Impl::~ComponentPropertyDescription_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentPropertyDescription_Impl::accept (Visitor * v)
  {
    v->visit_ComponentPropertyDescription (this);
  }

  //
  // _create
  //
  ComponentPropertyDescription ComponentPropertyDescription_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentPropertyDescription> (parent, ComponentPropertyDescription_Impl::metaname);
  }

  //
  // in_ComponentProperty_connections
  //
  size_t ComponentPropertyDescription_Impl::in_ComponentProperty_connections (std::vector <ComponentProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_DataType
  //
  DataType ComponentPropertyDescription_Impl::get_DataType (void) const
  {
    // Get the collection of children.
    std::vector <DataType> items;
    this->children (items);

    return !items.empty () ? items.front () : DataType ();
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentPropertyDescription_Impl::parent_ComponentContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentContainer> (this->object_.p);
  }
}

