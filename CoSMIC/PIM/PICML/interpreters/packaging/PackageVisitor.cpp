#include <afxdlgs.h> // For CFileDialog
#include "PackageVisitor.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;

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
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void PackageVisitor::initDocument (const std::string& rootName)
  {
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

  void PackageVisitor::Visit_RootFolder(const RootFolder&)
  {}

  // Predefined Types
  void PackageVisitor::Visit_LongInteger(const LongInteger&)
  {}

  void PackageVisitor::Visit_String(const String& str)
  {
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_string"));
  }

  void PackageVisitor::Visit_Boolean(const Boolean&)
  {}

  void PackageVisitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void PackageVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {
    const std::set<ArtifactContainer>
      afs = ia.ArtifactContainer_kind_children();
    for (std::set<ArtifactContainer>::const_iterator iter = afs.begin();
         iter != afs.end();
         ++iter)
      (*iter).Accept (*this);
  }

  void PackageVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
  {
    const std::set<ImplementationArtifact>
      ias = ac.ArtifactContainer_kind_children();
    for (std::set<ImplementationArtifact>::const_iterator iter = ias.begin();
         iter != ias.end();
         ++iter)
      (*iter).Accept (*this);
  }

  void PackageVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {
    this->initTarget (ia.name() + ".iad");
    this->initDocument ("Deployment:ImplementationArtifactDescription");
    this->initRootAttributes();
    if (!ia.label().empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           ia.label()));
    std::string uuid;
    if (ia.UUID().empty())
      uuid = PICML::MakeUuidString();
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));
    this->curr_->appendChild (this->createSimpleContent ("location",
                                                         ia.location()));
    const std::set<ArtifactDependsOn> dps = ia.dstArtifactDependsOn();
    for (std::set<ArtifactDependsOn>::const_iterator iter = dps.begin();
         iter != dps.end();
         ++iter)
      (*iter).Accept (*this);

    const std::set<ArtifactExecParameter> exec = ia.dstArtifactExecParameter();
    for (std::set<ArtifactExecParameter>::const_iterator iter = exec.begin();
         iter != exec.end();
         ++iter)
      (*iter).Accept (*this);
  }

  void PackageVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {
    const ImplementationArtifactReference ref = ado.dstArtifactDependsOn_end();
    ref.Accept (*this);
  }

  void PackageVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
  {
    DOMElement* ele = this->doc_->createElement (XStr ("dependsOn"));
    ele->appendChild (this->createSimpleContent ("name", iar.name()));
    const ImplementationArtifact ref = iar.ref();
    std::string refName = ref.name() + ".iad";
    DOMElement*
      refEle = this->doc_->createElement (XStr ("referencedArtifact"));
    refEle->setAttribute (XStr ("href"), XStr (refName));
    ele->appendChild (refEle);
    this->curr_->appendChild (ele);
  }

  void PackageVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {
    const Property ref = param.dstArtifactExecParameter_end();
    ref.Accept (*this);
  }

  void PackageVisitor::Visit_Property(const Property& property)
  {
    DOMElement* temp = this->curr_;
    DOMElement* ele;
    if (!property.srcArtifactExecParameter().empty())
      {
        ele = this->doc_->createElement (XStr ("execParameter"));
      }
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    this->curr_->appendChild (this->createSimpleContent ("name",
                                                         property.name()));
    DOMElement* value = this->doc_->createElement (XStr ("value"));
    this->curr->appendChild (value);
    this->curr_ = value;
    const DataType type = property.DataType_child();
    type.Accept (*this);
    ele->appendChild (value);
  }

  void PackageVisitor::Visit_DataType(const DataType& type)
  {
    const PredefinedType ref = type.ref();
    if (ref.type().name() == "String")
      {
        String str = PICML::String::Cast (ref);
        str.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void PackageVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void PackageVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

}
