// $Id$

#ifndef CIAO_EVENTS_VISITOR_H
#define CIAO_EVENTS_VISITOR_H

#include "CQML/CQML.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "Utils/XercesString.h"
#include "Utils/Utils.h"
#include "CIAOEvents/CIAOEvents_Export.h"

namespace CQML
{
  class CIAOEventsVisitor: public CQML::Visitor
  {
  public:
    CIAOEvents_Export CIAOEventsVisitor (const std::string& outputPath);
    CIAOEvents_Export ~CIAOEventsVisitor();
	CIAOEvents_Export void init ();

    // Root Folder Visitor
	CIAOEvents_Export virtual void Visit_RootFolder(const CQML::RootFolder&);

  private:
    /// creates a new xerces document and prints it
	/// to the path directory
    void print_es_configuration (const CQML::CIAOEvents& event_config, 
    							 const std::string& path);

	/// adds an eventServiceConfiguration element to a DOM node
	void add_event_service_configuration (
		xercesc::DOMElement* node,
		const CQML::eventServiceConfiguration esc);

	/// adds filter elements to an eventServiceConfiguration
	void add_filter (
		xercesc::DOMElement* node,
		const CQML::Filter filter);

	/// adds sender related fields like addr_serv and upd_sender
	void add_sender_info (
		xercesc::DOMElement* node,
		const CQML::EventChannelCommunicationPoint& comm_point,
		unsigned long count);

	/// adds sender related fields like addr_serv and upd_receiver
	void add_receiver_info (
		xercesc::DOMElement* node,
		const CQML::EventChannelCommunicationPoint& comm_point,
		unsigned long count);


	xercesc::DOMImplementation*  impl_;
    xercesc::DOMDocument*        doc_;
    xercesc::DOMWriter*          serializer_;
    std::string					 outputPath_;
	unsigned long				 serv_count_;
  };
}

#endif /* CIAO_EVENTS_VISITOR_H */
