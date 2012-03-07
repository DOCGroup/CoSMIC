// $Id$

#include "StdAfx.h"
#include "ComponentLib.h"

#if !defined (__GAME_INLINE__)
#include "ComponentLib.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentLib_Impl::metaname ("ComponentLib");

  //
  // src_ExtResourceConn
  //
  size_t ComponentLib_Impl::src_ExtResourceConn (std::vector <ExtResourceConn> & items) const
  {
    return this->in_connections <ExtResourceConn> (items);
  }
}

