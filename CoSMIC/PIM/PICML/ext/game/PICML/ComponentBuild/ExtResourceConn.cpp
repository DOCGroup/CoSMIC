// $Id$

#include "stdafx.h"
#include "ExtResourceConn.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ComponentLib.h"
#include "PICML/ComponentBuild/ExternalResources.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtResourceConn_Impl::metaname = "ExtResourceConn";

  //
  // ExtResourceConn_Impl
  //
  ExtResourceConn_Impl::ExtResourceConn_Impl (void)
  {
  }

  //
  // ExtResourceConn_Impl
  //
  ExtResourceConn_Impl::ExtResourceConn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtResourceConn_Impl
  //
  ExtResourceConn_Impl::~ExtResourceConn_Impl (void)
  {
  }

  //
  // accept
  //
  void ExtResourceConn_Impl::accept (Visitor * v)
  {
    v->visit_ExtResourceConn (this);
  }

  //
  // _create
  //
  ExtResourceConn ExtResourceConn_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object <ExtResourceConn> (parent, ExtResourceConn_Impl::metaname);
  }

  //
  // src_ComponentLib
  //
  ComponentLib ExtResourceConn_Impl::src_ComponentLib (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentLib::_narrow (target);
  }

  //
  // dst_ExternalResources
  //
  ExternalResources ExtResourceConn_Impl::dst_ExternalResources (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ExternalResources::_narrow (target);
  }

  //
  // parent_Project
  //
  Project ExtResourceConn_Impl::parent_Project (void) const
  {
    return ::GAME::Mga::get_parent <Project> (this->object_.p);
  }
}

