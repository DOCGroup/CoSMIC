// $Id$

#include "StdAfx.h"
#include "GenericValueObject.h"

#if !defined (__GAME_INLINE__)
#include "GenericValueObject.inl"
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
  const std::string GenericValueObject_Impl::metaname ("GenericValueObject");

  //
  // is_abstract
  //
  const bool GenericValueObject_Impl::is_abstract (0);

  //
  // _create (const PredefinedTypes_in)
  //
  GenericValueObject GenericValueObject_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < GenericValueObject > (parent, GenericValueObject_Impl::metaname);
  }

  //
  // accept
  //
  void GenericValueObject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_GenericValueObject (this);
    else
      v->visit_Atom (this);
  }
}

