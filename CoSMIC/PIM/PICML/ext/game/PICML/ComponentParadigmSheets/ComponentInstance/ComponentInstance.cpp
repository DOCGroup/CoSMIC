// $Id$

#include "StdAfx.h"
#include "ComponentInstance.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstanceType.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstance_Impl::metaname ("ComponentInstance");

  //
  // _create (const ComponentAssembly_in)
  //
  ComponentInstance ComponentInstance_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ComponentInstance > (parent, ComponentInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_ComponentInstanceType
  //
  ComponentInstanceType ComponentInstance_Impl::get_ComponentInstanceType (void) const
  {
    return this->children <ComponentInstanceType> ().item ();
  }

  //
  // get_SupportsInstances
  //
  size_t ComponentInstance_Impl::get_SupportsInstances (std::vector <SupportsInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_SupportsInstances
  //
  ::GAME::Mga::Iterator <SupportsInstance> ComponentInstance_Impl::get_SupportsInstances (void) const
  {
    return this->children <SupportsInstance> ();
  }

  //
  // get_PortInstances
  //
  size_t ComponentInstance_Impl::get_PortInstances (std::vector <PortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_PortInstances
  //
  ::GAME::Mga::Iterator <PortInstance> ComponentInstance_Impl::get_PortInstances (void) const
  {
    return this->children <PortInstance> ();
  }
}

