#include "ace/config.h"

#include "Utils/Utils.h"
#include "RTConfigurationVisitor.h"

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

  // Constructor.
    RTConfigurationVisitor::RTConfigurationVisitor (const std::string& outputPath)
      : impl_ (0),
    doc_ (0),
    root_ (0),
    curr_ (0),
    resources_ (0),
    serializer_ (0),
    target_ (0),
    outputPath_ (outputPath),
    artifact_name_ (""),
    dp_framework_owner_ (DeploymentPlanFrameworkVisitor::instance ()),
    rt_injector_ (0)
  {

    this->init();
    DeploymentPlanFrameworkVisitor::instance()->set_path (outputPath);
    }


  RTConfigurationVisitor::~RTConfigurationVisitor ()
  {
    if (this->doc_)
      this->doc_->release();
    delete this->target_;
    delete this->rt_injector_;
    this->outfile_.close ();

  }

  void RTConfigurationVisitor::init()
  {
    this->impl_ = DOMImplementationRegistry::getDOMImplementation (GAME::Xml::String("LS"));
    this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer();


    // Set features if the serializer supports the feature/mode
    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

    if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
      this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
  }

  void RTConfigurationVisitor::initTarget (const std::string& fileName)
  {
    if (this->target_)
      delete this->target_;
    this->target_ = new LocalFileFormatTarget (fileName.c_str());
  }

  void RTConfigurationVisitor::initDocument (const std::string& rootName)
  {
    if (this->doc_)
      this->doc_->release();
    // Create the document
    this->doc_ =
      this->impl_->createDocument (GAME::Xml::String ("http://www.dre.vanderbilt.edu/ServerResources"),
      GAME::Xml::String (rootName.c_str()),
      0);

    //erase all elements currently present in the element maps
    this->tp_.clear ();
    this->connections_.clear ();
    this->tp_with_lanes_.clear ();
    this->deployed_resources_.clear ();
  }

  void RTConfigurationVisitor::initRootAttributes()
  {
    //this->doc_->setEncoding (GAME::Xml::String("UTF-8"));
    this->doc_->setXmlVersion (GAME::Xml::String("1.0"));
    this->root_ = this->doc_->getDocumentElement();
    this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
      GAME::Xml::String ("xmlns:CIAO"),
      GAME::Xml::String ("http://www.dre.vanderbilt.edu/ServerResources"));
    this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
      GAME::Xml::String ("xmlns:xsi"),
      GAME::Xml::String ("http://www.w3.org/2001/XMLSchema-instance"));
    this->root_->setAttributeNS (GAME::Xml::String ("http://www.w3.org/2000/xmlns/"),
      GAME::Xml::String ("xmlns:xmi"),
      GAME::Xml::String ("http://www.omg.org/XMI"));
    this->root_->setAttribute (GAME::Xml::String ("xsi:schemaLocation"),
      GAME::Xml::String ("http://www.dre.vanderbilt.edu/ServerResources CIAOServerResources.xsd"));
    std::string id = "_";
    id += Utils::CreateUuid ();
    this->root_->setAttribute (GAME::Xml::String ("id"),
      GAME::Xml::String (id.c_str ()));
    this->artifact_name_ = id;
    this->curr_ = this->root_;
    this->resources_ = 0;
  }

  void RTConfigurationVisitor::dumpDocument()
  {
    xercesc::DOMLSOutput * output = ((DOMImplementationLS*)this->impl_)->createLSOutput ();
    output->setByteStream (this->target_);

    this->serializer_->write (this->doc_, output);
    output->release ();
  }

  void RTConfigurationVisitor::push()
  {
    this->curr_stack_.push (this->curr_);
  }

  void RTConfigurationVisitor::pop()
  {
    if (!this->curr_stack_.empty())
    {
      this->curr_ = this->curr_stack_.top();
      this->curr_stack_.pop();
    }
    else
    {
      throw(std::exception());
    }
  }

  DOMElement* RTConfigurationVisitor::createSimpleContent (const std::string& name,
    const std::string& value)
  {
    DOMElement* pName = this->doc_->createElement (GAME::Xml::String (name.c_str()));
    DOMText* pValue = this->doc_->createTextNode (GAME::Xml::String (value.c_str()));
    pName->appendChild (pValue);
    return pName;
  }

  void RTConfigurationVisitor::Visit_RootFolder(const RootFolder& rf)
    {
    // First parse and collect all the RT information locally.
    this->parse_rt_configs (rf);

    // Finally, call the DRFramework top level function.
    DeploymentPlanFrameworkVisitor::instance()->Visit_RootFolder (rf);
  }

  void RTConfigurationVisitor::parse_rt_configs (const RootFolder& rf)
  {
    RTConfigurationVisitor * rtv = const_cast<RTConfigurationVisitor *>(this);
    this->rt_injector_ = new RTInjector (rtv);

    // DeploymentPlans for creating the csr file and registering the injector with DRFramework.
    accept_each_child (rf, DeploymentPlans, *this);
    this->initDocument ("CIAO:ServerResources");
    this->artifact_name_ = rf.getPath ("_",false,true,"name",true);
    this->initRootAttributes ();
    this->push();
    // Continue visiting RTConfiguration.
    accept_each_child (rf, ComponentImplementations, *this);

    for (std::set <std::string>::const_iterator iter = this->csr_files_.begin();
         iter != this->csr_files_.end ();
         ++iter)
      {
        this->initTarget (*iter);
        this->dumpDocument ();
      }

  }

  void RTConfigurationVisitor::Visit_DeploymentPlans (const DeploymentPlans& dps)
  {
    accept_each_child (dps, DeploymentPlan, *this);
  }

  void RTConfigurationVisitor::Visit_ComponentImplementations
    (const ComponentImplementations &comp_impls)
  {
    accept_each_child (comp_impls, ComponentImplementationContainer, *this);
  }

  void RTConfigurationVisitor::Visit_ComponentImplementationContainer
    (const ComponentImplementationContainer &impl_container)
  {
    accept_each_child (impl_container, ComponentAssembly, *this);
  }

  void RTConfigurationVisitor::add_env_conf (const ComponentAssembly& assembly)
  {
    std::set<RealTimeConfiguration> rtcs = assembly.RealTimeConfiguration_kind_children ();

    for (std::set<RealTimeConfiguration>::iterator iter = rtcs.begin ();
      iter != rtcs.end ();
      ++iter)
    {
      std::set<EnvironmentConf> ecs = (*iter).EnvironmentConf_kind_children ();
	  for(auto ec : ecs)
		  ec.Accept(*this);
    }
  }

  void RTConfigurationVisitor::Visit_ComponentAssembly (const ComponentAssembly &assembly)
  {
    this->add_env_conf (assembly);

    //ORB configuration parameters
    DOMElement* oc = this->doc_->createElement (GAME::Xml::String ("orbConfigs"));
    this->curr_->appendChild (oc);
    this->curr_ = oc;

    //add the orbResources
    this->push ();
    //Create the <orbResources> as a child of the <orbConfigs>
    DOMElement* or = this->doc_->createElement (GAME::Xml::String ("resources"));
    this->curr_->appendChild (or);
    this->curr_ = or;
    this->resources_ = this->curr_;

    std::set<RealTimeConfiguration> rts = assembly.RealTimeConfiguration_kind_children ();

	
	for(auto rtsiter : rts)
		rtsiter.Accept(*this);

    this->pop ();

    for (std::set<RealTimeConfiguration>::iterator rtsiter = rts.begin (); rtsiter != rts.end ();
       ++rtsiter)
    {
      // handle policy set elements.
        if (!this->add_policy_set (*rtsiter))
       return;
    }




  }

  void RTConfigurationVisitor::Visit_Property (const Property& prop)
  {
    std::string propname = prop.name ();
    if (propname == "CIAOServerResources" )
    {
      std::string name = this->outputPath_ + "\\";
      name += prop.DataValue ();
      //name += ".csr";
      this->csr_files_.insert (name);
    }
    return;
  }

  void RTConfigurationVisitor::Visit_DeploymentPlan (const DeploymentPlan& dp)
  {
    // Create a new csr file according to the specified property name.
    accept_each_child (dp, Property, *this);
    // Register the injector with the DRFramework.
    DeploymentPlanFrameworkVisitor::instance ()->add_injector (dp.name (), this->rt_injector_);
  }


  // rt_injector calls this function on behalf of DPFramework to get the deployed resources string
  // for a specific component.
  std::string RTConfigurationVisitor::get_deployed_resource (const CQML::Component& comp)
  {

    if (this->deployed_resources_.find (comp) != this->deployed_resources_.end ())
    {
      std::string deployed_resource = this->deployed_resources_[comp];
      return deployed_resource;
    }
    return std::string ();
  }

  std::string RTConfigurationVisitor::get_resource_name ()
  {
    std::string resource_name = this->artifact_name_;
    return resource_name;
  }

  // Returns all the connected components for a RealTimeConfiguration element.
  std::set<Component> RTConfigurationVisitor::get_connected_components (const CQML::RealTimeConfiguration& rtc)
  {
    std::set<Component> comps;

    std::set<ComponentQoS> comp_qos = rtc.srcComponentQoS ();
    for (std::set<ComponentQoS>::iterator iter = comp_qos.begin();
      iter != comp_qos.end();
      ++iter)
    {
      ComponentBase compbase = (*iter).srcComponentQoS_end ();
      Component comp;
      if (Udm::null == compbase )
      {
        throw (udm_exception ("RTConfigurationVisitor::Visit_RealTimeConfiguration ():Component null."));
      }
      else
      {
        // Component, or a reference to the component.
        if (Udm::IsDerivedFrom (compbase.type(), ComponentRef::meta))
        {
          ComponentRef compref = ComponentRef::Cast (compbase);
          comp = compref.ref ();
        }
        else if (Udm::IsDerivedFrom (compbase.type(), Component::meta))
        {
          comp = Component::Cast (compbase);
        }
        // insert the componet in set.
        comps.insert (comp);
      }
    }
    return comps;
  }

  // Populates the deployed resources for every component in the CQML model.
  void RTConfigurationVisitor::populate_deployed_resources (const CQML::RealTimeConfiguration& rtc)
  {
    std::set<Component> comps = this->get_connected_components (rtc);
    if (comps.size () == 0)
      return;

    for (std::set<Component>::iterator iter = comps.begin ();
      iter != comps.end ();
      ++iter)
      this->deployed_resources_[*iter] = rtc.name ();
  }


  // RealTimeConfiguration element visitor.
  void RTConfigurationVisitor::Visit_RealTimeConfiguration( const CQML::RealTimeConfiguration& object )
  {
    this->populate_deployed_resources (object);


    std::set<CQML::ThreadPool> tpools = object.ThreadPool_kind_children ();
    std::set<CQML::PriorityBands> bandedconns = object.PriorityBands_kind_children ();

    if (tpools.size () != 0 || bandedconns.size () != 0)
    {
      ////add the orbResources
      //this->push ();
      ////Create the <orbResources> as a child of the <orbConfigs>
      //DOMElement* or = this->doc_->createElement (GAME::Xml::String ("resources"));
      //this->curr_->appendChild (or);
      //this->curr_ = or;
      //this->resources_ = this->curr_;

      //visit the resources

      if (tpools.size () != 0)
      {
        for (std::set<CQML::ThreadPool>::iterator iter = tpools.begin ();
          iter != tpools.end ();
          ++iter)
        {
          CQML::ThreadPool tp = *iter;
          tp.Accept (*this);
        }
      }


      if (bandedconns.size () != 0)
      {
        this->push ();

        //Create the <connectionBands> element
        DOMElement* e = this->doc_->createElement (GAME::Xml::String ("connectionBands"));
        std::string bcID ("band");
        e->setAttribute (GAME::Xml::String ("id"), GAME::Xml::String (bcID));
        this->curr_->appendChild (e);
        this->curr_ = e;

        for (std::set<CQML::PriorityBands>::iterator iter = bandedconns.begin ();
          iter != bandedconns.end ();
          ++iter)
        {
          CQML::PriorityBands tp = *iter;
          tp.Accept (*this);
        }

      }

    }


    return;

  }

  bool RTConfigurationVisitor::add_policy_set (const CQML::RealTimeConfiguration& object)
  {
    //add the priority model
    std::set<CQML::PriorityModelPolicy> pmps = object.PriorityModelPolicy_kind_children ();
    if (pmps.size () != 0)
    {
      this->push ();

      //Create the <threadpoolWithLanes> element
      DOMElement* e = this->doc_->createElement (GAME::Xml::String ("policySet"));
      std::string psID (object.name ());
      e->setAttribute (GAME::Xml::String ("id"), GAME::Xml::String (psID));
      this->curr_->appendChild (e);
      this->curr_ = e;

      for (std::set<CQML::PriorityModelPolicy>::iterator iter = pmps.begin ();
        iter != pmps.end ();
        ++iter)
      {
        CQML::PriorityModelPolicy pm = *iter;
        pm.Accept (*this);
      }
    }

    std::set<CQML::ThreadPool> pool_set = object.ThreadPool_kind_children ();
    std::string name;

    CQML::ThreadPool tp;
    if (pool_set.size () != 0)
      tp = *(pool_set.begin ());

      name =  tp.name ();


    if (name.size () != 0)
      this->curr_->appendChild (
        this->createSimpleContent ("threadpool", name.c_str ()));



    if (this->connections_.size () != 0)
    {

      std::map<std::string, bool>::iterator biter = this->connections_.begin ();

      name = (*biter).first;
      this->curr_->appendChild (
        this->createSimpleContent ("priorityBandedConnection", name.c_str ()));
    }


    //restore curr
    this->pop ();
    return true;

  }

  void RTConfigurationVisitor::Visit_EnvironmentConf (const EnvironmentConf& ec)
  {
    //save current level
    this->push ();

    //Add the <cmdline> options
    DOMElement* cmd = this->doc_->createElement (GAME::Xml::String ("cmdline"));
    this->curr_->appendChild (cmd);
    this->curr_ = cmd;

    std::string cl = ec.CmdLineOptions ();

    //Add the <arg>
    if (!cl.empty ())
      this->curr_->appendChild (this->createSimpleContent ("arg",
      cl.c_str ()));

    //return to entry level
    this->pop ();

    //save current level again
    this->push ();

    //Add the <svcconf> options
    DOMElement* svc = this->doc_->createElement (GAME::Xml::String ("svcconf"));
    this->curr_->appendChild (svc);
    this->curr_ = svc;

    std::string sc = ec.SvcConf ();
    //Add the <uri>
    if (!sc.empty ())
      this->curr_->appendChild (this->createSimpleContent ("uri",
      sc.c_str ()));

    //return to entry level
    this->pop ();

    return;
  }


  void RTConfigurationVisitor::add_threadpool_with_lanes (std::set<CQML::Lane> lanes)
  {
    for (std::set<CQML::Lane>::iterator iter = lanes.begin ();
      iter != lanes.end (); ++iter)
    {
      CQML::Lane lane = (*iter);
      lane.Accept (*this);
    }
  }

  void RTConfigurationVisitor::add_simple_threadpool (std::set<CQML::Lane> lanes)
  {
    //static, dynamic and lane priority elements from lane.
    std::set<CQML::Lane>::iterator iter = lanes.begin ();
    CQML::Lane lane = *iter;

    //output static threads
    long st = (long)lane.static_threads ();
    std::ostringstream temp;
    temp << st;

    //Add the <static_threads>
    this->curr_->appendChild (this->createSimpleContent ("static_threads", temp.str ()));

    //output dynamic threads
    long dt = (long)lane.dynamic_threads ();
    temp.str("");
    temp<<dt;
    //Add the <dynamic_threads>
    this->curr_->appendChild (this->createSimpleContent ("dynamic_threads", temp.str ()));

    //output default priority
    long prio = (long)lane.lane_priority ();
    temp.str ("");
    temp << prio;
    //Add the <default_priority>
    this->curr_->appendChild (this->createSimpleContent ("default_priority", temp.str ()));

  }


  void RTConfigurationVisitor::Visit_ThreadPool( const CQML::ThreadPool& tp)
  {
    // if only a single lane element is connected to threadpool, create a simple thread pool.
    // else create a threadpoolwithlanes.
    std::set<CQML::LanePerThreadPool> lanespertp = tp.srcLanePerThreadPool ();

    if (lanespertp.empty ())
      return;

    // Iterator of the lanespertp set.
    std::set<CQML::LanePerThreadPool>::iterator iter = lanespertp.begin ();

    // Populate the lanes
    std::set<CQML::Lane> lanes;
    for (;iter != lanespertp.end (); ++iter)
    {
      CQML::Lane lane = (*iter).srcLanePerThreadPool_end ();
      lanes.insert (lane);
    }

    // If more than one connections are present, configure with lanes, otherwise without lanes.
    std::string pooltype = ((lanespertp.size () == 1)?"threadpool":"threadpoolWithLanes");
    // handle the simple threadpool first.

    //save curr
    this->push ();

    //Create the <threadpool> element
    DOMElement* e = this->doc_->createElement (GAME::Xml::String (pooltype.c_str ()));
    std::string tpID (tp.name ());
    e->setAttribute (GAME::Xml::String ("id"), GAME::Xml::String (tpID));
    this->curr_->appendChild (e);
    this->curr_ = e;

    // if the threadpool has multiple lanes connected, also handle the lanes now.
    if (lanes.size () > 1)
      this->add_threadpool_with_lanes (lanes);



    std::ostringstream temp;

    //output stack size
    long ss = (long)tp.stacksize ();
    temp << ss;

    //Add the <static_threads>
    this->curr_->appendChild (this->createSimpleContent ("stacksize", temp.str ()));


    if (lanes.size () == 1)
      this->add_simple_threadpool (lanes);

    else
    {
      //output allow borrowing
      bool ab = tp.allow_borrowing ();
      //Add the <allow_borrowing>
      if (ab)
        this->curr_->appendChild
        (this->createSimpleContent ("allow_borrowing", "true"));
      else
        this->curr_->appendChild
        (this->createSimpleContent ("allow_borrowing", "false"));
    }

    //output allow request buffering
    bool arb = tp.allow_request_buffering ();
    //Add the <allow_buffering>
    if (arb)
      this->curr_->appendChild
      (this->createSimpleContent ("allow_request_buffering", "true"));
    else
      this->curr_->appendChild
      (this->createSimpleContent ("allow_request_buffering", "false"));

    //output max buffered requests
    long mbr = (long)tp.max_buffered_requests ();
    temp.str ("");
    temp << mbr;
    //Add the <max_buffered_requests>
    this->curr_->appendChild
      (this->createSimpleContent ("max_buffered_requests", temp.str ()));

    //output max request buffer size
    long mbrs = (long)tp.max_buffer_size ();
    temp.str ("");
    temp << mbrs;
    //Add the <max_request_buffered_size>
    this->curr_->appendChild
      (this->createSimpleContent ("max_request_buffered_size", temp.str ()));

    //add the threadpool to the list of elements that have been added
    if (lanes.size () == 1)
      this->tp_.insert (make_pair (tp.name (), true));
    else
      this->tp_with_lanes_.insert (make_pair (tp.name (), true));

    //restore curr
    this->pop ();

    return;


  }

  void RTConfigurationVisitor::Visit_PriorityBands (const CQML::PriorityBands& bc)
  {
    //save curr
    this->push ();

    //Add the <band> element
    DOMElement* band = this->doc_->createElement (GAME::Xml::String ("band"));
    this->curr_->appendChild (band);
    this->curr_ = band;


    std::ostringstream temp;

    //output low
    long low = (long)bc.low ();
    temp << low;

    //Add the <low>
    this->curr_->appendChild (this->createSimpleContent ("low", temp.str ()));

    //output high
    long high = (long)bc.high ();
    temp.str ("");
    temp << high;

    //Add the <high>
    this->curr_->appendChild (this->createSimpleContent ("high", temp.str ()));

    //restore curr
    this->connections_.insert (make_pair (bc.name (), true));

    this->pop ();

    return;
  }


  void RTConfigurationVisitor::Visit_Lane (const CQML::Lane& lns)
  {
    //save curr
    this->push ();

    //Add the <threadpoolLane> element
    DOMElement* lane = this->doc_->createElement (GAME::Xml::String ("threadpoolLane"));
    this->curr_->appendChild (lane);
    this->curr_ = lane;

    std::ostringstream temp;

    //output static threads
    long st = (long)lns.static_threads ();
    temp << st;

    //Add the <static_threads>
    this->curr_->appendChild (this->createSimpleContent ("static_threads", temp.str ()));

    //output dynamic threads
    long dt = (long)lns.dynamic_threads ();
    temp.str ("");
    temp << dt;

    //Add the <dynamic_threads>
    this->curr_->appendChild (this->createSimpleContent ("dynamic_threads", temp.str ()));

    //output lane priority
    long prio = (long)lns.lane_priority ();
    temp.str ("");
    temp << prio;

    //Add the <priority>
    this->curr_->appendChild (this->createSimpleContent ("priority", temp.str ()));

    //restore curr
    this->pop ();

    return ;
  }

  void RTConfigurationVisitor::Visit_PriorityModelPolicy (const PriorityModelPolicy& pmp)
  {
    //save curr
    this->push ();

    //Create the <priorityModel> element
    DOMElement* e = this->doc_->createElement (GAME::Xml::String ("priorityModel"));

    std::ostringstream temp;

    long pv = (long)pmp.priority_value ();
    temp << pv;

    std::string p_type = pmp.priority_model ();
    // Only set the server_priority if model is CLIENT_PROPAGATED

    //if (p_type.compare ("CLIENT_PROPAGATED") != 0 )
      e->setAttribute (GAME::Xml::String ("server_priority"), GAME::Xml::String (temp.str ()));

    this->curr_->appendChild (e);
    this->curr_ = e;

    //Add the <priority_model>


    // ugly, but serves the purpose.
    std::string pt = p_type.compare ("CLIENT_PROPAGATED") == 0?"CLIENT_PROPAGATED":"SERVER_DECLARED";

    this->curr_->appendChild (
      this->createSimpleContent ("priority_model", pt.c_str ())
      );

    //restore curr
    this->pop ();
    return ;
  }



  //========================================================================
  // Predefined Types
  void RTConfigurationVisitor::Visit_Boolean(const CQML::Boolean& boolean)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_boolean"));
    this->pop();
    return ;
  }

  void RTConfigurationVisitor::Visit_Byte(const CQML::Byte&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_octet"));
    this->pop();
    return ;
  }

  void RTConfigurationVisitor::Visit_String(const CQML::String&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_string"));
    this->pop();
    return ;
  }

  void RTConfigurationVisitor::Visit_RealNumber(const CQML::RealNumber&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_double"));
    this->pop();
    return ;
  }

  void RTConfigurationVisitor::Visit_ShortInteger(const CQML::ShortInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_short"));
    this->pop();
    return ;
  }

  void RTConfigurationVisitor::Visit_LongInteger(const CQML::LongInteger&)
  {
    this->push();
    DOMElement* type = this->doc_->createElement (GAME::Xml::String ("type"));
    this->curr_->appendChild (type);
    this->curr_ = type;
    this->curr_->appendChild (this->createSimpleContent ("kind",
      "tk_long"));
    this->pop();
    return ;
  }


}

