// $Id$

#include "StdAfx.h"
#include "ConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "ConfigProperty.inl"
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
  const std::string ConfigProperty_Impl::metaname ("ConfigProperty");

  //
  // _create (const ImplementationContainer_in)
  //
  ConfigProperty ConfigProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ConfigProperty > (parent, ConfigProperty_Impl::metaname);
  }

  //
  // accept
  //
  void ConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ConfigProperty (this);
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
  Implemenation ConfigProperty_Impl::src_Implemenation (void) const
  {
    return Implemenation::_narrow (this->src ());
  }

  //
  // Property
  //
  Property ConfigProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

