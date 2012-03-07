// $Id$

#include "StdAfx.h"
#include "OutputAction.h"

#if !defined (__GAME_INLINE__)
#include "OutputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string OutputAction_Impl::metaname ("OutputAction");

  //
  // _create (const BehaviorModel_in)
  //
  OutputAction OutputAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < OutputAction > (parent, OutputAction_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  OutputAction OutputAction_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < OutputAction > (parent, OutputAction_Impl::metaname);
  }

  //
  // accept
  //
  void OutputAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OutputAction (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

