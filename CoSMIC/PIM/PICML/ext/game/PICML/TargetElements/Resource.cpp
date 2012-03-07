// $Id$

#include "StdAfx.h"
#include "Resource.h"

#if !defined (__GAME_INLINE__)
#include "Resource.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Node.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Resource_Impl::metaname ("Resource");

  //
  // _create (const Bridge_in)
  //
  Resource Resource_Impl::_create (const Bridge_in parent)
  {
    return ::GAME::Mga::create_object < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // _create (const Interconnect_in)
  //
  Resource Resource_Impl::_create (const Interconnect_in parent)
  {
    return ::GAME::Mga::create_object < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // _create (const Node_in)
  //
  Resource Resource_Impl::_create (const Node_in parent)
  {
    return ::GAME::Mga::create_object < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // accept
  //
  void Resource_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Resource (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

