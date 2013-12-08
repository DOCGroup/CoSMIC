// $Id$

#include "StdAfx.h"
#include "ProvidedRequestPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortInstance_Impl::metaname ("ProvidedRequestPortInstance");

  //
  // _create (const ComponentInstance_in)
  //
  ProvidedRequestPortInstance ProvidedRequestPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPortInstance > (parent, ProvidedRequestPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ProvidedRequestPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ProvidedRequestPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // ProvidedRequestPort_is_nil
  //
  bool ProvidedRequestPortInstance_Impl::ProvidedRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ProvidedRequestPort
  //
  void ProvidedRequestPortInstance_Impl::set_ProvidedRequestPort (ProvidedRequestPort_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ProvidedRequestPort
  //
  ProvidedRequestPort ProvidedRequestPortInstance_Impl::get_ProvidedRequestPort (void) const
  {
    return ProvidedRequestPort::_narrow (this->refers_to ());
  }
}
