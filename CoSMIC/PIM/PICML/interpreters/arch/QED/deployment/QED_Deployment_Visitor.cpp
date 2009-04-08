// $Id$

#include "QED_Deployment_Visitor.h"
#include "QED_Implementation_Finder.h"
#include "Utils/XercesString.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <sstream>
#include <direct.h>

#include "Uml.h"

//
// QED_Deployment_Visitor
//
QED_Deployment_Visitor::
QED_Deployment_Visitor (const std::string & output)
: output_ (output),
  impl_ (0),
  doc_ (0),
  serializer_ (0),
  target_ (0)
{
  using namespace xercesc;

  this->path_.push (this->output_);

  this->impl_ =
    DOMImplementationRegistry::getDOMImplementation (Utils::XStr ("LS"));

  this->serializer_ =
    ((DOMImplementationLS *)impl_)->createLSSerializer ();

  // Initialize all the features for the writer.
  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTWhitespaceInElementContent, false))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTWhitespaceInElementContent, false);
}

//
// ~QED_Deployment_Visitor
//
QED_Deployment_Visitor::~QED_Deployment_Visitor (void)
{
  if (this->doc_ != 0)
    this->doc_->release();

  if (this->target_ != 0)
    delete this->target_;
}

//
// Visit_RootFolder
//
void QED_Deployment_Visitor::
Visit_RootFolder (const PICML::RootFolder & root)
{
  // Generate the component instance configuration.
  typedef
    std::vector <PICML::ComponentImplementations>
    ComponentImplementations_Set;

  ComponentImplementations_Set folders =
    root.ComponentImplementations_children ();

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&ComponentImplementations_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Generate the deployment plans in this project.
  typedef
    std::vector <PICML::DeploymentPlans>
    DeploymentPlans_Set;

  DeploymentPlans_Set plans = root.DeploymentPlans_kind_children ();

  std::for_each (plans.begin (),
                 plans.end (),
                 boost::bind (&DeploymentPlans_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentImplementations
//
void QED_Deployment_Visitor::
Visit_ComponentImplementations (const PICML::ComponentImplementations & cis)
{
  typedef
    std::vector <PICML::ComponentImplementationContainer>
    ComponentImplementationContainer_Set;

  ComponentImplementationContainer_Set containers =
    cis.ComponentImplementationContainer_children ();

  std::for_each (containers.begin (),
                 containers.end (),
                 boost::bind (&ComponentImplementationContainer_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_ComponentImplementationContainer
//
void QED_Deployment_Visitor::
Visit_ComponentImplementationContainer (
  const PICML::ComponentImplementationContainer & container)
{
  typedef
    std::vector <PICML::ComponentAssembly>
    ComponentAssembly_Set;

  ComponentAssembly_Set assembly =
    container.ComponentAssembly_kind_children ();

  std::for_each (assembly.begin (),
                 assembly.end (),
                 boost::bind (&ComponentAssembly_Set::value_type::Accept,
                              _1, boost::ref (*this)));
}

//
// Visit_ComponentAssembly
//
void QED_Deployment_Visitor::
Visit_ComponentAssembly (const PICML::ComponentAssembly & assembly)
{
  // Get the name of the assembly.
  std::string name = assembly.name ();

  // Construct the current scope.
  if (!this->scope_.empty ())
  {
    std::ostringstream scope;
    scope << this->scope_.top () << "." << name;

    this->scope_.push (scope.str ().c_str ());
  }
  else
  {
    this->scope_.push (name);
  }

  // Construct the new path, both in memory and on disk.
  std::ostringstream path;
  path << this->path_.top () << "/" << name;

  std::string pathstr = path.str ();
  ::_mkdir (pathstr.c_str ());

  // Save the path for later usage.
  this->path_.push (pathstr);
  this->scope_.push (name);

  // Visit all the assemblies in this assembly.
  typedef std::vector <PICML::ComponentAssembly> ComponentAssembly_Set;
  ComponentAssembly_Set assemblies = assembly.ComponentAssembly_children ();

  std::for_each (assemblies.begin (),
                 assemblies.end (),
                 boost::bind (&ComponentAssembly_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Visit each of the component's in the assembly.
  typedef std::vector <PICML::Component> Component_Set;
  Component_Set components = assembly.Component_children ();

  std::for_each (components.begin (),
                 components.end (),
                 boost::bind (&Component_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Remove the paths from the stack.
  this->path_.pop ();
  this->scope_.pop ();
}

//
// Visit_Component
//
void QED_Deployment_Visitor::
Visit_Component (const PICML::Component & component)
{
  // Create the XML document.
  if (this->doc_ != 0)
    this->doc_->release();

  this->doc_ =
    this->impl_->createDocument (
      Utils::XStr ("http://www.springframework.org/schema/beans"),
      Utils::XStr ("beans"),
      0);

  //this->doc_->setEncoding (Utils::XStr("UTF-8"));
  this->doc_->setXmlVersion (Utils::XStr("1.0"));

  xercesc::DOMElement * root = this->doc_->getDocumentElement ();

  root->setAttributeNS (
    Utils::XStr ("http://www.w3.org/2000/xmlns/"),
    Utils::XStr ("xmlns:xsi"),
    Utils::XStr ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttribute (
    Utils::XStr ("xsi:schemaLocation"),
    Utils::XStr ("http://www.springframework.org/schema/beans "
                 "http://www.springframework.org/schema/beans/spring-beans-2.5.xsd"));

  // Create the filename for the configuration.
  std::string name = component.name ();

  // Define the instance information.
  std::ostringstream unique_id;
  unique_id << this->scope_.top () << "." << name;

  xercesc::DOMElement * element =
    this->doc_->createElement (Utils::XStr ("bean"));

  element->setAttribute (Utils::XStr ("id"),
                         Utils::XStr (unique_id.str ().c_str ()));

  // Save the unique id for later usage.
  this->instance_names_[component] = unique_id.str ();

  // Find the implementation for this component.
  QED_Implementation_Finder finder;
  PICML::Component (component).Accept (finder);

  // Remove all the default properties.
  if (!this->default_props_.empty ())
    this->default_props_.empty ();

  if (finder.is_found ())
  {
    PICML::MonolithicImplementation impl = finder.implementation ();
    std::string type = impl.name ();

    element->setAttribute (Utils::XStr ("class"), Utils::XStr (type));
    impl.Accept (*this);
  }

  // Overwrite the default properties, if there are any.
  typedef std::set <PICML::AssemblyConfigProperty> ConfigProperty_Set;
  ConfigProperty_Set configs = component.dstAssemblyConfigProperty ();

  std::for_each (configs.begin (),
                 configs.end (),
                 boost::bind (&ConfigProperty_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  root->appendChild (element);
  this->root_.push (element);

  // Write the default properties to the XML document.
  std::for_each (this->default_props_.begin (),
                 this->default_props_.end (),
                 boost::bind (&QED_Deployment_Visitor::write_property,
                              this,
                              _1));

  // Get all the attributes for the component. We need to visit them
  // and add them to the XML document.
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attributes = component.Attribute_kind_children ();

  std::for_each (attributes.begin (),
                 attributes.end (),
                 boost::bind (&Attribute_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  this->root_.pop ();

  // Construct the filename for the XML document.
  std::ostringstream filename;
  filename << this->path_.top () << "/" << name << ".qic";

  // Serialize the XML to file.
  this->serialize_xml_to_file (filename.str ());
}

//
// Visit_Attribute
//
void QED_Deployment_Visitor::
Visit_Attribute (const PICML::Attribute & attr)
{
  PICML::AttributeValue attrval = attr.dstAttributeValue ();

  if (attrval != Udm::null)
  {
    // Create an XML element for the attribute.
    xercesc::DOMElement * element =
      this->doc_->createElement (Utils::XStr ("property"));

    element->setAttribute (Utils::XStr ("name"),
                           Utils::XStr (std::string (attr.name ())));

    // Insert the XML element into the document.
    this->root_.top ()->appendChild (element);

    // Save the element and visit the attribute value.
    this->root_.push (element);
    attrval.Accept (*this);
    this->root_.pop ();
  }
}

//
// Visit_AttributeValue
//
void QED_Deployment_Visitor::
Visit_AttributeValue (const PICML::AttributeValue & attrval)
{
  PICML::Property property = attrval.dstAttributeValue_end ();
  property.Accept (*this);
}

//
// Visit_Property
//
void QED_Deployment_Visitor::
Visit_Property (const PICML::Property & property)
{
  std::string value = property.DataValue ();

  this->root_.top ()->setAttribute (
    Utils::XStr ("value"),
    Utils::XStr (std::string (property.DataValue ())));
}

//
// Visit_ConfigProperty
//
void QED_Deployment_Visitor::
Visit_ConfigProperty (const PICML::ConfigProperty & config)
{
  PICML::Property property = config.dstConfigProperty_end ();

  // Store the default config property. It may get overwritten by
  // the assembly configuration.
  this->default_props_[property.name ()] = property.DataValue ();
}

//
// write_property
//
void QED_Deployment_Visitor::
write_property (const std::map <std::string, std::string>::value_type & property)
{
  // Create an XML element for the attribute.
  xercesc::DOMElement * element =
    this->doc_->createElement (Utils::XStr ("property"));

  element->setAttribute (
    Utils::XStr ("name"),
    Utils::XStr (property.first.c_str ()));

  element->setAttribute (
    Utils::XStr ("value"),
    Utils::XStr (property.second.c_str ()));

  this->root_.top ()->appendChild (element);
}

//
// Visit_MonolithicImplementation
//
void QED_Deployment_Visitor::
Visit_MonolithicImplementation (const PICML::MonolithicImplementation & impl)
{
  typedef std::set <PICML::ConfigProperty> ConfigProperty_Set;
  ConfigProperty_Set configs = impl.dstConfigProperty ();

  std::for_each (configs.begin (),
                 configs.end (),
                 boost::bind (&ConfigProperty_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_AssemblyConfigProperty
//
void QED_Deployment_Visitor::
Visit_AssemblyConfigProperty (const PICML::AssemblyConfigProperty & config)
{
  PICML::Property property = config.dstAssemblyConfigProperty_end ();

  // Overwrite the default configuration value, or store a new
  // configuration value.
  this->default_props_[property.name ()] = property.DataValue ();
}

//
// Visit_DeploymentPlans
//
void QED_Deployment_Visitor::
Visit_DeploymentPlans (const PICML::DeploymentPlans & folder)
{
  typedef std::vector <PICML::DeploymentPlan> DeploymentPlan_Set;
  DeploymentPlan_Set plans = folder.DeploymentPlan_children ();

  std::for_each (plans.begin (),
                 plans.end (),
                 boost::bind (&DeploymentPlan_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_DeploymentPlan
//
void QED_Deployment_Visitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Create the XML document.
  if (this->doc_ != 0)
    this->doc_->release();

  this->doc_ = this->impl_->createDocument (
    Utils::XStr ("http://www.dre.vanderbilt.edu/CUTS"),
    Utils::XStr ("jbi:deployment"),
    0);

  //this->doc_->setEncoding (Utils::XStr("UTF-8"));
  this->doc_->setXmlVersion (Utils::XStr("1.0"));

  xercesc::DOMElement * root = this->doc_->getDocumentElement ();

  root->setAttributeNS (
    Utils::XStr ("http://www.w3.org/2000/xmlns/"),
    Utils::XStr ("xmlns:xsi"),
    Utils::XStr ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttribute (
    Utils::XStr ("xsi:schemaLocation"),
    Utils::XStr ("http://www.dre.vanderbilt.edu/CUTS deployment.xsd"));

  // Create the UUID element for the deployment plan.
  xercesc::DOMElement * element =
    this->doc_->createElement (Utils::XStr ("UUID"));

  element->setTextContent (Utils::XStr (std::string (plan.UUID ())));
  root->appendChild (element);

  // Save the root element.
  this->root_.push (root);

  // Visit the node references in this file.
  typedef std::vector <PICML::NodeReference> NodeReference_Set;
  NodeReference_Set refs = plan.NodeReference_children ();

  std::for_each (refs.begin (),
                 refs.end (),
                 boost::bind (&NodeReference_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Construct the filename for the XML document.
  std::ostringstream filename;
  filename << this->path_.top () << "/" << plan.name () << ".qdp";

  // Serialize the XML document to a file.
  this->serialize_xml_to_file (filename.str ());

  this->root_.pop ();
}

//
// Visit_NodeReference
//
void QED_Deployment_Visitor::
Visit_NodeReference (const PICML::NodeReference & ref)
{
  PICML::Node node = ref.ref ();

  if (node != Udm::null)
    node.Accept (*this);

  // Visit all the mappings for this node.
  typedef std::set <PICML::InstanceMapping> InstanceMapping_Set;
  InstanceMapping_Set instance_mapping = ref.srcInstanceMapping ();

  std::for_each (instance_mapping.begin (),
                 instance_mapping.end (),
                 boost::bind (&InstanceMapping_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_Node
//
void QED_Deployment_Visitor::
Visit_Node (const PICML::Node & node)
{
  this->location_ = node.name ();

  PICML::Domain domain = node.Domain_parent ();
  domain.Accept (*this);
}

//
// Visit_Node
//
void QED_Deployment_Visitor::
Visit_Domain (const PICML::Domain & domain)
{
  //this->location_ += "." + std::string (domain.name ());
}

//
// Visit_InstanceMapping
//
void QED_Deployment_Visitor::
Visit_InstanceMapping (const PICML::InstanceMapping & mapping)
{
  PICML::CollocationGroup group = mapping.srcInstanceMapping_end ();
  group.Accept (*this);
}

//
// Visit_CollocationGroup
//
void QED_Deployment_Visitor::
Visit_CollocationGroup (const PICML::CollocationGroup & group)
{
  typedef
    std::set <PICML::CollocationGroupMember>
    CollocationGroupMember_Set;

  this->process_ = group.name ();
  CollocationGroupMember_Set members = group.members ();

  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&QED_Deployment_Visitor::Visit_CollocationGroupMember,
                              this, _1));
}

//
// Visit_CollocationGroupMember
//
void QED_Deployment_Visitor::
Visit_CollocationGroupMember (const PICML::CollocationGroupMember & member)
{
  Uml::Class metatype = member.type ();

  if (metatype == PICML::ComponentRef::meta)
  {
    PICML::ComponentRef comref = PICML::ComponentRef::Cast (member);
    comref.Accept (*this);
  }
  else if (metatype == PICML::ComponentAssemblyReference::meta)
  {

  }
  else
  {
    // we don't support other types right now
  }
}

//
// Visit_ComponentRef
//
void QED_Deployment_Visitor::
Visit_ComponentRef (const PICML::ComponentRef & ref)
{
  PICML::Component component = ref.ref ();

  // Create an XML element for the instance.
  xercesc::DOMElement * element_instance =
    this->doc_->createElement (Utils::XStr ("instance"));

  element_instance->setAttribute (
    Utils::XStr ("id"),
    Utils::XStr (this->instance_names_[component]));

  // Create an element for the location and add it to the document.
  xercesc::DOMElement * element =
    this->doc_->createElement (Utils::XStr ("location"));

  element->setTextContent (Utils::XStr (this->location_));
  element_instance->appendChild (element);

  // Create the element for the process.
  element = this->doc_->createElement (Utils::XStr ("process"));
  element->setTextContent (Utils::XStr (this->process_));
  element_instance->appendChild (element);

  // Add the instance to the main document.
  this->root_.top ()->appendChild (element_instance);
}

//
// serialize_xml_to_file
//
void QED_Deployment_Visitor::
serialize_xml_to_file (const std::string & filename)
{
  xercesc::LocalFileFormatTarget target (filename.c_str ());
  xercesc::DOMLSOutput * output = ((xercesc::DOMImplementationLS*)this->impl_)->createLSOutput ();
  output->setByteStream (&target);

  this->serializer_->write (this->doc_, output);
  output->release ();

  // Release the XML document.
  if (this->doc_ != 0)
  {
    this->doc_->release ();
    this->doc_ = 0;
  }
}
