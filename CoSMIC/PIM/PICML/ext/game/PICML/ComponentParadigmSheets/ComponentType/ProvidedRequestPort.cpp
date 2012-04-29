// $Id$

#include "StdAfx.h"
#include "ProvidedRequestPort.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
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
  const std::string ProvidedRequestPort_Impl::metaname ("ProvidedRequestPort");

  //
  // _create (const ConnectorObject_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // _create (const PortType_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // accept
  //
  void ProvidedRequestPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ProvidedRequestPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // ProvidedRequestPort_is_nil
  //
  bool ProvidedRequestPort_Impl::ProvidedRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ProvidedRequestPort
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::get_ProvidedRequestPort (void) const
  {
    return ProvidedRequestPort::_narrow (this->refers_to ());
  }

  //
  // Provideable_is_nil
  //
  bool ProvidedRequestPort_Impl::Provideable_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Provideable
  //
  Provideable ProvidedRequestPort_Impl::get_Provideable (void) const
  {
    return Provideable::_narrow (this->refers_to ());
  }
}

