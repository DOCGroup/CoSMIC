#include <sstream>
#include <fstream>

#include "FaultTolerance/FaultToleranceVisitor.h"
#include "CQML/Acceptor.h"

namespace CQML
{

  FaultToleranceVisitor::FaultToleranceVisitor (const std::string& op)
    : output_path_ (op),
	  ft_injector_ (0),
	  ft_req_visitor_ (0),
	  comp_addr_ (0),
	  dp_framework_owner (DeploymentPlanFrameworkVisitor::instance ())
  {
    DeploymentPlanFrameworkVisitor::instance()->set_path (op);
  }

  FaultToleranceVisitor::~FaultToleranceVisitor ()
  {
/*    for(std::map <std::string, Injector *>::iterator itr 
          = this->plan_injector_map_.begin();
          itr != this->plan_injector_map_.end();
          ++itr)
    {
      delete itr->second;
    }*/
  }

  void FaultToleranceVisitor::Visit_RootFolder(const RootFolder& rf)
    {
	  this->parse_ft_requirements (rf);
/*
      for (std::map <std::string, Injector *>::iterator itr 
            = this->plan_injector_map_.begin();
            itr != this->plan_injector_map_.end();
            ++itr)
        {
          std::string full_filename = output_path_ + "\\" + itr->first + ".nodes.txt";
          std::ofstream outfile (full_filename.c_str());
          const FTInjector * ft_injector = dynamic_cast <FTInjector *> (itr->second);
          const NodeAssigner *node_assgn = ft_injector->get_node_assigner ();
          const std::map <std::string, Node> &random_assgn = node_assgn->get_node_assignment ();
          for (std::map <std::string, Node>::const_iterator itr = random_assgn.begin ();
              itr != random_assgn.end();
              ++itr)
            {
              outfile << itr->first << " : " << std::string(itr->second.name ()) << endl;
            }
         }
*/

	    this->ft_injector_->register_with_DPFramework ();
        DeploymentPlanFrameworkVisitor::instance()->Visit_RootFolder (rf);
    }


  void FaultToleranceVisitor::parse_ft_requirements (const RootFolder& rf)
  {
    std::auto_ptr <FTRequirementsVisitor> ft_req_visitor (new FTRequirementsVisitor ());
    ft_req_visitor->Visit_RootFolder (rf);
	this->ft_req_visitor_ = ft_req_visitor.get ();

    std::auto_ptr <ComponentAdder> comp_addr (new ComponentAdder (ft_req_visitor.get()));
    comp_addr->compute_new_components ();
	this->comp_addr_ = comp_addr.get ();

    std::auto_ptr <ConnectionAdder> conn_addr (new ConnectionAdder (comp_addr.get()));
	this->ft_injector_ = std::auto_ptr <FTInjector>  (new FTInjector (comp_addr.release(), 
			     		  							   conn_addr.release(), 
				  								       ft_req_visitor.release()));

	accept_each_child (rf, DeploymentPlans, *this);
  }
  
  void FaultToleranceVisitor::Visit_DeploymentPlans (const DeploymentPlans& dp_folder)
  {
	accept_each_child (dp_folder, DeploymentPlan, *this);
  }

  void FaultToleranceVisitor::Visit_DeploymentPlan (const DeploymentPlan& plan)
  {
	std::auto_ptr <NodeAssigner> node_assgn;
	std::string dep_plan_name = std::string (plan.name());
	std::set <DomainRiskGroupingRef> srgc_refs 
		= plan.DomainRiskGroupingRef_kind_children ();
 
	if (srgc_refs.empty())
	  {
		std::auto_ptr<NodeCollector> node_collector (new NodeCollector ());
		node_collector->Visit_DeploymentPlan (plan);
		node_assgn = std::auto_ptr <NodeAssigner> 
		  (new RandomNodeAssigner (node_collector.release (), this->comp_addr_));
	  }
	else
	  {
		std::set <DomainRiskGroupingRef>::const_iterator iter 
			= srgc_refs.begin ();
		DomainRiskGrouping srg_con = iter->ref(); // Exactly one!!
		std::auto_ptr <SRGVisitor> srg_visitor (new SRGVisitor());
		srg_visitor->Visit_DomainRiskGrouping (srg_con);
		srg_visitor->compute_metric ();
		node_assgn = std::auto_ptr <NodeAssigner> (new BranchNBoundNodeAssigner 
													(srg_visitor.release(), 
													 this->ft_req_visitor_, 
													 this->comp_addr_));
	  }
	this->ft_injector_->add_node_assigner(dep_plan_name, node_assgn.release());
	}
}

