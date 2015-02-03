// $Id$

#include "StdAfx.h"
#include "MonolithExecParameter.h"

#if !defined (__GAME_INLINE__)
#include "MonolithExecParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithExecParameter_Impl::metaname ("MonolithExecParameter");

  //
  // is_abstract
  //
  const bool MonolithExecParameter_Impl::is_abstract (0);

  //
  // _create (const ImplementationContainer_in, MonolithicImplementationBase_in src, Property_in dst)
  //
  MonolithExecParameter MonolithExecParameter_Impl::_create (const ImplementationContainer_in parent, MonolithicImplementationBase_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, MonolithExecParameter_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void MonolithExecParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MonolithExecParameter (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithExecParameter_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithExecParameter_Impl::src_MonolithicImplementationBase (void) const
  {
    return MonolithicImplementationBase::_narrow (this->src ());
  }

  //
  // Property
  //
  Property MonolithExecParameter_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

