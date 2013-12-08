// $Id$

#include "StdAfx.h"
#include "NamedType.h"

#if !defined (__GAME_INLINE__)
#include "NamedType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string NamedType_Impl::metaname ("NamedType");

  //
  // parent_File
  //
  File NamedType_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // parent_Package
  //
  Package NamedType_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }
}
