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
  PackageVisitor::PackageVisitor (const std::string& path,
                                   const std::string& rootName)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), target_ (0),
      rootName_ (rootName)
  {
    this->target_ = new LocalFileFormatTarget (path.c_str());
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
    try
      {
        this->impl_ = DOMImplementationRegistry::getDOMImplementation(XStr("LS"));
        this->serializer_ = ((DOMImplementationLS*)impl_)->createDOMWriter();

        // set feature if the serializer supports the feature/mode
        if (this->serializer_->canSetFeature
            (XMLUni::fgDOMWRTDiscardDefaultContent, true))
          this->serializer_->setFeature (XMLUni::fgDOMWRTDiscardDefaultContent,
                                         true);

        if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTFormatPrettyPrint,
                                              true))
          this->serializer_->setFeature (XMLUni::fgDOMWRTFormatPrettyPrint, true);

        if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTBOM, false))
          this->serializer_->setFeature (XMLUni::fgDOMWRTBOM, false);

        // Create the document
        this->doc_ =
          this->impl_->createDocument (XStr ("http://www.omg.org/Deployment"),
                                       XStr (this->rootName_.c_str()),
                                       0);

      }
    catch (const DOMException& toCatch)
      {
        AfxMessageBox("Caught DOMException :" + CString (XStr (toCatch.msg).c_str()));
        return;
      }
    this->initRootAttributes();
  }

  void PackageVisitor::initRootAttributes()
  {
    try
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
    catch (const DOMException& toCatch)
      {
        AfxMessageBox("Caught DOMException :" + CString (XStr (toCatch.msg).c_str()));
        return;
      }
  }

  void PackageVisitor::dumpDocument()
  {
    try
      {
        this->serializer_->writeNode (this->target_, *this->doc_);
      }
    catch (const DOMException& toCatch)
      {
        AfxMessageBox("Caught DOMException :" + CString (XStr (toCatch.msg).c_str()));
        return;
      }
    catch (const XMLException& xmlex)
      {
        AfxMessageBox("Caught XMLException :" + CString (XStr (xmlex.getMessage()).c_str()));
        return;
      }
  }

  void PackageVisitor::Visit_RootFolder(const RootFolder&)
  {}

  // Predefined Types
  void PackageVisitor::Visit_LongInteger(const LongInteger&)
  {}

  void PackageVisitor::Visit_String(const String&)
  {}

  void PackageVisitor::Visit_Boolean(const Boolean&)
  {}

  void PackageVisitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void PackageVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts&)
  {}

  void PackageVisitor::Visit_ArtifactContainer(const ArtifactContainer&)
  {}

  void PackageVisitor::Visit_ImplementationArtifact(const ImplementationArtifact&)
  {}

  void PackageVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn&)
  {}

  void PackageVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference&)
  {}

  void PackageVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter&)
  {}

  void PackageVisitor::Visit_Property(const Property&)
  {}

  void PackageVisitor::Visit_DataType(const DataType&)
  {}

  void PackageVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void PackageVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void PackageVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

}
