// $Id$

#include "StdAfx.h"
#include "SatisfierProperty.h"

#if !defined (__GAME_INLINE__)
#include "SatisfierProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataType.h"
#include "PICML/Common/RequirementSatisfier.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/TargetElements/SharedResource.h"
#include "PICML/Common/Capability.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SatisfierProperty_Impl::metaname ("SatisfierProperty");

  //
  // _create (const RequirementSatisfier_in)
  //
  SatisfierProperty SatisfierProperty_Impl::_create (const RequirementSatisfier_in parent)
  {
    return ::GAME::Mga::create_object < SatisfierProperty > (parent, SatisfierProperty_Impl::metaname);
  }

  //
  // accept
  //
  void SatisfierProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SatisfierProperty (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_RequirementSatisfier
  //
  RequirementSatisfier SatisfierProperty_Impl::parent_RequirementSatisfier (void)
  {
    return RequirementSatisfier::_narrow (this->parent ());
  }

  //
  // has_DataType
  //
  bool SatisfierProperty_Impl::has_DataType (void) const
  {
    return this->children <DataType> ().count () == 1;
  }

  //
  // get_DataType
  //
  DataType SatisfierProperty_Impl::get_DataType (void) const
  {
    return this->children <DataType> ().first ();
  }
}

