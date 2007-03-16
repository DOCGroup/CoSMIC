//$Id:$
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <RTConfig/RTConfigVisitor.h>
#include "UmlExt.h"
#include "Utils/Utils.h"


using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

using Utils::XStr;
using xercesc::XMLString;
using Utils::CreateUuid;


//diable this annoyng warning:
//  conversion from '__int64' to 'long', possible loss of data
#pragma warning (disable: 4244) //disable warning 4244


RTConfigVisitor::RTConfigVisitor (const std::string& outputPath)
: impl_ (0),
doc_ (0),
root_ (0),
curr_ (0),
resources_ (0),
serializer_ (0),
target_ (0),
outputPath_ (outputPath)
{
	std::string filename = this->outputPath_ + "\\" + std::string ("RTConfig.trace");
	this->outfile_.open (filename.c_str (), ios::app);		
	this->init();
	this->outfile_<<"RTConfigVisitor::RTConfigVisitor ()"<<std::endl;
}

RTConfigVisitor::~RTConfigVisitor ()
{
	if (this->doc_)
		this->doc_->release();
	delete this->target_;
	this->outfile_.close ();
}

void RTConfigVisitor::init()
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

void RTConfigVisitor::initTarget (const std::string& fileName)
{
	if (this->target_)
		delete this->target_;
	this->target_ = new LocalFileFormatTarget (fileName.c_str());
}

void RTConfigVisitor::initDocument (const std::string& rootName)
{
	if (this->doc_)
		this->doc_->release();
	// Create the document
	this->doc_ =
		this->impl_->createDocument (XStr ("http://www.dre.vanderbilt.edu/ServerResources"),
		XStr (rootName.c_str()),
		0);

	//erase all elements currently present in the element maps	
	this->tp_.clear ();
	this->connections_.clear ();
	this->tp_with_lanes_.clear ();
}

void RTConfigVisitor::initRootAttributes()
{
	this->doc_->setEncoding (XStr("UTF-8"));
	this->doc_->setVersion (XStr("1.0"));
	this->root_ = this->doc_->getDocumentElement();
	this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
		XStr ("xmlns:CIAO"),
		XStr ("http://www.dre.vanderbilt.edu/ServerResources"));
	this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
		XStr ("xmlns:xsi"),
		XStr ("http://www.w3.org/2001/XMLSchema-instance"));
	this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
		XStr ("xmlns:xmi"),
		XStr ("http://www.omg.org/XMI"));
	this->root_->setAttribute (XStr ("xsi:schemaLocation"),
		XStr ("http://www.dre.vanderbilt.edu/ServerResources CIAOServerResources.xsd"));
	std::string id = "_";
	id += Utils::CreateUuid ();
	this->root_->setAttribute (XStr ("id"),
		XStr (id.c_str ()));
	this->curr_ = this->root_;
	this->resources_ = 0;
}

void RTConfigVisitor::dumpDocument()
{
	this->serializer_->writeNode (this->target_, *this->doc_);
}

void RTConfigVisitor::push()
{
	this->curr_stack_.push (this->curr_);
}

void RTConfigVisitor::pop()
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

DOMElement* RTConfigVisitor::createSimpleContent (const std::string& name,
												  const std::string& value)
{
	DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
	DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
	pName->appendChild (pValue);
	return pName;
}


// RealTimeConfiguration element visitor.
bool RTConfigVisitor::visitRealTimeConfiguration( const CQML::RealTimeConfiguration& object )
{
	this->outfile_ <<"visitRealTimeConfiguration"<<std::endl;
	// check if object is null.
	if ( !object)
	{
		this->outfile_ <<"visitRealTimeConfiguration invoked with null object"<<std::endl;
		return false;
	}

	std::string name = this->outputPath_ + "\\";
	// 
	
	name += object->getName ();
	name += ".csr";
	this->outfile_ <<"init target"<<std::endl;
	this->initTarget (name);
	this->outfile_ <<"init document"<<std::endl;
	this->initDocument ("CIAO:ServerResources");
	this->outfile_ <<"init root attributes"<<std::endl;
	this->initRootAttributes ();

	this->push();
	
	// Environment Configuration.
	std::set<CQML::EnvironmentConf> ecs = object->getEnvironmentConf();

	for (std::set<CQML::EnvironmentConf>::iterator iter = ecs.begin ();
		 iter != ecs.end ();
		 ++iter)
	{
		CQML::EnvironmentConf ec = *iter;
		ec->accept (this);
	}	
	
	//ORB configuration parameters	
	DOMElement* oc = this->doc_->createElement (XStr ("orbConfigs"));
	this->curr_->appendChild (oc);
	this->curr_ = oc;

	//add the orbResources
	this->push ();

	//Create the <orbResources> as a child of the <orbConfigs>
	DOMElement* or = this->doc_->createElement (XStr ("resources"));
	this->curr_->appendChild (or);
	this->curr_ = or;
	this->resources_ = this->curr_;

	//visit the resources
	std::set<CQML::ThreadPool> tpools = object->getThreadPool ();

	for (std::set<CQML::ThreadPool>::iterator iter = tpools.begin ();
		 iter != tpools.end ();
		 ++iter)
	{
		CQML::ThreadPool tp = *iter;
		tp->accept (this);
	}
	
	this->push ();

	//Create the <connectionBands> element
	DOMElement* e = this->doc_->createElement (XStr ("connectionBands"));
	std::string bcID ("band");//object.name ());
	e->setAttribute (XStr ("id"), XStr (bcID));
	this->curr_->appendChild (e);
	this->curr_ = e;

	std::set<CQML::BandedConnection> bandedconns = object->getBandedConnection ();

	for (std::set<CQML::BandedConnection>::iterator iter = bandedconns.begin ();
		 iter != bandedconns.end ();
		 ++iter)
	{
		CQML::BandedConnection tp = *iter;
		tp->accept (this);
	}

	//restore the current element to the ORBConfigs level
	this->pop ();

	// handle policy set elements.
	if (!this->handle_policy_set (object))
		return false;

	// Dump out an ComponentPackageDescription file
	this->dumpDocument();
	this->pop();

	return true;

}

bool RTConfigVisitor::handle_policy_set (const CQML::RealTimeConfiguration& object)
{
	this->push ();

	//Create the <threadpoolWithLanes> element
    DOMElement* e = this->doc_->createElement (XStr ("policySet"));
	std::string psID (object->getName ());
    e->setAttribute (XStr ("id"), XStr (psID));
    this->curr_->appendChild (e);
    this->curr_ = e;

    //add the priority model
	std::set<CQML::PriorityModelPolicy> pmps = object->getPriorityModelPolicy ();

	if (pmps.size () != 0)
	{

		for (std::set<CQML::PriorityModelPolicy>::iterator iter = pmps.begin ();
			iter != pmps.end ();
			++iter)
		{
			CQML::PriorityModelPolicy pm = *iter;
			pm->accept (this);
		}
	}

	std::string name;
	// add reference to first simplethreadpool
	if (this->tp_.size () != 0)
	{
		std::map<std::string, bool>::iterator siter = tp_.begin ();

		name = (*siter).first;
		this->curr_->appendChild (
			this->createSimpleContent ("threadpool", name.c_str ()));
	}

	if (this->tp_with_lanes_.size () != 0)
	{

		// add reference to first threadpoolwlanes
		std::map<std::string, bool>::iterator liter = tp_with_lanes_.begin ();

		name = (*liter).first;
		this->curr_->appendChild (
			this->createSimpleContent ("threadpool", name.c_str ()));
	}

	if (this->connections_.size () != 0)
	{

		std::map<std::string, bool>::iterator biter = connections_.begin ();

		name = (*biter).first;
		this->curr_->appendChild (
			this->createSimpleContent ("priorityBandedConnection", name.c_str ()));
	}


	//restore curr
    this->pop ();
	return true;

}

bool RTConfigVisitor::visitEnvironmentConf (const EnvironmentConf& ec)
{
	// check if object is null.
	if ( !ec)
		return false;

	//save current level
	this->push ();

	//Add the <cmdline> options
	DOMElement* cmd = this->doc_->createElement (XStr ("cmdline"));
	this->curr_->appendChild (cmd);
	this->curr_ = cmd;

	std::string cl = ec->getCmdLineOptions ();	

	//Add the <arg>
	if (!cl.empty ())
		this->curr_->appendChild (this->createSimpleContent ("arg",
		cl.c_str ()));

	//return to entry level
	this->pop ();

	//save current level again
	this->push ();

	//Add the <svcconf> options
	DOMElement* svc = this->doc_->createElement (XStr ("svcconf"));
	this->curr_->appendChild (svc);
	this->curr_ = svc;

	std::string sc = ec->getSvcConf ();
	//Add the <uri>
	if (!sc.empty ())
		this->curr_->appendChild (this->createSimpleContent ("uri",
		sc.c_str ()));

	//return to entry level
	this->pop ();

	return true;
}


void RTConfigVisitor::handle_threadpool_with_lanes (std::multiset<CQML::Lanes> lanes)
{	
	for (std::multiset<CQML::Lanes>::iterator iter = lanes.begin ();
		 iter != lanes.end (); ++iter)
	{
		CQML::Lanes lane = *iter;
		lane->accept (this);
	}
}

void RTConfigVisitor::handle_simple_threadpool (std::multiset<CQML::Lanes> lanes)
{
	//static, dynamic and lane priority elements from lane.
	std::multiset<CQML::Lanes>::iterator iter = lanes.begin ();
	CQML::Lanes lane = *iter;		

	char temp[256];

	//output static threads
	long st = lane->getstatic_threads ();
	_itoa (st, temp, 10);
	//Add the <static_threads>
	this->curr_->appendChild (this->createSimpleContent ("static_threads", temp));

	//output dynamic threads
	long dt = lane->getdynamic_threads ();
	_itoa (dt, temp, 10);
	//Add the <dynamic_threads>
	this->curr_->appendChild (this->createSimpleContent ("dynamic_threads", temp));

	//output default priority
	long prio = lane->getlane_priority ();
	_itoa (prio, temp, 10);
	//Add the <default_priority>
	this->curr_->appendChild (this->createSimpleContent ("default_priority", temp));

}


bool RTConfigVisitor::visitThreadPool( const CQML::ThreadPool& tp)
{
	if ( !tp)
		return false;

	// if only a single lane element is connected to threadpool, create a simple thread pool.
	// else create a threadpoolwithlanes.	
	std::multiset<CQML::Lanes> lanes = tp->getLanePerThreadPoolDsts ();
	if (lanes.empty ())
		return false;

	std::multiset<CQML::Lanes>::iterator iter = lanes.begin ();

	std::string pooltype = ((lanes.size () == 1)?"threadpool":"threadpoolWithLanes");
	// handle the simple threadpool first.

	//save curr
	this->push ();

	//Create the <threadpool> element
	DOMElement* e = this->doc_->createElement (XStr (pooltype.c_str ()));
	std::string tpID (tp->getName ());
	e->setAttribute (XStr ("id"), XStr (tpID));
	this->curr_->appendChild (e);
	this->curr_ = e;

	// if the threadpool has multiple lanes connected, also handle the lanes now.
	if (lanes.size () > 1)
		this->handle_threadpool_with_lanes (lanes);
	

	//temp char array to hold the output of itoa
	char temp [256];

	//output stack size
	long ss = tp->getstacksize ();
	_itoa (ss, temp, 10);
	//Add the <static_threads>
	this->curr_->appendChild (this->createSimpleContent ("stacksize", temp));

	
	if (lanes.size () == 1)
		this->handle_simple_threadpool (lanes);
	
	else
	{
		//output allow borrowing
		bool ab = tp->isallow_borrowing ();
		//Add the <allow_borrowing>
		if (ab)
			this->curr_->appendChild
				(this->createSimpleContent ("allow_borrowing", "true"));
		else
			this->curr_->appendChild
				(this->createSimpleContent ("allow_borrowing", "false"));
	}

	//output allow request buffering
	bool arb = tp->isallow_request_buffering ();
	//Add the <allow_buffering>
	if (arb)
		this->curr_->appendChild
		(this->createSimpleContent ("allow_request_buffering", "true"));
	else
		this->curr_->appendChild
		(this->createSimpleContent ("allow_request_buffering", "false"));

	//output max buffered requests
	long mbr = tp->getmax_buffered_requests ();
	_itoa (mbr, temp, 10);
	//Add the <max_buffered_requests>
	this->curr_->appendChild
		(this->createSimpleContent ("max_buffered_requests", temp));

	//output max request buffer size
	long mbrs = tp->getmax_buffer_size ();
	_itoa (mbrs, temp, 10);
	//Add the <max_request_buffered_size>
	this->curr_->appendChild
		(this->createSimpleContent ("max_request_buffered_size", temp));

	//add the threadpool to the list of elements that have been added
	if (lanes.size () == 1)
		this->tp_.insert (make_pair (tp->getName (), true));
	else
		this->tp_with_lanes_.insert (make_pair (tp->getName (), true));

	//restore curr
	this->pop ();		

	return true;
	
}

bool RTConfigVisitor::visitBandedConnection (const CQML::BandedConnection& bc)
{
	if (!bc)
		return false;

	//save curr
	this->push ();

	//Add the <band> element
	DOMElement* band = this->doc_->createElement (XStr ("band"));
	this->curr_->appendChild (band);
	this->curr_ = band;

	//temp char array to hold the output of itoa
	char temp [256];

	//output low
	long low = bc->getlow ();
	_itoa (low, temp, 10);
	//Add the <low>
	this->curr_->appendChild (this->createSimpleContent ("low", temp));

	//output high
	long high = bc->gethigh ();
	_itoa (high, temp, 10);
	//Add the <high>
	this->curr_->appendChild (this->createSimpleContent ("high", temp));

	//restore curr
	this->connections_.insert (make_pair (bc->getName (), true));

	this->pop ();

	return true;
}


bool RTConfigVisitor::visitLanes (const CQML::Lanes& lns)
{
	if ( !lns)
		return false;

	//save curr
	this->push ();

	//Add the <threadpoolLane> element
	DOMElement* lane = this->doc_->createElement (XStr ("threadpoolLane"));
	this->curr_->appendChild (lane);
	this->curr_ = lane;

	//temp char array to hold the output of itoa
	char temp [256];

	//output static threads
	long st = lns->getstatic_threads ();
	_itoa (st, temp, 10);
	//Add the <static_threads>
	this->curr_->appendChild (this->createSimpleContent ("static_threads", temp));

	//output dynamic threads
	long dt = lns->getdynamic_threads ();
	_itoa (dt, temp, 10);
	//Add the <dynamic_threads>
	this->curr_->appendChild (this->createSimpleContent ("dynamic_threads", temp));

	//output lane priority
	long prio = lns->getlane_priority ();
	_itoa (prio, temp, 10);
	//Add the <priority>
	this->curr_->appendChild (this->createSimpleContent ("priority", temp));

	//restore curr
	this->pop ();

	return true;
}

bool RTConfigVisitor::visitPriorityModelPolicy (const PriorityModelPolicy& pmp)
{
	if (!pmp)
		return true;

	//save curr
	this->push ();

	//Create the <priorityModel> element
	DOMElement* e = this->doc_->createElement (XStr ("priorityModel"));

	char temp[256];

	long pv = pmp->getpriority_value ();
	_itoa (pv, temp, 10);
	
	e->setAttribute (XStr ("server_priority"), XStr (temp));

	this->curr_->appendChild (e);
	this->curr_ = e;

	//Add the <priority_model>	
	CQML::PriorityModelPolicyImpl::priority_model_Type p_type = pmp->getpriority_model ();

	// ugly, but serves the purpose.
	std::string pt = p_type == CQML::PriorityModelPolicyImpl::CLIENT_PROPAGATED_priority_model_Type?"CLIENT_PROPAGATED":"SERVER_DECLARED";
	
	this->curr_->appendChild (
		this->createSimpleContent ("priority_model", pt.c_str ())
		);	
	
	//restore curr
	this->pop ();
	return true;
}



//========================================================================
// Predefined Types
bool RTConfigVisitor::visitBoolean(const PICML::Boolean& boolean)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_boolean"));
	this->pop();
	return true;
}

bool RTConfigVisitor::visitByte(const PICML::Byte&)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_octet"));
	this->pop();
	return true;
}

bool RTConfigVisitor::visitString(const PICML::String&)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_string"));
	this->pop();
	return true;
}

bool RTConfigVisitor::visitRealNumber(const PICML::RealNumber&)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_double"));
	this->pop();
	return true;
}

bool RTConfigVisitor::visitShortInteger(const PICML::ShortInteger&)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_short"));
	this->pop();
	return true;
}

bool RTConfigVisitor::visitLongInteger(const PICML::LongInteger&)
{
	this->push();
	DOMElement* type = this->doc_->createElement (XStr ("type"));
	this->curr_->appendChild (type);
	this->curr_ = type;
	this->curr_->appendChild (this->createSimpleContent ("kind",
		"tk_long"));
	this->pop();
	return true;
}