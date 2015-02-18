#include "StdAfx.h"

#include "Deployment_Plan_Visitor.h"
#include "Deployment_Domain_Visitor.h"
#include "Configuration.h"
#include "Connection_Visitor.h"
#include "External_Reference_Visitor.h"
#include "Connector_Visitor.h"
#include "Locality_Manager.h"

#include "../../xml/Data_Type_Visitor.h"
#include "../../xml/Data_Value_Visitor.h"

#include "game/xml/Fragment.h"

#include <sstream>

namespace PICML
{
namespace Deployment
{

Deployment_Plan_Visitor::Deployment_Plan_Visitor (const Configuration & config)
: config_ (config)
{

}

Deployment_Plan_Visitor::~Deployment_Plan_Visitor (void)
{

}

void Deployment_Plan_Visitor::
begin_document (const std::string & uuid, const std::string & label)
{
  using namespace xercesc;

  // Create a new document for the domain. This also requires initializing
  // its attributes.
  this->document_.create ("http://www.omg.org/Deployment", "Deployment:DeploymentPlan");
  GAME::Xml::Fragment root = this->document_.root ();

  root->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                        GAME::Xml::String ("xmlns:Deployment"),
                        GAME::Xml::String ("http://www.omg.org/Deployment"));

  root->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                        GAME::Xml::String ("xmlns:xsi"),
                        GAME::Xml::String ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                        GAME::Xml::String ("xmlns:xmi"),
                        GAME::Xml::String ("http://www.omg.org/XMI"));

  root->setAttribute (GAME::Xml::String ("xsi:schemaLocation"),
                      GAME::Xml::String ("http://www.omg.org/Deployment Deployment.xsd"));

  // Attach the <label> to the root element.
  if (!label.empty ())
    root.create_simple_content ("label", label);

  // Attach the <UUID> to the root element. We generate a UUID if
  // one is not present.
  if (uuid.empty ())
    root.create_simple_content ("UUID", uuid);
}

void Deployment_Plan_Visitor::write_document (const std::string & basename)
{
  std::ostringstream filename;
  filename << this->config_.output_ << "/" << basename << ".cdp";

  using namespace xercesc;

  // Write the XML document to a file.  
  DOMLSSerializer * serializer = this->document_.impl ()->createLSSerializer ();

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);

  serializer->writeToURI (this->document_.root (), GAME::Xml::String (filename.str ()));
  serializer->release ();
}

void Deployment_Plan_Visitor::
visit_RootFolder (PICML::RootFolder_in rf)
{
  for (PICML::DeploymentPlans plans : rf->get_DeploymentPlans ())
    plans->accept (this);
}

void Deployment_Plan_Visitor::
visit_DeploymentPlans (PICML::DeploymentPlans_in dps)
{
  for (PICML::DeploymentPlan plan : dps->get_DeploymentPlans ())
    plan->accept (this);
}

void Deployment_Plan_Visitor::
visit_DeploymentPlan (PICML::DeploymentPlan_in plan)
{
  // Start a new XML document for this deployment plan.
  this->begin_document (plan->UUID (), plan->label ());

  // Visit all the nodes in the deployment plan. This will gather all
  // the necessary parts of the XML document. We do not process the
  // connections at this point because we want to wait until we have
  // all the deployed instances. This will make a life a little less
  // hectic in the long run.
  for (PICML::NodeReference noderef : plan->get_NodeReferences ())
    noderef->accept (this);

  // Finally, get all the connections. To simplify this problem, we
  // can look at the outbound connections and if there is a connection
  // on the other end and the target instance is deployed, then we can
  // include the connection in the final deployment.
  Connection_Visitor cv (this->document_.root (), this->conns_, this->insts_);

  for (auto entry : this->insts_)
    entry.first->accept (&cv);

  // Handle the external references.
  External_Reference_Visitor external (this->document_.root (), this->conns_);

  for (auto entry : this->insts_)
    entry.first->accept (&external);

  // Handle the connections to connectors. We need to check if any
  // of the deployed instances has a connection to a connector since
  // connectors do not appear in the deployment model.
  Connector_Visitor connector_visitor (this, this->document_.root (), this->conns_);

  for (auto entry : this->insts_)
    entry.first->accept (&connector_visitor);

  // Append all the elements to this document in the correct order
  // so the deployment will be valid.

  // <implementation>
  for (auto impl : this->impls_)
    this->document_.append (impl.second);

  if (this->config_.has_locality_manager_)
    Locality_Manager::generate_default_implementation (this->document_.root ());

  // <instance>
  for (auto insts : this->insts_)
    this->document_.append (insts.second);

  for (auto connector : this->connector_insts_)
    this->document_.append (connector.second);

  for (auto locality : this->locality_insts_)
    this->document_.append (locality);

  // <connection>
  for (auto connection : this->conns_)
    this->document_.append (connection);

  // <artifact>
  for (auto artifact : this->artifacts_)
    this->document_.append (artifact.second);

  if (this->config_.has_locality_manager_)
    Locality_Manager::generate_default_artifacts (this->document_.root ());

  // <localityConstraint>
  for (auto locality : this->locality_)
    this->document_.append (locality.second);

  // Reset the generator's state.
  this->write_document (plan->name ());
  this->reset_state ();

  //call visitor that will generate the .cdd file
  Deployment_Domain_Visitor ddv (this->config_.output_);
  plan->accept (&ddv);
}

void Deployment_Plan_Visitor::reset_state (void)
{
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

void Deployment_Plan_Visitor::
visit_NodeReference (PICML::NodeReference_in noderef)
{
  this->current_node_ = noderef;

  for (PICML::InstanceMapping mapping : noderef->dst_of_InstanceMapping ())
    mapping->accept (this);
}

void Deployment_Plan_Visitor::
visit_InstanceMapping (PICML::InstanceMapping_in mapping)
{
  mapping->src_CollocationGroup ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_CollocationGroup (PICML::CollocationGroup_in group)
{
  using GAME::Xml::String;

  // Start a new plan locality constraint (SameProcess).
  this->curr_locality_ = this->document_.create_element ("localityConstraint");
  this->current_group_ = group;

  this->curr_locality_.create_simple_content ("constraint", "SameProcess");
  this->locality_.insert (std::make_pair (group, this->curr_locality_.ptr ()));

  if (this->config_.has_locality_manager_)
  {
    const std::string group_name (group->name ());
    const std::string node_name (this->current_node_->name ());

    const std::string uuid = node_name + "." + group_name;

    // Create the locality manager instance.
    GAME::Xml::Fragment instance = this->document_.create_element ("instance");

    // Initialize the tags for this instance.
    instance.set_attribute ("xmi:id", uuid);
    instance.create_simple_content ("name", uuid);
    instance.create_simple_content ("node", node_name);
    instance.create_simple_content ("source", "");

    GAME::Xml::Fragment impl = instance.create_element ("implementation");
    impl.set_attribute ("xmi:idref", Locality_Manager::DEFAULT_IMPLEMENTATION_ID);

    Locality_Manager::generate_default_instance_configs (instance, group);

    // Generate the remaining configuration properties.
    this->param_parent_ = instance;

    for (PICML::CollocationGroupProperty prop : group->dst_of_CollocationGroupProperty ())
      prop->accept (this);

    // Save this element to the locality instances.
    this->locality_insts_.insert (instance);

    // Finally, make sure we add the locality manager to the current
    // locality collection.
    GAME::Xml::Fragment constrainedInstance = this->curr_locality_.create_element ("constrainedInstance");
    constrainedInstance.set_attribute ("xmi:idref", uuid);
  }

  for (PICML::CollocationGroupMember member : group->members_CollocationGroupMember ())
    member->accept (this);
}

void Deployment_Plan_Visitor::
visit_CollocationGroupProperty (PICML::CollocationGroupProperty_in conn)
{
  this->curr_param_ = this->param_parent_.create_element ("configProperty");
  conn->src_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ComponentInstanceRef (PICML::ComponentInstanceRef_in ref)
{
  ref->refers_to_ComponentInstance ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ComponentInstance (PICML::ComponentInstance_in inst)
{
  using GAME::Xml::String;

  std::string uuid = "_" + std::string (inst->UUID ());
  std::string name = inst->path (".", false);

  // Create a new instance in the XML document.
  this->curr_instance_ = this->document_.create_element ("instance");
  this->insts_.insert (std::make_pair (inst, this->curr_instance_.ptr ()));
  this->mappings_[inst] = this->current_group_;

  this->curr_instance_.set_attribute ("xmi:id", uuid);
  this->curr_instance_.create_simple_content ("name", name);
  this->curr_instance_.create_simple_content ("node", String (this->current_node_->name ()));
  this->curr_instance_.create_simple_content ("source", "");

  // Insert this instance into the current locality and write a comment
  // that shows the constained instances name.
  // TODO make this a debugging feature.
  xercesc::DOMComment * comment = this->document_->createComment (String (name));
  this->curr_locality_->appendChild (comment);

  GAME::Xml::Fragment constrained = this->curr_locality_.create_element ("constrainedInstance");
  constrained.set_attribute ("xmi:idref", uuid);

  // Visit this instance's implementation.
  inst->get_ComponentInstanceType ()->accept (this);
  this->param_parent_ = this->curr_instance_;

  // Finish writing the component instance information.
  for (PICML::AttributeInstance attr_inst : inst->get_AttributeInstances ())
    attr_inst->accept (this);

  for (PICML::AssemblyConfigProperty config : inst->src_of_AssemblyConfigProperty ())
    config->accept (this);

  //@deployedResource
  //@deployedSharedResource
}

void Deployment_Plan_Visitor::
visit_ComponentInstanceType (PICML::ComponentInstanceType_in type)
{
  // TODO Create a new instance in the XML document.
  type->refers_to_MonolithicImplementation ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_MonolithicImplementation (PICML::MonolithicImplementation_in impl)
{
  this->visit_MonolithicImplementationBase (impl);
}

void Deployment_Plan_Visitor::
visit_MonolithicImplementationBase (PICML::MonolithicImplementationBase_in impl)
{
  using GAME::Xml::String;

  // Add the implementation to the current instance.
  std::string uuid = std::string ("_") + std::string (impl->UUID ());

  GAME::Xml::Fragment element = this->curr_instance_.create_element ("implementation");
  element.set_attribute ("xmi:idref", uuid);

  // Add all the configProperty elements to the current instance.
  this->param_parent_ = this->curr_instance_;

  for (PICML::ConfigProperty config : impl->src_of_ConfigProperty ())
    config->accept (this);

  // There is no need to continue if we have already seen this
  // implementation before.
  if (this->impls_.find (impl) != this->impls_.end ())
    return;

  // Since we have not seen this implementation before, we need to
  // create a new XML element for it.
  this->curr_impl_ = this->document_.create_element ("implementation");
  this->impls_.insert (std::make_pair (impl, this->curr_impl_.ptr ()));
  this->curr_impl_.set_attribute ("xmi:id", uuid);

  std::string name = impl->path (".", false);
  this->curr_impl_.create_simple_content ("name", name);
  this->curr_impl_.create_simple_content ("source", "");

  // The next part of this element is the artifacts. Therefore, visit
  // all the primary artifacts for this component.
  for (PICML::MonolithprimaryArtifact artifact : impl->src_of_MonolithprimaryArtifact ())
    artifact->accept (this);

  // Set the property parameter's parent.
  this->param_parent_ = this->curr_impl_;

  // Write the executor parameters for the required artifacts. This
  // should never be null, but just in case... :-)
  this->impl_artifact_->accept (this);
  this->impl_artifact_ = 0;

  this->svnt_artifact_->accept (this);
  this->svnt_artifact_ = 0;

  // The last part of this section of the XML document are the
  // executor parameters. So, let's visit all the monolithic executor
  // parameters for this implementation.
  for (PICML::MonolithExecParameter param : impl->src_of_MonolithExecParameter ())
    param->accept (this);

  // @deployRequirement
}

void Deployment_Plan_Visitor::
visit_MonolithprimaryArtifact (PICML::MonolithprimaryArtifact_in mpa)
{
  mpa->dst_ImplementationArtifactReference ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ImplementationArtifactReference (PICML::ImplementationArtifactReference_in ref)
{
  // Determine if this is a servant or executor artifact. If we find
  // one, then we save it since it will be used later on.
  const std::string metaname (ref->meta ()->name ());
  if (metaname == PICML::ComponentImplementationArtifact::impl_type::metaname)
    this->impl_artifact_ = PICML::ComponentImplementationArtifact::_narrow (ref);
  else if (metaname == PICML::ComponentServantArtifact::impl_type::metaname)
    this->svnt_artifact_ = PICML::ComponentServantArtifact::_narrow (ref);

  // Now, let's continue down the line. ;-)
  ref->refers_to_ImplementationArtifact ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ImplementationArtifact (PICML::ImplementationArtifact_in artifact)
{
  using GAME::Xml::String;

  std::string uuid = std::string ("_") + std::string (artifact->UUID ());

  // Add this artifact's id to the current implementation.
  GAME::Xml::Fragment element = this->curr_impl_.create_element ("artifact");
  element.set_attribute ("xmi:idref", uuid);

  // There is no need to continue if we have already seen this
  // artifact. Otherwise, we will overwrite the existing one.
  if (this->artifacts_.find (artifact) != this->artifacts_.end ())
    return;

  // We should go ahead and create a new artifact element for
  // the XML document.
  this->curr_artifact_ = this->document_.create_element ("artifact");
  this->artifacts_.insert (std::make_pair (artifact, this->curr_artifact_.ptr ()));

  this->curr_artifact_.set_attribute ("xmi:id", String (uuid));
  std::string name = artifact->path (".", false);

  this->curr_artifact_.create_simple_content ("name", name);
  this->curr_artifact_.create_simple_content ("source", "");
  this->curr_artifact_.create_simple_content ("node", "");
  this->curr_artifact_.create_simple_content ("location", String (artifact->location ()));

  // Let's generate the artifact exec parameters.
  this->param_parent_ = this->curr_artifact_;

  for (PICML::ArtifactExecParameter param : artifact->src_of_ArtifactExecParameter ())
    param->accept (this);

  // Finally, make sure we include all the artifact dependencies.
  for (PICML::ArtifactDependency dependency : artifact->dst_of_ArtifactDependency ())
    dependency->accept (this);

  // @deployRequirement
  // @deployedResource
}

void Deployment_Plan_Visitor::
visit_MonolithExecParameter (PICML::MonolithExecParameter_in mexec)
{
  // First, lets create a new executor parameter now since
  // we will not be able to tell what type it is once we reach
  // the property.
  this->curr_param_ = this->param_parent_.create_element ("execParameter");
  mexec->dst_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ArtifactDependsOn (PICML::ArtifactDependsOn_in ado)
{
  ado->dst_ImplementationArtifactReference ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ArtifactExecParameter (PICML::ArtifactExecParameter_in param)
{
  this->curr_param_ = this->param_parent_.create_element ("execParameter");
  param->dst_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
deploy_connector_fragment (PICML::ConnectorInstance_in connector,
                           PICML::ComponentInstance_in component)
{
  try
  {
    using GAME::Xml::String;

    // Find the group associated with the component instance since the
    // connector instance must be deployed in that group as well.
    PICML::CollocationGroup group = this->mappings_.at (component);

    std::string uuid = "_" + connector->UUID ();
    std::string name = connector->path (".", false);

    try
    {
      // Insert this instance into the current locality.
      GAME::Xml::Fragment locality = this->locality_.at (group);
     
      // Write a comment that shows the constained instances name.
      // TODO make this a debugging feature.
      xercesc::DOMComment * comment = this->document_->createComment (String (name));
      locality->appendChild (comment);

      GAME::Xml::Fragment constrained = locality.create_element ("constrainedInstance");
      constrained.set_attribute ("xmi:idref", uuid);
    }
    catch (const std::out_of_range &)
    {
      // We could not find a locality for the group.
    }

    // Get the target node's name for this instance
    PICML::InstanceMapping mapping = group->src_of_InstanceMapping ().first ();
    PICML::NodeReference noderef = mapping->dst_NodeReference ();

    // Create a new instance in the XML document.
    this->curr_instance_ = this->document_.create_element ("instance");
    this->connector_insts_.insert (std::make_pair (uuid, this->curr_instance_.ptr ()));

    this->curr_instance_.set_attribute ("xmi:id", uuid);
    this->curr_instance_.create_simple_content ("name", name);
    this->curr_instance_.create_simple_content ("node", String (noderef->name ()));
    this->curr_instance_.create_simple_content ("source", "");

    // Visit this instance's implementation.
    if (connector->has_ConnectorImplementationType ())
      connector->get_ConnectorImplementationType ()->accept (this);

    this->param_parent_ = this->curr_instance_;

    // Finish writing the component instance information.
    for (PICML::AttributeInstance attr_inst : connector->get_AttributeInstances ())
      attr_inst->accept (this);

    for (PICML::AssemblyConfigProperty prop : connector->src_of_AssemblyConfigProperty ())
      prop->accept (this);
  }
  catch (const std::out_of_range &)
  {
    // Cannot locate mapping for component instance.
  }
}

void Deployment_Plan_Visitor::
visit_ConnectorImplementationType (PICML::ConnectorImplementationType_in cit)
{
  cit->refers_to_ConnectorImplementation ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ConnectorImplementation (PICML::ConnectorImplementation_in impl)
{
  this->visit_MonolithicImplementationBase (impl);
}

void Deployment_Plan_Visitor::
visit_SimpleProperty (PICML::SimpleProperty_in prop)
{
  // Start with the name of the property.
  std::string name = prop->name ();

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

  this->curr_param_.create_simple_content ("name", name);
  GAME::Xml::Fragment value = this->curr_param_.create_element ("value");

  // First, we need to generate the type for this property
  PICML::Xml::Data_Type_Visitor dtv (value);
  prop->accept (&dtv);

  // Now, we can generate the value for the property.
  PICML::Xml::Data_Value_Visitor dvv (value);
  prop->accept (&dvv);
}

void Deployment_Plan_Visitor::
visit_ComplexProperty (PICML::ComplexProperty_in prop)
{
  // Create the XML fragment for the property.
  this->curr_param_.create_simple_content ("name", prop->name ());
  GAME::Xml::Fragment value = this->curr_param_.create_element ("value");

  // First, we need to generate the type for this property
  PICML::Xml::Data_Type_Visitor dtv (value);
  prop->accept (&dtv);

  // Now, we can generate the value for the property.
  PICML::Xml::Data_Value_Visitor dvv (value);
  prop->accept (&dvv);
}

void Deployment_Plan_Visitor::
visit_ComponentImplementationArtifact (PICML::ComponentImplementationArtifact_in cia)
{
  this->write_artifact_execParameter ("component factory", cia->EntryPoint ());
  PICML::ImplementationArtifact ia = cia->refers_to_ImplementationArtifact ();

  if (ia)
  {
    std::string id = ia->path (".", false);
    this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ExecutorArtifact", id);
  }
}

void Deployment_Plan_Visitor::
visit_ComponentServantArtifact (PICML::ComponentServantArtifact_in csa)
{
  this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ServantEntrypoint", csa->EntryPoint ());
  PICML::ImplementationArtifact ia = csa->refers_to_ImplementationArtifact ();

  if (ia)
  {
    std::string id = ia->path (".", false);
    this->write_artifact_execParameter ("edu.vanderbilt.dre.CIAO.ServantArtifact", id);
  }
}

void Deployment_Plan_Visitor::
write_artifact_execParameter (const std::string & name, const std::string & value)
{
  GAME::Xml::Fragment param = this->param_parent_.create_element ("execParameter");
  param.create_simple_content ("name", name);

  GAME::Xml::Fragment val = param.create_element ("value");
  GAME::Xml::Fragment type = val.create_element ("type");
  type.create_simple_content ("kind", "tk_string");

  val = val.create_element ("value");
  val.create_simple_content ("string", value);
}

void Deployment_Plan_Visitor::
visit_ConfigProperty (PICML::ConfigProperty_in cp)
{
  this->curr_param_ = this->param_parent_.create_element ("configProperty");
  cp->dst_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_AttributeInstance (PICML::AttributeInstance_in attr)
{
  attr->src_of_AttributeValue ().first ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_AttributeValue (PICML::AttributeValue_in v)
{
  this->curr_param_ = this->param_parent_.create_element ("configProperty");
  v->dst_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_AssemblyConfigProperty (PICML::AssemblyConfigProperty_in acp)
{
  this->curr_param_ = this->param_parent_.create_element ("configProperty");
  acp->dst_Property ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ComponentAssemblyReference (PICML::ComponentAssemblyReference_in ref)
{
  ref->refers_to_ComponentAssembly ()->accept (this);
}

void Deployment_Plan_Visitor::
visit_ComponentAssembly (PICML::ComponentAssembly_in assembly)
{
  // Visit all the component instances in this assembly.
  for (PICML::ComponentInstance inst : assembly->get_ComponentInstances ())
    inst->accept (this);

  // Visit all the component assemblies in this assembly.
  for (PICML::ComponentAssembly child : assembly->get_ComponentAssemblys ())
    child->accept (this);
}

}
}
