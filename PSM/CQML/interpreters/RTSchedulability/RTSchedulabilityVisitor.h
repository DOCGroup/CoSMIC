// -*- C++ -*-
// $Id:$

#ifndef RTSCHEDULABILITY_VISITOR_H
#define RTSCHEDULABILITY_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include <fstream>
#include "CQML/CQML.h"
#include "CQML/Acceptor.h"

#include "RTSchedulability_Export.h"

// Helper includes
#include "RTSchedulabilityDumper.h"

//#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "common.h"

namespace CQML
{
  class RTSchedulability_Export RTSchedulabilityVisitor: public Visitor
  {
  public:
    RTSchedulabilityVisitor (const std::string& outputPath);

    // Lord Of the Rings..
    virtual void Visit_RootFolder(const RootFolder&);

    virtual void Visit_InterfaceDefinitions(const InterfaceDefinitions&);
    virtual void Visit_File(const File&);
    virtual void Visit_Package(const Package&);
    virtual void Visit_Object(const Object&);

    virtual void Visit_ComponentImplementations(const ComponentImplementations& comp_impls);
    virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer& comp_impl_cont);
    virtual void Visit_ComponentAssembly(const ComponentAssembly& comp_assm);

  private:
    RTSchedulabilityDumper rtsched_dumper_;
    std::string outputPath_;
  };
}


#endif /* RTSCHEDULABILITY_VISITOR_H */

