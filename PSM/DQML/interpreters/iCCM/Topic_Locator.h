// -*- C++ -*-

//=============================================================================
/**
 * @file       Participant_Visitor.h
 *
 * @author     James H. Hill
 */
//=============================================================================

#ifndef _DQML_ICCM_TOPIC_LOCATOR_H_
#define _DQML_ICCM_TOPIC_LOCATOR_H_

#include <set>
#include "DQML/Visitor.h"

namespace DQML_iCCM
{

/**
 * @class Topic_Locator
 *
 * Visitor class that locates the topics for a participant.
 */
class Topic_Locator : public DQML::Visitor
{
public:
  /// Initializing constructor.
  Topic_Locator (std::set <DQML::TopicQos> & topics);

  /// Destructor.
  virtual ~Topic_Locator (void);

  virtual void visit_Participant (DQML::Participant_in item);
  virtual void visit_DataReaderQos (DQML::DataReaderQos_in item);
  virtual void visit_DataWriterQos (DQML::DataWriterQos_in item);

private:
  /// Located topics.
  std::set <DQML::TopicQos> & topics_;
};

}

#endif
