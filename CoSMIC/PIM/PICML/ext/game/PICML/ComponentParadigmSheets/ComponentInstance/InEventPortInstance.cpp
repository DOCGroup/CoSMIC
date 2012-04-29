// $Id$

#include "StdAfx.h"
#include "InEventPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "InEventPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortInstance_Impl::metaname ("InEventPortInstance");

  //
  // _create (const ComponentInstance_in)
  //
  InEventPortInstance InEventPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < InEventPortInstance > (parent, InEventPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void InEventPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InEventPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // InEventPort_is_nil
  //
  bool InEventPortInstance_Impl::InEventPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_InEventPort
  //
  InEventPort InEventPortInstance_Impl::get_InEventPort (void) const
  {
    return InEventPort::_narrow (this->refers_to ());
  }
}

