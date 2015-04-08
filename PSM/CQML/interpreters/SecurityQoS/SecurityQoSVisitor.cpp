#include "Utils/Utils.h"

#include "SecurityQoS/SecurityQoSVisitor.h"

#include "UmlExt.h"
#include <algorithm>
#include <functional>
#include <sstream>

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

    SecurityQoSVisitor::SecurityQoSVisitor (const std::string& outputPath)
      : outputPath_ (outputPath),
        secqos_dumper_ (outputPath)
    {
      try
        {
          this->obj_req_rights_cache_ = RequiredRights::Cast (Udm::null);
        }
      catch (...)
        {
        }
    }

    void SecurityQoSVisitor::Visit_RootFolder(const RootFolder& rf)
      {
        // Capture the Operation classifications from the interface definitions
        accept_each_child (rf, InterfaceDefinitions, *this)
        this->secqos_dumper_.dumpInterfaceRights (this->secqos_req_.iface2op2rts_map_);

        // Capture the user-role-rights mappings and the policy definitions from the Security model
        accept_each_child (rf, Security, *this)
        this->secqos_dumper_.dumpRoleRights (this->secqos_req_.role2rights_map_);
        this->secqos_dumper_.dumpPolicies (this->secqos_req_.policies_map_);

        // Capture the QoS assignments from component/assmbly implementations
        accept_each_child (rf, ComponentImplementations, *this)

        // Dump the final Security Permissions that are derived from all the mappings, policy rules and assignments
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
        accept_each_child (ntrface_def, File, *this)
      }

     void SecurityQoSVisitor::Visit_File(const File& file)
      {
        accept_each_child (file, Package, *this)
    }

    void SecurityQoSVisitor::Visit_Package(const Package& package)
      {
        accept_each_child (package, Object, *this)
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
        accept_each_child (object, OnewayOperation, *this)

        accept_each_child (object, TwowayOperation, *this)

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
        accept_each_child (security, PolicySet, *this)
        accept_each_child (security, RBAC, *this)
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture the user-role-rights mappings from the Security model
    /////////////////////////////////////////////////////////////////////////////////////////

    void SecurityQoSVisitor::Visit_RBAC(const RBAC& rbac)
      {
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
        accept_each_child (policyset, Policy, *this)
      }


    void SecurityQoSVisitor::Visit_Policy(const Policy& policy)
      {
        accept_each_child (policy, PortRule, *this)
        accept_each_child (policy, ComponentRule, *this)
        accept_each_child (policy, AssemblyRule, *this)
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

        if (Udm::null == opn_invoke_conn)
          return;

        ResourceActionBase res_act_base = opn_invoke_conn.dstOperationInvokeConn_end();
        rule.action_ = res_act_base;

        OnInterfaceConn on_iface_conn = port_rule.dstOnInterfaceConn();
        if (Udm::null == on_iface_conn)
          return;

        TargetObjectRef obj_ref = on_iface_conn.dstOnInterfaceConn_end();

        if (Udm::null == obj_ref.ref ())
          return;

        CQML::Object obj = CQML::Object::Cast (obj_ref.ref ());
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
        accept_each_child (comp_impls, ComponentImplementationContainer, *this)
      }

    void SecurityQoSVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& comp_impl_cont)
      {
        accept_each_child (comp_impl_cont, ComponentAssemblySecurityQoS, *this)
        accept_each_child (comp_impl_cont, ComponentAssembly, *this)
      }

    void SecurityQoSVisitor::Visit_ComponentAssembly(const ComponentAssembly& comp_assm)
      {
        accept_each_child (comp_assm, PortSecurityQoS, *this)
        accept_each_child (comp_assm, ComponentSecurityQoS, *this)

        CriticalPath cpath = comp_assm.dstCriticalPath();
        if (cpath != Udm::null)
          cpath.Accept (*this);
      }

    void SecurityQoSVisitor::Visit_PortSecurityQoS(const PortSecurityQoS& port_sec_qos)
      {
        // Reuse the ruleset that was used while visiting policies to add rules to a policy
        // make sure its clear
        this->rule_set_.clear();
        std::set<PortRuleRef> portruleref_set = port_sec_qos.PortRuleRef_kind_children();
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

        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }

    void SecurityQoSVisitor::Visit_ComponentSecurityQoS(const ComponentSecurityQoS& comp_sec_qos)
      {
        // make sure its clear
        this->rule_set_.clear();
        std::set<PortRuleRef> portruleref_set = comp_sec_qos.PortRuleRef_kind_children();
        this->populate_rules_from_qos <PortRule, PortRuleRef> (portruleref_set);

        std::set<ComponentRuleRef> compruleref_set = comp_sec_qos.ComponentRuleRef_kind_children();
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

        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }

    void SecurityQoSVisitor::Visit_ComponentAssemblySecurityQoS(const ComponentAssemblySecurityQoS& assm_sec_qos)
      {
        // make sure its clear
        this->rule_set_.clear();
        std::set<PortRuleRef> portruleref_set = assm_sec_qos.PortRuleRef_kind_children();
        this->populate_rules_from_qos <PortRule, PortRuleRef> (portruleref_set);

        std::set<AssemblyRuleRef> assmruleref_set = assm_sec_qos.AssemblyRuleRef_kind_children();
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
        this->secqos_req_.sec_qos_map_.insert(std::make_pair(secqosinfo, secqostarget_set));
        // make sure its clear
        this->rule_set_.clear();
      }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture QoS Assignments from the Component Implementations
    /////////////////////////////////////////////////////////////////////////////////////////

    void SecurityQoSVisitor::Visit_CriticalPath (const CriticalPath& cpath)
    {
      PathReference pref = cpath.dstCriticalPath_end();
      pref.Accept (*this);
    }


    void SecurityQoSVisitor::Visit_PathReference (const PathReference& pref)
    {
      Path criticalpath = pref.ref();
      criticalpath.Accept (*this);
    }

    void SecurityQoSVisitor::Visit_Path (const Path& path)
    {
      // Dump the top-level pointer to the critical path
/*      this->push();
      DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
      this->curr_->appendChild (ele);
      this->curr_ = ele;
      std::string pname = "edu.vanderbilt.dre.CIAO.RACE.criticalPath";
      this->DumpStringProperty (pname,
                                path.getPath (".", false, true, "name",
                                              true));
      this->pop();

      // Dump all the properties that are associated with the Path.
      set<PathProperty> properties = path.dstPathProperty();
      for (set<PathProperty>::iterator iter = properties.begin();
           iter != properties.end();
           ++iter)
        {
          this->push();
          DOMElement* ele = this->doc_->createElement (GAME::Xml::String ("configProperty"));
          this->curr_->appendChild (ele);
          this->curr_ = ele;
          PathProperty pprop = *iter;
          Property prop = pprop.dstPathProperty_end();
          std::string pname = path.getPath (".", false, true, "name", true);
          pname += "/";
          pname += prop.name();
          this->CreatePropertyElement (pname, prop);
          this->pop();
        }

      // Find the source node of the path.  Need to fix the metamodel so that
      // we don't need to do an O(n) search to find the source node.
      set<DisplayNode> nodes = path.DisplayNode_kind_children();
      for (set<DisplayNode>::iterator iter = nodes.begin();
           iter != nodes.end();
           ++iter)
        {
          DisplayNode node = *iter;
          SrcEdge edge = node.srcSrcEdge();
          if (edge == Udm::null)
            {
              // Dump the value of the criticalPath
              this->push();
              DOMElement* ele =
                this->doc_->createElement (GAME::Xml::String ("configProperty"));
              this->curr_->appendChild (ele);
              this->curr_ = ele;
              std::string pvalue = this->CreatePath (node);
              this->DumpStringProperty (path.getPath(".", false, true, "name",
                                                     true), pvalue);
              this->pop();
              break;
            }

      }
    */
    }

    std::string SecurityQoSVisitor::CreatePath (const DisplayNode& node)
    {
      // Handle the source node
      std::string nodename = node.name();
      std::string path ("");
      size_t offset = nodename.find ('/');
      if (offset == string::npos)
        throw udm_exception (string ("Invalid node name" + nodename));
      // Append component's uuid
      path.append (nodename, 0, offset);
      path += ',';
      // Append source port name
      path.append (nodename, offset + 1, nodename.size() - offset - 1);
      SrcEdge source = node.srcSrcEdge();
      if (source != Udm::null)
        throw  udm_exception
          (string ("Invalid detection of source port" + nodename));
      path += ',';
      // Append destination port name to be the same as source port name
      path.append (nodename, offset + 1, nodename.size() - offset - 1);

      // Get the connection to the intermediate nodes
      DstEdge dst = node.dstDstEdge();
      while (dst != Udm::null)
        {
          path += ';';
          // Get the intermediate connection node
          Edge dstEdge = dst.dstDstEdge_end();
          SrcEdge dstNodeEdge = dstEdge.dstSrcEdge();
          if (dstNodeEdge == Udm::null)
            throw udm_exception (string ("Connection from"
                                         + this->ExtractName (dstEdge)
                                         + " is null!"));
          // Get the display node at the end of the connection node
          Udm::Object vertex = dstNodeEdge.dstSrcEdge_end();
          if (!Udm::IsDerivedFrom (vertex.type(), DisplayNode::meta))
            throw udm_exception (string ("Invalid object inheritance in " +
                                         this->ExtractName (vertex)));

          DisplayNode dstNode = DisplayNode::Cast (vertex);
          std::string dstNodeName = dstNode.name();
          offset = dstNodeName.find ('/');
          if (offset == string::npos)
            throw udm_exception (string ("Invalid node name"
                                         + dstNodeName));
          // Append Component's uuid
          path.append (dstNodeName, 0, offset);
          path += ',';
          // Append source port name
          path.append (dstNodeName, offset + 1,
                       dstNodeName.size() - offset - 1);
          // Get the connection to the intermediate connection node
          DstEdge nodeEdge = dstNode.dstDstEdge();
          if (nodeEdge == Udm::null)
            {
              // We have reached the end of the path.  Just append the
              // source port name as the destination port name.
              path += ',';
              // Append destination port name
              path.append (dstNodeName, offset + 1,
                           dstNodeName.size() - offset - 1);
              return path;
            }
          else
            {
              // Get the intermediate connection node
              dstEdge = nodeEdge.dstDstEdge_end();
              dstNodeEdge = dstEdge.dstSrcEdge();
              if (dstNodeEdge == Udm::null)
                throw udm_exception (string ("Connection from"
                                             + this->ExtractName (dstEdge)
                                             + " is null!"));
              // Get the display node at the end of the connection node
              vertex = dstNodeEdge.dstSrcEdge_end();
              if (!Udm::IsDerivedFrom (vertex.type(), DisplayNode::meta))
                throw udm_exception (string ("Invalid object inheritance in "
                                             + this->ExtractName (vertex)));
              DisplayNode dnode = DisplayNode::Cast (vertex);
              std::string dnodename = dnode.name();
              offset = dnodename.find ('/');
              if (offset == string::npos)
                throw udm_exception (string ("Invalid node name"
                                             + dstNodeName));
              path += ',';
              // Append destination port name
              path.append (dnodename, offset + 1,
                           dnodename.size() - offset - 1);
              // Setup the loop for the next iteration
              dst = dnode.dstDstEdge();
            }
        }
      return path;
    }

    std::string SecurityQoSVisitor::ExtractName(Udm::Object ob)
    {
      Uml::Class cls= ob.type();
      set<Uml::Attribute> attrs=cls.attributes();

      // Adding parent attributes
      set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
      attrs.insert(aattrs.begin(),aattrs.end());

      for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++)
        {
          if(std::string(ai->type())=="String")
            {
              std::string str=ai->name();
              if(str=="name")
                {
                  std::string value=ob.getStringAttr(*ai);
                  if(value.empty())value="<empty string>";
                  return value;
                }
            }
        }
      return std::string("<no name specified>");
    }

  }
