// $Id$

#include "StdAfx.h"
#include "TemplateParameterValue.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameterValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/TemplateParameterValueType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterValue_Impl::metaname ("TemplateParameterValue");

  //
  // _create (const TemplatePackageInstance_in)
  //
  TemplateParameterValue TemplateParameterValue_Impl::_create (const TemplatePackageInstance_in parent)
  {
    return ::GAME::Mga::create_object < TemplateParameterValue > (parent, TemplateParameterValue_Impl::metaname);
  }

  //
  // accept
  //
  void TemplateParameterValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TemplateParameterValue (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // TemplateParameterValueType_is_nil
  //
  bool TemplateParameterValue_Impl::TemplateParameterValueType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_TemplateParameterValueType
  //
  TemplateParameterValueType TemplateParameterValue_Impl::get_TemplateParameterValueType (void) const
  {
    return TemplateParameterValueType::_narrow (this->refers_to ());
  }
}

