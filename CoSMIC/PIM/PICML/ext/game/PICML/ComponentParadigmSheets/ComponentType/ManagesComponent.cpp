// $Id$

#include "StdAfx.h"
#include "ManagesComponent.h"

#if !defined (__GAME_INLINE__)
#include "ManagesComponent.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ManagesComponent_Impl::metaname ("ManagesComponent");

  //
  // _create (const Package_in)
  //
  ManagesComponent ManagesComponent_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < ManagesComponent > (parent, ManagesComponent_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ManagesComponent ManagesComponent_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < ManagesComponent > (parent, ManagesComponent_Impl::metaname);
  }

  //
  // accept
  //
  void ManagesComponent_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ManagesComponent (this);
    else
      v->visit_Connection (this);
  }

  //
  // ComponentFactory
  //
  ComponentFactory ManagesComponent_Impl::src_ComponentFactory (void) const
  {
    return ComponentFactory::_narrow (this->src ());
  }

  //
  // Manageable
  //
  Manageable ManagesComponent_Impl::dst_Manageable (void) const
  {
    return Manageable::_narrow (this->dst ());
  }
}

