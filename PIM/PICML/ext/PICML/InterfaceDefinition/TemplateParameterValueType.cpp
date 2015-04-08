#include "StdAfx.h"
#include "TemplateParameterValueType.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameterValueType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameterValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterValueType_Impl::metaname ("TemplateParameterValueType");

  //
  // is_abstract
  //
  const bool TemplateParameterValueType_Impl::is_abstract = true;
}

