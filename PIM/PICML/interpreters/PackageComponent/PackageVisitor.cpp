#include "ace/config.h"
#include "Utils/Utils.h"
#include "PackageVisitor.h"

#include "game/xml/String.h"

#include "boost/bind.hpp"
#include "boost/ref.hpp"
#include "UmlExt.h"

#include <algorithm>
#include <functional>
#include <sstream>

namespace PICML
{

using Utils::CreateUuid;
using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;
using std::set;
using std::vector;
using std::string;
using std::map;
using boost::bind;
using boost::ref;
using boost::cref;

PackageVisitor::PackageVisitor (const string& outputPath)
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
  this->impl_ = DOMImplementationRegistry::getDOMImplementation(GAME::Xml::String("LS"));
  this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer();

  // Set features if the serializer supports the feature/mode
  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
}

void PackageVisitor::initTarget (const string& fileName)
{
  if (this->target_)
    delete this->target_;
  this->target_ = new LocalFileFormatTarget (fileName.c_str());
}

void PackageVisitor::initDocument (const string& rootName)
{
  if (this->doc_)
    this->doc_->release();
  // Create the document
  this->doc_ =
    this->impl_->createDocument (GAME::Xml::String ("http://www.omg.org/Deployment"),
                                 GAME::Xml::String (rootName.c_str()),
                                 0);
}

void PackageVisitor::initRootAttributes()
{
  //this->doc_->setEncoding (GAME::Xml::String("UTF-8"));
  this->doc_->setXmlVersion (GAME::Xml::String("1.0"));
  this->root_ = this->doc_->getDocumentElement();
  this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                               GAME::Xml::String ("xmlns:Deployment"),
                               GAME::Xml::String ("http://www.omg.org/Deployment"));
  this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                               GAME::Xml::String ("xmlns:xsi"),
                               GAME::Xml::String ("http://www.w3.org/2001/XMLSchema-instance"));
  this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
                               GAME::Xml::String ("xmlns:xmi"),
                               GAME::Xml::String ("http://www.omg.org/XMI"));
  this->root_->setAttribute (GAME::Xml::String ("xsi:schemaLocation"),
                             GAME::Xml::String ("http://www.omg.org/Deployment Deployment.xsd"));
  this->curr_ = this->root_;
}

void PackageVisitor::dumpDocument()
{
  xercesc::DOMLSOutput * output = ((DOMImplementationLS*)this->impl_)->createLSOutput ();
  output->setByteStream (this->target_);

  this->serializer_->write (this->doc_, output);
  output->release ();
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
      throw udm_exception ("Mismatched push/pop from stack!");
    }
}

DOMElement* PackageVisitor::createSimpleContent (const string& name,
                                                 const string& value)
{
  DOMElement* pName = this->doc_->createElement (GAME::Xml::String (name.c_str()));
  DOMText* pValue = this->doc_->createTextNode (GAME::Xml::String (value.c_str()));
  pName->appendChild (pValue);
  return pName;
}

void PackageVisitor::Visit_RootFolder(const RootFolder& rf)
{
  set<RootFolder> rfolders = rf.RootFolder_kind_children();
  for_each (rfolders.begin(), rfolders.end(),
            bind (&RootFolder::Accept, _1, ref (*this)));

  set<ComponentPackages> pkgs = rf.ComponentPackages_kind_children();
  for_each (pkgs.begin(), pkgs.end(),
            bind (&ComponentPackages::Accept, _1, ref (*this)));

  set<ComponentImplementations>
    impls = rf.ComponentImplementations_kind_children();
  for_each (impls.begin(), impls.end(),
            bind (&ComponentImplementations::Accept, _1, ref (*this)));

  set<ComponentTypes>
    comps = rf.ComponentTypes_kind_children();
  for_each (comps.begin(), comps.end(),
            bind (&ComponentTypes::Accept, _1, ref (*this)));

  set<ImplementationArtifacts>
    artifacts = rf.ImplementationArtifacts_kind_children();
  for_each (artifacts.begin(), artifacts.end(),
            bind (&ImplementationArtifacts::Accept, _1, ref (*this)));

  set<TopLevelPackages>
    tlpkgs = rf.TopLevelPackages_kind_children();
  for_each (tlpkgs.begin(), tlpkgs.end(),
            bind (&TopLevelPackages::Accept, _1, ref (*this)));

  set<PackageConfigurations>
    pkgConfs = rf.PackageConfigurations_kind_children();
  for_each (pkgConfs.begin(), pkgConfs.end(),
            bind (&PackageConfigurations::Accept, _1, ref (*this)));
}

// Implementation Artifact operations

void PackageVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
{
  set<ArtifactContainer>
    afs = ia.ArtifactContainer_kind_children();
  for_each (afs.begin(), afs.end(),
            bind (&ArtifactContainer::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
{
  set<ImplementationArtifact> ias = ac.ImplementationArtifact_kind_children();
  for_each (ias.begin(), ias.end(),
            bind (&ImplementationArtifact::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
{
  this->push();
  string name = this->outputPath_ + "\\";
  name += ia.name();
  name += ".iad";
  this->initTarget (name);
  this->initDocument ("Deployment:implementationArtifactDescription");
  this->initRootAttributes();

  string label = ia.label();
  if (!label.empty())
    this->curr_->appendChild (this->createSimpleContent ("label",
                                                         label));
  string uuid (ia.UUID());
  if (uuid.empty())
    ia.UUID() = uuid = ::Utils::CreateUuid();
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

  string location = ia.location();
  this->curr_->appendChild (this->createSimpleContent ("location",
                                                       location));

  set<ArtifactDependsOn> dps = ia.dstArtifactDependsOn();
  for_each (dps.begin(), dps.end(),
            bind (&ArtifactDependsOn::Accept, _1, ref (*this)));

  set<ArtifactDependency> adps = ia.dstArtifactDependency();
  for_each (adps.begin(), adps.end(),
            bind (&ArtifactDependency::Accept, _1, ref (*this)));

  set<ArtifactExecParameter> exec = ia.dstArtifactExecParameter();
  for_each (exec.begin(), exec.end(),
            bind (&ArtifactExecParameter::Accept, _1, ref (*this)));

  set<ArtifactInfoProperty> infoProps = ia.dstArtifactInfoProperty();
  for_each (infoProps.begin(), infoProps.end(),
            bind (&ArtifactInfoProperty::Accept, _1, ref (*this)));

  // Generate all the execParameters required to ensure that the location
  // of this artifact in the Component Repository can be retrieved.
  this->GenerateExecParameters (ia);

  // Dump out an ImplementationArtifactDescription file
  this->dumpDocument();
  this->pop();
}

void PackageVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
{
  ImplementationArtifactReference ref = ado.dstArtifactDependsOn_end();
  ref.Accept (*this);
}

void PackageVisitor::Visit_ArtifactDependency(const ArtifactDependency& ado)
{
  this->push();
  ImplementationArtifact ia = ado.dstArtifactDependency_end();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("dependsOn"));
  ele->appendChild (this->createSimpleContent ("name",
                                               ia.getPath (".", false, true, "name", true)));
  string iaName (ia.name());
  iaName += ".iad";
  DOMElement*
    iaEle = this->doc_->createElement (GAME::Xml::String ("referencedArtifact"));
  iaEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (iaName));
  ele->appendChild (iaEle);
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("dependsOn"));
  const ImplementationArtifact ref = iar.ref();
  ele->appendChild (this->createSimpleContent ("name",
                                               ref.getPath (".", false, true, "name", true)));
  string refName (ref.name());
  refName += ".iad";
  DOMElement*
    refEle = this->doc_->createElement (GAME::Xml::String ("referencedArtifact"));
  refEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  ele->appendChild (refEle);
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("execParameter"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = param.dstArtifactExecParameter_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::GenerateExecParameters (const ImplementationArtifact& ia)
{
  map<string, string> params;
  params["configuration"] = ia.configuration();
  params["operatingSystem"] = ia.operatingSystem();
  params["artifactVersion"] = ia.artifactVersion();
  params["architecture"] = ia.architecture();

  for (map<string, string>::iterator iter = params.begin();
       iter != params.end();
       ++iter)
    {
      this->push();
      pair<string,string> param = *iter;
      DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("execParameter"));
      this->curr_->appendChild (ele);
      this->curr_ = ele;
      this->DumpStringProperty (param.first, param.second);
      this->pop();
    }
}

void PackageVisitor::Visit_SimpleProperty(const SimpleProperty& prop)
{
  this->CreateSimplePropertyElement (prop.name (), prop);
}

void PackageVisitor::CreateSimplePropertyElement (string name, const SimpleProperty& prop)
{
  this->push();
  this->curr_->appendChild (this->createSimpleContent ("name", name));

  // Property's value
  DOMElement* value = this->doc_->createElement (GAME::Xml::String ("value"));
  this->curr_->appendChild (value);
  this->curr_ = value;

  // Property's type
  this->Evaluate_SimpleProperty_Reference (prop);

  // Property's type's value
  DOMElement* val = this->doc_->createElement (GAME::Xml::String ("value"));
  this->curr_->appendChild (val);
  this->curr_ = val;

  PredefinedType ref = PICML::PredefinedType::Cast (prop.ref ());
  const Uml::Class& refType = ref.type ();

  std::string data_val = prop.Value ();

  if (refType == Boolean::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("boolean",
                                                           data_val));
    }
  else if (refType == Byte::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("octet",
                                                           data_val));
    }
  else if (refType == String::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("string",
                                                           data_val));
    }
  else if (refType == FloatNumber::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("float",
                                                           data_val));
    }
  else if (refType == DoubleNumber::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("double",
                                                           data_val));
    }
  else if (refType == ShortInteger::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("short",
                                                           data_val));
    }
  else if (refType == LongInteger::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("long",
                                                           data_val));
    }
  this->pop();
}

void PackageVisitor::Evaluate_SimpleProperty_Reference (const PICML::SimpleProperty & prop)
{
  PredefinedType ref = PICML::PredefinedType::Cast (prop.ref ());
  const Uml::Class& refType = ref.type ();

  if (refType == Boolean::meta)
    {
      Boolean boolv = PICML::Boolean::Cast (ref);
      boolv.Accept (*this);
    }
  else if (refType == Byte::meta)
    {
      Byte byte = PICML::Byte::Cast (ref);
      byte.Accept (*this);
    }
  else if (refType == String::meta)
    {
      String str = PICML::String::Cast (ref);
      str.Accept (*this);
    }
  else if (refType == FloatNumber::meta)
    {
      FloatNumber real = PICML::FloatNumber::Cast (ref);
      real.Accept (*this);
    }
  else if (refType == DoubleNumber::meta)
    {
      DoubleNumber real = PICML::DoubleNumber::Cast (ref);
      real.Accept (*this);
    }
  else if (refType == ShortInteger::meta)
    {
      ShortInteger shortv = PICML::ShortInteger::Cast (ref);
      shortv.Accept (*this);
    }
  else if (refType == LongInteger::meta)
    {
      LongInteger lint = PICML::LongInteger::Cast (ref);
      lint.Accept (*this);
    }
}

// Predefined Types
void PackageVisitor::Visit_Boolean(const Boolean& boolean)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_boolean"));
  this->pop();

}

void PackageVisitor::Visit_Byte(const Byte& byte)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_octet"));
  this->pop();
}

void PackageVisitor::Visit_String(const String& str)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_string"));
  this->pop();
}

void PackageVisitor::Visit_FloatNumber(const FloatNumber& real)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_float"));
  this->pop();
}

void PackageVisitor::Visit_DoubleNumber(const DoubleNumber& real)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_double"));
  this->pop();
}

void PackageVisitor::Visit_ShortInteger(const ShortInteger&)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_short"));
  this->pop();
}

void PackageVisitor::Visit_LongInteger(const LongInteger&)
{
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       "tk_long"));
  this->pop();
}

void PackageVisitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
{}

void PackageVisitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty& aip)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("infoProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = aip.dstArtifactInfoProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
{}

void PackageVisitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
{
  set<TopLevelPackageContainer>
    tpcs = tp.TopLevelPackageContainer_kind_children();
  for_each (tpcs.begin(), tpcs.end(),
            bind (&TopLevelPackageContainer::Accept, _1, ref (*this)));
}


void PackageVisitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
{
  set<TopLevelPackage> tps = tpc.TopLevelPackage_kind_children();
  for_each (tps.begin(), tps.end(),
            bind (&TopLevelPackage::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
{
  this->push();
  string name = this->outputPath_;
  name += "\\";
  name += tp.name();
  name += ".tpd";
  this->initTarget (name);
  this->initDocument ("Deployment:topLevelPackageDescription");
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
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("basePackage"));
  const PackageConfiguration pc = pcr.ref();
  string refName (pc.name());
  refName += ".pcd";
  ele->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_PackageConfigurations(const PackageConfigurations& pcs)
{
  set<PackageConfigurationContainer>
    pccs = pcs.PackageConfigurationContainer_kind_children();
  for_each (pccs.begin(), pccs.end(),
            bind (&PackageConfigurationContainer::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_PackageConfigurationContainer(const PackageConfigurationContainer& pcc)
{
  set<PackageConfiguration>
    pcs = pcc.PackageConfiguration_kind_children();
  for_each (pcs.begin(), pcs.end(),
            bind (&PackageConfiguration::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
{
  this->push();
  string name = this->outputPath_ + "\\";
  name += pc.name();
  name += ".pcd";
  this->initTarget (name);
  this->initDocument ("Deployment:packageConfiguration");
  this->initRootAttributes();

  string uuid (pc.UUID());
  if (uuid.empty())
    pc.UUID() = uuid = ::Utils::CreateUuid();
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

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

  set<PackageConfConfigProperty> pccps = pc.dstPackageConfConfigProperty();
  for_each (pccps.begin(), pccps.end(),
            bind (&PackageConfConfigProperty::Accept, _1, ref (*this)));

  this->dumpDocument();
  this->pop();
}

void PackageVisitor::Visit_PackageConfBasePackage(const PackageConfBasePackage& pcbp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("basePackage"));
  const ComponentPackage pkg = pcbp.dstPackageConfBasePackage_end();
  string pkgName (pkg.name());
  pkgName += ".cpd";
  ele->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (pkgName));
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
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("basePackage"));
  ComponentPackage pkg = pkgref.ref();
  string pkgName (pkg.name());
  pkgName += ".cpd";
  ele->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (pkgName));
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty& pccp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = pccp.dstPackageConfConfigProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
{}

void PackageVisitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
{}


void PackageVisitor::Visit_ComponentPackages(const ComponentPackages& cps)
{
  set<PackageContainer> pcs = cps.PackageContainer_kind_children();
  for_each (pcs.begin(), pcs.end(),
            bind (&PackageContainer::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_PackageContainer(const PackageContainer& pc)
{
  set<ComponentPackage> cps = pc.ComponentPackage_kind_children();
  for_each (cps.begin(), cps.end(),
            bind (&ComponentPackage::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ComponentPackage(const ComponentPackage& cp)
{
  this->push();
  string name = this->outputPath_ + "\\";
  name += cp.name();
  name += ".cpd";
  this->initTarget (name);
  this->initDocument ("Deployment:componentPackageDescription");
  this->initRootAttributes();

  string label = cp.label();
  if (!label.empty())
    this->curr_->appendChild (this->createSimpleContent ("label",
                                                         label));
  string uuid (cp.UUID());
  if (uuid.empty())
    cp.UUID() = uuid = ::Utils::CreateUuid();
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

  PackageInterface pi = cp.dstPackageInterface();
  if (pi != Udm::null)
    {
      const ComponentRef cref = pi.dstPackageInterface_end();
      const Component comp  = cref.ref();
      string refName (comp.name());
      this->interfaces_[refName] = cp.name();
      pi.Accept (*this);
    }

  set<Implementation> impls = cp.dstImplementation();
  for_each (impls.begin(), impls.end(),
            bind (&Implementation::Accept, _1, ref (*this)));

  set<PackageConfigProperty> pcps = cp.dstPackageConfigProperty();
  for_each (pcps.begin(), pcps.end(),
            bind (&PackageConfigProperty::Accept, _1, ref (*this)));

  set<PackageInfoProperty> pips = cp.dstPackageInfoProperty();
  for_each (pips.begin(), pips.end(),
            bind (&PackageInfoProperty::Accept, _1, ref (*this)));

  // Dump out an ComponentPackageDescription file
  this->dumpDocument();
  this->pop();
}

void PackageVisitor::Visit_PackageInterface(const PackageInterface& pi)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("realizes"));
  const ComponentRef cref = pi.dstPackageInterface_end();
  const Component comp  = cref.ref();
  string refName (comp.name());
  refName += ".ccd";
  ele->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
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
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("implementation"));
  const ComponentImplementation ref = cir.ref();
  ele->appendChild (this->createSimpleContent ("name",
                                               ref.getPath (".", false, true, "name", true)));
  string refName (ref.name());
  refName += ".cid";
  DOMElement*
    refEle = this->doc_->createElement (GAME::Xml::String ("referencedImplementation"));
  refEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  ele->appendChild (refEle);
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_PackageConfigProperty(const PackageConfigProperty& pcp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = pcp.dstPackageConfigProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::Visit_PackageInfoProperty(const PackageInfoProperty& pip)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("infoProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = pip.dstPackageInfoProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::Visit_ComponentTypes(const ComponentTypes& cts)
{
  set<ComponentContainer> ccs = cts.ComponentContainer_kind_children();
  for_each (ccs.begin(), ccs.end(),
            bind (&ComponentContainer::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ComponentContainer(const ComponentContainer& cc)
{
  set<ComponentRef> cts = cc.ComponentRef_kind_children();
  for_each (cts.begin(), cts.end(),
            bind (&ComponentRef::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ComponentRef(const ComponentRef& ct)
{
  this->push();
  Component comp = ct.ref();
  string name = this->outputPath_ + "\\";
  name += comp.name();
  name += ".ccd";
  this->initTarget (name);
  this->initDocument ("Deployment:componentInterfaceDescription");
  this->initRootAttributes();
  comp.Accept (*this);

  set<ComponentConfigProperty> ccps = ct.dstComponentConfigProperty();
  for_each (ccps.begin(), ccps.end(),
            bind (&ComponentConfigProperty::Accept, _1, ref (*this)));

  set<ComponentInfoProperty> cips = ct.dstComponentInfoProperty();
  for_each (cips.begin(), cips.end(),
            bind (&ComponentInfoProperty::Accept, _1, ref (*this)));

  // Dump out an ComponentInterfaceDescription file
  this->dumpDocument();
  this->pop();

}

void PackageVisitor::CreateComponentCanonicalIds()
{
  DOMElement* type = 0;
  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/Components/Navigation:1.0");
  this->curr_->appendChild (type);

  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/Components/Receptacles:1.0");
  this->curr_->appendChild (type);

  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/Components/Events:1.0");
  this->curr_->appendChild (type);

  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/Components/CCMObject:1.0");
  this->curr_->appendChild (type);

  this->CreateObjectCanonicalIds();
}

void PackageVisitor::CreateObjectCanonicalIds()
{
  DOMElement* type = 0;
  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/CORBA/Object:1.0");
  this->curr_->appendChild (type);
}

void PackageVisitor::CreateEventCanonicalIds()
{
  DOMElement* type = 0;
  type = this->createSimpleContent ("supportedType",
                                    "IDL:omg.org/Components/EventConsumerBase:1.0");
  this->curr_->appendChild (type);
  this->CreateObjectCanonicalIds();
}

string PackageVisitor::CreateRepositoryId (const Udm::Object& obj)
{
  string id;
  Udm::Object parent;
  string prefix;
  string version;
  if (Udm::IsDerivedFrom (obj.type(), Component::meta))
    {
      const Component& comp = Component::Cast(obj);
      id = comp.name();
      version = comp.VersionTag();
      parent = comp.parent();
    }
  else if (Udm::IsDerivedFrom (obj.type(), Object::meta))
    {
      const Object& object = Object::Cast (obj);
      id = object.name();
      prefix = object.PrefixTag();
      version = object.VersionTag();
      parent = object.parent();
    }
  else if (Udm::IsDerivedFrom (obj.type(), Event::meta))
    {
      const Event& event = Event::Cast (obj);
      id = event.name();
      // Add Consumer to the name of the event as required by the spec
      id += "Consumer";
      prefix = event.PrefixTag();
      version = event.VersionTag();
      parent = event.parent();
    }
  else
    throw udm_exception ("Invalid object passed to CreateRepositoryId()");

  if (version.empty())
    version = "1.0";
  while (parent != Udm::null)
    {
      if (Udm::IsDerivedFrom (parent.type(), File::meta))
        {
          File file = File::Cast (parent);
          if (prefix.empty())
            prefix = file.PrefixTag();
          id.insert (0, prefix);
          id.insert (0, "IDL:");
          id.append (":");
          id.append (version);
          return id;
        }
      else if (Udm::IsDerivedFrom (parent.type(), Package::meta))
        {
          Package package = Package::Cast (parent);
          if (prefix.empty())
            prefix = package.PrefixTag();
          string pkgName = package.name();
          pkgName.append ("/");
          id.insert (0, pkgName);
          parent = package.parent();
        }
      else
        throw udm_exception (string ("Invalid parent for object"
                                     + id));
    }
  return id;
}

void PackageVisitor::CollectSupportedTypes(const Component& comp)
{
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = comp.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (comp);
  // Add our specific type as a supported type
  this->curr_->appendChild (this->createSimpleContent ("supportedType",
                                                       specificType));
  // Add all the parent component types
  if (comp.isSubtype())
    {
      // Cast away constness
      Component ncomp = comp;
      Component parent = ncomp.Archetype();
      this->CollectSupportedTypes (parent);
    }
  else
    {
      // Add all our supported interfaces
      set<Supports> supports = comp.Supports_kind_children();
      for (set<Supports>::iterator iter = supports.begin();
           iter != supports.end();
           ++iter)
        {
          Supports supported = *iter;
          Object interFace = PICML::Object::Cast (supported.ref());
          interFace.Accept (*this);
        }
    }
}

void PackageVisitor::CollectSupportedTypes (const Object& obj,
                                            set<string>& supportedTypes)
{
  set<Inherits> inherited = obj.Inherits_kind_children();
  for (set<Inherits>::iterator iter = inherited.begin();
       iter != inherited.end();
       ++iter)
    {
      Inherits inheritedInterface = *iter;
      Object interFace = Object::Cast (inheritedInterface.ref());
      this->CollectSupportedTypes (interFace, supportedTypes);
    }
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = obj.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (obj);
  supportedTypes.insert (specificType);
}


void PackageVisitor::Visit_Object (const Object& obj)
{
  set<string> supportedTypes;
  this->CollectSupportedTypes (obj, supportedTypes);

  for (set<string>::iterator iter = supportedTypes.begin();
       iter != supportedTypes.end();
       ++iter)
    {
      // Add our specific type as a supported type
      this->curr_->appendChild (this->createSimpleContent ("supportedType",
                                                           *iter));
    }
}

void PackageVisitor::CollectSupportedTypes (const Event& event,
                                            set<string>& supportedTypes)
{
  set<Inherits> inherited = event.Inherits_kind_children();
  for (set<Inherits>::iterator iter = inherited.begin();
       iter != inherited.end();
       ++iter)
    {
      Inherits inheritedEvent = *iter;
      Event baseEvent = Event::Cast (inheritedEvent.ref());
      this->CollectSupportedTypes (baseEvent, supportedTypes);
    }
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = event.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (event);
  supportedTypes.insert (specificType);
}

void PackageVisitor::Visit_Event (const Event& event)
{
  set<string> supportedTypes;
  this->CollectSupportedTypes (event, supportedTypes);

  for (set<string>::iterator iter = supportedTypes.begin();
       iter != supportedTypes.end();
       ++iter)
    {
      // Add our specific type as a supported type
      this->curr_->appendChild (this->createSimpleContent ("supportedType",
                                                           *iter));
    }
}

void PackageVisitor::Visit_Component(const Component& comp)
{
  this->push();

  string label = comp.label();
  if (!label.empty())
    this->curr_->appendChild (this->createSimpleContent ("label",
                                                         label));
  string uuid (comp.UUID());
  if (uuid.empty())
    comp.UUID() = uuid = ::Utils::CreateUuid();
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = comp.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (comp);
  this->curr_->appendChild (this->createSimpleContent ("specificType",
                                                       specificType));

  // Add all inherited types
  this->CollectSupportedTypes (comp);

  // Add all the standard supported types
  this->CreateComponentCanonicalIds();

  // Add the idlFile we were defined in
  Udm::Object parent = comp.parent();
  while (parent != Udm::null)
    {
      if (Udm::IsDerivedFrom (parent.type(), File::meta))
        {
          File file = File::Cast (parent);
          string idlFile = file.name();
          idlFile += ".idl";
          this->curr_->appendChild (this->createSimpleContent ("idlFile",
                                                               idlFile));
          break;
        }
      else if (Udm::IsDerivedFrom (parent.type(), Package::meta))
        {
          Package package = Package::Cast (parent);
          parent = package.parent();
        }
      else
        throw udm_exception ("Invalid hierarchy in interface definition!");
    }

  set<OutEventPort> oeps = comp.OutEventPort_kind_children();
  for_each (oeps.begin(), oeps.end(),
            bind (&OutEventPort::Accept, _1, ref (*this)));

  set<InEventPort> ieps = comp.InEventPort_kind_children();
  for_each (ieps.begin(), ieps.end(),
            bind (&InEventPort::Accept, _1, ref (*this)));

  set<ProvidedRequestPort> facets = comp.ProvidedRequestPort_kind_children();
  for_each (facets.begin(), facets.end(),
            bind (&ProvidedRequestPort::Accept, _1, ref (*this)));

  set<RequiredRequestPort> receps = comp.RequiredRequestPort_kind_children();
  for_each (receps.begin(), receps.end(),
            bind (&RequiredRequestPort::Accept, _1, ref (*this)));

  this->pop();
}

void PackageVisitor::Visit_OutEventPort(const OutEventPort& oep)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("port"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  this->curr_->appendChild (this->createSimpleContent ("name", oep.name()));

  Event referred = Event::Cast (oep.ref());
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = referred.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (referred);
  this->curr_->appendChild (this->createSimpleContent ("specificType",
                                                       specificType));
  // Generate all the supported types
  referred.Accept (*this);

  // Add all the standard supported types
  this->CreateEventCanonicalIds();

  this->curr_->appendChild (this->createSimpleContent ("provider", "true"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                       oep.exclusiveProvider() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveUser",
                                                       oep.exclusiveUser() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("optional",
                                                       oep.optional() ? "true" : "false"));

  // Check whether it is a RT_Event_Channel out port
  string out_port_type = oep.out_event_port_type ();
  if (oep.exclusiveProvider())
    {
      if (out_port_type == "DirectConnect")
        this->curr_->appendChild (this->createSimpleContent ("kind", "EventEmitter"));
      else // must be RT Event Channel
        this->curr_->appendChild (this->createSimpleContent ("kind", "rtecEventEmitter"));
    }
  else
    {
      if (out_port_type == "DirectConnect")
        this->curr_->appendChild (this->createSimpleContent ("kind", "EventPublisher"));
      else // must be RT Event Channel
        this->curr_->appendChild (this->createSimpleContent ("kind", "rtecEventPublisher"));
    }
  this->pop();
}

void PackageVisitor::Visit_InEventPort(const InEventPort& iep)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("port"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  this->curr_->appendChild (this->createSimpleContent ("name", iep.name()));

  Event referred = Event::Cast (iep.ref());
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = referred.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (referred);
  this->curr_->appendChild (this->createSimpleContent ("specificType",
                                                       specificType));
  // Generate all the supported types
  referred.Accept (*this);

  // Add all the standard supported types
  this->CreateEventCanonicalIds();

  this->curr_->appendChild (this->createSimpleContent ("provider", "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                       iep.exclusiveProvider() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveUser",
                                                       iep.exclusiveUser() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("optional",
                                                       iep.optional() ? "true" : "false"));

  this->curr_->appendChild (this->createSimpleContent ("kind", "EventConsumer"));
  this->pop();
}

void PackageVisitor::Visit_ProvidedRequestPort(const ProvidedRequestPort& facet)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("port"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  this->curr_->appendChild (this->createSimpleContent ("name", facet.name()));

  Object referred = Object::Cast (facet.ref());
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = referred.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (referred);
  this->curr_->appendChild (this->createSimpleContent ("specificType",
                                                       specificType));
  // Generate all the supported types
  referred.Accept (*this);

  // Add all the standard supported types
  this->CreateObjectCanonicalIds();

  this->curr_->appendChild (this->createSimpleContent ("provider", "true"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                       facet.exclusiveProvider() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveUser",
                                                       facet.exclusiveUser() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("optional",
                                                       facet.optional() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("kind", "Facet"));
  this->pop();
}


void PackageVisitor::Visit_RequiredRequestPort(const RequiredRequestPort& recep)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("port"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  this->curr_->appendChild (this->createSimpleContent ("name", recep.name()));

  Object referred = Object::Cast(recep.ref());
  // If the user specifies a SpecifyIdTag, we should honor it.
  string specificType = referred.SpecifyIdTag();
  if (specificType.empty())
    specificType = this->CreateRepositoryId (referred);
  this->curr_->appendChild (this->createSimpleContent ("specificType",
                                                       specificType));
  // Generate all the supported types
  referred.Accept (*this);

  // Add all the standard supported types
  this->CreateObjectCanonicalIds();

  this->curr_->appendChild (this->createSimpleContent ("provider", "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveProvider",
                                                       recep.exclusiveProvider() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("exclusiveUser",
                                                       recep.exclusiveUser() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("optional",
                                                       recep.optional() ? "true" : "false"));
  this->curr_->appendChild (this->createSimpleContent ("kind",
                                                       recep.multiple_connections() ? "MultiplexReceptacle" : "SimplexReceptacle"));
  this->pop();
}

void PackageVisitor::Visit_ComponentPropertyDescription(const ComponentPropertyDescription&)
{}

void PackageVisitor::Visit_ComponentProperty(const ComponentProperty&)
{}

void PackageVisitor::Visit_ComponentInfoProperty(const ComponentInfoProperty& cip)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("infoProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = cip.dstComponentInfoProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();

}

void PackageVisitor::Visit_ComponentConfigProperty(const ComponentConfigProperty& ccp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = ccp.dstComponentConfigProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();

}

void PackageVisitor::Visit_Supports(const Supports&)
{}

void PackageVisitor::Visit_ComponentImplementations(const ComponentImplementations& cimpls)
{
  set<ComponentImplementationContainer>
    cics = cimpls.ComponentImplementationContainer_kind_children();
  for_each (cics.begin(), cics.end(),
            bind (&ComponentImplementationContainer::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& cic)
{
  set<MonolithicImplementation>
    mimpls = cic.MonolithicImplementation_kind_children();
  for_each (mimpls.begin(), mimpls.end(),
            bind (&MonolithicImplementation::Accept, _1, ref (*this)));

  set<ComponentAssembly> asms = cic.ComponentAssembly_kind_children();
  for_each (asms.begin(), asms.end(),
            bind (&ComponentAssembly::Accept, _1, ref (*this)));
}

void PackageVisitor::Visit_MonolithicImplementation(const MonolithicImplementation& mimpl)
{
  this->push();
  string name = this->outputPath_ + "\\";
  name += mimpl.name();
  name += ".cid";
  this->initTarget (name);
  this->initDocument ("Deployment:componentImplementationDescription");
  this->initRootAttributes();

  string label = mimpl.label();
  if (!label.empty())
    this->curr_->appendChild (this->createSimpleContent ("label",
                                                         label));
  string uuid = mimpl.UUID();
  if (uuid.empty())
    mimpl.UUID() = uuid = ::Utils::CreateUuid();
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

  Implements iface = mimpl.dstImplements();
  iface.Accept (*this);

  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("monolithicImpl"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  set<MonolithprimaryArtifact> mpas = mimpl.dstMonolithprimaryArtifact();
  for_each (mpas.begin(), mpas.end(),
            bind (&MonolithprimaryArtifact::Accept, _1, ref (*this)));
  this->pop();

  set<ConfigProperty> cps = mimpl.dstConfigProperty();
  for_each (cps.begin(), cps.end(),
            bind (&ConfigProperty::Accept, _1, ref (*this)));

  // Dump out an ComponentImplementationDescription file
  this->dumpDocument();
  this->pop();
}

void PackageVisitor::Visit_Implements(const Implements& impl)
{
  this->push();
  const ComponentRef iface = impl.dstImplements_end();
  const Component ref = iface.ref();
  string refName (ref.name());
  refName += ".ccd";
  DOMElement*
    refEle = this->doc_->createElement (GAME::Xml::String ("implements"));
  refEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  this->curr_->appendChild (refEle);
  this->pop();
}

void PackageVisitor::Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact& mpa)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("primaryArtifact"));
  const ImplementationArtifactReference iaref = mpa.dstMonolithprimaryArtifact_end();
  const ImplementationArtifact ref = iaref.ref();
  ele->appendChild (this->createSimpleContent ("name",
                                               ref.getPath (".", false, true, "name", true)));
  string refName = ref.name();
  refName += ".iad";
  DOMElement*
    refEle = this->doc_->createElement (GAME::Xml::String ("referencedArtifact"));
  refEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  ele->appendChild (refEle);
  this->curr_->appendChild (ele);
  this->pop();
}

void PackageVisitor::Visit_ConfigProperty(const ConfigProperty& cp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = cp.dstConfigProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

void PackageVisitor::Visit_AssemblyConfigProperty(const AssemblyConfigProperty& acp)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = acp.dstAssemblyConfigProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}


void PackageVisitor::Visit_ComponentAssembly(const ComponentAssembly& assembly)
{
  this->push();
  string name = this->outputPath_ + "\\";
  name += assembly.name();
  name += ".cid";
  this->initTarget (name);
  this->initDocument ("Deployment:componentImplementationDescription");
  this->initRootAttributes();

  string label = assembly.label();
  if (!label.empty())
    this->curr_->appendChild (this->createSimpleContent ("label",
                                                         label));

  string uuid = assembly.UUID();
  if (uuid.empty())
    assembly.UUID() = uuid = ::Utils::CreateUuid();
  // Make a copy as opposed to casting away constness
  ComponentAssembly casm = assembly;
  // Make sure that every instance has a UUID
  if (assembly.isInstance())
    {
      ComponentAssembly typeParent = casm.Archetype();
      string parentUuid (typeParent.UUID());
      if (uuid == parentUuid)
        casm.UUID() = uuid = ::Utils::CreateUuid();
    }
  this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

  this->CreateAssemblies (assembly);

  // Handle configProperties on the assembly
  set<ConfigProperty> cps = assembly.dstConfigProperty ();
  for_each (cps.begin(), cps.end(),
            bind (&ConfigProperty::Accept, _1, ref (*this)));

  // @@Note:  The Critical path MUST be generated immediately AFTER any
  // configproperties.
  CriticalPath cpath = assembly.dstCriticalPath();
  if (cpath != Udm::null)
    cpath.Accept (*this);

  // Handle infoProperties on the assembly
  set< InfoProperty > ips = assembly.dstInfoProperty ();
  for_each (ips.begin(), ips.end(),
            bind (&InfoProperty::Accept, _1, ref (*this)));

  // Dump out an ComponentImplementationDescription file
  this->dumpDocument();
  this->pop();
}

void PackageVisitor::Visit_CriticalPath (const CriticalPath& cpath)
{
  PathReference pref = cpath.dstCriticalPath_end();
  pref.Accept (*this);
}


void PackageVisitor::Visit_PathReference (const PathReference& pref)
{
  Path criticalpath = pref.ref();
  criticalpath.Accept (*this);
}

void PackageVisitor::Visit_Path (const Path& path)
{
  // Dump the top-level pointer to the critical path
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  string pname = "edu.vanderbilt.dre.CIAO.RACE.criticalPath";
  this->DumpStringProperty (pname,
                            path.getPath (".", false, true, "name",
                                          true));
  this->pop();

  // Dump all the properties that are associated with the Path.
  set<PathProperty> properties = path.dstPathProperty();
  for (set<PathProperty>::iterator iter = properties.begin();
       iter != properties.end();
       ++iter)
    {
      this->push();
      DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
      this->curr_->appendChild (ele);
      this->curr_ = ele;
      PathProperty pprop = *iter;
      PICML::Property prop = pprop.dstPathProperty_end();
      string pname = path.getPath (".", false, true, "name", true);
      pname += "/";
      pname += prop.name();

      if (Udm::IsDerivedFrom (prop.type (), PICML::SimpleProperty::meta))
        this->CreateSimplePropertyElement (pname, PICML::SimpleProperty::Cast (prop));

      this->pop();
    }

  // Find the source node of the path.  Need to fix the metamodel so that
  // we don't need to do an O(n) search to find the source node.
  set<DisplayNode> nodes = path.DisplayNode_kind_children();
  for (set<DisplayNode>::iterator iter = nodes.begin();
       iter != nodes.end();
       ++iter)
    {
      DisplayNode node = *iter;
      SrcEdge edge = node.srcSrcEdge();
      if (edge == Udm::null)
        {
          // Dump the value of the criticalPath
          this->push();
          DOMElement* ele =
            this->doc_->createElement (GAME::Xml::String ("configProperty"));
          this->curr_->appendChild (ele);
          this->curr_ = ele;
          string pvalue = this->CreatePath (node);
          this->DumpStringProperty (path.getPath(".", false, true, "name",
                                                 true), pvalue);
          this->pop();
          break;
        }
    }
}

string PackageVisitor::CreatePath (const DisplayNode& node)
{
  // Handle the source node
  string nodename = node.name();
  string path ("");
  size_t offset = nodename.find ('/');
  if (offset == string::npos)
    throw udm_exception (string ("Invalid node name" + nodename));
  // Append component's uuid
  path.append (nodename, 0, offset);
  path += ',';
  // Append source port name
  path.append (nodename, offset + 1, nodename.size() - offset - 1);
  SrcEdge source = node.srcSrcEdge();
  if (source != Udm::null)
    throw  udm_exception
      (string ("Invalid detection of source port" + nodename));
  path += ',';
  // Append destination port name to be the same as source port name
  path.append (nodename, offset + 1, nodename.size() - offset - 1);

  // Get the connection to the intermediate nodes
  DstEdge dst = node.dstDstEdge();
  while (dst != Udm::null)
    {
      path += ';';
      // Get the intermediate connection node
      Edge dstEdge = dst.dstDstEdge_end();
      SrcEdge dstNodeEdge = dstEdge.dstSrcEdge();
      if (dstNodeEdge == Udm::null)
        throw udm_exception (string ("Connection from"
                                     + this->ExtractName (dstEdge)
                                     + " is null!"));
      // Get the display node at the end of the connection node
      Udm::Object vertex = dstNodeEdge.dstSrcEdge_end();
      if (!Udm::IsDerivedFrom (vertex.type(), DisplayNode::meta))
        throw udm_exception (string ("Invalid object inheritance in " +
                                     this->ExtractName (vertex)));

      DisplayNode dstNode = DisplayNode::Cast (vertex);
      string dstNodeName = dstNode.name();
      offset = dstNodeName.find ('/');
      if (offset == string::npos)
        throw udm_exception (string ("Invalid node name"
                                     + dstNodeName));
      // Append Component's uuid
      path.append (dstNodeName, 0, offset);
      path += ',';
      // Append source port name
      path.append (dstNodeName, offset + 1,
                   dstNodeName.size() - offset - 1);
      // Get the connection to the intermediate connection node
      DstEdge nodeEdge = dstNode.dstDstEdge();
      if (nodeEdge == Udm::null)
        {
          // We have reached the end of the path.  Just append the
          // source port name as the destination port name.
          path += ',';
          // Append destination port name
          path.append (dstNodeName, offset + 1,
                       dstNodeName.size() - offset - 1);
          return path;
        }
      else
        {
          // Get the intermediate connection node
          dstEdge = nodeEdge.dstDstEdge_end();
          dstNodeEdge = dstEdge.dstSrcEdge();
          if (dstNodeEdge == Udm::null)
            throw udm_exception (string ("Connection from"
                                         + this->ExtractName (dstEdge)
                                         + " is null!"));
          // Get the display node at the end of the connection node
          vertex = dstNodeEdge.dstSrcEdge_end();
          if (!Udm::IsDerivedFrom (vertex.type(), DisplayNode::meta))
            throw udm_exception (string ("Invalid object inheritance in "
                                         + this->ExtractName (vertex)));
          DisplayNode dnode = DisplayNode::Cast (vertex);
          string dnodename = dnode.name();
          offset = dnodename.find ('/');
          if (offset == string::npos)
            throw udm_exception (string ("Invalid node name"
                                         + dstNodeName));
          path += ',';
          // Append destination port name
          path.append (dnodename, offset + 1,
                       dnodename.size() - offset - 1);
          // Setup the loop for the next iteration
          dst = dnode.dstDstEdge();
        }
    }
  return path;
}


void PackageVisitor::DumpStringProperty (const string& name,
                                         const string& pvalue)
{
  this->push();

  // Property's name
  this->curr_->appendChild (this->createSimpleContent ("name", name));
  // Property's value
  DOMElement* value = this->doc_->createElement (GAME::Xml::String ("value"));
  this->curr_->appendChild (value);
  this->curr_ = value;

  // Property's type
  this->push();
  DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
  this->curr_->appendChild (type);
  this->curr_ = type;
  this->curr_->appendChild (this->createSimpleContent ("kind", "tk_string"));
  this->pop();

  // Property's type's value
  this->push();
  DOMElement* val = this->doc_->createElement (GAME::Xml::String ("value"));
  this->curr_->appendChild (val);
  this->curr_ = val;
  this->curr_->appendChild (this->createSimpleContent ("string", pvalue));
  this->pop();

  this->pop();
}


void PackageVisitor::CreateAssemblies (const ComponentAssembly& assembly)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("assemblyImpl"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  // Collect all the Components of this assembly into a set.
  set <ComponentInstance> comps = assembly.ComponentInstance_children ();

  /////////////////
  // TEMP DISABLE
  //// Add all the shared Components of this assembly into the set.  A
  //// shared Component is implemented as a reference to a Component.  So
  //// just traverse the reference and add it to the set.
  //set<ComponentRef> scomps = assembly.ComponentRef_kind_children();
  //for_each (scomps.begin(),
  //          scomps.end(),
  //          bind (&ComponentRef::Accept, _1, ref (*this)));

  /////////////////

  // Collect all the immediate ComponentAssembly children of this assembly
  set <ComponentAssembly> subasms = assembly.ComponentAssembly_kind_children();

  // Add all the shared ComponentAssemblies of the current assembly.
  // Like shared components, shared assemblies are also implemented as
  // references.  So just traverse the references, and add them to the set.
  set <ComponentAssemblyReference> sasms = assembly.ComponentAssemblyReference_kind_children();
  for_each (sasms.begin(),
            sasms.end(),
            bind (&ComponentAssemblyReference::Accept, _1, ref (*this)));

  // Maintain a list of all ComponentAssemblies in this assembly
  vector <ComponentAssembly> assemblies;

  // Put ourselves in the global list first.
  assemblies.push_back (assembly);

  // Do a Depth-First search and collect all the ComponentAssembly,
  // Component children of this assembly, and add them to the
  // assembly-specific list.
  while (!subasms.empty())
  {
    ComponentAssembly rassembly = *subasms.begin ();
    // Put the first assembly from the current list to the
    // assembly-specific list.
    assemblies.push_back (rassembly);

    // Remove this assembly so that we don't process it again.
    subasms.erase (rassembly);

    // Get the components of the current assembly
    set <ComponentInstance> rcomps = rassembly.ComponentInstance_children ();

    // TODO When shared component support is re-enabled, the code
    // below needs to be updated.

    // Get the shared components of the current assembly
    //scomps = rassembly.ComponentRef_kind_children ();
    //std::for_each (scomps.begin (),
    //               scomps.end (),
    //               boost::bind (&set <ComponentInstance>::insert,
    //                            boost::ref (rcomps),
    //                            boost::bind (&ComponentRef::ref, _1)));
    // Insert both into the component list.
    // comps.insert (rcomps.begin(), rcomps.end());

    // Get the subassemblies of the first assembly.
    set <ComponentAssembly> rasms = rassembly.ComponentAssembly_kind_children();

    // Add all the shared ComponentAssemblies of the current assembly.
    // Like shared components, shared assemblies are also implemented
    // as references.  So just traverse the references, and add them to
    // the set.
    set<ComponentAssemblyReference>
      sasms = rassembly.ComponentAssemblyReference_kind_children();
    for (set<ComponentAssemblyReference>::const_iterator iter = sasms.begin();
         iter != sasms.end();
         ++iter)
      {
        const ComponentAssemblyReference asmRef = *iter;
        rasms.insert (asmRef.ref());
      }

    // Insert them to the current list.
    subasms.insert (rasms.begin(), rasms.end());
  }

  // Create the appropriate component attribute value mappings
  this->CreateAttributeMappings (assemblies);

  std::for_each (comps.begin (),
                 comps.end (),
                 boost::bind (&PackageVisitor::CreateAssemblyInstance, this, _1));

  this->CreateAssemblyConnections (assemblies);
  this->pop();
}


void PackageVisitor::CreateAttributeMappings (vector<ComponentAssembly>& assemblies)
{
  for (vector<ComponentAssembly>::iterator iter = assemblies.begin();
       iter != assemblies.end();
       ++iter)
    {
      ComponentAssembly assembly = *iter;
      string assemblyName = this->ExtractName (assembly);
      set<AttributeMapping>
        mappings = assembly.AttributeMapping_kind_children();
      for_each (mappings.begin(), mappings.end(),
                bind (&AttributeMapping::Accept, _1, ref (*this)));
    }
}

void PackageVisitor::Visit_AttributeMapping(const AttributeMapping& mapping)
{
  string mappingName = this->ExtractName (mapping);
  AttributeMappingValue value = mapping.dstAttributeMappingValue();
  if (value != Udm::null)
    {
      Property prop = value.dstAttributeMappingValue_end();
      set<pair<string, string> > compAttrs;

      this->GetAttributeComponents (mapping, compAttrs);

      for (set<pair<string, string> >::const_iterator
             iter = compAttrs.begin();
           iter != compAttrs.end();
           ++iter)
        {
          // Get the component, attribute pair
          pair<string, string> compAttr = *iter;
          // Set the name of the associated property to the attribute name
          // prop.name() = compAttr.second;
          // If this component's attribute hasn't been assigned a value,
          // i.e., a value hasn't been propagated from a higher-level assembly,
          // set it to the current value.
          if (this->attrValues_.find (compAttr) == this->attrValues_.end())
            this->attrValues_[compAttr] = prop;
        }
    }
}

void PackageVisitor::GetAttributeComponents (const AttributeMapping& mapping,
                                             set<pair<string, string> >& output)
{
  string mappingName = this->ExtractName (mapping);
  set<AttributeDelegate> delegates = mapping.dstAttributeDelegate();
  if (delegates.empty())
    {
      set<AttributeMappingDelegate>
        mapDelegates = mapping.dstAttributeMappingDelegate();
      if (mapDelegates.empty())
        {
          string mapPath = mapping.getPath (".", false, true, "name", true);

          throw udm_exception (string ("AttributeMapping " +
                                       mapPath +
                                       " is not connected to any attributes or delegated to another AttributeMapping"));
        }
      else
        {
          for (set<AttributeMappingDelegate>::const_iterator
                 iter = mapDelegates.begin();
               iter != mapDelegates.end();
               ++iter)
            {
              AttributeMappingDelegate mapDelegate = *iter;
              AttributeMapping
                delegate = mapDelegate.dstAttributeMappingDelegate_end();
              string delegateName = this->ExtractName (delegate);
              this->GetAttributeComponents (delegate, output);
            }
        }
    }
  else
    {
      for (set<AttributeDelegate>::const_iterator iter = delegates.begin();
           iter != delegates.end(); ++iter)
        {
          //AttributeDelegate delegate = *iter;
          //ReadonlyAttribute attr = delegate.dstAttributeDelegate_end();
          //string attrName = this->ExtractName (attr);
          //Component parent = attr.Component_parent();
          //string parentName = this->ExtractName (parent);
          //string compName = parent.getPath (".", false, true, "name", true);
          //output.insert (make_pair (compName, attr.name()));
        }
    }
}

//
// CreateAssemblyInstances
//
void PackageVisitor::
CreateAssemblyInstance (const ComponentInstance & comp)
{
  DOMElement* instance = this->doc_->createElement (GAME::Xml::String ("instance"));

  this->curr_->appendChild (instance);
  this->push();
  this->curr_ = instance;
  Component typeParent;
  string uniqueName = comp.UUID();

  uniqueName = string ("_") + uniqueName;
  instance->setAttribute (GAME::Xml::String ("id"), GAME::Xml::String (uniqueName));
  instance->appendChild (this->createSimpleContent ("name",
                                                    comp.getPath (".", false, true, "name", true)));

  string interfaceName = typeParent.name();
  string refName = this->interfaces_[interfaceName];
  refName += ".cpd";
  DOMElement* refEle = this->doc_->createElement (GAME::Xml::String ("basePackage"));
  refEle->setAttribute (GAME::Xml::String ("href"), GAME::Xml::String (refName));
  instance->appendChild (refEle);

  // TODO Add AssemblyConfigProperty back to PICML.

  set <AssemblyConfigProperty> cps = comp.dstAssemblyConfigProperty ();
  for_each (cps.begin(), cps.end(),
            bind (&AssemblyConfigProperty::Accept, _1, ref (*this)));

  set <AttributeInstance> attrs = comp.AttributeInstance_kind_children ();
  for_each (attrs.begin(), attrs.end(),
            bind (&AttributeInstance::Accept, _1, ref (*this)));

  for (map<pair <string, string>, Property>::const_iterator iter = this->attrValues_.begin();
       iter != this->attrValues_.end();
       ++iter)
    {
      pair <pair <string, string>, Property> attrVal = *iter;
      pair <string, string> compAttr = attrVal.first;

      if (compAttr.first == comp.getPath (".", false, true, "name", true))
        {
          this->push();
          DOMElement*
            ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
          this->curr_->appendChild (ele);
          this->curr_ = ele;
          PICML::Property val = attrVal.second;

          if (Udm::IsDerivedFrom (val.type (), PICML::SimpleProperty::meta))
            this->CreateSimplePropertyElement (compAttr.second, PICML::SimpleProperty::Cast (val));

          this->pop();
        }
    }

  this->pop();
}

//
// Visit_AttributeInstance
//
void PackageVisitor::Visit_AttributeInstance (const AttributeInstance & attr)
{
  AttributeValue attValue = attr.dstAttributeValue();

  if (attValue != Udm::null)
    attValue.Accept (*this);
}

//
// Visit_AttributeValue
//
void PackageVisitor::Visit_AttributeValue (const AttributeValue& value)
{
  this->push();

  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;

  Property ref = value.dstAttributeValue_end();
  AttributeInstance attr = value.srcAttributeValue_end ();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

//
// CreateAssemblyConnections
//
void PackageVisitor::
CreateAssemblyConnections (vector <ComponentAssembly> & assemblies)
{
  for (vector<ComponentAssembly>::iterator iter = assemblies.begin();
       iter != assemblies.end();
       ++iter)
  {
    ComponentAssembly subasm = *iter;
    set <Invoke> invokes = subasm.Invoke_kind_children ();

    for_each (invokes.begin(),
              invokes.end(),
              bind (&Invoke::Accept, _1, ref (*this)));

    set <SendsTo> st = subasm.SendsTo_children ();
    std::for_each (st.begin (),
                   st.end (),
                   boost::bind (&SendsTo::Accept, _1, boost::ref (*this)));

    //set <emit> emits = subasm.emit_kind_children();

    //for_each (emits.begin(),
    //          emits.end(),
    //          bind (&emit::Accept, _1, ref (*this)));

    //set <publish> publishers = subasm.publish_kind_children();

    //for_each (publishers.begin(),
    //          publishers.end(),
    //          bind (&publish::Accept, _1, ref (*this)));

    //set<deliverTo> deliverTos = subasm.deliverTo_kind_children();
    //for_each (deliverTos.begin(),
    //          deliverTos.end(),
    //          bind (&deliverTo::Accept, _1, ref (*this)));

    //set<PublishConnector> connectors = subasm.PublishConnector_kind_children();
    //for_each (connectors.begin(),
    //          connectors.end(),
    //          bind (&PublishConnector::Accept, _1, ref (*this)));

    this->publishers_.clear();
    this->consumers_.clear();
  }
}

//template <typename T, typename Del, typename DelRet, typename DelEndRet>
//void PackageVisitor::GetComponents (const T& port,
//                                    DelRet (T::*srcDel)() const,
//                                    DelRet (T::*dstDel) () const,
//                                    DelEndRet (Del::*srcDelEnd)() const,
//                                    DelEndRet (Del::*dstDelEnd)() const,
//                                    map<Component, string>& output,
//                                    set<T>& visited)
//{
//  visited.insert (port);
//  Udm::Object par = port.parent();
//  string recepName = port.name();
//  string parentName = this->ExtractName (par);
//
//  if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
//    {
//      Del delegate = (port.*dstDelEnd)();
//      string srcPortName = this->ExtractName (srcPort);
//
//      if (find (visited.begin(),
//                visited.end(),
//                srcPort) == visited.end ())
//      this->GetComponents(srcPort, srcDel, dstDel,
//                          srcDelEnd, dstDelEnd, output, visited);
//
//      delegates = (port.*srcDel)();
//      for (set<Del>::const_iterator iter = delegates.begin();
//           iter != delegates.end();
//           ++iter)
//        {
//          Del delegate = *iter;
//          T dstPort = (delegate.*srcDelEnd)();
//          string dstPortName = this->ExtractName(dstPort);
//          if (find (visited.begin(),
//                    visited.end(),
//                    dstPort) == visited.end())
//            this->GetComponents(dstPort, srcDel, dstDel,
//                                srcDelEnd, dstDelEnd, output, visited);
//        }
//    }
//  else if (Udm::IsDerivedFrom (par.type(), Component::meta))
//    {
//      Component recep_comp = Component::Cast (par);
//      output.insert (make_pair (recep_comp, port.name()));
//    }
//  visited.erase (port);
//  return;
//}
//
//void PackageVisitor::
//GetReceptacleComponents (const RequiredRequestPort& receptacle,
//                         map<Component,string>& output)
//{
//  set<RequiredRequestPort> visited;
//  this->GetComponents (receptacle,
//                       &RequiredRequestPort::srcReceptacleDelegate,
//                       &RequiredRequestPort::dstReceptacleDelegate,
//                       &ReceptacleDelegate::srcReceptacleDelegate_end,
//                       &ReceptacleDelegate::dstReceptacleDelegate_end,
//                       output,
//                       visited);
//}
//
//void PackageVisitor::GetFacetComponents (const ProvidedRequestPort& facet,
//                                         map<Component,string>& output)
//{
//  set<ProvidedRequestPort> visited;
//  this->GetComponents (facet,
//                       &ProvidedRequestPort::srcFacetDelegate,
//                       &ProvidedRequestPort::dstFacetDelegate,
//                       &FacetDelegate::srcFacetDelegate_end,
//                       &FacetDelegate::dstFacetDelegate_end,
//                       output,
//                       visited);
//}
//
//void PackageVisitor::GetEventSinkComponents (const InEventPort& consumer,
//                                             map<Component,string>& output)
//{
//  set<InEventPort> visited;
//  this->GetComponents (consumer,
//                       &InEventPort::srcEventSinkDelegate,
//                       &InEventPort::dstEventSinkDelegate,
//                       &EventSinkDelegate::srcEventSinkDelegate_end,
//                       &EventSinkDelegate::dstEventSinkDelegate_end,
//                       output,
//                       visited);
//}
//
//void PackageVisitor::GetEventSourceComponents (const OutEventPort& publisher,
//                                               map<Component,string>& output)
//{
//  set<OutEventPort> visited;
//  this->GetComponents (publisher,
//                       &OutEventPort::srcEventSourceDelegate,
//                       &OutEventPort::dstEventSourceDelegate,
//                       &EventSourceDelegate::srcEventSourceDelegate_end,
//                       &EventSourceDelegate::dstEventSourceDelegate_end,
//                       output,
//                       visited);
//}

void PackageVisitor::CreateConnections (const map<Component, string>& src,
                                        const map<Component, string>& dst)
{
  for (map<Component,string>::const_iterator iter = src.begin();
       iter != src.end();
       ++iter)
    {
      Component srcComp = iter->first;
      string srcPortName = iter->second;
      for (map<Component, string>::const_iterator iter = dst.begin();
           iter != dst.end();
           ++iter)
        {
          Component dstComp = iter->first;
          string dstPortName = iter->second;
          this->CreateConnection (srcComp, srcPortName, dstComp, dstPortName);
        }
    }
}

void PackageVisitor::CreateConnection (const Component& srcComp,
                                       const string& srcPortName,
                                       const Component& dstComp,
                                       const string& dstPortName)
{
  // Create a connection
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("connection"));
  this->curr_->appendChild (ele);

  string connection = srcPortName + "_" + dstPortName;
  ele->appendChild (this->createSimpleContent ("name", connection));

  // Source endPoint
  DOMElement* endPoint
    = this->doc_->createElement (GAME::Xml::String ("internalEndpoint"));
  endPoint->appendChild (this->createSimpleContent ("portName",
                                                    srcPortName));
  // Source instance
  string uuid (srcComp.UUID());
  uuid = string ("_") + uuid;
  endPoint->appendChild (this->createSimpleContent ("instance", uuid));
  ele->appendChild (endPoint);

  // Destination endPoint
  endPoint = this->doc_->createElement (GAME::Xml::String ("internalEndpoint"));
  endPoint->appendChild (this->createSimpleContent ("portName",
                                                    dstPortName));
  // Destination instance
  uuid = dstComp.UUID();
  uuid = string ("_") + uuid;
  endPoint->appendChild (this->createSimpleContent ("instance", uuid));
  ele->appendChild (endPoint);
}

void PackageVisitor::Visit_Invoke (const Invoke & iv)
{
  ////// Get the receptacle end
  ////RequiredRequestPortEnd receptacle = iv.srcinvoke_end ();

  ////// Get the facet end
  ////ProvidedRequestPortEnd facet = ProvidedRequestPort::Cast (iv.dstinvoke_end());

  //map<Component,string> receptacles;
  //map<Component,string> facets;

  ////this->GetReceptacleComponents (receptacle, receptacles);
  ////this->GetFacetComponents (facet, facets);
  //this->CreateConnections (receptacles, facets);
}

//
// Visit_sendsTo
//
void PackageVisitor::Visit_sendsTo (const PICML::SendsTo & s)
{
  //OutEventPortEnd sender = s.srcSendsTo_end ();
  //InEventPortEnd consumer = s.dstSendsTo_end ();

  //if (sender.single_destination ())
  //{
  //  // This connection is going to only one destination. This
  //  // means we are dealing with an emitter.
  //  map <Component, string> emitters;
  //  map <Component, string> consumers;

  //  //this->GetEventSourceComponents (sender, emitters);
  //  //this->GetEventSinkComponents (consumer, consumers);
  //  this->CreateConnections (emitters, consumers);
  //}
  //else
  //{
  //  std::ostringstream ostr;
  //  ostr << '_' << sender.uniqueId () << '_' << consumer.uniqueId () << '_';

  //  this->publishers_[ostr.str ()] = sender;
  //  this->consumers_.insert (make_pair (ostr.str (), consumer));
  //}
}

//void PackageVisitor::
//Visit_PublishConnector(const PublishConnector& pubctor)
//{
//  string ctor = pubctor.name();
//
//  // Get Publisher
//  OutEventPort publisher = this->publishers_[ctor];
//  map<Component,string> publishers;
//  this->GetEventSourceComponents (publisher, publishers);
//
//  for (map<Component,string>::const_iterator
//         iter = publishers.begin();
//       iter != publishers.end();
//       ++iter)
//    {
//      Component srcComp = iter->first;
//      string srcPortName = iter->second;
//
//      for (multimap<string, InEventPort>::const_iterator
//             iter = this->consumers_.lower_bound (ctor);
//           iter != this->consumers_.upper_bound (ctor);
//           ++iter)
//        {
//          // Get Consumer
//          InEventPort consumer = iter->second;
//          map<Component,string> consumers;
//          this->GetEventSinkComponents (consumer, consumers);
//          for (map<Component,string>::const_iterator
//                 iter = consumers.begin();
//               iter != consumers.end();
//               ++iter)
//            {
//              Component dstComp = iter->first;
//              string dstPortName = iter->second;
//              this->CreateConnection (srcComp, srcPortName, dstComp,
//                                      dstPortName);
//            }
//        }
//    }
//}

void PackageVisitor::Visit_InfoProperty(const InfoProperty& ip)
{
  this->push();
  DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("infoProperty"));
  this->curr_->appendChild (ele);
  this->curr_ = ele;
  Property ref = ip.dstInfoProperty_end();

  if (Udm::IsDerivedFrom (ref.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (ref).Accept (*this);

  this->pop();
}

string PackageVisitor::ExtractName(Udm::Object ob)
{
  Uml::Class cls= ob.type();
  set<Uml::Attribute> attrs=cls.attributes();

  // Adding parent attributes
  set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
  attrs.insert(aattrs.begin(),aattrs.end());

  for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++)
    {
      if(string(ai->type())=="GAME::Xml::String")
        {
          string str=ai->name();
          if(str=="name")
            {
              string value=ob.getStringAttr(*ai);
              if(value.empty())value="<empty string>";
              return value;
            }
        }
    }
  return string("<no name specified>");
}

}
