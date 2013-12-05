// $Id$

#include "StdAfx.h"
#include "CBMLManager_Impl.h"
#include "Connection_Generation_Handler.h"
#include "Output_Action_Handler.h"
#include "Action_Handler.h"
#include "Action_Type_Handler.h"
#include "MultiInput_Handler.h"

#include "game/mga/component/ComponentEx_T.h"

/// Type definition of the add-on implementation.
typedef GAME::Mga::Addon_Impl_T <CBML_Manager_ComponentEx_Impl,
                                 CBML_Model_Intelligence>
                                 CBML_Model_Intelligence_Impl;

DECLARE_GAME_COMPONENT_EX (CBML_Model_Intelligence_Impl, CBMLManager_Addon);

//
// CBML_Model_Intelligence
//
CBML_Model_Intelligence::CBML_Model_Intelligence (void)
: GAME::Mga::Top_Level_Event_Handler (eventmask)
{

}

//
// ~CBML_Model_Intelligence
//
CBML_Model_Intelligence::~CBML_Model_Intelligence (void)
{

}

//
// initialize
//
int CBML_Model_Intelligence::initialize (GAME::Mga::Project project)
{
  this->sink_->register_handler ("Action", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("Action", new CBML_Action_Handler ());
  this->sink_->register_handler ("ActionType", new (CBML_Action_Type_Handler));
  this->sink_->register_handler ("CallAction", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("RequestAction", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("OutputAction", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("OutputAction", new CBML_Output_Action_Handler ());
  this->sink_->register_handler ("MultiInputAction", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("InputAction", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("State", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("BranchState", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("DoWhileState", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("WhileState", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("ForState", new CBML_Connection_Generation_Handler ());
  this->sink_->register_handler ("MultiInput", new CBML_MultiInput_Handler ());

  return 0;
}
