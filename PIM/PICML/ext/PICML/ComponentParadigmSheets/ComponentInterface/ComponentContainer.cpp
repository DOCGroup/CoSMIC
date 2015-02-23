// $Id$

#include "StdAfx.h"
#include "ComponentContainer.h"

#if !defined (__GAME_INLINE__)
#include "ComponentContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentInfoProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentConfigProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentTypes.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentContainer_Impl::metaname ("ComponentContainer");

  //
  // is_abstract
  //
  const bool ComponentContainer_Impl::is_abstract = false;

  //
  // _create (const ComponentTypes_in)
  //
  ComponentContainer ComponentContainer_Impl::_create (const ComponentTypes_in parent)
  {
    return ::GAME::Mga::create < ComponentContainer > (parent, ComponentContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentTypes
  //
  ComponentTypes ComponentContainer_Impl::parent_ComponentTypes (void)
  {
    return ComponentTypes::_narrow (this->parent ());
  }

  //
  // has_ComponentRef
  //
  bool ComponentContainer_Impl::has_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().count () == 1;
  }

  //
  // get_ComponentRef
  //
  ComponentRef ComponentContainer_Impl::get_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().first ();
  }

  //
  // get_SimplePropertys
  //
  size_t ComponentContainer_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> ComponentContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t ComponentContainer_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> ComponentContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_ComponentInfoPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentInfoPropertys (std::vector <ComponentInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInfoPropertys
  //
  ::GAME::Mga::Collection_T <ComponentInfoProperty> ComponentContainer_Impl::get_ComponentInfoPropertys (void) const
  {
    return this->children <ComponentInfoProperty> ();
  }

  //
  // get_ComponentConfigPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentConfigPropertys (std::vector <ComponentConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentConfigPropertys
  //
  ::GAME::Mga::Collection_T <ComponentConfigProperty> ComponentContainer_Impl::get_ComponentConfigPropertys (void) const
  {
    return this->children <ComponentConfigProperty> ();
  }

  //
  // get_ComponentPropertys
  //
  size_t ComponentContainer_Impl::get_ComponentPropertys (std::vector <ComponentProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPropertys
  //
  ::GAME::Mga::Collection_T <ComponentProperty> ComponentContainer_Impl::get_ComponentPropertys (void) const
  {
    return this->children <ComponentProperty> ();
  }

  //
  // get_ComponentPropertyDescriptions
  //
  size_t ComponentContainer_Impl::get_ComponentPropertyDescriptions (std::vector <ComponentPropertyDescription> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPropertyDescriptions
  //
  ::GAME::Mga::Collection_T <ComponentPropertyDescription> ComponentContainer_Impl::get_ComponentPropertyDescriptions (void) const
  {
    return this->children <ComponentPropertyDescription> ();
  }
}

