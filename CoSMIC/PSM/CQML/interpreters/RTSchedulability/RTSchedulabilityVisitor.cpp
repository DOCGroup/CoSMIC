// $Id$

#include "ace/config.h"
#include "Utils/Utils.h"

#include "RTSchedulabilityVisitor.h"

#include "game/xml/String.h"

#include <algorithm>
#include <functional>
#include <sstream>

#include "UmlExt.h"

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

    RTSchedulabilityVisitor::RTSchedulabilityVisitor (const std::string& outputPath)
      : outputPath_ (outputPath),
        rtsched_dumper_ (outputPath)
    {
    }

    void RTSchedulabilityVisitor::Visit_RootFolder(const RootFolder& rf)
      {
        // Capture the Operation classifications from the interface definitions
        accept_each_child (rf, InterfaceDefinitions, *this)

        // Capture the QoS assignments from component/assmbly implementations
        accept_each_child (rf, ComponentImplementations, *this)

     }

    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitors & Helpers methods to Capture the Operation classifications from the interface definitions//
    /////////////////////////////////////////////////////////////////////////////////////////
    void RTSchedulabilityVisitor::Visit_InterfaceDefinitions(const InterfaceDefinitions& ntrface_def)
      {
        // e.g. cuts/CUTS
        accept_each_child (ntrface_def, File, *this)
      }

     void RTSchedulabilityVisitor::Visit_File(const File& file)
      {
        // e.g. CUTS
        accept_each_child (file, Package, *this)
    }

    void RTSchedulabilityVisitor::Visit_Package(const Package& package)
      {
        // e.g. Testing_Service
        accept_each_child (package, Object, *this)
      }

    void RTSchedulabilityVisitor::Visit_Object(const CQML::Object& object)
      {

      }
    /////////////////////////////////////////////////////////////////////////////////////////
    // Visitor & Helpers to Capture QoS Assignments from the Component Implementations
    /////////////////////////////////////////////////////////////////////////////////////////

    void RTSchedulabilityVisitor::Visit_ComponentImplementations(const ComponentImplementations& comp_impls)
      {
        accept_each_child (comp_impls, ComponentImplementationContainer, *this)
      }

    void RTSchedulabilityVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer& comp_impl_cont)
      {
        accept_each_child (comp_impl_cont, ComponentAssembly, *this)
      }

    void RTSchedulabilityVisitor::Visit_ComponentAssembly(const ComponentAssembly& comp_assm)
      {

      }
  }
