// $Id$

#include "StdAfx.h"
#include "TemplatePackageInstance.h"

#if !defined (__GAME_INLINE__)
#include "TemplatePackageInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplateParameterValue.h"
#include "PICML/InterfaceDefinition/PackageType.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TemplatePackageInstance_Impl::metaname ("TemplatePackageInstance");

  //
  // _create (const Package_in)
  //
  TemplatePackageInstance TemplatePackageInstance_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < TemplatePackageInstance > (parent, TemplatePackageInstance_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  TemplatePackageInstance TemplatePackageInstance_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < TemplatePackageInstance > (parent, TemplatePackageInstance_Impl::metaname);
  }

  //
  // accept
  //
  void TemplatePackageInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TemplatePackageInstance (this);
    else
      v->visit_Model (this);
  }

  //
  // has_PackageType
  //
  bool TemplatePackageInstance_Impl::has_PackageType (void) const
  {
    return this->children <PackageType> ().count () == 1;
  }

  //
  // get_PackageType
  //
  PackageType TemplatePackageInstance_Impl::get_PackageType (void) const
  {
    return this->children <PackageType> ().first ();
  }

  //
  // get_TemplateParameterValues
  //
  size_t TemplatePackageInstance_Impl::get_TemplateParameterValues (std::vector <TemplateParameterValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_TemplateParameterValues
  //
  ::GAME::Mga::Collection_T <TemplateParameterValue> TemplatePackageInstance_Impl::get_TemplateParameterValues (void) const
  {
    return this->children <TemplateParameterValue> ();
  }
}

