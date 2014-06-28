// $Id$

#include "StdAfx.h"
#include "ExtendPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "ExtendPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Publish.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/Consume.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendPortEnd_Impl::metaname ("ExtendPortEnd");

  //
  // src_Publish
  //
  size_t ExtendPortEnd_Impl::src_Publish (std::vector <Publish> & items) const
  {
    return this->in_connections <Publish> (items);
  }

  //
  // dst_Consume
  //
  size_t ExtendPortEnd_Impl::dst_Consume (std::vector <Consume> & items) const
  {
    return this->in_connections <Consume> (items);
  }
}

