// $Id$

#include "StdAfx.h"
#include "SatisfierProperty.h"

#if !defined (__GAME_INLINE__)
#include "SatisfierProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/RequirementSatisfier.h"
#include "PICML/Common/DataType.h"
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
  // get_DataType
  //
  DataType SatisfierProperty_Impl::get_DataType (void) const
  {
    return this->children <DataType> ().item ();
  }
}

