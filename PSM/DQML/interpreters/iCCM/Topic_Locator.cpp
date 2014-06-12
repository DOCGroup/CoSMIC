// $Id$

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
  GAME::Mga::Collection_T <DQML::DataReaderQos> readers = item->get_DataReaderQoss ();
  for (auto & reader : readers)
    reader->accept (this);

  GAME::Mga::Collection_T <DQML::DataWriterQos> writers = item->get_DataWriterQoss ();
  for (auto & writer : writers)
    writer->accept (this);
}

//
// visit_DataReaderQos
//
void Topic_Locator::visit_DataReaderQos (DQML::DataReaderQos_in item)
{
  if (item->has_TopicQosReference ())
    this->topics_.insert (item->get_TopicQosReference ()->get_TopicQos ());
}

//
// visit_DataWriterQos
//
void Topic_Locator::visit_DataWriterQos (DQML::DataWriterQos_in item)
{
  if (item->has_TopicQosReference ())
    this->topics_.insert (item->get_TopicQosReference ()->get_TopicQos ());
}

}
