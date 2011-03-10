// $Id$

#include "stdafx.h"
#include "SupportsInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/InheritableTypes/Supports.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SupportsInstance_Impl::metaname = "SupportsInstance";

  //
  // SupportsInstance_Impl
  //
  SupportsInstance_Impl::SupportsInstance_Impl (void)
  {
  }

  //
  // SupportsInstance_Impl
  //
  SupportsInstance_Impl::SupportsInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SupportsInstance_Impl
  //
  SupportsInstance_Impl::~SupportsInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void SupportsInstance_Impl::accept (Visitor * v)
  {
    v->visit_SupportsInstance (this);
  }

  //
  // _create
  //
  SupportsInstance SupportsInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object <SupportsInstance> (parent, SupportsInstance_Impl::metaname);
  }

  //
  // parent_ComponentInstance
  //
  ComponentInstance SupportsInstance_Impl::parent_ComponentInstance (void) const
  {
    return ::GAME::Mga::get_parent <ComponentInstance> (this->object_.p);
  }
}

