// $Id$

#include "StdAfx.h"
#include "PICMLManager_Impl.h"

#include "game/mga/be/Event_Handler.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

// event handler(s)
#include "AMI4CCM_Event_Handler.h"
#include "AttributeMember_Event_Handler.h"
#include "AttributeValue_Event_Handler.h"
#include "CollocationGroup_Event_Handler.h"
#include "ComplexTypeReference_Event_Handler.h"
#include "Component_Event_Handler.h"
#include "ComponentInstance_Event_Handler.h"
#include "ComponentInstanceRef_Event_Handler.h"
#include "ComponentInstanceType_Event_Handler.h"
#include "ConnectorInstance_Event_Handler.h"
#include "Default_Implementation_Event_Handler.h"
#include "Event_Handler_Base.h"
#include "NodeReference_Event_Handler.h"
#include "Package_Type_Handler.h"
#include "ToConnector_Event_Handler.h"
#include "Template_Module_Instance_Handler.h"
#include "UUID_Event_Handler.h"

#include <algorithm>
#include <sstream>
#include <functional>

// Type definition
typedef std::vector <GAME::Mga::Reference> Reference_Set;

static const unsigned long EVENTMASK =
   OBJEVENT_CREATED | OBJEVENT_ATTR |
   OBJEVENT_RELATION |  OBJEVENT_SELECT |
   OBJEVENT_SETINCLUDED | OBJEVENT_SETEXCLUDED |
   OBJEVENT_DESTROYED | OBJEVENT_LOSTCHILD |
   OBJEVENT_REGISTRY;

#define DLL_NAME "PICML_Model_Intelligence"

/**
 * Adapter for the ACE_DLL_Singleton_T object. This allows singletons
 * defined in this module to operate correctly with the ACE framework.
 */
template <typename T>
class Singleton_DLL_Adapter : public T
{
public:
  const ACE_TCHAR * name (void) const
  {
    return DLL_NAME;
  }

  const ACE_TCHAR * dll_name (void) const
  {
    return DLL_NAME;
  }
};

//
// PICMLManager_Impl
//
PICMLManager_Impl::PICMLManager_Impl (void)
: GAME::Mga::Event_Handler_Impl (0xFFFFFFFF, false)
{

}

//
// ~PICMLManager_Impl
//
PICMLManager_Impl::~PICMLManager_Impl (void)
{
  ACE_Framework_Repository::instance ()->remove_dll_components (DLL_NAME);
}

//
// Initaialize
//
int PICMLManager_Impl::initialize (GAME::Mga::Project project)
{
  // The new way of writing event handler's for the model intelligence
  // is to use event handler objects. We are going to preload the objects
  // into memory.

  // Handlers for AttributeMember
  this->event_handler_->register_handler ("AttributeMember",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::AttributeMember_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for AtributeValue
  this->event_handler_->register_handler ("AttributeValue",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::AttributeValue_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for CollocationGroup
  this->event_handler_->register_handler ("CollocationGroup",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::CollocationGroup_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComplexTypeReference
  this->event_handler_->register_handler ("ComplexTypeReference",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ComplexTypeReference_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Component
  this->event_handler_->register_handler ("Component",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("Component",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Default_Implementation_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  PICML::MI::
    Default_Implementation_Generator::meta_info_t
    component_meta = {"ComponentImplementations",
                      "ComponentImplementations",
                      "ImplementationArtifacts",
                      "ComponentImplementationContainer",
                      "MonolithicImplementation",
                      "ComponentRef",
                      "Implements"};

  ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Default_Implementation_Event_Handler>,
                 ACE_Null_Mutex>::instance ()->insert ("Component",
                                                       component_meta);

  // Handlers for ComponentAssembly
  this->event_handler_->register_handler ("ComponentAssembly",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentFactoryInstance
  this->event_handler_->register_handler ("ComponentFactoryInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentInstace
  this->event_handler_->register_handler ("ComponentInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ComponentInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ComponentInstance_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentInstanceRef
  this->event_handler_->register_handler ("ComponentInstanceRef",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ComponentInstanceRef_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentInstanceType
  this->event_handler_->register_handler ("ComponentInstanceType",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ComponentInstanceType_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentPackage
  this->event_handler_->register_handler ("ComponentPackage",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorImplementation
  this->event_handler_->register_handler ("ConnectorImplementation",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorInstance
  this->event_handler_->register_handler ("ConnectorInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ConnectorInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ConnectorInstance_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorObject
  this->event_handler_->register_handler ("ConnectorObject",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ConnectorObject",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Default_Implementation_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  PICML::MI::
    Default_Implementation_Generator::meta_info_t
    connector_meta = {"ConnectorImplementations",
                      "ConnectorImplementations",
                      "ImplementationArtifacts",
                      "ConnectorImplementationContainer",
                      "ConnectorImplementation",
                      "ConnectorType",
                      "ConnectorImplements"};

  ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Default_Implementation_Event_Handler>,
                   ACE_Null_Mutex>::instance ()->insert ("ConnectorObject",
                                                         connector_meta);

  // Handlers for ConnectorToFacet
  this->event_handler_->register_handler ("ConnectorToFacet",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::FacetToConnector_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorToReceptacle
  this->event_handler_->register_handler ("ConnectorToReceptacle",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::ReceptacleToConnector_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Consume
  this->event_handler_->register_handler ("Consume",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Consume_To_Connector_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for DeploymentPlan
  this->event_handler_->register_handler ("DeploymentPlan",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Domain
  this->event_handler_->register_handler ("Domain",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ImplementationArtifact
  this->event_handler_->register_handler ("ImplementationArtifact",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for MonolithicImplementation
  this->event_handler_->register_handler ("MonolithicImplementation",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for NodeReference
  this->event_handler_->register_handler ("NodeReference",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::NodeReference_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Object
  this->event_handler_->register_handler ("Object",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::AMI4CCM_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for PackageType
  this->event_handler_->register_handler ("PackageType",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Package_Type_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for PackageConfiguration
  this->event_handler_->register_handler ("PackageConfiguration",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::UUID_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Publish
  this->event_handler_->register_handler ("Publish",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Publish_To_Connector_Event_Handler>,
                   ACE_Null_Mutex>::instance ());

  // Handlers for TemplatePackageInstance
  this->event_handler_->register_handler ("TemplatePackageInstance",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <PICML::MI::Template_Module_Instance_Handler>,
                             ACE_Null_Mutex>::instance ());

  return 0;
}
