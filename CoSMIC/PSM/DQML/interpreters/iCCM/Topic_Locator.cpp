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
  Iterator <DQML::DataReaderQos> reader_iter = item->get_DataReaderQoss ();
  std::for_each (GAME::Mga::make_impl_iter (reader_iter),
                 GAME::Mga::make_impl_iter (reader_iter.make_end ()),
                 boost::bind (&DQML::DataReaderQos::impl_type::accept, _1, this));

  Iterator <DQML::DataWriterQos> writer_iter = item->get_DataWriterQoss ();
  std::for_each (GAME::Mga::make_impl_iter (writer_iter),
                 GAME::Mga::make_impl_iter (writer_iter.make_end ()),
                 boost::bind (&DQML::DataWriterQos::impl_type::accept, _1, this));
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
