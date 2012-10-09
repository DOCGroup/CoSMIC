// $Id$

#include "StdAfx.h"
#include "Proxy_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Proxy_Visitor.inl"
#endif  // !defined __GAME_INLINE__

//
// visit_Reference
//
void Proxy_Visitor::visit_Reference (GAME::Mga::Reference_in ref)
{
  GAME::Mga::FCO item = ref->refers_to ();

  if (!item.is_nil ())
    item->accept (this);
}

//
// visit_Reference
//
void Proxy_Fwd_Visitor::visit_Reference (GAME::Mga::Reference_in ref)
{
  GAME::Mga::FCO item = ref->refers_to ();

  if (!item.is_nil ())
    item->accept (this->fwd_);
}

//
// visit_Reference
//
void Proxy_Fwd_Visitor::visit_Atom (GAME::Mga::Atom_in item)
{
  item->accept (this->fwd_);
}
