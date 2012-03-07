// $Id$

#include "StdAfx.h"
#include "MonolithDeployRequirement.h"

#if !defined (__GAME_INLINE__)
#include "MonolithDeployRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithDeployRequirement_Impl::metaname ("MonolithDeployRequirement");

  //
  // _create (const ImplementationContainer_in)
  //
  MonolithDeployRequirement MonolithDeployRequirement_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < MonolithDeployRequirement > (parent, MonolithDeployRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void MonolithDeployRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_MonolithDeployRequirement (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithDeployRequirement_Impl::src_MonolithicImplementationBase (void) const
  {
    return MonolithicImplementationBase::_narrow (this->src ());
  }

  //
  // ImplementationRequirement
  //
  ImplementationRequirement MonolithDeployRequirement_Impl::dst_ImplementationRequirement (void) const
  {
    return ImplementationRequirement::_narrow (this->dst ());
  }
}

