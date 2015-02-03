// $Id$

#include "StdAfx.h"
#include "RequirementSatisfier.h"

#if !defined (__GAME_INLINE__)
#include "RequirementSatisfier.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/SatisfierProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequirementSatisfier_Impl::metaname ("RequirementSatisfier");

  //
  // is_abstract
  //
  const bool RequirementSatisfier_Impl::is_abstract (1);

  //
  // get_SatisfierPropertys
  //
  size_t RequirementSatisfier_Impl::get_SatisfierPropertys (std::vector <SatisfierProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SatisfierPropertys
  //
  ::GAME::Mga::Collection_T <SatisfierProperty> RequirementSatisfier_Impl::get_SatisfierPropertys (void) const
  {
    return this->children <SatisfierProperty> ();
  }
}

