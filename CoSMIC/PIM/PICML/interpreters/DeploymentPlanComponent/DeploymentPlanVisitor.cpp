// $Id$

#include "DeploymentPlanVisitor.h"

#include "Deployment_Domain_Visitor.h"
#include "Nodemap_Generator.h"

#include "Data_Type_Visitor.h"
#include "Data_Value_Visitor.h"
#include "Connection_Visitor.h"
#include "External_Reference_Visitor.h"
#include "Connector_Visitor.h"

#include "Utils/xercesc/XercesString.h"
#include "Utils/udm/visit.h"
#include "Utils/UDM/Position_Sort_T.h"

#include "UmlExt.h"
#include "boost/bind.hpp"

#include <algorithm>
#include <functional>
#include <sstream>

using Utils::XStr;
using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;
using xercesc::DOMElement;

//
// DeploymentPlanVisitor
//
DeploymentPlanVisitor::
DeploymentPlanVisitor (const std::string & outputPath)
: impl_ (0),
  doc_ (0),
  output_ (0),
  serializer_ (0),
  outputPath_ (outputPath)
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
  if (this->doc_)
    this->doc_->release ();

  // Create the document
  this->doc_ = this->impl_->createDocument (XStr ("http://www.omg.org/Deployment"),
                                            XStr (rootName.c_str ()),
                                            0);

  this->doc_->setXmlVersion (XStr ("1.0"));
}

//
// Visit_RootFolder
//
void DeploymentPlanVisitor::
Visit_RootFolder (const PICML::RootFolder & rf)
{
  typedef std::set <PICML::DeploymentPlans> DeploymentPlans_Set;
  DeploymentPlans_Set folders = rf.DeploymentPlans_kind_children ();

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&DeploymentPlans_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_DeploymentPlans
//
void DeploymentPlanVisitor::
Visit_DeploymentPlans (const PICML::DeploymentPlans & dps)
{
  typedef std::set <PICML::DeploymentPlan> DeploymentPlan_Set;
  DeploymentPlan_Set plans = dps.DeploymentPlan_kind_children ();

  std::for_each (plans.begin (),
                 plans.end (),
                 boost::bind (&DeploymentPlan_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_DeploymentPlan
//
void DeploymentPlanVisitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Start a new XML document for this deployment plan.
  this->init_document ("Deployment:DeploymentPlan");

  // Prepare the XML document for writing.
  DOMElement * root = this->doc_->getDocumentElement ();

  root->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                        XStr ("xmlns:Deployment"),
                        XStr ("http://www.omg.org/Deployment"));

  root->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                        XStr ("xmlns:xsi"),
                        XStr ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                        XStr ("xmlns:xmi"),
                        XStr ("http://www.omg.org/XMI"));

  root->setAttribute (XStr ("xsi:schemaLocation"),
                      XStr ("http://www.omg.org/Deployment Deployment.xsd"));

  this->create_simple_content (root, "label", plan.label ());
  this->create_simple_content (root, "UUID", plan.UUID ());

  // Visit all the nodes in the deployment plan. This will gather all
  // the necessary parts of the XML document. We do not process the
  // connections at this point because we want to wait until we have
  // all the deployed instances. This will make a life a little less
  // hectic in the long run.
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept,
                              _1,
                              boost::ref (*this)));

  // Finally, get all the connections. To simplify this problem, we
  // can look at the outbound connections and if there is a connection
  // on the other end and the target instance is deployed, then we can
  // include the connection in the final deployment.

  typedef std::map <PICML::ComponentInstance, xercesc::DOMElement *> inst_map_t;
  inst_map_t::iterator inst_iter, inst_iter_end = this->insts_.end ();

  Connection_Visitor cv (this->doc_, this->insts_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (cv);

  // Handle the external references.
  PICML_External_Reference_Visitor external (this->doc_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (external);

  // Handle the connections to connectors. We need to check if any
  // of the deployed instances has a connection to a connector since
  // connectors do not appear in the deployment model.
  Connector_Visitor connector_visitor (*this, this->doc_);

  for (inst_iter = this->insts_.begin (); inst_iter != inst_iter_end; ++ inst_iter)
    PICML::ComponentInstance (inst_iter->first).Accept (connector_visitor);

  // Append all the elements to this document in the correct order
  // so the deployment will be valid.

  // <implementation>
  std::for_each (this->impls_.begin (),
                 this->impls_.end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              boost::bind (&std::map <PICML::Implemenation,
                                                      xercesc::DOMElement *>::
                                                      value_type::second, _1)));
  // <instance>
  std::for_each (this->insts_.begin (),
                 this->insts_.end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              boost::bind (&std::map <PICML::ComponentInstance,
                                                      xercesc::DOMElement *>::
                                                      value_type::second, _1)));

  std::for_each (this->conn_insts_.begin (),
                 this->conn_insts_.end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              boost::bind (&std::map <std::string,
                                                      xercesc::DOMElement *>::
                                                      value_type::second, _1)));

  // <connection>
  std::for_each (cv.connections ().begin (),
                 cv.connections ().end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              _1));

  std::for_each (external.connections ().begin (),
                 external.connections ().end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              _1));

  std::for_each (connector_visitor.connections ().begin (),
                 connector_visitor.connections ().end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              _1));

  // <artifact>
  std::for_each (this->artifacts_.begin (),
                 this->artifacts_.end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              boost::bind (&std::map <PICML::ImplementationArtifact,
                                                      xercesc::DOMElement *>::
                                                      value_type::second, _1)));

  // <localityConstraint>
  std::for_each (this->locality_.begin (),
                 this->locality_.end (),
                 boost::bind (&xercesc::DOMElement::appendChild,
                              root,
                              boost::bind (&locality_t::value_type::second, _1)));

  // Open the XML file for writing.
  std::ostringstream filename;
  filename << this->outputPath_ << "/" << plan.name () << ".cdp";
  LocalFileFormatTarget target (filename.str ().c_str ());

  // Write the document.
  this->output_->setByteStream (&target);
  this->serializer_->write (this->doc_, this->output_);
  this->output_->setByteStream (0);

  // Release the document.
  this->doc_->release ();

  //call visitor that will generate the .cdd file
  Deployment_Domain_Visitor ddv (this->outputPath_);
  PICML::DeploymentPlan (plan).Accept (ddv);

  //call visitor that will generate the .nodemap file
  Nodemap_Generator ng (this->outputPath_);
  PICML::DeploymentPlan (plan).Accept (ng);
}

//
// Visit_NodeReference
//
void DeploymentPlanVisitor::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  this->current_node_ = noderef.ref ();
  std::set <PICML::InstanceMapping> mapping = noderef.srcInstanceMapping () ;

  std::for_each (mapping.begin (),
                 mapping.end (),
                 boost::bind (&PICML::InstanceMapping::Accept,
                              _1,
                              boost::ref (*this)));
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
  this->curr_locality_ = this->doc_->createElement (Utils::XStr ("localityConstraint"));
  this->current_group_ = group;

  this->create_simple_content (curr_locality_, "constraint", "SameProcess");
  this->locality_.insert (std::make_pair (group, this->curr_locality_));

  std::set <PICML::CollocationGroupMember> members = group.members ();

  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&CollocationGroupMember_Dispatcher::dispatch,
                              boost::ref (this->cgm_dispatcher_),
                              boost::ref (*this),
                              _1));
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
  this->curr_instance_ = this->doc_->createElement (Utils::XStr ("instance"));
  this->insts_.insert (std::make_pair (inst, this->curr_instance_));
  this->mappings_[inst] = this->current_group_;

  this->curr_instance_->setAttribute (XStr ("xmi:id"), XStr (uuid));
  this->create_simple_content (this->curr_instance_, "name", name);
  this->create_simple_content (this->curr_instance_, "node", this->current_node_.name ());
  this->create_simple_content (this->curr_instance_, "source", "");

  // Insert this instance into the current locality.
  DOMElement * constrained = this->create_element (this->curr_locality_, "constrainedInstance");
  constrained->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid));

  // Visit this instance's implementation.
  PICML::ComponentInstanceType type = inst.ComponentInstanceType_child ();
  type.Accept (*this);

  this->param_parent_ = this->curr_instance_;

  // Finish writing the component instance information.
  Udm::visit_all <PICML::AttributeInstance> (inst, *this);

  std::set <PICML::AssemblyConfigProperty> configs = inst.dstAssemblyConfigProperty ();
  std::for_each (configs.begin (),
                 configs.end (),
                 boost::bind (&PICML::AssemblyConfigProperty::Accept,
                              _1,
                              boost::ref (*this)));

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

  DOMElement * element = this->create_element (this->curr_instance_, "implementation");
  element->setAttribute (XStr ("xmi:idref"), XStr (uuid));

  // Add all the configProperty elements to the current instance.
  this->param_parent_ = this->curr_instance_;

  std::set <PICML::ConfigProperty> configs = impl.dstConfigProperty ();
  std::for_each (configs.begin (),
                 configs.end (),
                 boost::bind (&PICML::ConfigProperty::Accept,
                              _1,
                              boost::ref (*this)));

  // There is no need to continue if we have already seen this
  // implementation before.
  if (this->impls_.find (impl) != this->impls_.end ())
    return;

  // Since we have not seen this implementation before, we need to
  // create a new XML element for it.
  this->curr_impl_ = this->doc_->createElement (XStr ("implementation"));
  this->impls_.insert (std::make_pair (impl, this->curr_impl_));

  this->curr_impl_->setAttribute (XStr ("xmi:id"), XStr (uuid));

  std::string name = impl.getPath (".", false, true, "name", true);
  this->create_simple_content (this->curr_impl_, "name", name);
  this->create_simple_content (this->curr_impl_, "source", "");

  // The next part of this element is the artifacts. Therefore, visit
  // all the primary artifacts for this component.
  std::set <PICML::MonolithprimaryArtifact> mpas = impl.dstMonolithprimaryArtifact ();
  std::for_each (mpas.begin (),
                 mpas.end (),
                 boost::bind (&PICML::MonolithprimaryArtifact::Accept,
                              _1,
                              boost::ref (*this)));

  // Set the property parameter's parent.
  this->param_parent_ = this->curr_impl_;

  // Write the executor parameters for the required artifacts. This
  // should never be null, but just in case... :-)
  if (Udm::null != this->impl_artifact_)
    this->impl_artifact_.Accept (*this);

  if (Udm::null != this->svnt_artifact_)
    this->svnt_artifact_.Accept (*this);

  // The last part of this section of the XML document are the
  // executor parameters. So, let's visit all the monolithic executor
  // parameters for this implementation.
  std::set <PICML::MonolithExecParameter> mexecs = impl.dstMonolithExecParameter ();

  std::for_each (mexecs.begin (),
                 mexecs.end (),
                 boost::bind (&PICML::MonolithExecParameter::Accept,
                              _1,
                              boost::ref (*this)));

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
  DOMElement * element = this->create_element (this->curr_impl_, "artifact");
  element->setAttribute (XStr ("xmi:idref"), XStr (uuid));

  // There is no need to continue if we have already seen this
  // artifact. Otherwise, we will overwrite the existing one.
  if (this->artifacts_.find (artifact) != this->artifacts_.end ())
    return;

  // We should go ahead and create a new artifact element for
  // the XML document.
  this->curr_artifact_ = this->doc_->createElement (XStr ("artifact"));
  this->artifacts_.insert (std::make_pair (artifact, this->curr_artifact_));

  this->curr_artifact_->setAttribute (XStr ("xmi:id"), XStr (uuid));
  std::string name = artifact.getPath (".", false, true, "name", true);
  this->create_simple_content (this->curr_artifact_, "name", name);
  this->create_simple_content (this->curr_artifact_, "source", "");
  this->create_simple_content (this->curr_artifact_, "node", "");
  this->create_simple_content (this->curr_artifact_, "location", artifact.location ());

  // Let's generate the artifact exec parameters.
  this->param_parent_ = this->curr_artifact_;

  std::set <PICML::ArtifactExecParameter> params = artifact.dstArtifactExecParameter ();
  std::for_each (params.begin (),
                 params.end (),
                 boost::bind (&PICML::ArtifactExecParameter::Accept,
                              _1,
                              boost::ref (*this)));

  // Finally, make sure we include all the artifact dependencies.
  std::set <PICML::ArtifactDependency> dependencies = artifact.srcArtifactDependency ();
  std::for_each (dependencies.begin (),
                 dependencies.end (),
                 boost::bind (&PICML::ArtifactDependency::Accept,
                              _1,
                              boost::ref (*this)));

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
  this->curr_param_ = this->create_element (this->param_parent_, "execParameter");

  PICML::Property prop = mexec.dstMonolithExecParameter_end ();
  prop.Accept (*this);
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

////
//// Visit_ImplementationArtifactReference
////
//void DeploymentPlanVisitor::
//Visit_ImplementationArtifactReference (const PICML::ImplementationArtifactReference & iar)
//{
//  this->push ();
//  DOMElement* ele = this->doc_->createElement (XStr ("dependsOn"));
//  ele->appendChild (this->createSimpleContent ("name", iar.name ()));
//  const ImplementationArtifact ref = iar.ref ();
//  std::string refName (ref.name ());
//  refName += ".iad";
//  DOMElement* refEle = this->doc_->createElement (XStr ("referencedArtifact"));
//  refEle->setAttribute (XStr ("href"), XStr (refName));
//  ele->appendChild (refEle);
//  this->curr_->appendChild (ele);
//  this->pop ();
//}

//
// Visit_ArtifactExecParameter
//
void DeploymentPlanVisitor::
Visit_ArtifactExecParameter (const PICML::ArtifactExecParameter& param)
{
  this->curr_param_ = this->create_element (this->param_parent_, "execParameter");

  PICML::Property prop = param.dstArtifactExecParameter_end ();
  prop.Accept (*this);
}

//
// Visit_ConnectorInstance
//
void DeploymentPlanVisitor::
deploy_connector_fragment (const PICML::ConnectorInstance & inst,
                           const PICML::CollocationGroup & group)
{
  //if (this->conn_insts_.find (inst) != this->conn_insts_.end ())
  //  return;

  std::string uuid = "_" + std::string (inst.UUID ());
  std::string name = inst.getPath (".", false, true, "name", true);

  // Insert this instance into the current locality.
  DOMElement * locality = this->locality_[group];

  if (0 != locality)
  {
    DOMElement * constrained = this->create_element (locality, "constrainedInstance");
    constrained->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid));
  }

  // Get the target node's name for this instance
  PICML::InstanceMapping mapping = group.dstInstanceMapping ();
  PICML::NodeReference noderef = mapping.dstInstanceMapping_end ();
  PICML::Node node = noderef.ref ();

  // Create a new instance in the XML document.
  this->curr_instance_ = this->doc_->createElement (Utils::XStr ("instance"));
  this->conn_insts_.insert (std::make_pair (uuid, this->curr_instance_));

  this->curr_instance_->setAttribute (XStr ("xmi:id"), XStr (uuid));
  this->create_simple_content (this->curr_instance_, "name", name);

  // TODO set the node correctly...
  this->create_simple_content (this->curr_instance_, "node", node.name ());
  this->create_simple_content (this->curr_instance_, "source", "");

  // Visit this instance's implementation.
  PICML::ConnectorImplementationType cit = inst.ConnectorImplementationType_child ();
  cit.Accept (*this);

  this->param_parent_ = this->curr_instance_;

  // Finish writing the component instance information.
  Udm::visit_all <PICML::AttributeInstance> (inst, *this);

  std::set <PICML::AssemblyConfigProperty> configs = inst.dstAssemblyConfigProperty ();
  std::for_each (configs.begin (),
                 configs.end (),
                 boost::bind (&PICML::AssemblyConfigProperty::Accept,
                              _1,
                              boost::ref (*this)));
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
// Visit_Property
//
void DeploymentPlanVisitor::
Visit_Property (const PICML::Property & prop)
{
  // Start with the name of the property.
  std::string name = prop.name ();

  if (name == "InstanceIOR")
    name = "edu.vanderbilt.dre.DAnCE.InstanceIOR";
  else if (name == "RegisterNaming")
    name = "edu.vanderbilt.dre.DAnCE.RegisterNaming";

  PICML_Data_Type_Dispatcher dt_dispatcher;

  this->create_simple_content (this->curr_param_, "name", name);
  xercesc::DOMElement * value = this->create_element (this->curr_param_, "value");

  // First, we need to generate the type for this property
  PICML_Data_Type_Visitor dtv (value);
  PICML_Data_Value_Visitor dvv (value);
  PICML::ComplexTypeReference complex = prop.ComplexTypeReference_child ();

  if (complex == Udm::null)
  {
    // Since this is not a complex type, then we know there should
    // only be one DataValue in the property.
    std::vector <PICML::DataValue> data_values = prop.DataValue_kind_children ();
    PICML::DataValue data_value = data_values.front ();
    PICML::SimpleType simple = data_value.ref ();

    // Write the data type for the property.
    dt_dispatcher.dispatch (dtv, simple);
  }
  else
  {
    // Ok, so we are dealing with a complex type. We therefore need to
    // visit the ComplexType reference in this container.
    dt_dispatcher.dispatch (dtv, complex.ref ());
  }

  // Generate the value for the property.
  PICML::Property (prop).Accept (dvv);
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
  ref.Accept (*this);
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
  prop.Accept (*this);
}

//
// Visit_AssemblyConfigProperty
//
void DeploymentPlanVisitor::
Visit_AssemblyConfigProperty (const PICML::AssemblyConfigProperty & acp)
{
  this->curr_param_ = this->create_element (this->param_parent_, "configProperty");

  PICML::Property ref = acp.dstAssemblyConfigProperty_end ();
  ref.Accept (*this);
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
  // Oder the ComponentInstances elements using the topdown ordering
  typedef UDM_Position_Sort_T <PICML::ComponentInstance, PS_Top_To_Bottom> sorter_t_inst;
  typedef std::set <PICML::ComponentInstance, sorter_t_inst> sorted_values_t_inst;
  sorted_values_t_inst insts = assembly.ComponentInstance_children_sorted (sorter_t_inst ());

  std::for_each (insts.begin (),
                 insts.end (),
                 boost::bind (&PICML::ComponentInstance::Accept,
                               _1,
                               boost::ref (*this)));

  // Oder the ComponentAsssembly elements using the topdown ordering
  typedef UDM_Position_Sort_T <PICML::ComponentAssembly, PS_Top_To_Bottom> sorter_t_ass;
  typedef std::set <PICML::ComponentAssembly, sorter_t_ass> sorted_values_t_ass;
  sorted_values_t_ass child_assemblies = assembly.ComponentAssembly_children_sorted (sorter_t_ass ());

  std::for_each (child_assemblies.begin (),
                 child_assemblies.end (),
                 boost::bind (&PICML::ComponentAssembly::Accept,
                               _1,
                               boost::ref (*this)));
}
