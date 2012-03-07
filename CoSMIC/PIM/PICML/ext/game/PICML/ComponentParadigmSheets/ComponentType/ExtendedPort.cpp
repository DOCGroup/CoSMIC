// $Id$

#include "StdAfx.h"
#include "ExtendedPort.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPort_Impl::metaname ("ExtendedPort");

  //
  // _create (const ConnectorObject_in)
  //
  ExtendedPort ExtendedPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < ExtendedPort > (parent, ExtendedPort_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  ExtendedPort ExtendedPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < ExtendedPort > (parent, ExtendedPort_Impl::metaname);
  }

  //
  // accept
  //
  void ExtendedPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ExtendedPort (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ExtendedPort_is_nil
  //
  bool ExtendedPort_Impl::ExtendedPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ExtendedPort
  //
  ExtendedPort ExtendedPort_Impl::get_ExtendedPort (void) const
  {
    return ExtendedPort::_narrow (this->refers_to ());
  }
}

