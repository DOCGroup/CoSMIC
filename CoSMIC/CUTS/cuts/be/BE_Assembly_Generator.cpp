// $Id$

#include "BE_Assembly_Generator.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Assembly_Generator.inl"
#endif

#include "BE_Position.h"
#include "BE_Scope_Manager.h"
#include "CoWorkEr_Cache.h"
#include "CUTS_Project.h"
#include "modelgen.h"

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
  if (Udm::contains (
      boost::bind (std::equal_to <std::string> (),
                   CoWorkEr_ComponentImplementations,
                   boost::bind (&PICML::ComponentImplementations::name,
                                _1))) (folder, this->target_folder_))
  {
    std::for_each (folders.begin (),
                   folders.end (),
                   boost::bind (&Folder_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));
  }
  else
  {
    // The user need to run the CoWorkEr generator first.
  }
}

//
// Visit_ComponentImplementations
//
void CUTS_BE_Assembly_Generator::
Visit_ComponentImplementations (const PICML::ComponentImplementations & folder)
{
  // We need to ignore all folders that contain the following.
  std::string name = folder.name ();

  if (name.find ("CUTS_") == std::string::npos &&
      name.find ("CoWorkEr_") == std::string::npos)
  {
    typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;
    Container_Set containers = folder.ComponentImplementationContainer_children ();

    std::for_each (containers.begin (),
                   containers.end (),
                   boost::bind (&Container_Set::value_type::Accept,
                                _1,
                                boost::ref (*this)));
  }
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
    std::string name = std::string (container.name ()) + "_CoWorkEr";

    // We need to find the "target" container for this container.
    if (Udm::create_if_not (this->target_folder_, this->target_container_,
        Udm::contains (boost::bind (std::equal_to <std::string> (),
                       name,
                       boost::bind (&PICML::ComponentImplementationContainer::name,
                                    _1)))))
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
    std::string name = assembly.name ();

    if (Udm::create_if_not (this->target_container_, this->target_assembly_,
        Udm::contains (boost::bind (std::equal_to <std::string> (),
                       name,
                       boost::bind (&PICML::ComponentAssembly::name, _1)))))
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
    // We should first search for an instance of the specified type
    // that has the same name. If we can't find it, when we should
    // create one.

    PICML::Component proxy_component;
    std::string name = component.name ();

    if (Udm::create_instance_if_not (this->target_assembly_,
        proxy_type, proxy_component,
        Udm::contains (boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <std::string> (),
                       name,
                       boost::bind (&PICML::Component::name, _1)),
          boost::bind (std::equal_to <Udm::Object> (),
                       proxy_type,
                       boost::bind (&Udm::Object::archetype, _1))))))
    {
      // Update the <proxy> so that it matches its <component>. We however,
      // are going to move the <proxy_component> down some to make space
      // for the <cuts_proxy_impl> property.
      proxy_component.name () = component.name ();

      CUTS_BE_Position pos;
      pos << component;
      pos.translate (0, 50);
      pos >> proxy_component;
    }

    // Locate the <cuts_proxy_impl> attribute. This is need to configure
    // the proxy to load the correct implementation.
    typedef std::vector <PICML::Attribute> Attribute_Set;
    Attribute_Set attributes = proxy_component.Attribute_kind_children ();

    PICML::Attribute attribute;
    PICML::Property property;
    std::string propval;

    if (Udm::contains (boost::bind (std::equal_to <std::string> (),
                       "cuts_proxy_impl",
                       boost::bind (&PICML::Attribute::name,
                                    _1))) (proxy_component, attribute))
    {
      if (this->create_attribute_property (attribute,
                                           this->target_assembly_,
                                           property))
      {
        // Create the property value for cuts_proxy_impl.
        this->locate_executor_entry_point (interface_type);
        propval = this->artifact_name_ + ":" + this->entry_point_;

        if (std::string (property.DataValue ()) != propval)
          property.DataValue () = propval;
      }
    }

    // Save the proxy by name for later usage.
    this->proxy_map_.insert (
      std::make_pair (proxy_component.name (), proxy_component));

    // We need to make sure their is a property set for the
    // name of the proxy.
    if (Udm::contains (boost::bind (std::equal_to <std::string> (),
                       "cuts_name",
                       boost::bind (&PICML::Attribute::name,
                                    _1))) (proxy_component, attribute))
    {
      if (this->create_attribute_property (attribute,
                                           this->target_assembly_,
                                           property))
      {
        this->generate_scoped_instance_name (component, propval);

        if (std::string (property.DataValue ()) != propval)
          property.DataValue () = propval;
      }
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
  // Get all the input ports for the <proxy_component>.
  if (!Udm::contains (boost::bind (std::equal_to <std::string> (),
                      outevent.name (),
                      boost::bind (&PICML::OutEventPort::name,
                                   _1))) (proxy_component,
                                          this->target_outevent_))
  {
    this->target_outevent_ = PICML::OutEventPort::Cast (Udm::null);
  }
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
  if (!Udm::contains (boost::bind (std::equal_to <std::string> (),
                      inevent.name (),
                      boost::bind (&PICML::InEventPort::name,
                                   _1))) (proxy_component,
                                          this->target_inevent_))
  {
    this->target_inevent_ = PICML::InEventPort::Cast (Udm::null);
  }
}

//
// Visit_publish
//
void CUTS_BE_Assembly_Generator::
Visit_publish (const PICML::publish & publish)
{
  // Locate the correct output port on the proxy.
  PICML::OutEventPort outevent = publish.srcpublish_end ();
  outevent.Accept (*this);

  // Get the connector in the target assembly.
  PICML::PublishConnector connector = publish.dstpublish_end ();
  PICML::PublishConnector target_connector = this->connector_map_[connector.name ()];

  PICML::publish target_publish;

  if (this->target_outevent_ != Udm::null && target_connector != Udm::null)
  {
    // We only need to create a publish connection if one does not
    // already exist.
    if (Udm::create_if_not (this->target_assembly_, target_publish,
        Udm::contains (boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <PICML::OutEventPort> (),
                       this->target_outevent_,
                       boost::bind (&PICML::publish::srcpublish_end, _1)),
          boost::bind (std::equal_to <PICML::PublishConnector> (),
                       target_connector,
                       boost::bind (&PICML::publish::dstpublish_end, _1))))))
    {
      target_publish.srcpublish_end () = this->target_outevent_;
      target_publish.dstpublish_end () = target_connector;
    }
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

  if (this->target_inevent_  != Udm::null &&
      this->target_outevent_ != Udm::null)
  {
    // We need to create a emits connection in the target assembly
    // if we are not able to find an existing one for the target
    // in and out event ports.
    PICML::emit target_emit;

    if (Udm::create_if_not (this->target_assembly_, target_emit,
        Udm::contains (boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <PICML::OutEventPort> (),
            this->target_outevent_,
            boost::bind (&PICML::emit::srcemit_end, _1)),
          boost::bind (std::equal_to <PICML::InEventPort> (),
            this->target_inevent_,
            boost::bind (&PICML::emit::dstemit_end, _1))))))
    {
      target_emit.srcemit_end () = this->target_outevent_;
      target_emit.dstemit_end () = this->target_inevent_;
    }
  }
}

//
// Visit_PublishConnector
//
void CUTS_BE_Assembly_Generator::
Visit_PublishConnector (const PICML::PublishConnector & connector)
{
  // Create a <PublishConnector> to represent <connector>.
  PICML::PublishConnector target_connector;
  std::string name = connector.name ();

  if (Udm::create_if_not (this->target_assembly_, target_connector,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     name,
                     boost::bind (&PICML::PublishConnector::name, _1)))))
  {
    target_connector.name () = connector.name ();
    target_connector.position () = connector.position ();
  }

  // Save the connector for later usage.
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

  if (this->target_inevent_ != Udm::null && target_connector != Udm::null)
  {
    PICML::deliverTo target_deliverTo;

    if (Udm::create_if_not (this->target_assembly_, target_deliverTo,
        Udm::contains (boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <PICML::PublishConnector> (),
            target_connector,
            boost::bind (&PICML::deliverTo::srcdeliverTo_end, _1)),
          boost::bind (std::equal_to <PICML::InEventPort> (),
            this->target_inevent_,
            boost::bind (&PICML::deliverTo::dstdeliverTo_end, _1))))))
    {
      target_deliverTo.srcdeliverTo_end () = target_connector;
      target_deliverTo.dstdeliverTo_end () = this->target_inevent_;
    }
  }
}

//
// locate_proxy
//
bool CUTS_BE_Assembly_Generator::
locate_proxy (const PICML::Component & component, PICML::Component & proxy)
{
  typedef std::vector <PICML::Component> Component_Set;
  Component_Set proxies = this->target_assembly_.Component_children ();

  // Locate the proxy component by its name.
  return Udm::contains (boost::bind (std::equal_to <std::string> (),
                        component.name (),
                        boost::bind (&PICML::Component::name,
                                     _1))) (this->target_assembly_, proxy);
}

//
// locate_proxy_type
//
bool CUTS_BE_Assembly_Generator::
locate_proxy_type (const PICML::Component & component,
                   PICML::Component & proxy)
{
  Proxy_Type_Map::
    const_iterator entry = this->proxy_type_map_.find (component);

  if (entry != this->proxy_type_map_.end ())
  {
    proxy = entry->second;
    return true;
  }

  // Locate the "proxy" that supports this interface. This mean we
  // have to search all the component's that are derived from this
  // component to locate the CoWorkEr proxy.

  typedef std::set <PICML::Component> Component_Set;
  Component_Set tmpset = Udm::DerivedAttr <PICML::Component> (component.__impl ());

  if (Udm::contains (
      boost::bind (&CUTS_CoWorkEr_Cache::is_coworker, _1)) (tmpset, proxy))
  {
    this->proxy_type_map_.insert (std::make_pair (component, proxy));
    return true;
  }
  else
    return false;
}

//
// locate_executor_entry_point
//
bool CUTS_BE_Assembly_Generator::
locate_executor_entry_point (const PICML::Component & component)
{
  // Erase the previous values.
  this->artifact_name_.clear ();
  this->entry_point_.clear ();

  // First, we need to locate the component implementation container
  // that contains a monolithic implementation for this component.
  typedef std::set <PICML::ComponentRef> ComponentRef_Set;
  ComponentRef_Set refs = component.referedbyComponentRef ();

  for (ComponentRef_Set::iterator iter = refs.begin ();
       iter != refs.end ();
       iter ++)
  {
    // Get the monolithic implementation in this container and visit
    // it. We need to locate the executor artifact.
    PICML::Implements implements = iter->srcImplements ();

    if (implements != Udm::null)
    {
      implements.Accept (*this);
      break;
    }
  }

  return !(this->artifact_name_.empty () || this->entry_point_.empty ());
}

//
// Visit_Implements
//
void CUTS_BE_Assembly_Generator::
Visit_Implements (const PICML::Implements & implements)
{
  PICML::MonolithicImplementation monoimpl =
    PICML::MonolithicImplementation::Cast (implements.srcImplements_end ());

  monoimpl.Accept (*this);
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

//
// create_attribute_property
//
bool CUTS_BE_Assembly_Generator::
create_attribute_property (const PICML::ReadonlyAttribute & attr,
                           const Udm::Object & parent,
                           PICML::Property & property)
{
  // Get the connection from the cuts_proxy_impl its property. If
  // we cannot find it, then we need to create one and attach it to
  // the connection.
  PICML::AttributeValue attrval = attr.dstAttributeValue ();

  if (attrval == Udm::null)
  {
    attrval = PICML::AttributeValue::Create (parent);
    attrval.srcAttributeValue_end () = attr;
  }

  // Get the property that is connected to the attribute value. If we
  // cannot find one, then we need to create one and attach it to
  // the connection.
  property = attrval.dstAttributeValue_end ();

  if (property == Udm::null)
  {
    // Create the new property and connect it with the attribute
    // value connection.
    property = PICML::Property::Create (parent);
    attrval.dstAttributeValue_end () = property;
  }

  if (std::string (property.name ()) != std::string (attr.name ()))
    property.name () = attr.name ();

  // We need to get the target attribute data type. We want to
  // reference the same data object in the property. This will
  // make life a LOT simplier.
  PICML::AttributeMember attr_member = attr.AttributeMember_child ();

  if (attr_member == Udm::null)
    return false;

  try
  {
    // Let's see what kind of member type we have in this attribute.
    PICML::MemberType member_type = attr_member.ref ();

    if (member_type == Udm::null)
      return false;

    PICML::PredefinedType target_type = PICML::PredefinedType::Cast (member_type);

    if (target_type == Udm::null)
      return false;

    // Now that we have the predefined type of the attribute, we need
    // to see if the property has a data type element.
    PICML::DataType datatype = property.DataType_child ();

    if (datatype == Udm::null)
      datatype = PICML::DataType::Create (property);

    // Make sure the name of the data type and the actual reference
    // to the predefined type is of <type>.
    if (std::string (datatype.name ()) != std::string (target_type.name ()))
      datatype.name () = target_type.name ();

    PICML::PredefinedType curr_type = datatype.ref ();

    if (curr_type != target_type)
      datatype.ref () = target_type;

    return true;
  }
  catch (udm_exception & )
  {

  }

  return false;
}

//
// generate_scoped_instance_name
//
void CUTS_BE_Assembly_Generator::
generate_scoped_instance_name (const PICML::Component & component,
                               std::string & name)
{
  // Initialize the scoped name for the component instance.
  name = component.name ();
  PICML::MgaObject parent = component.parent ();

  do
  {
    name.insert (0, ".").insert (0, parent.name ());
    parent = PICML::MgaObject::Cast (parent.parent ());
  } while (parent.type () != PICML::ComponentImplementationContainer::meta);
}
