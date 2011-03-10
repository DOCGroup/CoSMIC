// $Id$

#include "stdafx.h"
#include "Label.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Label_Impl::metaname = "Label";

  //
  // Label_Impl
  //
  Label_Impl::Label_Impl (void)
  {
  }

  //
  // Label_Impl
  //
  Label_Impl::Label_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Label_Impl
  //
  Label_Impl::~Label_Impl (void)
  {
  }

  //
  // accept
  //
  void Label_Impl::accept (Visitor * v)
  {
    v->visit_Label (this);
  }

  //
  // _create
  //
  Label Label_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object <Label> (parent, Label_Impl::metaname);
  }

  //
  // in_LabelConnection_connections
  //
  size_t Label_Impl::in_LabelConnection_connections (std::vector <LabelConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate Label_Impl::parent_SwitchedAggregate (void) const
  {
    return ::GAME::Mga::get_parent <SwitchedAggregate> (this->object_.p);
  }
}

