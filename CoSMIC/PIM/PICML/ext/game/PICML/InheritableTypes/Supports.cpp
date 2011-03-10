// $Id$

#include "stdafx.h"
#include "Supports.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/InheritableTypes/Object.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Supports_Impl::metaname = "Supports";

  //
  // Supports_Impl
  //
  Supports_Impl::Supports_Impl (void)
  {
  }

  //
  // Supports_Impl
  //
  Supports_Impl::Supports_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Supports_Impl
  //
  Supports_Impl::~Supports_Impl (void)
  {
  }

  //
  // accept
  //
  void Supports_Impl::accept (Visitor * v)
  {
    v->visit_Supports (this);
  }

  //
  // _create
  //
  Supports Supports_Impl::_create (const SupportsInterfaces_in parent)
  {
    return ::GAME::Mga::create_object <Supports> (parent, Supports_Impl::metaname);
  }

  //
  // parent_SupportsInterfaces
  //
  SupportsInterfaces Supports_Impl::parent_SupportsInterfaces (void) const
  {
    return ::GAME::Mga::get_parent <SupportsInterfaces> (this->object_.p);
  }

  //
  // refers_to_Object
  //
  Object Supports_Impl::refers_to_Object (void) const
  {
    return ::GAME::Mga::get_refers_to <Object> (this);
  }
}

