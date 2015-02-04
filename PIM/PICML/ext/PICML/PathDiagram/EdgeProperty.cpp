// $Id$

#include "StdAfx.h"
#include "EdgeProperty.h"

#if !defined (__GAME_INLINE__)
#include "EdgeProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
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
  // is_abstract
  //
  const bool EdgeProperty_Impl::is_abstract = false;

  //
  // _create (const Path_in, Property_in src, Edge_in dst)
  //
  EdgeProperty EdgeProperty_Impl::_create (const Path_in parent, Property_in src, Edge_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, EdgeProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void EdgeProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_EdgeProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Path
  //
  Path EdgeProperty_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
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

