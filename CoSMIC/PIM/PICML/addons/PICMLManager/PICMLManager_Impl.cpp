// $Id$

#include "StdAfx.h"
#include "PICMLManager_Impl.h"

#include "game/GAME.h"
#include "game/be/Event_Handler.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Dialogs.h"
#include "DefaultImplementationGenerator.h"
#include "DefaultArtifactGenerator.h"
#include "NewComponentConfig.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

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
#include "Event_Handler_Base.h"
#include "ExternalDelegate_Event_Handler.h"
#include "NodeReference_Event_Handler.h"
#include "PortInstance_Event_Handler.h"
#include "ToConnector_Event_Handler.h"
#include "UUID_Event_Handler.h"

#include <algorithm>
#include <sstream>
#include <functional>

// Type definition
typedef std::vector <GAME::Reference> Reference_Set;

static const long EVENTMASK =
   OBJEVENT_CREATED | OBJEVENT_ATTR |
   OBJEVENT_RELATION |  OBJEVENT_SELECT |
   OBJEVENT_SETINCLUDED | OBJEVENT_SETEXCLUDED |
   OBJEVENT_DESTROYED | OBJEVENT_LOSTCHILD;

//
// PICMLManager_Impl
//
PICMLManager_Impl::PICMLManager_Impl (void)
: GAME::Event_Handler_Impl (EVENTMASK),
  config_ (ACE_Singleton <PICML::MI::Event_Handler_Config,
                          ACE_Null_Mutex>::instance ())
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
int PICMLManager_Impl::initialize (GAME::Project & project)
{
  this->config_->project_ = project;

  // The new way of writing event handler's for the model intelligence
  // is to use event handler objects. We are going to preload the objects
  // into memory.

  // Handlers for AttributeMember
  this->event_handler_->register_handler ("AttributeMember",
    ACE_Singleton <PICML::MI::AttributeMember_Relation_Event_Handler,
                   ACE_Null_Mutex>::instance ());
  
  // Handlers for AtributeValue
  this->event_handler_->register_handler ("AttributeValue",
    ACE_Singleton <PICML::MI::AttributeValue_Create_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for CollocationGroup
  this->event_handler_->register_handler ("CollocationGroup",
    ACE_Singleton <PICML::MI::CollocationGroup_Relation_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComplexTypeReference
  this->event_handler_->register_handler ("ComplexTypeReference",
    ACE_Singleton <PICML::MI::ComplexTypeReference_Relation_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Component
  this->event_handler_->register_handler ("Component",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
 this->event_handler_->register_handler ("Component",
    ACE_Singleton <PICML::MI::Component_Create_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentAssembly
  this->event_handler_->register_handler ("ComponentAssembly",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ComponentFactoryInstance
  this->event_handler_->register_handler ("ComponentFactoryInstance",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ComponentInstace
  this->event_handler_->register_handler ("ComponentInstance",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  this->event_handler_->register_handler ("ComponentInstance",
    ACE_Singleton <PICML::MI::ComponentInstance_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentInstanceRef
  this->event_handler_->register_handler ("ComponentInstanceRef",
    ACE_Singleton <PICML::MI::ComponentInstanceRef_Set_Included_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentInstanceType
  this->event_handler_->register_handler ("ComponentInstanceType",
    ACE_Singleton <PICML::MI::ComponentInstanceType_Relation_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ComponentPackage
  this->event_handler_->register_handler ("ComponentPackage",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ConnectorImplementation
  this->event_handler_->register_handler ("ConnectorImplementation",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ConnectorInstance
  this->event_handler_->register_handler ("ConnectorInstance",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  this->event_handler_->register_handler ("ConnectorInstance",
    ACE_Singleton <PICML::MI::ConnectorInstance_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorObject
  this->event_handler_->register_handler ("ConnectorObject",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ConnectorToFacet
  this->event_handler_->register_handler ("ConnectorToFacet",
    ACE_Singleton <PICML::MI::FacetToConnector_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ConnectorToReceptacle
  this->event_handler_->register_handler ("ConnectorToReceptacle",
    ACE_Singleton <PICML::MI::ReceptacleToConnector_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Consume
  this->event_handler_->register_handler ("Consume",
    ACE_Singleton <PICML::MI::Consume_To_Connector_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for DeploymentPlan
  this->event_handler_->register_handler ("DeploymentPlan",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for Domain
  this->event_handler_->register_handler ("Domain",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for ExtendedPortInstance
  this->event_handler_->register_handler ("ExtendedPortInstance",
    ACE_Singleton <PICML::MI::ExtendedPortInstance_Destroyed_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ExternalDelegate
  this->event_handler_->register_handler ("ExternalDelegate",
    ACE_Singleton <PICML::MI::ExternalDelegate_Create_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for ImplementationArtifact
  this->event_handler_->register_handler ("ImplementationArtifact",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for MirrorPortInstance
  this->event_handler_->register_handler ("MirrorPortInstance",
    ACE_Singleton <PICML::MI::MirrorPortInstance_Destroyed_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for MonolithicImplementation
  this->event_handler_->register_handler ("MonolithicImplementation",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for NodeReference
  this->event_handler_->register_handler ("NodeReference",
    ACE_Singleton <PICML::MI::NodeReference_Create_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for Object
  this->event_handler_->register_handler ("Object",
    ACE_Singleton <PICML::MI::AMI4CCM_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  // Handlers for PackageConfiguration
  this->event_handler_->register_handler ("PackageConfiguration",
    ACE_Singleton <PICML::MI::UUID_Event_Handler,
                   ACE_Null_Mutex>::instance ());
                   
  // Handlers for Publish
  this->event_handler_->register_handler ("Publish",
    ACE_Singleton <PICML::MI::Publish_To_Connector_Event_Handler,
                   ACE_Null_Mutex>::instance ());

  return 0;
}


//
// handle_global_event
//
int PICMLManager_Impl::handle_global_event (long global_event)
{
  switch (global_event)
  {
  case APPEVENT_XML_IMPORT_BEGIN:
    this->is_importing_ = true;
    break;

  case GLOBALEVENT_OPEN_PROJECT:
    // this->verify_all_uuids ();
    break;

  case APPEVENT_XML_IMPORT_END:
    this->is_importing_ = false;
    // this->verify_all_uuids ();
    break;

  case GLOBALEVENT_NOTIFICATION_READY:
    //this->handle_pending ();
    break;

  default:
    /* do nothing */;
  }

  return S_OK;
}

//
// handle_object_event
//
int PICMLManager_Impl::
handle_object_event (GAME::Object & obj, unsigned long eventmask)
{
  try
  {
    GAME::Object object (obj);

    if (object.is_lib_object ())
      return 0;

    // Get the meta information for the object.
    std::string type = object.meta ().name ();
    _member_function handler;

    if (this->handlers_.find (type, handler) != -1)
      return 0;
  }
  catch (GAME::Exception &)
  {
    /* what should we really do right here??? */
  }
  catch (...)
  {
    /* what should we really do right here??? */
  }

  return S_OK;
}
