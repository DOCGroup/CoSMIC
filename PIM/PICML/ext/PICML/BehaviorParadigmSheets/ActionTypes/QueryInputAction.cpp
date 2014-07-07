// $Id$

#include "StdAfx.h"
#include "QueryInputAction.h"

#if !defined (__GAME_INLINE__)
#include "QueryInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_QueryInputAction (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel QueryInputAction_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // dst_QueryInput
  //
  size_t QueryInputAction_Impl::dst_QueryInput (std::vector <QueryInput> & items) const
  {
    return this->in_connections <QueryInput> (items);
  }

  //
  // get_SimplePropertys
  //
  size_t QueryInputAction_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> QueryInputAction_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t QueryInputAction_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> QueryInputAction_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }
}

