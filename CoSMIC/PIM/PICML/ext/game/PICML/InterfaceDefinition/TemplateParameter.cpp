// $Id$

#include "stdafx.h"
#include "TemplateParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InterfaceDefinition/Package.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameter_Impl::metaname = "TemplateParameter";

  //
  // TemplateParameter_Impl
  //
  TemplateParameter_Impl::TemplateParameter_Impl (void)
  {
  }

  //
  // TemplateParameter_Impl
  //
  TemplateParameter_Impl::TemplateParameter_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TemplateParameter_Impl
  //
  TemplateParameter_Impl::~TemplateParameter_Impl (void)
  {
  }

  //
  // parent_Package
  //
  Package TemplateParameter_Impl::parent_Package (void) const
  {
    return ::GAME::Mga::get_parent <Package> (this->object_.p);
  }
}

