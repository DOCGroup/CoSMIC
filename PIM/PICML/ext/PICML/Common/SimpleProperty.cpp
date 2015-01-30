// $Id$

#include "StdAfx.h"
#include "SimpleProperty.h"

#if !defined (__GAME_INLINE__)
#include "SimpleProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/TypeKind.h"
#include "PICML/PredefinedTypes/TypeEncoding.h"
#include "PICML/PredefinedTypes/GenericValue.h"
#include "PICML/PredefinedTypes/GenericValueObject.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/Common/RequirementBase.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/Domain/Domain.h"
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
  // _create (const QueryInputAction_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const QueryInputAction_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const BehaviorInputAction_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const BehaviorInputAction_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const RequirementBase_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const RequirementBase_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ComponentAssembly_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ImplementationContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ComponentContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Paths_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const DeploymentPlan_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // _create (const Domain_in)
  //
  SimpleProperty SimpleProperty_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create < SimpleProperty > (parent, SimpleProperty_Impl::metaname);
  }

  //
  // accept
  //
  void SimpleProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SimpleProperty (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool SimpleProperty_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_MemberType
  //
  void SimpleProperty_Impl::refers_to_MemberType (MemberType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_MemberType
  //
  MemberType SimpleProperty_Impl::refers_to_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

