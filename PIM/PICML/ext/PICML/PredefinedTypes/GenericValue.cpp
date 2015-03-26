// $Id$

#include "StdAfx.h"
#include "GenericValue.h"

#if !defined (__GAME_INLINE__)
#include "GenericValue.inl"
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
  const std::string GenericValue_Impl::metaname ("GenericValue");

  //
  // is_abstract
  //
  const bool GenericValue_Impl::is_abstract = false;

  //
  // _create (const PredefinedTypes_in)
  //
  GenericValue GenericValue_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < GenericValue > (parent, GenericValue_Impl::metaname);
  }

  //
  // accept
  //
  void GenericValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_GenericValue (this);
    else
      v->visit_Atom (this);
  }
}

