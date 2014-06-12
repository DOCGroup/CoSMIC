// $Id$

#include "StdAfx.h"
#include "Participant_Visitor.h"
#include "Topic_Locator.h"

#include "DQML/DQML.h"

#include "game/xml/Swap_Fragment.h"

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

//
// visit_Participant
//
void Participant_Visitor::visit_Participant (DQML::Participant_in item)
{
  if (item->has_UserDataQosPolicy ())
    item->get_UserDataQosPolicy ()->accept (this);

  if (item->has_EntityFactoryQosPolicy ())
    item->get_EntityFactoryQosPolicy ()->accept (this);

  // watchdog_scheduling goes here
  // listener_scheduling goes here

  // Gather all the topics and then visit them. When we visit the topic,
  // we are going to write it to the Xml document.
  std::set <DQML::TopicQos> topics;

  Topic_Locator topic_locator (topics);
  item->accept (&topic_locator);

  std::for_each (GAME::Mga::make_impl_iter (topics.begin ()),
                 GAME::Mga::make_impl_iter (topics.end ()),
                 boost::bind (&DQML::TopicQos::impl_type::accept, _1, this));

  // publisher(s) go here
  GAME::Mga::Collection_T <DQML::PublisherQos> publishers = item->get_PublisherQoss ();
  for (auto & publisher : publishers)
    publisher->accept (this);

  // subscribers(s) go here
  GAME::Mga::Collection_T <DQML::SubscriberQos> subscribers = item->get_SubscriberQoss ();
  for (auto & subscriber : subscribers)
    subscriber->accept (this);

  // datawriter(s) go here
  GAME::Mga::Collection_T <DQML::DataWriterQos> datawriters = item->get_DataWriterQoss ();
  for (auto & datawriter : datawriters)
    datawriter->accept (this);

  // datareaders(s) go here
  GAME::Mga::Collection_T <DQML::DataReaderQos> datareaders = item->get_DataReaderQoss ();
  for (auto & datareader : datareaders)
    datareader->accept (this);
}

//
// visit_EntityFactoryQosPolicy
//
void Participant_Visitor::
visit_EntityFactoryQosPolicy (DQML::EntityFactoryQosPolicy_in item)
{
  Fragment entity_factory = this->current_.create_element ("entity_factory");
  entity_factory.set_attribute ("autoenable_created_entities", item->autoenable_created_entities ());
}

//
// visit_UserDataQosPolicy
//
void Participant_Visitor::
visit_UserDataQosPolicy (DQML::UserDataQosPolicy_in item)
{
  Fragment user_data = this->current_.create_element ("user_data");
}

//
// visit_TopicQos
//
void Participant_Visitor::visit_TopicQos (DQML::TopicQos_in item)
{
  Swap_Fragment topic (this->current_, this->current_.create_element ("topic"));
  topic.set_attribute ("name", item->name ());

  //<xsd:element name="topic_data" type="TopicDataQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_TopicDataQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("topic_data"));
    item->get_TopicDataQosPolicy ()->accept (this);
  }

  //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DurabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("durability"));
    item->get_DurabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="durability_service" type="DurabilityServiceQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DurabilityServiceQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("durability_service"));
    item->get_DurabilityServiceQosPolicy ()->accept (this);
  }

  //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DeadlineQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("deadline"));
    item->get_DeadlineQosPolicy ()->accept (this);
  }

  //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LatencyBudgetQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("latency_budget"));
    item->get_LatencyBudgetQosPolicy ()->accept (this);
  }

  //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LivelinessQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("liveliness"));
    item->get_LivelinessQosPolicy ()->accept (this);
  }

  //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ReliabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("reliability"));
    item->get_ReliabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DestinationOrderQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("destination_order"));
    item->get_DestinationOrderQosPolicy ()->accept (this);
  }

  //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_HistoryQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("history"));
    item->get_HistoryQosPolicy ()->accept (this);
  }

  //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ResourceLimitsQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("resource_limits"));
    item->get_ResourceLimitsQosPolicy ()->accept (this);
  }

  //<xsd:element name="transport_priority" type="TransportPriorityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_TransportPriorityQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("transport_priority"));
    item->get_TransportPriorityQosPolicy  ()->accept (this);
  }

  //<xsd:element name="lifespan" type="LifespanQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LifespanQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("lifespan"));
    item->get_LifespanQosPolicy ()->accept (this);
  }

  //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_OwnershipQosPolicy ())
  {
    Swap_Fragment f (this->current_, this->current_.create_element ("ownership"));
    item->get_OwnershipQosPolicy ()->accept (this);
  }
}

//
// visit_GroupDataQosPolicy
//
void Participant_Visitor::visit_GroupDataQosPolicy (DQML::GroupDataQosPolicy item)
{

}

//
// visit_TopicDataQosPolicy
//
void Participant_Visitor::visit_TopicDataQosPolicy (DQML::TopicDataQosPolicy_in item)
{

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
  //this->current_.set_attribute ("synchronous", item->synchronous ());
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
// visit_PublisherQos
//
void Participant_Visitor::
visit_PublisherQos (DQML::PublisherQos_in item)
{
  Fragment publisher (this->current_.create_element ("publisher"));
  publisher.set_attribute ("name", item->name ());

  //<xsd:element name="presentation" type="PresentationQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_PresentationQosPolicy ())
  {
    Swap_Fragment f (this->current_, publisher.create_element ("presentation"));
    item->get_PresentationQosPolicy ()->accept (this);
  }

  //<xsd:element name="partition" type="PartitionQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_PartitionQosPolicy ())
  {
    Swap_Fragment f (this->current_, publisher.create_element ("partition"));
    item->get_PartitionQosPolicy ()->accept (this);
  }

  //<xsd:element name="group_data" type="GroupDataQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_GroupDataQosPolicy ())
  {
    Swap_Fragment f (this->current_, publisher.create_element ("group_data"));
    item->get_GroupDataQosPolicy ()->accept (this);
  }

  //<xsd:element name="entity_factory" type="EntityFactoryQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_EntityFactoryQosPolicy ())
  {
    Swap_Fragment f (this->current_, publisher.create_element ("entity_factory"));
    item->get_EntityFactoryQosPolicy ()->accept (this);
  }
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
  if (item->has_PresentationQosPolicy ())
  {
    Swap_Fragment f (this->current_, subscriber.create_element ("presentation"));
    item->get_PresentationQosPolicy ()->accept (this);
  }

  //<xsd:element name="partition" type="PartitionQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_PartitionQosPolicy ())
  {
    Swap_Fragment f (this->current_, subscriber.create_element ("partition"));
    item->get_PartitionQosPolicy ()->accept (this);
  }

  //<xsd:element name="group_data" type="GroupDataQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_GroupDataQosPolicy ())
  {
    Swap_Fragment f (this->current_, subscriber.create_element ("group_data"));
    item->get_GroupDataQosPolicy ()->accept (this);
  }

  //<xsd:element name="entity_factory" type="EntityFactoryQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_EntityFactoryQosPolicy ())
  {
    Swap_Fragment f (this->current_, subscriber.create_element ("entity_factory"));
    item->get_EntityFactoryQosPolicy ()->accept (this);
  }

  //<xsd:element name="share" type="ShareQosPolicy" minOccurs="0" maxOccurs="1" />
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
}

//
// visit_DataWriterQos
//
void Participant_Visitor::visit_DataWriterQos (DQML::DataWriterQos_in item)
{
  Fragment writer (this->current_.create_element ("datawriter"));
  writer.set_attribute ("name", item->name ());

  std::vector <DQML::PublisherConnection> publisher_conn;
  if (item->src_PublisherConnection (publisher_conn))
  {
    DQML::PublisherQos publisher = publisher_conn.front ()->dst_PublisherQos ();
    writer.set_attribute ("publisher", publisher->name ());
  }

  if (item->has_TopicQosReference ())
  {
    DQML::TopicQos topic = item->get_TopicQosReference ()->get_TopicQos ();

    if (!topic.is_nil ())
      writer.set_attribute ("topic", topic->name ());
  }

  //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DurabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("durability"));
    item->get_DurabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DeadlineQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("deadline"));
    item->get_DeadlineQosPolicy ()->accept (this);
  }

  //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LatencyBudgetQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("latency_budget"));
    item->get_LatencyBudgetQosPolicy ()->accept (this);
  }

  //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LivelinessQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("liveliness"));
    item->get_LivelinessQosPolicy ()->accept (this);
  }

  //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ReliabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("reliability"));
    item->get_ReliabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DestinationOrderQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("destination_order"));
    item->get_DestinationOrderQosPolicy ()->accept (this);
  }

  //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_HistoryQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("history"));
    item->get_HistoryQosPolicy ()->accept (this);
  }

  //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ResourceLimitsQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("resource_limits"));
    item->get_ResourceLimitsQosPolicy ()->accept (this);
  }

  //<xsd:element name="transport_priorty" type="TransportPriorityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_TransportPriorityQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("transport_priorty"));
    item->get_TransportPriorityQosPolicy ()->accept (this);
  }

  //<xsd:element name="lifespan" type="LifespanQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LifespanQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("lifespan"));
    item->get_LifespanQosPolicy ()->accept (this);
  }

  //<xsd:element name="user_data" type="UserDataQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_UserDataQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("user_data"));
    item->get_UserDataQosPolicy ()->accept (this);
  }

  //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_OwnershipQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("ownership"));
    item->get_OwnershipQosPolicy ()->accept (this);
  }

  //<xsd:element name="ownership_strength" type="OwnershipStrengthQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_OwnershipStrengthQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("ownership_strength"));
    item->get_OwnershipStrengthQosPolicy ()->accept (this);
  }

  //<xsd:element name="writer_data_lifecycle" type="WriterDataLifecycleQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_WriterDataLifecycleQosPolicy ())
  {
    Swap_Fragment f (this->current_, writer.create_element ("writer_data_lifecycle"));
    item->get_WriterDataLifecycleQosPolicy ()->accept (this);
  }
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
  //<xsd:attribute name="autopurge_suspended_samples_delay" type="Duration_t" />
  //<xsd:attribute name="autounregister_instance_delay" type="Duration_t" />
  this->current_.set_attribute ("autodispose_unregistered_instances", item->autodispose_unregistered_instances ());
}

//
// visit_DataReaderQos
//
void Participant_Visitor::visit_DataReaderQos (DQML::DataReaderQos_in item)
{
  Fragment reader (this->current_.create_element ("datareader"));
  reader.set_attribute ("name", item->name ());

  std::vector <DQML::SubscriberConnection> subscriber_conn;
  if (item->src_SubscriberConnection (subscriber_conn))
  {
    DQML::SubscriberQos subscriber = subscriber_conn.front ()->dst_SubscriberQos ();
    reader.set_attribute ("subscriber", subscriber->name ());
  }

  if (item->has_TopicQosReference ())
  {
    DQML::TopicQos topic = item->get_TopicQosReference ()->get_TopicQos ();

    if (!topic.is_nil ())
      reader.set_attribute ("topic", topic->name ());
  }

  //<xsd:element name="durability" type="DurabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DurabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("durability"));
    item->get_DurabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="deadline" type="DeadlineQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DeadlineQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("deadline"));
    item->get_DeadlineQosPolicy ()->accept (this);
  }

  //<xsd:element name="latency_budget" type="LatencyBudgetQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LatencyBudgetQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("latency_budget"));
    item->get_LatencyBudgetQosPolicy ()->accept (this);
  }

  //<xsd:element name="liveliness" type="LivelinessQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_LivelinessQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("liveliness"));
    item->get_LivelinessQosPolicy ()->accept (this);
  }

  //<xsd:element name="reliability" type="ReliabilityQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ReliabilityQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("reliability"));
    item->get_ReliabilityQosPolicy ()->accept (this);
  }

  //<xsd:element name="destination_order" type="DestinationOrderQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_DestinationOrderQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("destination_order"));
    item->get_DestinationOrderQosPolicy ()->accept (this);
  }

  //<xsd:element name="history" type="HistoryQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_HistoryQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("history"));
    item->get_HistoryQosPolicy ()->accept (this);
  }

  //<xsd:element name="resource_limits" type="ResourceLimitsQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ResourceLimitsQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("resource_limits"));
    item->get_ResourceLimitsQosPolicy ()->accept (this);
  }

  //<xsd:element name="user_data" type="UserDataQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_UserDataQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("user_data"));
    item->get_UserDataQosPolicy ()->accept (this);
  }

  //<xsd:element name="ownership" type="OwnershipQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_OwnershipQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("ownership"));
    item->get_OwnershipQosPolicy ()->accept (this);
  }

  //<xsd:element name="time_based_filter" type="TimeBasedFilterQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_TimeBasedFilterQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("time_based_filter"));
    item->get_TimeBasedFilterQosPolicy ()->accept (this);
  }

  //<xsd:element name="reader_data_lifecycle" type="ReaderDataLifecycleQosPolicy" minOccurs="0" maxOccurs="1" />
  if (item->has_ReaderDataLifecycleQosPolicy ())
  {
    Swap_Fragment f (this->current_, reader.create_element ("reader_data_lifecycle"));
    item->get_ReaderDataLifecycleQosPolicy ()->accept (this);
  }

  //<xsd:element name="subscription_keys" type="SubscriptionKeyQosPolicy" minOccurs="0" maxOccurs="1" />

  //<xsd:element name="reader_lifespan" type="ReaderLifespanQosPolicy" minOccurs="0" maxOccurs="1" />

  //<xsd:element name="share" type="ShareQosPolicy" minOccurs="0" maxOccurs="1" />

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
  //<xsd:attribute name="enable_invalid_samples" type="xsd:boolean" />
}

}
