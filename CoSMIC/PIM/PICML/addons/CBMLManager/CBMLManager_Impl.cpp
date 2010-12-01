// $Id$

#include "StdAfx.h"
#include "CBMLManager_Impl.h"
#include "Connection_Generation_Handler.h"
#include "Output_Action_Handler.h"
#include "Action_Handler.h"
#include "Action_Type_Handler.h"

#include "game/be/ComponentEx_T.h"
#include "game/Atom.h"
#include "game/Model.h"
#include "game/Object.h"
#include "game/Connection.h"
#include "game/MetaBase.h"
#include "game/MetaFCO.h"
#include "game/Reference.h"
#include "game/utils/Point.h"

#include "game/dialogs/Module.h"
#include "game/dialogs/Selection_List_Dialog_T.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <sstream>

#define OFFSET_Y  7
#define OFFSET_X  50

#define PREF_AUTOROUTER           "autorouterPref"
#define PREF_AUTOROUTER_ALL       "NEWSnews"

typedef GAME::Addon_Impl_T <
  CBML_Manager_ComponentEx_Impl,
  CBML_Model_Intelligence >
  CBML_Model_Intelligence_Impl;

DECLARE_GAME_COMPONENT_EX (CBML_Model_Intelligence_Impl, CBMLManager_Addon);

//
// CBML_Model_Intelligence
//
CBML_Model_Intelligence::CBML_Model_Intelligence (void)
: GAME::Event_Handler_Impl (eventmask, false)
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
int CBML_Model_Intelligence::initialize (GAME::Project project)
{
  this->event_handler_->register_handler ("Action",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("Action",
    ACE_Unmanaged_Singleton <CBML_Action_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ActionType",
    ACE_Unmanaged_Singleton <CBML_Action_Type_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("RequestAction",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("OutputAction",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("OutputAction",
    ACE_Unmanaged_Singleton <CBML_Output_Action_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("MultiInputAction",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("InputAction",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("State",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("BranchState",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("DoWhileState",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("WhileState",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ForState",
    ACE_Unmanaged_Singleton <CBML_Connection_Generation_Handler,
                   ACE_Null_Mutex>::instance ());

  return 0;
}
