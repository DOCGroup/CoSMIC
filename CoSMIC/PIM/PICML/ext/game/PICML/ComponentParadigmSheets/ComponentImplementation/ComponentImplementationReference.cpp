// $Id$

#include "stdafx.h"
#include "ComponentImplementationReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementationReference_Impl::metaname = "ComponentImplementationReference";

  //
  // ComponentImplementationReference_Impl
  //
  ComponentImplementationReference_Impl::ComponentImplementationReference_Impl (void)
  {
  }

  //
  // ComponentImplementationReference_Impl
  //
  ComponentImplementationReference_Impl::ComponentImplementationReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementationReference_Impl
  //
  ComponentImplementationReference_Impl::~ComponentImplementationReference_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentImplementationReference_Impl::accept (Visitor * v)
  {
    v->visit_ComponentImplementationReference (this);
  }

  //
  // refers_to_ComponentImplementation
  //
  ComponentImplementation ComponentImplementationReference_Impl::refers_to_ComponentImplementation (void) const
  {
    return ::GAME::Mga::get_refers_to <ComponentImplementation> (this);
  }
}

