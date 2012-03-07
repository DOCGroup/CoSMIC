// $Id$

#include "StdAfx.h"
#include "ImplementationRequirement.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/RequirementBase.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationRequirement_Impl::metaname ("ImplementationRequirement");

  //
  // _create (const ImplementationContainer_in)
  //
  ImplementationRequirement ImplementationRequirement_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationRequirement > (parent, ImplementationRequirement_Impl::metaname);
  }

  //
  // _create (const RequirementBase_in)
  //
  ImplementationRequirement ImplementationRequirement_Impl::_create (const RequirementBase_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationRequirement > (parent, ImplementationRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ImplementationRequirement (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // dst_MonolithDeployRequirement
  //
  size_t ImplementationRequirement_Impl::dst_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->in_connections <MonolithDeployRequirement> (items);
  }
}

