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

#define DLL_NAME "CBML_Model_Intelligence"

/**
 * Adapter for the ACE_DLL_Singleton_T object. This allows singletons
 * defined in this module to operate correctly with the ACE framework.
 */
template <typename T>
class Singleton_DLL_Adapter : public T
{
public:
  const ACE_TCHAR * name (void) const
  {
    return DLL_NAME;
  }

  const ACE_TCHAR * dll_name (void) const
  {
    return DLL_NAME;
  }
};

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
  ACE_Framework_Repository::instance ()->remove_dll_components (DLL_NAME);
}

//
// initialize
//
int CBML_Model_Intelligence::initialize (GAME::Project project)
{
  this->event_handler_->register_handler ("Action",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("Action",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Action_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ActionType",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Action_Type_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("RequestAction",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("OutputAction",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("OutputAction",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Output_Action_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("MultiInputAction",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("InputAction",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("State",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("BranchState",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("DoWhileState",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("WhileState",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  this->event_handler_->register_handler ("ForState",
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <CBML_Connection_Generation_Handler>,
                   ACE_Null_Mutex>::instance ());

  return 0;
}
