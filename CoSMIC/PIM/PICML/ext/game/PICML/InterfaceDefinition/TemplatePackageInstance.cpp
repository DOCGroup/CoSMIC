// $Id$

#include "stdafx.h"
#include "TemplatePackageInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameterValue.h"
#include "PICML/InterfaceDefinition/PackageType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplatePackageInstance_Impl::metaname = "TemplatePackageInstance";

  //
  // TemplatePackageInstance_Impl
  //
  TemplatePackageInstance_Impl::TemplatePackageInstance_Impl (void)
  {
  }

  //
  // TemplatePackageInstance_Impl
  //
  TemplatePackageInstance_Impl::TemplatePackageInstance_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TemplatePackageInstance_Impl
  //
  TemplatePackageInstance_Impl::~TemplatePackageInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void TemplatePackageInstance_Impl::accept (Visitor * v)
  {
    v->visit_TemplatePackageInstance (this);
  }

  //
  // get_TemplateParameterValues
  //
  size_t TemplatePackageInstance_Impl::get_TemplateParameterValues (std::vector <TemplateParameterValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageType
  //
  PackageType TemplatePackageInstance_Impl::get_PackageType (void) const
  {
    // Get the collection of children.
    std::vector <PackageType> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageType ();
  }
}

