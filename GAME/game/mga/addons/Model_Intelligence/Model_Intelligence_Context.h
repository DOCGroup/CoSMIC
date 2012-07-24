// -*- C++ -*-

//=============================================================================
/**
 * @file          Model_Intelligence_Context.h
 *
 * $Id: Model_Intelligence_Context.h 2904 2012-05-16 01:03:53Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_CONTEXT_H_
#define _MODEL_INTELLIGENCE_CONTEXT_H_

#include <iostream>
#include <map>
#include "MetaRole.h"
#include "game/mga/Model.h"
#include "game/mga/Atom.h"
#include "game/mga/Reference.h"
#include "game/mga/Object.h"

#include "Expr_Command.h"
#include "Value.h"
#include "Int_Value.h"

/**
 * @struct Ocl_Context
 *
 * Struct used for keeping a track of variables
 * and local objects.Used by different expression resolvers
 */
struct Ocl_Context
{
	// Flag denoting the type of constraint (for containment)
	bool model_constraint;

  // Flag denoting the type of constraint (for attributes)
  bool model_attributes;

  // Variables common to all constraints:

  // The parent_model of the FCO's to be created 
	GAME::Mga::Model model_object;

	// The object that triggers the event
	GAME::Mga::Object self;

  // Vector storing the list of actions to be performed
  std::vector <Expr_Command *> actions;

  // Constraint specific variables:

  // Stores the target metaroles used by expression resolvers
  // (example Parts_Method_Expr)
	std::vector <GAME::Mga::Meta::Role> target_metaroles;

  // Map for storing local variables and its value
  std::map <std::string, Value *> locals;

	// Current FCO being worked on
	GAME::Mga::FCO cur_fco;

  // Containment Constraint checker
  bool checker;
};

#endif