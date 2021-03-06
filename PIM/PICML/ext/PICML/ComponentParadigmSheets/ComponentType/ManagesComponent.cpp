#include "StdAfx.h"
#include "ManagesComponent.h"

#if !defined (__GAME_INLINE__)
#include "ManagesComponent.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
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
  // is_abstract
  //
  const bool ManagesComponent_Impl::is_abstract = false;

  //
  // _create (const Package_in, ComponentFactory_in src, Manageable_in dst)
  //
  ManagesComponent ManagesComponent_Impl::_create (const Package_in parent, ComponentFactory_in src, Manageable_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ManagesComponent_Impl::metaname, src, dst);
  }

  //
  // _create (const File_in, ComponentFactory_in src, Manageable_in dst)
  //
  ManagesComponent ManagesComponent_Impl::_create (const File_in parent, ComponentFactory_in src, Manageable_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ManagesComponent_Impl::metaname, src, dst);
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
  // parent_Package
  //
  Package ManagesComponent_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }

  //
  // parent_File
  //
  File ManagesComponent_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
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

