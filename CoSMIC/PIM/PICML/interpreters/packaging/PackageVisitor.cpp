#include <afxdlgs.h> // For CFileDialog
#include "PackageVisitor.h"
#include "UuidString.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

namespace PICML
{
  PackageVisitor::PackageVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), target_ (0),
      outputPath_ (outputPath)
  {
    this->init();
  }

  PackageVisitor::~PackageVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
  }

  void PackageVisitor::init()
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

  void PackageVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void PackageVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (XStr ("http://www.omg.org/Deployment"),
                                   XStr (rootName.c_str()),
                                   0);
  }

  void PackageVisitor::initRootAttributes()
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

  void PackageVisitor::dumpDocument()
  {
    this->serializer_->writeNode (this->target_, *this->doc_);
  }

  void PackageVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void PackageVisitor::pop()
  {
    if (!this->curr_stack_.empty())
      {
        this->curr_ = this->curr_stack_.top();
        this->curr_stack_.pop();
      }
    else
      {
        AfxMessageBox("Oops..Mismatch in push()/pop()");
        throw(std::exception());
      }
  }

  DOMElement* PackageVisitor::createSimpleContent (const std::string& name,
                                                   const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  void PackageVisitor::Visit_RootFolder(const RootFolder&)
  {}

  // Predefined Types
  void PackageVisitor::Visit_LongInteger(const LongInteger&)
  {}

  void PackageVisitor::Visit_Boolean(const Boolean&)
  {}

  void PackageVisitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void PackageVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {
    std::set<ArtifactContainer>
      afs = ia.ArtifactContainer_kind_children();
    for (std::set<ArtifactContainer>::iterator iter = afs.begin();
         iter != afs.end();
         ++iter)
      {
        ArtifactContainer ac = *iter;
        ac.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
  {
    const std::set<ImplementationArtifact>
      ias = ac.ImplementationArtifact_kind_children();
    for (std::set<ImplementationArtifact>::const_iterator iter = ias.begin();
         iter != ias.end();
         ++iter)
      {
        ImplementationArtifact ia = *iter;
        ia.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += ia.name();
    name += ".iad";
    this->initTarget (name);
    this->initDocument ("Deployment:ImplementationArtifactDescription");
    this->initRootAttributes();

    std::string label = ia.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
    std::string uuid = ia.UUID();
    if (uuid.empty())
      uuid = PICML::MakeUuidString();
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

    std::string location = ia.location();
    if (!location.empty())
      this->curr_->appendChild (this->createSimpleContent ("location",
                                                           location));

    const std::set<ArtifactDependsOn> dps = ia.dstArtifactDependsOn();
    for (std::set<ArtifactDependsOn>::const_iterator iter = dps.begin();
         iter != dps.end();
         ++iter)
      {
        ArtifactDependsOn ad = *iter;
        ad.Accept (*this);
      }

    const std::set<ArtifactExecParameter> exec = ia.dstArtifactExecParameter();
    for (std::set<ArtifactExecParameter>::const_iterator it = exec.begin();
         it != exec.end();
         ++it)
      {
        ArtifactExecParameter aep = *it;
        aep.Accept (*this);
      }
    // Dump out an ImplementationArtifactDescription file
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {
    ImplementationArtifactReference ref = ado.dstArtifactDependsOn_end();
    ref.Accept (*this);
  }

  void PackageVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("dependsOn"));
    ele->appendChild (this->createSimpleContent ("name", iar.name()));
    const ImplementationArtifact ref = iar.ref();
    std::string refName (ref.name());
    refName += ".iad";
    DOMElement*
      refEle = this->doc_->createElement (XStr ("referencedArtifact"));
    refEle->setAttribute (XStr ("href"), XStr (refName));
    ele->appendChild (refEle);
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {
    Property ref = param.dstArtifactExecParameter_end();
    ref.Accept (*this);
  }

  void PackageVisitor::Visit_Property(const Property& property)
  {
    this->push();
    DOMElement* ele = 0;
    set<ArtifactExecParameter> ias = property.srcArtifactExecParameter();
    if (!ias.empty())
      {
        ele = this->doc_->createElement (XStr ("execParameter"));
      }
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    this->curr_->appendChild (this->createSimpleContent ("name",
                                                         property.name()));
    // Property's value
    DOMElement* value = this->doc_->createElement (XStr ("value"));
    this->curr_->appendChild (value);
    this->curr_ = value;
    // Property's type
    DataType type = property.DataType_child();
    type.Accept (*this);
    // Property's type's value
    DOMElement* val = this->doc_->createElement (XStr ("value"));
    this->curr_->appendChild (val);
    this->curr_ = val;
    this->curr_->appendChild (this->createSimpleContent ("string",
                                                         property.DataValue()));
    this->pop();
  }

  void PackageVisitor::Visit_DataType(const DataType& type)
  {
    PredefinedType ref = type.ref();
    std::string kindName = ref.name();
    if (kindName == "String")
      {
        String str = PICML::String::Cast (ref);
        str.Accept (*this);
      }
  }

  void PackageVisitor::Visit_String(const String& str)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_string"));
    this->pop();
  }

  void PackageVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void PackageVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void PackageVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

  void PackageVisitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
  {
    std::set<TopLevelPackageContainer>
      tpcs = tp.TopLevelPackageContainer_kind_children();
    for (std::set<TopLevelPackageContainer>::iterator iter = tpcs.begin();
         iter != tpcs.end();
         ++iter)
      {
        TopLevelPackageContainer tpc = *iter;
        tpc.Accept (*this);
      }
  }


  void PackageVisitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
  {
    std::set<TopLevelPackage> tps = tpc.TopLevelPackage_kind_children();
    for (std::set<TopLevelPackage>::iterator iter = tps.begin();
         iter != tps.end();
         ++iter)
      {
        TopLevelPackage tp = *iter;
        tp.Accept (*this);
      }
  }

  void PackageVisitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
  {
    this->push();
    std::string name = this->outputPath_ + "\\package.tpd";
    this->initTarget (name);
    this->initDocument ("Deployment:TopLevelPackageDescription");
    this->initRootAttributes();

    package pkg = tp.dstpackage();
    pkg.Accept (*this);
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_package(const package& pkg)
  {
    PackageConfigurationReference pcr = pkg.dstpackage_end();
    pcr.Accept (*this);
  }

  void PackageVisitor::Visit_PackageConfigurationReference(const PackageConfigurationReference& pcr)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("package"));
    const PackageConfiguration pc = pcr.ref();
    std::string refName (pc.name());
    refName += ".pcd";
    ele->setAttribute (XStr ("href"), XStr (refName));
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_PackageConfigurations(const PackageConfigurations& pcs)
  {
    std::set<PackageConfigurationContainer>
      pccs = pcs.PackageConfigurationContainer_kind_children();
    for (std::set<PackageConfigurationContainer>::iterator iter = pccs.begin();
         iter != pccs.end();
         ++iter)
      {
        PackageConfigurationContainer pcc = *iter;
        pcc.Accept (*this);
      }
  }

  void PackageVisitor::Visit_PackageConfigurationContainer(const PackageConfigurationContainer& pcc)
  {
    std::set<PackageConfiguration>
      pcs = pcc.PackageConfiguration_kind_children();
    for (std::set<PackageConfiguration>::iterator iter = pcs.begin();
         iter != pcs.end();
         ++iter)
      {
        PackageConfiguration pc = *iter;
        pc.Accept (*this);
      }
  }

  void PackageVisitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += pc.name();
    name += ".pcd";
    this->initTarget (name);
    this->initDocument ("Deployment:PackageConfiguration");
    this->initRootAttributes();
  }

  void PackageVisitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty&)
  {}

  void PackageVisitor::Visit_PackageConfReference(const PackageConfReference&)
  {}

  void PackageVisitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
  {}

  void PackageVisitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
  {}

  void PackageVisitor::Visit_PackageConfBasePackage(const PackageConfBasePackage&)
  {}

  void PackageVisitor::Visit_ComponentPackageReference(const ComponentPackageReference&)
  {}

}
