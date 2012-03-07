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
  // _create (const ComponentInstance_in)
  //
  MirrorPortInstance MirrorPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < MirrorPortInstance > (parent, MirrorPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void MirrorPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_MirrorPortInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // MirrorPort_is_nil
  //
  bool MirrorPortInstance_Impl::MirrorPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MirrorPort
  //
  MirrorPort MirrorPortInstance_Impl::get_MirrorPort (void) const
  {
    return MirrorPort::_narrow (this->refers_to ());
  }
}

