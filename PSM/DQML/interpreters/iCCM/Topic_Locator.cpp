#include "StdAfx.h"
#include "Topic_Locator.h"

#include "DQML/DQML.h"

#include "boost/bind.hpp"
#include <algorithm>

namespace DQML_iCCM
{
using GAME::Mga::Iterator;

//
// Topic_Locator
//
Topic_Locator::Topic_Locator (std::set <DQML::TopicQos> & topics)
: topics_ (topics)
{

}

//
// ~Topic_Locator
//
Topic_Locator::~Topic_Locator (void)
{

}

//
// visit_DataReaderQos
//
void Topic_Locator::visit_Participant (DQML::Participant_in item)
{
  for (auto & reader : item->get_DataReaderQoss ())
    reader->accept (this);

  for (auto & writer : item->get_DataWriterQoss ())
    writer->accept (this);
}

//
// visit_DataReaderQos
//
void Topic_Locator::visit_DataReaderQos (DQML::DataReaderQos_in item)
{
  if (item->has_TopicQosReference ())
    this->topics_.insert (item->get_TopicQosReference ()->refers_to_TopicQos ());
}

//
// visit_DataWriterQos
//
void Topic_Locator::visit_DataWriterQos (DQML::DataWriterQos_in item)
{
  if (item->has_TopicQosReference ())
    this->topics_.insert (item->get_TopicQosReference ()->refers_to_TopicQos ());
}

}
