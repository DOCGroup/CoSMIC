#include "StdAfx.h"
#include "DQML_Model_Factory.h"
#include "game/mga/Project.h"
#include "DQML/Impl_Factory.h"
#include "game/mga/Impl_Factory.h"
namespace PICML_To_DQML
{
  DQML_Model_Factory::DQML_Model_Factory (std::string & path)
    :project_ (GAME::Mga::Project::_create (path, "DQML")),
     writter_trans_ (this->project_, TRANSACTION_GENERAL),
     topic_qos_folder_ (NULL),
     topic_qos_list_ ()
  {

  }


  DQML_Model_Factory::~DQML_Model_Factory (void)
  {
  }

  //
  //save_And_Close
  //
  void DQML_Model_Factory::save_And_Close (void)
  {
    writter_trans_.commit ();
    this->project_.save ();
    this->project_.close ();
  }

  //
  //create_RootFolder
  //
  DQML::RootFolder DQML_Model_Factory::create_RootFolder (const std::string name)
  {
    DQML::RootFolder ret_obj = this->project_.root_folder ();

    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_iCCM
  //
  DQML::iCCM DQML_Model_Factory::create_iCCM (GAME::Mga::RootFolder_in parent, const std::string & name)
  {
    this->topic_qos_folder_ = 0;
    this->topic_qos_list_.clear ();

    DQML::iCCM ret_obj = DQML::iCCM_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_DomainQosFolder
  //
  DQML::DomainQosFolder DQML_Model_Factory::create_DomainQosFolder (DQML::iCCM_in parent, const std::string & name)
  {
    DQML::DomainQosFolder ret_obj = DQML::DomainQosFolder_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_Domain
  //
  DQML::Domain DQML_Model_Factory::create_Domain (DQML::DomainQosFolder_in parent, const std::string & name)
  {
    DQML::Domain ret_obj = DQML::Domain_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_Participant
  //
  DQML::Participant DQML_Model_Factory::create_Participant (DQML::Domain_in parent, const std::string & name)
  {
    DQML::Participant ret_obj = DQML::Participant_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_DataReaderQos
  //
  DQML::DataReaderQos DQML_Model_Factory::create_DataReaderQos (DQML::Participant_in parent, const std::string & name)
  {
    DQML::DataReaderQos ret_obj = DQML::DataReaderQos_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_DataWriterQos
  //
  DQML::DataWriterQos DQML_Model_Factory::create_DataWriterQos (DQML::Participant_in parent, const std::string & name)
  {
    DQML::DataWriterQos ret_obj = DQML::DataWriterQos_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_TopicQosReference
  //
  DQML::TopicQosReference DQML_Model_Factory::create_TopicQosReference (DQML::DataReaderQos_in parent, const std::string & name)
  {
    DQML::TopicQosReference ret_obj = DQML::TopicQosReference_Impl::_create (parent);

    ret_obj->refers_to_TopicQos (this->create_TopicQos (parent, name));

    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_TopicQosReference
  //
  DQML::TopicQosReference DQML_Model_Factory::create_TopicQosReference (DQML::DataWriterQos_in parent, const std::string & name)
  {
    DQML::TopicQosReference ret_obj = DQML::TopicQosReference_Impl::_create (parent);

    ret_obj->refers_to_TopicQos (this->create_TopicQos (parent, name));

    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_TopicQosFolder
  //
  DQML::TopicQosFolder DQML_Model_Factory::create_TopicQosFolder (DQML::iCCM_in parent, const std::string & name)
  {
    DQML::TopicQosFolder ret_obj = DQML::TopicQosFolder_Impl::_create (parent);
    ret_obj->name (name);
    return ret_obj;
  }

  //
  //create_TopicQos
  //
  DQML::TopicQos DQML_Model_Factory::create_TopicQos (GAME::Mga::Model node, const std::string & name)
  {
    if (topic_qos_folder_ == NULL)
    {
      DQML::iCCM iCCM_folder = DQML::iCCM::_narrow (node->parent ()->parent ()->parent ()->parent ());
      this->topic_qos_folder_ = this->create_TopicQosFolder (iCCM_folder, "TopicQosFolder");
    }
    return this->create_TopicQos ( &*this->topic_qos_folder_, name);
  }

  //
  //create_TopicQos
  //
  DQML::TopicQos DQML_Model_Factory::create_TopicQos (DQML::TopicQosFolder_in parent, const std::string & name)
  {
    std::map <std::string, DQML::TopicQos>::iterator t = this->topic_qos_list_.find (name);
    if (t != this->topic_qos_list_.end ())
      return t->second;

    DQML::TopicQos ret_obj = DQML::TopicQos_Impl::_create (parent);
    ret_obj->name (name);

    topic_qos_list_ [name] = ret_obj;

    return ret_obj;
  }
  //
  //create_PublisherConnection
  //
  DQML::PublishesConnection DQML_Model_Factory::
  create_PublishesConnection (DQML::Domain_in parent,
                              DQML::DataWriterQos_in src,
                              DQML::DataReaderQos_in dest)
  {
    GAME::Mga::Connection ret_obj = GAME::Mga::Connection_Impl::_create (parent, "PublishesConnection", src, dest);
    return ret_obj;
  }
}
