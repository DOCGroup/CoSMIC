// $Id$

#include "StdAfx.h"
#include "QueryInputAction.h"

#if !defined (__GAME_INLINE__)
#include "QueryInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"
#include "PICML/Common/Property.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInputAction_Impl::metaname ("QueryInputAction");

  //
  // _create (const BehaviorModel_in)
  //
  QueryInputAction QueryInputAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < QueryInputAction > (parent, QueryInputAction_Impl::metaname);
  }

  //
  // accept
  //
  void QueryInputAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_QueryInputAction (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // dst_QueryInput
  //
  size_t QueryInputAction_Impl::dst_QueryInput (std::vector <QueryInput> & items) const
  {
    return this->in_connections <QueryInput> (items);
  }

  //
  // get_Propertys
  //
  size_t QueryInputAction_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> QueryInputAction_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }
}

