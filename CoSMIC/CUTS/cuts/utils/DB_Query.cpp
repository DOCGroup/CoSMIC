// $Id$

#include "DB_Query.h"

#if !defined (__CUTS_INLINE__)
#include "DB_Query.inl"
#endif

//
// destroy
//
void CUTS_DB_Query::destroy (void)
{
  delete this;
}
