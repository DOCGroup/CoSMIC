#include "StdAfx.h"
#include "InoutParameter.h"

#if !defined (__GAME_INLINE__)
#include "InoutParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InoutParameter_Impl::metaname ("InoutParameter");

  //
  // is_abstract
  //
  const bool InoutParameter_Impl::is_abstract = false;

  //
  // _create (const TwowayOperation_in)
  //
  InoutParameter InoutParameter_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create < InoutParameter > (parent, InoutParameter_Impl::metaname);
  }

  //
  // _create (const Operation_in)
  //
  InoutParameter InoutParameter_Impl::_create (const Operation_in parent)
  {
    return ::GAME::Mga::create < InoutParameter > (parent, InoutParameter_Impl::metaname);
  }

  //
  // accept
  //
  void InoutParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InoutParameter (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TwowayOperation
  //
  TwowayOperation InoutParameter_Impl::parent_TwowayOperation (void)
  {
    return TwowayOperation::_narrow (this->parent ());
  }
}

