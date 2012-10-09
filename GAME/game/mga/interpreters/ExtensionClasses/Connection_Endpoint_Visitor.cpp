// $Id$

#include "StdAfx.h"
#include "Connection_Endpoint_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Connection_Endpoint_Visitor.inl"
#endif  // !defined __GAME_INLINE__

#include "Object_Manager.h"

///////////////////////////////////////////////////////////////////////////////
// Source_Connection_Endpoint_Visitor

//
// visit_Connnection
//
void Source_Connection_Endpoint_Visitor::
visit_Connection (GAME::Mga::Connection_in item)
{
  item->src ()->accept (this);
}

//
// visit_Atom
//
void Source_Connection_Endpoint_Visitor::
visit_Atom (GAME::Mga::Atom_in item)
{
  this->items_.insert (OBJECT_MANAGER->get (item));
}

///////////////////////////////////////////////////////////////////////////////
// Destination_Connection_Endpoint_Visitor

//
// visit_Connnection
//
void Destination_Connection_Endpoint_Visitor::
visit_Connection (GAME::Mga::Connection_in item)
{
  item->dst ()->accept (this);
}

//
// visit_Atom
//
void Destination_Connection_Endpoint_Visitor::
visit_Atom (GAME::Mga::Atom_in item)
{
  this->items_.insert (OBJECT_MANAGER->get (item));
}
