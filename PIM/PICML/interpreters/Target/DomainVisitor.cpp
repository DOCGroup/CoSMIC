// $Id$

#include "ace/config.h"
#include "Utils/Utils.h"
#include "DomainVisitor.h"

#include "game/xml/String.h"

#include "Uml.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

namespace PICML
{
  DomainVisitor::DomainVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), target_ (0),
    outputPath_ (outputPath)
  {
    this->init();
  }

  DomainVisitor::~DomainVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
  }

  void DomainVisitor::init()
  {
    this->impl_ = DOMImplementationRegistry::getDOMImplementation(L"LS");
    this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer();

    // Set features if the serializer supports the feature/mode
    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
  }

  void DomainVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void DomainVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (GAME::Xml::String ("http://www.omg.org/Deployment"),
      GAME::Xml::String (rootName.c_str()),
      0);
  }

  void DomainVisitor::initRootAttributes()
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

  void DomainVisitor::dumpDocument()
  {
    xercesc::DOMLSOutput * output = ((DOMImplementationLS*)this->impl_)->createLSOutput ();
    output->setByteStream (this->target_);

    this->serializer_->write (this->doc_, output);
    output->release ();
  }

  void DomainVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void DomainVisitor::pop()
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

  DOMElement* DomainVisitor::createSimpleContent (const std::string& name,
    const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (GAME::Xml::String (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (GAME::Xml::String (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  void DomainVisitor::Visit_RootFolder(const RootFolder& rf)
  {
    {
      std::set<Targets>
        folders = rf.Targets_kind_children();
      for (std::set<Targets>::iterator iter = folders.begin();
        iter != folders.end();
        ++iter)
      {
        Targets folder = *iter;
        folder.Accept (*this);
      }
    }
  }

  void DomainVisitor::Visit_Targets(const Targets& targets)
  {
    std::set<Domain>
      domains = targets.Domain_kind_children();
    for (std::set<Domain>::iterator iter = domains.begin();
      iter != domains.end();
      ++iter)
    {
      Domain domain = *iter;
      domain.Accept (*this);
    }
  }

  void DomainVisitor::Visit_Domain(const Domain& domain)
  {
    this->push();
    std::string name = this->outputPath_ + "\\";
    name += domain.name();
    name += ".cdd";
    this->initTarget (name);
    this->initDocument ("Deployment:domain");
    this->initRootAttributes();

    std::string label = domain.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
      label));
    std::string uuid = domain.UUID();
    if (uuid.empty())
      domain.UUID() = uuid = ::Utils::CreateUuid();
    this->curr_->appendChild (this->createSimpleContent ("UUID", uuid));

    const std::set<Node> domain_nodes = domain.Node_kind_children();
    for (std::set<Node>::const_iterator domain_node_iter = domain_nodes.begin();
      domain_node_iter != domain_nodes.end();
      ++domain_node_iter)
    {
      Node domain_node = *domain_node_iter;
      domain_node.Accept (*this);
    }

    const std::set<Interconnect>
      domain_ics = domain.Interconnect_kind_children();
    for (std::set<Interconnect>::const_iterator
      domain_ic_iter = domain_ics.begin();
      domain_ic_iter != domain_ics.end();
    ++domain_ic_iter)
    {
      Interconnect domain_ic = *domain_ic_iter;
      domain_ic.Accept (*this);
    }

    const std::set<Bridge> domain_bridges = domain.Bridge_kind_children();
    for (std::set<Bridge>::const_iterator
      domain_bridge_iter = domain_bridges.begin();
      domain_bridge_iter != domain_bridges.end();
    ++domain_bridge_iter)
    {
      Bridge domain_bridge = *domain_bridge_iter;
      domain_bridge.Accept (*this);
    }

    const std::set<SharedResource>
      domain_srs = domain.SharedResource_kind_children();
    for (std::set<SharedResource>::const_iterator
      domain_sr_iter = domain_srs.begin();
      domain_sr_iter != domain_srs.end();
    ++domain_sr_iter)
    {
      SharedResource domain_sr = *domain_sr_iter;
      domain_sr.Accept (*this);
    }

    this->dumpDocument();
    this->pop();
  }

  void DomainVisitor::Visit_Node(const Node& node)
  {
    this->push();

    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("node"));
    ele->appendChild (this->createSimpleContent ("name", node.name()));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    std::string label = node.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
      label));

    const std::set<Resource> resources = node.Resource_children();
    for (std::set<Resource>::const_iterator iter = resources.begin();
      iter != resources.end();
      ++iter)
    {
      Resource node_res = *iter;
      node_res.Accept (*this);
    }

    //const std::set <InterconnectConnection>
    //  node_to_ics = node.dstInterconnectConnection ();

    //for (std::set <InterconnectConnection>::const_iterator
    //     node_to_ic_iter  = node_to_ics.begin();
    //     node_to_ic_iter != node_to_ics.end ();
    //     ++ node_to_ic_iter)
    //{
    //  Interconnect node_ic = node_to_ic_iter->dstInterconnectConnection_end ();
    //  node_ic.Accept (*this);
    //}

    this->pop();
  }

  void DomainVisitor::Visit_Interconnect(const Interconnect& ic)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("interconnect"));
    ele->appendChild (this->createSimpleContent ("name", ic.name()));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    std::string label = ic.label();
    if (!label.empty())
      this->curr_->appendChild (this->createSimpleContent ("label",
      label));

    const std::set<Resource> resources = ic.Resource_children();
    for (std::set<Resource>::const_iterator iter = resources.begin();
      iter != resources.end();
      ++iter)
    {
      Resource ic_res = *iter;
      DOMElement* res_ele = this->doc_->createElement (GAME::Xml::String ("resource"));
      res_ele->appendChild (this->createSimpleContent ("name", ic_res.name()));
      this->curr_->appendChild (res_ele);
    }

    //const std::set<Interconnect2Node> ic_to_nodes = ic.dstInterconnect2Node();
    //for (std::set<Interconnect2Node>::const_iterator
    //  ic_to_node_iter = ic_to_nodes.begin();
    //  ic_to_node_iter != ic_to_nodes.end ();
    //++ic_to_node_iter)
    //{
    //  Interconnect2Node ic_to_node = *ic_to_node_iter;
    //  Node ic_node = ic_to_node.dstInterconnect2Node_end();
    //}

    //const std::set<Interconnect2Bridge>
    //  ic_to_bridges = ic.dstInterconnect2Bridge();
    //for (std::set<Interconnect2Bridge>::const_iterator
    //  ic_to_bridge_iter = ic_to_bridges.begin();
    //  ic_to_bridge_iter != ic_to_bridges.end ();
    //++ic_to_bridge_iter)
    //{
    //  Interconnect2Bridge ic_to_bridge = *ic_to_bridge_iter;
    //  Bridge ic_bridge = ic_to_bridge.dstInterconnect2Bridge_end();
    //}

    this->pop();
  }

  void DomainVisitor::Visit_Bridge(const Bridge& br)
  {
    this->push();

    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("bridge"));
    ele->appendChild (this->createSimpleContent ("name", br.name()));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    const std::set<Resource> resources = br.Resource_children();
    for (std::set<Resource>::const_iterator iter = resources.begin();
      iter != resources.end();
      ++iter)
    {
      Resource br_res = *iter;
      br_res.Accept (*this);
    }

    //const std::set<Bridge2Interconnect>
    //  bridge_to_ics = br.dstBridge2Interconnect();
    //for (std::set<Bridge2Interconnect>::const_iterator
    //  bridge_to_ic_iter = bridge_to_ics.begin();
    //  bridge_to_ic_iter != bridge_to_ics.end ();
    //++bridge_to_ic_iter)
    //{
    //  Bridge2Interconnect bridge_to_ic = *bridge_to_ic_iter;
    //  Interconnect bridge_ic = bridge_to_ic.dstBridge2Interconnect_end();
    //}

    this->pop();
  }

  void DomainVisitor::Visit_SharedResource(const SharedResource& sr)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("sharedResource"));
    ele->appendChild (this->createSimpleContent ("name", sr.name()));
    ele->appendChild (this->createSimpleContent ("resourceType",
      sr.resourceType()));

    this->curr_->appendChild (ele);
    this->curr_ = ele;

    std::set<SatisfierProperty> sprops = sr.SatisfierProperty_kind_children();
    for (std::set<SatisfierProperty>::const_iterator iter = sprops.begin();
      iter != sprops.end();
      ++iter)
    {
      SatisfierProperty property = *iter;
      property.Accept (*this);
    }

    this->pop();
  }

  void DomainVisitor::Visit_InstanceMapping(const InstanceMapping& ins_map)
  {
    NodeReference node_ref = ins_map.dstInstanceMapping_end();
    node_ref.Accept (*this);
  }

  void DomainVisitor::Visit_Resource(const Resource& res)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("resource"));
    ele->appendChild (this->createSimpleContent ("name", res.name()));
    ele->appendChild (this->createSimpleContent ("resourceType",
      res.resourceType()));
    this->curr_->appendChild (ele);
    this->curr_ = ele;

    std::set<SatisfierProperty> sprops = res.SatisfierProperty_kind_children();
    for (std::set<SatisfierProperty>::const_iterator iter = sprops.begin();
      iter != sprops.end();
      ++iter)
    {
      SatisfierProperty property = *iter;
      property.Accept (*this);
    }
    this->pop();
  }

  void DomainVisitor::Visit_SatisfierProperty(const SatisfierProperty& property)
  {
    this->push();
    DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("property"));
    ele->appendChild (this->createSimpleContent ("name", property.name()));
    ele->appendChild (this->createSimpleContent ("kind", property.SatisfierPropertyKind()));
    ele->appendChild (this->createSimpleContent ("dynamic",
      property.dynamic() ? "true" : "false"));
    this->curr_->appendChild (ele);
    this->curr_ = ele;
    // Property's value
    DOMElement* value = this->doc_->createElement (GAME::Xml::String ("value"));
    this->curr_->appendChild (value);
    this->curr_ = value;
    // Property's type
    DataType type = property.DataType_child();
    type.Accept (*this);
    // Property's type's value
    DOMElement* val = this->doc_->createElement (GAME::Xml::String ("value"));
    this->curr_->appendChild (val);
    this->curr_ = val;

    /// @note If the domain interpreter is to support complex types,
    ///       then this section of the code will need changing.

    PredefinedType ptype = PICML::PredefinedType::Cast (type.ref());
    Uml::Class meta = ptype.type ();

    if (meta == PICML::Boolean::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("boolean",
        property.DataValue()));
    }
    else if (meta == PICML::Byte::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("octet",
        property.DataValue()));
    }
    else if (meta == PICML::String::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("string",
        property.DataValue()));
    }
    else if (meta == PICML::FloatNumber::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("float",
        property.DataValue()));
    }
    else if (meta == PICML::DoubleNumber::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("double",
        property.DataValue()));
    }
    else if (meta == PICML::ShortInteger::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("short",
        property.DataValue()));
    }
    else if (meta == PICML::LongInteger::meta)
    {
      this->curr_->appendChild (this->createSimpleContent ("long",
        property.DataValue()));
    }

    this->pop();
  }

  void DomainVisitor::Visit_DataType(const DataType& type)
  {
    PredefinedType ref = PICML::PredefinedType::Cast (type.ref());
    Uml::Class meta = ref.type ();

    if (meta == PICML::Boolean::meta)
    {
      Boolean boolv = PICML::Boolean::Cast (ref);
      boolv.Accept (*this);
    }
    else if (meta == PICML::Byte::meta)
    {
      Byte byte = PICML::Byte::Cast (ref);
      byte.Accept (*this);
    }
    else if (meta == PICML::String::meta)
    {
      String str = PICML::String::Cast (ref);
      str.Accept (*this);
    }
    else if (meta == PICML::FloatNumber::meta)
    {
      FloatNumber real = PICML::FloatNumber::Cast (ref);
      real.Accept (*this);
    }
    else if (meta == PICML::DoubleNumber::meta)
    {
      DoubleNumber real = PICML::DoubleNumber::Cast (ref);
      real.Accept (*this);
    }
    else if (meta == PICML::ShortInteger::meta)
    {
      ShortInteger shortv = PICML::ShortInteger::Cast (ref);
      shortv.Accept (*this);
    }
    else if (meta == PICML::LongInteger::meta)
    {
      LongInteger lint = PICML::LongInteger::Cast (ref);
      lint.Accept (*this);
    }
  }

  // Predefined Types
  void DomainVisitor::Visit_Boolean(const Boolean& boolean)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_boolean"));
    this->pop();

  }

  void DomainVisitor::Visit_Byte(const Byte& byte)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_octet"));
    this->pop();
  }

  void DomainVisitor::Visit_String(const String& str)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_string"));
    this->pop();
  }

  void DomainVisitor::Visit_FloatNumber (const FloatNumber & real)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_float"));
    this->pop();
  }

  void DomainVisitor::Visit_DoubleNumber (const DoubleNumber & real)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_double"));
    this->pop();
  }

  void DomainVisitor::Visit_ShortInteger(const ShortInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_short"));
    this->pop();
  }

  void DomainVisitor::Visit_LongInteger(const LongInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_long"));
    this->pop();
  }
}