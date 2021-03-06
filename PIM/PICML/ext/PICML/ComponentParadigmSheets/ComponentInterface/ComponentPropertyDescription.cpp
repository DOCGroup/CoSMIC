#include "StdAfx.h"
#include "ComponentPropertyDescription.h"

#if !defined (__GAME_INLINE__)
#include "ComponentPropertyDescription.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/Common/DataType.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPropertyDescription_Impl::metaname ("ComponentPropertyDescription");

  //
  // is_abstract
  //
  const bool ComponentPropertyDescription_Impl::is_abstract = false;

  //
  // _create (const ComponentContainer_in)
  //
  ComponentPropertyDescription ComponentPropertyDescription_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentPropertyDescription > (parent, ComponentPropertyDescription_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentPropertyDescription_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentPropertyDescription (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentPropertyDescription_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
  }

  //
  // dst_of_ComponentProperty
  //
  size_t ComponentPropertyDescription_Impl::dst_of_ComponentProperty (std::vector <ComponentProperty> & items) const
  {
    return this->in_connections <ComponentProperty> (items);
  }

  //
  // dst_of_ComponentProperty
  //
  GAME::Mga::Collection_T <ComponentProperty> ComponentPropertyDescription_Impl::dst_of_ComponentProperty (void) const
  {
    return this->in_connections <ComponentProperty> ("dst");
  }

  //
  // has_DataType
  //
  bool ComponentPropertyDescription_Impl::has_DataType (void) const
  {
    return this->children <DataType> ().count () == 1;
  }

  //
  // get_DataType
  //
  DataType ComponentPropertyDescription_Impl::get_DataType (void) const
  {
    return this->children <DataType> ().first ();
  }
}

