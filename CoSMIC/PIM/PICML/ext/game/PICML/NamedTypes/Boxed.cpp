// $Id$

#include "stdafx.h"
#include "Boxed.h"

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
  const std::string Boxed_Impl::metaname = "Boxed";

  //
  // Boxed_Impl
  //
  Boxed_Impl::Boxed_Impl (void)
  {
  }

  //
  // Boxed_Impl
  //
  Boxed_Impl::Boxed_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Boxed_Impl
  //
  Boxed_Impl::~Boxed_Impl (void)
  {
  }

  //
  // accept
  //
  void Boxed_Impl::accept (Visitor * v)
  {
    v->visit_Boxed (this);
  }

  //
  // refers_to_MemberType
  //
  MemberType Boxed_Impl::refers_to_MemberType (void) const
  {
    return ::GAME::Mga::get_refers_to <MemberType> (this);
  }
}

