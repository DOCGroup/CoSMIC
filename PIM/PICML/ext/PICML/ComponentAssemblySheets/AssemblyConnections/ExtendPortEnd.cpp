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
  const bool ExtendPortEnd_Impl::is_abstract = true;

  //
  // src_of_Publish
  //
  size_t ExtendPortEnd_Impl::src_of_Publish (std::vector <Publish> & items) const
  {
    return this->in_connections <Publish> (items);
  }

  //
  // has_src_of_Publish
  //
  bool ExtendPortEnd_Impl::has_src_of_Publish (void) const
  {
    return this->in_connections <Publish> ("src").count () == 1;
  }

  //
  // src_of_Publish
  //
  Publish ExtendPortEnd_Impl::src_of_Publish (void) const
  {
    return this->in_connections <Publish> ("src").first ();
  }

  //
  // dst_of_Consume
  //
  size_t ExtendPortEnd_Impl::dst_of_Consume (std::vector <Consume> & items) const
  {
    return this->in_connections <Consume> (items);
  }

  //
  // has_dst_of_Consume
  //
  bool ExtendPortEnd_Impl::has_dst_of_Consume (void) const
  {
    return this->in_connections <Consume> ("dst").count () == 1;
  }

  //
  // dst_of_Consume
  //
  Consume ExtendPortEnd_Impl::dst_of_Consume (void) const
  {
    return this->in_connections <Consume> ("dst").first ();
  }
}

