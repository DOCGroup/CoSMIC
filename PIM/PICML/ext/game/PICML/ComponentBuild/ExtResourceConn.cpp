// $Id$

#include "StdAfx.h"
#include "ExtResourceConn.h"

#if !defined (__GAME_INLINE__)
#include "ExtResourceConn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ComponentLib.h"
#include "PICML/ComponentBuild/StubProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/ExecutorProject.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExtResourceConn_Impl::metaname ("ExtResourceConn");

  //
  // _create (const Project_in)
  //
  ExtResourceConn ExtResourceConn_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ExtResourceConn > (parent, ExtResourceConn_Impl::metaname);
  }

  //
  // accept
  //
  void ExtResourceConn_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExtResourceConn (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Project
  //
  Project ExtResourceConn_Impl::parent_Project (void)
  {
    return Project::_narrow (this->parent ());
  }

  //
  // ComponentLib
  //
  ComponentLib ExtResourceConn_Impl::src_ComponentLib (void) const
  {
    return ComponentLib::_narrow (this->src ());
  }

  //
  // ExternalResources
  //
  ExternalResources ExtResourceConn_Impl::dst_ExternalResources (void) const
  {
    return ExternalResources::_narrow (this->dst ());
  }
}

