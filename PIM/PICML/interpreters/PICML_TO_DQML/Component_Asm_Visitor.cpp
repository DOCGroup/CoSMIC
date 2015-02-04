#include "StdAfx.h"
#include "Component_Asm_Visitor.h"
#include "Utils/Utils.h"
#include <string>

namespace PICML_To_DQML
{
  Component_Asm_Visitor::Component_Asm_Visitor (DQML_Model_Factory & factory,GAME::Mga::Object current_node)
    :factory_ (factory),
     current_node_ (current_node)
  {
  }

  Component_Asm_Visitor::~Component_Asm_Visitor(void)
  {
  }
 
  //
  //visit_ComponentAssembly
  //
  void Component_Asm_Visitor::visit_ComponentAssembly (PICML::ComponentAssembly_in item)
  {
    GAME::Mga::Object current_node = this->current_node_;
    this->current_node_ = this->factory_.create_Domain (DQML::DomainQosFolder::_narrow (this->current_node_), item->name ());

    this->ports_map_.clear ();

    //Looking for component instances
    for (auto & comp_inst_model : item->get_ComponentInstances ())
      comp_inst_model->accept (this);

    //Looking for connections
    for (auto & send_To : item->get_SendsTos ())
      send_To->accept (this);

    this->current_node_ = current_node;
  }

  //
  // visit_SendsTo
  //
  void Component_Asm_Visitor::visit_SendsTo (PICML::SendsTo_in item)
  {
    this->factory_.create_PublishesConnection (DQML::Domain::_narrow (this->current_node_), 
      DQML::DataWriterQos::_narrow (this->ports_map_ [item->src ()]), 
      DQML::DataReaderQos::_narrow (this->ports_map_ [item->dst ()]));
  }

  //
  //visit_ComponentInstance
  //
  void Component_Asm_Visitor::visit_ComponentInstance (PICML::ComponentInstance_in item)
  {
    GAME::Mga::Object current_node = this->current_node_;
    this->current_node_ = this->factory_.create_Participant (DQML::Domain::_narrow (this->current_node_), item->name ());
    
    //Looking for Input ports
    for (auto & in_event_port : item->get_InEventPortInstances ())
      in_event_port->accept (this);
    
    //Looking for Output ports
    for (auto & out_event_port : item->get_OutEventPortInstances ())
      out_event_port->accept (this);

    this->current_node_ = current_node;
  }

  //
  //visit_InEventPortInstance
  //
  void Component_Asm_Visitor::visit_InEventPortInstance (PICML::InEventPortInstance_in item)
  {
    GAME::Mga::Object current_node = this->current_node_;
    DQML::DataReaderQos dr = this->factory_.create_DataReaderQos (DQML::Participant::_narrow (this->current_node_), item->name ());
    this->current_node_ = dr;
    this->ports_map_ [item] = dr;
    item->refers_to_InEventPort ()->accept (this);

    this->current_node_ = current_node;
  }

  //
  //visit_OutEventPortInstance
  //
  void Component_Asm_Visitor::visit_OutEventPortInstance (PICML::OutEventPortInstance_in item)
  {
    GAME::Mga::Object current_node = this->current_node_;
    DQML::DataWriterQos dw = this->factory_.create_DataWriterQos (DQML::Participant::_narrow (this->current_node_), item->name ());
    this->current_node_ = dw;
    this->ports_map_ [item] = dw;
    item->refers_to_OutEventPort ()->accept (this);

    this->current_node_ = current_node;
  }

  //
  //visit_OutEventPort
  //
  void Component_Asm_Visitor::visit_InEventPort (PICML::InEventPort_in item)
  {
    PICML::Event ev = item->refers_to_EventType ();
    this->factory_.create_TopicQosReference (DQML::DataReaderQos::_narrow (this->current_node_), ev->name ());
  }

  //
  //visit_OutEventPort
  //
  void Component_Asm_Visitor::visit_OutEventPort (PICML::OutEventPort_in item)
  {
    PICML::Event ev = item->refers_to_EventType ();
    this->factory_.create_TopicQosReference (DQML::DataWriterQos::_narrow (this->current_node_), ev->name ());
  }

}