#include "StdAfx.h"
#include "ExtendedPortInstance.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortInstance_Impl::metaname ("ExtendedPortInstance");

  //
  // is_abstract
  //
  const bool ExtendedPortInstance_Impl::is_abstract = false;

  //
  // _create (const ComponentInstance_in)
  //
  ExtendedPortInstance ExtendedPortInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < ExtendedPortInstance > (parent, ExtendedPortInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ExtendedPortInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExtendedPortInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // ExtendedPort_is_nil
  //
  bool ExtendedPortInstance_Impl::ExtendedPort_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ExtendedPort
  //
  void ExtendedPortInstance_Impl::refers_to_ExtendedPort (ExtendedPort_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ExtendedPort
  //
  ExtendedPort ExtendedPortInstance_Impl::refers_to_ExtendedPort (void) const
  {
    return ExtendedPort::_narrow (this->refers_to ());
  }
}

