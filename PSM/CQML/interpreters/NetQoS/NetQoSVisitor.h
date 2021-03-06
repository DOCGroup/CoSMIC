// $Id: NetQoSVisitor.h 587 2005-12-14 21:39:34Z sutambe $

#ifndef NETQOS_VISITOR_H
#define NETQOS_VISITOR_H

#include <memory>
#include <stack>
#include <map>
#include "CQML/CQML.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "NetQoS_Export.h"

#include "DeploymentPlanFramework/DeploymentPlanFrameworkVisitor.h"
#include "common.h"

namespace CQML
{
  using xercesc::DOMImplementation;
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMLSSerializer;
  using xercesc::XMLFormatTarget;
  using xercesc::LocalFileFormatTarget;

  class NetQoS_Export NetQoSVisitor: public Visitor
  {
  public:
    NetQoSVisitor (const std::string& outputPath);
    ~NetQoSVisitor();

    // Lord Of the Rings..
    virtual void Visit_RootFolder(const RootFolder&);
    virtual void Visit_ComponentImplementations(const ComponentImplementations&);
    virtual void Visit_ComponentImplementationContainer(const ComponentImplementationContainer&);
    virtual void Visit_ComponentAssembly(const ComponentAssembly &);
    virtual void Visit_DeploymentPlans(const DeploymentPlans&);
    virtual void Visit_DeploymentPlan(const DeploymentPlan&);
    virtual void Visit_Property(const Property&);
    virtual void Visit_NetQoS (const NetQoS &);
    virtual void Visit_QoSConnector (const QoSConnector &);
    virtual void Visit_QoSCharRef(const QoSCharRef &);
    virtual void Visit_PortQoS (const PortQoS &);
  //virtual void Visit_QoSReq (const QoSReq &qos_req);

  private:
    template <typename T, typename Del, typename DelRet, typename DelEndRet>
    void GetComponents (const T& port,
                        DelRet (T::*srcDel)() const,
                        DelRet (T::*dstDel) () const,
                        DelEndRet (Del::*srcDelEnd)() const,
                        DelEndRet (Del::*dstDelEnd)() const,
                        map<Component, string>& output,
                        set<T>& visited);

    void GetReceptacleComponents (const RequiredRequestPort& receptacle,
                                  map<Component,string>& output);
    void GetFacetComponents (const ProvidedRequestPort& facet,
                             map<Component,string>& output);
    void GetEventSinkComponents (const InEventPort& consumer,
                                 map<Component,string>& output);
    void GetEventSourceComponents (const OutEventPort& publisher,
                                   map<Component,string>& output);
    void CreateConnections (const map<Component, string>& src,
                            const map<Component, string>& dst);
    void CreateConnection (const Component& srcComp,
                           const string& srcPortName,
                           const Component& dstComp,
                           const string& dstPortName);
    DOMElement* createSimpleContent (const std::string& name,
                                     const std::string& value);
    std::string ExtractName(Udm::Object ob);
    void dump_NetQoSAttributes (DOMElement*, const NetQoS &);

    template <typename PortType, typename ConnectionType, typename QoSConnectorRet, typename ConnSetRet>
    void visit_adjacent_qos_connector (ConnSetRet (PortType::*connection_set_getter)() const,
                                       QoSConnectorRet (ConnectionType::*connector_getter)() const,
                                       Port generic_port);
    template <class ConnQoS>
    void conn_qoschar_visit (const ConnQoS &cq);

  QoSCharacteristicBase recursive_dereference (const QoSCharacteristicBase &qos_char, int depth = 0);

  private:

      NetQoS current_netqos_;
      NetQoSRequirements qos_conn_mmap_;
      std::map <std::string, std::string> plan_nqfile_map_;
      std::set <std::string> filenames_;
/***************************************************************************/
    // The const auto_ptr idiom by Hurb Sutter.
    // The const auto_ptr is the only owner of the singleton framework pointer
    // See Tom Cargill's ownership patterns in PLoPD2.
    // that will be deleted at the end. As a side effect of making this member
    // a const member, compiler can not generate a copy-constructor for
    // the NetQoSVisitor class because std::auto_ptr uses move semantics. Therefore,
    // a protected copy-constructor is declared to supress automatic generation
    // of the copy-constructor.
    const std::auto_ptr <DeploymentPlanFrameworkVisitor> dp_framework_owner;

  protected:
    NetQoSVisitor (const NetQoSVisitor &);
/***************************************************************************/

  private:

    DOMImplementation*  impl_;
    DOMDocument*        doc_;
    DOMElement*         root_;
    DOMElement*         curr_;
    DOMLSSerializer*          serializer_;
    XMLFormatTarget*    target_;
    std::string         outputPath_;
    std::stack<DOMElement*> curr_stack_;

    void init();
    void initTarget (const std::string& fileName);
    void initDocument (const std::string& rootName);
    void initRootAttributes();
    void dumpDocument();

    void push();
    void pop();
  };
}

//#include "NetQoSRequirementsIterator.h"

#endif /* NETQOS_VISITOR_H */
