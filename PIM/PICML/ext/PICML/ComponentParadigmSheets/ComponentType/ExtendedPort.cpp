// $Id$

#include "StdAfx.h"
#include "ExtendedPort.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ExtendedPortInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
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
  // is_abstract
  //
  const bool ExtendedPort_Impl::is_abstract = false;

  //
  // _create (const ConnectorObject_in)
  //
  ExtendedPort ExtendedPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create < ExtendedPort > (parent, ExtendedPort_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  ExtendedPort ExtendedPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < ExtendedPort > (parent, ExtendedPort_Impl::metaname);
  }

  //
  // accept
  //
  void ExtendedPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExtendedPort (this);
    else
      v->visit_Reference (this);
  }
}

