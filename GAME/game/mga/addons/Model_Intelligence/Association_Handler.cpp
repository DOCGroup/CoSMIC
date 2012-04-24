// $Id$

#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "Association_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/Folder.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Connection.h"
#include "game/mga/Atom.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaConstraint.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "MetaPart.h"
#include "MetaConnection.h"
#include "MetaBase.h"

#include "boost/bind.hpp"

#include "Boolean_Expr.h"
#include "OCL_Expr_Parser.h"
#include "Model_Intelligence_Context.h"
#include "Expr_Command.h"

//
// Association_Handler
//
Association_Handler::Association_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~Containment_Handler
//
Association_Handler::~Association_Handler (void)
{

}

//
// handle_object_created
//
int Association_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::Atom atm = GAME::Mga::Atom::_narrow (obj);

  return 0;

}