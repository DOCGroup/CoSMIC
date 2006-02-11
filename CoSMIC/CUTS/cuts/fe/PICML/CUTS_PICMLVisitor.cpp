// $Id$

#include "StdAfx.h"
#include "cuts/fe/PICML/CUTS_PICMLVisitor.h"
#include "cuts/pir/Action_Property.h"
#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventManager.h"
#include "cuts/pir/Event.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/Event_Source.h"
#include "cuts/pir/Facet.h"
#include "cuts/pir/File.h"
#include "cuts/pir/Method.h"
#include "cuts/pir/Object.h"
#include "cuts/pir/Output_Action.h"
#include "cuts/pir/Periodic_Action.h"
#include "cuts/pir/Project.h"
#include "cuts/pir/Worker.h"
#include "cuts/pir/Worker_Action.h"
#include "cuts/pir/Worker_Type.h"

#include <functional>
#include <algorithm>
#include <strstream>

namespace PICML_BON
{
  struct Find_Element_By_Name_Ptr
  {
    Find_Element_By_Name_Ptr (const std::string & name)
      : name_ (name)
    {

    }

    bool operator () (const CUTS_PIR::Element * element)
    {
      return element->name () == this->name_;
    }

  private:
    std::string name_;
  };

  struct Find_Element_By_UUID_Ptr
  {
    Find_Element_By_UUID_Ptr (const std::string & uuid)
      : uuid_ (uuid)
    {

    }

    bool operator () (const CUTS_PIR::Element * element)
    {
      return element->uuid () == this->uuid_;
    }

  private:
    std::string uuid_;
  };

  //===========================================================================
  /**
   * @struct Position_Ordering_L2R_T2B
   */
  //===========================================================================

  template <typename ELEMENT_TYPE>
  struct Position_Ordering_L2R_T2B
  {
    bool operator () (const ELEMENT_TYPE & left,
                      const ELEMENT_TYPE & right)
    {
      BON::Point lp =
        BON::FCOExRegistryNode (left->getRegistry ())->getLocation ();

      BON::Point rp =
        BON::FCOExRegistryNode (left->getRegistry ())->getLocation ();

      return (lp.first < rp.first) && (lp.second > lp.second);
    }
  };

  //
  // Child_FCOs
  //
  typedef std::set<BON::FCO> Child_FCOs;

  //
  // CUTS_PICMLVisitor
  //
  CUTS_PICMLVisitor::CUTS_PICMLVisitor (void)
    : file_ (0),
      module_ (0),
      component_ (0)
  {

  }

  //
  // ~CUTS_PICMLVisitor
  //
  CUTS_PICMLVisitor::~CUTS_PICMLVisitor (void)
  {

  }

  //
  // visitFile
  //
  bool CUTS_PICMLVisitor::visitFile (const File & object)
  {
    if (!object)
      return false;

    // Create a new file and insert it into the <CUTS_PIR::Project>.
    this->file_ = new CUTS_PIR::File ();
    this->file_->name (object->getName ());
    this->file_->uuid (object->getID ());
    CUTS_PIR::Project::instance ()->files ().insert (this->file_);

    // Visit the contents of the module.
    this->module_ = this->file_;
    visitPackageContents (object);
    this->module_ = 0;

    return true;
  }

  //
  // visitPackage
  //
  bool CUTS_PICMLVisitor::visitPackage (const Package & object)
  {
    if (!object)
      return false;

    // Create a new <CUTS_PIR::Module> and insert it into the
    // current module.
    CUTS_PIR::Module * module = new CUTS_PIR::Module (this->module_);
    module->name (object->getName ());
    module->uuid (object->getID ());
    this->module_->modules ().insert (module);

    // Cache the current <module_> and switch to the new <module>.
    std::swap (module, this->module_);
    visitPackageContents (object);

    // Revert back to the previous <module>.
    std::swap (module, this->module_);
    return true;
  }

  //
  // visitComponent
  //
  bool CUTS_PICMLVisitor::visitComponent (const Component & object)
  {
    if (!object)
      return false;

    // Create a new <CUTS_PIR::Component> and insert it into the
    // current module.
    this->component_ = new CUTS_PIR::Component ();
    this->component_->name (object->getName ());
    this->component_->uuid (object->getID ());
    this->module_->components ().insert (this->component_);

    if (!resolveComponentHome (object))
    {
      // Determine if the component is referenced and has a component
      // home elsewhere.
      std::set <BON::Reference> component_refs = object->getReferredBy ();

      if (!component_refs.empty ())
      {
        resolveComponentHome ((*component_refs.begin ()));
      }
    }

    // Get the types of workers.
    std::set <WorkerType> worker_types =
      object->getWorkerType <std::less <WorkerType> > ();

    for ( std::set <WorkerType>::const_iterator iter =
          worker_types.begin ();
          iter != worker_types.end ();
          iter ++)
    {
      visitWorkerType (*iter);
    }

    // Get all the <OutEventPort> objects for this component.
    std::set <OutEventPort> out_event_ports =
      object->getOutEventPort <std::less <OutEventPort> > ();

    for ( std::set <OutEventPort>::const_iterator iter =
          out_event_ports.begin ();
          iter != out_event_ports.end ();
          iter ++)
    {
      visitOutEventPort (*iter);
    }

    // Get all the <InEventPort> objects for this component.
    std::set <InEventPort> in_event_ports =
      object->getInEventPort <std::less <InEventPort> > ();

    for ( std::set <InEventPort>::const_iterator iter =
          in_event_ports.begin ();
          iter != in_event_ports.end ();
          iter ++)
    {
      visitInEventPort (*iter);
    }

    // Get all the <ProvidedRequestPort> objects for this component.
    std::set <ProvidedRequestPort> request_ports =
      object->getProvidedRequestPort <std::less <ProvidedRequestPort> > ();

    for ( std::set <ProvidedRequestPort>::const_iterator iter =
          request_ports.begin ();
          iter != request_ports.end ();
          iter ++)
    {
      visitProvidedRequestPort (*iter);
    }

    // Get all the <ProvidedRequestPort> objects for this component.
    std::set <PeriodicAction> periodic_actions =
      object->getPeriodicAction <std::less <PeriodicAction> > ();

    for ( std::set <PeriodicAction>::const_iterator iter =
          periodic_actions.begin ();
          iter != periodic_actions.end ();
          iter ++)
    {
      visitPeriodicAction (*iter);
    }

    // Get all the <Environment> objects for this component.
    std::set <Environment> environment =
      object->getEnvironment <std::less <Environment> > ();

    for ( std::set <Environment>::const_iterator iter =
          environment.begin ();
          iter != environment.end ();
          iter ++)
    {
      visitEnvironment (*iter);
    }

    return true;
  }

  //
  // visitPackageContents
  //
  void CUTS_PICMLVisitor::visitPackageContents (const BON::Model & object)
  {
    // Visit all the <Event> models.
    Child_FCOs children = object->getChildFCOs ("Event");

    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      visitEvent (*iter);
    }

    // Visit all the <Object> models.
    children = object->getChildFCOs ("Object");

    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      visitObject (*iter);
    }

    // Visit all the <Component> models.
    children = object->getChildFCOs ("Component");

    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      visitComponent (*iter);
    }

    // Get all the <Package> models.
    children = object->getChildFCOs ("Package");

    // Visit the child FCOs.
    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      visitPackage (*iter);
    }
  }

  //
  // visitInterfaceDefinitions
  //
  bool CUTS_PICMLVisitor::visitInterfaceDefinitions (const InterfaceDefinitions &object)
  {
    if (!object)
      return false;

    // Get all the <Files> in this folder and visit them.
    Child_FCOs files = object->getRootFCOs ();

    for ( Child_FCOs::iterator iter = files.begin ();
          iter != files.end ();
          iter ++)
    {
      visitFile (*iter);
    }
    return true;
  }

  //
  // visitEvent
  //
  bool CUTS_PICMLVisitor::visitEvent (const Event & object)
  {
    if (!object)
      return false;

   // Create a new <event> since we have never seen this one.
   CUTS_PIR::Event  * event = new CUTS_PIR::Event (this->module_);
   event->name (object->getName ());
   event->uuid (object->getID ());

   // Insert the element into the referenced elements since it
   // can be referenced by event ports.
   this->ref_elements_.insert (
    Reference_Map::value_type (object->getID (), event));

    // Insert the event to the <Event_Manager> for the project.
    CUTS_PIR::Project::instance ()->event_manager ().insert (
      CUTS_PIR::Event_Manager::value_type (object->getID (), event));

    // Set the <has_events> flag to true.
    this->file_->has_events (true);
    return true;
  }

  //
  // visitObject
  //
  bool CUTS_PICMLVisitor::visitObject (const Object & obj)
  {
    if (!obj)
      return false;

    // Create a new object and initialize it properly.
    CUTS_PIR::Object * object = new CUTS_PIR::Object (this->module_);
    object->name (obj->getName ());
    object->uuid (obj->getID ());
    this->module_->objects ().insert (object);

    // Insert the object into the reference map since it can be
    // referenced by facets and receptacles.
    this->ref_elements_.insert (
      Reference_Map::value_type (obj->getID (), object));
    return true;
  }

  //
  // visitInEventPort
  //
  bool CUTS_PICMLVisitor::visitInEventPort (const InEventPort & object)
  {
    if (!object)
      return false;

    // Create a <Event_Sink> for the <InEventPort> and insert
    // it into the current component.
    CUTS_PIR::Event_Sink * event_sink = new CUTS_PIR::Event_Sink ();
    event_sink->name (object->getName ());
    event_sink->uuid (object->getID ());

    this->component_->event_sinks ().insert (event_sink);
    this->method_ = event_sink;

    // Resolve the reference for the event sink.
    Event event = object->getEvent ();
    resolveReference (object->getEvent ()->getID (), event_sink);

    // Get the <InputAction> associated w/ this input port.
    std::multiset <InputAction> inputs =
      object->getInputDsts <std::less <InputAction> > ();

    for ( std::multiset <InputAction>::iterator iter = inputs.begin ();
          iter != inputs.end ();
          iter ++)
    {
      visitInputAction (*iter);
    }

    return true;
  }

  //
  // visitProject
  //
  void CUTS_PICMLVisitor::visitProject (const BON::Project & project)
  {
    // Get the root folder for the project.
    BON::Folder root = project->getRootFolder ();

    // Visit all the child folders of the root folder.
    typedef std::set <BON::Folder> Folder_Set;
    Folder_Set folders = root->getChildFolders ();

    for ( Folder_Set::iterator iter = folders.begin ();
          iter != folders.end ();
          iter ++)
    {
      visitInterfaceDefinitions (*iter);
    }

    // Resolve all the unresolved references.
    for ( Unresolved_References::iterator iter =
            this->unresolved_references_.begin ();
          iter != this->unresolved_references_.end ();
          iter ++)
    {
      // Locate the unresolved reference.
      CUTS_PICMLVisitor::Reference_Map::const_iterator ref
        = this->ref_elements_.find (iter->first);

      if (ref != this->ref_elements_.end ())
      {
        iter->second->reference (ref->second);
      }
    }
  }

  //
  // resolveComponentHome
  //
  bool CUTS_PICMLVisitor::resolveComponentHome (const BON::FCO & object)
  {
    // Get the in connection links.
    std::set <BON::Connection> manages = object->getInConnLinks ();

    if (manages.empty ())
      return false;

    // Get the factory associated with the link.
    std::set <BON::Connection>::const_iterator conn_iter = manages.begin ();
    ComponentFactory factory = (*conn_iter)->getSrc ();

    if (!factory)
      return false;

    // Create a new <Component_Home>.
    CUTS_PIR::Component_Home * home =
      new CUTS_PIR::Component_Home (this->module_);

    home->name (factory->getName ());
    home->uuid (factory->getID ());

    // Assign the <home> to the <component_>.
    this->component_->home (home);
    return true;
  }

  //
  // visitFacet
  //
  bool CUTS_PICMLVisitor::visitProvidedRequestPort (
    const ProvidedRequestPort & object)
  {
    if (!object)
      return false;

    if (object->getName () != "cuts_benchmark_agent")
    {
        // Create a new <facet> and appropriately initialize it.
      CUTS_PIR::Facet * facet = new CUTS_PIR::Facet ();
      this->component_->facets ().insert (facet);
      facet->name (object->getName ());
      facet->uuid (object->getID ());

      PICML_BON::Object facet_type = object->getReferred ();

      if (facet_type)
      {
        // Locate the facet in reference map.
        Reference_Map::iterator iter =
          this->ref_elements_.find (facet_type->getID ());

        if (iter != this->ref_elements_.end ())
        {
          // Resolve the reference.
          facet->reference (iter->second);
        }
        else
        {
          // Insert the <facet> as an inresolved reference.
          this->unresolved_references_.insert (
            Unresolved_References::value_type (facet_type->getID (), facet));
        }
      }
      else
      {
        // the type is undefined!!!!
      }
    }

    return true;
  }

  //
  // visitWorkerType
  //
  bool CUTS_PICMLVisitor::visitWorkerType (const WorkerType & object)
  {
    if (!object)
      return false;

    // Visit the reference worker.
    Worker worker = object->getWorker ();
    visitWorker (worker);

    // Locate the worker in the manager.
    CUTS_PIR::Worker_Manager::iterator result =
      CUTS_PIR::Project::instance ()->worker_manager ().find (worker->getID ());

    if (result != CUTS_PIR::Project::instance ()->worker_manager ().end ())
    {
      // Get the reference worker.
      CUTS_PIR::Worker_Type * worker_type = new CUTS_PIR::Worker_Type ();
      worker_type->name (object->getName ());
      worker_type->uuid (object->getID ());

      // Save the worker type for the worker.
      worker_type->reference (result->second);

      // Insert the worker into the component.
      this->component_->worker_types ().insert (worker_type);
    }

    return true;
  }

  //
  // visitWorker
  //
  bool CUTS_PICMLVisitor::visitWorker (const Worker & object)
  {
    if (!object)
      return false;

    // Try and located the worker into the <worker_manager>.
    CUTS_PIR::Worker_Manager::iterator result =
      CUTS_PIR::Project::instance ()->worker_manager ().find (
      object->getID ());

    if (result == CUTS_PIR::Project::instance ()->worker_manager ().end ())
    {
      // Create a new worker and insert it into the
      CUTS_PIR::Worker * worker = new CUTS_PIR::Worker ();
      worker->name (object->getName ());
      worker->uuid (object->getID ());

      CUTS_PIR::Project::instance ()->worker_manager ().insert (
        CUTS_PIR::Worker_Manager::value_type (object->getID (), worker));
    }

    // Insert the worker into the current files includes.
    BON::Model model;

    do {
      model = object->getParent ();
    } while (model->getObjectMeta ().name () != "WorkerFile");

    this->file_->includes ().insert (model->getName () + ".h");

    return true;
  }

  //
  // visitInputAction
  //
  bool CUTS_PICMLVisitor::visitInputAction (const InputAction & input)
  {
    if (!input)
      return false;

    // Get the <State> which this action transitions.
    std::multiset <State> states =
      input->getEffectDsts <std::less <State> > ();

    // Visit the state.
    visitState (*states.begin ());
    return true;
  }

  //
  // visitState
  //
  bool CUTS_PICMLVisitor::visitState (const State & object)
  {
    if (!object)
      return false;

    // Determine if this is the end of the sequeunce.
    std::multiset <InputAction> inputs =
      object->getFinishDsts <std::less <InputAction> > ();

    for ( std::multiset <InputAction>::iterator iter = inputs.begin ();
          iter != inputs.end ();
          iter ++)
    {
      if ((*iter)->getID () == this->input_action_id_)
        return true;
    }

    // Get the <State> which this action transitions.
    std::multiset <ActionBase> actions =
      object->getTransitionDsts <std::less <ActionBase> > ();

    for ( std::multiset <ActionBase>::iterator iter = actions.begin ();
          iter != actions.end ();
          iter ++)
    {
      if (!visitWorkerAction (*iter))
      {
        visitOutputAction (*iter);
      }
    }
    return true;
  }

  //
  // visitWorkerAction
  //
  bool CUTS_PICMLVisitor::visitWorkerAction (const WorkerAction & object)
  {
    if (!object)
      return false;

    // Verify the type is an instance.
    BON::TypeInhObject type_inheritance
      = BON::TypeInhObject (object->getTypeInhObject ());

    if (!type_inheritance->isInstance ())
      return true;

    // Get the type of the instance.
    BON::FCO type = type_inheritance->getType ()->getFCO ();

    CUTS_PIR::Component::Worker_Types::iterator result =
      std::find_if (
        this->component_->worker_types ().begin (),
        this->component_->worker_types ().end (),
        Find_Element_By_Name_Ptr (object->getName ()));

    if (result != this->component_->worker_types ().end ())
    {
      // Create a new worker action.
      CUTS_PIR::Worker_Action * action
        = new CUTS_PIR::Worker_Action (*result);

      action->name (type->getName ());
      action->uuid (object->getID ());
      action->repetitions (object->getRepetitions ());
      action->log_action (object->isLogAction ());

      if (this->method_)
      {
        // Get all the properties associate with this action.
        typedef std::set <
          Property, Position_Ordering_L2R_T2B <Property> > Property_Set;

        Property_Set properties =
          object->getProperty <Position_Ordering_L2R_T2B <Property> > ();

        // Create a new <property>.
        CUTS_PIR::Action_Property * property =
          new CUTS_PIR::Action_Property ();

        for ( Property_Set::iterator iter = properties.begin ();
              iter != properties.end ();
              iter ++)
        {
          property->name ((*iter)->getName ());
          property->value ((*iter)->getDataValue ());

          // Insert the property into the action.
          action->properties ().push (property);
        }

        // Insert the <action> into the <method_>.
        this->method_->actions ().push (action);

        // Get the <State> which this action transitions.
        std::multiset <State> states =
          object->getEffectDsts <std::less <State> > ();

        // Visit the state.
        visitState (*states.begin ());
      }
    }
    return true;
  }

  //
  // visitOutEventPort
  //
  bool CUTS_PICMLVisitor::visitOutEventPort (const OutEventPort & object)
  {
    if (!object)
      return false;

    // Create a <Event_Sink> for the <InEventPort> and insert
    // it into the current component.
    CUTS_PIR::Event_Source * event_source = new CUTS_PIR::Event_Source ();
    event_source->name (object->getName ());
    event_source->uuid (object->getID ());

    this->component_->event_sources ().insert (event_source);

    // Set the reference ID for the <event_sink>.
    resolveReference (object->getEvent ()->getID (), event_source);
    return true;
  }

  //
  // visitOutputAction
  //
  bool CUTS_PICMLVisitor::visitOutputAction (const OutputAction & object)
  {
    if (!object)
      return false;

    CUTS_PIR::Component::Event_Sources::iterator iter =
      std::find_if (this->component_->event_sources ().begin (),
                    this->component_->event_sources ().end (),
                    Find_Element_By_Name_Ptr (object->getName ()));

    if (iter == this->component_->event_sources ().end ())
      return true;

    // Create a new output action.
    CUTS_PIR::Output_Action * action = new CUTS_PIR::Output_Action ();
    action->uuid (object->getID ());
    action->name (object->getName ());
    action->event_source (*iter);

    // Get the properties for the action.
    typedef std::set <
      Property, Position_Ordering_L2R_T2B <Property> > Property_Set;

    Property_Set properties =
      object->getProperty <Position_Ordering_L2R_T2B <Property> > ();

    for ( Property_Set::iterator iter = properties.begin ();
          iter != properties.end ();
          iter ++)
    {
      // We are only concerned w/ the size property.
      if ((*iter)->getName () == "size")
      {
        // Get the size of the event.
        std::string string_data = (*iter)->getDataValue ();

        // Convert string to an integer.
        std::strstream temp;
        temp << string_data << std::ends;

        size_t size;
        temp >> size;

        // Store the size of the event.
        action->size (size);
      }
    }

    // Insert the <action> into the current method.
    this->method_->actions ().push (action);

    // Get the <State> which this action transitions.
    std::multiset <State> states =
      object->getEffectDsts <std::less <State> > ();

    // Visit the state.
    visitState (*states.begin ());
    return true;
  }

  //
  // visitProperty
  //
  bool CUTS_PICMLVisitor::visitProperty (const Property & object)
  {
    if (!object)
      return false;

    return true;
  }

  //
  // resolveReference
  //
  void CUTS_PICMLVisitor::resolveReference (
    const std::string & uuid,
    CUTS_PIR::Reference_Element * element)
  {
    // Locate the <reference> in the <ref_elements_>.
    Reference_Map::iterator iter =
      this->ref_elements_.find (uuid);

    if (iter == this->ref_elements_.end ())
    {
      this->unresolved_references_.insert (
        Unresolved_References::value_type (uuid, element));
    }
    else
    {
      element->reference (iter->second);
    }
  }

  //
  // visitPeriodicAction
  //
  bool CUTS_PICMLVisitor::visitPeriodicAction (
    const PeriodicAction & object)
  {
    if (!object)
      return false;

    // Create a new periodic action.
    CUTS_PIR::Periodic_Action * periodic_action =
      new CUTS_PIR::Periodic_Action ();
    periodic_action->name (object->getName ());
    periodic_action->uuid (object->getID ());
    periodic_action->period (object->getPeriod ());
    periodic_action->probability (object->getProbability ());


    // Insert the action into the component.
    this->component_->periodic_actions ().insert (periodic_action);
    this->method_ = periodic_action;

    // Visit the string of connected actions.
    visitInputAction (object);
    return true;
  }

  //
  // visitEnvironment
  //
  bool CUTS_PICMLVisitor::visitEnvironment (const Environment & object)
  {
    if (!object)
      return false;

    // Get the <InputAction> associated w/ this input port.
    std::multiset <InputAction> inputs =
      object->getInputDsts <std::less <InputAction> > ();

    for ( std::multiset <InputAction>::iterator iter = inputs.begin ();
          iter != inputs.end ();
          iter ++)
    {
      if ((*iter)->getName () == "activate")
      {
        // Create the method and set as the <activate_method> for the
        // current component.
        CUTS_PIR::Method * method = new CUTS_PIR::Method;
        method->name ((*iter)->getName ());
        this->component_->activate_method (method);

        // Save the method as the current method.
        this->method_ = method;

        // Visit the input action to finish creating the method.
        visitInputAction (*iter);
        break;
      }
    }

    return true;
  }
}
