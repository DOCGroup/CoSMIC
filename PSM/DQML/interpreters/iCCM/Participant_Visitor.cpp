// $Id$

#include "StdAfx.h"
#include "Participant_Visitor.h"
#include "Topic_Locator.h"

#include "DQML/DQML.h"

#include "game/xml/Swap_Fragment.h"

#include <boost/algorithm/string.hpp>
#include "boost/bind.hpp"
#include <algorithm>

namespace DQML_iCCM
{

  using GAME::Xml::String;
  using GAME::Xml::Fragment;
  using GAME::Xml::Swap_Fragment;
  using GAME::Mga::Iterator;

  //
  // Participant_Visitor
  //
  Participant_Visitor::Participant_Visitor (GAME::Xml::Document & doc)
    : doc_ (doc)
  {
    // Create the document, which includes setting the XML version.
    this->doc_.create ("http://cuts.cs.iupui.edu/iccm", "dds:participant");
    this->doc_->setXmlVersion (String ("1.0"));

    this->current_ = this->doc_.root ();

    this->current_->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
      String ("xmlns:xsi"),
      String ("http://www.w3.org/2001/XMLSchema-instance"));

    this->current_->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
      String ("xmlns:xmi"),
      String ("http://www.omg.org/XMI"));

    this->current_->setAttribute (String ("xsi:schemaLocation"),
      String ("http://cuts.cs.iupui.edu/iccm dds.xsd"));

  }

  //
  // Participant_Visitor
  //
  Participant_Visitor::~Participant_Visitor (void)
  {

  }

  template <typename T, typename ITEM>
  void Participant_Visitor::
  handle_element (ITEM & item, const std::string & label)
  {
    auto collection = item->children <T> ();
    if (collection.count () != 0)
    {
      Swap_Fragment f (this->current_, this->current_.create_element (label));
      collection.first ()->accept (this);
    }
  }

  template <typename COLLECTION>
  void Participant_Visitor::
  handle_main_qos (COLLECTION & collection, const std::string & comment)
  {
    if (collection.count () == 0)
      return;

    auto new_comment = this->doc_->createComment (String (comment));
    this->current_->appendChild (new_comment);

    for (auto & item : collection)
      item->accept (this);
  }

  //
  // visit_Participant
  //
  void Participant_Visitor::visit_Participant (DQML::Participant_in item)
  {
    xercesc::DOMComment * comment = this->doc_->createComment (String (" BEGIN DDS::DomainParticipantQoS parameters "));
    this->current_->appendChild (comment);

    this->handle_element <DQML::UserDataQosPolicy> (item, "user_data");
    this->handle_element <DQML::EntityFactoryQosPolicy> (item, "entity_factory");

    comment = this->doc_->createComment (String (" BEGIN DDS::DomainParticipantQoS (SchedulingQosPolicy) parameters "));
    this->current_->appendChild (comment);

    this->handle_element <DQML::WatchdogSchedulingQosPolicy> (item, "watchdog_scheduling");
    this->handle_element <DQML::ListenerSchedulingQosPolicy> (item, "listener_scheduling");

    // Gather all the topics and then visit them. When we visit the topic,
    // we are going to write it to the Xml document.
    // topic(s) go here
    std::set <DQML::TopicQos> topics;
    Topic_Locator topic_locator (topics);
    item->accept (&topic_locator);

    if (topics.size () != 0)
    {
      comment = this->doc_->createComment (String (" BEGIN DDS::TopicQoS parameters "));
      this->current_->appendChild (comment);
    }

    for (auto topic : topics)
      topic->accept (this);

    this->handle_main_qos (item->get_PublisherQoss (), " BEGIN DDS::PublisherQoS parameters ");
    this->handle_main_qos (item->get_SubscriberQoss (), " BEGIN DDS::SubscriberQoS parameters ");
    this->handle_main_qos (item->get_DataWriterQoss (), " BEGIN DDS::DataWriterQoS parameters ");
    this->handle_main_qos (item->get_DataReaderQoss (), " BEGIN DDS::DataReaderQoS parameters ");
  }

  //
  // visit_TopicQos
  //
  void Participant_Visitor::
    visit_TopicQos (DQML::TopicQos_in item)
  {
    Swap_Fragment topic (this->current_, this->current_.create_element ("topic"));
    topic.set_attribute ("name", item->name ());

    //<xsd:element name="topic_data" type="TopicDataQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::TopicDataQosPolicy> (item, "topic_data");

    //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DurabilityQosPolicy> (item, "durability");

    //<xsd:element name="durability_service" type="DurabilityServiceQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DurabilityServiceQosPolicy> (item, "durability_service");

    //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DeadlineQosPolicy> (item, "deadline");

    //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LatencyBudgetQosPolicy> (item, "latency_budget");

    //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LivelinessQosPolicy> (item, "liveliness");

    //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ReliabilityQosPolicy> (item, "reliability");

    //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DestinationOrderQosPolicy> (item, "destination_order");

    //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::HistoryQosPolicy> (item, "history");

    //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ResourceLimitsQosPolicy> (item, "resource_limits");

    //<xsd:element name="transport_priority" type="TransportPriorityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::TransportPriorityQosPolicy> (item, "transport_priority");

    //<xsd:element name="lifespan" type="LifespanQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LifespanQosPolicy> (item, "lifespan");

    //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::OwnershipQosPolicy> (item, "ownership");
  }

  //
  // visit_PublisherQos
  //
  void Participant_Visitor::
    visit_PublisherQos (DQML::PublisherQos_in item)
  {
    Fragment publisher (this->current_.create_element ("publisher"));
    publisher.set_attribute ("name", item->name ());

    //<xsd:element name="presentation" type="PresentationQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::PresentationQosPolicy> (item, "presentation");

    //<xsd:element name="partition" type="PartitionQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::PartitionQosPolicy> (item, "partition");

    //<xsd:element name="group_data" type="GroupDataQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::GroupDataQosPolicy> (item, "group_data");

    //<xsd:element name="entity_factory" type="EntityFactoryQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::EntityFactoryQosPolicy> (item, "entity_factory");
  }

  //
  // visit_SubscriberQos
  //
  void Participant_Visitor::
    visit_SubscriberQos (DQML::SubscriberQos_in item)
  {
    Fragment subscriber (this->current_.create_element ("subscriber"));
    subscriber.set_attribute ("name", item->name ());

    //<xsd:element name="presentation" type="PresentationQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::PresentationQosPolicy> (item, "presentation");

    //<xsd:element name="partition" type="PartitionQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::PartitionQosPolicy> (item, "partition");

    //<xsd:element name="group_data" type="GroupDataQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::GroupDataQosPolicy> (item, "group_data");

    //<xsd:element name="entity_factory" type="EntityFactoryQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::EntityFactoryQosPolicy> (item, "entity_factory");

    //<xsd:element name="share" type="ShareQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ShareQosPolicy> (item, "share");
  }

  //
  // visit_DataWriterQos
  //
  void Participant_Visitor::visit_DataWriterQos (DQML::DataWriterQos_in item)
  {
    Fragment writer (this->current_.create_element ("datawriter"));
    writer.set_attribute ("name", item->name ());
    writer.set_attribute ("topic_name", item->topic_name ());
    writer.set_attribute ("isinstance", item->IsInstance ());
    writer.set_attribute ("isprivate", item->isprivate ());

    GAME::Mga::Collection_T <DQML::PublisherConnection> publisher_conn =
      item->src_of_PublisherConnection ();
    if (publisher_conn.count ())
    {
      DQML::PublisherQos publisher = publisher_conn.first ()->dst_PublisherQos ();
      writer.set_attribute ("publisher", publisher->name ());
    }

    if (item->has_TopicQosReference ())
    {
      DQML::TopicQos topic = item->get_TopicQosReference ()->refers_to_TopicQos ();

      if (!topic.is_nil ())
        writer.set_attribute ("topic", topic->name ());
    }

    //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DurabilityQosPolicy> (item, "durability");

    //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DeadlineQosPolicy> (item, "deadline");

    //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LatencyBudgetQosPolicy> (item, "latency_budget");

    //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LivelinessQosPolicy> (item, "liveliness");

    //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ReliabilityQosPolicy> (item, "reliability");

    //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DestinationOrderQosPolicy> (item, "destination_order");

    //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::HistoryQosPolicy> (item, "history");

    //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ResourceLimitsQosPolicy> (item, "resource_limits");

    //<xsd:element name="transport_priorty" type="TransportPriorityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::TransportPriorityQosPolicy> (item, "transport_priority");

    //<xsd:element name="lifespan" type="LifespanQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LifespanQosPolicy> (item, "lifespan");

    //<xsd:element name="user_data" type="UserDataQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::UserDataQosPolicy> (item, "user_data");

    //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::OwnershipQosPolicy> (item, "ownership");

    //<xsd:element name="ownership_strength" type="OwnershipStrengthQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::OwnershipStrengthQosPolicy> (item, "ownership_strength");

    //<xsd:element name="writer_data_lifecycle" type="WriterDataLifecycleQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::WriterDataLifecycleQosPolicy> (item, "writer_data_lifecycle");
  }

  //
  // visit_DataReaderQos
  //
  void Participant_Visitor::visit_DataReaderQos (DQML::DataReaderQos_in item)
  {
    Fragment reader (this->current_.create_element ("datareader"));
    reader.set_attribute ("name", item->name ());
    reader.set_attribute ("isprivate", item->isprivate ());

    GAME::Mga::Collection_T <DQML::SubscriberConnection> subscriber_conn =
      item->src_of_SubscriberConnection ();

    if (subscriber_conn.count ())
    {
      DQML::SubscriberQos subscriber = subscriber_conn.first ()->dst_SubscriberQos ();
      reader.set_attribute ("subscriber", subscriber->name ());
    }

    if (item->has_TopicQosReference ())
    {
      DQML::TopicQos topic = item->get_TopicQosReference ()->refers_to_TopicQos ();

      if (!topic.is_nil ())
        reader.set_attribute ("topic", topic->name ());
    }

    //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DurabilityQosPolicy> (item, "durability");

    //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DeadlineQosPolicy> (item, "deadline");

    //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LatencyBudgetQosPolicy> (item, "latency_budget");

    //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::LivelinessQosPolicy> (item, "liveliness");

    //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ReliabilityQosPolicy> (item, "reliability");

    //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::DestinationOrderQosPolicy> (item, "destination_order");

    //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::HistoryQosPolicy> (item, "history");

    //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ResourceLimitsQosPolicy> (item, "resource_limits");

    //<xsd:element name="user_data" type="UserDataQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::UserDataQosPolicy> (item, "user_data");

    //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::OwnershipQosPolicy> (item, "ownership");

    //<xsd:element name="time_based_filter" type="TimeBasedFilterQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::TimeBasedFilterQosPolicy> (item, "time_based_filter");

    //<xsd:element name="reader_data_lifecycle" type="ReaderDataLifecycleQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ReaderDataLifecycleQosPolicy> (item, "reader_data_lifecycle");

    //<xsd:element name="subscription_keys" type="SubscriptionKeyQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::SubscriptionKeyQosPolicy> (item, "subscription_keys");

    //<xsd:element name="reader_lifespan" type="ReaderLifespanQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ReaderLifespanQosPolicy> (item, "reader_lifespan");

    //<xsd:element name="share" type="ShareQosPolicy" minOccurs="0" maxOccurs="1" />
    this->handle_element <DQML::ShareQosPolicy> (item, "share");
  }

  //
  // stringseq_splitter
  //
  void Participant_Visitor::stringseq_splitter (std::string & str)
  {
    std::vector<std::string> parts;
    boost::split (parts , str , boost::is_any_of ("."));
    for (std::string part : parts)
    {
      Fragment item_string (this->current_.create_element ("item"));
      item_string->setTextContent (String (part));
    }
  }

  //
  // visit_GroupDataQosPolicy
  //
  void Participant_Visitor::visit_GroupDataQosPolicy (DQML::GroupDataQosPolicy item)
  {
    //<!-- xsd:element name="value" type="xsd:base64Binary" minOccurs="0" maxOccurs="1" / -->
  }

  //
  // visit_TopicDataQosPolicy
  //
  void Participant_Visitor::visit_TopicDataQosPolicy (DQML::TopicDataQosPolicy_in item)
  {
    //<!-- xsd:element name="value" type="xsd:base64Binary" minOccurs="0" maxOccurs="1" / -->
  }

  //
  // visit_DurabilityQosPolicy
  //
  void Participant_Visitor::
  visit_DurabilityQosPolicy (DQML::DurabilityQosPolicy_in item)
  {
    this->current_.set_attribute ("kind", item->kind ());
  }

  //
  // visit_DurabilityServiceQosPolicy
  //
  void Participant_Visitor::
  visit_DurabilityServiceQosPolicy (DQML::DurabilityServiceQosPolicy_in item)
  {
    this->current_.set_attribute ("history_depth", item->history_depth ());
    this->current_.set_attribute ("max_samples", item->max_samples ());
    this->current_.set_attribute ("max_instances", item->max_instances ());
    this->current_.set_attribute ("max_samples_per_instance", item->max_samples_per_instance ());
    this->current_.set_attribute ("history_depth", item->history_depth ());
    this->current_.set_attribute ("service_cleanup_delay", item->service_cleanup_delay ());
  }

  //
  // visit_LatencyBudgetQosPolicy
  //
  void Participant_Visitor::
  visit_LatencyBudgetQosPolicy (DQML::LatencyBudgetQosPolicy_in item)
  {
    this->current_.set_attribute ("duration", item->duration ());
  }

  //
  // visit_DeadlineQosPolicy
  //
  void Participant_Visitor::
  visit_DeadlineQosPolicy (DQML::DeadlineQosPolicy_in item)
  {
    this->current_.set_attribute ("period", item->period ());
  }

  //
  // visit_LivelinessQosPolicy
  //
  void Participant_Visitor::
  visit_LivelinessQosPolicy (DQML::LivelinessQosPolicy_in item)
  {
    this->current_.set_attribute ("lease_duration", item->lease_duration ());
    this->current_.set_attribute ("kind", item->liveliness_kind ());
  }

  //
  // visit_ReliabilityQosPolicy
  //
  void Participant_Visitor::
  visit_ReliabilityQosPolicy (DQML::ReliabilityQosPolicy_in item)
  {
    this->current_.set_attribute ("kind", item->reliability_kind ());
    this->current_.set_attribute ("synchronous", item->synchronous ());
    this->current_.set_attribute ("max_blocking_time", item->max_blocking_time ());
  }

  //
  // visit_DestinationOrderQosPolicy
  //
  void Participant_Visitor::
  visit_DestinationOrderQosPolicy (DQML::DestinationOrderQosPolicy_in item)
  {
    this->current_.set_attribute ("kind", item->dest_order_kind ());
  }

  //
  // visit_HistoryQosPolicy
  //
  void Participant_Visitor::
  visit_HistoryQosPolicy (DQML::HistoryQosPolicy_in item)
  {
    this->current_.set_attribute ("kind", item->history_kind ());
    this->current_.set_attribute ("depth", item->history_depth ());
  }

  //
  // visit_ResourceLimitsQosPolicy
  //
  void Participant_Visitor::
  visit_ResourceLimitsQosPolicy (DQML::ResourceLimitsQosPolicy_in item)
  {
    this->current_.set_attribute ("max_samples", item->max_samples ());
    this->current_.set_attribute ("max_instances", item->max_instances ());
    this->current_.set_attribute ("max_samples_per_instance", item->max_samples_per_instance ());
  }

  //
  // visit_TransportPriorityQosPolicy
  //
  void Participant_Visitor::
  visit_TransportPriorityQosPolicy (DQML::TransportPriorityQosPolicy_in item)
  {
    this->current_.set_attribute ("value", item->transport_value ());
  }

  //
  // visit_LifespanQosPolicy
  //
  void Participant_Visitor::
  visit_LifespanQosPolicy (DQML::LifespanQosPolicy_in item)
  {
    this->current_.set_attribute ("duration", item->lifespan_duration ());
  }

  //
  // visit_OwnershipQosPolicy
  //
  void Participant_Visitor::
  visit_OwnershipQosPolicy (DQML::OwnershipQosPolicy_in item)
  {
    this->current_.set_attribute ("kind", item->ownership_kind ());
  }

  //
  // visit_SchedulingPriorityQosPolicy
  //
  void Participant_Visitor::
  visit_SchedulingPriorityQosPolicy (DQML::SchedulingPriorityQosPolicy_in item)
  {
    Fragment scheduling_priority (this->current_.create_element ("scheduling_priority_kind"));
    scheduling_priority.set_attribute ("kind", item->scheduling_priority_kind ());
  }

  //
  // visit_SchedulingClassQosPolicy
  //
  void Participant_Visitor::
  visit_SchedulingClassQosPolicy (DQML::SchedulingClassQosPolicy_in item)
  {
    Fragment scheduling_class (this->current_.create_element ("scheduling_class"));
    scheduling_class.set_attribute ("kind", item->scheduling_class_kind ());
  }

  //
  // visit_SchedulingQosPolicy
  //
  void Participant_Visitor::
  visit_SchedulingQosPolicy (DQML::SchedulingQosPolicy_in item)
  {
    this->current_.set_attribute ("scheduling_priority", item->scheduling_priority ());

    if (item->has_SchedulingClassQosPolicy ())
      item->get_SchedulingClassQosPolicy ()->accept (this);

    if (item->has_SchedulingPriorityQosPolicy ())
      item->get_SchedulingPriorityQosPolicy ()->accept (this);
  }

  //
  // visit_ListenerSchedulingQosPolicy
  //
  void Participant_Visitor::
  visit_ListenerSchedulingQosPolicy (DQML::ListenerSchedulingQosPolicy_in item)
  {
    this->visit_SchedulingQosPolicy (item);
  }

  //
  // visit_WatchdogSchedulingQosPolicy
  //
  void Participant_Visitor::
  visit_WatchdogSchedulingQosPolicy (DQML::WatchdogSchedulingQosPolicy_in item)
  {
    this->visit_SchedulingQosPolicy (item);
  }

  //
  // visit_ShareQosPolicy
  //
  void Participant_Visitor::
  visit_ShareQosPolicy (DQML::ShareQosPolicy_in item)
  {
    this->current_.set_attribute ("name", item->name ());
    this->current_.set_attribute ("enable", item->share_qos_enable ());
  }

  //
  // visit_SubscriptionKeyQosPolicy
  //
  void Participant_Visitor::
  visit_SubscriptionKeyQosPolicy (DQML::SubscriptionKeyQosPolicy_in item)
  {      
    // <name><item></item><item></item></name>
    Swap_Fragment f (this->current_, this->current_.create_element ("name"));
    this->stringseq_splitter (item->key_list ());
  }

  //
  // visit_ReaderLifespanQosPolicy
  //
  void Participant_Visitor::
  visit_ReaderLifespanQosPolicy (DQML::ReaderLifespanQosPolicy_in item)
  {
    this->current_.set_attribute ("duration", item->duration ());
    this->current_.set_attribute ("use_lifespan", item->use_lifespan ());
  }

  //
  // visit_PresentationQosPolicy
  //
  void Participant_Visitor::
  visit_PresentationQosPolicy (DQML::PresentationQosPolicy_in item)
  {
    this->current_.set_attribute ("access_scope", item->access_scope ());
    this->current_.set_attribute ("coherent_access", item->coherent_access ());
    this->current_.set_attribute ("ordered_access", item->ordered_access ());
  }

  //
  // visit_PartitionQosPolicy
  //
  void Participant_Visitor::
  visit_PartitionQosPolicy (DQML::PartitionQosPolicy_in item)
  {
    // <name><item></item><item></item></name>
    Swap_Fragment f (this->current_, this->current_.create_element ("name"));
    this->stringseq_splitter (item->partition_name ());
  }

  //
  // visit_OwnershipStrengthQosPolicy
  //
  void Participant_Visitor::
  visit_OwnershipStrengthQosPolicy (DQML::OwnershipStrengthQosPolicy_in item)
  {
    this->current_.set_attribute ("value", item->ownership_value ());
  }

  //
  // visit_WriterDataLifecycleQosPolicy
  //
  void Participant_Visitor::
  visit_WriterDataLifecycleQosPolicy (DQML::WriterDataLifecycleQosPolicy_in item)
  {
    this->current_.set_attribute ("autopurge_suspended_samples_delay", item->autopurge_suspended_samples_delay ());
    this->current_.set_attribute ("autounregister_instance_delay", item->autounregister_instance_delay ());
    this->current_.set_attribute ("autodispose_unregistered_instances", item->autodispose_unregistered_instances ());
  }

  //
  // visit_EntityFactoryQosPolicy
  //
  void Participant_Visitor::
  visit_EntityFactoryQosPolicy (DQML::EntityFactoryQosPolicy_in item)
  {
    this->current_.set_attribute ("autoenable_created_entities", item->autoenable_created_entities ());
  }

  //
  // visit_UserDataQosPolicy
  //
  void Participant_Visitor::
  visit_UserDataQosPolicy (DQML::UserDataQosPolicy_in item)
  {
    //<!-- xsd:element name="value" type="xsd:base64Binary" minOccurs="0" maxOccurs="1" / -->
  }

  //
  // visit_TimeBasedFilterQosPolicy
  //
  void Participant_Visitor::
  visit_TimeBasedFilterQosPolicy (DQML::TimeBasedFilterQosPolicy_in item)
  {
    this->current_.set_attribute ("minimum_separation", item->minimum_separation ());
  }

  //
  // visit_ReaderDataLifecycleQosPolicy
  //
  void Participant_Visitor::
  visit_ReaderDataLifecycleQosPolicy (DQML::ReaderDataLifecycleQosPolicy_in item)
  {
    this->current_.set_attribute ("autopurge_nowriter_samples_delay", item->autopurge_nowriter_samples_delay ());
    this->current_.set_attribute ("autopurge_disposed_samples_delay", item->autopurge_disposed_samples_delay ());
    this->current_.set_attribute ("enable_invalid_samples", item->enable_invalid_samples ());
  }
}
