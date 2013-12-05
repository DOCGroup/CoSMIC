// $Id$

#include "Utils/Utils.h"
#include "BIRSpecificationVisitor.h"
#include "UmlExt.h"

#include <algorithm>
#include <functional>
#include <sstream>

namespace CQML
  {

  // Constructor.
    BIRSpecificationVisitor::BIRSpecificationVisitor (const std::string& outputPath)
      : outputPath_ (outputPath)
    {
    // open file for bir specification.
    this->filename_ = this->outputPath_ + "\\" + std::string ("RTBIRSpecification.BIR");
    outfile_.open (this->filename_.c_str (), ios::app);
    }

  //
  void BIRSpecificationVisitor::Visit_RootFolder(const RootFolder& rf)
    {
    accept_each_child (rf, ComponentImplementations, *this);
  }


  void BIRSpecificationVisitor::Visit_ComponentImplementations(const ComponentImplementations &comp_impl)
  {
    accept_each_child (comp_impl, ComponentImplementationContainer, *this);
  }

  void BIRSpecificationVisitor::Visit_ComponentImplementationContainer(const ComponentImplementationContainer &comp_impl_cont)
  {
    accept_each_child (comp_impl_cont, ComponentAssembly, *this);
  }

  void BIRSpecificationVisitor::Visit_ComponentAssembly(const ComponentAssembly &comp_assembly)
  {
    accept_each_child (comp_assembly, RealTimeConfiguration, *this);

    // Initialize the BIR file.
    this->init_bir_arguments ();

    accept_each_child (comp_assembly, publish, *this);
    accept_each_child (comp_assembly, deliverTo, *this);
    accept_each_child (comp_assembly, PublishConnector, *this);
  }

  void BIRSpecificationVisitor::Visit_publish(const publish& ev)
  {
    // Get the publisher end
    const OutEventPort publisher = ev.srcpublish_end();

    // Get the connector end
    const PublishConnector connector = ev.dstpublish_end();

    // Create an entry in the publishers_ map
    this->publishers_[std::string (connector.name())] = publisher;
  }

  void BIRSpecificationVisitor::Visit_deliverTo(const deliverTo& dv)
  {
    // Get the connector end
    const  PublishConnector connector = dv.srcdeliverTo_end();

    // Get the consumer end
    const InEventPort consumer = dv.dstdeliverTo_end();

    // Create an entry in the consumers_ map
    this->consumers_.insert (make_pair (std::string (connector.name()),
      consumer));
  }

  void BIRSpecificationVisitor::GetEventSourceComponents
    (const OutEventPort& publisher,
    std::map<Component,std::string>& output)
  {
    std::set<OutEventPort> visited;
    this->GetComponents (publisher,
      &OutEventPort::srcEventSourceDelegate,
      &OutEventPort::dstEventSourceDelegate,
      &EventSourceDelegate::srcEventSourceDelegate_end,
      &EventSourceDelegate::dstEventSourceDelegate_end,
      output,
      visited);
  }

  void BIRSpecificationVisitor::GetEventSinkComponents (const InEventPort& consumer,
    std::map<Component,
    std::string>& output)
  {
    std::set<InEventPort> visited;
    this->GetComponents (consumer,
      &InEventPort::srcEventSinkDelegate,
      &InEventPort::dstEventSinkDelegate,
      &EventSinkDelegate::srcEventSinkDelegate_end,
      &EventSinkDelegate::dstEventSinkDelegate_end,
      output,
      visited);
  }

  std::string BIRSpecificationVisitor::ExtractName(Udm::Object ob)
  {
    Uml::Class cls= ob.type();
    set<Uml::Attribute> attrs=cls.attributes();

    // Adding parent attributes
    set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
    attrs.insert(aattrs.begin(),aattrs.end());

    for(set<Uml::Attribute>::iterator ai = attrs.begin();
      ai != attrs.end(); ai++)
    {
      if(string(ai->type())=="String")
      {
        string str=ai->name();
        if(str=="name")
        {
          string value=ob.getStringAttr(*ai);
          if(value.empty())
          {
            value="<empty string>";
          }
          return value;
        }
      }
    }
    return string("<no name specified>");
  }


  template <typename T, typename Del, typename DelRet, typename DelEndRet>
  void BIRSpecificationVisitor::GetComponents (const T& port,
    DelRet (T::*srcDel)() const,
    DelRet (T::*dstDel) () const,
    DelEndRet (Del::*srcDelEnd)() const,
    DelEndRet (Del::*dstDelEnd)() const,
    std::map<Component, std::string>& output,
    std::set<T>& visited)
  {
    visited.insert (port);
    Udm::Object par = port.parent();
    std::string recepName = port.name();
    std::string parentName = this->ExtractName (par);
    if (Udm::IsDerivedFrom (par.type(), ComponentAssembly::meta))
    {
      std::set<Del> delegates = (port.*dstDel)();
      for (std::set<Del>::const_iterator iter = delegates.begin();
        iter != delegates.end();
        ++iter)
      {
        Del delegate = *iter;
        T srcPort = (delegate.*dstDelEnd)();
        std::string srcPortName = this->ExtractName(srcPort);
        if (std::find (visited.begin(),
          visited.end(),
          srcPort) == visited.end())
        {
          this->GetComponents(srcPort, srcDel, dstDel,
            srcDelEnd, dstDelEnd, output, visited);
        }
      }
      delegates = (port.*srcDel)();
      for (std::set<Del>::const_iterator iter = delegates.begin();
        iter != delegates.end();
        ++iter)
      {
        Del delegate = *iter;
        T dstPort = (delegate.*srcDelEnd)();
        std::string dstPortName = this->ExtractName(dstPort);
        if (std::find (visited.begin(),
          visited.end(),
          dstPort) == visited.end())
        {
          this->GetComponents(dstPort, srcDel, dstDel,
            srcDelEnd, dstDelEnd, output, visited);
        }
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


  void BIRSpecificationVisitor::Visit_PublishConnector(const PublishConnector& pubctor)
  {
    std::string ctor = pubctor.name();

    // Get Publisher
    OutEventPort publisher = this->publishers_[ctor];
    std::map<Component,std::string> publishers;
    this->GetEventSourceComponents (publisher, publishers);

    for (std::map<Component,std::string>::const_iterator
      iter = publishers.begin();
      iter != publishers.end();
    ++iter)
    {
      Component srcComp = iter->first;
      std::string srcPortName = iter->second;

      for (std::multimap<std::string, InEventPort>::const_iterator
        iter = this->consumers_.lower_bound (ctor);
        iter != this->consumers_.upper_bound (ctor);
      ++iter)
      {
        // Get Consumer
        InEventPort consumer = iter->second;
        std::map<Component,std::string> consumers;
        this->GetEventSinkComponents (consumer, consumers);
        for (std::map<Component,std::string>::const_iterator
          iter = consumers.begin();
          iter != consumers.end();
        ++iter)
        {
          Component dstComp = iter->first;
          std::string dstPortName = iter->second;
          std::string source_kind = "EventConsumer";
          std::string dest_kind = "EventPublisher";
          this->CreateConnection (srcComp, srcPortName, dstComp,
            dstPortName, source_kind, dest_kind);
        }
      }
    }
  }

  void BIRSpecificationVisitor::init_bir_arguments ()
  {
    // first create a new system
    this->outfile_ << "system " << "RTBIRSpecification" <<std::endl<< "{" << std::endl;
    // Create all data elements needed for model checking later.
    // 1. component_priority_model
    // 2. component_priority_low
    // 3. component_priority_high
    // 4. component_multithreading*

    for (
      std::map<Component, RealTimeConfiguration>::iterator iter = this->rtc_.begin ();
      iter != this->rtc_.end ();
      ++iter)
    {
      Component comp = (*iter).first;
      RealTimeConfiguration rtc = (*iter).second;
      PriorityModelPolicy pmp = rtc.PriorityModelPolicy_child ();
      if (Udm::null != pmp)
      {
        std::string pmp_model = pmp.priority_model ();
        std::string p_model = pmp_model.compare ("CLIENT_PROPAGATED") == 0? "true":"false";
        this->outfile_ << "boolean " << comp.name () << "_priority_model := " << p_model <<";"<< std::endl;
        this->outfile_ << "int " << comp.name () << "_priority_value := " << pmp.priority_value () <<";"<< std::endl;
      }


      std::set<PriorityBands> bcs = rtc.PriorityBands_children ();

      if (bcs.size () != 0)
      {
        this->outfile_ << "int "<< comp.name () << "_client_priority_low := " << this->get_lowest_priority (rtc) <<";"<< std::endl;
        this->outfile_ << "int "<< comp.name () << "_client_priority_high := " << this->get_highest_priority (rtc) <<";"<< std::endl;
      }

      std::set<ThreadPool> tps = rtc.ThreadPool_kind_children ();

      if (tps.size () != 0)
      {
        int i = 0;
        for (std::set<ThreadPool>::iterator iter = tps.begin ();
          iter != tps.end ();
          ++iter)
        {
          ThreadPool tp = *iter;
          this->outfile_ << "boolean "<< comp.name () << "_allow_request_buffering_" << i << " := " << tp.allow_request_buffering () <<";"<< std::endl;
          this->outfile_ << "int "<< comp.name () << "_max_buffered_requests_" << i << " := " << tp.max_buffered_requests () <<";"<< std::endl;
          this->outfile_ << "int "<< comp.name () << "_stacksize_" << i << " := " << tp.stacksize () <<";"<< std::endl;
          this->outfile_ << "int "<< comp.name () << "_max_buffer_size_" << i << " := " << tp.max_buffer_size () <<";"<< std::endl;
          this->outfile_ << "boolean "<< comp.name () << "_allow_borrowing_" << i++ << " := " << tp.allow_borrowing () <<";"<< std::endl;
        }
      }

    }

    // end of the initizlization section.
    this->outfile_ << std::endl<<std::endl<<std::endl<<std::endl;

  }

  int BIRSpecificationVisitor::get_lowest_priority (RealTimeConfiguration rtc)
  {
    std::set<PriorityBands> bcs = rtc.PriorityBands_children ();
    std::set<PriorityBands>::iterator iter = bcs.begin ();

    int low = (int)(*iter).low ();
    for (;iter != bcs.end ();++iter)
    {
      if (low > (*iter).low () )
        low = (int)(*iter).low ();
    }
    return low;
  }

  int BIRSpecificationVisitor::get_highest_priority (RealTimeConfiguration rtc)
  {

    std::set<PriorityBands> bcs = rtc.PriorityBands_children ();
    std::set<PriorityBands>::iterator iter = bcs.begin ();
    int high = (int)(*iter).high ();

    for (;iter != bcs.end ();++iter)
    {
      if (high < (*iter).high () )
        high = (int)(*iter).high ();
    }
    return high;
  }


  void BIRSpecificationVisitor::open_thread (std::string comp_name)
  {
    this->outfile_ << "active thread " << comp_name << "()" <<std::endl<<"{" <<std::endl;
      this->outfile_ << "loc loc0: live {}" << std::endl;
  }

  bool BIRSpecificationVisitor::component_traversed (std::string comp_name)
  {
    std::list<std::string>::iterator iter =
        std::find (this->trav_comps_.begin(), this->trav_comps_.end(), comp_name);
    if (iter == this->trav_comps_.end ())
    {
      this->trav_comps_.push_front (comp_name);
      return false;
    }
    return true;
  }


  void BIRSpecificationVisitor::CreateConnection (const Component& srcComp,
    const std::string& srcPortName,
    const Component& dstComp,
    const std::string& dstPortName,
    const std::string& source_kind,
    const std::string& dest_kind)
  {
    // Dump source component.

    // 1. Create a new active thread for the source component.
    // 2. Create a loc function to check priority_model for this component.
    if (!this->component_traversed (srcComp.name () ))
    {
      this->open_thread (srcComp.name () );

      // priority model false indicates s_declared.
      this->outfile_ << "when !" << srcComp.name () << "_priority_model do {}" << std::endl;
      this->outfile_ << "goto loc0;" << std::endl;
      this->outfile_ << "}"<<std::endl<<std::endl;
    }

    if (!this->component_traversed (dstComp.name () ))
    {
      // Dump destination component.
      this->open_thread (dstComp.name ());
      this->outfile_ << "when " << dstComp.name () << "_priority_model do {}" << std::endl;
      this->outfile_ << "goto loc1;" << std::endl;
      this->outfile_ << "loc loc1: live {}" << std::endl;
      this->outfile_ << "do {assert " << dstComp.name () << "_client_priority_low < " << srcComp.name () << "_priority_value;}" << std::endl;
      this->outfile_ << "goto loc0;" << std::endl;
      this->outfile_ << "}"<<std::endl<<std::endl;
    }

  }

  // RealTimeConfiguration read.
  void BIRSpecificationVisitor::Visit_RealTimeConfiguration(const RealTimeConfiguration &rtc)
  {

    std::set<ComponentQoS> comp_qos = rtc.srcComponentQoS ();
    for (std::set<ComponentQoS>::iterator iter = comp_qos.begin();
      iter != comp_qos.end();
      ++iter)
    {
      ComponentBase compbase = (*iter).srcComponentQoS_end ();
      if (Udm::null == compbase )
      {
        throw (udm_exception ("BIRSpecificationVisitor::Visit_RealTimeConfiguration ():Component null."));
      }
      else
      {
        if (Udm::IsDerivedFrom (compbase.type(), ComponentRef::meta))
        {
          ComponentRef compref = ComponentRef::Cast (compbase);
          this->rtc_[compref.ref ()] = rtc;
        }
        else if (Udm::IsDerivedFrom (compbase.type(), Component::meta))
        {
          Component comp = Component::Cast (compbase);
          this->rtc_[comp] = rtc;
        }

        // For each component,
      }
    }

  }


  BIRSpecificationVisitor::~BIRSpecificationVisitor ()
  {
    this->outfile_ << std::endl<<std::endl;
    this->outfile_ << "}";
    this->outfile_.close ();
  }
  }

