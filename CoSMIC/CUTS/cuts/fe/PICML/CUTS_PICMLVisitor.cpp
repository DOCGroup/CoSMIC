// $Id$

#include "StdAfx.h"
#include "cuts/fe/PICML/CUTS_PICMLVisitor.h"
#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventManager.h"
#include "cuts/pir/Event.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/File.h"
#include "cuts/pir/Project.h"

#include <functional>
#include <algorithm>

namespace PICML_BON
{
  typedef std::set<BON::FCO> Child_FCOs;

  //
  // CUTS_PICMLVisitor
  //
  CUTS_PICMLVisitor::CUTS_PICMLVisitor (void)
    : file_ (0),
      module_ (0),
      component_ (0),
      event_ (0)
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
    this->module_->components ().insert (this->component_);

    // Get the factory assigned to this component.
    typedef std::set <BON::Connection> Connections;
    Connections manages = object->getInConnLinks();
    for ( Connections::iterator iter = manages.begin ();
          iter != manages.end ();
          iter ++)
    {
      visitManagesComponent (*iter);
    }

    // Get all the <InEventPort> objects for this component.
    Child_FCOs children = object->getChildFCOs ("InEventPort");
    for ( Child_FCOs::const_iterator iter = children.begin ();
          iter != children.end ();
          iter ++)
    {
      visitInEventPort (*iter);
    }

    return true;
  }

  //
  // visitPackageContents
  //
  void CUTS_PICMLVisitor::visitPackageContents (const BON::Model & object)
  {
    // Visit all the <Component> models.
    Child_FCOs children = object->getChildFCOs ("Component");

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
  // visitManagesComponent
  //
  bool CUTS_PICMLVisitor::visitManagesComponent (const ManagesComponent & object)
  {
    if (!object)
      return false;

    // Get the factory managing the current component.
    visitComponentFactory (object->getSrc ());
    return true;
  }

  //
  // visitComponentFactory
  //
  bool CUTS_PICMLVisitor::visitComponentFactory (const ComponentFactory & object)
  {
    if (!object)
      return false;

    // Represent the <ComponentFactory> as a <Component_Home>
    CUTS_PIR::Component_Home * home =
      new CUTS_PIR::Component_Home (this->module_);

    // Save the information about the <Component_Home>
    home->name (object->getName ().c_str ());
    this->component_->home (home);

    return true;
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

    // Create a new <event> in this module.
    CUTS_PIR::Event_Manager::iterator result =
      CUTS_PIR::Project::instance ()->event_manager ().find (object->getID ());

    if (result == CUTS_PIR::Project::instance ()->event_manager ().end ())
    {
      // Create a new <event> since we have never seen this one.
      this->event_ = new CUTS_PIR::Event (this->module_);
      this->event_->name (object->getName ().c_str ());

      // Add the event to the <Event_Manager> for the project.
      CUTS_PIR::Project::instance ()->event_manager ().insert (
        CUTS_PIR::Event_Manager::value_type (object->getID (), this->event_));
    }
    else
    {
      this->event_ = result->second;
    }

    return true;
  }

  //
  // visitInEventPort
  //
  bool CUTS_PICMLVisitor::visitInEventPort (const InEventPort & object)
  {
    if (!object)
      return false;

    // Visit the event for the <InEventPort>
    this->file_->has_events (true);
    visitEvent (object->getEvent ());

    // Create a <Event_Sink> for the <InEventPort>.
    CUTS_PIR::Event_Sink * event_sink = new CUTS_PIR::Event_Sink (this->event_);
    event_sink->name (object->getName ().c_str ());

    // Inser the <event_type> and <event_sink> into this component.
    this->component_->event_sinks ().insert (event_sink);
    this->component_->in_events_types ().insert (this->event_);
    return true;
  }
}
