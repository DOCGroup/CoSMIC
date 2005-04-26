#include "PackageVisitor.h"
#include "UmlExt.h"

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

  void PackageVisitor::Visit_RootFolder(const RootFolder& rf)
  {
    { // Extra scopes to avoid clashing for-loop counter variable names
      // with MSVC6's compiler. Yuck!
      std::set<ComponentImplementations>
        folders = rf.ComponentImplementations_kind_children();
      for (std::set<ComponentImplementations>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ComponentImplementations folder = *iter;
          folder.Accept (*this);
        }
    }
    {
      std::set<ComponentPackages>
        folders = rf.ComponentPackages_kind_children();
      for (std::set<ComponentPackages>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ComponentPackages folder = *iter;
          folder.Accept (*this);
        }
    }
    {
      std::set<ComponentTypes>
        folders = rf.ComponentTypes_kind_children();
      for (std::set<ComponentTypes>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ComponentTypes folder = *iter;
          folder.Accept (*this);
        }
    }
    {
      std::set<ImplementationArtifacts>
        folders = rf.ImplementationArtifacts_kind_children();
      for (std::set<ImplementationArtifacts>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ImplementationArtifacts folder = *iter;
          folder.Accept (*this);
        }
    }
    {
      std::set<TopLevelPackages>
        folders = rf.TopLevelPackages_kind_children();
      for (std::set<TopLevelPackages>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          TopLevelPackages folder = *iter;
          folder.Accept (*this);
        }
    }
    {
      std::set<PackageConfigurations>
        folders = rf.PackageConfigurations_kind_children();
      for (std::set<PackageConfigurations>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          PackageConfigurations folder = *iter;
          folder.Accept (*this);
        }
    }
  }

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
      uuid = ia.getPath ("_",false,true);
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
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("execParameter"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    Property ref = param.dstArtifactExecParameter_end();
    ref.Accept (*this);
    this->pop();
  }

  void PackageVisitor::Visit_Property(const Property& property)
  {
    this->push();
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
    PredefinedType ref = type.ref();
    std::string refName = ref.name();
    if (refName == "Boolean")
      {
        this->curr_->appendChild (this->createSimpleContent ("boolean",
                                                             property.DataValue()));
      }
    else if (refName == "Byte")
      {
        this->curr_->appendChild (this->createSimpleContent ("octet",
                                                             property.DataValue()));
      }
    else if (refName == "String")
      {
        this->curr_->appendChild (this->createSimpleContent ("string",
                                                             property.DataValue()));
      }
    else if (refName == "RealNumber")
      {
        this->curr_->appendChild (this->createSimpleContent ("double",
                                                             property.DataValue()));
      }
    else if (refName == "ShortInteger")
      {
        this->curr_->appendChild (this->createSimpleContent ("short",
                                                             property.DataValue()));
      }
    else if (refName == "LongInteger")
      {
        this->curr_->appendChild (this->createSimpleContent ("long",
                                                             property.DataValue()));
      }
    this->pop();
  }

  void PackageVisitor::Visit_DataType(const DataType& type)
  {
    PredefinedType ref = type.ref();
    std::string kindName = ref.name();
    if (kindName == "Boolean")
      {
        Boolean boolv = PICML::Boolean::Cast (ref);
        boolv.Accept (*this);
      }
    else if (kindName == "Byte")
      {
        Byte byte = PICML::Byte::Cast (ref);
        byte.Accept (*this);
      }
    else if (kindName == "String")
      {
        String str = PICML::String::Cast (ref);
        str.Accept (*this);
      }
    else if (kindName == "RealNumber")
      {
        RealNumber real = PICML::RealNumber::Cast (ref);
        real.Accept (*this);
      }
    else if (kindName == "ShortInteger")
      {
        ShortInteger shortv = PICML::ShortInteger::Cast (ref);
        shortv.Accept (*this);
      }
    else if (kindName == "LongInteger")
      {
        LongInteger lint = PICML::LongInteger::Cast (ref);
        lint.Accept (*this);
      }
  }

  // Predefined Types
  void PackageVisitor::Visit_Boolean(const Boolean& boolean)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_boolean"));
    this->pop();

  }

  void PackageVisitor::Visit_Byte(const Byte& byte)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_octet"));
    this->pop();
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

  void PackageVisitor::Visit_RealNumber(const RealNumber& real)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_double"));
    this->pop();
  }

  void PackageVisitor::Visit_ShortInteger(const ShortInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_short"));
    this->pop();
  }

  void PackageVisitor::Visit_LongInteger(const LongInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_long"));
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

    PackageConfBasePackage bp = pc.dstPackageConfBasePackage();
    if (bp != Udm::null)
      bp.Accept (*this);
    else
      {
        PackageConfReference pcr = pc.dstPackageConfReference();
        if (pcr != Udm::null)
          pcr.Accept (*this);
        else
          {
            PackageConfSpecializedConfig
              pcsc = pc.dstPackageConfSpecializedConfig();
            if (pcsc != Udm::null)
              pcsc.Accept (*this);
          }
      }
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_PackageConfBasePackage(const PackageConfBasePackage& pcbp)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("basePackage"));
    const ComponentPackage pkg = pcbp.dstPackageConfBasePackage_end();
    std::string pkgName (pkg.name());
    pkgName += ".cpd";
    ele->setAttribute (XStr ("href"), XStr (pkgName));
    this->curr_->appendChild (ele);
    this->pop();
  }


  void PackageVisitor::Visit_PackageConfReference(const PackageConfReference& pkgconfref)
  {
    ComponentPackageReference pkgref = pkgconfref.dstPackageConfReference_end();
    pkgref.Accept (*this);
  }

  void PackageVisitor::Visit_ComponentPackageReference(const ComponentPackageReference& pkgref)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("basePackage"));
    ComponentPackage pkg = pkgref.ref();
    std::string pkgName (pkg.name());
    pkgName += ".cpd";
    ele->setAttribute (XStr ("href"), XStr (pkgName));
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty&)
  {}

  void PackageVisitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
  {}

  void PackageVisitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
  {}


  void PackageVisitor::Visit_ComponentPackages(const ComponentPackages& cps)
  {
    std::set<PackageContainer> pcs = cps.PackageContainer_kind_children();
    for (std::set<PackageContainer>::iterator iter = pcs.begin();
         iter != pcs.end();
         ++iter)
      {
        PackageContainer pc = *iter;
        pc.Accept (*this);
      }
  }

  void PackageVisitor::Visit_PackageContainer(const PackageContainer& pc)
  {
    std::set<ComponentPackage> cps = pc.ComponentPackage_kind_children();
    for (std::set<ComponentPackage>::iterator iter = cps.begin();
         iter != cps.end();
         ++iter)
      {
        ComponentPackage cp = *iter;
        cp.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ComponentPackage(const ComponentPackage& cp)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += cp.name();
    name += ".cpd";
    this->initTarget (name);
    this->initDocument ("Deployment:ComponentPackageDescription");
    this->initRootAttributes();

    std::string label = cp.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
    std::string uuid = cp.UUID();
    if (uuid.empty())
      uuid = cp.getPath ("_",false,true);
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

    PackageInterface pi = cp.dstPackageInterface();
    if (pi != Udm::null)
      pi.Accept (*this);

    std::set<Implementation> impls = cp.dstImplementation();
    for (std::set<Implementation>::const_iterator it = impls.begin();
         it != impls.end();
         ++it)
      {
        Implementation impl = *it;
        impl.Accept (*this);
      }
    // Dump out an ComponentPackageDescription file
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_PackageInterface(const PackageInterface& pi)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("realizes"));
    const ComponentRef cref = pi.dstPackageInterface_end();
    const Component comp  = cref.ref();
    std::string refName (comp.name());
    refName += ".ccd";
    ele->setAttribute (XStr ("href"), XStr (refName));
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_Implementation(const Implementation& impl)
  {
    ComponentImplementationReference cir = impl.dstImplementation_end();
    cir.Accept (*this);
  }

  void PackageVisitor::Visit_ComponentImplementationReference(const ComponentImplementationReference& cir)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("implementation"));
    ele->appendChild (this->createSimpleContent ("name", cir.name()));
    const ComponentImplementation ref = cir.ref();
    std::string refName (ref.name());
    refName += ".cid";
    DOMElement*
      refEle = this->doc_->createElement (XStr ("referencedImplementation"));
    refEle->setAttribute (XStr ("href"), XStr (refName));
    ele->appendChild (refEle);
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_PackageConfigProperty(const PackageConfigProperty&)
  {}

  void PackageVisitor::Visit_PackageInfoProperty(const PackageInfoProperty&)
  {}

  void PackageVisitor::Visit_ComponentTypes(const ComponentTypes& cts)
  {
    std::set<ComponentContainer> ccs = cts.ComponentContainer_kind_children();
    for (std::set<ComponentContainer>::iterator iter = ccs.begin();
         iter != ccs.end();
         ++iter)
      {
        ComponentContainer cc = *iter;
        cc.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ComponentContainer(const ComponentContainer& cc)
  {
    std::set<ComponentRef> cts = cc.ComponentRef_kind_children();
    for (std::set<ComponentRef>::iterator iter = cts.begin();
         iter != cts.end();
         ++iter)
      {
        ComponentRef ct = *iter;
        ct.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ComponentRef(const ComponentRef& ct)
  {
    Component comp = ct.ref();
    comp.Accept (*this);
  }

  void PackageVisitor::Visit_Component(const Component& comp)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += comp.name();
    name += ".ccd";
    this->initTarget (name);
    this->initDocument ("Deployment:ComponentInterfaceDescription");
    this->initRootAttributes();

    std::string label = comp.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
    std::string uuid = comp.UUID();
    if (uuid.empty())
      uuid = comp.getPath ("_",false,true);
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

//     Package parent = comp.Package_parent();
//     std::string pkg = "";
//     for (; parent != Udm::null; parent = parent.Package_parent())
//       {
//         std::string pcomp = parent.name();
//         pkg = pcomp + "_" + pkg;
//       }
//     std::string specificType = "IDL:" + pkg + std::string (comp.name())+ ":1.0";
//     this->curr_->appendChild (this->createSimpleContent ("specificType",
//                                                          specificType));

    const std::set<OutEventPort> oeps = comp.OutEventPort_kind_children();
    for (std::set<OutEventPort>::const_iterator it1 = oeps.begin();
         it1 != oeps.end();
         ++it1)
      {
        OutEventPort oep = *it1;
        oep.Accept (*this);
      }

    const std::set<InEventPort> ieps = comp.InEventPort_kind_children();
    for (std::set<InEventPort>::const_iterator it2 = ieps.begin();
         it2 != ieps.end();
         ++it2)
      {
        InEventPort iep = *it2;
        iep.Accept (*this);
      }

    const std::set<ProvidedRequestPort>
      facets = comp.ProvidedRequestPort_kind_children();
    for (std::set<ProvidedRequestPort>::const_iterator it3 = facets.begin();
         it3 != facets.end();
         ++it3)
      {
        ProvidedRequestPort facet = *it3;
        facet.Accept (*this);
      }

    const std::set<RequiredRequestPort>
      receps = comp.RequiredRequestPort_kind_children();
    for (std::set<RequiredRequestPort>::const_iterator it4 = receps.begin();
         it4 != receps.end();
         ++it4)
      {
        RequiredRequestPort recep = *it4;
        recep.Accept (*this);
      }

    // Dump out an ComponentInterfaceDescription file
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_OutEventPort(const OutEventPort& oep)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("port"));
    ele->appendChild (this->createSimpleContent ("name", oep.name()));
    ele->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                 oep.exclusiveProvider() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("exclusiveUser",
                                                 oep.exclusiveUser() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("optional",
                                                 oep.optional() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("provider", "true"));

    // Check whether it is a RT_Event_Channel out port
    std::string out_port_type = oep.out_event_port_type ();
    if (oep.exclusiveProvider())
    {
      if (out_port_type == "DirectConnect")
        ele->appendChild (this->createSimpleContent ("kind", "EventEmitter"));
      else // must be RT Event Channel
        ele->appendChild (this->createSimpleContent ("kind", "rtecEventEmitter"));
    }
    else
    {
      if (out_port_type == "DirectConnect")
        ele->appendChild (this->createSimpleContent ("kind", "EventPublisher"));
      else // must be RT Event Channel
        ele->appendChild (this->createSimpleContent ("kind", "rtecEventPublisher"));
    }

    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_InEventPort(const InEventPort& iep)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("port"));
    ele->appendChild (this->createSimpleContent ("name", iep.name()));
    ele->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                 iep.exclusiveProvider() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("exclusiveUser",
                                                 iep.exclusiveUser() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("optional",
                                                 iep.optional() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("provider", "false"));
    ele->appendChild (this->createSimpleContent ("kind", "EventConsumer"));
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_ProvidedRequestPort(const ProvidedRequestPort& facet)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("port"));
    ele->appendChild (this->createSimpleContent ("name", facet.name()));
    ele->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                 facet.exclusiveProvider() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("exclusiveUser",
                                                 facet.exclusiveUser() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("optional",
                                                 facet.optional() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("provider", "true"));
    ele->appendChild (this->createSimpleContent ("kind", "Facet"));
    this->curr_->appendChild (ele);
    this->pop();
  }


  void PackageVisitor::Visit_RequiredRequestPort(const RequiredRequestPort& recep)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("port"));
    ele->appendChild (this->createSimpleContent ("name", recep.name()));
    ele->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                 recep.exclusiveProvider() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("exclusiveUser",
                                                 recep.exclusiveUser() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("optional",
                                                 recep.optional() ? "true" : "false"));
    ele->appendChild (this->createSimpleContent ("provider", "false"));
    ele->appendChild (this->createSimpleContent ("kind",
                                                 recep.multiple_connections() ? "MultiplexReceptacle" : "SimplexReceptacle"));
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_ComponentPropertyDescription(const ComponentPropertyDescription&)
  {}

  void PackageVisitor::Visit_ComponentProperty(const ComponentProperty&)
  {}

  void PackageVisitor::Visit_ComponentInfoProperty(const ComponentInfoProperty&)
  {}

  void PackageVisitor::Visit_ComponentConfigProperty(const ComponentConfigProperty&)
  {}

  void PackageVisitor::Visit_Supports(const Supports&)
  {}

  void PackageVisitor::Visit_Object(const Object&)
  {}

  void PackageVisitor::Visit_ComponentImplementations(const ComponentImplementations& cimpls)
  {
    std::set<ComponentImplementationContainer>
      cics = cimpls.ComponentImplementationContainer_kind_children();
    for (std::set<ComponentImplementationContainer>::iterator
           iter = cics.begin();
         iter != cics.end();
         ++iter)
      {
        ComponentImplementationContainer cc = *iter;
        cc.Accept (*this);
      }
  }

  void PackageVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& cic)
  {
    std::set<MonolithicImplementation>
      mimpls = cic.MonolithicImplementation_kind_children();
    for (std::set<MonolithicImplementation>::iterator iter = mimpls.begin();
         iter != mimpls.end();
         ++iter)
      {
        MonolithicImplementation mimpl = *iter;
        mimpl.Accept (*this);
      }

    std::set<ComponentAssembly> asms = cic.ComponentAssembly_kind_children();
    for (std::set<ComponentAssembly>::iterator it = asms.begin();
         it != asms.end();
         ++it)
      {
        ComponentAssembly assembly = *it;
        assembly.Accept (*this);
      }
  }

  void PackageVisitor::Visit_MonolithicImplementation(const MonolithicImplementation& mimpl)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += mimpl.name();
    name += ".cid";
    this->initTarget (name);
    this->initDocument ("Deployment:ComponentImplementationDescription");
    this->initRootAttributes();

    std::string label = mimpl.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
    std::string uuid = mimpl.UUID();
    if (uuid.empty())
      uuid = mimpl.getPath ("_",false,true);
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

    const std::set<Implements> impls = mimpl.dstImplements();
    for (std::set<Implements>::const_iterator iter = impls.begin();
         iter != impls.end();
         ++iter)
      {
        Implements impl = *iter;
        impl.Accept (*this);
      }
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("monolithicImpl"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    const std::set<MonolithprimaryArtifact>
      mpas = mimpl.dstMonolithprimaryArtifact();
    for (std::set<MonolithprimaryArtifact>::const_iterator it = mpas.begin();
         it != mpas.end();
         ++it)
      {
        MonolithprimaryArtifact mpa = *it;
        mpa.Accept (*this);
      }
    this->pop();
    const std::set<ConfigProperty>
      cps = mimpl.dstConfigProperty();
    for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
         it2 != cps.end();
         ++it2)
      {
        ConfigProperty cp = *it2;
        cp.Accept (*this);
      }

    // Dump out an ComponentImplementationDescription file
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_Implements(const Implements& impl)
  {
    this->push();
    const ComponentRef iface = impl.dstImplements_end();
    const Component ref = iface.ref();
    std::string refName (ref.name());
    refName += ".ccd";
    DOMElement*
      refEle = this->doc_->createElement (XStr ("implements"));
    refEle->setAttribute (XStr ("href"), XStr (refName));
    this->curr_->appendChild (refEle);
    this->pop();
  }

  void PackageVisitor::Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact& mpa)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("primaryArtifact"));
    const ImplementationArtifactReference iaref = mpa.dstMonolithprimaryArtifact_end();
    const ImplementationArtifact ref = iaref.ref();
    ele->appendChild (this->createSimpleContent ("name", ref.name()));
    std::string refName (ref.name());
    refName += ".iad";
    DOMElement*
      refEle = this->doc_->createElement (XStr ("referencedArtifact"));
    refEle->setAttribute (XStr ("href"), XStr (refName));
    ele->appendChild (refEle);
    this->curr_->appendChild (ele);
    this->pop();
  }

  void PackageVisitor::Visit_ConfigProperty(const ConfigProperty& cp)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("configProperty"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    Property ref = cp.dstConfigProperty_end();
    ref.Accept (*this);
    this->pop();
  }

  void PackageVisitor::Visit_AssemblyConfigProperty(const AssemblyConfigProperty& acp)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("configProperty"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    Property ref = acp.dstAssemblyConfigProperty_end();
    ref.Accept (*this);
    this->pop();
  }


  void PackageVisitor::Visit_ComponentAssembly(const ComponentAssembly& assembly)
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

    this->push();
    std::string name = this->outputPath_ + "\\";
    name += assembly.name();
    name += ".cid";
    this->initTarget (name);
    this->initDocument ("Deployment:ComponentImplementationDescription");
    this->initRootAttributes();

    std::string label = assembly.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));
    std::string uuid = assembly.UUID();
    if (uuid.empty())
      uuid = assembly.getPath ("_",false,true);
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("assemblyImpl"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    std::set<Component> comps = assembly.Component_kind_children();
    std::vector<ComponentAssembly> nasms = assembly.ComponentAssembly_kind_children();
    std::vector<ComponentAssembly> assemblies;
    assemblies.push_back (assembly);
    while (!nasms.empty())
      {
        ComponentAssembly rassembly = nasms.back();
        assemblies.push_back (rassembly);
        nasms.pop_back();
        std::set<Component> rcomps = rassembly.Component_kind_children();
        comps.insert (rcomps.begin(), rcomps.end());
        std::vector<ComponentAssembly> rasms = rassembly.ComponentAssembly_kind_children();
        std::copy (rasms.begin(), rasms.end(), std::back_inserter (nasms));
      }

    for (std::set<Component>::iterator iter = comps.begin();
         iter != comps.end();
         ++iter)
      {
        Component comp = *iter;
        DOMElement* instance = this->doc_->createElement (XStr ("instance"));
        this->curr_->appendChild (instance);
        this->push();
        this->curr_ = instance;
        std::string uniqueName = comp.getPath ("_",false,true);
        instance->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
        instance->appendChild (this->createSimpleContent ("name",
                                                          uniqueName));
        std::string refName = comp.name();
        refName += ".cpd";
        DOMElement* refEle = this->doc_->createElement (XStr ("package"));
        refEle->setAttribute (XStr ("href"), XStr (refName));
        instance->appendChild (refEle);
        const std::set<AssemblyConfigProperty>
          cps = comp.dstAssemblyConfigProperty();
        for (std::set<AssemblyConfigProperty>::const_iterator it2 = cps.begin();
             it2 != cps.end();
             ++it2)
          {
            AssemblyConfigProperty cp = *it2;
            cp.Accept (*this);
          }
        this->pop();
      }
    for (std::vector<ComponentAssembly>::iterator iter = assemblies.begin();
         iter != assemblies.end();
         ++iter)
      {
        ComponentAssembly subasm = *iter;
        const std::set<invoke> invokes = subasm.invoke_kind_children();
        for (std::set<invoke>::const_iterator iter = invokes.begin();
             iter != invokes.end();
             ++iter)
          {
            invoke iv = *iter;
            iv.Accept (*this);
          }
        const std::set<emit> emits = subasm.emit_kind_children();
        for (std::set<emit>::const_iterator iter = emits.begin();
             iter != emits.end();
             ++iter)
          {
            emit ev = *iter;
            ev.Accept (*this);
          }
        const std::set<publish> publishers = subasm.publish_kind_children();
        for (std::set<publish>::const_iterator iter = publishers.begin();
             iter != publishers.end();
             ++iter)
          {
            publish ev = *iter;
            ev.Accept (*this);
          }
        const std::set<deliverTo> deliverTos = subasm.deliverTo_kind_children();
        for (std::set<deliverTo>::const_iterator iter = deliverTos.begin();
             iter != deliverTos.end();
             ++iter)
          {
            deliverTo dv = *iter;
            dv.Accept (*this);
          }
        const std::set<PublishConnector>
          connectors = subasm.PublishConnector_kind_children();
        for (std::set<PublishConnector>::const_iterator iter = connectors.begin();
             iter != connectors.end();
             ++iter)
          {
            PublishConnector conn = *iter;
            conn.Accept (*this);
          }
      }

    this->pop();

    // Dump out an ComponentImplementationDescription file
    this->dumpDocument();
    this->pop();
  }

  void PackageVisitor::Visit_invoke(const invoke& iv)
  {
    this->push();

    DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    // Get the receptacle end
    RequiredRequestPort receptacle = iv.srcinvoke_end();
    Component recep_comp;
    while (true)
      {
        Udm::Object par = receptacle.parent();
        if (Udm::IsDerivedFrom (par.type(), Component::meta))
          {
            recep_comp = Component::Cast (par);
            break;
          }
        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
          {
            ReceptacleDelegate delegate = receptacle.dstReceptacleDelegate();
            if (delegate != Udm::null)
              receptacle = delegate.dstReceptacleDelegate_end();
            else
              {
                delegate = receptacle.srcReceptacleDelegate();
                receptacle = delegate.srcReceptacleDelegate_end();
              }
          }
      }

    // Get the facet end
    ProvidedRequestPort facet = iv.dstinvoke_end();
    Component facet_comp;
    while (true)
      {
        Udm::Object par = facet.parent();
        if (Udm::IsDerivedFrom (par.type(), Component::meta))
          {
            facet_comp = Component::Cast (par);
            break;
          }
        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
          {
            FacetDelegate delegate = facet.dstFacetDelegate();
            if (delegate != Udm::null)
              facet = delegate.dstFacetDelegate_end();
            else
              {
                delegate = facet.srcFacetDelegate();
                facet = delegate.srcFacetDelegate_end();
              }
          }
      }

    // Create a connection
    std::string connection = receptacle.name();
    connection += "_";
    connection += facet.name();
    ele->appendChild (this->createSimpleContent ("name", connection));

    // Facet endPoint
    DOMElement* endPoint
      = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      facet.name()));
    // Facet instance
    DOMElement* instance = this->doc_->createElement (XStr ("instance"));
    instance->setAttribute (XStr ("xmi:idref"),
                            XStr (facet_comp.getPath ("_", false, true)));
    endPoint->appendChild (instance);
    ele->appendChild (endPoint);

    // Receptacle endPoint
    endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      receptacle.name()));
    // Receptacle instance
    instance = this->doc_->createElement (XStr ("instance"));
    instance->setAttribute (XStr ("xmi:idref"),
                            XStr (recep_comp.getPath ("_", false, true)));
    endPoint->appendChild (instance);
    ele->appendChild (endPoint);

    this->pop();
  }

  void PackageVisitor::Visit_emit(const emit& ev)
  {
    this->push();

    DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    // Get the emitter end
    OutEventPort emitter = ev.srcemit_end();
    Component emitter_comp;
    while (true)
      {
        Udm::Object par = emitter.parent();
        if (Udm::IsDerivedFrom (par.type(), Component::meta))
          {
            emitter_comp = Component::Cast (par);
            break;
          }
        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
          {
            EventSourceDelegate delegate = emitter.dstEventSourceDelegate();
            if (delegate != Udm::null)
              emitter = delegate.dstEventSourceDelegate_end();
            else
              {
                delegate = emitter.srcEventSourceDelegate();
                emitter = delegate.srcEventSourceDelegate_end();
              }
          }
      }

    // Get the consumer end
    InEventPort consumer = ev.dstemit_end();
    Component consumer_comp;
    while (true)
      {
        Udm::Object par = consumer.parent();
        if (Udm::IsDerivedFrom (par.type(), Component::meta))
          {
            consumer_comp = Component::Cast (par);
            break;
          }
        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
          {
            EventSinkDelegate delegate = consumer.dstEventSinkDelegate();
            if (delegate != Udm::null)
              consumer = delegate.dstEventSinkDelegate_end();
            else
              {
                delegate = consumer.srcEventSinkDelegate();
                consumer = delegate.srcEventSinkDelegate_end();
              }
          }
      }

    // Create a connection
    std::string connection = consumer.name();
    connection += "_";
    connection += emitter.name();
    ele->appendChild (this->createSimpleContent ("name", connection));

    // Emitter endPoint
    DOMElement* endPoint
      = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      emitter.name()));
    // Emitter instance
    DOMElement* instance = this->doc_->createElement (XStr ("instance"));
    instance->setAttribute (XStr ("xmi:idref"),
                            XStr (emitter_comp.getPath ("_", false, true)));
    endPoint->appendChild (instance);
    ele->appendChild (endPoint);

    // Consumer endPoint
    endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      consumer.name()));
    // Consumer instance
    instance = this->doc_->createElement (XStr ("instance"));
    instance->setAttribute (XStr ("xmi:idref"),
                            XStr (consumer_comp.getPath ("_", false, true)));
    endPoint->appendChild (instance);
    ele->appendChild (endPoint);

    this->pop();
  }

  void PackageVisitor::Visit_publish(const publish& ev)
  {
    // Get the publisher end
    const OutEventPort publisher = ev.srcpublish_end();

    // Get the connector end
    const PublishConnector connector = ev.dstpublish_end();

    // Create an entry in the publishers_ map
    this->publishers_[std::string (connector.name())] = publisher;
  }

  void PackageVisitor::Visit_deliverTo(const deliverTo& dv)
  {
    // Get the connector end
    const  PublishConnector connector = dv.srcdeliverTo_end();

    // Get the consumer end
    const InEventPort consumer = dv.dstdeliverTo_end();

    // Create an entry in the consumers_ map
    this->consumers_.insert (make_pair (std::string (connector.name()),
                                        consumer));
  }

  void PackageVisitor::Visit_PublishConnector(const PublishConnector& pubctor)
  {
    std::string ctor = pubctor.name();

    // Get Publisher
    OutEventPort publisher = this->publishers_[ctor];
    Component publisher_comp;

    while (true)
      {
        Udm::Object par = publisher.parent();
        if (Udm::IsDerivedFrom (par.type(), Component::meta))
          {
            publisher_comp = Component::Cast (par);
            break;
          }
        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
          {
            EventSourceDelegate delegate = publisher.dstEventSourceDelegate();
            if (delegate != Udm::null)
              publisher = delegate.dstEventSourceDelegate_end();
            else
              {
                delegate = publisher.srcEventSourceDelegate();
                publisher = delegate.srcEventSourceDelegate_end();
              }
          }
      }

    for (std::multimap<std::string, InEventPort>::const_iterator
           iter = this->consumers_.lower_bound (ctor);
         iter != this->consumers_.upper_bound (ctor);
         ++iter)
      {
        this->push();

        DOMElement* ele = this->doc_->createElement (XStr ("connection"));
        this->curr_->appendChild (ele);
        this->curr_ = ele;

        // Get Consumer
        InEventPort consumer = iter->second;
        Component consumer_comp;

        while (true)
          {
            Udm::Object par = consumer.parent();
            if (Udm::IsDerivedFrom (par.type(), Component::meta))
              {
                consumer_comp = Component::Cast (par);
                break;
              }
            else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
              {
                EventSinkDelegate delegate = consumer.dstEventSinkDelegate();
                if (delegate != Udm::null)
                  consumer = delegate.dstEventSinkDelegate_end();
                else
                  {
                    delegate = consumer.srcEventSinkDelegate();
                    consumer = delegate.srcEventSinkDelegate_end();
                  }
              }
          }

        // Create connection(s)
        std::string connection = consumer.name();
        connection += "_";
        connection += publisher.name();
        ele->appendChild (this->createSimpleContent ("name", connection));

        // Publisher endPoint
        DOMElement* endPoint
          = this->doc_->createElement (XStr ("internalEndpoint"));
        endPoint->appendChild (this->createSimpleContent ("portName",
                                                          publisher.name()));
        // Publisher instance
        DOMElement* instance = this->doc_->createElement (XStr ("instance"));
        instance->setAttribute (XStr ("xmi:idref"),
                                XStr (publisher_comp.getPath ("_", false,
                                                              true)));
        endPoint->appendChild (instance);
        ele->appendChild (endPoint);

        // Consumer endPoint
        endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
        endPoint->appendChild (this->createSimpleContent ("portName",
                                                          consumer.name()));
        // Consumer instance
        instance = this->doc_->createElement (XStr ("instance"));
        instance->setAttribute (XStr ("xmi:idref"),
                                XStr (consumer_comp.getPath ("_", false,
                                                             true)));
        endPoint->appendChild (instance);
        ele->appendChild (endPoint);

        this->pop();
      }
  }

  void PackageVisitor::Visit_MonolithExecParameter(const MonolithExecParameter&)
  {}

  void PackageVisitor::Visit_Requirement(const Requirement&)
  {}

  void PackageVisitor::Visit_SatisfierProperty(const SatisfierProperty&)
  {}

  void PackageVisitor::Visit_ImplementationDependency(const ImplementationDependency&)
  {}

  void PackageVisitor::Visit_Capability(const Capability&)
  {}

  void PackageVisitor::Visit_AssemblyselectRequirement(const AssemblyselectRequirement&)
  {}


  void PackageVisitor::Visit_AssemblyDeployRequirement(const AssemblyDeployRequirement&)
  {}


  void PackageVisitor::Visit_InfoProperty(const InfoProperty&)
  {}


  void PackageVisitor::Visit_MonolithDeployRequirement(const MonolithDeployRequirement&)
  {}


  void PackageVisitor::Visit_ImplementationDependsOn(const ImplementationDependsOn&)
  {}


  void PackageVisitor::Visit_ImplementationCapability(const ImplementationCapability&)
  {}
}
