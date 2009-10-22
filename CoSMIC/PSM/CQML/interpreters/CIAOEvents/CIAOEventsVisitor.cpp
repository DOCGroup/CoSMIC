// $Id$

#include "Utils/xercesc/XercesString.h"
#include "Utils/Utils.h"

#include "CIAOEvents/CIAOEventsVisitor.h"

#include "UmlExt.h"
#include "UdmUtil.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

using Utils::XStr;
using Utils::CreateUuid;

#include <sstream>


namespace CQML
{

  //-----------------------------------------------------------------------------

  CIAOEventsVisitor::CIAOEventsVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), serializer_ (0),
    outputPath_ (outputPath), serv_count_(0)
  {
    this->init();
  }

  //-----------------------------------------------------------------------------

  CIAOEventsVisitor::~CIAOEventsVisitor ()
  {
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::init()
  {
    this->impl_ = DOMImplementationRegistry::getDOMImplementation(XStr("LS"));
    this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer();

    // Set features if the serializer supports the feature/mode
    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::Visit_RootFolder(const CQML::RootFolder& rf)
  {
    std::set<CQML::ComponentImplementations> ci_folders
      = rf.ComponentImplementations_kind_children ();
    for (std::set<CQML::ComponentImplementations>::iterator ci_it =
      ci_folders.begin ();
      ci_it != ci_folders.end ();
    ci_it++)
    {
      std::set<CQML::ComponentImplementationContainer> cic_models =
        ci_it->ComponentImplementationContainer_kind_children ();
      for (std::set<CQML::ComponentImplementationContainer>::iterator
        cic_it = cic_models.begin ();
        cic_it != cic_models.end ();
      cic_it++)
      {
        std::set<CQML::ComponentAssembly> ca_models =
          cic_it->ComponentAssembly_kind_children ();
        for (std::set<CQML::ComponentAssembly>::iterator ca_it =
          ca_models.begin ();
          ca_it != ca_models.end ();
        ca_it++)
        {
          std::set<CQML::CIAOEvents> ce_models =
            ca_it->CIAOEvents_kind_children ();
          for (std::set<CQML::CIAOEvents>::iterator ce_it =
            ce_models.begin ();
            ce_it != ce_models.end ();
          ce_it++)
          {
            // print one file for each CIAOEvents element in the
            // model
            print_es_configuration (*ce_it, outputPath_);
          }
        }
      }
    }
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::print_es_configuration (
    const CQML::CIAOEvents& event_config,
    const std::string& path)
  {
    this->serv_count_ = 0;

    // ------ Create the document header -----------------------

    xercesc::DOMDocument* doc =
      this->impl_->createDocument (
      XStr ("http://www.dre.vanderbilt.edu/CIAOEvents"),
      XStr ("CIAO:CIAOEvents"),
      0);

    //doc->setEncoding (XStr("UTF-8"));
    doc->setXmlVersion (XStr("1.0"));
    xercesc::DOMElement* root_node = doc->getDocumentElement();
    root_node->setAttributeNS (
      XStr ("http://www.w3.org/2000/xmlns/"),
      XStr ("xmlns:CIAO"),
      XStr ("http://www.dre.vanderbilt.edu/CIAOEvents"));
    root_node->setAttributeNS (
      XStr ("http://www.w3.org/2000/xmlns/"),
      XStr ("xmlns:xmi"),
      XStr ("http://www.omg.org/XMI"));
    root_node->setAttributeNS (
      XStr ("http://www.w3.org/2000/xmlns/"),
      XStr ("xmlns:xsi"),
      XStr ("http://www.w3.org/2001/XMLSchema-instance"));
    root_node->setAttribute (
      XStr ("xsi:schemaLocation"),
      XStr ("http://www.dre.vanderbilt.edu/CIAOEvents CIAOEvents.xsd"));

    std::set<CQML::eventServiceConfiguration> es_models =
      event_config.eventServiceConfiguration_kind_children ();

    // ------ add the eventServiceConfiguration entries

    for (std::set<CQML::eventServiceConfiguration>::iterator es_it =
      es_models.begin ();
      es_it != es_models.end ();
    es_it++)
    {
      add_event_service_configuration (root_node, *es_it);
    }

    // write the file to disk
    std::stringstream output_file;
    output_file << path << "\\" << event_config.name () << ".ced";

    xercesc::LocalFileFormatTarget target (output_file.str ().c_str ());
    xercesc::DOMLSOutput * output = ((DOMImplementationLS*)this->impl_)->createLSOutput ();
    output->setByteStream (&target);

    this->serializer_->write (this->doc_, output);
    output->release ();

    target.flush ();
    doc->release ();
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::add_event_service_configuration (
    xercesc::DOMElement* node,
    const CQML::eventServiceConfiguration esc)
  {
    // create dom element
    xercesc::DOMElement* ec =
      node->getOwnerDocument ()->createElement (
      XStr("eventServiceConfiguration"));
    ec->setAttribute (XStr("id"), XStr ((std::string)esc.configuration_id ()));

    // add name node
    xercesc::DOMElement* name_elem =
      node->getOwnerDocument ()->createElement (XStr ("name"));
    xercesc::DOMText* name_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)esc.name ()));
    name_elem->appendChild (name_text);
    ec->appendChild (name_elem);

    // add node node
    xercesc::DOMElement* node_elem =
      node->getOwnerDocument ()->createElement (XStr ("node"));
    xercesc::DOMText* node_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)esc.node ()));
    node_elem->appendChild (node_text);
    ec->appendChild (node_elem);

    // add type node
    xercesc::DOMElement* type_elem =
      node->getOwnerDocument ()->createElement (XStr ("type"));
    xercesc::DOMText* type_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)esc.type ()));
    type_elem->appendChild (type_text);
    ec->appendChild (type_elem);

    // add svc_cfg_file node
    xercesc::DOMElement* svc_elem =
      node->getOwnerDocument ()->createElement (XStr ("svc_cfg_file"));
    xercesc::DOMText* svc_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)esc.svc_cfg_file ()));
    svc_elem->appendChild (svc_text);
    ec->appendChild (svc_elem);

    // add all filters
    std::set<CQML::Filter> filters = esc.Filter_kind_children ();
    for (std::set<CQML::Filter>::iterator filter_it = filters.begin ();
      filter_it != filters.end ();
      filter_it++)
    {
      add_filter (ec, *filter_it);
    }

    // add sender entries for addr_serv connections
    std::set<CQML::SenderConnection> sender_connections = esc.dstSenderConnection ();
    for (std::set<CQML::SenderConnection>::iterator sc_it =
      sender_connections.begin ();
      sc_it != sender_connections.end ();
    sc_it++)
    {
      add_sender_info (ec, sc_it->dstSenderConnection_end (), serv_count_++);
    }

    // add receiver entries for addr_serv connections
    std::set<CQML::ReceiverConnection> receiver_connections = esc.srcReceiverConnection ();
    for (std::set<CQML::ReceiverConnection>::iterator rc_it =
      receiver_connections.begin ();
      rc_it != receiver_connections.end ();
    rc_it++)
    {
      add_receiver_info (ec, rc_it->srcReceiverConnection_end (), serv_count_++);
    }

    node->appendChild (ec);
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::add_filter (
    xercesc::DOMElement* node,
    const CQML::Filter filter)
  {
    // create dom element
    xercesc::DOMElement* filter_elem =
      node->getOwnerDocument ()->createElement (XStr("filter"));
    if (!((std::string)filter.filter_id ()).empty ())
    {
      filter_elem->setAttribute (XStr("id"),
        XStr ((std::string)filter.filter_id ()));
    }

    // add name element
    xercesc::DOMElement* name_elem =
      node->getOwnerDocument ()->createElement (XStr ("name"));
    xercesc::DOMText* name_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)filter.name ()));
    name_elem->appendChild (name_text);
    filter_elem->appendChild (name_elem);

    // add type element
    xercesc::DOMElement* type_elem =
      node->getOwnerDocument ()->createElement (XStr ("type"));
    xercesc::DOMText* type_text =
      node->getOwnerDocument ()->createTextNode (XStr ((std::string)filter.filter_type ()));
    type_elem->appendChild (type_text);
    filter_elem->appendChild (type_elem);

    std::string source_name;
    std::set<CQML::EventSourcePort> esports =
      filter.EventSourcePort_kind_children ();
    // if there is a EventSourcePort element in the filter model
    for (std::set<CQML::EventSourcePort>::iterator esp_it = esports.begin ();
      esp_it != esports.end ();
      esp_it++)
    {
      CQML::OutEventPort out_port = esp_it->ref ();
      // and if the reference is actually given
      if (!out_port)
      {
        source_name = "undefined reference";
      }
      else
      {
        // reproduce id which was used in the deploymentplan to
        // identify the Component of the referenced port
        Udm::Object idelem(out_port.GetParent ());
        source_name.clear ();
        while (idelem != Udm::null)
        {
          if (source_name.empty ())
          {
            source_name = UdmUtil::ExtractName(idelem);
          }
          else
          {
            source_name = UdmUtil::ExtractName(idelem) + "." + source_name;
          }
          idelem = idelem.GetParent ();
        }
        source_name += "_";
        source_name += out_port.name ();
      }

      // add source element
      xercesc::DOMElement* source_elem =
        node->getOwnerDocument ()->createElement (XStr ("source"));
      xercesc::DOMText* source_text =
        node->getOwnerDocument ()->createTextNode (XStr (source_name));
      source_elem->appendChild (source_text);
      filter_elem->appendChild (source_elem);
    }

    // try to use EventSource
    std::set<EventSource> esource =
      filter.EventSource_kind_children ();

    for (std::set<EventSource>::iterator esrc_it = esource.begin ();
      esrc_it != esource.end ();
      esrc_it++)
    {
      source_name = esrc_it->name ();
      // add source element
      xercesc::DOMElement* source_elem =
        node->getOwnerDocument ()->createElement (XStr ("source"));
      xercesc::DOMText* source_text =
        node->getOwnerDocument ()->createTextNode (XStr (source_name));
      source_elem->appendChild (source_text);
      filter_elem->appendChild (source_elem);
    }

    node->appendChild (filter_elem);
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::add_sender_info (
    xercesc::DOMElement* node,
    const CQML::EventChannelCommunicationPoint& comm_point,
    unsigned long count)
  {
    // create an addr_serv element
    xercesc::DOMElement* addr_serv_elem =
      node->getOwnerDocument ()->createElement (XStr("addr_serv"));

    // construct name and make it unique by adding a number
    std::stringstream name;
    name << comm_point.name () << "_" << count;

    // add name element
    xercesc::DOMElement* name_elem =
      node->getOwnerDocument ()->createElement (XStr ("name"));
    xercesc::DOMText* name_text =
      node->getOwnerDocument ()->createTextNode (XStr (name.str ()));
    name_elem->appendChild (name_text);
    addr_serv_elem->appendChild (name_elem);

    // transform port number into string
    std::stringstream port;
    port << comm_point.port ();

    // add port element
    xercesc::DOMElement* port_elem =
      node->getOwnerDocument ()->createElement (XStr ("port"));
    xercesc::DOMText* port_text =
      node->getOwnerDocument ()->createTextNode (XStr (port.str ()));
    port_elem->appendChild (port_text);
    addr_serv_elem->appendChild (port_elem);

    // add address element
    xercesc::DOMElement* address_elem =
      node->getOwnerDocument ()->createElement (XStr ("address"));
    xercesc::DOMText* address_text =
      node->getOwnerDocument ()->createTextNode (
      XStr ((std::string)comm_point.address ()));
    address_elem->appendChild (address_text);
    addr_serv_elem->appendChild (address_elem);

    node->appendChild (addr_serv_elem);

    // check if a udp_sender element should be added
    if (comm_point.udp ())
    {
      // create udp_sender element
      xercesc::DOMElement* udp_sender_elem =
        node->getOwnerDocument ()->createElement (XStr("udp_sender"));

      // construct name for udp sender
      std::stringstream udp_sender_name;
      udp_sender_name << "udp_sender_" << count;

      // add name element
      xercesc::DOMElement* udp_name_elem =
        node->getOwnerDocument ()->createElement (XStr ("name"));
      xercesc::DOMText* udp_name_text =
        node->getOwnerDocument ()->createTextNode (
        XStr (udp_sender_name.str ()));
      udp_name_elem->appendChild (udp_name_text);
      udp_sender_elem->appendChild (udp_name_elem);

      // add name referencing the addr_serv element
      xercesc::DOMElement* asid_elem =
        node->getOwnerDocument ()->createElement (XStr ("addr_serv_id"));
      xercesc::DOMText* asid_text =
        node->getOwnerDocument ()->createTextNode (
        XStr (name.str ()));
      asid_elem->appendChild (asid_text);
      udp_sender_elem->appendChild (asid_elem);

      // add udp_sender element
      node->appendChild (udp_sender_elem);
    }
  }

  //-----------------------------------------------------------------------------

  void CIAOEventsVisitor::add_receiver_info (
    xercesc::DOMElement* node,
    const CQML::EventChannelCommunicationPoint& comm_point,
    unsigned long count)
  {
    // create an addr_serv element
    xercesc::DOMElement* addr_serv_elem =
      node->getOwnerDocument ()->createElement (XStr("addr_serv"));

    // construct name and make it unique by adding a number
    std::stringstream name;
    name << comm_point.name () << "_" << count;

    // add name element
    xercesc::DOMElement* name_elem =
      node->getOwnerDocument ()->createElement (XStr ("name"));
    xercesc::DOMText* name_text =
      node->getOwnerDocument ()->createTextNode (XStr (name.str ()));
    name_elem->appendChild (name_text);
    addr_serv_elem->appendChild (name_elem);

    // transform port number into string
    std::stringstream port;
    port << comm_point.port ();

    // add port element
    xercesc::DOMElement* port_elem =
      node->getOwnerDocument ()->createElement (XStr ("port"));
    xercesc::DOMText* port_text =
      node->getOwnerDocument ()->createTextNode (XStr (port.str ()));
    port_elem->appendChild (port_text);
    addr_serv_elem->appendChild (port_elem);

    // add address element
    xercesc::DOMElement* address_elem =
      node->getOwnerDocument ()->createElement (XStr ("address"));
    xercesc::DOMText* address_text =
      node->getOwnerDocument ()->createTextNode (
      XStr ((std::string)comm_point.address ()));
    address_elem->appendChild (address_text);
    addr_serv_elem->appendChild (address_elem);

    node->appendChild (addr_serv_elem);

    // check if a udp_receiver element should be added
    if (comm_point.udp ())
    {
      // create udp_receiver element
      xercesc::DOMElement* udp_receiver_elem =
        node->getOwnerDocument ()->createElement (XStr("udp_receiver"));

      // construct name for udp sender
      std::stringstream udp_receiver_name;
      udp_receiver_name << "udp_receiver_" << count;

      // add name element
      xercesc::DOMElement* udp_name_elem =
        node->getOwnerDocument ()->createElement (XStr ("name"));
      xercesc::DOMText* udp_name_text =
        node->getOwnerDocument ()->createTextNode (
        XStr (udp_receiver_name.str ()));
      udp_name_elem->appendChild (udp_name_text);
      udp_receiver_elem->appendChild (udp_name_elem);

      // add name referencing the addr_serv element
      xercesc::DOMElement* asid_elem =
        node->getOwnerDocument ()->createElement (XStr ("addr_serv_id"));
      xercesc::DOMText* asid_text =
        node->getOwnerDocument ()->createTextNode (
        XStr (name.str ()));
      asid_elem->appendChild (asid_text);
      udp_receiver_elem->appendChild (asid_elem);

      // add multicast selection entry
      std::string is_multicast;
      if (comm_point.is_multicast ())
      {
        is_multicast = "true";
      }
      else
      {
        is_multicast = "false";
      }

      xercesc::DOMElement* multicast_elem =
        node->getOwnerDocument ()->createElement (XStr ("is_multicast"));
      xercesc::DOMText* multicast_text =
        node->getOwnerDocument ()->createTextNode (XStr (is_multicast));
      multicast_elem->appendChild (multicast_text);
      udp_receiver_elem->appendChild (multicast_elem);

      // add listen_port element that listens to the same port than the addr_serv
      xercesc::DOMElement* udp_port_elem =
        node->getOwnerDocument ()->createElement (XStr ("listen_port"));
      xercesc::DOMText* udp_port_text =
        node->getOwnerDocument ()->createTextNode (XStr (port.str ()));
      udp_port_elem->appendChild (udp_port_text);
      udp_receiver_elem->appendChild (udp_port_elem);

      // add udp_receiver element
      node->appendChild (udp_receiver_elem);
    }
  }

  //-----------------------------------------------------------------------------

} // end namespace CQML
