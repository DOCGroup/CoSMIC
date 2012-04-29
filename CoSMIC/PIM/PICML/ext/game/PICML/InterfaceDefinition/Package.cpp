// $Id$

#include "StdAfx.h"
#include "Package.h"

#if !defined (__GAME_INLINE__)
#include "Package.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "PICML/NamedTypes/NamedType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Package_Impl::metaname ("Package");

  //
  // _create (const File_in)
  //
  Package Package_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Package > (parent, Package_Impl::metaname);
  }

  //
  // accept
  //
  void Package_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Package (this);
    else
      v->visit_Model (this);
  }

  //
  // get_ComponentRefs
  //
  size_t Package_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  ::GAME::Mga::Iterator <ComponentRef> Package_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }

  //
  // get_ManagesComponents
  //
  size_t Package_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  ::GAME::Mga::Iterator <ManagesComponent> Package_Impl::get_ManagesComponents (void) const
  {
    return this->children <ManagesComponent> ();
  }

  //
  // get_Exceptions
  //
  size_t Package_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  ::GAME::Mga::Iterator <Exception> Package_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
  }

  //
  // get_Constants
  //
  size_t Package_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  ::GAME::Mga::Iterator <Constant> Package_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }

  //
  // get_TemplateParameters
  //
  size_t Package_Impl::get_TemplateParameters (std::vector <TemplateParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplateParameters
  //
  ::GAME::Mga::Iterator <TemplateParameter> Package_Impl::get_TemplateParameters (void) const
  {
    return this->children <TemplateParameter> ();
  }

  //
  // get_NativeValues
  //
  size_t Package_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_NativeValues
  //
  ::GAME::Mga::Iterator <NativeValue> Package_Impl::get_NativeValues (void) const
  {
    return this->children <NativeValue> ();
  }

  //
  // get_NamedTypes
  //
  size_t Package_Impl::get_NamedTypes (std::vector <NamedType> & items) const
  {
    return this->children (items);
  }

  //
  // get_NamedTypes
  //
  ::GAME::Mga::Iterator <NamedType> Package_Impl::get_NamedTypes (void) const
  {
    return this->children <NamedType> ();
  }
}

