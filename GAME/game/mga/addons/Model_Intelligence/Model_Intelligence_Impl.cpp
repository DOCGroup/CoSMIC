// $Id$

#include "StdAfx.h"
#include "Model_Intelligence_Impl.h"
#include "Reference_Handler.h"
#include "Containment_Handler.h"
#include "Containment_Handler_Extended.h"
#include "Association_Handler.h"
#include "game/mga/component/ComponentEx_T.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Object.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaBase.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/Reference.h"
#include "game/mga/utils/Point.h"

#include "game/mga/dialogs/Module.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <sstream>

namespace GAME
{
/// Type definition of the add-on implementation.
typedef Mga::Addon_Impl_T <Model_Intelligence_Impl,
                           Model_Intelligence>
                           Model_Intelligence_ComponentEx;

DECLARE_GAME_COMPONENT_EX (Model_Intelligence_ComponentEx, Model_Intelligence_Addon);

#define DLL_NAME "GAME_Model_Intelligence"

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
// Model_Intelligence
//
Model_Intelligence::Model_Intelligence (void)
: Mga::Event_Handler_Impl (eventmask, false)
{

}

//
// ~Model_Intelligence
//
Model_Intelligence::~Model_Intelligence (void)
{
  ACE_Framework_Repository::instance ()->remove_dll_components (DLL_NAME);
}

//
// initialize
//
int Model_Intelligence::initialize (Mga::Project project)
{

  this->event_handler_->register_handler (OBJTYPE_REFERENCE,
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <Reference_Handler>, 
	              ACE_Null_Mutex>::instance ());

   this->event_handler_->register_handler (OBJTYPE_MODEL,
    ACE_DLL_Singleton_T <Singleton_DLL_Adapter <Containment_Handler>, 
	              ACE_Null_Mutex>::instance ());

   this->event_handler_->register_handler (OBJTYPE_ATOM,
     ACE_DLL_Singleton_T <Singleton_DLL_Adapter <Containment_Handler_Extended>,
                ACE_Null_Mutex>::instance ());

   this->event_handler_->register_handler (OBJTYPE_ATOM,
     ACE_DLL_Singleton_T <Singleton_DLL_Adapter <Association_Handler>,
                ACE_Null_Mutex>::instance ());

  
  return 0;
}
}