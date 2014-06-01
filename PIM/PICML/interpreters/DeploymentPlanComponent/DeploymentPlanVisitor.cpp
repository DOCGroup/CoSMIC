// $Id$

#include "DeploymentPlanVisitor.h"

#include "Deployment_Domain_Visitor.h"

#include "Configuration.h"
#include "Data_Type_Visitor.h"
#include "Data_Value_Visitor.h"
#include "Connection_Visitor.h"
#include "External_Reference_Visitor.h"
#include "Connector_Visitor.h"
#include "Locality_Manager.h"

#include "Utils/udm/visit.h"
#include "Utils/UDM/Position_Sort_T.h"

#include "game/xml/Fragment.h"

#include "UmlExt.h"
#include "boost/bind.hpp"

#include <algorithm>
#include <functional>
#include <sstream>

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;
using xercesc::DOMElement;
using xercesc::DOMComment;

using GAME::Xml::String;
using GAME::Xml::Fragment;

//
// DeploymentPlanVisitor
//
DeploymentPlanVisitor::
DeploymentPlanVisitor (const Configuration & config)
: impl_ (0),
  doc_ (0),
  output_ (0),
  serializer_ (0),
  config_ (config)
{
  this->init ();
}

//
// ~DeploymentPlanVisitor
//
DeploymentPlanVisitor::~DeploymentPlanVisitor (void)
{
  if (this->output_)
    this->output_->release ();

  if (this->serializer_)
    this->serializer_->release ();
}

//
// init
//
void DeploymentPlanVisitor::init (void)
{
  this->impl_ = DOMImplementationRegistry::getDOMImplementation (L"LS");

  this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer ();
  this->output_ = ((DOMImplementationLS*)this->impl_)->createLSOutput ();

  // Set features if the serializer supports the feature/mode
  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
}

//
// init_document
//
void DeploymentPlanVisitor::init_document (const std::string& rootName)
{
  if (0 != this->doc_)
    this->doc_->release ();

  // Create the document
  this->doc_ = this->impl_->createDocument (String ("http://www.omg.org/Deployment"),
                                            String (rootName),
                                            0);

  this->doc_->setXmlVersion (String ("1.0"));
}

//
// Visit_RootFolder
//
void DeploymentPlanVisitor::
Visit_RootFolder (const PICML::RootFolder & rf)
{
  typedef std::set <PICML::DeploymentPlans> DeploymentPlans_Set;
  DeploymentPlans_Set folders = rf.DeploymentPlans_kind_children ();

  for(auto folder : folders)
	  folder.Accept(*this);
}

//
// Visit_DeploymentPlans
//
void DeploymentPlanVisitor::
Visit_DeploymentPlans (const PICML::DeploymentPlans & dps)
{
  typedef std::set <PICML::DeploymentPlan> DeploymentPlan_Set;
  DeploymentPlan_Set plans = dps.DeploymentPlan_kind_children ();

  for(auto plan : plans)
	  plan.Accept(*this);
}

//
// Visit_DeploymentPlan
//
void DeploymentPlanVisitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Start a new XML document for this deployment plan.
  this->init_document ("Deployment:DeploymentPlan");
  Fragment root (this->doc_->getDocumentElement ());

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:Deployment"),
                        String ("http://www.omg.org/Deployment"));

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:xsi"),
                        String ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:xmi"),
                        String ("http://www.omg.org/XMI"));

  root->setAttribute (String ("xsi:schemaLocation"),
                      String ("http://www.omg.org/Deployment Deployment.xsd"));

  root.create_simple_content ("label", String (plan.label ()));
  root.create_simple_content ("UUID", String (plan.UUID ()));

  // Visit all the nodes in the deployment plan. This will gather all
  // the necessary parts of the XML document. We do not process the
  // connections at this point because we want to wait until we have
  // all the deployed instances. This will make a life a little less
  // hectic in the long run.
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  for(auto node : nodes)
	  node.Accept(*this);

  // Finally, get all the connections. To simplify this problem, we
  // can look at the outbound connections and if there is a connection
  // on the other end and the target instance is deployed, then we can
  // include the connection in the final deployment.

  typedef std::map <PICML::ComponentInstance, xercesc::DOMElement *> inst_map_t;
  inst_map_t::iterator inst_iter, inst_iter_end = this->insts_.end ();

  Connection_Visitor cv (this->doc_, this->conns_, this->insts_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (cv);

  // Handle the external references.
  PICML_External_Reference_Visitor external (this->doc_, this->conns_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (external);

  // Handle the connections to connectors. We need to check if any
  // of the deployed instances has a connection to a connector since
  // connectors do not appear in the deployment model.
  Connector_Visitor connector_visitor (*this, this->conns_, this->doc_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (connector_visitor);

  // Append all the elements to this document in the correct order
  // so the deployment will be valid.

  // <implementation>
  for(auto & imp : impls_)
	  root.ptr ()->appendChild (imp.second);


  if (this->config_.has_locality_manager_)
    Locality_Manager::generate_default_implementation (root);

  // <instance>
  for(auto & insts : insts_)
	  root.ptr ()->appendChild (insts.second);

  for(auto & conn_insts : connector_insts_)
	  root.ptr ()->appendChild (conn_insts.second);

  for(auto & loc_insts : locality_insts_)
	  root.ptr ()->appendChild (loc_insts);

  // <connection>
  for(auto & conn : conns_)
	  root.ptr ()->appendChild (conn);

  // <artifact>
  for(auto & art : artifacts_)
	  root.ptr ()->appendChild (art.second);

  if (this->config_.has_locality_manager_)
    Locality_Manager::generate_default_artifacts (root);

  // <localityConstraint>
  for(auto & loc : locality_)
	  root.ptr ()->appendChild (loc.second);

  // Open the XML file for writing.
  std::ostringstream filename;
  filename << this->config_.output_ << "/" << plan.name () << ".cdp";
  LocalFileFormatTarget target (filename.str ().c_str ());

  // Write the document.
  this->output_->setByteStream (&target);
  this->serializer_->write (this->doc_, this->output_);
  this->output_->setByteStream (0);

  // Reset the generator's state.
  this->reset_state ();

  //call visitor that will generate the .cdd file
  Deployment_Domain_Visitor ddv (this->config_.output_);
  PICML::DeploymentPlan (plan).Accept (ddv);
}

//
// reset
//
void DeploymentPlanVisitor::reset_state (void)
{
  // Release the document.
  this->doc_->release ();
  this->doc_ = 0;

  // Reset all the state variables.
  this->insts_.clear ();
  this->connector_insts_.clear ();
  this->impls_.clear ();
  this->artifacts_.clear ();
  this->conns_.clear ();
  this->mappings_.clear ();
  this->locality_.clear ();
  this->locality_insts_.clear ();
}

//
// Visit_NodeReference
//
void DeploymentPlanVisitor::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  this->current_node_ = noderef;
  std::set <PICML::InstanceMapping> mapping = noderef.srcInstanceMapping () ;

  for(auto map : mapping)
	  map.Accept(*this);

}

//
// Visit_InstanceMapping
//
void DeploymentPlanVisitor::
Visit_InstanceMapping (const PICML::InstanceMapping & mapping)
{
  PICML::CollocationGroup group = mapping.srcInstanceMapping_end ();
  group.Accept (*this);
}

//
// Visit_CollocationGroup
//
void DeploymentPlanVisitor::
Visit_CollocationGroup (const PICML::CollocationGroup & group)
{
  // Start a new plan locality constraint (SameProcess).
  this->curr_locality_ = this->doc_->createElement (String ("localityConstraint"));
  this->current_group_ = group;

  this->curr_locality_.create_simple_content ("constraint", "SameProcess");
  this->locality_.insert (std::make_pair (group, this->curr_locality_.ptr ()));

  if (this->config_.has_locality_manager_)
  {
    const std::string group_name (group.name ());
    const std::string node_name (this->current_node_.name ());

    const std::string uuid = node_name + "." + group_name;

    // Create the locality manager instance.
    Fragment instance = this->doc_->createElement (String ("instance"));

    // Initialize the tags for this instance.
    instance->setAttribute (String ("xmi:id"), String (uuid));
    instance.create_simple_content ("name", uuid);
    instance.create_simple_content ("node", node_name);
    instance.create_simple_content ("source", "");

    Fragment impl = instance.create_element ("implementation");
    impl->setAttribute (String ("xmi:idref"), Locality_Manager::DEFAULT_IMPLEMENTATION_ID);

    Locality_Manager::generate_default_instance_configs (instance, group);

    // Generate the remaining configuration properties.
    this->param_parent_ = instance;

    std::set <PICML::CollocationGroupProperty> props = group.srcCollocationGroupProperty ();
	for(auto prop : props)
		prop.Accept(*this);

    // Save this element to the locality instances.
    this->locality_insts_.insert (instance);

    // Finally, make sure we add the locality manager to the current
    // locality collection.
    Fragment constrainedInstance = this->curr_locality_.create_element ("constrainedInstance");
    constrainedInstance->setAttribute (String ("xmi:idref"), String (uuid));
  }

  std::set <PICML::CollocationGroupMember> members = group.members ();

  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&CollocationGroupMember_Dispatcher::dispatch,
                              boost::ref (this->cgm_dispatcher_),
                              boost::ref (*this),
                              _1));
}

//
// Visit_CollocationGroupProperty
//
void DeploymentPlanVisitor::
Visit_CollocationGroupProperty (const PICML::CollocationGroupProperty & conn)
{
  this->curr_param_ = this->create_element (this->param_parent_, "configProperty");

  PICML::Property prop = conn.srcCollocationGroupProperty_end ();
  const Uml::Class & type = prop.type ();

  if (type == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (prop).Accept (*this);
  else if (type == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (prop).Accept (*this);
}

//
// Visit_ComponentInstanceRef
//
void DeploymentPlanVisitor::
Visit_ComponentInstanceRef (const PICML::ComponentInstanceRef & ref)
{
  PICML::ComponentInstance inst = ref.ref ();

  if (inst != Udm::null)
    inst.Accept (*this);
}

//
// Visit_ComponentInstance
//
void DeploymentPlanVisitor::
Visit_ComponentInstance (const PICML::ComponentInstance & inst)
{
  std::string uuid = "_" + std::string (inst.UUID ());
  std::string name = inst.getPath (".", false, true, "name", true);

  // Create a new instance in the XML document.
  this->curr_instance_ = this->doc_->createElement (String ("instance"));
  this->insts_.insert (std::make_pair (inst, this->curr_instance_.ptr ()));
  this->mappings_[inst] = this->current_group_;

  this->curr_instance_->setAttribute (String ("xmi:id"), String (uuid));
  this->curr_instance_.create_simple_content ("name", name);
  this->curr_instance_.create_simple_content ("node", String (this->current_node_.name ()));
  this->curr_instance_.create_simple_content ("source", "");

  // Insert this instance into the current locality and write a comment
  // that shows the constained instances name.
  // TODO make this a debugging feature.
  DOMComment * comment = this->doc_->createComment (String(name));
  this->curr_locality_->appendChild (comment);

  Fragment constrained = this->curr_locality_.create_element ("constrainedInstance");
  constrained->setAttribute (String ("xmi:idref"), String (uuid));

  // Visit this instance's implementation.
  PICML::ComponentInstanceType type = inst.ComponentInstanceType_child ();
  type.Accept (*this);

  this->param_parent_ = this->curr_instance_;

  // Finish writing the component instance information.
  CoSMIC::Udm::visit_all <PICML::AttributeInstance> (inst, *this);

  std::set <PICML::AssemblyConfigProperty> configs = inst.dstAssemblyConfigProperty ();
  for(auto conf : configs)
	  conf.Accept(*this);

  //@deployedResource
  //@deployedSharedResource
}

//
// Visit_ComponentInstanceType
//
void DeploymentPlanVisitor::
Visit_ComponentInstanceType (const PICML::ComponentInstanceType & type)
{
  // TODO Create a new instance in the XML document.
  PICML::MonolithicImplementation impl = type.ref ();

  if (impl != Udm::null)
    impl.Accept (*this);
}

//
// Visit_MonolithicImplementation
//
void DeploymentPlanVisitor::
Visit_MonolithicImplementation (const PICML::MonolithicImplementation & impl)
{
  this->Visit_MonolithicImplementationBase (impl);
}

//
// Visit_MonolithicImplementationBase
//
void DeploymentPlanVisitor::
Visit_MonolithicImplementationBase (const PICML::MonolithicImplementationBase & impl)
{
  // Add the implementation to the current instance.
  std::string uuid = std::string ("_") + std::string (impl.UUID ());

  Fragment element = this->curr_instance_.create_element ("implementation");
  element->setAttribute (String ("xmi:idref"), String (uuid));

  // Add all the configProperty elements to the current instance.
  this->param_parent_ = this->curr_instance_;

  std::set <PICML::ConfigProperty> configs = impl.dstConfigProperty ();
  for(auto conf : configs)
	  conf.Accept(*this);

  // There is no need to continue if we have already seen this
  // implementation before.
  if (this->impls_.find (impl) != this->impls_.end ())
    return;

  // Since we have not seen this implementation before, we need to
  // create a new XML element for it.
  this->curr_impl_ = this->doc_->createElement (String ("implementation"));
  this->impls_.insert (std::make_pair (impl, this->curr_impl_.ptr ()));

  this->curr_impl_->setAttribute (String ("xmi:id"), String (uuid));

  std::string name = impl.getPath (".", false, true, "name", true);
  this->curr_impl_.create_simple_content ("name", name);
  this->curr_impl_.create_simple_content ("source", "");

  // The next part of this element is the artifacts. Therefore, visit
  // all the primary artifacts for this component.
  std::set <PICML::MonolithprimaryArtifact> mpas = impl.dstMonolithprimaryArtifact ();
  for(auto mpa : mpas)
	  mpa.Accept(*this);

  // Set the property parameter's parent.
  this->param_parent_ = this->curr_impl_;

  // Write the executor parameters for the required artifacts. This
  // should never be null, but just in case... :-)
  if (Udm::null != this->impl_artifact_)
  {
    this->impl_artifact_.Accept (*this);
    this->impl_artifact_ = PICML::ComponentImplementationArtifact ();
  }

  if (Udm::null != this->svnt_artifact_)
  {
    this->svnt_artifact_.Accept (*this);
    this->svnt_artifact_ = PICML::ComponentServantArtifact ();
  }

  // The last part of this section of the XML document are the
  // executor parameters. So, let's visit all the monolithic executor
  // parameters for this implementation.
  std::set <PICML::MonolithExecParameter> mexecs = impl.dstMonolithExecParameter ();

  for(auto mexec : mexecs)
	  mexec.Accept(*this);

  // @deployRequirement
}

//
// Visit_MonolithprimaryArtifact
//
void DeploymentPlanVisitor::
Visit_MonolithprimaryArtifact (const PICML::MonolithprimaryArtifact & mpa)
{
  PICML::ImplementationArtifactReference iaref = mpa.dstMonolithprimaryArtifact_end ();
  iaref.Accept (*this);
}

//
// Visit_ImplementationArtifactReference
//
void DeploymentPlanVisitor::
Visit_ImplementationArtifactReference (const PICML::ImplementationArtifactReference & ref)
{
  // Determine if this is a servant or executor artifact. If we find
  // one, then we save it since it will be used later on.
  if (PICML::ComponentImplementationArtifact::meta == ref.type ())
    this->impl_artifact_ = PICML::ComponentImplementationArtifact::Cast (ref);
  else if (PICML::ComponentServantArtifact::meta == ref.type ())
    this->svnt_artifact_ = PICML::ComponentServantArtifact::Cast (ref);

  // Now, let's continue down the line. ;-)
  PICML::ImplementationArtifact artifact = ref.ref ();

  if (artifact != Udm::null)
    artifact.Accept (*this);
}

//
// Visit_ImplementationArtifact
//
void DeploymentPlanVisitor::
Visit_ImplementationArtifact (const PICML::ImplementationArtifact & artifact)
{
  std::string uuid = std::string ("_") + std::string (artifact.UUID ());

  // Add this artifact's id to the current implementation.
  Fragment element = this->curr_impl_.create_element ("artifact");
  element->setAttribute (String ("xmi:idref"), String (uuid));

  // There is no need to continue if we have already seen this
  // artifact. Otherwise, we will overwrite the existing one.
  if (this->artifacts_.find (artifact) != this->artifacts_.end ())
    return;

  // We should go ahead and create a new artifact element for
  // the XML document.
  this->curr_artifact_ = this->doc_->createElement (String ("artifact"));
  this->artifacts_.insert (std::make_pair (artifact, this->curr_artifact_.ptr ()));

  this->curr_artifact_->setAttribute (String ("xmi:id"), String (uuid));
  std::string name = artifact.getPath (".", false, true, "name", true);

  this->curr_artifact_.create_simple_content ("name", name);
  this->curr_artifact_.create_simple_content ("source", "");
  this->curr_artifact_.create_simple_content ("node", "");
  this->curr_artifact_.create_simple_content ("location", String (artifact.location ()));

  // Let's generate the artifact exec parameters.
  this->param_parent_ = this->curr_artifact_;

  std::set <PICML::ArtifactExecParameter> params = artifact.dstArtifactExecParameter ();
  for(auto param : params)
	  param.Accept(*this);

  // Finally, make sure we include all the artifact dependencies.
  std::set <PICML::ArtifactDependency> dependencies = artifact.srcArtifactDependency ();
  for(auto dependency : dependencies)
	  dependency.Accept(*this);

  // @deployRequirement
  // @deployedResource
}


//
// Visit_MonolithExecParameter
//
void DeploymentPlanVisitor::
Visit_MonolithExecParameter (const PICML::MonolithExecParameter & mexec)
{
  // First, lets create a new executor parameter now since
  // we will not be able to tell what type it is once we reach
  // the property.
  this->curr_param_ = this->param_parent_.create_element ("execParameter");
  PICML::Property prop = mexec.dstMonolithExecParameter_end ();

  if (prop.type () == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (prop).Accept (*this);
  else if (prop.type () == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (prop).Accept (*this);
}

//
// Visit_ArtifactDependsOn
//
void DeploymentPlanVisitor::
Visit_ArtifactDependsOn (const PICML::ArtifactDependsOn& ado)
{
  PICML::ImplementationArtifactReference ref = ado.dstArtifactDependsOn_end ();
  ref.Accept (*this);
}

//
// Visit_ArtifactExecParameter
//
void DeploymentPlanVisitor::
Visit_ArtifactExecParameter (const PICML::ArtifactExecParameter& param)
{
  this->curr_param_ = this->param_parent_.create_element ("execParameter");
  PICML::Property prop = param.dstArtifactExecParameter_end ();

  if (prop.type () == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (prop).Accept (*this);
  else if (prop.type () == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (prop).Accept (*this);
}

//
// Visit_ConnectorInstance
//
void DeploymentPlanVisitor::
deploy_connector_fragment (const PICML::ConnectorInstance & inst,
                           const PICML::CollocationGroup & group)
{
  std::string uuid = "_" + std::string (inst.UUID ());
  std::string name = inst.getPath (".", false, true, "name", true);

  // Insert this instance into the current locality.
  Fragment locality (this->locality_[group]);

  if (0 != locality)
  {
    // Write a comment that shows the constained instances name.
    // TODO make this a debugging feature.
    DOMComment * comment = this->doc_->createComment (String (name));
    locality->appendChild (comment);

    Fragment constrained = locality.create_element ("constrainedInstance");
    constrained->setAttribute (String ("xmi:idref"), String (uuid));
  }

  // Get the target node's name for this instance
  PICML::InstanceMapping mapping = group.dstInstanceMapping ();
  PICML::NodeReference noderef = mapping.dstInstanceMapping_end ();

  // Create a new instance in the XML document.
  this->curr_instance_ = this->doc_->createElement (String ("instance"));
  this->connector_insts_.insert (std::make_pair (uuid, this->curr_instance_.ptr ()));

  this->curr_instance_->setAttribute (String ("xmi:id"), String (uuid));
  this->curr_instance_.create_simple_content ("name", name);
  this->curr_instance_.create_simple_content ("node", String (noderef.name ()));
  this->curr_instance_.create_simple_content ("source", "");

  // Visit this instance's implementation.
  PICML::ConnectorImplementationType cit = inst.ConnectorImplementationType_child ();

  if (cit != Udm::null)
    cit.Accept (*this);

  this->param_parent_ = this->curr_instance_;

  // Finish writing the component instance information.
  CoSMIC::Udm::visit_all <PICML::AttributeInstance> (inst, *this);

  std::set <PICML::AssemblyConfigProperty> configs = inst.dstAssemblyConfigProperty ();
  for(auto config : configs)
	  config.Accept(*this);
}

//
// Visit_ConnectorImplementationType
//
void DeploymentPlanVisitor::
Visit_ConnectorImplementationType (const PICML::ConnectorImplementationType & cit)
{
  PICML::ConnectorImplementation impl = cit.ref ();

  if (impl != Udm::null)
    impl.Accept (*this);
}

//
// Visit_ConnectorImplementation
//
void DeploymentPlanVisitor::
Visit_ConnectorImplementation (const PICML::ConnectorImplementation & impl)
{
  this->Visit_MonolithicImplementationBase (impl);
}

//
// Visit_SimpleProperty
//
void DeploymentPlanVisitor::
Visit_SimpleProperty (const PICML::SimpleProperty & prop)
{
  // Start with the name of the property.
  std::string name = prop.name ();

  if (name == "InstanceIOR")
    name = "edu.vanderbilt.dre.DAnCE.InstanceIOR";
  else if (name == "RegisterNaming")
    name = "edu.vanderbilt.dre.DAnCE.RegisterNaming";
  else if (name == "LocalityArguments")
    name = "edu.vanderbilt.dre.DAnCE.LocalityArguments";
  else if (name == "CPUAffinity")
    name = "edu.vanderbilt.dre.DAnCE.LocalityManager.CPUAffinity";
  else if (name == "ProcessPriority")
    name = "edu.vanderbilt.dre.DAnCE.LocalityManager.ProcessPriority";

  PICML_Data_Type_Dispatcher dt_dispatcher;

  this->curr_param_.create_simple_content ("name", name);
  Fragment value = this->curr_param_.create_element ("value");

  // First, we need to generate the type for this property
  PICML_Data_Type_Visitor dtv (value);
  PICML_Data_Value_Visitor dvv (value);

  // Write the data type for the property.
  dt_dispatcher.dispatch (dtv, prop.ref ());

  // Generate the value for the property.
  PICML::SimpleProperty::Cast (prop).Accept (dvv);
}

//
// Visit_ComplexProperty
//
void DeploymentPlanVisitor::
Visit_ComplexProperty (const PICML::ComplexProperty & prop)
{
  // Start with the name of the property.
  std::string name = prop.name ();

  PICML_Data_Type_Dispatcher dt_dispatcher;

  this->create_simple_content (this->curr_param_, "name", name);
  xercesc::DOMElement * value = this->create_element (this->curr_param_, "value");

  // First, we need to generate the type for this property
  PICML_Data_Type_Visitor dtv (value);
  PICML_Data_Value_Visitor dvv (value);
  PICML::ComplexTypeReference complex = prop.ComplexTypeReference_child ();

  // visit the ComplexType reference in this container.
  dt_dispatcher.dispatch (dtv, complex.ref ());

  // Generate the value for the property.
  PICML::ComplexProperty::Cast (prop).Accept (dvv);
}

//
// Visit_DataType
//
void DeploymentPlanVisitor::
Visit_DataType (const PICML::DataType& type)
{
  // Prepare the datatype visitor.
  PICML_Data_Type_Visitor dtv (this->curr_value_);

  // Visit the concrete data type.
  PICML::MemberType mt = type.ref ();
  this->datatypes_.dispatch (dtv, mt);
}

//
// Visit_ComponentImplementationArtifact
//
void DeploymentPlanVisitor::
Visit_ComponentImplementationArtifact (const PICML::ComponentImplementationArtifact & cia)
{
  this->write_artifact_execParameter ("component factory", cia.EntryPoint ());

  PICML::ImplementationArtifact ia = cia.ref ();

  if (Udm::null != ia)
  {
    std::string id = ia.getPath (".", false, true, "name", true);
    this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ExecutorArtifact", id);
  }
}

//
// Visit_ComponentServantArtifact
//
void DeploymentPlanVisitor::
Visit_ComponentServantArtifact (const PICML::ComponentServantArtifact & csa)
{
  this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ServantEntrypoint",
                                      csa.EntryPoint ());

  PICML::ImplementationArtifact ia = csa.ref ();

  if (Udm::null != ia)
  {
    std::string id = ia.getPath (".", false, true, "name", true);
    this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ServantArtifact", id);
  }
}


// write_artifact_execParameter
//
void DeploymentPlanVisitor::
write_artifact_execParameter (const std::string & name, const std::string & value)
{
  DOMElement * param = this->create_element (this->param_parent_, "execParameter");
  this->create_simple_content (param, "name", name);

  DOMElement * val = this->create_element (param, "value");
  DOMElement * type  = this->create_element (val, "type");
  this->create_simple_content (type, "kind", "tk_string");

  val = this->create_element (val, "value");
  this->create_simple_content (val, "string", value);
}

//
// Visit_ConfigProperty
//
void DeploymentPlanVisitor::
Visit_ConfigProperty (const PICML::ConfigProperty & cp)
{
  this->curr_param_ = this->create_element (this->param_parent_, "configProperty");

  PICML::Property ref = cp.dstConfigProperty_end ();

  if (ref.type () == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (ref).Accept (*this);
  else if (ref.type () == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (ref).Accept (*this);
}

//
// Visit_AttributeInstance
//
void DeploymentPlanVisitor::
Visit_AttributeInstance (const PICML::AttributeInstance & attr)
{
  PICML::AttributeValue attValue = attr.dstAttributeValue ();

  if (attValue != Udm::null)
    attValue.Accept (*this);
}

//
// Visit_AttributeValue
//
void DeploymentPlanVisitor::
Visit_AttributeValue (const PICML::AttributeValue & v)
{
  this->curr_param_ = this->create_element (this->param_parent_, "configProperty");

  PICML::Property prop = v.dstAttributeValue_end ();

  if (prop.type () == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (prop).Accept (*this);
  else if (prop.type () == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (prop).Accept (*this);
}

//
// Visit_AssemblyConfigProperty
//
void DeploymentPlanVisitor::
Visit_AssemblyConfigProperty (const PICML::AssemblyConfigProperty & acp)
{
  this->curr_param_ = this->create_element (this->param_parent_, "configProperty");

  PICML::Property ref = acp.dstAssemblyConfigProperty_end ();

  if (ref.type () == PICML::SimpleProperty::meta)
    PICML::SimpleProperty::Cast (ref).Accept (*this);
  else if (ref.type () == PICML::ComplexProperty::meta)
    PICML::ComplexProperty::Cast (ref).Accept (*this);
}

//
// localities
//
const DeploymentPlanVisitor::locality_t & DeploymentPlanVisitor::localities (void) const
{
  return this->locality_;
}

//
// mappings
//
const std::map <PICML::ComponentInstance, PICML::CollocationGroup> &
DeploymentPlanVisitor::mappings (void) const
{
  return this->mappings_;
}

//
// Visit_ComponentAssemblyReference
//
void DeploymentPlanVisitor::
Visit_ComponentAssemblyReference (const PICML::ComponentAssemblyReference & ref)
{
  PICML::ComponentAssembly inst = ref.ref ();

  if (inst != Udm::null)
    inst.Accept (*this);
}

//
// Visit_ComponentAssembly
//
void DeploymentPlanVisitor::
Visit_ComponentAssembly (const PICML::ComponentAssembly & assembly)
{
  // Visit all the component instances in this assembly.
  std::vector <PICML::ComponentInstance> insts = assembly.ComponentInstance_children ();

  for(auto inst : insts)
	  inst.Accept(*this);

  // Visit all the component assemblies in this assembly.
  std::vector <PICML::ComponentAssembly> assemblies = assembly.ComponentAssembly_children ();

  for(auto assembly : assemblies)
	  assembly.Accept(*this);
}
