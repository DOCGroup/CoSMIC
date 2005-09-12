#include <algorithm>
#include <functional>
#include "FlatPlanVisitor.h"
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

  void FlatPlanVisitor::initcgName (const std::string& cgName)
  {
    this->cg_name_ = cgName;
  }

  std::string FlatPlanVisitor::retcgName ()
  {
    return this->cg_name_;
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
    {
      this->root_folder_ = rf;
      std::set<DeploymentPlans> folders = rf.DeploymentPlans_kind_children();
      for (std::set<DeploymentPlans>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          DeploymentPlans folder = *iter;
          folder.Accept (*this);
        }
    }
  }

  // Predefined Types
  void FlatPlanVisitor::Visit_LongInteger(const LongInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_long"));
    this->pop();
  }

  void FlatPlanVisitor::Visit_RealNumber(const RealNumber& real)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_double"));
    this->pop();
  }

  void FlatPlanVisitor::Visit_Boolean(const Boolean&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_boolean"));
    this->pop();
  }

  void FlatPlanVisitor::Visit_ShortInteger(const ShortInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_short"));
    this->pop();
  }

  // Implementation Artifact operations

  void FlatPlanVisitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {
    std::set<ArtifactContainer> afs = ia.ArtifactContainer_kind_children();
    for (std::set<ArtifactContainer>::iterator iter = afs.begin();
         iter != afs.end();
         ++iter)
      {
        ArtifactContainer ac = *iter;
        ac.Accept (*this);
      }
  }

  void FlatPlanVisitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
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

  void FlatPlanVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("artifact"));
    std::string uniqueName = ia.getPath ("_",false,true,"name",true);
    ele->setAttribute (XStr ("id"), XStr (uniqueName));
    ele->appendChild (this->createSimpleContent ("name", uniqueName));
    //ele->appendChild (this->createSimpleContent ("node", "<!-- empty-->"));
    ele->appendChild (this->doc_->createElement (XStr ("source")));
    ele->appendChild (this->doc_->createElement (XStr ("node")));
    std::string location = ia.location();
    if (!location.empty())
      {
        ele->appendChild (this->createSimpleContent ("location",
                                                     location));
      }
    else
      {
        ele->appendChild (this->doc_->createElement (XStr ("location")));
      }
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    const std::set<ArtifactExecParameter> exec = ia.dstArtifactExecParameter();
    for (std::set<ArtifactExecParameter>::const_iterator it = exec.begin();
         it != exec.end();
         ++it)
      {
        ArtifactExecParameter aep = *it;
        aep.Accept (*this);
      }
    this->pop();
  }

  void FlatPlanVisitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {
    ImplementationArtifactReference ref = ado.dstArtifactDependsOn_end();
    ref.Accept (*this);
  }

  void FlatPlanVisitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
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

  void FlatPlanVisitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {
    this->push();
    /*
      DOMElement* ele = this->doc_->createElement (XStr ("execParameter"));
      this->curr_->appendChild (ele);
      this->curr_ = ele;
      Property ref = param.dstArtifactExecParameter_end();
      ref.Accept (*this);
    */
    DOMElement* value = this->doc_->createElement (XStr ("execParameter"));
    this->curr_->appendChild (value);
    this->curr_ = value;
    Property ref = param.dstArtifactExecParameter_end();
    ref.Accept (*this);
    this->pop();
  }

  void FlatPlanVisitor::Visit_Property(const Property& property)
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

  void FlatPlanVisitor::Visit_DataType(const DataType& type)
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

  void FlatPlanVisitor::Visit_String(const String& str)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_string"));
    this->pop();
  }

  void FlatPlanVisitor::Visit_Byte(const Byte& byte)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (XStr ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
                                                         "tk_octet"));
    this->pop();
  }

  void FlatPlanVisitor::Visit_ComponentImplementations(const ComponentImplementations& cimpls)
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

  void FlatPlanVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& cic)
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
  }

  void FlatPlanVisitor::Visit_MonolithicImplementation(const MonolithicImplementation& mimpl)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("implementation"));
    std::string impl_name = mimpl.name ();
    this->monoimpls_.insert (make_pair (impl_name, mimpl));
    std::string uniqueName = mimpl.getPath ("_",false,true,"name",true);
    ele->setAttribute (XStr ("id"), XStr (uniqueName));
    ele->appendChild (this->createSimpleContent ("name", uniqueName));
    ele->appendChild (this->doc_->createElement (XStr ("source")));
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

    /*const std::set<ConfigProperty>
    cps = mimpl.dstConfigProperty();
    for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
    it2 != cps.end();
    ++it2)
    {
    ConfigProperty cp = *it2;
    cp.Accept (*this);
    }*/

    this->pop();
  }

  void FlatPlanVisitor::Visit_Implements(const Implements& impl)
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

  void FlatPlanVisitor::Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact& mpa)
  {
    this->push();
    const ImplementationArtifactReference iaref = mpa.dstMonolithprimaryArtifact_end();
    const ImplementationArtifact ref = iaref.ref();
    std::string uniqueName = ref.getPath ("_",false,true,"name",true);
    this->curr_->appendChild (this->createSimpleContent ("artifact", uniqueName));
    this->pop();
  }

  void FlatPlanVisitor::Visit_ConfigProperty(const ConfigProperty& cp)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("configProperty"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    Property ref = cp.dstConfigProperty_end();
    ref.Accept (*this);
    this->pop();
  }

  void FlatPlanVisitor::Visit_AssemblyConfigProperty(const AssemblyConfigProperty& acp)
  {
    this->push();
    DOMElement* value = this->doc_->createElement (XStr ("configProperty"));
    this->curr_->appendChild (value);
    this->curr_ = value;
    Property ref = acp.dstAssemblyConfigProperty_end();
    ref.Accept (*this);
    this->pop();
  }

  template <typename T, typename Del, typename DelRet, typename DelEndRet>
  void FlatPlanVisitor::GetComponents (const T& port,
                                      DelRet (T::*srcDel)() const,
                                      DelRet (T::*dstDel) () const,
                                      DelEndRet (Del::*srcDelEnd)() const,
                                      DelEndRet (Del::*dstDelEnd)() const,
                                      std::map<Component, std::string>& output,
                                      std::set<T>& visited)
  {
    visited.insert (port);
    Udm::Object par = port.parent();
    std::string recepName = port.name();
    std::string parentName = this->ExtractName (par);
    if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
      {
        std::set<Del> delegates = (port.*dstDel)();
        for (std::set<Del>::const_iterator iter = delegates.begin();
             iter != delegates.end();
             ++iter)
          {
            Del delegate = *iter;
            T srcPort = (delegate.*dstDelEnd)();
            std::string srcPortName = this->ExtractName(srcPort);
            if (std::find (visited.begin(),
                           visited.end(),
                           srcPort) == visited.end())
              this->GetComponents(srcPort, srcDel, dstDel,
                                  srcDelEnd, dstDelEnd, output, visited);
          }
        delegates = (port.*srcDel)();
        for (std::set<Del>::const_iterator iter = delegates.begin();
             iter != delegates.end();
             ++iter)
          {
            Del delegate = *iter;
            T dstPort = (delegate.*srcDelEnd)();
            std::string dstPortName = this->ExtractName(dstPort);
            if (std::find (visited.begin(),
                           visited.end(),
                           dstPort) == visited.end())
              this->GetComponents(dstPort, srcDel, dstDel,
                                  srcDelEnd, dstDelEnd, output, visited);
          }
      }
    else if (Udm::IsDerivedFrom (par.type(), Component::meta))
      {
        Component recep_comp = Component::Cast (par);
        output.insert (make_pair (recep_comp, port.name()));
      }
    visited.erase (port);
    return;
  }

  void FlatPlanVisitor::GetReceptacleComponents (const RequiredRequestPort& receptacle,
                                                std::map<Component,std::string>& output)
  {
    std::set<RequiredRequestPort> visited;
    this->GetComponents (receptacle,
                        &RequiredRequestPort::srcReceptacleDelegate,
                        &RequiredRequestPort::dstReceptacleDelegate,
                        &ReceptacleDelegate::srcReceptacleDelegate_end,
                        &ReceptacleDelegate::dstReceptacleDelegate_end,
                        output,
                        visited);
  }

  void FlatPlanVisitor::GetFacetComponents (const ProvidedRequestPort& facet,
                                           std::map<Component,std::string>& output)
  {
    std::set<ProvidedRequestPort> visited;
    this->GetComponents (facet,
                         &ProvidedRequestPort::srcFacetDelegate,
                         &ProvidedRequestPort::dstFacetDelegate,
                         &FacetDelegate::srcFacetDelegate_end,
                         &FacetDelegate::dstFacetDelegate_end,
                         output,
                         visited);
  }

  void FlatPlanVisitor::GetEventSinkComponents (const InEventPort& consumer,
                                               std::map<Component,std::string>& output)
  {
    std::set<InEventPort> visited;
    this->GetComponents (consumer,
                         &InEventPort::srcEventSinkDelegate,
                         &InEventPort::dstEventSinkDelegate,
                         &EventSinkDelegate::srcEventSinkDelegate_end,
                         &EventSinkDelegate::dstEventSinkDelegate_end,
                         output,
                         visited);
  }

    void FlatPlanVisitor::GetEventSourceComponents (const OutEventPort& publisher,
                                                   std::map<Component,std::string>& output)
  {
    std::set<OutEventPort> visited;
    this->GetComponents (publisher,
                         &OutEventPort::srcEventSourceDelegate,
                         &OutEventPort::dstEventSourceDelegate,
                         &EventSourceDelegate::srcEventSourceDelegate_end,
                         &EventSourceDelegate::dstEventSourceDelegate_end,
                         output,
                         visited);
  }

  void FlatPlanVisitor::CreateConnections (const std::map<Component, std::string>& src,
                                          const std::map<Component, std::string>& dst,
										  const std::string& source_kind,
										  const std::string& dest_kind)
  {
    for (std::map<Component,std::string>::const_iterator iter = src.begin();
         iter != src.end();
         ++iter)
      {
        Component srcComp = iter->first;
        std::string srcPortName = iter->second;
        for (std::map<Component, std::string>::const_iterator iter = dst.begin();
             iter != dst.end();
             ++iter)
          {
            Component dstComp = iter->first;
            std::string dstPortName = iter->second;
            this->CreateConnection (srcComp, srcPortName, dstComp, dstPortName, source_kind, dest_kind);
          }
      }
  }

  void FlatPlanVisitor::CreateConnection (const Component& srcComp,
                                         const std::string& srcPortName,
                                         const Component& dstComp,
                                         const std::string& dstPortName,
										 const std::string& source_kind,
										 const std::string& dest_kind)
  {
    // Create a connection
    DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    this->curr_->appendChild (ele);

    std::string connection = srcPortName + "_" + dstPortName;
    ele->appendChild (this->createSimpleContent ("name", connection));

    // Source endPoint
    DOMElement* endPoint
      = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      srcPortName));
	endPoint->appendChild (this->createSimpleContent ("kind",
                                                      dest_kind));
    // Source instance

    // DOMElement* instance = this->doc_->createElement (XStr ("instance"));
    // instance->setAttribute (XStr ("xmi:idref"),
    //                         XStr (srcComp.getPath ("_", false, true,"name",true)));
    // endPoint->appendChild (instance);

    std::string source_comp_instance = srcComp.getPath ("_",false,true,"name",true);
	endPoint->appendChild (this->createSimpleContent ("instance", source_comp_instance));
    ele->appendChild (endPoint);

    // Destination endPoint
    endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    endPoint->appendChild (this->createSimpleContent ("portName",
                                                      dstPortName));
	endPoint->appendChild (this->createSimpleContent ("kind",
                                                      source_kind));
    // Destination instance

    // instance = this->doc_->createElement (XStr ("instance"));
    // instance->setAttribute (XStr ("xmi:idref"),
    //                        XStr (dstComp.getPath ("_", false, true,"name",true)));
    // endPoint->appendChild (instance);

	std::string dest_comp_instance = dstComp.getPath ("_",false,true,"name",true);
	endPoint->appendChild (this->createSimpleContent ("instance", dest_comp_instance));
    ele->appendChild (endPoint);
  }

  std::string FlatPlanVisitor::ExtractName(Udm::Object ob)
  {
    Uml::Class cls= ob.type();
    set<Uml::Attribute> attrs=cls.attributes();

    // Adding parent attributes
    set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
    attrs.insert(aattrs.begin(),aattrs.end());

    for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++)
      {
        if(string(ai->type())=="String")
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

  void FlatPlanVisitor::Visit_invoke(const invoke& iv)
  {

    // Get the receptacle end
    RequiredRequestPort receptacle = iv.srcinvoke_end();

    // Get the facet end
    ProvidedRequestPort facet = iv.dstinvoke_end();

    std::map<Component,std::string> receptacles;
    std::map<Component,std::string> facets;
	std::string source_kind = "Facet";
	std::string dest_kind = "SimplexReceptacle";
    this->GetReceptacleComponents (receptacle, receptacles);
    this->GetFacetComponents (facet, facets);
    this->CreateConnections (receptacles, facets, source_kind, dest_kind);

	//this->push();

    //DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    //this->curr_->appendChild (ele);
    //this->curr_ = ele;

    //// Create a connection
    //std::string connection = receptacle.name();
    //connection += "_";
    //connection += facet.name();
    //ele->appendChild (this->createSimpleContent ("name", connection));

    //// Facet endPoint
    //DOMElement* endPoint
    //  = this->doc_->createElement (XStr ("internalEndpoint"));
    //endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                  facet.name()));
    //endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                  "Facet"));
    //// Facet instance
    //std::string uni_facet_insName = facet_comp.getPath ("_",false,true,"name",true);
    //endPoint->appendChild (this->createSimpleContent ("instance", uni_facet_insName));
    //ele->appendChild (endPoint);

    //// Receptacle endPoint
    //endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    //endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                  receptacle.name()));
    //endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                  "SimplexReceptacle"));
    //// Receptacle instance
    //std::string uni_recep_insName = recep_comp.getPath ("_",false,true,"name",true);
    //endPoint->appendChild (this->createSimpleContent ("instance", uni_recep_insName));
    //ele->appendChild (endPoint);

    //this->pop();
  }

  void FlatPlanVisitor::Visit_emit(const emit& ev)
  {
    // Get the emitter end
    OutEventPort emitter = ev.srcemit_end();

    // Get the consumer end
    InEventPort consumer = ev.dstemit_end();

    std::map<Component,std::string> emitters;
    std::map<Component,std::string> consumers;
	std::string source_kind = "EventConsumer";
	std::string dest_kind = "EventPublisher";
    this->GetEventSourceComponents (emitter, emitters);
    this->GetEventSinkComponents (consumer, consumers);
    this->CreateConnections (emitters, consumers, source_kind, dest_kind);

    //this->push();

    //DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    //this->curr_->appendChild (ele);
    //this->curr_ = ele;

    //// Create a connection
    //std::string connection = consumer.name();
    //connection += "_";
    //connection += emitter.name();
    //ele->appendChild (this->createSimpleContent ("name", connection));

    //// Emitter endPoint
    //DOMElement* endPoint
    //  = this->doc_->createElement (XStr ("internalEndpoint"));
    //endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                  emitter.name()));
    //endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                  "EventEmitter"));

    //// Emitter instance
    //std::string emitter_insName = emitter_comp.getPath ("_",false,true,"name",true);
    //endPoint->appendChild (this->createSimpleContent ("instance", emitter_insName));
    //ele->appendChild (endPoint);

    //// Consumer endPoint
    //endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    //endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                  consumer.name()));
    //endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                  "SimplexReceptacle"));
    //// Consumer instance
    //std::string consumer_insName = consumer_comp.getPath ("_",false,true,"name",true);
    //endPoint->appendChild (this->createSimpleContent ("instance", consumer_insName));
    //ele->appendChild (endPoint);

    //this->pop();
  }

  void FlatPlanVisitor::Visit_publish(const publish& ev)
  {
    // Get the publisher end
    const OutEventPort publisher = ev.srcpublish_end();

    // Get the connector end
    const PublishConnector connector = ev.dstpublish_end();

    // Create an entry in the publishers_ map
    this->publishers_[std::string (connector.name())] = publisher;
  }

  void FlatPlanVisitor::Visit_deliverTo(const deliverTo& dv)
  {
    // Get the connector end
    const  PublishConnector connector = dv.srcdeliverTo_end();

    // Get the consumer end
    const InEventPort consumer = dv.dstdeliverTo_end();

    // Create an entry in the consumers_ map
    this->consumers_.insert (make_pair (std::string (connector.name()),
                                        consumer));
  }

  void FlatPlanVisitor::Visit_PublishConnector(const PublishConnector& pubctor)
  {
    std::string ctor = pubctor.name();

    // Get Publisher
    OutEventPort publisher = this->publishers_[ctor];
    std::map<Component,std::string> publishers;
    this->GetEventSourceComponents (publisher, publishers);

    for (std::map<Component,std::string>::const_iterator
           iter = publishers.begin();
         iter != publishers.end();
         ++iter)
      {
        Component srcComp = iter->first;
        std::string srcPortName = iter->second;

        for (std::multimap<std::string, InEventPort>::const_iterator
               iter = this->consumers_.lower_bound (ctor);
             iter != this->consumers_.upper_bound (ctor);
             ++iter)
          {
            // Get Consumer
            InEventPort consumer = iter->second;
            std::map<Component,std::string> consumers;
            this->GetEventSinkComponents (consumer, consumers);
            for (std::map<Component,std::string>::const_iterator
                   iter = consumers.begin();
                 iter != consumers.end();
                 ++iter)
              {
                Component dstComp = iter->first;
                std::string dstPortName = iter->second;
				std::string source_kind = "EventConsumer";
				std::string dest_kind = "EventPublisher";
                this->CreateConnection (srcComp, srcPortName, dstComp,
                                        dstPortName, source_kind, dest_kind);
              }
          }
      }
	  
	//std::string ctor = pubctor.name();

    //// Get Publisher
    //OutEventPort publisher = this->publishers_[ctor];
    //Component publisher_comp;

    //for (std::multimap<std::string, InEventPort>::const_iterator
    //       iter = this->consumers_.lower_bound (ctor);
    //     iter != this->consumers_.upper_bound (ctor);
    //     ++iter)
    //  {
    //    this->push();

    //    DOMElement* ele = this->doc_->createElement (XStr ("connection"));
    //    this->curr_->appendChild (ele);
    //    this->curr_ = ele;

    //    // Get Consumer
    //    InEventPort consumer = iter->second;
    //    Component consumer_comp;

    //    while (true)
    //      {
    //        Udm::Object par = consumer.parent();
    //        if (Udm::IsDerivedFrom (par.type(), Component::meta))
    //          {
    //            consumer_comp = Component::Cast (par);
    //            break;
    //          }
    //        else if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
    //          {
    //            EventSinkDelegate delegate = consumer.dstEventSinkDelegate();
    //            if (delegate != Udm::null)
    //              consumer = delegate.dstEventSinkDelegate_end();
    //            else
    //              {
    //                delegate = consumer.srcEventSinkDelegate();
    //                consumer = delegate.srcEventSinkDelegate_end();
    //              }
    //          }
    //      }

    //    // Create connection(s)
    //    std::string connection = consumer.name();
    //    connection += "_";
    //    connection += publisher.name();
    //    ele->appendChild (this->createSimpleContent ("name", connection));

    //    // Publisher endPoint
    //    DOMElement* endPoint
    //      = this->doc_->createElement (XStr ("internalEndpoint"));
    //    endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                      publisher.name()));
    //    endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                      "EventPublisher"));
    //    // Publisher instance
    //    std::string publisher_insName = publisher_comp.getPath ("_",false,true,"name",true);
    //    endPoint->appendChild (this->createSimpleContent ("instance", publisher_insName));
    //    ele->appendChild (endPoint);

    //    // Consumer endPoint
    //    endPoint = this->doc_->createElement (XStr ("internalEndpoint"));
    //    endPoint->appendChild (this->createSimpleContent ("portName",
    //                                                      consumer.name()));
    //    endPoint->appendChild (this->createSimpleContent ("kind",
    //                                                      "EventConsumer"));
    //    // Consumer instance
    //    std::string consumer_insName = consumer_comp.getPath ("_",false,true,"name",true);
    //    endPoint->appendChild (this->createSimpleContent ("instance", consumer_insName));
    //    ele->appendChild (endPoint);

    //    this->pop();
    //  }
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
    this->initDocument ("Deployment:deploymentPlan");
    this->initRootAttributes();

	std::string label = dp.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
                                                           label));

    { 
      std::set<ComponentImplementations>
        folders = this->root_folder_.ComponentImplementations_kind_children();
      for (std::set<ComponentImplementations>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ComponentImplementations folder = *iter;
          folder.Accept (*this);
        }
    }

    const std::set<CollocationGroup> dps = dp.CollocationGroup_children();
    std::set<PICML::ComponentAssembly> containing_assemblies;
    MonolithicImplementation mimpl;

    for (std::set<CollocationGroup>::const_iterator iter = dps.begin();
         iter != dps.end();
         ++iter)
      {
        std::string nodeRefName;
		std::string cgName;
        CollocationGroup cg = *iter;
		cgName = cg.name();
		this->initcgName (cgName);

        const std::set<InstanceMapping> cg_ins_maps = cg.dstInstanceMapping ();

        for (std::set<InstanceMapping>::const_iterator cg_ins_map_iter = cg_ins_maps.begin();
             cg_ins_map_iter != cg_ins_maps.end ();
             ++cg_ins_map_iter)
          {
            InstanceMapping cg_ins = *cg_ins_map_iter;
            NodeReference node_ref = cg_ins.dstInstanceMapping_end();
            const Node ref = node_ref.ref();
            nodeRefName = ref.name();
            this->initNodeRefName (nodeRefName);
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
				std::string component_name = comp.name ();
                containing_assemblies.insert(comp.ComponentAssembly_parent());
                Component typeParent;
				if (this->monoimpls_.find (component_name) != this->monoimpls_.end ())
                  {
					  mimpl = this->monoimpls_[component_name];
				  }
				else
				  {
					if (comp.isInstance())
                      {
                        typeParent = comp.Archetype();
                        while (typeParent.isInstance())
                          typeParent = typeParent.Archetype();
                      }
                    std::string refName = typeParent.name();
                    if (this->monoimpls_.find (refName) != this->monoimpls_.end ())
                      {
                        mimpl = this->monoimpls_[refName];
                      }
				  }
                this->push ();
                DOMElement* ele = this->doc_->createElement (XStr ("instance"));
                std::string uniqueName = comp.getPath ("_",false,true,"name",true);
				/*uniqueName += "_";
				uniqueName += nodeRefName;
				uniqueName += "_";
				uniqueName += cgName;*/
                ele->setAttribute (XStr ("id"), XStr (uniqueName));
                ele->appendChild (this->createSimpleContent ("name", uniqueName));
                ele->appendChild (this->createSimpleContent ("node", nodeRefName));
                ele->appendChild (this->doc_->createElement (XStr ("source")));
                this->curr_->appendChild (ele);
                this->curr_ = ele;
                std::string mimpl_name = mimpl.getPath ("_",false,true,"name",true);
                this->curr_->appendChild (this->createSimpleContent ("implementation", mimpl_name));
                const std::set<ConfigProperty> cps = mimpl.dstConfigProperty();
                for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
                     it2 != cps.end();
                     ++it2)
                  {
                    ConfigProperty cp = *it2;
                    cp.Accept (*this);
                  }
                this->pop ();
              }
            else if (Udm::IsDerivedFrom (comp_type.type(), ComponentAssemblyReference::meta))
              {
                ComponentAssemblyReference comp_assembly_ref = ComponentAssemblyReference::Cast (comp_type);
                ComponentAssembly comp_assembly = comp_assembly_ref.ref ();
                containing_assemblies.insert(comp_assembly);
				containing_assemblies.insert(comp_assembly.ComponentAssembly_parent());
                comp_assembly.Accept (*this);
              }
          }
      }

    for (std::set<PICML::ComponentAssembly>::const_iterator assembly_iter = containing_assemblies.begin();
         assembly_iter != containing_assemblies.end (); ++assembly_iter)
      {
        ComponentAssembly component_assembly = *assembly_iter;
        update_connections (component_assembly);
      }

    {
      std::set<ImplementationArtifacts>
        folders = this->root_folder_.ImplementationArtifacts_kind_children();
      for (std::set<ImplementationArtifacts>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          ImplementationArtifacts folder = *iter;
          folder.Accept (*this);
        }
    }

    this->dumpDocument();
    this->pop();
  }

  void FlatPlanVisitor::update_connections(const ComponentAssembly& assembly)
  {
    /*std::set<ComponentAssembly>
      asms = assembly.ComponentAssembly_kind_children();
    for (std::set<ComponentAssembly>::iterator aiter = asms.begin();
         aiter != asms.end();
         ++aiter)
      {
        ComponentAssembly rassembly  = *aiter;
        rassembly.Accept (*this);
      }*/

    std::string node_reference_name = this->retNodeRefName ();

    /*std::set<Component> comps = assembly.Component_kind_children();
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
      }*/

	// Collect all the Components of this assembly into a set.
    std::set<Component> comps = assembly.Component_kind_children();

    // Collect all the immediate ComponentAssembly children of this assembly
    std::vector<ComponentAssembly>
      subasms = assembly.ComponentAssembly_kind_children();

    // Maintain a list of all ComponentAssemblies in this assembly
    std::vector<ComponentAssembly> assemblies;

    // Put ourselves in the global list first.
    assemblies.push_back (assembly);

    // Do a Depth-First search and collect all the ComponentAssembly,
    // Component children of this assembly, and add them to the
    // assembly-specific list.
    while (!subasms.empty())
      {
        ComponentAssembly rassembly = subasms.back();
        // Put the first assembly from the current list to the
        // assembly-specific list.
        assemblies.push_back (rassembly);

        subasms.pop_back();

        // Get the components of the current assembly, and insert them into
        // the component list
        std::set<Component> rcomps = rassembly.Component_kind_children();
        comps.insert (rcomps.begin(), rcomps.end());

        // Get the subassemblies of the first assembly.
        std::vector<ComponentAssembly>
          rasms = rassembly.ComponentAssembly_kind_children();

        // Insert them to the current list.
        std::copy (rasms.begin(), rasms.end(), std::back_inserter (subasms));
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
        this->publishers_.erase (this->publishers_.begin(),
                                 this->publishers_.end());

        this->consumers_.erase (this->consumers_.begin(),
                                this->consumers_.end());

      }
  }

  void FlatPlanVisitor::Visit_ComponentAssembly(const ComponentAssembly& assembly)
  {
    /*std::set<ComponentAssembly>
      asms = assembly.ComponentAssembly_kind_children();
    for (std::set<ComponentAssembly>::iterator aiter = asms.begin();
         aiter != asms.end();
         ++aiter)
      {
        ComponentAssembly rassembly  = *aiter;
        rassembly.Accept (*this);
      }*/

    std::string node_reference_name = this->retNodeRefName ();
	std::string cg_name = this->retcgName ();

    /*std::set<Component> comps = assembly.Component_kind_children();
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
      }*/

	// Collect all the Components of this assembly into a set.
    std::set<Component> comps = assembly.Component_kind_children();

    // Collect all the immediate ComponentAssembly children of this assembly
    std::vector<ComponentAssembly>
      subasms = assembly.ComponentAssembly_kind_children();

    // Maintain a list of all ComponentAssemblies in this assembly
    std::vector<ComponentAssembly> assemblies;

    // Put ourselves in the global list first.
    assemblies.push_back (assembly);

    // Do a Depth-First search and collect all the ComponentAssembly,
    // Component children of this assembly, and add them to the
    // assembly-specific list.
    while (!subasms.empty())
      {
        ComponentAssembly rassembly = subasms.back();
        // Put the first assembly from the current list to the
        // assembly-specific list.
        assemblies.push_back (rassembly);

        subasms.pop_back();

        // Get the components of the current assembly, and insert them into
        // the component list
        std::set<Component> rcomps = rassembly.Component_kind_children();
        comps.insert (rcomps.begin(), rcomps.end());

        // Get the subassemblies of the first assembly.
        std::vector<ComponentAssembly>
          rasms = rassembly.ComponentAssembly_kind_children();

        // Insert them to the current list.
        std::copy (rasms.begin(), rasms.end(), std::back_inserter (subasms));
      }

    // Create the appropriate component attribute value mappings
    this->CreateAttributeMappings (assemblies);

    MonolithicImplementation mimpl;
    for (std::set<Component>::iterator iter = comps.begin();
         iter != comps.end();
         ++iter)
      {
        Component comp = *iter;
        Component typeParent;
        if (comp.isInstance())
          {
            typeParent = comp.Archetype();
            while (typeParent.isInstance())
              typeParent = typeParent.Archetype();
          }
        std::string refName = typeParent.name();
        if (this->monoimpls_.find (refName) != this->monoimpls_.end ())
          {
            mimpl = this->monoimpls_[refName];
          }
        this->push ();
        DOMElement* ele = this->doc_->createElement (XStr ("instance"));
        std::string uniqueName = comp.getPath ("_",false,true,"name",true);
		/*uniqueName += "_";
		uniqueName += node_reference_name;
		uniqueName += "_";
		uniqueName += cg_name;*/
        ele->setAttribute (XStr ("id"), XStr (uniqueName));
        ele->appendChild (this->createSimpleContent ("name", uniqueName));
        ele->appendChild (this->createSimpleContent ("node", node_reference_name));
        ele->appendChild (this->doc_->createElement (XStr ("source")));
        this->curr_->appendChild (ele);
        this->curr_ = ele;
        std::string mimpl_name = mimpl.getPath ("_",false,true,"name",true);
        this->curr_->appendChild (this->createSimpleContent ("implementation", mimpl_name));
		std::set<AssemblyConfigProperty> cps = comp.dstAssemblyConfigProperty();
        for (std::set<AssemblyConfigProperty>::const_iterator it2 = cps.begin();
             it2 != cps.end();
             ++it2)
          {
            AssemblyConfigProperty cp = *it2;
            cp.Accept (*this);
          }
        std::set<ReadonlyAttribute> attrs = comp.ReadonlyAttribute_children();
        for (std::set<ReadonlyAttribute>::const_iterator iter = attrs.begin();
             iter != attrs.end();
             ++iter)
          {
            ReadonlyAttribute attr = *iter;
            attr.Accept (*this);
          }
        for (std::map<std::pair<std::string, std::string>, Property>::const_iterator iter = this->attrValues_.begin();
             iter != this->attrValues_.end();
             ++iter)
          {
            std::pair<std::pair<std::string, std::string>, Property>
              attrVal = *iter;
            std::pair<std::string, std::string> compAttr = attrVal.first;
            if (compAttr.first == uniqueName)
              {
                this->push();
                DOMElement*
                  ele = this->doc_->createElement (XStr ("configProperty"));
                this->curr_->appendChild (ele);
				this->curr_ = ele;
                Property val = attrVal.second;
                val.Accept (*this);
				this->pop();
              }
          }
		/*
        const std::set<ConfigProperty> mcps = mimpl.dstConfigProperty();
        for (std::set<ConfigProperty>::const_iterator it2 = mcps.begin();
             it2 != mcps.end();
             ++it2)
          {
            ConfigProperty mcp = *it2;
            mcp.Accept (*this);
          }
        */

        this->pop ();
      }
  }

  void FlatPlanVisitor::CreateAttributeMappings (std::vector<ComponentAssembly>& assemblies)
  {
    for (std::vector<ComponentAssembly>::iterator iter = assemblies.begin();
         iter != assemblies.end();
         ++iter)
      {
        ComponentAssembly assembly = *iter;
        std::string assemblyName = this->ExtractName (assembly);
        const std::set<AttributeMapping>
          mappings = assembly.AttributeMapping_kind_children();
        for (std::set<AttributeMapping>::const_iterator iter = mappings.begin();
             iter != mappings.end();
             ++iter)
          {
            AttributeMapping mapping = *iter;
            mapping.Accept (*this);
          }
      }
  }

  void FlatPlanVisitor::Visit_AttributeMapping(const AttributeMapping& mapping)
  {
    std::string mappingName = this->ExtractName (mapping);
    AttributeMappingValue value = mapping.dstAttributeMappingValue();
    if (value != Udm::null)
      {
        Property prop = value.dstAttributeMappingValue_end();
        std::set<std::pair<std::string, std::string> > compAttrs;
        this->GetAttributeComponents (mapping, compAttrs);
        for (std::set<std::pair<std::string, std::string> >::const_iterator
               iter = compAttrs.begin();
             iter != compAttrs.end();
             ++iter)
          {
            // Get the component, attribute pair
            pair<std::string, std::string> compAttr = *iter;
            // Set the name of the associated property to the attribute name
            prop.name() = compAttr.second;
            // If this component's attribute hasn't been assigned a value,
            // i.e., a value hasn't been propagated from a higher-level assembly,
            // set it to the current value.
            if (this->attrValues_.find (compAttr) == this->attrValues_.end())
              this->attrValues_[compAttr] = prop;
          }
      }
  }

  void FlatPlanVisitor::GetAttributeComponents (const AttributeMapping& mapping,
                                               std::set<std::pair<std::string, std::string> >& output)
  {
    std::string mappingName = this->ExtractName (mapping);
    std::set<AttributeDelegate> delegates = mapping.dstAttributeDelegate();
    if (delegates.empty())
      {
        std::set<AttributeMappingDelegate>
          mapDelegates = mapping.dstAttributeMappingDelegate();
        if (mapDelegates.empty())
          {
            std::string mapPath = mapping.getPath ("_", false, true,"name",true);

            throw udm_exception (std::string ("AttributeMapping " +
                                              mapPath +
                                              " is not connected to any attributes or delegated to another AttributeMapping"));
          }
        else
          {
            for (std::set<AttributeMappingDelegate>::const_iterator
                   iter = mapDelegates.begin();
                 iter != mapDelegates.end();
                 ++iter)
              {
                AttributeMappingDelegate mapDelegate = *iter;
                AttributeMapping
                  delegate = mapDelegate.dstAttributeMappingDelegate_end();
                std::string delegateName = this->ExtractName (delegate);
                this->GetAttributeComponents (delegate, output);
              }
          }
      }
    else
      {
        for (std::set<AttributeDelegate>::const_iterator
               iter = delegates.begin();
             iter != delegates.end();
             ++iter)
          {
            AttributeDelegate delegate = *iter;
            ReadonlyAttribute attr = delegate.dstAttributeDelegate_end();
            std::string attrName = this->ExtractName (attr);
            Component parent = attr.Component_parent();
            std::string parentName = this->ExtractName (parent);
            std::string compName = parent.getPath ("_", false, true,"name",true);
            output.insert (make_pair (compName, attr.name()));
          }
      }
  }

  void FlatPlanVisitor::CreateAssemblyInstances (std::set<Component>& comps)
  {
    for (std::set<Component>::iterator iter = comps.begin();
         iter != comps.end();
         ++iter)
      {
        Component comp = *iter;
        DOMElement* instance = this->doc_->createElement (XStr ("instance"));
        this->curr_->appendChild (instance);
        this->push();
        this->curr_ = instance;
        std::string uniqueName = comp.getPath ("_",false,true,"name",true);
        instance->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
        instance->appendChild (this->createSimpleContent ("name",
                                                          uniqueName));
        Component typeParent;
        if (comp.isInstance())
          {
           typeParent = comp.Archetype();
            while (typeParent.isInstance())
              typeParent = typeParent.Archetype();
          }
        std::string interfaceName = typeParent.name();
        std::string refName = this->interfaces_[interfaceName];
        refName += ".cpd";
        DOMElement* refEle = this->doc_->createElement (XStr ("package"));
        refEle->setAttribute (XStr ("href"), XStr (refName));
        instance->appendChild (refEle);
        std::set<AssemblyConfigProperty> cps = comp.dstAssemblyConfigProperty();
        for (std::set<AssemblyConfigProperty>::const_iterator it2 = cps.begin();
             it2 != cps.end();
             ++it2)
          {
            AssemblyConfigProperty cp = *it2;
            cp.Accept (*this);
          }
        std::set<ReadonlyAttribute> attrs = comp.ReadonlyAttribute_children();
        for (std::set<ReadonlyAttribute>::const_iterator iter = attrs.begin();
             iter != attrs.end();
             ++iter)
          {
            ReadonlyAttribute attr = *iter;
            attr.Accept (*this);
          }
        for (std::map<std::pair<std::string, std::string>, Property>::const_iterator iter = this->attrValues_.begin();
             iter != this->attrValues_.end();
             ++iter)
          {
            std::pair<std::pair<std::string, std::string>, Property>
              attrVal = *iter;
            std::pair<std::string, std::string> compAttr = attrVal.first;
            if (compAttr.first == uniqueName)
              {
                this->push();
                DOMElement*
                  ele = this->doc_->createElement (XStr ("configProperty"));
                this->curr_->appendChild (ele);
				this->curr_ = ele;
                Property val = attrVal.second;
                val.Accept (*this);
				this->pop();
              }
          }
        this->pop();
      }
  }

  void FlatPlanVisitor::Visit_ReadonlyAttribute(const ReadonlyAttribute& attr)
  {
    AttributeValue attValue = attr.dstAttributeValue();
    if (attValue != Udm::null)
      attValue.Accept (*this);
  }

  void FlatPlanVisitor::Visit_AttributeValue(const AttributeValue& value)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (XStr ("configProperty"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    Property ref = value.dstAttributeValue_end();
    ReadonlyAttribute attr = value.srcAttributeValue_end();
    ref.name() = attr.name();
    ref.Accept (*this);
    this->pop();
  }

  void FlatPlanVisitor::Visit_AttributeDelegate(const AttributeDelegate&){}
  void FlatPlanVisitor::Visit_AttributeMappingValue(const AttributeMappingValue&){}
  void FlatPlanVisitor::Visit_AttributeMappingDelegate(const AttributeMappingDelegate&){}

  void FlatPlanVisitor::CreateAssemblyConnections (std::vector<ComponentAssembly>& assemblies)
  {
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
        this->publishers_.clear();
        this->consumers_.clear();
      }


  }

  void FlatPlanVisitor::Visit_MonolithExecParameter(const MonolithExecParameter&)
  {}

  void FlatPlanVisitor::Visit_InstanceMapping(const InstanceMapping& ins_map)
  {
    NodeReference node_ref = ins_map.dstInstanceMapping_end();
    node_ref.Accept (*this);
  }

  void FlatPlanVisitor::Visit_NodeReference(const NodeReference& node_ref)
  {
  }

}
