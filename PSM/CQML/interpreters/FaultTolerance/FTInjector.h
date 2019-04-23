#ifndef FTINJECTOR_H
#define FTINJECTOR_H

#include <memory>
#include <map>
#include "CQML/CQML.h"

#include "DeploymentPlanFramework/Injector.h"
#include "FaultTolerance/common.h"
#include "FaultTolerance/FTVisitors.h"
#include "FaultTolerance/FTAdders.h"


namespace CQML
  {
    class FTInjector : public Injector
      {
        public:
          FTInjector (ComponentAdder *, ConnectionAdder *, FTRequirementsVisitor *);
          virtual ~FTInjector();
		
		  virtual std::map<std::string, CQML::Component> add_monolith_instances (const std::string& plan_name);
          virtual std::map<std::string, CQML::Component> add_assembly_instances (const std::string& plan_name);
          virtual Injector::ConnectionMap add_connections (const std::string& plan_name, const Injector::ConnectionMap &);
          virtual std::map <std::string, std::string> assign_node_mappings (const std::string& plan_name, const std::map <std::string, std::string> &);

          const ComponentAdder * get_component_adder(void) const;
          const ConnectionAdder * get_connection_adder (void) const;
          const NodeAssigner * get_node_assigner (const std::string &plan_name) const;
		  void add_node_assigner (const std::string &, NodeAssigner *);
		  void register_with_DPFramework ();

	    protected:
		  void destroy_node_assigner (NodeAssigner *na) throw ();

		private:
          std::auto_ptr <ComponentAdder> comp_addr_;
          std::auto_ptr <ConnectionAdder> conn_addr_;
          std::auto_ptr <FTRequirementsVisitor> ft_req_visitor_;
		  std::map <std::string, NodeAssigner *> node_assigner_map_;
      };

  }  // namespace CQML

#endif // FTINJECTOR_H
