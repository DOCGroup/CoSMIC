#include "StdAfx.h"
#include "OutputAction.h"

#if !defined (__GAME_INLINE__)
#include "OutputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
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
  // is_abstract
  //
  const bool OutputAction_Impl::is_abstract = false;

  //
  // _create (const BehaviorModel_in)
  //
  OutputAction OutputAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < OutputAction > (parent, OutputAction_Impl::metaname);
  }

  //
  // accept
  //
  void OutputAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OutputAction (this);
    else
      v->visit_Model (this);
  }
}

