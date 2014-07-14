//=============================================================================
/**
* @file       DQML_Model_Factory.h
*
* $Id$
*
* @author     Hossein Karimy
*/
//=============================================================================
#ifndef _DQML_MODEL_FACTORY_H_
#define _DQML_MODEL_FACTORY_H_

#include <string>
#include "DQML/DQML.h"
#include "game/mga/Mga.h"
#include "game/mga/Transaction.h"
#include <map>

namespace PICML_To_DQML
{
  class DQML_Model_Factory
  {
  public:
    DQML_Model_Factory (std::string & path);
    ~DQML_Model_Factory (void);

    void save_And_Close (void);

    GAME::Mga::RootFolder create_RootFolder (const std::string name);
    DQML::iCCM create_iCCM (GAME::Mga::RootFolder_in parent , const std::string name);
    DQML::DomainQosFolder create_DomainQosFolder (DQML::iCCM_in parent , const std::string name);
    DQML::Domain create_Domain (DQML::DomainQosFolder_in parent , const std::string name);
    DQML::Participant create_Participant (DQML::Domain_in parent , const std::string name);
    DQML::DataReaderQos create_DataReaderQos (DQML::Participant_in parent , const std::string name);
    DQML::DataWriterQos create_DataWriterQos (DQML::Participant_in parent , const std::string name);
    DQML::TopicQosReference create_TopicQosReference (DQML::DataReaderQos_in parent , const std::string name);
    DQML::TopicQosReference create_TopicQosReference (DQML::DataWriterQos_in parent , const std::string name);

    DQML::TopicQosFolder create_TopicQosFolder (DQML::iCCM_in parent , const std::string name);
    DQML::TopicQos create_TopicQos (DQML::TopicQosFolder_in parent , const std::string name);
    DQML::TopicQos create_TopicQos (GAME::Mga::Model node , const std::string name);

    DQML::PublishesConnection create_PublishesConnection (DQML::Domain_in parent , DQML::DataWriterQos_in src, DQML::DataReaderQos_in dest);
  private:
    void set_name(GAME::Mga::Object obj, std::string name);
    GAME::Mga::Project project_;
    GAME::Mga::Transaction writter_trans_;
    
    //Internal States
    DQML::TopicQosFolder topic_qos_folder_;
    std::map <std::string, DQML::TopicQos> topic_qos_list_;

  };
}

#endif  // !defined _DQML_MODEL_FACTORY_H_ 
