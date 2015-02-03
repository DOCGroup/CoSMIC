// $Id$

#include "StdAfx.h"
#include "OutParameter.h"

#if !defined (__GAME_INLINE__)
#include "OutParameter.inl"
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
  const std::string OutParameter_Impl::metaname ("OutParameter");

  //
  // is_abstract
  //
  const bool OutParameter_Impl::is_abstract (0);

  //
  // _create (const TwowayOperation_in)
  //
  OutParameter OutParameter_Impl::_create (const TwowayOperation_in parent)
  {
    return ::GAME::Mga::create < OutParameter > (parent, OutParameter_Impl::metaname);
  }

  //
  // _create (const Operation_in)
  //
  OutParameter OutParameter_Impl::_create (const Operation_in parent)
  {
    return ::GAME::Mga::create < OutParameter > (parent, OutParameter_Impl::metaname);
  }

  //
  // accept
  //
  void OutParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OutParameter (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TwowayOperation
  //
  TwowayOperation OutParameter_Impl::parent_TwowayOperation (void)
  {
    return TwowayOperation::_narrow (this->parent ());
  }
}

