// $Id$

#include "StdAfx.h"
#include "MirrorPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstance_Impl::metaname ("MirrorPortInstance");

  //
  // is_abstract
  //
  const bool MirrorPortInstance_Impl::is_abstract (0);

  //
  // _create (const ComponentInstance_in)
  //
  MirrorPortInstance MirrorPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < MirrorPortInstance > (parent, MirrorPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void MirrorPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MirrorPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // MirrorPort_is_nil
  //
  bool MirrorPortInstance_Impl::MirrorPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_MirrorPort
  //
  void MirrorPortInstance_Impl::refers_to_MirrorPort (MirrorPort_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_MirrorPort
  //
  MirrorPort MirrorPortInstance_Impl::refers_to_MirrorPort (void) const
  {
    return MirrorPort::_narrow (this->refers_to ());
  }
}

