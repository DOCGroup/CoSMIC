//$Id$
#ifndef RT_CONFIGURATION_VISITOR_H
#define RT_CONFIGURATION_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include <fstream>
#include "CQML/CQML.h"
#include "CQML/Acceptor.h"

#include "RTConfiguration/RTConfiguration_Export.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "RTConfiguration/RTInjector.h"


// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "Utils/XercesString.h"
#include "Utils/Utils.h"

using std::string;
using std::ofstream;
using std::map;
using std::multimap;
using std::set;




namespace CQML
{
  class RTInjector;
  
  class RTConfiguration_Export RTConfigurationVisitor: public Visitor
  {
  public:	

    RTConfigurationVisitor (const std::string& outputPath);    
	~RTConfigurationVisitor ();
	    
    virtual void Visit_RootFolder(const RootFolder&);	
	void Visit_DeploymentPlans (const DeploymentPlans& dps);
	void Visit_DeploymentPlan (const DeploymentPlan& dp);
	void Visit_Property (const Property& prop);
	void Visit_ComponentImplementations (const ComponentImplementations &comp_impls);	
	void Visit_ComponentImplementationContainer (const ComponentImplementationContainer &impl_container);	
	void Visit_ComponentAssembly (const ComponentAssembly &assembly);
	
    
	//RTConfig-related elements
    virtual void Visit_RealTimeConfiguration( const CQML::RealTimeConfiguration& object );
    virtual void Visit_EnvironmentConf (const EnvironmentConf& ec);
	virtual void Visit_ThreadPool( const CQML::ThreadPool& tp );            
	virtual void Visit_PriorityBands( const CQML::PriorityBands & bc);        	
    virtual void Visit_PriorityModelPolicy( const CQML::PriorityModelPolicy& pmp);
	virtual void Visit_Lane (const CQML::Lane& ln);	

	// Predefined Types    
	virtual void Visit_Boolean( const CQML::Boolean& object );
	virtual void Visit_Byte(const CQML::Byte& object);
	virtual void Visit_String(const CQML::String& object);
	virtual void Visit_RealNumber(const CQML::RealNumber& object);
    virtual void Visit_ShortInteger(const CQML::ShortInteger& object);
    virtual void Visit_LongInteger(const CQML::LongInteger& object);
	

	void parse_rt_configs (const RootFolder& rf);
	bool add_policy_set (const CQML::RealTimeConfiguration& rtc);
	void add_simple_threadpool (std::set<CQML::Lane> lanes);
	void add_threadpool_with_lanes (std::set<CQML::Lane> lanes);
	void add_env_conf (const ComponentAssembly& assembly);

	void populate_deployed_resources (const CQML::RealTimeConfiguration& rtc);

	// interfaces required by RTInjector	
	std::string get_deployed_resource (const CQML::Component& comp);
	std::string get_resource_name ();
	std::set<Component> get_connected_components (const CQML::RealTimeConfiguration& rtc);
	
  private:
	typedef std::map<CQML::Component, std::string> DeployedResourceMap;
    void init();
    void initTarget (const std::string& fileName);
    void initDocument (const std::string& rootName);
	void initRootAttributes();
    void dumpDocument();

    void push();
    void pop();

    DOMElement* createSimpleContent (const std::string& name,
                                     const std::string& value);

	DOMImplementation*      impl_;
    DOMDocument*            doc_;
    DOMElement*             root_;
    DOMElement*             curr_;
    DOMElement*             resources_;
    DOMWriter*              serializer_;
    XMLFormatTarget*        target_;
    std::string             outputPath_;
	std::set<std::string>             csr_files_;
	std::string artifact_name_;
    std::stack<DOMElement*> curr_stack_;
	std::ofstream outfile_;
    //maps to maintain the elements that were added already
    //on a per-file basis.
	std::map<std::string, bool> tp_;
	std::map<std::string, bool> tp_with_lanes_;
    std::map<std::string, bool> connections_;

	// DRFramework pointer.
	const std::auto_ptr <DeploymentPlanFrameworkVisitor> dp_framework_owner_;

	// Injector instance for inserting RTConfiguration instances into deployment plan.	
	RTInjector * rt_injector_;	
	DeployedResourceMap deployed_resources_;
	 
    
  };
}


#endif /* RT_CONFIGURATION_VISITOR_H */