#include "StdAfx.h"
#include "Component_Asm_Visitor.h"
#include "Utils/Utils.h"
#include <string>

namespace PICML_To_DQML
{
  Component_Asm_Visitor::Component_Asm_Visitor (DQML_Model_Factory & factory,GAME::Mga::Object current_node)
    :factory_ (factory)
    ,current_node_(current_node)
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
    std::vector <PICML::ComponentInstance> comp_inst_models;
    item->children (comp_inst_models);
    for (PICML::ComponentInstance & comp_inst_model : comp_inst_models)
      comp_inst_model->accept (this);

    //Looking for connections
    std::vector <PICML::SendsTo> send_Tos;
    item->children (send_Tos);
    for (PICML::SendsTo & send_To : send_Tos)
      send_To->accept (this);

    this->current_node_ = current_node;
  }

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
    std::vector <PICML::InEventPortInstance> in_event_ports;
    item->children (in_event_ports);
    for (PICML::InEventPortInstance & in_event_port : in_event_ports)
      in_event_port->accept (this);
    
    //Looking for Output ports
    std::vector <PICML::OutEventPortInstance> out_event_ports;
    item->children (out_event_ports);
    for (PICML::OutEventPortInstance & out_event_port : out_event_ports)
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
    item->refers_to ()->accept (this);

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
    item->refers_to ()->accept (this);

    this->current_node_ = current_node;
  }

  //
  //visit_OutEventPort
  //
  void Component_Asm_Visitor::visit_InEventPort (PICML::InEventPort_in item)
  {
    PICML::Event ev = item-> refers_to ();
    this->factory_.create_TopicQosReference (DQML::DataReaderQos::_narrow (this->current_node_), ev->name ());
  }

  //
  //visit_OutEventPort
  //
  void Component_Asm_Visitor::visit_OutEventPort (PICML::OutEventPort_in item)
  {
    PICML::Event ev = item-> refers_to ();
    this->factory_.create_TopicQosReference (DQML::DataWriterQos::_narrow (this->current_node_), ev->name ());
  }

}