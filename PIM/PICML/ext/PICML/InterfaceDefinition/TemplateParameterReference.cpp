// $Id$

#include "StdAfx.h"
#include "TemplateParameterReference.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameterReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TemplateParameterReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TemplatePackageAlias
  //
  TemplatePackageAlias TemplateParameterReference_Impl::parent_TemplatePackageAlias (void)
  {
    return TemplatePackageAlias::_narrow (this->parent ());
  }

  //
  // TemplateParameter_is_nil
  //
  bool TemplateParameterReference_Impl::TemplateParameter_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_TemplateParameter
  //
  void TemplateParameterReference_Impl::set_TemplateParameter (TemplateParameter_in item)
  {
    this->refers_to (item);
  }

  //
  // get_TemplateParameter
  //
  TemplateParameter TemplateParameterReference_Impl::get_TemplateParameter (void) const
  {
    return TemplateParameter::_narrow (this->refers_to ());
  }
}

