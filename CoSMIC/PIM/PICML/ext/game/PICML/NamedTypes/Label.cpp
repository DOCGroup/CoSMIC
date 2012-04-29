// $Id$

#include "StdAfx.h"
#include "Label.h"

#if !defined (__GAME_INLINE__)
#include "Label.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Label_Impl::metaname ("Label");

  //
  // _create (const SwitchedAggregate_in)
  //
  Label Label_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object < Label > (parent, Label_Impl::metaname);
  }

  //
  // accept
  //
  void Label_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Label (this);
    else
      v->visit_Atom (this);
  }

  //
  // dst_LabelConnection
  //
  size_t Label_Impl::dst_LabelConnection (std::vector <LabelConnection> & items) const
  {
    return this->in_connections <LabelConnection> (items);
  }
}

