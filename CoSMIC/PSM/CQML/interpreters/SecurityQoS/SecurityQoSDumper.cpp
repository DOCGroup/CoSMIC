#include "SecurityQoSDumper.h"

#include <algorithm>
#include <functional>
#include <sstream>

#include "UmlExt.h"
#include "Utils/Utils.h"
#include "common.h"

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
    SecurityQoSDumper::SecurityQoSDumper (const std::string& output_path)
      : DOMBuilder (output_path)
      { }

    void SecurityQoSDumper::dumpInterfaceRights (Interface2Operations2RightsMap& iface2op2rts_map)
      {
        std::string name = this->outputPath_ + "\\";
        name += "OperationRightsMapping.cir";
        this->initTarget (name);
        this->initDocument ("CIAO:SecurityQoSRequirements");
        this->initRootAttributes(); // this->curr_ is ROOT now.
 
        for (Interface2Operations2RightsMap::iterator itr = iface2op2rts_map.begin();
              itr != iface2op2rts_map.end();          
              itr++)
          {
            Object object = itr->first;
            Auto_DOM dom (*this, "Interface");
            dom.curr()->setAttribute (XStr("name"), XStr (std::string (object.name ())));
            dom.curr()->setAttribute (XStr("version"), XStr (std::string (object.VersionTag())));

            Operation2RightsSet op2rts_set = itr->second;

            for (Operation2RightsSet::iterator itr1=op2rts_set.begin();
                  itr1 != op2rts_set.end();          
                  itr1++)
              {
                OperationBase opn = itr1->first;
                RequiredRights rts = itr1->second;
                //std::set<RequiredRights> req_rights = object.RequiredRights_kind_children();
                Auto_DOM dom (*this, "Operation");
                dom.curr()->setAttribute (XStr("name"), XStr (std::string (opn.name ())));
                dom.curr()->setAttribute (XStr("required_rights"), XStr (this->getRightsString(rts)));
                dom.curr()->setAttribute (XStr("combinator"), XStr (std::string (rts.combinator())));
              }
          }
        this->dumpDocument();
      }


    void SecurityQoSDumper::dumpRoleRights (Role2RightsMap& role2rights_map)
      {
        std::string name = this->outputPath_ + "\\";
        name += "RoleRightsMapping.saml";
        this->initTarget (name);
        this->initDocument ("CIAO:SecurityQoSRequirements");
        this->initRootAttributes(); // this->curr_ is ROOT now.
 
        for (Role2RightsMap::iterator itr = role2rights_map.begin();
              itr != role2rights_map.end();          
              itr++)
          {
            Role role = itr->first;
            GrantedRights gr = itr->second;
            
            Auto_DOM dom (*this, "security-role-mapping");
            dom.curr()->setAttribute (XStr("role-name"), XStr (std::string (role.name ())));
            dom.curr()->setAttribute (XStr("granted-rights"), XStr (this->getRightsString(gr)));
          }
        this->dumpDocument();      
      }


    void SecurityQoSDumper::dumpPolicies (PoliciesMap& policies_map)
      {
        std::string name = this->outputPath_ + "\\";
        name += "SecurityPolicies.xacml";
        this->initTarget (name);
        this->initDocument ("CIAO:SecurityQoSRequirements");
        this->initRootAttributes(); // this->curr_ is ROOT now.
    
        for (PoliciesMap::iterator policy_itr = policies_map.begin();
              policy_itr != policies_map.end();          
              ++policy_itr)
          {
            Policy policy = policy_itr->first;
            RuleSet rules_set = policy_itr->second;

            Auto_DOM dom (*this, "security-policy");
            dom.curr()->setAttribute (XStr("policy-name"), XStr (std::string (policy.name ())));
            //policy_elm->setAttribute (XStr("policy-id"), XStr (policy.uniqueId()));
            for (RuleSet::iterator rule_itr=rules_set.begin();
                  rule_itr != rules_set.end();          
                  ++rule_itr)
              {
                generateRule (*rule_itr);
              }
          }
        this->dumpDocument();      
      }

    void SecurityQoSDumper::generateRule (Rule &rule)
      {
        RuleBase rule_base = rule.rule_base_;
        Role role = rule.role_;

        Auto_DOM dom (*this, "security-rule");
        dom.curr()->setAttribute (XStr("rule-name"), XStr (std::string (rule_base.name())));
        
        DOMElement *role_elm = this->doc_->createElement(XStr ("security-role"));
        role_elm->setAttribute (XStr("role-name"), XStr (std::string (role.name ())));
        dom.curr()->appendChild (role_elm);
        
        Udm::Object target = rule.target_;
        DOMElement *target_elm = this->doc_->createElement(XStr ("resource"));
        // Generate rule specific info
        
        if (rule_base.type() == PortRule::meta)
          {
            generatePortRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), Object::meta))
              {
                Object obj = Object::Cast (target);
                target_elm->setAttribute (XStr("Port"), XStr (std::string (obj.name ())));
              }
          }
        else if (rule_base.type() == ComponentRule::meta) 
          {
            generateComponentRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), Component::meta))
              {
                Component comp = Component::Cast (target);
                target_elm->setAttribute (XStr("Component"), XStr (std::string (comp.name ())));
                dom.curr()->setAttribute (XStr("id"), XStr (std::string (comp.UUID ())));
              }
          }
        else if (rule_base.type() == AssemblyRule::meta) 
          {
            generateAssemblyRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), ComponentAssembly::meta))
              {
                ComponentAssembly assm = ComponentAssembly::Cast (target);
                target_elm->setAttribute (XStr("Assembly"), XStr (std::string (assm.name ())));
                dom.curr()->setAttribute (XStr("id"), XStr (std::string (assm.UUID ())));
              }
          }
        dom.curr()->appendChild (target_elm);
      }

    void SecurityQoSDumper::generatePortRule (Rule& rule)
      {
        Udm::Object action = rule.action_;
        outfile << "generatePortRule\n";
        if (Udm::null != action)
          {
            // Check if the action is just a single operation
            if (Udm::IsDerivedFrom (action.type(), OperationRef ::meta))
              {
                OperationRef op_ref = OperationRef::Cast (action);
                OperationBase op_base = op_ref.ref();
                DOMElement *op_elm = this->doc_->createElement(XStr ("Operation"));
                op_elm ->setAttribute (XStr("name"), XStr (std::string (op_base.name ())));
                this->curr_->appendChild (op_elm);
              }
            // Check if the action is a set of operations
            else if (Udm::IsDerivedFrom (action.type(), OperationSet::meta))
              {
                OperationSet op_set = OperationSet::Cast (action);
                std::set<OperationRef> opref_set = op_set.OperationRef_kind_children ();
                for (std::set<OperationRef>::iterator itr=opref_set.begin();
                      itr != opref_set.end();          
                      itr++)
                  {
                    OperationRef op_ref = (*itr);
                    OperationBase op_base = op_ref.ref();
                    //std::set<RequiredRights> req_rights = object.RequiredRights_kind_children();
                    DOMElement *op_elm = this->doc_->createElement(XStr ("Operation"));
                    op_elm ->setAttribute (XStr("name"), XStr (std::string (op_base.name ())));
                    this->curr_->appendChild (op_elm);
                  }
              }
            // Check if action is based on required rights
            // Here the code does something better where it uses the rights to extract out operations that have the same rights
            else if (Udm::IsDerivedFrom (action.type(), RequiredRights::meta))
              {
                RequiredRights rr = RequiredRights::Cast (action);
                // Get the interface        
                if (Udm::null != rule.target_ && Udm::IsDerivedFrom (rule.target_.type(), Object::meta))
                  {
                    Object object = Object::Cast (rule.target_);

                    std::set<OperationBase> op_set = object.OperationBase_kind_children();
                    if (! op_set.empty())
                      {
                        for (std::set<OperationBase>::iterator itr=op_set.begin();
                          itr != op_set.end();
                          itr++)
                          {
                            OperationBase op_base = (*itr);
                            OperationClassificationConn op_class_conn = op_base.dstOperationClassificationConn();
                            RequiredRights op_rr = op_class_conn.dstOperationClassificationConn_end();

                            if (getRightsString(op_rr) == getRightsString(rr))
                              {
                                DOMElement *op_elm = this->doc_->createElement(XStr ("Operation"));
                                op_elm ->setAttribute (XStr("name"), XStr (std::string (op_base.name ())));
                                this->curr_->appendChild (op_elm);
                              }              
                          }
                      }
                  }
              }
          }
      }

    void SecurityQoSDumper::generateComponentRule (Rule& rule)
      {
              outfile << "generateComponentRule\n";
        if (Udm::null != rule.action_ && Udm::IsDerivedFrom (rule.action_.type(), Attribute::meta))
          {
            Attribute attr = Attribute::Cast (rule.action_);
            DOMElement *attr_elm = this->doc_->createElement(XStr ("Attribute"));
            attr_elm ->setAttribute (XStr("name"), XStr (std::string (attr.name ())));
            this->curr_->appendChild (attr_elm);
          }
      }

    void SecurityQoSDumper::generateAssemblyRule (Rule& rule)
      {
      outfile << "generateAssemblyRule\n";
        if (Udm::null != rule.action_ && Udm::IsDerivedFrom (rule.action_.type(), Path::meta))
          {
            Path path = Path::Cast (rule.action_);
            DOMElement *path_elm = this->doc_->createElement(XStr ("CriticalPath"));
            path_elm ->setAttribute (XStr("name"), XStr (std::string (path.name ())));
            this->curr_->appendChild (path_elm);
          }
      }

    std::string SecurityQoSDumper::getRightsString (const CQML::Rights& rights)
      {
        std::string rights_str="";
        rights_str = std::string (rights.get()?"g":"_") 
                + std::string (rights.set()?"s":"_") 
                + std::string (rights.use()?"u":"_") 
                + std::string (rights.manage()?"m":"_");
        return rights_str;
      }  

    void SecurityQoSDumper::dumpPermissions (const SecurityQoSRequirements& secqos_req)
      {
        SecurityQoSMap sec_qos_map = secqos_req.sec_qos_map_;
        Role2RightsMap role2rights_map = secqos_req.role2rights_map_;
        PoliciesMap policies_map = secqos_req.policies_map_;

        std::string name = this->outputPath_ + "\\";
        name += "SecurityPermissions.xacml";
        this->initTarget (name);
        this->initDocument ("CIAO:SecurityPermissions");
        this->initRootAttributes(); // this->curr_ is ROOT now.

        for (SecurityQoSMap::iterator qos_itr = sec_qos_map.begin();
              qos_itr != sec_qos_map.end();
              ++qos_itr)
          {
            SecurityQoSInfo seqqos = qos_itr->first;
            SecurityQoSTargetSet seqqos_tgtset = qos_itr->second;
            RuleSet rule_set = seqqos.rule_set_;
            
            outfile << "For "<<seqqos.secqos_.name()<<" "<< seqqos_tgtset.size() <<" targets \n";
            for (SecurityQoSTargetSet::iterator tgt_itr = seqqos_tgtset.begin();
                  tgt_itr != seqqos_tgtset.end();
                  ++tgt_itr)
              {
                Udm::Object target = (*tgt_itr);

                Auto_DOM dom (*this, "resource-access-control");

                // Generate rule specific info
                if (Udm::null != target)
                  {
                    if (Udm::IsDerivedFrom (target.type(), Object::meta))
                      {
                        Object obj = Object::Cast (target);
                        dom.curr()->setAttribute (XStr("Port"), XStr (std::string (obj.name ())));
                        dom.curr()->setAttribute (XStr("id"), XStr (std::string (obj.VersionTag ())));
                        outfile << "Port Target "<<obj.name()<<"\n";
                      }
                    else if (Udm::IsDerivedFrom (target.type(), Component::meta))
                      {
                        Component comp = Component::Cast (target);
                        dom.curr()->setAttribute (XStr("Component"), XStr (std::string (comp.name ())));
                        dom.curr()->setAttribute (XStr("id"), XStr (std::string (comp.UUID ())));
                        outfile << "Component Target "<<comp.name()<<"\n";
                      }
                    else if (Udm::IsDerivedFrom (target.type(), ComponentAssembly::meta))
                      {
                        ComponentAssembly assm = ComponentAssembly::Cast (target);
                        dom.curr()->setAttribute (XStr("Assembly"), XStr (std::string (assm.name ())));
                        dom.curr()->setAttribute (XStr("id"), XStr (std::string (assm.UUID ())));
                        outfile << "Assembly Target "<<assm.name()<<"\n";
                      }
                  }
                
                for (RuleSet::iterator rule_itr = rule_set.begin();
                      rule_itr != rule_set.end();
                      rule_itr++)
                  {
                    Rule rule = (*rule_itr);
                    // If the rule is for this target
                    if (rule.target_ == target)
                      {
                      outfile << "Rule "<<rule.rule_base_.name()<<"\n";
                        Auto_DOM dom1 (*this, "role-permission");  
                        dom1.curr()->setAttribute (XStr("role-name"), XStr (std::string (rule.role_.name())));

                        if (rule.rule_base_.allow())
                          {
                            dom1.curr()->setAttribute (XStr("access-decision"), XStr (std::string ("allow")));
                          }
                        else
                          {
                            dom1.curr()->setAttribute (XStr("access-decision"), XStr (std::string ("deny")));
                          }

                        // Generate rule specific info
                        if (rule.rule_base_.type() == PortRule::meta)
                          {
                            generatePortRule (rule);
                          }
                        else if (rule.rule_base_.type() == ComponentRule::meta) 
                          {
                            generateComponentRule (rule);
                           }
                        else if (rule.rule_base_.type() == AssemblyRule::meta) 
                          {
                            generateAssemblyRule (rule);
                          }
    
                      }
                  }
              }
          }
         this->dumpDocument(); 
      }

  }
