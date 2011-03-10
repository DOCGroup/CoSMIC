// $Id$

#include "stdafx.h"
#include "Targets.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Targets_Impl::metaname = "Targets";

  //
  // Targets_Impl
  //
  Targets_Impl::Targets_Impl (void)
  {
  }

  //
  // Targets_Impl
  //
  Targets_Impl::Targets_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Targets_Impl
  //
  Targets_Impl::~Targets_Impl (void)
  {
  }

  //
  // accept
  //
  void Targets_Impl::accept (Visitor * v)
  {
    v->visit_Targets (this);
  }

  //
  // _create
  //
  Targets Targets_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <Targets> (parent, Targets_Impl::metaname);
  }

  ::GAME::Mga::RootFolder Targets_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

