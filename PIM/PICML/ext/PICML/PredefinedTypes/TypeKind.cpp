// $Id$

#include "StdAfx.h"
#include "TypeKind.h"

#if !defined (__GAME_INLINE__)
#include "TypeKind.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TypeKind_Impl::metaname ("TypeKind");

  //
  // is_abstract
  //
  const bool TypeKind_Impl::is_abstract (0);

  //
  // _create (const PredefinedTypes_in)
  //
  TypeKind TypeKind_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < TypeKind > (parent, TypeKind_Impl::metaname);
  }

  //
  // accept
  //
  void TypeKind_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TypeKind (this);
    else
      v->visit_Atom (this);
  }
}

