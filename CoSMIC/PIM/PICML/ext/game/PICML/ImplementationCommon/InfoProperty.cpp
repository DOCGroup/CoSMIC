// $Id$

#include "StdAfx.h"
#include "InfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "InfoProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/ImplementationCommon/Implemenation.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InfoProperty_Impl::metaname ("InfoProperty");

  //
  // _create (const ImplementationContainer_in)
  //
  InfoProperty InfoProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < InfoProperty > (parent, InfoProperty_Impl::metaname);
  }

  //
  // accept
  //
  void InfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_InfoProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Implemenation
  //
  Implemenation InfoProperty_Impl::src_Implemenation (void) const
  {
    return Implemenation::_narrow (this->src ());
  }

  //
  // Property
  //
  Property InfoProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

