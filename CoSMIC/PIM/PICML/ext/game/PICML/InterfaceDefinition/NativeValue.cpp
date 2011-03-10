// $Id$

#include "stdafx.h"
#include "NativeValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string NativeValue_Impl::metaname = "NativeValue";

  //
  // NativeValue_Impl
  //
  NativeValue_Impl::NativeValue_Impl (void)
  {
  }

  //
  // NativeValue_Impl
  //
  NativeValue_Impl::NativeValue_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NativeValue_Impl
  //
  NativeValue_Impl::~NativeValue_Impl (void)
  {
  }

  //
  // accept
  //
  void NativeValue_Impl::accept (Visitor * v)
  {
    v->visit_NativeValue (this);
  }

  //
  // _create
  //
  NativeValue NativeValue_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object <NativeValue> (parent, NativeValue_Impl::metaname);
  }

  //
  // _create
  //
  NativeValue NativeValue_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object <NativeValue> (parent, NativeValue_Impl::metaname);
  }

  //
  // parent_File
  //
  File NativeValue_Impl::parent_File (void) const
  {
    return ::GAME::Mga::get_parent <File> (this->object_.p);
  }

  //
  // parent_Package
  //
  Package NativeValue_Impl::parent_Package (void) const
  {
    return ::GAME::Mga::get_parent <Package> (this->object_.p);
  }
}

