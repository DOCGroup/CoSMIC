// $Id$

#include "StdAfx.h"
#include "SupportsInterfaces.h"

#if !defined (__GAME_INLINE__)
#include "SupportsInterfaces.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Supports.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SupportsInterfaces_Impl::metaname ("SupportsInterfaces");

  //
  // get_Supportss
  //
  size_t SupportsInterfaces_Impl::get_Supportss (std::vector <Supports> & items) const
  {
    return this->children (items);
  }

  //
  // get_Supportss
  //
  ::GAME::Mga::Collection_T <Supports> SupportsInterfaces_Impl::get_Supportss (void) const
  {
    return this->children <Supports> ();
  }
}

