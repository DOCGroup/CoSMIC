#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iterator>

#include "DeploymentPlanFramework/Injector.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"


#include "UmlExt.h"
#include "UdmUtil.h"

#include "FaultTolerance/FTInjector.h"

namespace CQML
{

  FTInjector::FTInjector (ComponentAdder *comp_add,
                          ConnectionAdder *conn_add,
                          FTRequirementsVisitor *ft_req)
    : comp_addr_ (comp_add),
      conn_addr_ (conn_add),
      ft_req_visitor_ (ft_req)
    {}

  FTInjector::~FTInjector ()
    {
		for (std::map <std::string, NodeAssigner *>::const_iterator iter
			 = this->node_assigner_map_.begin();
			iter != this->node_assigner_map_.end();
			++iter)
		{
			delete iter->second;
		}
	}

  const ComponentAdder * FTInjector::get_component_adder(void) const
    {
      return this->comp_addr_.get();
    }
  const ConnectionAdder * FTInjector::get_connection_adder (void) const
    {
      return this->conn_addr_.get();
    }
  const NodeAssigner * FTInjector::get_node_assigner (const std::string &plan_name) const
    {
		return this->node_assigner_map_.find (plan_name)->second;
    }

  void FTInjector::register_with_DPFramework ()
  {
	  class Register 
		  : public std::unary_function <std::pair <std::string, NodeAssigner *>, void >
	  {
	  public:
		  explicit Register (Injector *inj) : injector_(inj) {}
		  result_type operator() (argument_type const &arg)
		  {
			  DeploymentPlanFrameworkVisitor::instance()->add_injector(arg.first, injector_);
		  }
	  private:
		  Injector *injector_;
	  };
	  std::for_each (this->node_assigner_map_.begin (), 
		             this->node_assigner_map_.end(),
		             Register (this));
  }

  std::map<std::string, CQML::Component> FTInjector::add_monolith_instances (const std::string& plan_name)
    {
      return this->comp_addr_->get_all_monolith_components ();
    }

  std::map<std::string, CQML::Component> FTInjector::add_assembly_instances (const std::string& plan_name)
    {
      return this->comp_addr_->get_all_assembly_components ();
    }

  Injector::ConnectionMap FTInjector::add_connections (const std::string& plan_name, const Injector::ConnectionMap &conn_map)
    {
      return this->conn_addr_->get_new_connections (plan_name, conn_map);
    }

  std::map <std::string, std::string> FTInjector::assign_node_mappings (const std::string& plan_name, const std::map <std::string, std::string> &known_mapping)
    {
	  NodeAssigner * node_assgn = this->node_assigner_map_.find (plan_name)->second;
      node_assgn->compute_assignment (known_mapping);
      const std::map <std::string, Node> compname_node_map = 
        node_assgn->get_node_assignment ();
      std::map <std::string, std::string> compname_nodename_map;
      for (std::map <std::string, Node>::const_iterator itr = compname_node_map.begin();
           itr != compname_node_map.end();
           ++itr)
        {
          compname_nodename_map.insert (std::make_pair(itr->first, std::string(itr->second.name ())));
        }
      return compname_nodename_map;
    }
	
  void FTInjector::add_node_assigner (const std::string &dep_plan_name, NodeAssigner *na)
  {
	  this->node_assigner_map_.insert (std::make_pair (dep_plan_name, na));
  }
} // namespace CQML

