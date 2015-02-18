// $Id$

#include "StdAfx.h"
#include "ArrayMember.h"

#if !defined (__GAME_INLINE__)
#include "ArrayMember.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArrayMember_Impl::metaname ("ArrayMember");

  //
  // is_abstract
  //
  const bool ArrayMember_Impl::is_abstract = false;

  //
  // _create (const Exception_in)
  //
  ArrayMember ArrayMember_Impl::_create (const Exception_in parent)
  {
    return ::GAME::Mga::create < ArrayMember > (parent, ArrayMember_Impl::metaname);
  }

  //
  // _create (const Aggregate_in)
  //
  ArrayMember ArrayMember_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create < ArrayMember > (parent, ArrayMember_Impl::metaname);
  }

  //
  // _create (const ObjectByValue_in)
  //
  ArrayMember ArrayMember_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create < ArrayMember > (parent, ArrayMember_Impl::metaname);
  }

  //
  // _create (const SwitchedAggregate_in)
  //
  ArrayMember ArrayMember_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create < ArrayMember > (parent, ArrayMember_Impl::metaname);
  }

  //
  // accept
  //
  void ArrayMember_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArrayMember (this);
    else
      v->visit_Reference (this);
  }
}

