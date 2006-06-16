#ifndef INJECTOR_H
#define INJECTOR_H

#include <map>
#include "PICML/PICML.h"

namespace PICML
  {
    struct InstanceConnection
      {
        std::string instance_name;
        std::string port_name;
        std::string port_kind;
      };
    
    class Injector
      {
        public:
          typedef std::map <std::string, std::pair <InstanceConnection, InstanceConnection> > ConnectionMap;

          Injector () {};
          virtual ~Injector () {};
		      virtual std::map<std::string, PICML::Component> add_monolith_instances () = 0;
          virtual std::map<std::string, PICML::Component> add_assembly_instances () = 0;
          virtual ConnectionMap add_connections (const ConnectionMap &, std::string& plan_name) = 0;
          virtual std::map <std::string, std::string> assign_node_mappings (const std::map <std::string, std::string> &) = 0;
      };
  } // namespace PICML

#endif // INJECTOR_H