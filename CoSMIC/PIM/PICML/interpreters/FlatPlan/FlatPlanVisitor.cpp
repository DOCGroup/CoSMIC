#include "FlatPlanVisitor.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

namespace PICML
{
  FlatPlanVisitor::FlatPlanVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), target_ (0),
      outputPath_ (outputPath)
  {
    this->init();
  }

  FlatPlanVisitor::~FlatPlanVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
  }

  void FlatPlanVisitor::init()
  {
    this->impl_ = DOMImplementationRegistry::getDOMImplementation(XStr("LS"));
    this->serializer_ = ((DOMImplementationLS*)impl_)->createDOMWriter();

    // Set features if the serializer supports the feature/mode
    if (this->serializer_->canSetFeature
        (XMLUni::fgDOMWRTDiscardDefaultContent, true))
      this->serializer_->setFeature (XMLUni::fgDOMWRTDiscardDefaultContent,
                                     true);

    if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTFormatPrettyPrint,
                                          true))
      this->serializer_->setFeature (XMLUni::fgDOMWRTFormatPrettyPrint, true);

    if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTBOM, false))
      this->serializer_->setFeature (XMLUni::fgDOMWRTBOM, false);
  }

  void FlatPlanVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void FlatPlanVisitor::initNodeRefName (const std::string& nodeRefName)
  {
    this->node_ref_name_ = nodeRefName;
  }

  std::string FlatPlanVisitor::retNodeRefName ()
  {
    return this->node_ref_name_;
  }

  void FlatPlanVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (XStr ("http://www.omg.org/Deployment"),
                                   XStr (rootName.c_str()),
                                   0);
  }

  void FlatPlanVisitor::initRootAttributes()
  {
    this->doc_->setEncoding (XStr("UTF-8"));
    this->doc_->setVersion (XStr("1.0"));
    this->root_ = this->doc_->getDocumentElement();
    this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                                 XStr ("xmlns:Deployment"),
                                 XStr ("http://www.omg.org/Deployment"));
    this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                                 XStr ("xmlns:xsi"),
                                 XStr ("http://www.w3.org/2001/XMLSchema-instance"));
    this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                                 XStr ("xmlns:xmi"),
                                 XStr ("http://www.omg.org/XMI"));
    this->root_->setAttribute (XStr ("xsi:schemaLocation"),
                               XStr ("http://www.omg.org/Deployment Deployment.xsd"));
    this->curr_ = this->root_;
  }

  void FlatPlanVisitor::dumpDocument()
  {
    this->serializer_->writeNode (this->target_, *this->doc_);
  }

  void FlatPlanVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void FlatPlanVisitor::pop()
  {
    if (!this->curr_stack_.empty())
      {
        this->curr_ = this->curr_stack_.top();
        this->curr_stack_.pop();
      }
    else
      {
        throw(std::exception());
      }
  }

  DOMElement* FlatPlanVisitor::createSimpleContent (const std::string& name,
                                                const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  void FlatPlanVisitor::Visit_RootFolder(const RootFolder& rf)
  {
    std::set<DeploymentPlans> folders = rf.DeploymentPlans_kind_children();
    for (std::set<DeploymentPlans>::iterator iter = folders.begin();
         iter != folders.end();
         ++iter)
      {
        DeploymentPlans folder = *iter;
        folder.Accept (*this);
      }
  }

  // Predefined Types
  void FlatPlanVisitor::Visit_LongInteger(const LongInteger&)
  {}

  void FlatPlanVisitor::Visit_Boolean(const Boolean&)
  {}

  void FlatPlanVisitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void FlatPlanVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {

  }

  void FlatPlanVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
  {

  }

  void FlatPlanVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {

  }

  void FlatPlanVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {

  }

  void FlatPlanVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
  {

  }

  void FlatPlanVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {

  }

  void FlatPlanVisitor::Visit_Property(const Property& property)
  {

  }

  void FlatPlanVisitor::Visit_DataType(const DataType& type)
  {

  }

  void FlatPlanVisitor::Visit_String(const String& str)
  {

  }

  void FlatPlanVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void FlatPlanVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void FlatPlanVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

  void FlatPlanVisitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
  {

  }


  void FlatPlanVisitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
  {

  }

  void FlatPlanVisitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
  {

  }

  void FlatPlanVisitor::Visit_package(const package& pkg)
  {

  }

  void FlatPlanVisitor::Visit_PackageConfigurationReference(const PackageConfigurationReference& pcr)
  {

  }

  void FlatPlanVisitor::Visit_PackageConfigurations(const PackageConfigurations& pcs)
  {

  }

  void FlatPlanVisitor::Visit_PackageConfigurationContainer(const PackageConfigurationContainer& pcc)
  {

  }

  void FlatPlanVisitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
  {

  }

  void FlatPlanVisitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty&)
  {}

  void FlatPlanVisitor::Visit_PackageConfReference(const PackageConfReference&)
  {}

  void FlatPlanVisitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
  {}

  void FlatPlanVisitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
  {}

  void FlatPlanVisitor::Visit_PackageConfBasePackage(const PackageConfBasePackage&)
  {}

  void FlatPlanVisitor::Visit_ComponentPackageReference(const ComponentPackageReference&)
  {}

  void FlatPlanVisitor::Visit_DeploymentPlans(const DeploymentPlans& dps)
  {
    std::set<DeploymentPlan> plans = dps.DeploymentPlan_kind_children();
    for (std::set<DeploymentPlan>::iterator iter = plans.begin();
         iter != plans.end();
         ++iter)
      {
        DeploymentPlan plan = *iter;
        plan.Accept (*this);
      }
  }

  void FlatPlanVisitor::Visit_DeploymentPlan(const DeploymentPlan& dp)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
	name += dp.name();
    name += ".cdp";
    this->initTarget (name);
    this->initDocument ("Deployment:DeploymentPlan");
    this->initRootAttributes();

    const std::set<CollocationGroup> dps = dp.CollocationGroup_children();

    for (std::set<CollocationGroup>::const_iterator iter = dps.begin();
         iter != dps.end();
         ++iter)
      {
        std::string refName;
        CollocationGroup cg = *iter;

        const std::set<InstanceMapping> cg_ins_maps = cg.dstInstanceMapping ();

        for (std::set<InstanceMapping>::const_iterator cg_ins_map_iter = cg_ins_maps.begin();
             cg_ins_map_iter != cg_ins_maps.end ();
             ++cg_ins_map_iter)
          {
            InstanceMapping cg_ins = *cg_ins_map_iter;
            NodeReference node_ref = cg_ins.dstInstanceMapping_end();
            const Node ref = node_ref.ref();
            refName = (ref.name());
			this->initNodeRefName (refName);
          }

        std::set<CollocationGroup_Members_Base> comp_types = cg.members ();
		for (std::set<CollocationGroup_Members_Base>::const_iterator comp_type_iter = comp_types.begin();
			 comp_type_iter != comp_types.end (); ++comp_type_iter)
		  {
            CollocationGroup_Members_Base comp_type = *comp_type_iter;
			if (Udm::IsDerivedFrom (comp_type.type(), ComponentRef::meta))
			  {
			    ComponentRef component_ref = ComponentRef::Cast (comp_type);
				Component comp = component_ref.ref();
				this->push();
                DOMElement* ele = this->doc_->createElement (XStr ("instance"));
				std::string uniqueName = comp.getPath ("_",false,true);
                ele->appendChild (this->createSimpleContent ("name", uniqueName));
                ele->appendChild (this->createSimpleContent ("node", refName));
                this->curr_->appendChild (ele);
                this->pop();
			  }
		    else if (Udm::IsDerivedFrom (comp_type.type(), ComponentAssemblyReference::meta))
			  {
			    ComponentAssemblyReference comp_assembly_ref = ComponentAssemblyReference::Cast (comp_type);
				ComponentAssembly comp_assembly = comp_assembly_ref.ref ();
				comp_assembly.Accept (*this);
			  }
		  }
	  }


    this->dumpDocument();
    this->pop();
  }

  void FlatPlanVisitor::Visit_ComponentAssembly(const ComponentAssembly& assembly)
  {
    std::set<ComponentAssembly>
      asms = assembly.ComponentAssembly_kind_children();
    for (std::set<ComponentAssembly>::iterator aiter = asms.begin();
         aiter != asms.end();
         ++aiter)
      {
        ComponentAssembly rassembly  = *aiter;
        rassembly.Accept (*this);
      }

    std::string node_reference_name = this->retNodeRefName ();

    std::set<Component> comps = assembly.Component_kind_children();
	for (std::set<Component>::iterator iter = comps.begin();
         iter != comps.end();
         ++iter)
      {
	    Component comp = *iter;
		this->push();
        DOMElement* ele = this->doc_->createElement (XStr ("instance"));
		std::string uniqueName = comp.getPath ("_",false,true);
        ele->appendChild (this->createSimpleContent ("name", uniqueName));
        ele->appendChild (this->createSimpleContent ("node", node_reference_name));
        this->curr_->appendChild (ele);
        this->pop();
	  }
  }

  void FlatPlanVisitor::Visit_InstanceMapping(const InstanceMapping& ins_map)
  {
    NodeReference node_ref = ins_map.dstInstanceMapping_end();
    node_ref.Accept (*this);
  }

  void FlatPlanVisitor::Visit_NodeReference(const NodeReference& node_ref)
  {
  }

}
