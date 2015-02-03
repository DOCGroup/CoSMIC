// $Id$

#include "StdAfx.h"
#include "OutEventPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortInstance_Impl::metaname ("OutEventPortInstance");

  //
  // is_abstract
  //
  const bool OutEventPortInstance_Impl::is_abstract (0);

  //
  // _create (const ComponentInstance_in)
  //
  OutEventPortInstance OutEventPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < OutEventPortInstance > (parent, OutEventPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void OutEventPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OutEventPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // OutEventPort_is_nil
  //
  bool OutEventPortInstance_Impl::OutEventPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_OutEventPort
  //
  void OutEventPortInstance_Impl::refers_to_OutEventPort (OutEventPort_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_OutEventPort
  //
  OutEventPort OutEventPortInstance_Impl::refers_to_OutEventPort (void) const
  {
    return OutEventPort::_narrow (this->refers_to ());
  }
}

