#include "StdAfx.h"
#include "MirrorPortInstanceBase.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPortInstanceBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstanceBase_Impl::metaname ("MirrorPortInstanceBase");

  //
  // is_abstract
  //
  const bool MirrorPortInstanceBase_Impl::is_abstract = true;

  //
  // src_of_MirrorDelegate
  //
  size_t MirrorPortInstanceBase_Impl::src_of_MirrorDelegate (std::vector <MirrorDelegate> & items) const
  {
    return this->in_connections <MirrorDelegate> (items);
  }

  //
  // has_src_of_MirrorDelegate
  //
  bool MirrorPortInstanceBase_Impl::has_src_of_MirrorDelegate (void) const
  {
    return this->in_connections <MirrorDelegate> ("src").count () == 1;
  }

  //
  // src_of_MirrorDelegate
  //
  MirrorDelegate MirrorPortInstanceBase_Impl::src_of_MirrorDelegate (void) const
  {
    return this->in_connections <MirrorDelegate> ("src").first ();
  }
}

