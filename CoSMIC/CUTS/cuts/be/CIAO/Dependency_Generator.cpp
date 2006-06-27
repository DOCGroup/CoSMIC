// $Id$

#include "Dependency_Generator.h"
#include "Dependency_Graph.h"
#include "CoWorkEr_Cache.h"
#include "UDM_Utility_T.h"
#include "UmlExt.h"

#include  <algorithm>

//
// CUTS_Dependency_Generator
//
CUTS_Dependency_Generator::CUTS_Dependency_Generator (
  CUTS_Dependency_Graph & graph)
: graph_ (graph),
  current_node_ (0)
{

}

//
// ~CUTS_Dependency_Generator
//
CUTS_Dependency_Generator::~CUTS_Dependency_Generator (void)
{

}

//
// Visit_RootFolder
//
void CUTS_Dependency_Generator::Visit_RootFolder (
  const PICML::RootFolder & root)
{
  // Get all the interface definition folders.
  typedef std::set <PICML::InterfaceDefinitions> IDefs_Set;
  IDefs_Set defs = root.InterfaceDefinitions_kind_children ();

  // Visit all the interface definition folders.
  std::for_each (defs.begin (),
                 defs.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     IDefs_Set::value_type> (*this));
}

//
// Visit_InterfaceDefinitions
//
void CUTS_Dependency_Generator::Visit_InterfaceDefinitions (
  const PICML::InterfaceDefinitions & folder)
{
  typedef std::set <PICML::File> File_Set;
  File_Set files = folder.File_kind_children ();

  // Visit all the the files.
  std::for_each (files.begin (),
                 files.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     File_Set::value_type> (*this));
}

//
// Visit_File
//
void CUTS_Dependency_Generator::Visit_File (const PICML::File & file)
{
  // Create a node for the new file and visit its contents.
  this->current_node_ = this->graph_.create_node (file.name ());
  this->visit_file_and_package_contents (file);
}

//
// visit_file_and_package_contents
//
void CUTS_Dependency_Generator::visit_file_and_package_contents (
  const Udm::Object & obj)
{
  // Visit all the components at this level.
  typedef std::set <PICML::Component> Component_Set;

  Component_Set components =
    Udm::ChildrenAttr <PICML::Component> (obj.__impl (),
                                          Udm::NULLCHILDROLE);
  std::for_each (components.begin (),
                 components.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     Component_Set::value_type> (*this));

  //// Visit all the named types at this level.
  //typedef std::set <PICML::Event> Event_Set;
  //Event_Set events =
  //  Udm::ChildrenAttr <PICML::Event> (obj.__impl (), Udm::NULLCHILDROLE);

  //std::for_each (events.begin (),
  //               events.end (),
  //               UDM_Accept_Functor <CUTS_Dependency_Generator,
  //                                   Event_Set::value_type> (*this));

  //// Visit all the named types at this level.
  //typedef std::set <PICML::Object> Object_Set;
  //Object_Set objects =
  //  Udm::ChildrenAttr <PICML::Object> (obj.__impl (), Udm::NULLCHILDROLE);

  //std::for_each (objects.begin (),
  //               objects.end (),
  //               UDM_Accept_Functor <CUTS_Dependency_Generator,
  //                                   Object_Set::value_type> (*this));


  // Visit all the packages at this level.
  typedef std::set <PICML::Package> Package_Set;
  Package_Set packages =
    Udm::ChildrenAttr <PICML::Package> (obj.__impl (), Udm::NULLCHILDROLE);

  std::for_each (packages.begin (),
                 packages.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     Package_Set::value_type> (*this));
}

//
// Visit_Package
//
void CUTS_Dependency_Generator::Visit_Package (
  const PICML::Package & package)
{
  this->visit_file_and_package_contents (package);
}

//
// Visit_Component
//
void CUTS_Dependency_Generator::Visit_Component (
  const PICML::Component & component)
{
  // Determine if the component is a CoWorkEr. If it is then we
  // need to build the executor project as well and check
  // for all dependencies.
  if (!CUTS_CoWorkEr_Cache::instance ()->is_coworker (component))
  {
    return;
  }

  this->current_node_->flags_ |= (CUTS_Dependency_Node::DNF_STUB |
                                  CUTS_Dependency_Node::DNF_SVNT |
                                  CUTS_Dependency_Node::DNF_EXEC);

  // Get and visit all the worker types in this component.
  typedef std::set <PICML::WorkerType> WorkerType_Set;
  WorkerType_Set worker_types = component.WorkerType_kind_children ();

  std::for_each (worker_types.begin (),
                 worker_types.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     WorkerType_Set::value_type> (*this));

  // Determine if the component has output events.
  typedef std::set <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set oep_set = component.OutEventPort_kind_children ();

  if (!oep_set.empty ())
  {
    this->current_node_->flags_ |= CUTS_Dependency_Node::DNF_OUTEVENTS;

    std::for_each (oep_set.begin (),
                   oep_set.end (),
                   UDM_Accept_Functor <CUTS_Dependency_Generator,
                                       OutEventPort_Set::value_type> (*this));
  }

  // Determine if the component has input events.
  typedef std::set <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set iep_set = component.InEventPort_kind_children ();

  if (!iep_set.empty ())
  {
    this->current_node_->flags_ |= CUTS_Dependency_Node::DNF_INEVENTS;

    std::for_each (iep_set.begin (),
                   iep_set.end (),
                   UDM_Accept_Functor <CUTS_Dependency_Generator,
                                       InEventPort_Set::value_type> (*this));
  }

  // Determine if the component has any receptacles.
  typedef std::set <PICML::RequiredRequestPort> Receptacle_Set;
  Receptacle_Set receptacles = component.RequiredRequestPort_kind_children ();

  std::for_each (receptacles.begin (),
                 receptacles.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     Receptacle_Set::value_type> (*this));

  // Determine if the component has any facets.
  typedef std::set <PICML::ProvidedRequestPort> Facet_Set;
  Facet_Set facets = component.ProvidedRequestPort_kind_children ();

  std::for_each (facets.begin (),
                 facets.end (),
                 UDM_Accept_Functor <CUTS_Dependency_Generator,
                                     Facet_Set::value_type> (*this));

  // Determine if the component has any periodic actions.
  typedef std::set <PICML::PeriodicAction> Periodic_Set;
  Periodic_Set pset = component.PeriodicAction_kind_children ();

  if (!pset.empty ())
  {
    this->current_node_->flags_ |= CUTS_Dependency_Node::DNF_PERIODIC;
  }
}

//
// Visit_OutEventPort
//
void CUTS_Dependency_Generator::Visit_OutEventPort (
  const PICML::OutEventPort & port)
{
  PICML::Event event = port.ref ();

  if (event != 0)
  {
    event.Accept (*this);
  }
}

//
// Visit_InEventPort
//
void CUTS_Dependency_Generator::Visit_InEventPort (
  const PICML::InEventPort & port)
{
  PICML::Event event = port.ref ();

  if (event != 0)
  {
    event.Accept (*this);
  }
}

//
// Visit_RequiredRequestPort
//
void CUTS_Dependency_Generator::Visit_RequiredRequestPort (
  const PICML::RequiredRequestPort & port)
{
  PICML::Provideable provides = port.ref ();

  if (provides)
  {
    this->Visit_Providable (provides);
  }
}

//
// Visit_ProvidedRequestPort
//
void CUTS_Dependency_Generator::Visit_ProvidedRequestPort (
  const PICML::ProvidedRequestPort & port)
{
  PICML::Provideable provides = port.ref ();

  if (provides)
  {
    this->Visit_Providable (provides);
  }
}

//
// Visit_Provideable
//
void CUTS_Dependency_Generator::Visit_Providable (
  const PICML::Provideable & provides)
{
  this->Visit_NamedType (PICML::NamedType::Cast (provides));
}

//
// Visit_Object
//
void CUTS_Dependency_Generator::Visit_Object (const PICML::Object & object)
{
  this->Visit_NamedType (PICML::NamedType::Cast (object));
}

//
// Visit_Event
//
void CUTS_Dependency_Generator::Visit_Event (const PICML::Event & event)
{
  this->Visit_NamedType (PICML::NamedType::Cast (event));
}

//
// Visit_NamedType
//
void CUTS_Dependency_Generator::Visit_NamedType (const PICML::NamedType & type)
{
  PICML::Package package;
  PICML::MgaObject parent = type.parent ();

  // Continue building the name of the event type until we have
  // reached the File, or end of the Package tree.
  while ((std::string) parent.type ().name () ==
         (std::string) PICML::Package::meta.name ())
  {
    package = PICML::Package::Cast (parent);
    parent = package.parent ();
  }

  // Determine the location of this NamedType. If this event is not
  // in the current file then, when we need to add it to the list of
  // depends.
  if ((std::string) parent.type ().name () ==
      (std::string) PICML::File::meta.name ())
  {
    if ((std::string) parent.name () != this->current_node_->name ())
    {
      // Locate the node that contains this <PICML::NamedType>
      // element since it's not located in this file.
      CUTS_Dependency_Node * node = 0;
      this->graph_.find_node (parent.name (), node, true);

      // Add the <NamedType> elements node to the <current_node_>'s
      // <reference_> set. We also need to set the <STUB> and <SVNT>
      // flags since both projects are going to be need for the
      // the <current_node_> to build successfully.
      node->flags_ |= (CUTS_Dependency_Node::DNF_STUB |
                       CUTS_Dependency_Node::DNF_SVNT |
                       CUTS_Dependency_Node::DNF_COWORKER);

      this->current_node_->references_.insert (node);
    }
  }
}

//
// Visit_WorkerType
//
void CUTS_Dependency_Generator::Visit_WorkerType (
  const PICML::WorkerType & worker_type)
{
  PICML::Worker worker = worker_type.ref ();

  if (worker)
  {
    worker.Accept (*this);
  }
}

//
// Visit_Worker
//
void CUTS_Dependency_Generator::Visit_Worker (const PICML::Worker & worker)
{
  // Visit the file that contains this worker.
  PICML::WorkerPackageImplementationBase package_impl;
  package_impl = worker.WorkerPackageImplementationBase_parent ();

  // Trace the worker to it's parent file.
  while ((std::string) package_impl.type ().name () ==
         (std::string) PICML::WorkerPackage::meta.name ())
  {
    PICML::WorkerPackage package = PICML::WorkerPackage::Cast (package_impl);
    package_impl = package.WorkerPackageImplementationBase_parent ();
  }

  // Visit the parent file of the worker.
  PICML::WorkerFile::Cast (package_impl).Accept (*this);
}

//
// Visit_WorkerFile
//
void CUTS_Dependency_Generator::Visit_WorkerFile (
  const PICML::WorkerFile & worker_file)
{
  // Insert the name of this worker file into the current configuration.
  this->current_node_->includes_.insert (worker_file.name ());

  PICML::WorkerLibrary library = worker_file.WorkerLibrary_parent ();
  library.Accept (*this);
}

//
// Visit_WorkerLibrary
//
void CUTS_Dependency_Generator::Visit_WorkerLibrary (
  const PICML::WorkerLibrary & library)
{
  // Insert the name of the library into the libs for this
  // current file configuration.
  this->current_node_->libs_.insert (library.name ());

  std::string location = library.Location ();

  if (!location.empty ())
  {
    this->current_node_->libpaths_.insert (location);
  }
}
