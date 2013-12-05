#ifndef FTVISITORS_H
#define FTVISITORS_H

#include <set>
#include <map>
#include "CQML/CQML.h"

#include "common.h"

namespace CQML
  {
    class FTRequirementsVisitor : public Visitor
      {
        public:

          FTRequirementsVisitor ();
          virtual ~FTRequirementsVisitor();

          // Member functions used by FTRequirementVisitor interpreter
		  virtual void Visit_RootFolder (const RootFolder &);
   		  virtual void Visit_ComponentImplementations (const ComponentImplementations &);
		  virtual void Visit_ComponentImplementationContainer (const ComponentImplementationContainer &);
          virtual void Visit_FTDeployment(const FTDeployment &);
		  virtual void Visit_ComponentAssembly (const ComponentAssembly &assembly);
		  virtual void Visit_ComponentAssemblyQoS (const ComponentAssemblyQoS & caq);
		  virtual void Visit_ComponentAssemblyReference 
			  (const ComponentAssemblyReference &assembly_ref);

		  virtual void Visit_ComponentRef (const ComponentRef &comp_ref);
		  virtual void Visit_Component(const Component &comp);
		  virtual void Visit_ComponentQoS (const ComponentQoS & cq);

          std::set <std::string> get_all_monolith_components (void) const;
          std::set <std::string> get_all_assembly_components (void) const;
          FTReq get_requirements (const std::string &) const;

        private:
          int strcasecmp (const std::string &, const std::string &);
          void assembly_instance_visit (const Component &);
          void component_visit (const Component &);
          void assembly_visit (const ComponentAssembly &);
		  void failoverunit_visit (const FailOverUnit &fou, const ComponentQoS & cq);
/*		  template <class QoSConnectionType, class T, class TRef, class UnaryFunctor>
		  void qos_connection_visit (const FailOverUnit & fou,
								     void (QoSConnectionType::*QoS_end)(void),
								     void (FailOverUnit::*srcTQoS)(void),
								     UnaryFunctor func);

		  void component_qos_connection_visit (const FailOverUnit & fou);
		  void assembly_qos_connection_visit (const FailOverUnit & fou);
*/
          int current_req_replica_;
		  bool attached_FOU_;
		  std::set <ComponentAssembly> nonFT_nested_assemblies_; 
          std::map <std::string, FTReq> monolith_instance_req_map_;
          std::map <std::string, FTReq> assembly_instance_req_map_;
      };

    class SRGVisitor : public Visitor
      {
        public:
          typedef int Distance;

          SRGVisitor ();
          virtual ~SRGVisitor();
          virtual void Visit_DomainRiskGrouping (const DomainRiskGrouping &);
		  virtual void Visit_SharedRiskGroup (const SharedRiskGroup &srg);
          virtual void Visit_HostReference (const HostReference &hr);
		  virtual void Visit_RootRiskGroup (const RootRiskGroup &rrg);
		  virtual void Visit_RootRiskAssociation (const RootRiskAssociation &rra);
		  virtual void Visit_SRGRiskAssociation (const SRGRiskAssociation &sra);

		  void srgbase_visit (const SRGBase &srgbase);
		  virtual int node_count() const;
          virtual HostReference get_hostref (int) const;
          virtual void compute_metric ();
          virtual Distance get_metric_value (int node1, int node2) const;
          virtual int get_node_number (const std::string node_name) const;
        private:
          //void srg_visit (const SharedRiskGroup &);
			MgaObject parent (const MgaObject &);

        private:
          CQML::RootRiskGroup root_risk_group_;
          std::vector <HostReference> noderef_vec_;
          std::map <std::string, int> node_to_number_map_;
          std::vector <std::vector <Distance> > node_matrix_;
      };

    class NodeCollector : public Visitor
      {
        public:
          NodeCollector();
          virtual ~NodeCollector ();
          virtual void Visit_RootFolder (const RootFolder &);
          virtual void Visit_Targets(const Targets &);
          virtual void Visit_Domain(const Domain &);
          virtual void Visit_DeploymentPlan (const DeploymentPlan &);
          virtual const std::vector <Node> & get_all_nodes (void) const;
        private:
          std::vector <Node> node_vector_;
      };
  }

#endif // FTVISITORS_H

