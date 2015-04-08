#include "ace/config.h"

#include "Utils/Utils.h"
#include "SecurityQoSDumper.h"

#include "game/xml/String.h"

#include <algorithm>
#include <functional>
#include <sstream>

#include "UmlExt.h"
#include "common.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

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
            dom.curr()->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (object.name ())));
            dom.curr()->setAttribute (GAME::Xml::String("version"), GAME::Xml::String (std::string (object.VersionTag())));

            Operation2RightsSet op2rts_set = itr->second;

            for (Operation2RightsSet::iterator itr1=op2rts_set.begin();
                  itr1 != op2rts_set.end();
                  itr1++)
              {
                OperationBase opn = itr1->first;
                RequiredRights rts = itr1->second;
                Auto_DOM dom (*this, "Operation");
                dom.curr()->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (opn.name ())));
                dom.curr()->setAttribute (GAME::Xml::String("required_rights"), GAME::Xml::String (this->getRightsString(rts)));
                dom.curr()->setAttribute (GAME::Xml::String("combinator"), GAME::Xml::String (std::string (rts.combinator())));
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
            dom.curr()->setAttribute (GAME::Xml::String("role-name"), GAME::Xml::String (std::string (role.name ())));
            dom.curr()->setAttribute (GAME::Xml::String("granted-rights"), GAME::Xml::String (this->getRightsString(gr)));
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
            dom.curr()->setAttribute (GAME::Xml::String("policy-name"), GAME::Xml::String (std::string (policy.name ())));
			for(auto rule_itr : rules_set)
				generateRule(rule_itr);
          }
        this->dumpDocument();
      }

    void SecurityQoSDumper::generateRule (Rule &rule)
      {
        RuleBase rule_base = rule.rule_base_;
        Role role = rule.role_;

        Auto_DOM dom (*this, "security-rule");
        dom.curr()->setAttribute (GAME::Xml::String("rule-name"), GAME::Xml::String (std::string (rule_base.name())));

        DOMElement *role_elm = this->doc_->createElement(GAME::Xml::String ("security-role"));
        role_elm->setAttribute (GAME::Xml::String("role-name"), GAME::Xml::String (std::string (role.name ())));
        dom.curr()->appendChild (role_elm);

        Udm::Object target = rule.target_;
        DOMElement *target_elm = this->doc_->createElement(GAME::Xml::String ("resource"));
        // Generate rule specific info

        if (rule_base.type() == PortRule::meta)
          {
            generatePortRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), Object::meta))
              {
                Object obj = Object::Cast (target);
                target_elm->setAttribute (GAME::Xml::String("Port"), GAME::Xml::String (std::string (obj.name ())));
              }
          }
        else if (rule_base.type() == ComponentRule::meta)
          {
            generateComponentRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), Component::meta))
              {
                Component comp = Component::Cast (target);
                target_elm->setAttribute (GAME::Xml::String("Component"), GAME::Xml::String (std::string (comp.name ())));
                dom.curr()->setAttribute (GAME::Xml::String("id"), GAME::Xml::String (std::string (comp.UUID ())));
              }
          }
        else if (rule_base.type() == AssemblyRule::meta)
          {
            generateAssemblyRule (rule);
            if (Udm::null != target && Udm::IsDerivedFrom (target.type(), ComponentAssembly::meta))
              {
                ComponentAssembly assm = ComponentAssembly::Cast (target);
                target_elm->setAttribute (GAME::Xml::String("Assembly"), GAME::Xml::String (std::string (assm.name ())));
                dom.curr()->setAttribute (GAME::Xml::String("id"), GAME::Xml::String (std::string (assm.UUID ())));
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
                DOMElement *op_elm = this->doc_->createElement(GAME::Xml::String ("Operation"));
                op_elm ->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (op_base.name ())));
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
                    DOMElement *op_elm = this->doc_->createElement(GAME::Xml::String ("Operation"));
                    op_elm ->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (op_base.name ())));
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
                                DOMElement *op_elm = this->doc_->createElement(GAME::Xml::String ("Operation"));
                                op_elm ->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (op_base.name ())));
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
        if (Udm::null != rule.action_ && Udm::IsDerivedFrom (rule.action_.type(), Attribute::meta))
          {
            Attribute attr = Attribute::Cast (rule.action_);
            DOMElement *attr_elm = this->doc_->createElement(GAME::Xml::String ("Attribute"));
            attr_elm ->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (attr.name ())));
            this->curr_->appendChild (attr_elm);
          }
      }

    void SecurityQoSDumper::generateAssemblyRule (Rule& rule)
      {
        if (Udm::null != rule.action_ && Udm::IsDerivedFrom (rule.action_.type(), Path::meta))
          {
            Path path = Path::Cast (rule.action_);
            DOMElement *path_elm = this->doc_->createElement(GAME::Xml::String ("CriticalPath"));
            path_elm ->setAttribute (GAME::Xml::String("name"), GAME::Xml::String (std::string (path.name ())));
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
            SecurityQoSInfo secqosinfo = qos_itr->first;
            SecurityQoS secqos = secqosinfo.secqos_;
            SecurityQoSTargetSet seqqos_tgtset = qos_itr->second;
            RuleSet rule_set = secqosinfo.rule_set_;

            Auto_DOM rootdom (*this, "security-qos-requirements");
            rootdom.curr()->setAttribute (GAME::Xml::String("authentication"), GAME::Xml::String (std::string (secqos.Authentication()?"true":"false")));
            rootdom.curr()->setAttribute (GAME::Xml::String("audit-level"), GAME::Xml::String (std::string (secqos.AuditLevel())));
            rootdom.curr()->setAttribute (GAME::Xml::String("delegation-policy"), GAME::Xml::String (std::string (secqos.DelegationPolicy())));
            rootdom.curr()->setAttribute (GAME::Xml::String("integrity-level"), GAME::Xml::String (std::string (secqos.IntegrityLevel())));
            rootdom.curr()->setAttribute (GAME::Xml::String("confidentiality-level"), GAME::Xml::String (std::string (secqos.ConfidentialityLevel())));
            rootdom.curr()->setAttribute (GAME::Xml::String("security-level"), GAME::Xml::String (std::string (secqos.SecurityLevel())));
            rootdom.curr()->setAttribute (GAME::Xml::String("security-policy"), GAME::Xml::String (std::string (secqos.SecurityLevel())));
            rootdom.curr()->setAttribute (GAME::Xml::String("nonrepudiation"), GAME::Xml::String (std::string (secqos.NonRepudiation()?"true":"false")));

            outfile << "For "<<secqos.name()<<" "<< seqqos_tgtset.size() <<" targets \n";
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
                        dom.curr()->setAttribute (GAME::Xml::String("Port"), GAME::Xml::String (std::string (obj.name ())));
                        dom.curr()->setAttribute (GAME::Xml::String("id"), GAME::Xml::String (std::string (obj.VersionTag ())));
                        outfile << "Port Target "<<obj.name()<<"\n";
                      }
                    else if (Udm::IsDerivedFrom (target.type(), Component::meta))
                      {
                        Component comp = Component::Cast (target);
                        dom.curr()->setAttribute (GAME::Xml::String("Component"), GAME::Xml::String (std::string (comp.name ())));
                        dom.curr()->setAttribute (GAME::Xml::String("id"), GAME::Xml::String (std::string (comp.UUID ())));
                        outfile << "Component Target "<<comp.name()<<"\n";
                      }
                    else if (Udm::IsDerivedFrom (target.type(), ComponentAssembly::meta))
                      {
                        ComponentAssembly assm = ComponentAssembly::Cast (target);
                        dom.curr()->setAttribute (GAME::Xml::String("Assembly"), GAME::Xml::String (std::string (assm.name ())));
                        dom.curr()->setAttribute (GAME::Xml::String("id"), GAME::Xml::String (std::string (assm.UUID ())));
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
                        dom1.curr()->setAttribute (GAME::Xml::String("role-name"), GAME::Xml::String (std::string (rule.role_.name())));

                        if (rule.rule_base_.allow())
                          {
                            dom1.curr()->setAttribute (GAME::Xml::String("access-decision"), GAME::Xml::String (std::string ("allow")));
                          }
                        else
                          {
                            dom1.curr()->setAttribute (GAME::Xml::String("access-decision"), GAME::Xml::String (std::string ("deny")));
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
