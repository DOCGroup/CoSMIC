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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ProvidedRequestPortInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ProvidedRequestPort_is_nil
  //
  bool ProvidedRequestPortInstance_Impl::ProvidedRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ProvidedRequestPort
  //
  ProvidedRequestPort ProvidedRequestPortInstance_Impl::get_ProvidedRequestPort (void) const
  {
    return ProvidedRequestPort::_narrow (this->refers_to ());
  }
}

