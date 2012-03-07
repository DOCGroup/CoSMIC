// $Id$

#include "StdAfx.h"
#include "ComplexProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComplexProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/Domain/Domain.h"
#include "PICML/Common/RequirementBase.h"
#include "PICML/Common/ComplexTypeReference.h"
#include "PICML/Common/DataValueBase.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComplexProperty_Impl::metaname ("ComplexProperty");

  //
  // _create (const BehaviorInputAction_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const BehaviorInputAction_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const QueryInputAction_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const QueryInputAction_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const ComponentContainer_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const ComponentAssembly_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const Domain_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const RequirementBase_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const RequirementBase_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const DeploymentPlan_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const Paths_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // _create (const ImplementationContainer_in)
  //
  ComplexProperty ComplexProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexProperty > (parent, ComplexProperty_Impl::metaname);
  }

  //
  // accept
  //
  void ComplexProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComplexProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // has_ComplexTypeReference
  //
  bool ComplexProperty_Impl::has_ComplexTypeReference (void) const
  {
    return this->children <ComplexTypeReference> ().count () == 1;
  }

  //
  // get_ComplexTypeReference
  //
  ComplexTypeReference ComplexProperty_Impl::get_ComplexTypeReference (void) const
  {
    return this->children <ComplexTypeReference> ().item ();
  }

  //
  // get_DataValueBases
  //
  size_t ComplexProperty_Impl::get_DataValueBases (std::vector <DataValueBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataValueBases
  //
  ::GAME::Mga::Iterator <DataValueBase> ComplexProperty_Impl::get_DataValueBases (void) const
  {
    return this->children <DataValueBase> ();
  }
}

