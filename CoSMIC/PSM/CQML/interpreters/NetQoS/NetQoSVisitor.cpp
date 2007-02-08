#include <algorithm>
#include <functional>
#include <sstream>
#include "NetQoS/NetQoSVisitor.h"
#include "UmlExt.h"
#include "Utils/Utils.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;

using Utils::XStr;
using Utils::CreateUuid;

namespace CQML
{
  NetQoSVisitor::NetQoSVisitor (const std::string& outputPath)
    : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), 
      target_ (0), outputPath_ (outputPath),
	  dp_framework_owner (DeploymentPlanFrameworkVisitor::instance())
  {
    DeploymentPlanFrameworkVisitor::instance()->set_path (outputPath);
    this->init();
  }

  NetQoSVisitor::~NetQoSVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
  }

  void NetQoSVisitor::init()
  {
    this->impl_ = DOMImplementationRegistry::getDOMImplementation(XStr("LS"));
    this->serializer_ = ((DOMImplementationLS*)impl_)->createDOMWriter();

    // Set features if the serializer supports the feature/mode
    if (this->serializer_->canSetFeature
        (XMLUni::fgDOMWRTDiscardDefaultContent, true))
      this->serializer_->setFeature (XMLUni::fgDOMWRTDiscardDefaultContent,
                                     true);

    if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTFormatPrettyPrint,
                                          true))
      this->serializer_->setFeature (XMLUni::fgDOMWRTFormatPrettyPrint, true);

    if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTBOM, false))
      this->serializer_->setFeature (XMLUni::fgDOMWRTBOM, false);
  }

  void NetQoSVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void NetQoSVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (XStr ("http://www.dre.vanderbilt.edu/NetQoSRequirements"),
                                   XStr (rootName.c_str()),
                                   0);
  }

  void NetQoSVisitor::initRootAttributes()
  {
    this->doc_->setEncoding (XStr("UTF-8"));
    this->doc_->setVersion (XStr("1.0"));
    this->doc_->setStandalone (false);
    this->root_ = this->doc_->getDocumentElement();
    this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                                 XStr ("xmlns:xsi"),
                                 XStr ("http://www.w3.org/2001/XMLSchema-instance"));
    this->root_->setAttribute (XStr ("xsi:schemaLocation"),
                               XStr ("http://www.dre.vanderbilt.edu/NetQoSRequirements NetQoSRequirements.xsd"));
    std::string id = std::string ("_") + Utils::CreateUuid();
    this->root_->setAttribute (XStr("id"), XStr (id));
    this->curr_ = this->root_;
  }

  void NetQoSVisitor::dumpDocument()
  {
    this->serializer_->writeNode (this->target_, *this->doc_);
  }

  void NetQoSVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void NetQoSVisitor::pop()
  {
    if (!this->curr_stack_.empty())
      {
        this->curr_ = this->curr_stack_.top();
        this->curr_stack_.pop();
      }
    else
      {
		  throw (udm_exception ("NetQoSVisitor::pop(): Internal stack error."));
      }
  }

  void NetQoSVisitor::Visit_RootFolder(const RootFolder& rf)
  {
    std::set <DeploymentPlans> dep_plan_folders = rf.DeploymentPlans_kind_children ();
	accept_each (dep_plan_folders, *this);
    
	this->initDocument ("CIAO:NetQoSRequirements");
    this->initRootAttributes(); // this->curr_ is ROOT now.

    std::set<ComponentImplementations>
      comp_impls = rf.ComponentImplementations_kind_children();
	accept_each (comp_impls, *this);

    for (std::set <std::string>::const_iterator iter = this->filenames_.begin();
         iter != this->filenames_.end ();
         ++iter)
      {
        std::string name = this->outputPath_ + "\\" + *iter;
        this->initTarget (name);
        this->dumpDocument ();
      }

    DeploymentPlanFrameworkVisitor::instance()->Visit_RootFolder (rf);
  }

  void NetQoSVisitor::Visit_DeploymentPlans(const DeploymentPlans& plans_folder)
    {
      std::set <DeploymentPlan> dep_plans = plans_folder.DeploymentPlan_kind_children ();
	  accept_each (dep_plans, *this);
  }
  
  void NetQoSVisitor::Visit_DeploymentPlan(const DeploymentPlan& dep_plan)
    {
      std::set <Property> properties = dep_plan.Property_kind_children ();
	  accept_each (properties, *this);
  }

  void NetQoSVisitor::Visit_Property(const Property &property) 
    {
      std::string propname = property.name ();
      if (propname == "CIAONetworkQoS")
        this->filenames_.insert (property.DataValue ());
    }

  void NetQoSVisitor::Visit_ComponentImplementations(const ComponentImplementations &comp_impl)
  {
    std::set<ComponentImplementationContainer>
      comp_impl_conts = comp_impl.ComponentImplementationContainer_kind_children();
	accept_each (comp_impl_conts, *this);  
  }

  void NetQoSVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer &comp_impl_cont)
  {
    std::set<ComponentAssembly>
      comp_assemblies = comp_impl_cont.ComponentAssembly_kind_children();
	accept_each (comp_assemblies, *this);
  }

  void NetQoSVisitor::Visit_ComponentAssembly(const ComponentAssembly &comp_assembly)
    {
      std::set<QoSCharRef> qos_char_refs = comp_assembly.QoSCharRef_kind_children();
	  accept_each (qos_char_refs, *this);
      std::set<NetQoS> netqos = comp_assembly.NetQoS_kind_children();
	  accept_each (netqos, *this);    
    }

  void NetQoSVisitor::Visit_QoSCharRef(const QoSCharRef &qc_ref)
    {
      QoSCharacteristic qos_char = recursive_dereference(qc_ref);
      if (Udm::null != qos_char && 
		  Udm::IsDerivedFrom (qos_char.type(), NetQoS::meta))
        {
          NetQoS netqos = NetQoS::Cast (qos_char);
          this->current_netqos_ = netqos;
          this->conn_qoschar_visit (qc_ref);
        }
     }

  QoSCharacteristic NetQoSVisitor::recursive_dereference (const QoSCharacteristic &qos_char, int depth)
  {
	  // CQML's generic QoSModeling makes cycles of references possible including
	  // self-referencing. This is actually unfortunate but I am living it for now!
	  // Therefore, a sanity-check is necessary below.
	  const int MAX_DEPTH = 100;
	  if (depth == MAX_DEPTH) 
		// If recursion goes too too deep then throw a udm_exception.
		throw udm_exception ("NetQoSVisitor::recursive_dereference(): To long a chain of references! Check for cyclic references.");

	  if (Udm::IsDerivedFrom (qos_char.type(), QoSCharRef::meta))
	  {
		  QoSCharRef qos_char_ref = QoSCharRef::Cast (qos_char);
		  QoSCharacteristic qc = qos_char_ref.ref();
		  // Self-refereing references are also possible in CQML.
		  // This is actually unfortunate but I am living it for now!
		  // Therefore, a sanity-check is necessary below.
		  if (qc == qos_char_ref)
			  throw udm_exception ("NetQoSVisitor::recursive_dereference(): Self-refering reference was detected!");
		  return recursive_dereference (qc, depth+1);
	  }
	  else
		  return qos_char;
  }

  void NetQoSVisitor::Visit_NetQoS (const NetQoS &netqos)
    {
   	  DOMElement *conn_qos = this->doc_->createElement(XStr ("connectionQoS"));
	  this->curr_->appendChild (conn_qos);
	  this->push (); // push connectionQoS
	  this->curr_ = conn_qos;

      this->current_netqos_ = netqos;
      this->conn_qoschar_visit (netqos);

      for (std::multimap <NetQoS, ConnectionInfo>::iterator itr = this->qos_conn_mmap_.lower_bound (netqos);
           itr != this->qos_conn_mmap_.upper_bound (netqos);
           ++itr)
        {
          this->curr_->appendChild (this->createSimpleContent ("connectionName", itr->second.connection_name));  
/*
          DOMElement *connection_info = this->doc_->createElement (XStr ("connectionInfo"));
          connection_info->appendChild (this->createSimpleContent ("connectionName", itr->second.connection_name));  
          connection_info->appendChild (this->createSimpleContent ("client", itr->second.client));  
          connection_info->appendChild (this->createSimpleContent ("clientPortName", itr->second.client_port_name));  
          connection_info->appendChild (this->createSimpleContent ("server", itr->second.server));  
          connection_info->appendChild (this->createSimpleContent ("serverPortName", itr->second.server_port_name));  
          this->curr_->appendChild (connection_info);
*/
        }
      this->dump_NetQoSAttributes (this->curr_, netqos);
      this->pop (); // pop connectionQoS
    }

  void NetQoSVisitor::Visit_QoSReq (const QoSReq &qos_req)
  {
	  QoSConnector qos_connector = qos_req.srcQoSReq_end ();
	  qos_connector.Accept (*this);
  }

  void NetQoSVisitor::Visit_PortQoS (const PortQoS &port_qos)
  {
      Port port = port_qos.srcPortQoS_end ();
      if (Udm::IsDerivedFrom (port.type (), RequiredRequestPort::meta ))
        {
          this->visit_adjacent_qos_connector (&RequiredRequestPort::dstRecepInvoke,
                                              &RecepInvoke::dstRecepInvoke_end,
                                              port);
        }
      else if (Udm::IsDerivedFrom (port.type (), InEventPort::meta ))
        {
          this->visit_adjacent_qos_connector (&InEventPort::srcEventSinkPublish,
                                              &EventSinkPublish::srcEventSinkPublish_end,
                                              port);
        }
      else if (Udm::IsDerivedFrom (port.type (), ProvidedRequestPort::meta ))
        {
          this->visit_adjacent_qos_connector (&ProvidedRequestPort::srcFacetInvoke,
                                              &FacetInvoke::srcFacetInvoke_end,
                                              port);
        }
      else // OutEventPort
        {
          this->visit_adjacent_qos_connector (&OutEventPort::dstEventSourcePublish,
                                              &EventSourcePublish::dstEventSourcePublish_end,
                                              port); 
        }
  }

  void NetQoSVisitor::conn_qoschar_visit (const ConnectionQoSCharacteristic & conn_qoschar)
    {
/*		QoSCharacteristicBase base_qos;
		if (Udm::IsDerivedFrom (qoschar_base.type (), QoSCharRef::meta ))
		{
			QoSCharRef qos_char_ref = QoSCharRef::Cast (qoschar_base);
			QoSCharacteristic qos_char = qos_char_ref.ref ();
			base_qos = QoSCharacteristicBase::Cast (qos_char);
		}
		else
			base_qos = qoschar_base;
*/
		if (Udm::IsDerivedFrom (conn_qoschar.type (), ConnectionQoSCharacteristic::meta ))
		  {
			  ConnectionQoSCharacteristic cqc 
				  = ConnectionQoSCharacteristic::Cast (conn_qoschar);
			  std::set <QoSReq> qos_req_connections = cqc.srcQoSReq ();
			  if (! qos_req_connections.empty ())
					accept_each (qos_req_connections, *this);        

			  std::set <PortQoS> port_qos_connections = conn_qoschar.srcPortQoS ();
			  if (! port_qos_connections.empty ())
				  accept_each (port_qos_connections, *this);
		  }
    }

  template <typename PortType, typename ConnectionType, typename QoSConnectorRet, typename ConnSetRet>
  void NetQoSVisitor::visit_adjacent_qos_connector 
                     (ConnSetRet (PortType::*connection_set_getter)() const,
                      QoSConnectorRet (ConnectionType::*connector_getter)() const,
                      Port generic_port)
    {
      PortType port = PortType::Cast (generic_port);
      std::set <ConnectionType> connections = (port.*connection_set_getter)();
      for (std::set <ConnectionType>::iterator itr = connections.begin ();
            itr != connections.end ();
            ++itr)
        {
          ConnectionType conn = *itr;
          QoSConnector qos_connector = (conn.*connector_getter)();
          qos_connector.Accept (*this);
        }
    }

  void NetQoSVisitor::dump_NetQoSAttributes (DOMElement *ele, const NetQoS &netqos)
    {
      std::ostringstream ostr;
      ostr << netqos.fwdBW ();
      ele->appendChild (this->createSimpleContent ("fwdBW", ostr.str()));
      ostr.str("");

      ostr << netqos.revBW ();
      ele->appendChild (this->createSimpleContent ("revBW", ostr.str()));
      ostr.str("");

      ele->appendChild (this->createSimpleContent ("qos", netqos.quality ()));
      ele->appendChild (this->createSimpleContent ("admissionPriority", netqos.admissionPriority ()));
    }

  void NetQoSVisitor::Visit_QoSConnector (const QoSConnector &qos_connector)
    {
      RecepInvoke recep_invoke_connection = qos_connector.srcRecepInvoke ();
      FacetInvoke facet_invoke_connection = qos_connector.dstFacetInvoke ();
      if (Udm::null != recep_invoke_connection &&
          Udm::null != facet_invoke_connection) 
        {
          RequiredRequestPort receptacle = recep_invoke_connection.srcRecepInvoke_end ();
          ProvidedRequestPort facet = facet_invoke_connection.dstFacetInvoke_end ();

          std::map <Component,string> receptacles;
          std::map <Component,string> facets;
          this->GetReceptacleComponents (receptacle, receptacles);
          this->GetFacetComponents (facet, facets);
          this->CreateConnections (receptacles, facets);
        }

      EventSourcePublish esource_connection = qos_connector.srcEventSourcePublish ();
      std::set <EventSinkPublish> esink_connection_set = qos_connector.dstEventSinkPublish ();
      if (Udm::null != esource_connection &&
          ! esink_connection_set.empty ()) 
        {
          OutEventPort out_event_port = esource_connection.srcEventSourcePublish_end ();
          for (std::set <EventSinkPublish>::const_iterator 
                 itr = esink_connection_set.begin ();
               itr != esink_connection_set.end ();
               ++itr)
            {
              EventSinkPublish event_sink_pub = *itr;
              InEventPort in_event_port = event_sink_pub.dstEventSinkPublish_end ();

              std::map <Component,string> event_sources;
              std::map <Component,string> event_sinks;
              this->GetEventSourceComponents (out_event_port, event_sources);
              this->GetEventSinkComponents (in_event_port,event_sinks);
              this->CreateConnections (event_sources, event_sinks);
            }
        }

      /// Should not reach here
    }

  template <typename T, typename Del, typename DelRet, typename DelEndRet>
  void NetQoSVisitor::GetComponents (const T& port,
                                      DelRet (T::*srcDel)() const,
                                      DelRet (T::*dstDel) () const,
                                      DelEndRet (Del::*srcDelEnd)() const,
                                      DelEndRet (Del::*dstDelEnd)() const,
                                      map<Component, string>& output,
                                      set<T>& visited)
  {
    visited.insert (port);
    Udm::Object par = port.parent();
    string recepName = port.name();
    string parentName = this->ExtractName (par);
    if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
      {
        set<Del> delegates = (port.*dstDel)();
        for (set<Del>::const_iterator iter = delegates.begin();
             iter != delegates.end();
             ++iter)
          {
            Del delegate = *iter;
            T srcPort = (delegate.*dstDelEnd)();
            string srcPortName = this->ExtractName(srcPort);
            if (find (visited.begin(),
                           visited.end(),
                           srcPort) == visited.end())
              this->GetComponents(srcPort, srcDel, dstDel,
                                  srcDelEnd, dstDelEnd, output, visited);
          }
        delegates = (port.*srcDel)();
        for (set<Del>::const_iterator iter = delegates.begin();
             iter != delegates.end();
             ++iter)
          {
            Del delegate = *iter;
            T dstPort = (delegate.*srcDelEnd)();
            string dstPortName = this->ExtractName(dstPort);
            if (find (visited.begin(),
                           visited.end(),
                           dstPort) == visited.end())
              this->GetComponents(dstPort, srcDel, dstDel,
                                  srcDelEnd, dstDelEnd, output, visited);
          }
      }
    else if (Udm::IsDerivedFrom (par.type(), Component::meta))
      {
        Component recep_comp = Component::Cast (par);
        output.insert (make_pair (recep_comp, port.name()));
      }
    visited.erase (port);
    return;
  }

  void NetQoSVisitor::GetReceptacleComponents (const RequiredRequestPort& receptacle,
                                                map<Component,string>& output)
  {
    set<RequiredRequestPort> visited;
    this->GetComponents (receptacle,
                         &RequiredRequestPort::srcReceptacleDelegate,
                         &RequiredRequestPort::dstReceptacleDelegate,
                         &ReceptacleDelegate::srcReceptacleDelegate_end,
                         &ReceptacleDelegate::dstReceptacleDelegate_end,
                         output,
                         visited);
  }

  void NetQoSVisitor::GetFacetComponents (const ProvidedRequestPort& facet,
                                           map<Component,string>& output)
  {
    set<ProvidedRequestPort> visited;
    this->GetComponents (facet,
                         &ProvidedRequestPort::srcFacetDelegate,
                         &ProvidedRequestPort::dstFacetDelegate,
                         &FacetDelegate::srcFacetDelegate_end,
                         &FacetDelegate::dstFacetDelegate_end,
                         output,
                         visited);
  }

  void NetQoSVisitor::GetEventSinkComponents (const InEventPort& consumer,
                                               map<Component,string>& output)
  {
    set<InEventPort> visited;
    this->GetComponents (consumer,
                         &InEventPort::srcEventSinkDelegate,
                         &InEventPort::dstEventSinkDelegate,
                         &EventSinkDelegate::srcEventSinkDelegate_end,
                         &EventSinkDelegate::dstEventSinkDelegate_end,
                         output,
                         visited);
  }

  void NetQoSVisitor::GetEventSourceComponents (const OutEventPort& publisher,
                                                 map<Component,string>& output)
  {
    set<OutEventPort> visited;
    this->GetComponents (publisher,
                         &OutEventPort::srcEventSourceDelegate,
                         &OutEventPort::dstEventSourceDelegate,
                         &EventSourceDelegate::srcEventSourceDelegate_end,
                         &EventSourceDelegate::dstEventSourceDelegate_end,
                         output,
                         visited);
  }

  void NetQoSVisitor::CreateConnections (const map<Component, string>& src,
                                          const map<Component, string>& dst)
  {
    for (map<Component,string>::const_iterator iter = src.begin();
         iter != src.end();
         ++iter)
      {
        Component srcComp = iter->first;
        string srcPortName = iter->second;
        for (map<Component, string>::const_iterator iter2 = dst.begin();
             iter2 != dst.end();
             ++iter2)
          {
            Component dstComp = iter2->first;
            string dstPortName = iter2->second;
            this->CreateConnection (srcComp, srcPortName, dstComp, dstPortName);
          }
      }
  }

  void NetQoSVisitor::CreateConnection (const Component& srcComp,
                                         const string& srcPortName,
                                         const Component& dstComp,
                                         const string& dstPortName)
  {
    std::string source_comp_instance 
		= DeploymentPlanFrameworkVisitor::instance()->unique_id (srcComp);
    std::string dest_comp_instance 
		= DeploymentPlanFrameworkVisitor::instance()->unique_id (dstComp);

    std::string connection = srcPortName + "_" + dstPortName + source_comp_instance + dest_comp_instance;
 
    ConnectionInfo conn_info;
    conn_info.connection_name = connection;
    conn_info.client = DeploymentPlanFrameworkVisitor::instance()->unique_id (srcComp);
    conn_info.client_port_name = srcPortName;
    conn_info.server = DeploymentPlanFrameworkVisitor::instance()->unique_id (dstComp);
    conn_info.server_port_name = dstPortName;
    
    this->qos_conn_mmap_.insert (std::make_pair (this->current_netqos_, conn_info));
  }

  DOMElement* NetQoSVisitor::createSimpleContent (const std::string& name,
                                                  const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  std::string NetQoSVisitor::ExtractName(Udm::Object ob)
  {
    Uml::Class cls= ob.type();
    set<Uml::Attribute> attrs=cls.attributes();

    // Adding parent attributes
    set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
    attrs.insert(aattrs.begin(),aattrs.end());

    for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++)
      {
        if(string(ai->type())=="String")
          {
            string str=ai->name();
            if(str=="name")
              {
                string value=ob.getStringAttr(*ai);
                if(value.empty())value="<empty string>";
                return value;
              }
          }
      }
    return string("<no name specified>");
  }
/*
  NetQoSRequirementsIterator NetQoSVisitor::iterator_begin () const
    {
      return NetQoSRequirementsIterator (*this, this->qos_conn_mmap_.begin ());
    }
  
  NetQoSRequirementsIterator NetQoSVisitor::iterator_end () const
    {
      return NetQoSRequirementsIterator (*this, this->qos_conn_mmap_.end ());
    }
*/
}