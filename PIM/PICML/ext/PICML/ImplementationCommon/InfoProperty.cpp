#include "StdAfx.h"
#include "InfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "InfoProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ImplementationCommon/Implemenation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InfoProperty_Impl::metaname ("InfoProperty");

  //
  // is_abstract
  //
  const bool InfoProperty_Impl::is_abstract = false;

  //
  // _create (const ImplementationContainer_in, Implemenation_in src, Property_in dst)
  //
  InfoProperty InfoProperty_Impl::_create (const ImplementationContainer_in parent, Implemenation_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, InfoProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void InfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InfoProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer InfoProperty_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // Implemenation
  //
  Implemenation InfoProperty_Impl::src_Implemenation (void) const
  {
    return Implemenation::_narrow (this->src ());
  }

  //
  // Property
  //
  Property InfoProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

