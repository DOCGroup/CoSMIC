// $Id$

#include "StdAfx.h"
#include "SharedResource.h"

#if !defined (__GAME_INLINE__)
#include "SharedResource.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/Domain/Shares.h"
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
  // _create (const Domain_in)
  //
  SharedResource SharedResource_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < SharedResource > (parent, SharedResource_Impl::metaname);
  }

  //
  // accept
  //
  void SharedResource_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_SharedResource (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // dst_Shares
  //
  size_t SharedResource_Impl::dst_Shares (std::vector <Shares> & items) const
  {
    return this->in_connections <Shares> (items);
  }
}

