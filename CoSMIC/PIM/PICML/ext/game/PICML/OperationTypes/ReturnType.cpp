// $Id$

#include "StdAfx.h"
#include "ReturnType.h"

#if !defined (__GAME_INLINE__)
#include "ReturnType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ReturnType_Impl::metaname ("ReturnType");

  //
  // _create (const Operation_in)
  //
  ReturnType ReturnType_Impl::_create (const Operation_in parent)
  {
    return ::GAME::Mga::create_object < ReturnType > (parent, ReturnType_Impl::metaname);
  }

  //
  // _create (const TwowayOperation_in)
  //
  ReturnType ReturnType_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create_object < ReturnType > (parent, ReturnType_Impl::metaname);
  }

  //
  // accept
  //
  void ReturnType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ReturnType (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool ReturnType_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType ReturnType_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

