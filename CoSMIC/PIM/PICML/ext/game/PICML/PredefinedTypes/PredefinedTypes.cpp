// $Id$

#include "stdafx.h"
#include "PredefinedTypes.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedTypes_Impl::metaname = "PredefinedTypes";

  //
  // PredefinedTypes_Impl
  //
  PredefinedTypes_Impl::PredefinedTypes_Impl (void)
  {
  }

  //
  // PredefinedTypes_Impl
  //
  PredefinedTypes_Impl::PredefinedTypes_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PredefinedTypes_Impl
  //
  PredefinedTypes_Impl::~PredefinedTypes_Impl (void)
  {
  }

  //
  // accept
  //
  void PredefinedTypes_Impl::accept (Visitor * v)
  {
    v->visit_PredefinedTypes (this);
  }

  //
  // _create
  //
  PredefinedTypes PredefinedTypes_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PredefinedTypes> (parent, PredefinedTypes_Impl::metaname);
  }

  ::GAME::Mga::RootFolder PredefinedTypes_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

