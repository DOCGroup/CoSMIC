// $Id$

#include "StdAfx.h"
#include "File.h"

#if !defined (__GAME_INLINE__)
#include "File.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/InterfaceDefinition/InterfaceDefinitions.h"
#include "PICML/InterfaceDefinition/Constant.h"
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
  const std::string File_Impl::metaname ("File");

  //
  // _create (const InterfaceDefinitions_in)
  //
  File File_Impl::_create (const InterfaceDefinitions_in parent)
  {
    return ::GAME::Mga::create_root_object < File > (parent, File_Impl::metaname);
  }

  //
  // accept
  //
  void File_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_File (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_ComponentRefs
  //
  size_t File_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  ::GAME::Mga::Iterator <ComponentRef> File_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }

  //
  // get_ManagesComponents
  //
  size_t File_Impl::get_ManagesComponents (std::vector <ManagesComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ManagesComponents
  //
  ::GAME::Mga::Iterator <ManagesComponent> File_Impl::get_ManagesComponents (void) const
  {
    return this->children <ManagesComponent> ();
  }

  //
  // get_Packages
  //
  size_t File_Impl::get_Packages (std::vector <Package> & items) const
  {
    return this->children (items);
  }

  //
  // get_Packages
  //
  ::GAME::Mga::Iterator <Package> File_Impl::get_Packages (void) const
  {
    return this->children <Package> ();
  }

  //
  // get_Exceptions
  //
  size_t File_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  ::GAME::Mga::Iterator <Exception> File_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
  }

  //
  // get_FileRefs
  //
  size_t File_Impl::get_FileRefs (std::vector <FileRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_FileRefs
  //
  ::GAME::Mga::Iterator <FileRef> File_Impl::get_FileRefs (void) const
  {
    return this->children <FileRef> ();
  }

  //
  // get_Constants
  //
  size_t File_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  ::GAME::Mga::Iterator <Constant> File_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }

  //
  // get_NativeValues
  //
  size_t File_Impl::get_NativeValues (std::vector <NativeValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_NativeValues
  //
  ::GAME::Mga::Iterator <NativeValue> File_Impl::get_NativeValues (void) const
  {
    return this->children <NativeValue> ();
  }

  //
  // get_NamedTypes
  //
  size_t File_Impl::get_NamedTypes (std::vector <NamedType> & items) const
  {
    return this->children (items);
  }

  //
  // get_NamedTypes
  //
  ::GAME::Mga::Iterator <NamedType> File_Impl::get_NamedTypes (void) const
  {
    return this->children <NamedType> ();
  }
}

