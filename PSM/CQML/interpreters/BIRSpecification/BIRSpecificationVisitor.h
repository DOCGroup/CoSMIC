// -*- C++ -*-
#ifndef BIRSPECIFICATION_VISITOR_H
#define BIRSPECIFICATION_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include <fstream>
#include "CQML/CQML.h"
#include "CQML/Acceptor.h"
#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"

// Utility includes
#include "BIRSpecification/BIRSpecification_Export.h"


namespace CQML
{

  class BIRSpecification_Export BIRSpecificationVisitor: public Visitor
  {
  public:

    BIRSpecificationVisitor (const std::string& outputPath);
  ~BIRSpecificationVisitor ();

    virtual void Visit_RootFolder(const RootFolder&);

    virtual void Visit_ComponentImplementations (const ComponentImplementations& comp_impls);
    virtual void Visit_ComponentImplementationContainer (const ComponentImplementationContainer& comp_impl_cont);
    virtual void Visit_ComponentAssembly (const ComponentAssembly& comp_assm);
  virtual void Visit_publish (const publish& ev);
  virtual void Visit_deliverTo (const deliverTo& dv);
  virtual void Visit_RealTimeConfiguration(const RealTimeConfiguration &rtc);
  virtual void Visit_PublishConnector(const PublishConnector& pubctor);

  // Helpers.
  void GetEventSinkComponents (const InEventPort& consumer,
                  std::map<Component, std::string>& output);
  void GetEventSourceComponents (const OutEventPort& publisher,
                    std::map<Component,std::string>& output);
  std::string ExtractName (Udm::Object ob);
  template <typename T, typename Del, typename DelRet, typename DelEndRet>
  void GetComponents (const T& port,
    DelRet (T::*srcDel)() const,
    DelRet (T::*dstDel) () const,
    DelEndRet (Del::*srcDelEnd)() const,
    DelEndRet (Del::*dstDelEnd)() const,
    std::map<Component, std::string>& output,
    std::set<T>& visited);
  void CreateConnection (const Component& srcComp,
    const std::string& srcPortName,
    const Component& dstComp,
    const std::string& dstPortName,
    const std::string& source_kind,
    const std::string& dest_kind);
  void open_thread (std::string comp_name);
  void init_bir_arguments ();
  int get_lowest_priority (RealTimeConfiguration rtc);
  int get_highest_priority (RealTimeConfiguration rtc);
  bool component_traversed (std::string comp_name);



  private:
    std::string outputPath_;
    std::ofstream outfile_;
    std::string filename_;

    // Maintain associations between PublishConnector and event publishers
    std::map<std::string, OutEventPort> publishers_;
    // Maintain associations between PublishConnector and event consumers
      std::multimap<std::string, InEventPort> consumers_;
    // Maintain associations of a component with corresponding RTConfiguration
    std::map<Component, RealTimeConfiguration> rtc_;
    // Bookkeeping.
    std::list<std::string> trav_comps_;

  };
}


#endif /* BIRSPECIFICATION_VISITOR_H */

