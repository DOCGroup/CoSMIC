#include <algorithm>
#include <functional>
#include <sstream>
#include "SecurityQoS/SecurityQoSVisitor.h"

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
using Utils::CreateUuid;

namespace CQML
  {
    
    SecurityQoSVisitor::SecurityQoSVisitor (const std::string& outputPath)
      : outputPath_ (outputPath),
        secqos_dumper_ (outputPath)
    {
      try 
        {
          this->obj_req_rights_cache_ = RequiredRights::Cast (Udm::null);
          outfile << "SecurityQoSVisitor constructor...\n";
        }
      catch (...)
        {
          outfile << "Dynamic cast exception...\n";
        }
    }

    void SecurityQoSVisitor::Visit_RootFolder(const RootFolder& rf)
      {
        outfile << "RootFolder..."<<rf.name()<<"\n";

        // Capture the Operation classifications from the interface definitions
        std::set<InterfaceDefinitions> interface_defs_folders = rf.InterfaceDefinitions_kind_children();
        accept_each(interface_defs_folders, *this);
        outfile << "Dumping Operation Rights...\n";
        this->secqos_dumper_.dumpInterfaceRights (this->secqos_req_.iface2op2rts_map_);
        
        // Capture the user-role-rights mappings and the policy definitions from the Security model 
        std::set<Security> security = rf.Security_kind_children();
        accept_each(security, *this);
        outfile << "Dumping Role Rights...\n";
        this->secqos_dumper_.dumpRoleRights (this->secqos_req_.role2rights_map_);
        outfile << "Dumping Security Policies...\n";
        this->secqos_dumper_.dumpPolicies (this->secqos_req_.policies_map_);

        // Capture the QoS assignments from component/assmbly implementations
        std::set<ComponentImplementations> comp_impls = rf.ComponentImplementations_kind_children();
        outfile << "Checking QoS Assignments...\n";
        accept_each(comp_impls, *this);
                
        // Dump the final Security Permissions that are derived from all the mappings, policy rules and assignments
        outfile << "Dumping Security Permissions...\n";
        this->secqos_dumper_.dumpPermissions (this->secqos_req_);

        /*  // To be used to inject access control information in the deployment plan
        for (std::set <std::string>::const_iterator iter = this->filenames_.begin();
             iter != this->filenames_.end ();
             ++iter)
          {
            std::string name = this->outputPath_ + "\\" + *iter;
            this->initTarget (name);
            this->dumpDocument ();
          }

        this->dep_plan_framework_.Visit_RootFolder (rf);
    */ 
     }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitors & Helpers methods to Capture the Operation classifications from the interface definitions//
    /////////////////////////////////////////////////////////////////////////////////////////
    void SecurityQoSVisitor::Visit_InterfaceDefinitions(const InterfaceDefinitions& ntrface_def)
	    {
        // e.g. cuts/CUTS
        std::set<File> files = ntrface_def.File_kind_children();
        accept_each(files, *this);
	    }

     void SecurityQoSVisitor::Visit_File(const File& file)
	    {
        // e.g. CUTS
        std::set<Package> packages = file.Package_kind_children();
        accept_each(packages, *this);
		}

    void SecurityQoSVisitor::Visit_Package(const Package& package)
	    {
        // e.g. Testing_Service
        std::set<CQML::Object> objects = package.Object_kind_children();
        accept_each(objects, *this);
      }

    void SecurityQoSVisitor::Visit_Object(const CQML::Object& object)
	    {
        InterfaceClassificationConn iface_class = object.dstInterfaceClassificationConn ();
       
        if (Udm::null != iface_class)
          {
            // Cache it.
            RequiredRights r = iface_class.dstInterfaceClassificationConn_end();
            // If the interface has rights, cache them
            this->obj_req_rights_cache_ = r;
          }
        else 
          {
            this->obj_req_rights_cache_ = RequiredRights::Cast (Udm::null);
          }

        std::set<OnewayOperation> onewyops = object.OnewayOperation_kind_children();
        accept_each(onewyops, *this);
  
        std::set<TwowayOperation> twowyops = object.TwowayOperation_kind_children();
        accept_each(twowyops, *this);
        
        // The operation set is ready so load it in the map
        this->populateObj2Op2RightsMap(object);
	    }

    void SecurityQoSVisitor::Visit_TwowayOperation(const TwowayOperation& twowyop)
      {
        this->populate_operation_set <TwowayOperation> (twowyop);
      }
    
    void SecurityQoSVisitor::Visit_OnewayOperation(const OnewayOperation& onewyop)
      {
        this->populate_operation_set <OnewayOperation> (onewyop);
      }
    
    void SecurityQoSVisitor::Visit_FactoryOperation(const FactoryOperation& factoryop)
      {
        this->populate_operation_set <FactoryOperation> (factoryop);
      }
    
    void SecurityQoSVisitor::Visit_LookupOperation(const LookupOperation& lookupop)
      {
        this->populate_operation_set <LookupOperation> (lookupop);
      }


    void SecurityQoSVisitor::populateObj2Op2RightsMap(CQML::Object object)
      {
        // cleanup
        // Insert this interface and the populated operation set
        if (! this->opn_set_.empty())
          {
            this->secqos_req_.iface2op2rts_map_.insert (std::make_pair(object, this->opn_set_));
            this->opn_set_.clear();
          }
        // Done processing this interface so Reset the cached rights
        this->obj_req_rights_cache_ = RequiredRights::Cast (Udm::null);
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture the Security model
    /////////////////////////////////////////////////////////////////////////////////////////
 
    void SecurityQoSVisitor::Visit_Security(const Security& security)
      {
        std::set<PolicySet> policysets = security.PolicySet_kind_children();
        accept_each(policysets, *this);
        std::set<RBAC> rbac_models = security.RBAC_kind_children();
        accept_each(rbac_models, *this);
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture the user-role-rights mappings from the Security model
    /////////////////////////////////////////////////////////////////////////////////////////
     
    void SecurityQoSVisitor::Visit_RBAC(const RBAC& rbac)
      {
		    // e.g. cuts/CUTS
        std::set<Role> roles = rbac.Role_kind_children();
        for (std::set<Role>::iterator iter = roles.begin();
	        iter != roles.end();
	        ++iter)
          {
	          Role role = *iter;
            RightsAssignmentConn rt_assg_conn = role.dstRightsAssignmentConn();
            if (Udm::null != rt_assg_conn)
              {
                GrantedRights gr = rt_assg_conn.dstRightsAssignmentConn_end ();
                this->secqos_req_.role2rights_map_.insert(std::make_pair(role, gr)); 
              }
          }
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture the policy definitions from the Security model
    /////////////////////////////////////////////////////////////////////////////////////////
    void SecurityQoSVisitor::Visit_PolicySet(const PolicySet& policyset)
      {
        std::set<Policy> policies = policyset.Policy_kind_children();
        accept_each(policies, *this);
      }
    

    void SecurityQoSVisitor::Visit_Policy(const Policy& policy)
      {
        std::set<PortRule> port_rules = policy.PortRule_kind_children();
        accept_each(port_rules, *this);

        std::set<ComponentRule> comp_rules = policy.ComponentRule_kind_children();
        accept_each(comp_rules, *this);

        std::set<AssemblyRule> assm_rules = policy.AssemblyRule_kind_children();
        accept_each(assm_rules, *this);

        this->populatePoliciesMap(policy);
      }

    void SecurityQoSVisitor::Visit_PortRule(const PortRule& port_rule)
      {
        Rule rule;
        rule.rule_base_ = port_rule;
        
        ObjectAccessConn obj_acc_conn = port_rule.srcObjectAccessConn();
        if (Udm::null == obj_acc_conn) return;
        InitiatorRoleRef role_ref = obj_acc_conn.srcObjectAccessConn_end();
        if (Udm::null == role_ref.ref()) return;
        Role role = role_ref.ref ();
        rule.role_ = role;
        
        OperationInvokeConn opn_invoke_conn = port_rule.dstOperationInvokeConn();
        if (Udm::null == opn_invoke_conn) return;
        ResourceActionBase res_act_base = opn_invoke_conn.dstOperationInvokeConn_end();
        rule.action_ = res_act_base;
      
        OnInterfaceConn on_iface_conn = port_rule.dstOnInterfaceConn();
        if (Udm::null == on_iface_conn) return;
        TargetObjectRef obj_ref = on_iface_conn.dstOnInterfaceConn_end();
        if (Udm::null == obj_ref.ref ()) return;
        CQML::Object obj = obj_ref.ref ();
        rule.target_ = obj;
      
        this->rule_set_.insert(rule); 
      }

    void SecurityQoSVisitor::Visit_ComponentRule(const ComponentRule& comp_rule)
      {
        Rule rule;
        rule.rule_base_ = comp_rule;
      
        ComponentAccessConn comp_acc_conn = comp_rule.srcComponentAccessConn();
        if (Udm::null == comp_acc_conn) return;
        InitiatorRoleRef role_ref = comp_acc_conn.srcComponentAccessConn_end();
        if (Udm::null == role_ref.ref()) return;
        Role role = role_ref.ref ();
        rule.role_ = role;
      
        AttributeManipulateConn attr_manip_conn = comp_rule.dstAttributeManipulateConn();
        if (Udm::null == attr_manip_conn) return;
        AttributeRef attr_ref = attr_manip_conn.dstAttributeManipulateConn_end();
        if (Udm::null == attr_ref.ref()) return;
        ReadonlyAttribute attr = attr_ref.ref ();
        rule.action_ = attr;
      
        OnComponentConn on_comp_conn = comp_rule.dstOnComponentConn();
        if (Udm::null == on_comp_conn) return;
        ComponentRef comp_ref = on_comp_conn.dstOnComponentConn_end();
        if (Udm::null == comp_ref.ref()) return;
        Component comp = comp_ref.ref ();
        rule.target_ = comp;
      
        this->rule_set_.insert(rule);
     }

    void SecurityQoSVisitor::Visit_AssemblyRule(const AssemblyRule& assm_rule)
      {
        Rule rule;
        rule.rule_base_ = assm_rule;
      
        AssemblyAccessConn assm_acc_conn = assm_rule.srcAssemblyAccessConn();
        if (Udm::null == assm_acc_conn) return;
        InitiatorRoleRef role_ref = assm_acc_conn.srcAssemblyAccessConn_end();
        if (Udm::null == role_ref.ref()) return;
        Role role = role_ref.ref ();
        rule.role_ = role;
      
        SecuredPathConn sec_path_conn = assm_rule.dstSecuredPathConn();
        PathRef path_ref = sec_path_conn.dstSecuredPathConn_end();
        if (Udm::null == path_ref.ref()) return;
        Path path = path_ref.ref ();
        rule.action_ = path;
      
        OnAssemblyConn on_assm_conn = assm_rule.dstOnAssemblyConn();
        if (Udm::null == on_assm_conn) return;
        ComponentAssemblyReference assm_ref = on_assm_conn.dstOnAssemblyConn_end();
        if (Udm::null == path_ref.ref()) return;
        ComponentAssembly assm = assm_ref.ref ();
        rule.target_ = assm;

        this->rule_set_.insert(rule);
      }


    void SecurityQoSVisitor::populatePoliciesMap(Policy policy)
      {
        // cleanup
        // Insert this interface and the populated operation set
        this->secqos_req_.policies_map_.insert (std::make_pair(policy, this->rule_set_));
        this->rule_set_.clear();
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture QoS Assignments from the Component Implementations
    /////////////////////////////////////////////////////////////////////////////////////////

		void SecurityQoSVisitor::Visit_ComponentImplementations(const ComponentImplementations& comp_impls)
      {
        outfile << "ComponentImplementation...\n";
        std::set<ComponentImplementationContainer> comp_impl_conts 
                                            = comp_impls.ComponentImplementationContainer_kind_children();

        accept_each(comp_impl_conts, *this);
      }
    
    void SecurityQoSVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& comp_impl_cont)
      {
        outfile << "ComponentImplmentationContainer...\n";
        std::set<ComponentAssemblySecurityQoS> assm_sec_qos_set 
                                       = comp_impl_cont.ComponentAssemblySecurityQoS_kind_children();
        accept_each(assm_sec_qos_set, *this);

        std::set<ComponentAssembly> comp_assmblies = comp_impl_cont.ComponentAssembly_kind_children();
        accept_each(comp_assmblies, *this);
      }

    void SecurityQoSVisitor::Visit_ComponentAssembly(const ComponentAssembly& comp_assm)
      {
        outfile << "ComponentAssembly...\n";
        std::set<PortSecurityQoS> port_sec_qos_set = comp_assm.PortSecurityQoS_kind_children();
        accept_each(port_sec_qos_set, *this);

        std::set<ComponentSecurityQoS> comp_sec_qos_set = comp_assm.ComponentSecurityQoS_kind_children();
        accept_each(comp_sec_qos_set, *this);
      }

    void SecurityQoSVisitor::Visit_PortSecurityQoS(const PortSecurityQoS& port_sec_qos)
      {
        // Reuse the ruleset that was used while visiting policies to add rules to a policy
        outfile << "PortSecurityQoS...";
        // make sure its clear
        this->rule_set_.clear();        
        std::set<PortRuleRef> portruleref_set = port_sec_qos.PortRuleRef_kind_children();        
        outfile << portruleref_set.size()<< " portrules "; 
        this->populate_rules_from_qos <PortRule, PortRuleRef> (portruleref_set);

        SecurityQoSTargetSet secqostarget_set;
        std::set<PortQoS> port_qos_conns = port_sec_qos.srcPortQoS();

        for (std::set<PortQoS>::iterator itr=port_qos_conns.begin();
            itr != port_qos_conns.end();
            ++itr)
          {
            if (this->isPortType <ProvidedRequestPort> (*itr, secqostarget_set)) {}
            else if (this->isPortType <RequiredRequestPort> (*itr, secqostarget_set)) {}
          }
        
        SecurityQoSInfo secqosinfo; 
        secqosinfo.secqos_ = port_sec_qos; 
        secqosinfo.rule_set_ = this->rule_set_;
        outfile <<this->rule_set_.size()<<" rules\n";
        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }
    
    void SecurityQoSVisitor::Visit_ComponentSecurityQoS(const ComponentSecurityQoS& comp_sec_qos)
      {
        outfile << "ComponentSecurityQoS...";
        // make sure its clear
        this->rule_set_.clear();        
        std::set<PortRuleRef> portruleref_set = comp_sec_qos.PortRuleRef_kind_children();        
        outfile << portruleref_set.size()<< " port rules "; 
        this->populate_rules_from_qos <PortRule, PortRuleRef> (portruleref_set);

        std::set<ComponentRuleRef> compruleref_set = comp_sec_qos.ComponentRuleRef_kind_children();
        outfile << compruleref_set.size()<< " component rules "; 
        this->populate_rules_from_qos <ComponentRule, ComponentRuleRef> (compruleref_set);        
         
        SecurityQoSTargetSet secqostarget_set;
        std::set<ComponentQoS> comp_qos_conns = comp_sec_qos.srcComponentQoS();
        for (std::set<ComponentQoS>::iterator itr=comp_qos_conns.begin();
            itr != comp_qos_conns.end();
            itr++)
          {
            ComponentQoS comp_qos = (*itr);
            ComponentBase compbase = comp_qos.srcComponentQoS_end();
            if (Udm::null != compbase )
              {
                if (Udm::IsDerivedFrom (compbase.type(), ComponentRef::meta))
                  {
                    ComponentRef compref = ComponentRef::Cast (compbase);
                    secqostarget_set.insert(compref.ref());
                  }
                else if (Udm::IsDerivedFrom (compbase.type(), Component::meta))
                  {
                    Component comp = Component::Cast (compbase);
                    secqostarget_set.insert(comp);
                  }
              }
          }
        SecurityQoSInfo secqosinfo; 
        secqosinfo.secqos_ = comp_sec_qos; 
        secqosinfo.rule_set_ = this->rule_set_;
        outfile <<this->rule_set_.size()<<" rules\n";
        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }
  
    void SecurityQoSVisitor::Visit_ComponentAssemblySecurityQoS(const ComponentAssemblySecurityQoS& assm_sec_qos)
      {
        outfile << "ComponentAssemblySecurityQoS...";
        // make sure its clear
        this->rule_set_.clear();
        std::set<PortRuleRef> portruleref_set = assm_sec_qos.PortRuleRef_kind_children();
        outfile << portruleref_set.size()<< " port rules "; 
        this->populate_rules_from_qos <PortRule, PortRuleRef> (portruleref_set);

        std::set<AssemblyRuleRef> assmruleref_set = assm_sec_qos.AssemblyRuleRef_kind_children();
        outfile << assmruleref_set.size()<< " assembly rules ";
        this->populate_rules_from_qos <AssemblyRule, AssemblyRuleRef> (assmruleref_set);        
          
        SecurityQoSTargetSet secqostarget_set;
        std::set<ComponentAssemblyQoS> assm_qos_conns = assm_sec_qos.srcComponentAssemblyQoS();
        for (std::set<ComponentAssemblyQoS>::iterator itr=assm_qos_conns.begin();
            itr != assm_qos_conns.end();
            ++itr)
          {
            ComponentAssemblyQoS assm_qos = (*itr);
            ComponentAssemblyBase assmbase = assm_qos.srcComponentAssemblyQoS_end();
            if (Udm::null != assmbase)
              {
                if (Udm::IsDerivedFrom (assmbase.type(), ComponentAssemblyReference::meta))
                  {
                    ComponentAssemblyReference assmref = ComponentAssemblyReference::Cast (assmbase);
                    secqostarget_set.insert(assmref.ref());
                  }
                else if (Udm::IsDerivedFrom (assmbase.type(), ComponentAssembly::meta))
                  {
                    ComponentAssembly assm = ComponentAssembly::Cast (assmbase);
                    secqostarget_set.insert(assm);
                  }
              }
          }
        SecurityQoSInfo secqosinfo; 
        secqosinfo.secqos_ = assm_sec_qos; 
        secqosinfo.rule_set_ = this->rule_set_;
        outfile <<this->rule_set_.size()<<" rules\n";
        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }

  }

