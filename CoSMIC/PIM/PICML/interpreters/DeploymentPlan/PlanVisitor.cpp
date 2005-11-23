#include "DeploymentPlan/PlanVisitor.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

namespace PICML
{
  PlanVisitor::PlanVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), target_ (0),
      outputPath_ (outputPath)
  {
    this->init();
  }

  PlanVisitor::~PlanVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
  }

  void PlanVisitor::init()
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

  void PlanVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void PlanVisitor::initNodeRefName (const std::string& nodeRefName)
  {
    this->node_ref_name_ = nodeRefName;
  }

  std::string PlanVisitor::retNodeRefName ()
  {
    return this->node_ref_name_;
  }

  void PlanVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (XStr ("http://www.omg.org/Deployment"),
                                   XStr (rootName.c_str()),
                                   0);
  }

  void PlanVisitor::initRootAttributes()
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

  void PlanVisitor::dumpDocument()
  {
    this->serializer_->writeNode (this->target_, *this->doc_);
  }

  void PlanVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void PlanVisitor::pop()
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

  DOMElement* PlanVisitor::createSimpleContent (const std::string& name,
                                                const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  void PlanVisitor::Visit_RootFolder(const RootFolder& rf)
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
  void PlanVisitor::Visit_LongInteger(const LongInteger&)
  {}

  void PlanVisitor::Visit_Boolean(const Boolean&)
  {}

  void PlanVisitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void PlanVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {

  }

  void PlanVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
  {

  }

  void PlanVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {

  }

  void PlanVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {

  }

  void PlanVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
  {

  }

  void PlanVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {

  }

  void PlanVisitor::Visit_Property(const Property& property)
  {

  }

  void PlanVisitor::Visit_DataType(const DataType& type)
  {

  }

  void PlanVisitor::Visit_String(const String& str)
  {

  }

  void PlanVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void PlanVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void PlanVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

  void PlanVisitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
  {

  }


  void PlanVisitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
  {

  }

  void PlanVisitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
  {

  }

  void PlanVisitor::Visit_package(const package& pkg)
  {

  }

  void PlanVisitor::Visit_PackageConfigurationReference(const PackageConfigurationReference& pcr)
  {

  }

  void PlanVisitor::Visit_PackageConfigurations(const PackageConfigurations& pcs)
  {

  }

  void PlanVisitor::Visit_PackageConfigurationContainer(const PackageConfigurationContainer& pcc)
  {

  }

  void PlanVisitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
  {

  }

  void PlanVisitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty&)
  {}

  void PlanVisitor::Visit_PackageConfReference(const PackageConfReference&)
  {}

  void PlanVisitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
  {}

  void PlanVisitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
  {}

  void PlanVisitor::Visit_PackageConfBasePackage(const PackageConfBasePackage&)
  {}

  void PlanVisitor::Visit_ComponentPackageReference(const ComponentPackageReference&)
  {}

  void PlanVisitor::Visit_DeploymentPlans(const DeploymentPlans& dps)
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

  void PlanVisitor::Visit_DeploymentPlan(const DeploymentPlan& dp)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
	name += dp.name();
    name += ".cdp";
    this->initTarget (name);
    this->initDocument ("Deployment:DeploymentPlan");
    this->initRootAttributes();

	std::string label = dp.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
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

  void PlanVisitor::Visit_ComponentAssembly(const ComponentAssembly& assembly)
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

  void PlanVisitor::Visit_InstanceMapping(const InstanceMapping& ins_map)
  {
    NodeReference node_ref = ins_map.dstInstanceMapping_end();
    node_ref.Accept (*this);
  }

  void PlanVisitor::Visit_NodeReference(const NodeReference& node_ref)
  {
  }

}
