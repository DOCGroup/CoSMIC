// $Id$

#include "stdafx.h"
#include "Package.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/PackageType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Package_Impl::metaname = "Package";

  //
  // Package_Impl
  //
  Package_Impl::Package_Impl (void)
  {
  }

  //
  // Package_Impl
  //
  Package_Impl::Package_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Package_Impl
  //
  Package_Impl::~Package_Impl (void)
  {
  }

  //
  // accept
  //
  void Package_Impl::accept (Visitor * v)
  {
    v->visit_Package (this);
  }

  //
  // _create
  //
  Package Package_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object <Package> (parent, Package_Impl::metaname);
  }

  //
  // _create
  //
  Package Package_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object <Package> (parent, Package_Impl::metaname);
  }

  //
  // get_NativeValues
  //
  size_t Package_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplateParameters
  //
  size_t Package_Impl::get_TemplateParameters (std::vector <TemplateParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  size_t Package_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  size_t Package_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_NamedTypes
  //
  size_t Package_Impl::get_NamedTypes (std::vector <NamedType> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  size_t Package_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  size_t Package_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Packages
  //
  size_t Package_Impl::get_Packages (std::vector <Package> & items) const
  {
    return this->children (items);
  }

  //
  // parent_File
  //
  File Package_Impl::parent_File (void) const
  {
    return ::GAME::Mga::get_parent <File> (this->object_.p);
  }
}

