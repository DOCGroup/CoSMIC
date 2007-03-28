// $Id$

#include "BE_Assembly_Generator.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Assembly_Generator.inl"
#endif

#include "CUTS_Project.h"
#include "BE_Position.h"
#include "BE_Scope_Manager.h"
#include "CoWorkEr_Cache.h"
#include "UDM_Utility_T.h"

// BOOST headers
#include "boost/bind.hpp"

// UDM headers
#include "Uml.h"

static const char *
CoWorkEr_ComponentImplementations = "CoWorkEr_ComponentImplementations";

//
// Visit_RootFolder
//
void CUTS_BE_Assembly_Generator::
Visit_RootFolder (const PICML::RootFolder & folder)
{
  typedef std::vector <PICML::ComponentImplementations> Folder_Set;
  Folder_Set folders = folder.ComponentImplementations_children ();

  // We need to locate the <CoWorkEr_ComponentImplementations> folder
  // or create one since this is where all the <CoWorkErs> will be
  // placed.
  if (create_element_if_not_exist (folders,
                                   Find_Element_By_Name <
                                      PICML::ComponentImplementations> (
                                      CoWorkEr_ComponentImplementations),
                                   folder,
                                   Udm::NULLCHILDROLE,
                                   this->target_folder_))
  {
    this->target_folder_.
      SetStrValue ("name", CoWorkEr_ComponentImplementations);
  }

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&Folder_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentImplementations
//
void CUTS_BE_Assembly_Generator::
Visit_ComponentImplementations (const PICML::ComponentImplementations & folder)
{
  // We need to ignore all folders that contain the following.
  std::string name = folder.name ();

  if (name.find_first_of ("CUTS_") == 0 ||
      name.find_first_of ("CoWorkEr_") == 0)
  {
    return;
  }

  typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;
  Container_Set containers = folder.ComponentImplementationContainer_children ();

  std::for_each (containers.begin (),
                 containers.end (),
                 boost::bind (&Container_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentImplementations
//
void CUTS_BE_Assembly_Generator::
Visit_ComponentImplementationContainer (
  const PICML::ComponentImplementationContainer & container)
{
  PICML::ComponentImplementation impl =
    container.ComponentImplementation_child ();

  if (impl.type () == PICML::ComponentAssembly::meta)
  {
    // We need to find the "target" container for this container.
    typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;
    Container_Set containers =
      this->target_folder_.ComponentImplementationContainer_children ();

    std::string name = (std::string)container.name () + "_CoWorkEr";

    if (create_element_if_not_exist (containers,
                                     Find_Element_By_Name <
                                        PICML::ComponentImplementationContainer> (
                                        name),
                                     this->target_folder_,
                                     Udm::NULLCHILDROLE,
                                     this->target_container_))
    {
      this->target_container_.SetStrValue ("name", name);
    }

    // We can now visit the assembly to create the proxies.
    PICML::ComponentAssembly assembly = PICML::ComponentAssembly::Cast (impl);
    assembly.Accept (*this);
  }
}

//
// Visit_ComponentAssembly
//
void CUTS_BE_Assembly_Generator::
Visit_ComponentAssembly (const PICML::ComponentAssembly & assembly)
{
  if (!assembly.isInstance ())
  {
    // Find the CoWorkEr assembly that matches this <assembly>.
    typedef std::vector <PICML::ComponentAssembly> ComponentAssembly_Set;
    ComponentAssembly_Set target_assemblies =
      this->target_container_.ComponentAssembly_kind_children ();

    std::string name = assembly.name ();

    if (create_element_if_not_exist (target_assemblies,
                                     Find_Element_By_Name <
                                        PICML::ComponentAssembly> (name),
                                     this->target_container_,
                                     Udm::NULLCHILDROLE,
                                     this->target_assembly_))
    {
      this->target_assembly_.SetStrValue ("name", name);
    }

    // Visit all the components in the assembly.
    typedef std::vector <PICML::Component> Component_Set;
    Component_Set components = assembly.Component_children ();

    std::for_each (components.begin (),
                   components.end (),
                   boost::bind (&Component_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));

    // Visit all the PublishConnector elements.
    typedef std::vector <PICML::PublishConnector> PublishConnector_Set;
    PublishConnector_Set connectors = assembly.PublishConnector_kind_children ();

    std::for_each (connectors.begin (),
                   connectors.end (),
                   boost::bind (&PublishConnector_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));

    // Visit all the emit connections in the assembly.
    typedef std::vector <PICML::emit> emit_Set;
    emit_Set emits = assembly.emit_children ();

    std::for_each (emits.begin (),
                   emits.end (),
                   boost::bind (&emit_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));

    // Visit all the <publish> connections in the <assembly>.
    typedef std::vector <PICML::publish> publish_Set;
    publish_Set publishes = assembly.publish_kind_children ();

    std::for_each (publishes.begin (),
                   publishes.end (),
                   boost::bind (&publish_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));

    // Visit all the <deliverTo> connections in the <assembly>.
    typedef std::vector <PICML::deliverTo> deliverTo_Set;
    deliverTo_Set deliversTo = assembly.deliverTo_kind_children ();

    std::for_each (deliversTo.begin (),
                   deliversTo.end (),
                   boost::bind (&deliverTo_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));
  }
}

//
// Visit_Component
//
void CUTS_BE_Assembly_Generator::
Visit_Component (const PICML::Component & component)
{
  // Get the interface type of this component.
  PICML::Component proxy_type;
  PICML::Component interface_type =
    PICML::Component::Cast (component.archetype ());

  if (this->locate_proxy_type (interface_type, proxy_type))
  {
    // Create an instance of the <proxy_type> in the <target_assembly_>.
    PICML::Component proxy_component =
      proxy_type.CreateInstance (this->target_assembly_);

    // Update the <proxy> so that it matches is <component>. We however,
    // are going to move the <proxy_component> down some to make space
    // for the <cuts_proxy_impl> property.
    proxy_component.name () = component.name ();

    CUTS_BE_Position pos;
    pos << component;
    pos.translate (0, 50);

    pos >> proxy_component;

    // Cache the proxy away for future usage.
    this->proxy_map_.insert (
      std::make_pair (proxy_component.name (), proxy_component));

    // Locate the <cuts_proxy_impl> attribute. This is need to configure
    // the proxy to load the correct implementation.
    typedef std::vector <PICML::Attribute> Attribute_Set;
    Attribute_Set attributes = proxy_component.Attribute_kind_children ();

    Attribute_Set::iterator cuts_proxy_impl =
      std::find_if (attributes.begin (),
                    attributes.end (),
                    boost::bind (std::equal_to <std::string> (),
                                 "cuts_proxy_impl",
                                 boost::bind (&PICML::Attribute::name,
                                              _1)));

    if (cuts_proxy_impl != attributes.end ())
    {
      // Locate the entry point for this proxy so we can fill
      // set the <cuts_proxy_impl> attribute.
      this->locate_executor_entry_point (proxy_type);

      // Create the property for the <cuts_proxy_impl>.
      PICML::Property property =
        PICML::Property::Create (this->target_assembly_);

      property.name () = "cuts_proxy_impl";
      property.DataValue () = this->artifact_name_ + ":" + this->entry_point_;

      // Create the attribute value connection for the property.
      PICML::AttributeValue attr_value =
        PICML::AttributeValue::Create (this->target_assembly_);

      attr_value.srcAttributeValue_end () = *cuts_proxy_impl;
      attr_value.dstAttributeValue_end () = property;

      // Create the <DataType> for the <property>. It is going to
      // reference the string type in the CUTS project.
      PICML::DataType datatype = PICML::DataType::Create (property);
      datatype.ref () = CUTS_Project::instance ()->get_string_type ();
    }
  }
}

//
// Visit_OutEventPort
//
void CUTS_BE_Assembly_Generator::
Visit_OutEventPort (const PICML::OutEventPort & outevent)
{
  // Get the parent of the <outevent>.
  PICML::Component component =
    PICML::Component::Cast (outevent.parent ());

  // Get the proxy that has the same name as <component>.
  PICML::Component proxy_component = this->proxy_map_[component.name ()];

  // Get all the output ports for the <proxy_component>.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set outevents = proxy_component.OutEventPort_kind_children ();

  OutEventPort_Set::iterator iter =
    std::find_if (outevents.begin (),
                  outevents.end (),
                  boost::bind (std::equal_to <std::string> (),
                               outevent.name (),
                               boost::bind (&PICML::OutEventPort::name, _1)));

  // Save the located output event port.
  if (iter != outevents.end ())
    this->target_outevent_ = *iter;
  else
    this->target_outevent_ = PICML::OutEventPort ();
}

//
// Visit_InEventPort
//
void CUTS_BE_Assembly_Generator::
Visit_InEventPort (const PICML::InEventPort & inevent)
{
  // Get the parent of the <inevent>.
  PICML::Component component =
    PICML::Component::Cast (inevent.parent ());

  // Get the proxy that has the same name as <component>.
  PICML::Component proxy_component = this->proxy_map_[component.name ()];

  // Get all the input ports for the <proxy_component>.
  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set inevents = proxy_component.InEventPort_kind_children ();

  InEventPort_Set::iterator iter =
    std::find_if (inevents.begin (),
                  inevents.end (),
                  boost::bind (std::equal_to <std::string> (),
                               inevent.name (),
                               boost::bind (&PICML::InEventPort::name, _1)));

  // Save the located input event port.
  if (iter != inevents.end ())
    this->target_inevent_ = *iter;
  else
    this->target_inevent_ = PICML::InEventPort ();
}

//
// Visit_publish
//
void CUTS_BE_Assembly_Generator::
Visit_publish (const PICML::publish & publish)
{
  // This will locate the correct input event port on the
  // proxy component.
  PICML::OutEventPort outevent = publish.srcpublish_end ();
  outevent.Accept (*this);

  PICML::PublishConnector connector = publish.dstpublish_end ();
  PICML::PublishConnector target_connector =
    this->connector_map_[connector.name ()];

  if (this->target_outevent_ != Udm::null &&
      target_connector != Udm::null)
  {
    PICML::publish target_publish =
      PICML::publish::Create (this->target_assembly_);

    target_publish.srcpublish_end () = this->target_outevent_;
    target_publish.dstpublish_end () = target_connector;
  }
}

//
// Visit_emit
//
void CUTS_BE_Assembly_Generator::
Visit_emit (const PICML::emit & emit)
{
  // Visit the <InEventPort> for this connection.
  PICML::InEventPort inevent = emit.dstemit_end ();
  inevent.Accept (*this);

  // Visit the <OutEventPort> for this connection.
  PICML::OutEventPort outevent = emit.srcemit_end ();
  outevent.Accept (*this);

  if (this->target_inevent_ != Udm::null &&
      this->target_outevent_ != Udm::null)
  {
    // Create an <emit> connection and connect the input
    // and output ports.
    PICML::emit target_emit =
      PICML::emit::Create (this->target_assembly_);

    target_emit.srcemit_end () = this->target_outevent_;
    target_emit.dstemit_end () = this->target_inevent_;
  }
}

//
// Visit_PublishConnector
//
void CUTS_BE_Assembly_Generator::
Visit_PublishConnector (const PICML::PublishConnector & connector)
{
  // Create a <PublishConnector> to represent <connector>.
  PICML::PublishConnector target_connector =
    PICML::PublishConnector::Create (this->target_assembly_);

  target_connector.name () = connector.name ();
  target_connector.position () = connector.position ();

  this->connector_map_.insert (
    std::make_pair (target_connector.name (), target_connector));
}

//
// Visit_deliverTo
//
void CUTS_BE_Assembly_Generator::
Visit_deliverTo (const PICML::deliverTo & deliverTo)
{
  // This will locate the correct input port on the proxy component.
  PICML::InEventPort inevent = deliverTo.dstdeliverTo_end ();
  inevent.Accept (*this);

  PICML::PublishConnector connector = deliverTo.srcdeliverTo_end ();
  PICML::PublishConnector target_connector =
    this->connector_map_[connector.name ()];

  if (this->target_inevent_ != Udm::null &&
      target_connector != Udm::null)
  {
    PICML::deliverTo target_deliverTo =
      PICML::deliverTo::Create (this->target_assembly_);

    target_deliverTo.srcdeliverTo_end () = target_connector;
    target_deliverTo.dstdeliverTo_end () = this->target_inevent_;
  }
}

//
// locate_proxy
//
bool CUTS_BE_Assembly_Generator::
locate_proxy (const PICML::Component & component,
              PICML::Component & proxy)
{
  typedef std::vector <PICML::Component> Component_Set;
  Component_Set proxies = this->target_assembly_.Component_children ();

  // Locate the proxy component by its name.
  Component_Set::iterator iter =
    std::find_if (proxies.begin (),
                  proxies.end (),
                  boost::bind (std::equal_to <std::string> (),
                               component.name (),
                               boost::bind (&PICML::Component::name, _1)));

  if (iter == proxies.end ())
    return false;

  proxy = *iter;
  return true;
}

//
// locate_proxy_type
//
bool CUTS_BE_Assembly_Generator::
locate_proxy_type (const PICML::Component & component,
                   PICML::Component & proxy)
{
  Proxy_Type_Map::const_iterator entry =
    this->proxy_type_map_.find (component);

  if (entry != this->proxy_type_map_.end ())
  {
    proxy = entry->second;
    return true;
  }

  // Locate the "proxy" that supports this interface. This mean we
  // have to search all the component's that are derived from this
  // component to locate the CoWorkEr proxy.
  typedef std::set <PICML::Component> Component_Set;
  Component_Set derived = Udm::DerivedAttr <PICML::Component> (component.__impl ());

  Component_Set::const_iterator iter =
    std::find_if (derived.begin (),
                  derived.end (),
                  &CUTS_CoWorkEr_Cache::is_coworker);

  if (iter == derived.end ())
    return false;

  this->proxy_type_map_.insert (std::make_pair (component, *iter));
  proxy = *iter;
  return true;
}

//
// locate_executor_entry_point
//
void CUTS_BE_Assembly_Generator::
locate_executor_entry_point (const PICML::Component & component)
{
  if (!this->artifact_name_.empty ())
    this->artifact_name_.clear ();

  if (!this->entry_point_.empty ())
    this->entry_point_.empty ();

  // The first thing we need to do is locate the container that
  // has the same path name as this <component>.
  typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;
  Container_Set containers =
    this->target_folder_.ComponentImplementationContainer_kind_children ();

  std::string scoped_name =
    CUTS_BE_SCOPE_MANAGER ()->generate_scope (component, "/") +
    (std::string) component.name ();

  Container_Set::iterator iter =
    std::find_if (containers.begin (),
                  containers.end (),
                  boost::bind (std::equal_to <std::string> (),
                               scoped_name,
                               boost::bind (&PICML::ComponentImplementationContainer::name,
                                            _1)));

  // If we have found the <container>, then we need to visit its
  // monolithic implementation. This will allow use to eventually
  // visti its artifacts.
  if (iter != containers.end ())
  {
    typedef std::vector <PICML::MonolithicImplementation> MonoImpl_Set;
    MonoImpl_Set monoimpls = iter->MonolithicImplementation_kind_children ();

    if (!monoimpls.empty ())
      monoimpls.begin ()->Accept (*this);
  }
}

//
// Visit_MonolithicImplementation
//
void CUTS_BE_Assembly_Generator::
Visit_MonolithicImplementation (const PICML::MonolithicImplementation & monoimpl)
{
  typedef std::set <PICML::MonolithprimaryArtifact> primaryArtifact_Set;
  primaryArtifact_Set primaries = monoimpl.dstMonolithprimaryArtifact ();

  std::for_each (primaries.begin (),
                 primaries.end (),
                 boost::bind (&primaryArtifact_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

}

//
// Visit_MonolithprimaryArtifact
//
void CUTS_BE_Assembly_Generator::
Visit_MonolithprimaryArtifact (const PICML::MonolithprimaryArtifact & primary)
{
  PICML::ImplementationArtifactReference ref =
    primary.dstMonolithprimaryArtifact_end ();

  PICML::ImplementationArtifact artifact = ref.ref ();

  if (artifact != Udm::null)
    artifact.Accept (*this);
}

//
// Visit_ImplementationArtifact
//
void CUTS_BE_Assembly_Generator::
Visit_ImplementationArtifact (const PICML::ImplementationArtifact & artifact)
{
  // Determine if this is the CIAO executor artifact. The artifact
  // will end in _exec.
  std::string name = artifact.name ();

  if (name.rfind ("_exec") == (name.length () - 5))
  {
    this->artifact_name_ = artifact.location ();

    typedef std::set <PICML::ArtifactExecParameter> ExecParameter_Set;
    ExecParameter_Set params = artifact.dstArtifactExecParameter ();

    std::for_each (params.begin (),
                   params.end (),
                   boost::bind (&ExecParameter_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));
  }
}

//
// Visit_ArtifactExecParameter
//
void CUTS_BE_Assembly_Generator::
Visit_ArtifactExecParameter (const PICML::ArtifactExecParameter & param)
{
  PICML::Property property = param.dstArtifactExecParameter_end ();

  if ((std::string) property.name () == "entryPoint")
    this->entry_point_ = property.DataValue ();
}
