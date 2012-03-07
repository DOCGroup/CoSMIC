// $Id$

#include "StdAfx.h"
#include "ConnectorInherits.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorInherits.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorInherits_Impl::metaname ("ConnectorInherits");

  //
  // _create (const ConnectorObject_in)
  //
  ConnectorInherits ConnectorInherits_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorInherits > (parent, ConnectorInherits_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorInherits_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ConnectorInherits (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ConnectorObject_is_nil
  //
  bool ConnectorInherits_Impl::ConnectorObject_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ConnectorObject
  //
  ConnectorObject ConnectorInherits_Impl::get_ConnectorObject (void) const
  {
    return ConnectorObject::_narrow (this->refers_to ());
  }
}

