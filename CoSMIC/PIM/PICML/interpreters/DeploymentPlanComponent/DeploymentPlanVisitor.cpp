// $Id$

#include "DeploymentPlanVisitor.h"

#include "Data_Type_Visitor.h"
#include "Data_Value_Visitor.h"
#include "Connection_Visitor.h"
#include "External_Reference_Visitor.h"

#include "Utils/xercesc/XercesString.h"

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
                              _1));

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
  this->create_simple_content (curr_locality_, "constraint", "SameProcess");
  this->locality_.push_back (this->curr_locality_);

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
  std::vector <PICML::ReadonlyAttribute> attrs = inst.ReadonlyAttribute_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&PICML::ReadonlyAttribute::Accept,
                              _1,
                              boost::ref (*this)));

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
// Visit_Property
//
void DeploymentPlanVisitor::
Visit_Property (const PICML::Property & prop)
{
  std::string name = prop.name ();

  if (name == "ComponentIOR")
    name = "edu.vanderbilt.dre.DAnCE.InstanceIOR";
  else if (name == "RegisterNaming")
    name = "edu.vanderbilt.dre.DAnCE.RegisterNaming";

  // Create the property's name and value.
  this->create_simple_content ("name", name);
  this->curr_value_ = this->create_element (this->curr_param_, "value");

  // Visit the actual data type. This will add the necessary elements
  // to the document that determine if property's data type.
  PICML::DataType type = prop.DataType_child ();
  type.Accept (*this);

  // Now, we need to write attribute value to XML document.
  PICML_Data_Value_Visitor dvv (this->curr_value_, prop);
  this->datatypes_.dispatch (dvv, type.ref ());
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
// Visit_ReadonlyAttribute
//
void DeploymentPlanVisitor::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & attr)
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

//template <typename T, typename Del, typename DelRet, typename DelEndRet>
//  void DeploymentPlanVisitor::GetComponents (const T& port,
//  DelRet (T::*srcDel)() const,
//  DelRet (T::*dstDel) () const,
//  DelEndRet (Del::*srcDelEnd)() const,
//  DelEndRet (Del::*dstDelEnd)() const,
//  std::map<Component, std::string>& output,
//  std::set<T>& visited)
//{
//  visited.insert (port);
//  Udm::Object par = port.parent ();
//  std::string recepName = port.name ();
//  std::string parentName = this->ExtractName (par);
//  if (Udm::IsDerivedFrom (par.type (), ComponentAssembly::meta))
//  {
//    std::set<Del> delegates = (port.*dstDel)();
//    for (std::set<Del>::const_iterator iter = delegates.begin ();
//      iter != delegates.end ();
//      ++iter)
//    {
//      Del delegate = *iter;
//      T srcPort = (delegate.*dstDelEnd)();
//      std::string srcPortName = this->ExtractName (srcPort);
//      if (std::find (visited.begin (),
//        visited.end (),
//        srcPort) == visited.end ())
//        this->GetComponents (srcPort, srcDel, dstDel,
//        srcDelEnd, dstDelEnd, output, visited);
//    }
//    delegates = (port.*srcDel)();
//    for (std::set<Del>::const_iterator iter = delegates.begin ();
//      iter != delegates.end ();
//      ++iter)
//    {
//      Del delegate = *iter;
//      T dstPort = (delegate.*srcDelEnd)();
//      std::string dstPortName = this->ExtractName (dstPort);
//      if (std::find (visited.begin (),
//        visited.end (),
//        dstPort) == visited.end ())
//        this->GetComponents (dstPort, srcDel, dstDel,
//        srcDelEnd, dstDelEnd, output, visited);
//    }
//  }
//  else if (Udm::IsDerivedFrom (par.type (), Component::meta))
//  {
//    Component recep_comp = Component::Cast (par);
//    output.insert (make_pair (recep_comp, port.name ()));
//  }
//  visited.erase (port);
//  return;
//}
//
//void DeploymentPlanVisitor::GetReceptacleComponents
//  (const RequiredRequestPort& receptacle,
//  std::map<Component,std::string>& output)
//{
//  std::set<RequiredRequestPort> visited;
//  this->GetComponents (receptacle,
//    &RequiredRequestPort::srcReceptacleDelegate,
//    &RequiredRequestPort::dstReceptacleDelegate,
//    &ReceptacleDelegate::srcReceptacleDelegate_end,
//    &ReceptacleDelegate::dstReceptacleDelegate_end,
//    output,
//    visited);
//}
//
//void DeploymentPlanVisitor::GetFacetComponents (const ProvidedRequestPort& facet,
//  std::map<Component,
//  std::string>& output)
//{
//  std::set<ProvidedRequestPort> visited;
//  this->GetComponents (facet,
//    &ProvidedRequestPort::srcFacetDelegate,
//    &ProvidedRequestPort::dstFacetDelegate,
//    &FacetDelegate::srcFacetDelegate_end,
//    &FacetDelegate::dstFacetDelegate_end,
//    output,
//    visited);
//}
//
////
//// GetEventSinkComponents
////
//void DeploymentPlanVisitor::
//GetEventSinkComponents (const InEventPort& consumer,
//                        std::map<Component, std::string>& output)
//{
//  std::set<InEventPort> visited;
//
//  this->GetComponents (consumer,
//                       &InEventPort::srcEventSinkDelegate,
//                       &InEventPort::dstEventSinkDelegate,
//                       &EventSinkDelegate::srcEventSinkDelegate_end,
//                       &EventSinkDelegate::dstEventSinkDelegate_end,
//                       output,
//                       visited);
//}
//
////
//// GetEventSourceComponents
////
//void DeploymentPlanVisitor::
//GetEventSourceComponents (const OutEventPort& publisher,
//                          std::map <Component,std::string> & output)
//{
//  std::set<OutEventPort> visited;
//
//  this->GetComponents (publisher,
//                       &OutEventPort::srcEventSourceDelegate,
//                       &OutEventPort::dstEventSourceDelegate,
//                       &EventSourceDelegate::srcEventSourceDelegate_end,
//                       &EventSourceDelegate::dstEventSourceDelegate_end,
//                       output,
//                       visited);
//}
//
//void DeploymentPlanVisitor::CreateConnections (const std::map<Component,
//  std::string>& src,
//  const std::map<Component,
//  std::string>& dst,
//  const std::string& source_kind,
//  const std::string& dest_kind)
//{
//  for (std::map<Component,std::string>::const_iterator iter = src.begin ();
//    iter != src.end ();
//    ++iter)
//  {
//    Component srcComp = iter->first;
//    std::string srcPortName = iter->second;
//    for (std::map<Component,
//      std::string>::const_iterator iter = dst.begin ();
//      iter != dst.end ();
//    ++iter)
//    {
//      Component dstComp = iter->first;
//      std::string dstPortName = iter->second;
//      this->CreateConnection (srcComp, srcPortName, dstComp,
//        dstPortName, source_kind, dest_kind);
//    }
//  }
//}
//

////
//// CreateConnection
////
//void DeploymentPlanVisitor::
//CreateConnection (const Component& srcComp,
//                  const std::string& srcPortName,
//                  const Component& dstComp,
//                  const std::string& dstPortName,
//                  const std::string& source_kind,
//                  const std::string& dest_kind)
//{
//  std::string source_comp_instance = "_" + std::string (srcComp.UUID ());
//  std::string dest_comp_instance = "_" + std::string (dstComp.UUID ());
//
//  if (this->selected_instances_.find (source_comp_instance) != this->selected_instances_.end () &&
//      this->selected_instances_.find (dest_comp_instance) != this->selected_instances_.end ())
//  {
//    // Create a connection
//    DOMElement* ele = this->doc_->createElement (XStr ("connection"));
//    this->curr_->appendChild (ele);
//
//    std::string connection =
//      this->unique_id (srcComp) + ":" + srcPortName + "::" +
//      this->unique_id (dstComp) + ":" + dstPortName;
//
//    ele->appendChild (this->createSimpleContent ("name", connection));
//
//    // Source endPoint
//    DOMElement * endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
//    endPoint->appendChild (this->createSimpleContent ("portName", srcPortName));
//    endPoint->appendChild (this->createSimpleContent ("provider", "false"));
//    endPoint->appendChild (this->createSimpleContent ("kind", dest_kind));
//
//    DOMElement * instance = this->doc_->createElement (XStr ("instance"));
//    endPoint->appendChild (instance);
//    instance->setAttribute (XStr ("xmi:idref"), XStr (source_comp_instance.c_str ()));
//    ele->appendChild (endPoint);
//
//    // Destination endPoint
//    endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
//    endPoint->appendChild (this->createSimpleContent ("portName", dstPortName));
//    endPoint->appendChild (this->createSimpleContent ("provider", "true"));
//    endPoint->appendChild (this->createSimpleContent ("kind", source_kind));
//
//    instance = this->doc_->createElement (XStr ("instance"));
//    endPoint->appendChild (instance);
//    instance->setAttribute (XStr ("xmi:idref"), XStr (dest_comp_instance.c_str ()));
//
//    ele->appendChild (endPoint);
//  }
//}
//
//std::string DeploymentPlanVisitor::ExtractName (Udm::Object ob)
//{
//  Uml::Class cls= ob.type ();
//  set<Uml::Attribute> attrs=cls.attributes ();
//
//  // Adding parent attributes
//  set<Uml::Attribute> aattrs=Uml::AncestorAttributes (cls);
//  attrs.insert (aattrs.begin (),aattrs.end ());
//
//  for (set<Uml::Attribute>::iterator ai = attrs.begin ();
//    ai != attrs.end (); ai++)
//  {
//    if (string (ai->type ())=="String")
//    {
//      string str=ai->name ();
//      if (str=="name")
//      {
//        string value=ob.getStringAttr (*ai);
//        if (value.empty ())value="<empty string>";
//        return value;
//      }
//    }
//  }
//  return string ("<no name specified>");
//}
//
//void DeploymentPlanVisitor::Visit_invoke (const invoke& iv)
//{
//
//  // Get the receptacle end
//  RequiredRequestPort receptacle = iv.srcinvoke_end ();
//
//  // Get the facet end. This could be a supported interface.
//  ProvidedRequestPort facet =
//    PICML::ProvidedRequestPort::Cast (iv.dstinvoke_end ());
//
//  std::map<Component,std::string> receptacles;
//  std::map<Component,std::string> facets;
//  std::string source_kind = "Facet";
//  std::string dest_kind = "SimplexReceptacle";
//  this->GetReceptacleComponents (receptacle, receptacles);
//  this->GetFacetComponents (facet, facets);
//  this->CreateConnections (receptacles, facets, source_kind, dest_kind);
//}
//
//void DeploymentPlanVisitor::Visit_emit (const emit& ev)
//{
//  // Get the emitter end
//  OutEventPort emitter = ev.srcemit_end ();
//
//  // Get the consumer end
//  InEventPort consumer = ev.dstemit_end ();
//
//  std::map<Component,std::string> emitters;
//  std::map<Component,std::string> consumers;
//  std::string source_kind = "EventConsumer";
//  std::string dest_kind = "EventEmitter";
//  this->GetEventSourceComponents (emitter, emitters);
//  this->GetEventSinkComponents (consumer, consumers);
//  this->CreateConnections (emitters, consumers, source_kind, dest_kind);
//}
//
//void DeploymentPlanVisitor::Visit_publish (const publish& ev)
//{
//  // Get the publisher end
//  const OutEventPort publisher = ev.srcpublish_end ();
//
//  // Get the connector end
//  const PublishConnector connector = ev.dstpublish_end ();
//
//  // Create an entry in the publishers_ map
//  this->publishers_[std::string (connector.name ())] = publisher;
//}
//
//void DeploymentPlanVisitor::Visit_deliverTo (const deliverTo& dv)
//{
//  // Get the connector end
//  const  PublishConnector connector = dv.srcdeliverTo_end ();
//
//  // Get the consumer end
//  const InEventPort consumer = dv.dstdeliverTo_end ();
//
//  // Create an entry in the consumers_ map
//  this->consumers_.insert (make_pair (std::string (connector.name ()),
//    consumer));
//}
//
//void DeploymentPlanVisitor::Visit_PublishConnector (const PublishConnector& pubctor)
//{
//  std::string ctor = pubctor.name ();
//
//  // Get Publisher
//  OutEventPort publisher = this->publishers_[ctor];
//  std::map<Component,std::string> publishers;
//  this->GetEventSourceComponents (publisher, publishers);
//
//  for (std::map<Component,std::string>::const_iterator
//    iter = publishers.begin ();
//    iter != publishers.end ();
//  ++iter)
//  {
//    Component srcComp = iter->first;
//    std::string srcPortName = iter->second;
//
//    for (std::multimap<std::string, InEventPort>::const_iterator
//      iter = this->consumers_.lower_bound (ctor);
//      iter != this->consumers_.upper_bound (ctor);
//    ++iter)
//    {
//      // Get Consumer
//      InEventPort consumer = iter->second;
//      std::map<Component,std::string> consumers;
//      this->GetEventSinkComponents (consumer, consumers);
//      for (std::map<Component,std::string>::const_iterator
//        iter = consumers.begin ();
//        iter != consumers.end ();
//      ++iter)
//      {
//        Component dstComp = iter->first;
//        std::string dstPortName = iter->second;
//        std::string source_kind = "EventConsumer";
//        std::string dest_kind = "EventPublisher";
//        this->CreateConnection (srcComp, srcPortName, dstComp,
//          dstPortName, source_kind, dest_kind);
//      }
//    }
//  }
//}
//

////
//// instantiate_deployment_plan_descriptor
////
//void DeploymentPlanVisitor::
//instantiate_deployment_plan_descriptor (const DeploymentPlan & dp)
//{
//  this->push ();
//  std::string name = this->outputPath_ + "\\";
//  name += dp.name ();
//  name += ".cdp";
//  this->initTarget (name);
//  this->init_document ("Deployment:DeploymentPlan");
//  this->init_root_attributes ();
//}

//
// Visit_ComponentAssembly
//
void DeploymentPlanVisitor::
Visit_ComponentAssembly (const PICML::ComponentAssembly & assembly)
{
  //std::string node_reference_name = this->retNodeRefName ();
  //std::string cg_name = this->retcgName ();

  //// Collect all the Components of this assembly into a set.
  //std::set<Component> comps = assembly.Component_kind_children ();

  //// Add all the shared Components of this assembly into the set.  A
  //// shared Component is implemented as a reference to a Component.  So
  //// just traverse the reference and add it to the set.
  //std::set<ComponentRef> scomps = assembly.ComponentRef_kind_children ();
  //for (std::set<ComponentRef>::const_iterator
  //  iter = scomps.begin ();
  //  iter != scomps.end ();
  //++iter)
  //{
  //  const ComponentRef compRef = *iter;
  //  comps.insert (compRef.ref ());
  //}

  //// Collect all the immediate ComponentAssembly children of this assembly
  //std::set<ComponentAssembly>
  //  subasms = assembly.ComponentAssembly_kind_children ();

  //// Add all the shared ComponentAssemblies of the current assembly.
  //// Like shared components, shared assemblies are also implemented as
  //// references.  So just traverse the references, and add them to the set.
  //std::set<ComponentAssemblyReference>
  //  sasms = assembly.ComponentAssemblyReference_kind_children ();
  //for (std::set<ComponentAssemblyReference>::const_iterator
  //  iter = sasms.begin ();
  //  iter != sasms.end ();
  //++iter)
  //{
  //  const ComponentAssemblyReference asmRef = *iter;
  //  subasms.insert (asmRef.ref ());
  //}

  //// Maintain a list of all ComponentAssemblies in this assembly
  //std::vector<ComponentAssembly> assemblies;

  //// Put ourselves in the global list first.
  //assemblies.push_back (assembly);

  //// Do a Depth-First search and collect all the ComponentAssembly,
  //// Component children of this assembly, and add them to the
  //// assembly-specific list.
  //while (!subasms.empty ())
  //{
  //  ComponentAssembly rassembly = *subasms.begin ();
  //  // Put the first assembly from the current list to the
  //  // assembly-specific list.
  //  assemblies.push_back (rassembly);

  //  subasms.erase (rassembly);

  //  // Get the components of the current assembly, and insert them into
  //  // the component list
  //  std::set<Component> rcomps = rassembly.Component_kind_children ();

  //  // Get the shared components of the current assembly
  //  scomps = rassembly.ComponentRef_kind_children ();
  //  for (std::set<ComponentRef>::const_iterator
  //    iter = scomps.begin ();
  //    iter != scomps.end ();
  //  ++iter)
  //  {
  //    const ComponentRef compRef = *iter;
  //    rcomps.insert (compRef.ref ());
  //  }

  //  comps.insert (rcomps.begin (), rcomps.end ());

  //  // Get the subassemblies of the first assembly.
  //  std::set<ComponentAssembly>
  //    rasms = rassembly.ComponentAssembly_kind_children ();

  //  // Add all the shared ComponentAssemblies of the current assembly.
  //  // Like shared components, shared assemblies are also implemented
  //  // as references.  So just traverse the references, and add them to
  //  // the set.
  //  std::set<ComponentAssemblyReference>
  //    sasms = rassembly.ComponentAssemblyReference_kind_children ();
  //  for (std::set<ComponentAssemblyReference>::const_iterator
  //    iter = sasms.begin ();
  //    iter != sasms.end ();
  //  ++iter)
  //  {
  //    const ComponentAssemblyReference asmRef = *iter;
  //    rasms.insert (asmRef.ref ());
  //  }

  //  // Insert them to the current list.
  //  // std::copy (rasms.begin (), rasms.end (), std::back_inserter (subasms));
  //  subasms.insert (rasms.begin (), rasms.end ());
  //}

  //// Create the appropriate component attribute value mappings
  //this->CreateAttributeMappings (assemblies);
  //this->assembly_components_ = comps;
}

//
//void DeploymentPlanVisitor::Visit_AttributeValue (const AttributeValue& value)
//{
//  this->push ();
//  DOMElement* ele = this->doc_->createElement (XStr ("configProperty"));
//  this->curr_->appendChild (ele);
//  this->curr_ = ele;
//  Property ref = value.dstAttributeValue_end ();
//  ReadonlyAttribute attr = value.srcAttributeValue_end ();
//  ref.name () = attr.name ();
//  ref.Accept (*this);
//  this->pop ();
//}
