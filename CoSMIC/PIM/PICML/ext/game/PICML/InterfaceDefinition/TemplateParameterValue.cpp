// $Id$

#include "stdafx.h"
#include "TemplateParameterValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/TemplateParameterValueType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterValue_Impl::metaname = "TemplateParameterValue";

  //
  // TemplateParameterValue_Impl
  //
  TemplateParameterValue_Impl::TemplateParameterValue_Impl (void)
  {
  }

  //
  // TemplateParameterValue_Impl
  //
  TemplateParameterValue_Impl::TemplateParameterValue_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TemplateParameterValue_Impl
  //
  TemplateParameterValue_Impl::~TemplateParameterValue_Impl (void)
  {
  }

  //
  // accept
  //
  void TemplateParameterValue_Impl::accept (Visitor * v)
  {
    v->visit_TemplateParameterValue (this);
  }

  //
  // _create
  //
  TemplateParameterValue TemplateParameterValue_Impl::_create (const TemplatePackageInstance_in parent)
  {
    return ::GAME::Mga::create_object <TemplateParameterValue> (parent, TemplateParameterValue_Impl::metaname);
  }

  //
  // parent_TemplatePackageInstance
  //
  TemplatePackageInstance TemplateParameterValue_Impl::parent_TemplatePackageInstance (void) const
  {
    return ::GAME::Mga::get_parent <TemplatePackageInstance> (this->object_.p);
  }

  //
  // refers_to_TemplateParameterValueType
  //
  TemplateParameterValueType TemplateParameterValue_Impl::refers_to_TemplateParameterValueType (void) const
  {
    return ::GAME::Mga::get_refers_to <TemplateParameterValueType> (this);
  }
}

