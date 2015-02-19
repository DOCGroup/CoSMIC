// $Id$

#include "StdAfx.h"
#include "SharedResource.h"

#if !defined (__GAME_INLINE__)
#include "SharedResource.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Shares.h"
#include "PICML/Domain/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SharedResource_Impl::metaname ("SharedResource");

  //
  // is_abstract
  //
  const bool SharedResource_Impl::is_abstract = false;

  //
  // _create (const Domain_in)
  //
  SharedResource SharedResource_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create < SharedResource > (parent, SharedResource_Impl::metaname);
  }

  //
  // accept
  //
  void SharedResource_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SharedResource (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Domain
  //
  Domain SharedResource_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // dst_of_Shares
  //
  size_t SharedResource_Impl::dst_of_Shares (std::vector <Shares> & items) const
  {
    return this->in_connections <Shares> (items);
  }

  //
  // dst_of_Shares
  //
  GAME::Mga::Collection_T <Shares> SharedResource_Impl::dst_of_Shares (void) const
  {
    return this->in_connections <Shares> ("dst");
  }
}

