// $Id$

#include "stdafx.h"
#include "Constant.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/ConstantType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Constant_Impl::metaname = "Constant";

  //
  // Constant_Impl
  //
  Constant_Impl::Constant_Impl (void)
  {
  }

  //
  // Constant_Impl
  //
  Constant_Impl::Constant_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Constant_Impl
  //
  Constant_Impl::~Constant_Impl (void)
  {
  }

  //
  // accept
  //
  void Constant_Impl::accept (Visitor * v)
  {
    v->visit_Constant (this);
  }

  //
  // _create
  //
  Constant Constant_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object <Constant> (parent, Constant_Impl::metaname);
  }

  //
  // _create
  //
  Constant Constant_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object <Constant> (parent, Constant_Impl::metaname);
  }

  //
  // value
  //
  void Constant_Impl::value (const std::string & val)
  {
    static const std::string attr_value ("value");
    this->attribute (attr_value)->string_value (val);
  }

  //
  // value
  //
  std::string Constant_Impl::value (void) const
  {
    static const std::string attr_value ("value");
    return this->attribute (attr_value)->string_value ();
  }

  //
  // parent_File
  //
  File Constant_Impl::parent_File (void) const
  {
    return ::GAME::Mga::get_parent <File> (this->object_.p);
  }

  //
  // parent_Package
  //
  Package Constant_Impl::parent_Package (void) const
  {
    return ::GAME::Mga::get_parent <Package> (this->object_.p);
  }

  //
  // refers_to_ConstantType
  //
  ConstantType Constant_Impl::refers_to_ConstantType (void) const
  {
    return ::GAME::Mga::get_refers_to <ConstantType> (this);
  }
}

