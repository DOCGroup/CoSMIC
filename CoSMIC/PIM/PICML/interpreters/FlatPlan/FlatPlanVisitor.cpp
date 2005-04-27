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
    this->push();
    std::string name = this->outputPath_ + "\\";
	//name += dp.name();
    name += "DeploymentPlan.cdp";
    this->initTarget (name);
    this->initDocument ("Deployment:DeploymentPlan");
    this->initRootAttributes();

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
      std::set<DeploymentPlans> folders = rf.DeploymentPlans_kind_children();
      for (std::set<DeploymentPlans>::iterator iter = folders.begin();
           iter != folders.end();
           ++iter)
        {
          DeploymentPlans folder = *iter;
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

	this->dumpDocument();
    this->pop();
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
	std::string uniqueName = ia.getPath ("_",false,true);
	ele->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
	ele->appendChild (this->createSimpleContent ("name", uniqueName));
	std::string location = ia.location();
    if (!location.empty())
      ele->appendChild (this->createSimpleContent ("location",
                                                           location));
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
	std::string uniqueName = mimpl.getPath ("_",false,true);
	ele->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
	ele->appendChild (this->createSimpleContent ("name", uniqueName));
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

	/*
	//this->pop();

    const std::set<ConfigProperty>
      cps = mimpl.dstConfigProperty();
    for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
         it2 != cps.end();
         ++it2)
      {
        ConfigProperty cp = *it2;
        cp.Accept (*this);
      }
    */

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
	std::string uniqueName = ref.getPath ("_",false,true);
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

  void FlatPlanVisitor::Visit_invoke(const invoke& iv)
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

  void FlatPlanVisitor::Visit_emit(const emit& ev)
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
	const std::set<CollocationGroup> dps = dp.CollocationGroup_children();
	std::set<PICML::ComponentAssembly> containing_assemblies;
	MonolithicImplementation mimpl;

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
                containing_assemblies.insert(comp.ComponentAssembly_parent());
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
			    this->push();
                DOMElement* ele = this->doc_->createElement (XStr ("instance"));
				std::string uniqueName = comp.getPath ("_",false,true);
	            ele->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
				ele->appendChild (this->createSimpleContent ("name", uniqueName));
                ele->appendChild (this->createSimpleContent ("node", refName));
                this->curr_->appendChild (ele);
				this->curr_ = ele;
				std::string mimpl_name = mimpl.getPath ("_",false,true);
	            this->curr_->appendChild (this->createSimpleContent ("implementation", mimpl_name));
				const std::set<ConfigProperty> cps = mimpl.dstConfigProperty();
				for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
					it2 != cps.end();
					++it2)
				{
					ConfigProperty cp = *it2;
					cp.Accept (*this);
				}
                this->pop();
			  }
		    else if (Udm::IsDerivedFrom (comp_type.type(), ComponentAssemblyReference::meta))
			  {
			    ComponentAssemblyReference comp_assembly_ref = ComponentAssemblyReference::Cast (comp_type);
				ComponentAssembly comp_assembly = comp_assembly_ref.ref ();
				containing_assemblies.insert(comp_assembly);
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

    this->pop();
  }

  void FlatPlanVisitor::update_connections(const ComponentAssembly& assembly)
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
		this->push();
        DOMElement* ele = this->doc_->createElement (XStr ("instance"));
		std::string uniqueName = comp.getPath ("_",false,true);
	    ele->setAttribute (XStr ("xmi:id"), XStr (uniqueName));
		ele->appendChild (this->createSimpleContent ("name", uniqueName));
        ele->appendChild (this->createSimpleContent ("node", node_reference_name));
        this->curr_->appendChild (ele);
		std::string mimpl_name = mimpl.getPath ("_",false,true);
	    this->curr_->appendChild (this->createSimpleContent ("implementation", mimpl_name));
		const std::set<ConfigProperty> cps = mimpl.dstConfigProperty();
		for (std::set<ConfigProperty>::const_iterator it2 = cps.begin();
			it2 != cps.end();
			++it2)
		{
			ConfigProperty cp = *it2;
			cp.Accept (*this);
		}
		this->pop();
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
