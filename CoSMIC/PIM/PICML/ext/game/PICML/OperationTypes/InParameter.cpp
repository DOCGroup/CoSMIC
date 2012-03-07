// $Id$

#include "StdAfx.h"
#include "InParameter.h"

#if !defined (__GAME_INLINE__)
#include "InParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InParameter_Impl::metaname ("InParameter");

  //
  // _create (const OperationBase_in)
  //
  InParameter InParameter_Impl::_create (const OperationBase_in parent)
  {
    return ::GAME::Mga::create_object < InParameter > (parent, InParameter_Impl::metaname);
  }

  //
  // _create (const Operation_in)
  //
  InParameter InParameter_Impl::_create (const Operation_in parent)
  {
    return ::GAME::Mga::create_object < InParameter > (parent, InParameter_Impl::metaname);
  }

  //
  // accept
  //
  void InParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_InParameter (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }
}

