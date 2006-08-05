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
          FTInjector (ComponentAdder *, ConnectionAdder *, NodeAssigner *, FTRequirementsVisitor *);
          virtual ~FTInjector();
		      virtual std::map<std::string, CQML::Component> add_monolith_instances ();
          virtual std::map<std::string, CQML::Component> add_assembly_instances ();
          virtual Injector::ConnectionMap add_connections (const Injector::ConnectionMap &, std::string &);
          virtual std::map <std::string, std::string> assign_node_mappings (const std::map <std::string, std::string> &);

          const ComponentAdder * get_component_adder(void) const;
          const ConnectionAdder * get_connection_adder (void) const;
          const NodeAssigner * get_node_assigner (void) const;

        private:
          std::auto_ptr <ComponentAdder> comp_addr_;
          std::auto_ptr <ConnectionAdder> conn_addr_;
          std::auto_ptr <NodeAssigner> node_assgn_;
          std::auto_ptr <FTRequirementsVisitor> ft_req_visitor_;
      };

  }  // namespace CQML

#endif // FTINJECTOR_H
