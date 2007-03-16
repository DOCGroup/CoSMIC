//$Id:$
#ifndef RTCONFIG_VISITOR_H
#define RTCONFIG_VISITOR_H

#include <BON.h>
#include <BONImpl.h>
#include <Extensions.h>
#include <RTConfig/CQMLVisitor.h>
#include <memory>
#include <fstream>
#include <stack>
#include <map>


// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "Utils/XercesString.h"
#include "Utils/Utils.h"

using namespace CQML;
using namespace PICML;

using std::string;
using std::ofstream;
using std::map;
using std::multimap;
using std::set;

namespace CQML
{
using xercesc::DOMImplementation;
using xercesc::DOMDocument;
using xercesc::DOMElement;
using xercesc::DOMWriter;
using xercesc::XMLFormatTarget;
using xercesc::LocalFileFormatTarget;

class RTConfigVisitor : public CQMLVisitor
{
  
  
  public:
    RTConfigVisitor (const std::string& outputPath);
    ~RTConfigVisitor();

    
    // Predefined Types
    
	virtual bool visitBoolean( const PICML::Boolean& object );
	virtual bool visitByte(const PICML::Byte& object);
	virtual bool visitString(const PICML::String& object);
	virtual bool visitRealNumber(const PICML::RealNumber& object);
    virtual bool visitShortInteger(const PICML::ShortInteger& object);
    virtual bool visitLongInteger(const PICML::LongInteger& object);	

    //RTConfig-related elements

    virtual bool visitRealTimeConfiguration( const CQML::RealTimeConfiguration& object );
    virtual bool visitEnvironmentConf (const EnvironmentConf& ec);
	virtual bool visitThreadPool( const CQML::ThreadPool& tp );            
	virtual bool visitBandedConnection( const CQML::BandedConnection& bc);        	
    virtual bool visitPriorityModelPolicy( const CQML::PriorityModelPolicy& pmp);
	virtual bool visitLanes (const CQML::Lanes& lns);	
	

	bool handle_policy_set (const CQML::RealTimeConfiguration& rtc);
	void handle_threadpool_with_lanes (std::multiset<CQML::Lanes> lanes);
	void handle_simple_threadpool (std::multiset<CQML::Lanes> lanes);
	

  private:

    DOMImplementation*      impl_;
    DOMDocument*            doc_;
    DOMElement*             root_;
    DOMElement*             curr_;
    DOMElement*             resources_;
    DOMWriter*              serializer_;
    XMLFormatTarget*        target_;
    std::string             outputPath_;
    std::stack<DOMElement*> curr_stack_;
	std::ofstream outfile_;

    void init();
    void initTarget (const std::string& fileName);
    void initDocument (const std::string& rootName);
    void initRootAttributes();
    void dumpDocument();

    void push();
    void pop();

    DOMElement* createSimpleContent (const std::string& name,
                                     const std::string& value);


    //maps to maintain the elements that were added already
    //on a per-file basis.
	std::map<std::string, bool> tp_;
	std::map<std::string, bool> tp_with_lanes_;
    std::map<std::string, bool> connections_;
};
}
#endif /* RTConfig_VISITOR_H */
