// $Id$

#include "StdAfx.h"
#include "TypeEncoding.h"

#if !defined (__GAME_INLINE__)
#include "TypeEncoding.inl"
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
  const std::string TypeEncoding_Impl::metaname ("TypeEncoding");

  //
  // is_abstract
  //
  const bool TypeEncoding_Impl::is_abstract = false;

  //
  // _create (const PredefinedTypes_in)
  //
  TypeEncoding TypeEncoding_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < TypeEncoding > (parent, TypeEncoding_Impl::metaname);
  }

  //
  // accept
  //
  void TypeEncoding_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TypeEncoding (this);
    else
      v->visit_Atom (this);
  }
}

