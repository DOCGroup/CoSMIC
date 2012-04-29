// $Id$

#include "StdAfx.h"
#include "RequiredRequestPort.h"

#if !defined (__GAME_INLINE__)
#include "RequiredRequestPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPort_Impl::metaname ("RequiredRequestPort");

  //
  // _create (const ConnectorObject_in)
  //
  RequiredRequestPort RequiredRequestPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < RequiredRequestPort > (parent, RequiredRequestPort_Impl::metaname);
  }

  //
  // _create (const PortType_in)
  //
  RequiredRequestPort RequiredRequestPort_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create_object < RequiredRequestPort > (parent, RequiredRequestPort_Impl::metaname);
  }

  //
  // accept
  //
  void RequiredRequestPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RequiredRequestPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // RequiredRequestPort_is_nil
  //
  bool RequiredRequestPort_Impl::RequiredRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_RequiredRequestPort
  //
  RequiredRequestPort RequiredRequestPort_Impl::get_RequiredRequestPort (void) const
  {
    return RequiredRequestPort::_narrow (this->refers_to ());
  }

  //
  // Provideable_is_nil
  //
  bool RequiredRequestPort_Impl::Provideable_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Provideable
  //
  Provideable RequiredRequestPort_Impl::get_Provideable (void) const
  {
    return Provideable::_narrow (this->refers_to ());
  }
}

