// $Id$

#include "StdAfx.h"
#include "PICMLManager_Impl.h"

#include "game/mga/component/Event_Sink.h"

// event handler(s)
#include "AMI4CCM_Event_Handler.h"
#include "AttributeMember_Event_Handler.h"
#include "AttributeValue_Event_Handler.h"
#include "ComplexTypeReference_Event_Handler.h"
#include "ComponentInstance_Creator_Event_Handler.h"
#include "ComponentInstanceType_Event_Handler.h"
#include "ConnectorInstance_Event_Handler.h"
#include "Default_Implementation_Event_Handler.h"
#include "Event_Handler_Base.h"
#include "PredefinedTypes_Handler.h"
#include "NodeReference_Event_Handler.h"
#include "Package_Type_Handler.h"
#include "ToConnector_Event_Handler.h"
#include "Template_Module_Instance_Handler.h"
#include "Single_Deployment_Event_Handler.h"

//
// PICMLManager_Impl
//
PICMLManager_Impl::PICMLManager_Impl (void)
: GAME::Mga::Top_Level_Event_Handler (0xFFFFFFFF)
{

}

//
// ~PICMLManager_Impl
//
PICMLManager_Impl::~PICMLManager_Impl (void)
{

}

//
// Initaialize
//
int PICMLManager_Impl::initialize (GAME::Mga::Project project)
{
  // The new way of writing event handler's for the model intelligence
  // is to use event handler objects. We are going to preload the objects
  // into memory.
  PICML::MI::Default_Implementation_Event_Handler * default_impl =
    new PICML::MI::Default_Implementation_Event_Handler ();

  // Handlers for AttributeMember
  this->sink_->register_handler ("AttributeMember", new PICML::MI::AttributeMember_Event_Handler ());

  // Handlers for AtributeValue
  this->sink_->register_handler ("AttributeValue", new PICML::MI::AttributeValue_Event_Handler ());

  // Handlers for ComplexTypeReference
  this->sink_->register_handler ("ComplexTypeReference", new PICML::MI::ComplexTypeReference_Event_Handler ());

  // Handlers for Component
  this->sink_->register_handler ("Component", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  PICML::MI::
    Default_Implementation_Generator::meta_info_t
    component_meta = {"ComponentImplementations",
                      "ComponentImplementations",
                      "ImplementationArtifacts",
                      "ComponentImplementationContainer",
                      "MonolithicImplementation",
                      "ComponentRef",
                      "Implements"};

  default_impl->insert ("Component", component_meta);
  this->sink_->register_handler ("Component", default_impl);

  this->sink_->register_handler (PICML::InEventPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::OutEventPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::RequiredRequestPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::ProvidedRequestPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::ExtendedPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::MirrorPort_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::Attribute_Impl::metaname, &this->component_obs_);
  this->sink_->register_handler (PICML::ReadonlyAttribute_Impl::metaname, &this->component_obs_);

  // Handlers for ComponentAssembly
  this->sink_->register_handler ("ComponentAssembly", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for ComponentFactoryInstance
  this->sink_->register_handler ("ComponentFactoryInstance", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for ComponentInstace
  this->sink_->register_handler ("ComponentInstance", new PICML::MI::UUID_Event_Handler (this->all_uuids_));
  this->sink_->register_handler ("ComponentInstance", new PICML::MI::ComponentInstance_Creator_Event_Handler (&this->component_obs_));

  // Handlers for ComponentInstanceRef
  GAME::Mga::Object_Event_Handler * sdeh = new PICML::MI::Single_Deployment_Event_Handler ();
  this->sink_->register_handler ("CollocationGroup", sdeh);
  this->sink_->register_handler ("ComponentInstanceRef", sdeh);
  this->sink_->register_handler ("ComponentAssemblyReference", sdeh);

  // Handlers for ComponentInstanceType
  this->sink_->register_handler ("ComponentInstanceType", new PICML::MI::ComponentInstanceType_Event_Handler ());

  // Handlers for ComponentPackage
  this->sink_->register_handler ("ComponentPackage", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for ConnectorImplementation
  this->sink_->register_handler ("ConnectorImplementation", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for ConnectorInstance
  this->sink_->register_handler ("ConnectorInstance", new PICML::MI::UUID_Event_Handler (this->all_uuids_));
  this->sink_->register_handler ("ConnectorInstance", new PICML::MI::ConnectorInstance_Event_Handler ());

  // Handlers for ConnectorObject
  this->sink_->register_handler ("ConnectorObject", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  PICML::MI::
    Default_Implementation_Generator::meta_info_t
    connector_meta = {"ConnectorImplementations",
                      "ConnectorImplementations",
                      "ImplementationArtifacts",
                      "ConnectorImplementationContainer",
                      "ConnectorImplementation",
                      "ConnectorType",
                      "ConnectorImplements"};

  default_impl->insert ("ConnectorObject", connector_meta);
  this->sink_->register_handler ("ConnectorObject", default_impl);

  // Handlers for ConnectorToFacet
  this->sink_->register_handler ("ConnectorToFacet", new PICML::MI::FacetToConnector_Event_Handler ());

  // Handlers for ConnectorToReceptacle
  this->sink_->register_handler ("ConnectorToReceptacle", new PICML::MI::ReceptacleToConnector_Event_Handler ());

  // Handlers for Consume
  this->sink_->register_handler ("Consume", new PICML::MI::Consume_To_Connector_Event_Handler ());

  // Handlers for DeploymentPlan
  this->sink_->register_handler ("DeploymentPlan", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for Domain
  this->sink_->register_handler ("Domain", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for ImplementationArtifact
  this->sink_->register_handler ("ImplementationArtifact", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for MonolithicImplementation
  this->sink_->register_handler ("MonolithicImplementation", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for NodeReference
  this->sink_->register_handler ("NodeReference", new PICML::MI::NodeReference_Event_Handler ());

  // Handlers for Object
  this->sink_->register_handler ("Object", new PICML::MI::AMI4CCM_Event_Handler ());

  // Handlers for PackageType
  this->sink_->register_handler ("PackageType", new PICML::MI::Package_Type_Handler ());

  // Handlers for PackageConfiguration
  this->sink_->register_handler ("PackageConfiguration", new PICML::MI::UUID_Event_Handler (this->all_uuids_));

  // Handlers for Publish
  this->sink_->register_handler ("Publish", new PICML::MI::Publish_To_Connector_Event_Handler ());

  // Handlers for TemplatePackageInstance
  this->sink_->register_handler ("TemplatePackageInstance", new PICML::MI::Template_Module_Instance_Handler ());

  // Handlers for TemplatePackageInstance
  this->sink_->register_handler ("PredefinedTypes", new PICML::MI::PredefinedTypes_Handler ());

  return 0;
}
