// $Id$

#include "StdAfx.h"
#include "TemplateParameterReference.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameterReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterReference_Impl::metaname ("TemplateParameterReference");

  //
  // _create (const TemplatePackageAlias_in)
  //
  TemplateParameterReference TemplateParameterReference_Impl::_create (const TemplatePackageAlias_in parent)
  {
    return ::GAME::Mga::create_object < TemplateParameterReference > (parent, TemplateParameterReference_Impl::metaname);
  }

  //
  // accept
  //
  void TemplateParameterReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TemplateParameterReference (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // TemplateParameter_is_nil
  //
  bool TemplateParameterReference_Impl::TemplateParameter_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_TemplateParameter
  //
  TemplateParameter TemplateParameterReference_Impl::get_TemplateParameter (void) const
  {
    return TemplateParameter::_narrow (this->refers_to ());
  }
}

