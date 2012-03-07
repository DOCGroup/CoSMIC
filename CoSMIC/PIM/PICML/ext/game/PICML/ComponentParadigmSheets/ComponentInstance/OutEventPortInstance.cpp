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
  // _create (const ComponentInstance_in)
  //
  OutEventPortInstance OutEventPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < OutEventPortInstance > (parent, OutEventPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void OutEventPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OutEventPortInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // OutEventPort_is_nil
  //
  bool OutEventPortInstance_Impl::OutEventPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_OutEventPort
  //
  OutEventPort OutEventPortInstance_Impl::get_OutEventPort (void) const
  {
    return OutEventPort::_narrow (this->refers_to ());
  }
}

