// $Id$

#include "stdafx.h"
#include "TemplateParameterValueType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InterfaceDefinition/TemplateParameterValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterValueType_Impl::metaname = "TemplateParameterValueType";

  //
  // TemplateParameterValueType_Impl
  //
  TemplateParameterValueType_Impl::TemplateParameterValueType_Impl (void)
  {
  }

  //
  // TemplateParameterValueType_Impl
  //
  TemplateParameterValueType_Impl::TemplateParameterValueType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TemplateParameterValueType_Impl
  //
  TemplateParameterValueType_Impl::~TemplateParameterValueType_Impl (void)
  {
  }
}

