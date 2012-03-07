// $Id$

#include "StdAfx.h"
#include "ExtResourceConn.h"

#if !defined (__GAME_INLINE__)
#include "ExtResourceConn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "PICML/ComponentBuild/ComponentLib.h"
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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ExtResourceConn (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

