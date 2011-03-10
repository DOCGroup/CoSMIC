// $Id$

#include "stdafx.h"
#include "File.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/NativeValue.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/InterfaceDefinitions.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string File_Impl::metaname = "File";

  //
  // File_Impl
  //
  File_Impl::File_Impl (void)
  {
  }

  //
  // File_Impl
  //
  File_Impl::File_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~File_Impl
  //
  File_Impl::~File_Impl (void)
  {
  }

  //
  // accept
  //
  void File_Impl::accept (Visitor * v)
  {
    v->visit_File (this);
  }

  //
  // _create
  //
  File File_Impl::_create (const InterfaceDefinitions_in parent)
  {
    return ::GAME::Mga::create_root_object <File> (parent, File_Impl::metaname);
  }

  //
  // Path
  //
  void File_Impl::Path (const std::string & val)
  {
    static const std::string attr_Path ("Path");
    this->attribute (attr_Path)->string_value (val);
  }

  //
  // Path
  //
  std::string File_Impl::Path (void) const
  {
    static const std::string attr_Path ("Path");
    return this->attribute (attr_Path)->string_value ();
  }

  //
  // get_NativeValues
  //
  size_t File_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  size_t File_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  size_t File_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_NamedTypes
  //
  size_t File_Impl::get_NamedTypes (std::vector <NamedType> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  size_t File_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_FileRefs
  //
  size_t File_Impl::get_FileRefs (std::vector <FileRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  size_t File_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Packages
  //
  size_t File_Impl::get_Packages (std::vector <Package> & items) const
  {
    return this->children (items);
  }

  //
  // parent_InterfaceDefinitions
  //
  InterfaceDefinitions File_Impl::parent_InterfaceDefinitions (void) const
  {
    return ::GAME::Mga::get_parent <InterfaceDefinitions> (this->object_.p);
  }
}

