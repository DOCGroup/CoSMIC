// -*- C++ -*-

//=============================================================================
/**
 * @file          Model_Intelligence_Context.h
 *
 * $Id$
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
#include "Expr_Command.h"

/**
 * @struct Ocl_Context
 *
 * Struct used for keeping a track of variables
 * and local objects.used by different expression resolvers
 */
struct Ocl_Context
{
  // Map for storing local variables and its value
  std::map <std::string, size_t> locals;

  // Vector storing the list of actions to be performed
  std::vector <Expr_Command *> actions;

  // Stores the target metarole used by expression resolvers
  // (example Parts_Method_Expr)
  GAME::Mga::Meta::Role target_metarole;

  // This is either the model which triggers the event handler
  // or the parent_model of the FCO triggering the event handler
  GAME::Mga::Model model_object;

  // This is the Atom object which triggers the event handler
  GAME::Mga::Atom atom_object;
};

#endif