// $Id$

#include "StdAfx.h"
#include "MirrorPort.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
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
  // _create (const ConnectorObject_in)
  //
  MirrorPort MirrorPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < MirrorPort > (parent, MirrorPort_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  MirrorPort MirrorPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < MirrorPort > (parent, MirrorPort_Impl::metaname);
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

  //
  // MirrorPort_is_nil
  //
  bool MirrorPort_Impl::MirrorPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MirrorPort
  //
  MirrorPort MirrorPort_Impl::get_MirrorPort (void) const
  {
    return MirrorPort::_narrow (this->refers_to ());
  }
}

