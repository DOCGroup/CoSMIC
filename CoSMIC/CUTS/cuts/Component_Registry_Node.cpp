// $Id$

#include "cuts/Component_Registry_Node.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Component_Registry_Node.inl"
#endif

//
// CUTS_Component_Registry_Node
//
CUTS_INLINE
CUTS_Component_Registry_Node::
CUTS_Component_Registry_Node (void)
{
  this->info_.uid_ = ACE_reinterpret_cast (size_t, this);
}
