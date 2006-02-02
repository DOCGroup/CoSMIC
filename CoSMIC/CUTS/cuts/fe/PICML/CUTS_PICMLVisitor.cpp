// $Id$

#include "StdAfx.h"
#include "cuts/fe/PICML/CUTS_PICMLVisitor.h"
#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventManager.h"
#include "cuts/pir/Event.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/Facet.h"
#include "cuts/pir/File.h"
#include "cuts/pir/Object.h"
#include "cuts/pir/Project.h"
#include "cuts/pir/Worker.h"
#include "cuts/pir/Worker_Type.h"

#include <functional>
#include <algorithm>

namespace PICML_BON
{
  //===========================================================================
  /**
   * @struct Alphabetical_Order
   */
  //===========================================================================

  template <typename ELEMENT_TYPE>
  struct Alphabetical_Order
  {
    bool operator () (const ELEMENT_TYPE & left,
                      const ELEMENT_TYPE & right)
    {
      return left->getName () < right->getName ();
    }
  };

  //===========================================================================
  /**
   * @struct Reverse_Alphabetical_Order
   */
  //===========================================================================

  template <typename ELEMENT_TYPE>
  struct Reverse_Alphabetical_Order
  {
    bool operator () (const ELEMENT_TYPE & left,
                      const ELEMENT_TYPE & right)
    {
      return left->getName () > right->getName ();
    }
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

      return (lp.first < rp.first) && (left.second > right.second);
    }
  };

  //===========================================================================
  /**
   * @struct Location_Ordering_R2L
   */
  //===========================================================================

  template <typename ELEMENT_TYPE>
  struct Location_Ordering_R2L
  {
    bool operator () (const ELEMENT_TYPE & left,
                      const ELEMENT_TYPE & right)
    {
      BON::Point lp =
        BON::FCOExRegistryNode (left->getRegistry ())->getLocation ();

      BON::Point rp =
        BON::FCOExRegistryNode (left->getRegistry ())->getLocation ();

      return lp.first > rp.first;
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
    this->file_->name (object->getName ().c_str ());
    this->file_->uuid (object->getID ().c_str ());
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
    module->name (object->getName ().c_str ());
    module->uuid (object->getID ().c_str ());
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
    this->component_ = new CUTS_PIR::Component;
    this->component_->name (object->getName ().c_str ());
    this->component_->uuid (object->getID ().c_str ());
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
      this->visitEvent (*iter);
    }

    // Visit all the <Object> models.
    children = object->getChildFCOs ("Object");

    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      this->visitObject (*iter);
    }

    // Visit all the <Component> models.
    children = object->getChildFCOs ("Component");

    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      this->visitComponent (*iter);
    }

    // Get all the <Package> models.
    children = object->getChildFCOs ("Package");

    // Visit the child FCOs.
    for ( Child_FCOs::iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      this->visitPackage (*iter);
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
   event->name (object->getName ().c_str ());
   event->uuid (object->getID ().c_str ());

   // Insert the element into the referenced elements since it
   // can be referenced by event ports.
   this->ref_elements_.insert (
    Reference_Map::value_type (object->getID (), event));

    // Insert the event to the <Event_Manager> for the project.
    CUTS_PIR::Project::instance ()->event_manager ().insert (
      CUTS_PIR::Event_Manager::value_type (object->getID (), event));

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
    object->name (obj->getName ().c_str ());
    object->uuid (obj->getID ().c_str ());
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
    event_sink->name (object->getName ().c_str ());
    event_sink->uuid (object->getID ().c_str ());
    this->component_->event_sinks ().insert (event_sink);

    // Set the reference ID for the <event_sink>.
    Event event = object->getEvent ();

    // Locate the <reference> in the <ref_elements_>.
    Reference_Map::iterator iter =
      this->ref_elements_.find (event->getID ());

    if (iter == this->ref_elements_.end ())
    {
      this->unresolved_references_.insert (
        Unresolved_References::value_type (event->getID (), event_sink));
    }
    else
    {
      event_sink->reference (iter->second);
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

    home->name (factory->getName ().c_str ());
    home->uuid (factory->getID ().c_str ());

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
      facet->name (object->getName ().c_str ());
      facet->uuid (object->getID ().c_str ());

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
      worker_type->name (object->getName ().c_str ());
      worker_type->uuid (object->getID ().c_str ());

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
      worker->name (object->getName ().c_str ());
      worker->uuid (object->getID ().c_str ());

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
}
