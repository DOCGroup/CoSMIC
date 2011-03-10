// $Id$

#include "stdafx.h"
#include "SatisfierProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/DataType.h"
#include "PICML/Common/RequirementSatisfier.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SatisfierProperty_Impl::metaname = "SatisfierProperty";

  //
  // SatisfierProperty_Impl
  //
  SatisfierProperty_Impl::SatisfierProperty_Impl (void)
  {
  }

  //
  // SatisfierProperty_Impl
  //
  SatisfierProperty_Impl::SatisfierProperty_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SatisfierProperty_Impl
  //
  SatisfierProperty_Impl::~SatisfierProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void SatisfierProperty_Impl::accept (Visitor * v)
  {
    v->visit_SatisfierProperty (this);
  }

  //
  // _create
  //
  SatisfierProperty SatisfierProperty_Impl::_create (const RequirementSatisfier_in parent)
  {
    return ::GAME::Mga::create_object <SatisfierProperty> (parent, SatisfierProperty_Impl::metaname);
  }

  //
  // get_DataType
  //
  DataType SatisfierProperty_Impl::get_DataType (void) const
  {
    // Get the collection of children.
    std::vector <DataType> items;
    this->children (items);

    return !items.empty () ? items.front () : DataType ();
  }

  //
  // parent_RequirementSatisfier
  //
  RequirementSatisfier SatisfierProperty_Impl::parent_RequirementSatisfier (void) const
  {
    return ::GAME::Mga::get_parent <RequirementSatisfier> (this->object_.p);
  }
}

