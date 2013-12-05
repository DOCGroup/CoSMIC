#ifndef NETQOS_SPLITTLER_H
#define NETQOS_SPLITTER

#include <map>
#include <string>

#include "CQML/CQML.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "NetQoSVisitor.h"
#include "common.h"

namespace CQML
  {

  class NetQoS_Splitter : public Injector
    {
      NetQoS_Splitter (NetQoSVisitor const &);
      
      virtual std::map <std::string, std::string> 
      assign_node_mappings (std::string const & plan_name, 
                            std::map <std::string, std::string> const &);
      
    private:
      NetQoSVisitor *netqos_req_;
      NetQoSRequirementsIterator iter_;
      std::map <HostPair, SharedNetQoS> HostPairQoS;
    };

  } // namespace CQML
#endif
