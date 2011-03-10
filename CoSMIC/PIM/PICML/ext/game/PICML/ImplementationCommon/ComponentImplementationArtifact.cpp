// $Id$

#include "stdafx.h"
#include "ComponentImplementationArtifact.h"

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
  const std::string ComponentImplementationArtifact_Impl::metaname = "ComponentImplementationArtifact";

  //
  // ComponentImplementationArtifact_Impl
  //
  ComponentImplementationArtifact_Impl::ComponentImplementationArtifact_Impl (void)
  {
  }

  //
  // ComponentImplementationArtifact_Impl
  //
  ComponentImplementationArtifact_Impl::ComponentImplementationArtifact_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementationArtifact_Impl
  //
  ComponentImplementationArtifact_Impl::~ComponentImplementationArtifact_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentImplementationArtifact_Impl::accept (Visitor * v)
  {
    v->visit_ComponentImplementationArtifact (this);
  }

  //
  // EntryPoint
  //
  void ComponentImplementationArtifact_Impl::EntryPoint (const std::string & val)
  {
    static const std::string attr_EntryPoint ("EntryPoint");
    this->attribute (attr_EntryPoint)->string_value (val);
  }

  //
  // EntryPoint
  //
  std::string ComponentImplementationArtifact_Impl::EntryPoint (void) const
  {
    static const std::string attr_EntryPoint ("EntryPoint");
    return this->attribute (attr_EntryPoint)->string_value ();
  }
}

