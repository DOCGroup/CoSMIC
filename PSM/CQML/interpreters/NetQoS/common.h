#ifndef __COMMON_H_
#define __COMMON_H_

#include "CQML/CQML.h"
#include <set>
#include <string>

namespace CQML
  {

  struct ConnectionInfo
    {
      std::string connection_name;
      std::string client, client_port_name;
      std::string server, server_port_name;
    };

  struct SharedNetQoS
    {
      CQML::NetQoS netqos;
      std::set <ConnectionInfo> conn_set;
    };

  struct HostPair
    {
      std::string src;
      std::string dest;
    };
  
  typedef std::multimap <NetQoS, ConnectionInfo> NetQoSRequirements;
  
  }

#endif  // __COMMON_H_
