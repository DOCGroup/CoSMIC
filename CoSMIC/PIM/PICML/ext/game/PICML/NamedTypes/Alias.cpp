// $Id$

#include "stdafx.h"
#include "Alias.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Alias_Impl::metaname = "Alias";

  //
  // Alias_Impl
  //
  Alias_Impl::Alias_Impl (void)
  {
  }

  //
  // Alias_Impl
  //
  Alias_Impl::Alias_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Alias_Impl
  //
  Alias_Impl::~Alias_Impl (void)
  {
  }

  //
  // accept
  //
  void Alias_Impl::accept (Visitor * v)
  {
    v->visit_Alias (this);
  }

  //
  // refers_to_MemberType
  //
  MemberType Alias_Impl::refers_to_MemberType (void) const
  {
    return ::GAME::Mga::get_refers_to <MemberType> (this);
  }
}

