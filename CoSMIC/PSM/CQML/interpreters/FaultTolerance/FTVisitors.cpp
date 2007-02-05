#include "FaultTolerance/FTVisitors.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
/*
template <>
::CQML::DeploymentPlanFrameworkVisitor::unique_id <Component &> ();
*/
// Named Loop idiom
#define LABEL(x) goto LOOP_##x; \
				 BREAK_##x: if(0)  \
                 LOOP_##x: 
#define BREAK(x) goto BREAK_##x; 

namespace CQML
{

// **************************************
//           FT Requirements Visitor
// **************************************
  FTRequirementsVisitor::FTRequirementsVisitor ()
    : current_req_replica_ (0),
	  attached_FOU_ (false),
      monolith_instance_req_map_ (),
      assembly_instance_req_map_ ()
  {
  }

  FTRequirementsVisitor::~FTRequirementsVisitor ()
  {
  }

  void FTRequirementsVisitor::Visit_RootFolder (const RootFolder &rf)
  {
      std::set<ComponentImplementations>
        comp_impls = rf.ComponentImplementations_kind_children();
	  accept_each (comp_impls, *this);
 
/*	  std::set<FTDeployment>
        ftdeploy_models = rf.FTDeployment_kind_children();
	  accept_each (ftdeploy_models, *this);
*/
  }

  void FTRequirementsVisitor::Visit_ComponentImplementations 
	  (const ComponentImplementations &comp_impls)
  {
	  std::set <ComponentImplementationContainer> comp_impl_containers = 
		  comp_impls.ComponentImplementationContainer_kind_children ();
	  accept_each (comp_impl_containers, *this);
  }

  void FTRequirementsVisitor::Visit_ComponentImplementationContainer 
	  (const ComponentImplementationContainer &impl_container)
  {
	  std::set <MonolithicImplementation> mono_impls = 
		  impl_container.MonolithicImplementation_kind_children ();
	  if (!mono_impls.empty()) // We don't want to visit a component implementation
		  return;
	  std::set <ComponentAssembly> assemblies = impl_container.ComponentAssembly_kind_children ();
	  accept_each (assemblies, *this);
  }

  void FTRequirementsVisitor::Visit_ComponentAssembly (const ComponentAssembly &assembly)
  {
/*
	class FTAnnotatedAssemblyRemover : public std::unary_function <ComponentAssembly, void>
	  {
		public:
			FTAnnotatedAssemblyRemover (Visitor &v, std::set <ComponentAssembly> &assembly_set) 
				:  visitor_ (v),
				   assembly_set_ (assembly_set){}
			result_type operator () (const argument_type & arg)
			{
				//this->assembly_set_.erase(remove (arg));
				//visitor_.assembly_visit (arg);
			}
		private:
			Visitor &visitor_;
			//std::set <ComponentAssembly> assembly_set_;
	  };

	  this->nonFT_nested_assemblies_ = assembly.ComponentAssembly_kind_children ();
*/
	  this->attached_FOU_ = false;
	  std::set <ComponentAssemblyQoS> caq_connection_set = assembly.dstComponentAssemblyQoS ();
	  accept_each (caq_connection_set, *this);
	  if (!this->attached_FOU_)
	  {
		  std::set<ComponentAssembly> nested_assemblies
			  = assembly.ComponentAssembly_kind_children ();
		  accept_each (nested_assemblies, *this);
		  std::set<Component> nested_components
			  = assembly.Component_kind_children ();
		  accept_each (nested_components,*this);
		  std::set<ComponentAssemblyReference> nested_assembly_refs
			  = assembly.ComponentAssemblyReference_kind_children ();
		  accept_each (nested_assembly_refs,*this);
		  std::set<ComponentRef> nested_component_refs
			  = assembly.ComponentRef_kind_children ();
		  accept_each (nested_component_refs,*this);
	  }
	  //accept_each (nonFT_nested_assemblies_, *this);
/*
	  std::set <QoSCharacteristicBase> qos_chars = assembly.dstComponentAssemblyQoS ();
	  bool found_FOU = false;
	  for (std::set <QoSCharacteristicBase>::const_iterator iter
				= qos_chars.begin();
			iter != qos_chars.end();
	        ++iter)
    	{
			if (Udm::IsDerivedFrom (iter->type(), FailOverUnit::meta))
			{
				//std::set <FailOverUnit> FOUs = impl_container.FailOverUnit_kind_children ();
				FailOverUnit fou = FailOverUnit::Cast (*iter);
				this->current_req_replica_ = fou.Replica ();
				this->assembly_visit (assembly);
				found_fou = true;
				break;
			}
		}
	  if (!found_FOU)
	  {
		  std::set <FailOverUnit> FOUs = impl_container.FailOverUnit_kind_children ();
		  if (FOUs.empty ())
			  return;
		  std::set <ComponentAssembly> assemblies = assembly.ComponentAssembly_kind_children ();
		  
		  for (std::set<FailOverUnit>::const_iterator iter = FOUs.begin();
			   iter != FOUs.end();
			   ++iter)
		  {
  			FTAnnotatedAssemblyRemover remover (assemblies);
			this->qos_connection_visit <ComponentAssemblyQoS, ComponentAssembly, 
										  ComponentAssemblyReference, FTAnnotatedAssemblyRemover>
										  (*iter, FailOverUnit::srcComponentAssemblyQoS, 
										   ComponentQoS::srcComponentAssemblyQoS_end,
										   remover);
		  }
		  accept_each (FOUs, *this);		  
		  accept_each (assemblies, *this);
	  }*/
  }

  void FTRequirementsVisitor::Visit_ComponentAssemblyReference 
	  (const ComponentAssemblyReference &assembly_ref)
  {
	  this->attached_FOU_ = false;
	  std::set <ComponentAssemblyQoS> caq_connection_set 
		  = assembly_ref.dstComponentAssemblyQoS ();
	  accept_each (caq_connection_set, *this);
	  /// Not sure whether I should do this recursively when assembly reference
	  /// is annotated. There is a possibility that the referred assembly will
	  /// be traversed twice.
	  if (!this->attached_FOU_)
	  {
		  ComponentAssembly assembly = assembly_ref.ref ();
		  std::set<ComponentAssembly> nested_assemblies
			  = assembly.ComponentAssembly_kind_children ();
		  accept_each (nested_assemblies, *this);
		  std::set<Component> nested_components
			  = assembly.Component_kind_children ();
		  accept_each (nested_components,*this);
		  std::set<ComponentAssemblyReference> nested_assembly_refs
			  = assembly.ComponentAssemblyReference_kind_children ();
		  accept_each (nested_assembly_refs,*this);
		  std::set<ComponentRef> nested_component_refs
			  = assembly.ComponentRef_kind_children ();
		  accept_each (nested_component_refs,*this);
	  }
  }

  void FTRequirementsVisitor::Visit_ComponentRef
	  (const ComponentRef &comp_ref)
  {
	  std::set <ComponentQoS> cq_connection_set = comp_ref.dstComponentQoS ();
	  accept_each (cq_connection_set, *this);
  }

  void FTRequirementsVisitor::Visit_Component(const Component &comp)
  {
	  std::set <ComponentQoS> cq_connection_set = comp.dstComponentQoS ();
	  accept_each (cq_connection_set, *this);
  }

  void FTRequirementsVisitor::Visit_ComponentQoS (const ComponentQoS & cq)
  {
	QoSCharacteristicBase qos_char = cq.dstComponentQoS_end ();  
	if (Udm::IsDerivedFrom (qos_char.type(), FailOverUnit::meta))
	{
		this->attached_FOU_ = true;
		FailOverUnit fou = FailOverUnit::Cast (qos_char);
		this->current_req_replica_ = fou.Replica ();
		ComponentBase comp_base = cq.srcComponentQoS_end ();
		if (Udm::IsDerivedFrom (comp_base.type(), ComponentRef::meta))
		{
			ComponentRef comp_ref = ComponentRef::Cast (comp_base);
			Component comp = comp_ref.ref ();
			this->current_req_replica_ = fou.Replica();
			this->component_visit (comp);
		}
		else if (Udm::IsDerivedFrom (comp_base.type(), Component::meta))
		{
			Component comp = Component::Cast (comp_base);
			this->current_req_replica_ = fou.Replica();
			this->component_visit (comp);
		}
	}
  }
	
  void FTRequirementsVisitor::Visit_ComponentAssemblyQoS (const ComponentAssemblyQoS & caq)
  {
	QoSCharacteristicBase qos_char = caq.dstComponentAssemblyQoS_end ();  
	if (Udm::IsDerivedFrom (qos_char.type(), FailOverUnit::meta))
	{
		this->attached_FOU_ = true;
		FailOverUnit fou = FailOverUnit::Cast (qos_char);
		this->current_req_replica_ = fou.Replica ();
		ComponentAssemblyBase assembly_base = caq.srcComponentAssemblyQoS_end ();
		if (Udm::IsDerivedFrom (assembly_base.type(), ComponentAssemblyReference::meta))
		{
			ComponentAssemblyReference assembly_ref 
				= ComponentAssemblyReference::Cast (assembly_base);
			ComponentAssembly assembly = assembly_ref.ref ();
			this->current_req_replica_ = fou.Replica();
			this->assembly_visit (assembly);
		}
		else if (Udm::IsDerivedFrom (assembly_base.type(), ComponentAssembly::meta))
		{
			ComponentAssembly assembly = ComponentAssembly::Cast (assembly_base);
			this->current_req_replica_ = fou.Replica();
			this->assembly_visit (assembly);
		}
	}
  }
/*
  void FTRequirementsVisitor::Visit_FailOverUnit(const FailOverUnit & fou)
  {
	  this->current_req_replica_ = fou.Replica ();
	  this->component_qos_connection_visit (fou);
	  this->assembly_qos_connection_visit (fou);
  }

  template <class QoSConnectionType, class T, class TRef, class UnaryFunctor>
  void FTRequirementsVisitor::qos_connection_visit 
	  (const FailOverUnit & fou,
	   void (QoSConnectionType::*srcTQoS_end)(void),
	   void (FailOverUnit::*srcTQoS)(void),
	   UnaryFunctor func)
  {
	  std::set <QoSConnectionType> qos_connections = fou.*srcTQoS ();
	  for (std::set <QoSConnectionType>::const_iterator iter 
				= qos_connections.begin();
		   iter != qos_connections.end();
		   ++iter)
	  {
		MgaObject base = iter->*srcTQoS_end ();
		if (Udm::IsDerivedFrom (base.type(), TRef::meta))
          {
            TRef ref = TRef::Cast (base);
            T t = ref.ref ();
            func (t);  
          }
		else if (Udm::IsDerivedFrom (base.type(), T::meta))
		  {
            T t = T::Cast (base);
            func (t);  
		  }
	  }
  }
  
  void FTRequirementsVisitor::component_qos_connection_visit (const FailOverUnit & fou)
  {
	  class Monolith_instance_caller : public std::unary_function <Component, void>
	  {
		public:
			Monolith_instance_caller (Visitor &v) : visitor_ (v) {}
			result_type operator () (argument_type arg)
			{
				visitor_.monolith_instance_visit (arg);
			}
		private:
			Visitor &visitor_;
	  };
	  Monolith_instance_caller caller (*this);
	  this->qos_connection_visit <ComponentQoS, Component, 
		                          ComponentRef, Monolith_instance_caller>
								  (fou, FailOverUnit::srcComponentQoS, 
								   ComponentQoS::srcComponentQoS_end,
								   caller);
  }

  void FTRequirementsVisitor::assembly_qos_connection_visit (const FailOverUnit & fou)
  {
	  class Assembly_visit_caller : public std::unary_function <ComponentAssembly, void>
	  {
		public:
			Assembly_visit_caller (Visitor &v) : visitor_ (v) {}
			result_type operator () (argument_type arg)
			{
				visitor_.assembly_visit (arg);
			}
		private:
			Visitor &visitor_;
	  };
	  Assembly_visit_caller caller (*this);
	  this->qos_connection_visit <ComponentAssemblyQoS, ComponentAssembly, 
		                          ComponentAssemblyReference, Assembly_visit_caller>
								  (fou, FailOverUnit::srcComponentAssemblyQoS, 
								   ComponentQoS::srcComponentAssemblyQoS_end,
								   caller);

	  std::set <ComponentAssemblyQoS> assembly_qos_connections = fou.srcComponentAssemblyQoS ();
	  for (std::set <ComponentAssemblyQoS>::const_iterator iter 
				= assembly_qos_connections.begin();
		   iter != assembly_qos_connections.end();
		   ++iter)
	  {
		ComponentAssemblyBase assembly_base = iter->srcComponentAssemblyQoS_end ();
		if (Udm::IsDerivedFrom (assembly_base.type(), ComponentAssemblyReference::meta))
          {
            ComponentAssemblyReference assm_ref 
				= ComponentAssemblyReference::Cast (assembly_base);
            ComponentAssembly assembly = assm_ref.ref ();
            this->assembly_visit (assembly);  
          }
		else if (Udm::IsDerivedFrom (assembly_base.type(), ComponentAssembly::meta))
          {
            ComponentAssembly assembly 
				= ComponentAssembly::Cast (assembly_base);
            this->assembly_visit (assembly);  
          }
	  }

  }
*/

  void FTRequirementsVisitor::assembly_visit (const ComponentAssembly &assembly)
    {
        std::set <ComponentAssembly> assemblies = 
          assembly.ComponentAssembly_kind_children ();
        for (std::set <ComponentAssembly>::iterator itr = assemblies.begin();
             itr != assemblies.end ();
             ++itr)
          {
            this->assembly_visit (*itr);
          }

        std::set <Component> components = assembly.Component_kind_children ();
        for (std::set <Component>::iterator itr = components.begin();
             itr != components.end ();
             ++itr)
          {
            this->component_visit (*itr);
          }

        std::set <ComponentAssemblyReference> assembly_refs = 
          assembly.ComponentAssemblyReference_kind_children ();
        for (std::set <ComponentAssemblyReference>::iterator itr = assembly_refs.begin();
             itr != assembly_refs.end ();
             ++itr)
          {
            this->assembly_visit (itr->ref ());
          }

        std::set <ComponentRef> component_refs = assembly.ComponentRef_kind_children ();
        for (std::set <ComponentRef>::iterator itr = component_refs.begin();
             itr != component_refs.end ();
             ++itr)
          {
            this->component_visit (itr->ref());
          }
    }

  void FTRequirementsVisitor::monolith_instance_visit (const Component &component)
    {
        const std::string comp_name = 
			DeploymentPlanFrameworkVisitor::instance().unique_id(component);
        
        // Put the component primary into the replica group set.
        this->monolith_instance_req_map_.insert (std::make_pair(comp_name, 
                                                 std::make_pair (this->current_req_replica_, 
                                                 component)));
    }

  void FTRequirementsVisitor::component_visit (const Component &component)
    {
        const std::string comp_name 
			= DeploymentPlanFrameworkVisitor::instance().unique_id(component);
        
        // Put the component primary into the replica group set.
        this->assembly_instance_req_map_.insert (std::make_pair(comp_name, 
                                                 std::make_pair (this->current_req_replica_, 
                                                 component)));
    }

    std::set <std::string> FTRequirementsVisitor::get_all_monolith_components (void) const
    {
      std::set <std::string> comp_set;
      for (std::map <std::string, FTReq>::const_iterator itr
           = this->monolith_instance_req_map_.begin ();
           itr != this->monolith_instance_req_map_.end();
           ++itr)
        {
          comp_set.insert (itr->first);
        }
      return comp_set;
    }

  std::set <std::string> FTRequirementsVisitor::get_all_assembly_components (void) const
    {
      std::set <std::string> comp_set;
      for (std::map <std::string, FTReq>::const_iterator itr
            = this->assembly_instance_req_map_.begin ();
            itr != this->assembly_instance_req_map_.end();
            ++itr)
        {
          comp_set.insert (itr->first);
        }
      return comp_set;
    }

  FTReq FTRequirementsVisitor::get_requirements (const std::string &comp_name) const
    {
      std::map <std::string, FTReq>::const_iterator assembly_itr = 
        this->assembly_instance_req_map_.find (comp_name);
      if (assembly_itr !=  this->assembly_instance_req_map_.end())
        {
          return assembly_itr->second;
        }

      std::map <std::string, FTReq>::const_iterator monolith_itr = 
        this->monolith_instance_req_map_.find (comp_name);
      if (monolith_itr !=  this->monolith_instance_req_map_.end())
        {
          return monolith_itr->second;
        }
      throw "ERROR: Invalid component name";
    }

  void FTRequirementsVisitor::Visit_FTDeployment(const FTDeployment & ftdeploy)
  {
  }

/*
  void FTRequirementsVisitor::Visit_FOU_Requirement (const FOU_Requirement &fou_req)
    {
      std::set <Property> property_set = fou_req.Property_kind_children ();
      for (std::set <Property>::iterator itr = property_set.begin ();
           itr != property_set.end ();
           ++itr)
        {
          const Property &property = *itr;
          if (0 == this->strcasecmp (std::string ("Replica"), std::string (property.name ())))
            {
              const std::string &value = std::string(property.DataValue());
              this->current_req_replica_ = atoi (value.c_str());
              return;
            }
        }
    }

  int FTRequirementsVisitor::strcasecmp (const std::string &s, const std::string &s2)
    {
      std::string::const_iterator p = s.begin ();
      std::string::const_iterator p2 = s2.begin ();

      while (p != s.end() && p2 != s2.end())
        { 
          if (toupper (*p) != toupper (*p2)) 
            return (toupper (*p) < toupper (*p2)) ? -1 : 1;
          ++p;
          ++p2;
        }
      return (s2.size() == s.size ()) ? 0 : (s.size() < s2.size()) ? -1 : 1;
    }

	void FTRequirementsVisitor::Visit_FTRequirements(const FTRequirements & ft_req)
  {
    std::set<FailOverUnit>
      fous = ft_req.FailOverUnit_kind_children();
    for (std::set<FailOverUnit>::iterator iter = fous.begin();
         iter != fous.end();
         ++iter)
      {
        FailOverUnit fou = *iter;
        ReqConnection fou_connect = fou.dstReqConnection ();
        FOU_Requirement fou_req = fou_connect.dstReqConnection_end ();
        
        // Find out how many replica are required and store in 
        // this->current_req_replica
        fou_req.Accept (*this);
        
        // Populate the ref2_instance_map with the component instance ids
        // for every FOU.
        fou.Accept (*this);
      }
  }
*/

	NodeCollector::NodeCollector ()
    {    }

  NodeCollector::~NodeCollector ()
    {    }

  const std::vector <Node> & NodeCollector::get_all_nodes (void) const
    {
      return this->node_vector_;
    }

  void NodeCollector::Visit_RootFolder (const RootFolder &rf)
    {
        std::set <Targets> targets = rf.Targets_kind_children ();

        if (targets.empty ())
            return;

        for (std::set <Targets>::iterator itr = targets.begin ();
            itr != targets.end();
            ++itr)
          {
            Targets t = *itr;
            t.Accept (*this);
          }
    }

  void NodeCollector::Visit_Targets(const Targets &t)
    {
      std::set <Domain> domains = t.Domain_kind_children ();
      for (std::set <Domain>::iterator itr = domains.begin ();
           itr != domains.end();
           ++itr)
        {
          Domain domain = *itr;
          domain.Accept (*this);
        }
    }

  void NodeCollector::Visit_Domain(const Domain &domain)
    {
      std::set <Node> nodes = domain.Node_kind_children ();
      //std::copy(nodes.begin (), nodes.end (), this->node_vector_.begin());
      for (std::set<Node>::iterator itr = nodes.begin();
           itr != nodes.end();
           ++itr)
        {
          this->node_vector_.push_back (*itr);
        }
    }

  void NodeCollector::Visit_DeploymentPlan (const DeploymentPlan &dep_plan)
    {
      std::set <NodeReference> nodes = dep_plan.NodeReference_kind_children ();
      for (std::set<NodeReference>::iterator itr = nodes.begin();
           itr != nodes.end();
           ++itr)
        {
          this->node_vector_.push_back (itr->ref());
        }
    }


  SRGVisitor::SRGVisitor () 
    {
    }

  SRGVisitor::~SRGVisitor()
    {
    }

  void SRGVisitor::Visit_DomainRiskGrouping (const DomainRiskGrouping &drg)
    {
	  std::set<RootRiskGroup> rrg_set = drg.RootRiskGroup_kind_children ();
	  accept_each (rrg_set, *this);
/*
	  std::set <SharedRiskGroup> srgs = srg_con.SharedRiskGroup_kind_children ();
      for (std::set <SharedRiskGroup>::iterator itr = srgs.begin();
            itr != srgs.end();
            ++itr)
        {
          this->srg_visit (*itr);
        }
*/
    }

  void SRGVisitor::Visit_RootRiskGroup (const RootRiskGroup &rrg)
  {
	  this->root_risk_group_ = rrg;
	  std::set <RootRiskAssociation> rra_set = rrg.dstRootRiskAssociation ();
	  accept_each (rra_set, *this);
  }

  void SRGVisitor::Visit_RootRiskAssociation (const RootRiskAssociation &rra)
  {
	  SRGBase srgbase = rra.dstRootRiskAssociation_end ();
	  srgbase.Accept (*this);
  }

  void SRGVisitor::Visit_SRGBase (const SRGBase &srgbase)
  {
	if (Udm::IsDerivedFrom (srgbase.type(), SharedRiskGroup::meta))
	{
		SharedRiskGroup srg = SharedRiskGroup::Cast (srgbase);
		srg.Accept (*this);
	}
	else if (Udm::IsDerivedFrom (srgbase.type(), HostReference::meta))
	{
		HostReference hr = HostReference::Cast (srgbase);
		hr.Accept (*this);
	}
  }

  void SRGVisitor::Visit_SharedRiskGroup (const SharedRiskGroup &srg)
  {
	  std::set <SRGRiskAssociation> sra_set = srg.dstSRGRiskAssociation ();
	  accept_each (sra_set, *this);
  }

  void SRGVisitor::Visit_SRGRiskAssociation (const SRGRiskAssociation &sra)
  {
	  SRGBase srgbase = sra.dstSRGRiskAssociation_end ();
	  srgbase.Accept (*this);
  }
/*
  void SRGVisitor::srg_visit (const SharedRiskGroup &srg)
    {
      std::set <SharedRiskGroup> srgs = srg.SharedRiskGroup_kind_children ();
      for (std::set <SharedRiskGroup>::iterator itr = srgs.begin();
            itr != srgs.end();
            ++itr)
        {
          this->srg_visit (*itr);
        }
      std::set <NodeGroup> node_groups = srg.NodeGroup_kind_children ();
      for (std::set <NodeGroup>::iterator itr = node_groups.begin();
            itr != node_groups.end();
            ++itr)
        {
          NodeGroup node_group = *itr;
          node_group.Accept (*this);
        }
      std::set <NodeRef> nodes = srg.NodeRef_kind_children ();
      for (std::set <NodeRef>::iterator itr = nodes.begin();
            itr != nodes.end();
            ++itr)
        {
          NodeRef node_ref = *itr;
          node_ref.Accept (*this);
        }
    }
*/
  /*
  void SRGVisitor::Visit_NodeGroup (const NodeGroup &node_group)
    {
      std::set <NodeRef> nodes = node_group.NodeRef_kind_children();
      for (std::set <NodeRef>::iterator itr = nodes.begin ();
            itr != nodes.end();
            ++itr)
        {
          NodeRef node_ref = *itr;
          node_ref.Accept (*this);
        }
    }
*/
  void SRGVisitor::Visit_HostReference (const HostReference &hr)
    {
      Node node = hr.ref();
      this->noderef_vec_.push_back (hr); 
      this->node_to_number_map_.insert 
        (std::make_pair (node.name(), this->noderef_vec_.size() - 1));
    }

  int SRGVisitor::node_count() const
    {
      return this->noderef_vec_.size();
    }

  int SRGVisitor::get_node_number (const std::string node_name) const
    {
      std::map <std::string, int>::const_iterator itr 
        = this->node_to_number_map_.find(node_name);
      return itr->second;
    }

  HostReference SRGVisitor::get_hostref (int index) const
    {
      return this->noderef_vec_.at(index);
    }

  void SRGVisitor::compute_metric ()
    {
      int size = this->node_count ();

      this->node_matrix_.resize (size);
      for (int i = 0; i < size; ++i)
          this->node_matrix_[i].resize (size);

      //std::ofstream outfile ("C:\\Documents and Settings\\sumant\\Desktop\\DOC Files\\backup\\matrix_debug.txt");

      for (int i = 0; i < size; ++i)
        {
          for (int j = i; j < size; ++j)
            {
              if (i == j)
                this->node_matrix_[i][j] = 0;
              else
                {
                  HostReference i_noderef = this->noderef_vec_[i];
                  HostReference j_noderef = this->noderef_vec_[j];
                  //Node i_node = i_noderef.ref();
                  //Node j_node = j_noderef.ref();
                  //outfile << "(" << i << ", " << j << ") ";
                  //outfile << "(" << std::string (i_node.name()) << ", " << std::string (j_node.name()) << ")" << std::endl;

                  bool found = false;
                  int i_dist = 1;
				  MgaObject i_parent = MgaObject::Cast (parent(i_noderef));
	 LABEL(OUTER) while (!found)
				  {
					int j_dist = 1;
					MgaObject j_parent = MgaObject::Cast (parent(j_noderef));
					while (!found)
					{
                      if (i_parent == j_parent)
                        {
                          this->node_matrix_[j][i] = this->node_matrix_[i][j] = 
                            i_dist + j_dist - 1;
                          //outfile << this->node_matrix_[i][j] << std::endl;
                          found = true;
						  BREAK(OUTER);
                        }
					  if (j_parent != this->root_risk_group_)
					  {
						  j_parent = parent (j_parent);
						  j_dist++;
					  }
					  else
						  BREAK(OUTER);
					}
				    if (i_parent != this->root_risk_group_)
				    {
					    i_parent = parent (i_parent);
					    i_dist++;
				    }
					else
						break;
				  }
                  /*for (MgaObject i_parent = MgaObject::Cast (parent(i_noderef));
                       (this->root_risk_group_ != i_parent) && !found;
                       (i_parent = MgaObject::Cast (parent(i_parent)), ++i_dist))
                    {
                      int j_dist = 1;
                      for (MgaObject j_parent = MgaObject::Cast (parent(j_noderef));
                           (this->top_SRGcontainer_ != j_parent) && !found;
                           (j_parent = MgaObject::Cast (parent(j_parent)), ++j_dist))
                        {
                          if (i_parent == j_parent)
                            {
                              this->node_matrix_[j][i] = this->node_matrix_[i][j] = 
                                i_dist + j_dist - 1;
                              //outfile << this->node_matrix_[i][j] << std::endl;
                              found = true;
                            }
                        }
                    }*/
                  //if (!found) throw "Incomaptible SRG hierarchy.";
                }
            }
        }
    }


  MgaObject SRGVisitor::parent (const MgaObject &o)
  {
	if (Udm::IsDerivedFrom (o.type(), SRGBase::meta))
	{
		SRGBase srgbase = SRGBase::Cast (o);
		SRGRiskAssociation sra = srgbase.srcSRGRiskAssociation ();
		if (sra != Udm::null)
		{
			SharedRiskGroup srg = sra.srcSRGRiskAssociation_end ();
			return MgaObject::Cast (srg);
		}
		else
		{
			RootRiskAssociation rra = srgbase.srcRootRiskAssociation ();
			RootRiskGroup rrg = rra.srcRootRiskAssociation_end();
			return MgaObject::Cast (rrg);
		}
	}
	else
		return MgaObject::Cast (Udm::null);
  }
  SRGVisitor::Distance SRGVisitor::get_metric_value (int node1, int node2) const
    {
      return this->node_matrix_[node1][node2];
    }


}
