// -*- C++ -*-
// $Id:$
#ifndef SECURITYQOS_req_H
#define SECURITYQOS_req_H

#include <memory>
#include <map>
#include <fstream>
#include "CQML/CQML.h"
#include "common.h"

namespace CQML
  {
  
  class Rule
    {
    public:
      CQML::RuleBase rule_base_;
      CQML::Role role_;
      Udm::Object action_;
      Udm::Object target_;

      bool operator<(const CQML::Rule& rule_) const
        {
          return this->rule_base_.uniqueId() < rule_.rule_base_.uniqueId();
        }
    };

  typedef std::pair<CQML::OperationBase, CQML::RequiredRights> Operation2RightsPair;
  typedef std::set<Operation2RightsPair> Operation2RightsSet;
  typedef std::map<CQML::Object, Operation2RightsSet> Interface2Operations2RightsMap;

  typedef std::map<CQML::Role, CQML::GrantedRights> Role2RightsMap;

  typedef std::set<CQML::Rule> RuleSet;
  typedef std::map<CQML::Policy, RuleSet> PoliciesMap;
  
  class SecurityQoSInfo
    {
    public:
      CQML::SecurityQoS secqos_; 
      RuleSet rule_set_;
    
      bool operator<(const CQML::SecurityQoSInfo& secqosinfo) const
        {
          return this->secqos_.uniqueId() < secqosinfo.secqos_.uniqueId();
        }
    };

  typedef std::set<Udm::Object> SecurityQoSTargetSet;
  typedef std::map<CQML::SecurityQoSInfo, SecurityQoSTargetSet> SecurityQoSMap;
  
  class SecurityQoSRequirements
    {
    public:
      Interface2Operations2RightsMap iface2op2rts_map_;
      Role2RightsMap role2rights_map_;
      PoliciesMap policies_map_;
      SecurityQoSMap sec_qos_map_;
    };
  }
#endif /* SECURITYQOS_req_H */
