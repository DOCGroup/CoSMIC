// $Id$

#include "StdAfx.h"
#include "MirrorPort.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/MirrorPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPort_Impl::metaname ("MirrorPort");

  //
  // is_abstract
  //
  const bool MirrorPort_Impl::is_abstract (0);

  //
  // _create (const Component_in)
  //
  MirrorPort MirrorPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < MirrorPort > (parent, MirrorPort_Impl::metaname);
  }

  //
  // _create (const ConnectorObject_in)
  //
  MirrorPort MirrorPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create < MirrorPort > (parent, MirrorPort_Impl::metaname);
  }

  //
  // accept
  //
  void MirrorPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MirrorPort (this);
    else
      v->visit_Reference (this);
  }
}

