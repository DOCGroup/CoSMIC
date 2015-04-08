#include "StdAfx.h"
#include "ImplementationRequirement.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
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
  // is_abstract
  //
  const bool ImplementationRequirement_Impl::is_abstract = false;

  //
  // _create (const ImplementationContainer_in)
  //
  ImplementationRequirement ImplementationRequirement_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < ImplementationRequirement > (parent, ImplementationRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ImplementationRequirement (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer ImplementationRequirement_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // dst_of_MonolithDeployRequirement
  //
  size_t ImplementationRequirement_Impl::dst_of_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->in_connections <MonolithDeployRequirement> (items);
  }

  //
  // dst_of_MonolithDeployRequirement
  //
  GAME::Mga::Collection_T <MonolithDeployRequirement> ImplementationRequirement_Impl::dst_of_MonolithDeployRequirement (void) const
  {
    return this->in_connections <MonolithDeployRequirement> ("dst");
  }
}

