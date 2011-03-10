// $Id$

#include "stdafx.h"
#include "ComponentServantArtifact.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentServantArtifact_Impl::metaname = "ComponentServantArtifact";

  //
  // ComponentServantArtifact_Impl
  //
  ComponentServantArtifact_Impl::ComponentServantArtifact_Impl (void)
  {
  }

  //
  // ComponentServantArtifact_Impl
  //
  ComponentServantArtifact_Impl::ComponentServantArtifact_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentServantArtifact_Impl
  //
  ComponentServantArtifact_Impl::~ComponentServantArtifact_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentServantArtifact_Impl::accept (Visitor * v)
  {
    v->visit_ComponentServantArtifact (this);
  }

  //
  // EntryPoint
  //
  void ComponentServantArtifact_Impl::EntryPoint (const std::string & val)
  {
    static const std::string attr_EntryPoint ("EntryPoint");
    this->attribute (attr_EntryPoint)->string_value (val);
  }

  //
  // EntryPoint
  //
  std::string ComponentServantArtifact_Impl::EntryPoint (void) const
  {
    static const std::string attr_EntryPoint ("EntryPoint");
    return this->attribute (attr_EntryPoint)->string_value ();
  }
}

