// $Id$

#include "StdAfx.h"
#include "RequiredRequestPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "RequiredRequestPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortInstance_Impl::metaname ("RequiredRequestPortInstance");

  //
  // _create (const ComponentInstance_in)
  //
  RequiredRequestPortInstance RequiredRequestPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < RequiredRequestPortInstance > (parent, RequiredRequestPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void RequiredRequestPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RequiredRequestPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // RequiredRequestPort_is_nil
  //
  bool RequiredRequestPortInstance_Impl::RequiredRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_RequiredRequestPort
  //
  void RequiredRequestPortInstance_Impl::set_RequiredRequestPort (RequiredRequestPort_in item)
  {
    this->refers_to (item);
  }

  //
  // get_RequiredRequestPort
  //
  RequiredRequestPort RequiredRequestPortInstance_Impl::get_RequiredRequestPort (void) const
  {
    return RequiredRequestPort::_narrow (this->refers_to ());
  }
}

