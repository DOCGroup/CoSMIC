// $Id$

#include "stdafx.h"
#include "PICML_Model_Visitor.h"
#include "Component_Asm_Visitor.h"

namespace PICML_To_DQML
{
  ///////////////////////////////////////////////////////////////////////////////
  // PICML_Model_Visitor

  //
  // PICML_Model_Visitor
  //
  PICML_Model_Visitor::PICML_Model_Visitor (DQML_Model_Factory & factory)
    :factory_ (factory)
    ,current_node_(0)
  {

  }

  //
  // Participant_File_Locator
  //
  PICML_Model_Visitor::~PICML_Model_Visitor (void)
  {

  }

  //
  // visit_RootFolder
  //
  void PICML_Model_Visitor::visit_RootFolder (GAME::Mga::RootFolder_in item)
  {
    std::vector <PICML::ComponentImplementations> comp_impl_folders;
    item->folders (comp_impl_folders);
    if (comp_impl_folders.size () == 0)
      return;

    this->current_node_ = this->factory_.create_RootFolder (item->name ());

    for (auto & comp_impl_folder : comp_impl_folders)
      comp_impl_folder->accept (this);
  }

  //
  // visit_ComponentImplementations
  //
  void PICML_Model_Visitor::visit_ComponentImplementations (PICML::ComponentImplementations_in item)
  {
    std::vector <PICML::ComponentImplementationContainer> comp_impl_cont_models;
    item->children (comp_impl_cont_models);
    if (comp_impl_cont_models.size () == 0)
      return;

    GAME::Mga::Object current_node = this->current_node_;
    this->current_node_ = this->factory_.create_iCCM (GAME::Mga::RootFolder::_narrow (this->current_node_), item->name ()+"_iCCM");

    for (auto & comp_impl_cont_model : comp_impl_cont_models)
      comp_impl_cont_model->accept (this);

    this->current_node_ = current_node;
  }

  //
  // visit_ComponentImplementationContainer
  //
  void PICML_Model_Visitor::visit_ComponentImplementationContainer (PICML::ComponentImplementationContainer_in item)
  {
    std::vector <PICML::ComponentAssembly> comp_asm_models;
    item->children (comp_asm_models);
    if (comp_asm_models.size () == 0)
      return;

    GAME::Mga::Object current_node = this->current_node_;
    this->current_node_ = this->factory_.create_DomainQosFolder (DQML::iCCM::_narrow (this->current_node_), item->name ());

    Component_Asm_Visitor cav (this->factory_, this->current_node_);

    for (auto & comp_asm_model : comp_asm_models)
      comp_asm_model->accept (&cav);

    this->current_node_ = current_node;
  }

}