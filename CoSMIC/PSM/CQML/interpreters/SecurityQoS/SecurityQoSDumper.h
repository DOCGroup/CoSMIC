// -*- C++ -*-
// $Id:$
#ifndef SECURITYQOS_DUMPER_H
#define SECURITYQOS_DUMPER_H

#include <memory>
#include <stack>
#include <map>

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#include "CQML/CQML.h"

// Utility includes
#include "SecurityQoS/SecurityQoS_Export.h"

#include "SecurityQoSAdder.h"

#include "UmlExt.h"
#include "Utils/Utils.h"
#include "common.h"

namespace CQML 
  {
    using xercesc::DOMImplementation;
    using xercesc::DOMDocument;
    using xercesc::DOMElement;
    using xercesc::DOMLSSerializer;
    using xercesc::XMLFormatTarget;
    using xercesc::LocalFileFormatTarget;
    
    using CQML::SecurityQoSRequirements;

    class SecurityQoSDumper : public DOMBuilder
      {
      
      public:
        SecurityQoSDumper(const std::string& outputPath);     

        void dumpInterfaceRights (Interface2Operations2RightsMap& iface2op2rts_map);
        void dumpRoleRights (Role2RightsMap& role2rights_map);
        void dumpPolicies (PoliciesMap& policies_map);
        void dumpPermissions (const SecurityQoSRequirements& secqos_req);
        inline std::string getRightsString (const CQML::Rights& rights);

      private:

        void generateRule (Rule &rule);
        void generatePortRule (Rule& rule);
        void generateComponentRule (Rule& rule);
        void generateAssemblyRule (Rule& rule);
      };

  }
#endif /* SECURITYQOS_DUMPER_H */
