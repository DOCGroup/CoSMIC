// $Id$

#include "StdAfx.h"
#include "InParameter.h"

#if !defined (__GAME_INLINE__)
#include "InParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
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
  // is_abstract
  //
  const bool InParameter_Impl::is_abstract = false;

  //
  // _create (const OperationBase_in)
  //
  InParameter InParameter_Impl::_create (const OperationBase_in parent)
  {
    return ::GAME::Mga::create < InParameter > (parent, InParameter_Impl::metaname);
  }

  //
  // _create (const Operation_in)
  //
  InParameter InParameter_Impl::_create (const Operation_in parent)
  {
    return ::GAME::Mga::create < InParameter > (parent, InParameter_Impl::metaname);
  }

  //
  // accept
  //
  void InParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InParameter (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_OperationBase
  //
  OperationBase InParameter_Impl::parent_OperationBase (void)
  {
    return OperationBase::_narrow (this->parent ());
  }
}

