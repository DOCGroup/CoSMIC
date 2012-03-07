// $Id$

#include "StdAfx.h"
#include "PathProperty.h"

#if !defined (__GAME_INLINE__)
#include "PathProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/Paths.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PathProperty_Impl::metaname ("PathProperty");

  //
  // _create (const Paths_in)
  //
  PathProperty PathProperty_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object < PathProperty > (parent, PathProperty_Impl::metaname);
  }

  //
  // accept
  //
  void PathProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PathProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Path
  //
  Path PathProperty_Impl::src_Path (void) const
  {
    return Path::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PathProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

