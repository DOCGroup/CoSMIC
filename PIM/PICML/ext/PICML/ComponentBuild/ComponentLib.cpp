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
  // is_abstract
  //
  const bool ComponentLib_Impl::is_abstract = true;

  //
  // parent_Project
  //
  Project ComponentLib_Impl::parent_Project (void)
  {
    return Project::_narrow (this->parent ());
  }

  //
  // src_of_ExtResourceConn
  //
  size_t ComponentLib_Impl::src_of_ExtResourceConn (std::vector <ExtResourceConn> & items) const
  {
    return this->in_connections <ExtResourceConn> (items);
  }

  //
  // src_of_ExtResourceConn
  //
  GAME::Mga::Collection_T <ExtResourceConn> ComponentLib_Impl::src_of_ExtResourceConn (void) const
  {
    return this->in_connections <ExtResourceConn> ("src");
  }
}

