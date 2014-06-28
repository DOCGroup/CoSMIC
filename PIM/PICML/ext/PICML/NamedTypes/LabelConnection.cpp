// $Id$

#include "StdAfx.h"
#include "LabelConnection.h"

#if !defined (__GAME_INLINE__)
#include "LabelConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/NamedTypes/Label.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string LabelConnection_Impl::metaname ("LabelConnection");

  //
  // _create (const SwitchedAggregate_in)
  //
  LabelConnection LabelConnection_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object < LabelConnection > (parent, LabelConnection_Impl::metaname);
  }

  //
  // accept
  //
  void LabelConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LabelConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate LabelConnection_Impl::parent_SwitchedAggregate (void)
  {
    return SwitchedAggregate::_narrow (this->parent ());
  }

  //
  // Member
  //
  Member LabelConnection_Impl::src_Member (void) const
  {
    return Member::_narrow (this->src ());
  }

  //
  // Label
  //
  Label LabelConnection_Impl::dst_Label (void) const
  {
    return Label::_narrow (this->dst ());
  }
}

