// $Id$

#include "stdafx.h"
#include "LabelConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/Label.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LabelConnection_Impl::metaname = "LabelConnection";

  //
  // LabelConnection_Impl
  //
  LabelConnection_Impl::LabelConnection_Impl (void)
  {
  }

  //
  // LabelConnection_Impl
  //
  LabelConnection_Impl::LabelConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LabelConnection_Impl
  //
  LabelConnection_Impl::~LabelConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void LabelConnection_Impl::accept (Visitor * v)
  {
    v->visit_LabelConnection (this);
  }

  //
  // _create
  //
  LabelConnection LabelConnection_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object <LabelConnection> (parent, LabelConnection_Impl::metaname);
  }

  //
  // src_Member
  //
  Member LabelConnection_Impl::src_Member (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Member::_narrow (target);
  }

  //
  // dst_Label
  //
  Label LabelConnection_Impl::dst_Label (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Label::_narrow (target);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate LabelConnection_Impl::parent_SwitchedAggregate (void) const
  {
    return ::GAME::Mga::get_parent <SwitchedAggregate> (this->object_.p);
  }
}

