// $Id$

#include "StdAfx.h"
#include "Model_Intelligence_Impl.h"
#include "Containment_Handler.h"
#include "Association_Handler.h"
#include "Reference_Handler.h"
#include "Attributes_Handler.h"
#include "User_Guidance_Handler.h"
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

#include <algorithm>
#include <sstream>

namespace GAME
{
/// Type definition of the add-on implementation.
typedef Mga::Addon_Impl_T <Model_Intelligence_Impl,
                           Model_Intelligence>
                           Model_Intelligence_ComponentEx;

DECLARE_GAME_COMPONENT_EX (Model_Intelligence_ComponentEx, Model_Intelligence_Addon);

//
// Model_Intelligence
//
Model_Intelligence::Model_Intelligence (void)
: Mga::Top_Level_Event_Handler (eventmask)
{

}

//
// ~Model_Intelligence
//
Model_Intelligence::~Model_Intelligence (void)
{

}

//
// initialize
//
int Model_Intelligence::initialize (Mga::Project project)
{
  this->sink_->register_handler (OBJTYPE_REFERENCE, new Reference_Handler ());
  this->sink_->register_handler (OBJTYPE_MODEL, new Containment_Handler ());
  this->sink_->register_handler (OBJTYPE_ATOM, new Association_Handler ());
  this->sink_->register_handler (OBJTYPE_ATOM, new Attributes_Handler ());
  //this->sink_->register_handler (new User_Guidance_Handler ());

  	
  return 0;
}

}