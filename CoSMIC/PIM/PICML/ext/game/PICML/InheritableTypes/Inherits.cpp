// $Id$

#include "stdafx.h"
#include "Inherits.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inheritable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Inherits_Impl::metaname = "Inherits";

  //
  // Inherits_Impl
  //
  Inherits_Impl::Inherits_Impl (void)
  {
  }

  //
  // Inherits_Impl
  //
  Inherits_Impl::Inherits_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Inherits_Impl
  //
  Inherits_Impl::~Inherits_Impl (void)
  {
  }

  //
  // accept
  //
  void Inherits_Impl::accept (Visitor * v)
  {
    v->visit_Inherits (this);
  }

  //
  // _create
  //
  Inherits Inherits_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create_object <Inherits> (parent, Inherits_Impl::metaname);
  }

  //
  // parent_Inheritable
  //
  Inheritable Inherits_Impl::parent_Inheritable (void) const
  {
    return ::GAME::Mga::get_parent <Inheritable> (this->object_.p);
  }

  //
  // refers_to_Inheritable
  //
  Inheritable Inherits_Impl::refers_to_Inheritable (void) const
  {
    return ::GAME::Mga::get_refers_to <Inheritable> (this);
  }
}

