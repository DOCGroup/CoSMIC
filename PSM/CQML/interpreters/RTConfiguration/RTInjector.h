#ifndef RTINJECTOR_H
#define RTINJECTOR_H

#include <memory>
#include <map>
#include "CQML/CQML.h"

#include "DeploymentPlanFramework/Injector.h"
#include "RTConfiguration/RTConfigurationVisitor.h"



namespace CQML
  {
	class RTConfigurationVisitor;
    class RTInjector : public Injector
      {
        public:
			RTInjector ( CQML::RTConfigurationVisitor *);
          virtual ~RTInjector();		
		  virtual std::string get_deployed_resource (const CQML::Component& comp);
		  virtual std::string get_resource_name ();
			 
		private:     
			RTConfigurationVisitor * rt_config_visitor_;		
      };

  }  // namespace CQML

#endif // RTINJECTOR_H
