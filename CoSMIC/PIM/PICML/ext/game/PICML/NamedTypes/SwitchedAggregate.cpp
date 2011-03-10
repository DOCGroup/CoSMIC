// $Id$

#include "stdafx.h"
#include "SwitchedAggregate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/Label.h"
#include "PICML/NamedTypes/Discriminator.h"
#include "PICML/NamedTypes/LabelConnection.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SwitchedAggregate_Impl::metaname = "SwitchedAggregate";

  //
  // SwitchedAggregate_Impl
  //
  SwitchedAggregate_Impl::SwitchedAggregate_Impl (void)
  {
  }

  //
  // SwitchedAggregate_Impl
  //
  SwitchedAggregate_Impl::SwitchedAggregate_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SwitchedAggregate_Impl
  //
  SwitchedAggregate_Impl::~SwitchedAggregate_Impl (void)
  {
  }

  //
  // accept
  //
  void SwitchedAggregate_Impl::accept (Visitor * v)
  {
    v->visit_SwitchedAggregate (this);
  }

  //
  // get_Members
  //
  size_t SwitchedAggregate_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Labels
  //
  size_t SwitchedAggregate_Impl::get_Labels (std::vector <Label> & items) const
  {
    return this->children (items);
  }

  //
  // get_Discriminator
  //
  Discriminator SwitchedAggregate_Impl::get_Discriminator (void) const
  {
    // Get the collection of children.
    std::vector <Discriminator> items;
    this->children (items);

    return !items.empty () ? items.front () : Discriminator ();
  }

  //
  // get_LabelConnections
  //
  size_t SwitchedAggregate_Impl::get_LabelConnections (std::vector <LabelConnection> & items) const
  {
    return this->children (items);
  }
}

