// $Id$

#include "StdAfx.h"
#include "TemplatePackageAlias.h"

#if !defined (__GAME_INLINE__)
#include "TemplatePackageAlias.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
#include "PICML/InterfaceDefinition/PackageType.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TemplatePackageAlias_Impl::metaname ("TemplatePackageAlias");

  //
  // _create (const File_in)
  //
  TemplatePackageAlias TemplatePackageAlias_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < TemplatePackageAlias > (parent, TemplatePackageAlias_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  TemplatePackageAlias TemplatePackageAlias_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < TemplatePackageAlias > (parent, TemplatePackageAlias_Impl::metaname);
  }

  //
  // accept
  //
  void TemplatePackageAlias_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TemplatePackageAlias (this);
    else
      v->visit_Model (this);
  }

  //
  // has_PackageType
  //
  bool TemplatePackageAlias_Impl::has_PackageType (void) const
  {
    return this->children <PackageType> ().count () == 1;
  }

  //
  // get_PackageType
  //
  PackageType TemplatePackageAlias_Impl::get_PackageType (void) const
  {
    return this->children <PackageType> ().item ();
  }

  //
  // get_TemplateParameterReferences
  //
  size_t TemplatePackageAlias_Impl::get_TemplateParameterReferences (std::vector <TemplateParameterReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplateParameterReferences
  //
  ::GAME::Mga::Iterator <TemplateParameterReference> TemplatePackageAlias_Impl::get_TemplateParameterReferences (void) const
  {
    return this->children <TemplateParameterReference> ();
  }
}

