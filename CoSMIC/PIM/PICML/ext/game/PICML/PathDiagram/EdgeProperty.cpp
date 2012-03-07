// $Id$

#include "StdAfx.h"
#include "EdgeProperty.h"

#if !defined (__GAME_INLINE__)
#include "EdgeProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/Edge.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EdgeProperty_Impl::metaname ("EdgeProperty");

  //
  // _create (const Path_in)
  //
  EdgeProperty EdgeProperty_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < EdgeProperty > (parent, EdgeProperty_Impl::metaname);
  }

  //
  // accept
  //
  void EdgeProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_EdgeProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Property
  //
  Property EdgeProperty_Impl::src_Property (void) const
  {
    return Property::_narrow (this->src ());
  }

  //
  // Edge
  //
  Edge EdgeProperty_Impl::dst_Edge (void) const
  {
    return Edge::_narrow (this->dst ());
  }
}

