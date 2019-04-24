#include "NetQoS_Splitter.h"

NetQoS_Splitter::NetQoS_Splitter (NetQoSVisitor::NetQoS_Requirements const &netqos_req)
: netqos_req_(&netqos_req)
  {}

std::map <std::string, std::string>
NetQoS_Splitter::assign_node_mappings (const std::string& plan_name,
                                       const std::map <std::string, std::string> &
                                       known_mappings)
  {
    for (NetQoSVisitor::NetQoS_Requirements::iterator itr =
           this->netqos_req_->lower_bound (netqos);
         itr != this->qos_conn_mmap_.upper_bound (netqos);
         ++itr)
      {
          this->curr_->appendChild (this->createSimpleContent ("connectionName", itr->second.connection_name));
      }
  }
 /*
  private:
    struct HostPair
      {
        std::string src;
        std::string dest;
      };
    struct SharedNetQoS
      {
        const CQML::NetQoS *netqos;
        std::set <NetQoSVisitor::ConnectionInfo *> conn_set;
      };
    NetQoSVisitor::NetQoS_Requirements const *netqos_req_;
    std::map <HostPair, NetQoS_Division> hostpair_qos_;
  */