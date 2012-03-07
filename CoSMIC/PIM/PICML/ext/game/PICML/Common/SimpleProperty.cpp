// $Id$

#include "StdAfx.h"
#include "SimpleProperty.h"

#if !defined (__GAME_INLINE__)
#include "SimpleProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/Domain/Domain.h"
#include "PICML/Common/RequirementBase.h"
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
  const std::string SimpleProperty_Impl::metaname ("SimpleProperty");

  //
  // _create (const BehaviorInputAction_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const BehaviorInputAction_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const QueryInputAction_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const QueryInputAction_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ComponentContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ComponentAssembly_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Domain_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const RequirementBase_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const RequirementBase_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const DeploymentPlan_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Paths_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ImplementationContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // accept
  //
  void SimpleProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_SimpleProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // MemberType_is_nil
  //
  bool SimpleProperty_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType SimpleProperty_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

