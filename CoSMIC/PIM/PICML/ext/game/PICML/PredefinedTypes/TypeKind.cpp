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
  // _create (const PredefinedTypes_in)
  //
  TypeKind TypeKind_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create_root_object < TypeKind > (parent, TypeKind_Impl::metaname);
  }

  //
  // accept
  //
  void TypeKind_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TypeKind (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

