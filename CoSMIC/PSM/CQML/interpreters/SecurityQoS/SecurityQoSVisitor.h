// $Id: SecurityQoSVisitor.h 587 2005-12-14 21:39:34Z sutambe $

#ifndef SECURITYQOS_VISITOR_H
#define SECURITYQOS_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include <fstream>
#include "CQML/CQML.h"

// Utility includes
#include "Utils/XercesString.h"
#include "SecurityQoS/SecurityQoS_Export.h"

// Helper includes
#include "SecurityQoSDumper.h"

//#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "common.h"

namespace CQML
{
  class SecurityQoS_Export SecurityQoSVisitor: public Visitor
  {
  public:
    SecurityQoSVisitor (const std::string& outputPath);
    
    // Function object that accepts visitors
    template <class Obj>
    class Acceptor
      {
        public:
          Acceptor (Visitor &v)
            : visitor_(&v) {}
          void operator ()(const Obj &o)
            {
              const_cast<Obj &> (o).Accept (*visitor_);
            };
      private:
          Visitor *visitor_;
      };

    // Template that makes the accept code just a single template method call. :-)
    template <class Container>
    void accept_each (Container c)
      {
        std::for_each (c.begin (), c.end(), Acceptor<Container::value_type> (*this));            
      }
    
    // Helpers
    inline void populateObj2Op2RightsMap(CQML::Object object);
    inline void populatePoliciesMap(CQML::Policy policy);

    template <class PortType>
    bool isPortType (const PortQoS& port_qos, SecurityQoSTargetSet& secqostarget_set)
      {
        Port port = port_qos.srcPortQoS_end();
        if (Udm::IsDerivedFrom (port.type(), PortType::meta))
          {
            PortType portref = PortType::Cast (port);
            Provideable prov = portref.ref();
            if (Udm::IsDerivedFrom (prov.type(), Object::meta))
              {
                Object obj = Object::Cast (prov);
                secqostarget_set.insert(obj);
                return true;
              }
            else return false;
          }
        else return false;
      }

    template <class OperationType>
    void populate_operation_set (const OperationType& operation)
      {
        OperationClassificationConn op_class_conn = operation.dstOperationClassificationConn ();        
         // Check if this operation has rights assigned to it
        if (Udm::null != op_class_conn) // YES
          {
            RequiredRights r = op_class_conn.dstOperationClassificationConn_end ();
            this->opn_set_.insert(std::make_pair (operation, r));
          }
        else if (this->obj_req_rights_cache_ != Udm::null)// NO: Take interface rights if available 
          {
            this->opn_set_.insert(std::make_pair (operation, this->obj_req_rights_cache_));
          }
      }

    template <class R, class RRef>
    void populate_rules_from_qos (const std::set<RRef>& ruleref_set)
      {
          for (std::set<RRef>::const_iterator itr=ruleref_set.begin();
            itr != ruleref_set.end();
            itr++)
          {
            R rule = itr->ref();
            outfile << rule.name() <<"\n";
            // Reusing visitor that populates the rule associations into a rule set
            rule.Accept (*this);
          }
      }
    
    // Lord Of the Rings..
    virtual void Visit_RootFolder(const RootFolder&);

    virtual void Visit_InterfaceDefinitions(const InterfaceDefinitions&);
    virtual void Visit_File(const File&);
    virtual void Visit_Package(const Package&);
    virtual void Visit_Object(const Object&);
    virtual void Visit_TwowayOperation(const TwowayOperation&);
    virtual void Visit_OnewayOperation(const OnewayOperation&);
    virtual void Visit_FactoryOperation(const FactoryOperation&);
    virtual void Visit_LookupOperation(const LookupOperation&);
    virtual void Visit_OperationClassificationConn(const OperationClassificationConn&){};
    virtual void Visit_RequiredRights(const RequiredRights&){};
    //virtual void Visit_ReadonlyAttribute(const ReadonlyAttribute&);
    //virtual void Visit_AttributeValue(const AttributeValue&);
    //virtual void Visit_AttributeDelegate(const AttributeDelegate&);

    virtual void Visit_Security(const Security&);    

    virtual void Visit_RBAC(const RBAC&);
    virtual void Visit_Realm(const Realm&){};
    virtual void Visit_Group(const Group&){};
    virtual void Visit_Role(const Role&){};
    virtual void Visit_User(const User&){};
    virtual void Visit_RoleAssignmentConn(const RoleAssignmentConn&){};
    virtual void Visit_SecurityDomain(const SecurityDomain&){};
    virtual void Visit_RightsAssignmentConn(const RightsAssignmentConn&){};
    virtual void Visit_GrantedRights(const GrantedRights&){};


    virtual void Visit_PolicySet(const PolicySet&);
    virtual void Visit_Policy(const Policy&);
    virtual void Visit_InitiatorRoleRef(const InitiatorRoleRef&){};
    virtual void Visit_AssemblyRule(const AssemblyRule&);
    virtual void Visit_OperationInvokeConn(const OperationInvokeConn&){};
    virtual void Visit_ComponentRule(const ComponentRule&);
    virtual void Visit_TargetObjectRef(const TargetObjectRef&){};
    virtual void Visit_OnInterfaceConn(const OnInterfaceConn&){};
    virtual void Visit_AttributeManipulateConn(const AttributeManipulateConn&){};
    virtual void Visit_OnAssemblyConn(const OnAssemblyConn&){};
    virtual void Visit_OnComponentConn(const OnComponentConn&){};
    virtual void Visit_AttributeRef(const AttributeRef&){};
    virtual void Visit_OperationSet(const OperationSet&){};
    virtual void Visit_PortRule(const PortRule&);
    virtual void Visit_SecuredPathConn(const SecuredPathConn&){};
    virtual void Visit_PathRef(const PathRef&){};

    virtual void Visit_ComponentImplementations(const ComponentImplementations& comp_impls);
    virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer& comp_impl_cont);
    virtual void Visit_ComponentAssembly(const ComponentAssembly& comp_assm);
    virtual void Visit_PortSecurityQoS(const PortSecurityQoS&);
    virtual void Visit_ComponentSecurityQoS(const ComponentSecurityQoS&);
    virtual void Visit_ComponentAssemblySecurityQoS(const ComponentAssemblySecurityQoS&);

    virtual void Visit_PriorityModelPolicy(const PriorityModelPolicy&){};

  private:
    RequiredRights obj_req_rights_cache_;
    SecurityQoSRequirements secqos_req_;
    SecurityQoSDumper secqos_dumper_;
    std::string outputPath_;  
    // Global set of operations that is populated per interface
    Operation2RightsSet opn_set_;
    RuleSet rule_set_;

  };
}

//#include "SecurityQoSRequirementsIterator.h"

#endif /* SECURITYQOS_VISITOR_H */
