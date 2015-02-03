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
  // is_abstract
  //
  const bool ExtendPortEnd_Impl::is_abstract (1);

  //
  // src_of_Publish
  //
  size_t ExtendPortEnd_Impl::src_of_Publish (std::vector <Publish> & items) const
  {
    return this->in_connections <Publish> (items);
  }

  //
  // src_of_Publish
  //
  GAME::Mga::Collection_T <Publish> ExtendPortEnd_Impl::src_of_Publish (void) const
  {
    return this->in_connections <Publish> ("src");
  }

  //
  // dst_of_Consume
  //
  size_t ExtendPortEnd_Impl::dst_of_Consume (std::vector <Consume> & items) const
  {
    return this->in_connections <Consume> (items);
  }

  //
  // dst_of_Consume
  //
  GAME::Mga::Collection_T <Consume> ExtendPortEnd_Impl::dst_of_Consume (void) const
  {
    return this->in_connections <Consume> ("dst");
  }
}

