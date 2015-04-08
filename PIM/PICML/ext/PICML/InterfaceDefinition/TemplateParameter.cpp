#include "StdAfx.h"
#include "TemplateParameter.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameter_Impl::metaname ("TemplateParameter");

  //
  // is_abstract
  //
  const bool TemplateParameter_Impl::is_abstract = true;

  //
  // parent_Package
  //
  Package TemplateParameter_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }
}

