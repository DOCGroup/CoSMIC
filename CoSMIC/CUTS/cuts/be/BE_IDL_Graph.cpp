// $Id$

#include "BE_IDL_Graph.h"
#include "boost/bind.hpp"
#include "Uml.h"

//
// CUTS_BE_IDL_Graph
//
CUTS_BE_IDL_Graph::CUTS_BE_IDL_Graph (void)
{

}

//
// ~CUTS_BE_IDL_Graph
//
CUTS_BE_IDL_Graph::~CUTS_BE_IDL_Graph (void)
{

}

//
// Visit_RootFolder
//
void CUTS_BE_IDL_Graph::
Visit_RootFolder (const PICML::RootFolder & root)
{
  typedef std::set <PICML::InterfaceDefinitions> IDefs_Set;
  IDefs_Set defs = root.InterfaceDefinitions_kind_children ();

  std::for_each (defs.begin (),
                 defs.end (),
                 boost::bind (&IDefs_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_InterfaceDefinitions
//
void CUTS_BE_IDL_Graph::
Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & folder)
{
  typedef std::set <PICML::File> File_Set;
  File_Set files = folder.File_kind_children ();

  std::for_each (files.begin (),
                 files.end (),
                 boost::bind (&File_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_File
//
void CUTS_BE_IDL_Graph::
Visit_File (const PICML::File & file)
{
  // Find this node in the graph then visit the <file>.
  if (this->find (file.name (), this->current_node_) == -1)
    return;

  // We are trying to keep from parsing this file more than once.
  // So, if we are have already visited this file, then we do
  // not need to do it again!! Just a waste of time.
  if (!this->current_node_->flags_[CUTS_BE_IDL_Node::IDL_VISITED])
  {
    // Set the visit flag. See above for reason.
    this->current_node_->flags_[CUTS_BE_IDL_Node::IDL_VISITED] = true;

    // Save the active file and visit its contents.
    this->active_file_ = file;
    this->visit_file_and_package_contents (file);

    while (!this->pending_files_.empty ())
    {
      // Get the first file in the collection.
      File_Set::iterator iter = this->pending_files_.begin ();
      PICML::File file = *iter;

      // Remove the file from the collection and visit it.
      this->pending_files_.erase (iter);
      file.Accept (*this);
    }
  }
}

//
// visit_file_and_package_contents
//
void CUTS_BE_IDL_Graph::
visit_file_and_package_contents (const Udm::Object & obj)
{
  // Visit all the events at this level.
  typedef std::vector <PICML::Event> Event_Set;

  Event_Set events =
    Udm::ChildrenAttr <PICML::Event> (
    obj.__impl (), Udm::NULLCHILDROLE);

  std::for_each (events.begin (),
                 events.end (),
                 boost::bind (&Event_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the objects at this level.
  typedef std::vector <PICML::Object> Object_Set;

  Object_Set objects =
    Udm::ChildrenAttr <PICML::Object> (
    obj.__impl (), Udm::NULLCHILDROLE);

  std::for_each (objects.begin (),
                 objects.end (),
                 boost::bind (&Object_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the components at this level.
  typedef std::vector <PICML::Component> Component_Set;

  Component_Set components =
    Udm::ChildrenAttr <PICML::Component> (
    obj.__impl (), Udm::NULLCHILDROLE);

  std::for_each (components.begin (),
                 components.end (),
                 boost::bind (&Component_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit all the packages at this level.
  typedef std::set <PICML::Package> Package_Set;

  Package_Set packages =
    Udm::ChildrenAttr <PICML::Package> (
    obj.__impl (), Udm::NULLCHILDROLE);

  std::for_each (packages.begin (),
                 packages.end (),
                 boost::bind (&Package_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_Package
//
void CUTS_BE_IDL_Graph::
Visit_Package (const PICML::Package & package)
{
  this->visit_file_and_package_contents (package);
}

//
// Visit_Component
//
void CUTS_BE_IDL_Graph::
Visit_Component (const PICML::Component & component)
{
  // Determine if the component has output events.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set oep_set = component.OutEventPort_kind_children ();

  std::for_each (oep_set.begin (),
                 oep_set.end (),
                 boost::bind (&OutEventPort_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Determine if the component has input events.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set iep_set = component.InEventPort_kind_children ();

  std::for_each (iep_set.begin (),
                 iep_set.end (),
                 boost::bind (&InEventPort_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Determine if the component has any receptacles.
  typedef std::vector <PICML::RequiredRequestPort> Receptacle_Set;
  Receptacle_Set receptacles = component.RequiredRequestPort_kind_children ();

  std::for_each (receptacles.begin (),
                 receptacles.end (),
                 boost::bind (&Receptacle_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Determine if the component has any facets.
  typedef std::vector <PICML::ProvidedRequestPort> Facet_Set;
  Facet_Set facets = component.ProvidedRequestPort_kind_children ();

  std::for_each (facets.begin (),
                 facets.end (),
                 boost::bind (&Facet_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Determine the dependency for supported interfaces.
  typedef std::vector <PICML::Supports> Supports_Set;
  Supports_Set supports = component.Supports_children ();

  std::for_each (supports.begin (),
                 supports.end (),
                 boost::bind (&Supports_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Determine the dependency for attributes. We get the read-only
  // kind since it will return both read-only and read-write
  // attributes.
  typedef std::vector <PICML::ReadonlyAttribute> Readonly_Set;
  Readonly_Set attrs = component.ReadonlyAttribute_kind_children ();

  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&Readonly_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // If this component is a <subtype> of another component, there is a
  // chance that it is located in another file. If this is the case
  // then we have to update its references.
  if (component.isSubtype ())
  {
    PICML::NamedType subtype =
      PICML::NamedType::Cast (component).Archetype ();

    this->Visit_NamedType (subtype);
  }
}

//
// Visit_OutEventPort
//
void CUTS_BE_IDL_Graph::
Visit_OutEventPort (const PICML::OutEventPort & port)
{
  PICML::Event event = port.ref ();

  if (event != Udm::null)
    event.Accept (*this);
}

//
// Visit_InEventPort
//
void CUTS_BE_IDL_Graph::
Visit_InEventPort (const PICML::InEventPort & port)
{
  PICML::Event event = port.ref ();

  if (event != Udm::null)
    event.Accept (*this);
}

//
// Visit_RequiredRequestPort
//
void CUTS_BE_IDL_Graph::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & port)
{
  PICML::Provideable provides = port.ref ();

  if (provides != Udm::null)
    this->Visit_Providable (provides);
}

//
// Visit_ProvidedRequestPort
//
void CUTS_BE_IDL_Graph::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & port)
{
  PICML::Provideable provides = port.ref ();

  if (provides != Udm::null)
    this->Visit_Providable (provides);
}

//
// Visit_Provideable
//
void CUTS_BE_IDL_Graph::
Visit_Providable (const PICML::Provideable & provides)
{
  this->Visit_NamedType (PICML::NamedType::Cast (provides));
}

//
// Visit_Object
//
void CUTS_BE_IDL_Graph::
Visit_Object (const PICML::Object & object)
{
  this->Visit_NamedType (PICML::NamedType::Cast (object));
}

//
// Visit_Event
//
void CUTS_BE_IDL_Graph::
Visit_Event (const PICML::Event & event)
{
  this->Visit_NamedType (PICML::NamedType::Cast (event));
}

//
// Visit_NamedType
//
void CUTS_BE_IDL_Graph::
Visit_NamedType (const PICML::NamedType & type)
{
  // Get the parent of the named type.
  PICML::File parent = this->NamedType_parent (type);

  // Determine the location of this NamedType. If this event is not
  // in the current file then, when we need to add it to the list of
  // depends.
  CUTS_BE_IDL_Node * node = 0;

  if (this->active_file_ != parent)
  {
    // Find the node with the name of the parent.
    this->find (parent.name (), node);

    if (node != 0)
      this->current_node_->references_.insert (node);

    // Ok, now we have to parse the <parent> before quiting.
    this->pending_files_.insert (parent);
  }
}

//
// Visit_Supports
//
void CUTS_BE_IDL_Graph::
Visit_Supports (const PICML::Supports & supports)
{
  PICML::Object object = supports.ref ();

  if (object != Udm::null)
    object.Accept (*this);
}

//
// Visit_ReadonlyAttribute
//
void CUTS_BE_IDL_Graph::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & readonly)
{
  PICML::AttributeMember member = readonly.AttributeMember_child ();

  if (member != Udm::null)
  {
    // The model is valid since we have a child!!!!
    PICML::MemberType type = member.ref ();

    try
    {
      // Try and extact the named type so we can update our
      // dependencies.
      PICML::NamedType named_type = PICML::NamedType::Cast (type);
      this->Visit_NamedType (named_type);
    }
    catch (udm_exception)
    {
      /* bad cast: not a NamedType */
    }
  }
}

//
// NamedType_parent
//
PICML::File CUTS_BE_IDL_Graph::
NamedType_parent (const PICML::NamedType & type)
{
  PICML::MgaObject parent = type.parent ();

  while (parent.type () != PICML::File::meta)
    parent = PICML::MgaObject::Cast (parent.parent ());

  return PICML::File::Cast (parent);
}
