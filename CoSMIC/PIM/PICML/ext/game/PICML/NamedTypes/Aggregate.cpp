// $Id$

#include "stdafx.h"
#include "Aggregate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/Key.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Aggregate_Impl::metaname = "Aggregate";

  //
  // Aggregate_Impl
  //
  Aggregate_Impl::Aggregate_Impl (void)
  {
  }

  //
  // Aggregate_Impl
  //
  Aggregate_Impl::Aggregate_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Aggregate_Impl
  //
  Aggregate_Impl::~Aggregate_Impl (void)
  {
  }

  //
  // accept
  //
  void Aggregate_Impl::accept (Visitor * v)
  {
    v->visit_Aggregate (this);
  }

  //
  // get_KeyMembers
  //
  size_t Aggregate_Impl::get_KeyMembers (std::vector <KeyMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  size_t Aggregate_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Key
  //
  Key Aggregate_Impl::get_Key (void) const
  {
    // Get the collection of children.
    std::vector <Key> items;
    this->children (items);

    return !items.empty () ? items.front () : Key ();
  }
}

