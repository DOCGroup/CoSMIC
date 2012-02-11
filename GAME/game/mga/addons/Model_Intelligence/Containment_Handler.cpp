// $Id$

#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "Containment_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Connection.h"
#include "game/mga/Atom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaConstraint.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "MetaPart.h"

#include "boost/bind.hpp"

#include "Boolean_Expr.h"
#include "OCL_Expr_Parser.h"
#include "Model_Intelligence_Context.h"
#include "Expr_Command.h"

//
// Containment_Handler
//
Containment_Handler::Containment_Handler (void)
: GAME::Mga::Dynamic_Event_Handler_Impl (eventmask)
{

}

//
// ~Containment_Handler
//
Containment_Handler::~Containment_Handler (void)
{

}

//
// handle_object_created
//
int Containment_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::Model mod = GAME::Mga::Model::_narrow (obj);

  // Collecting all constraints on the entered model
  std::vector <GAME::Mga::Meta::Constraint> cs;

  size_t csize = mod->meta ()->constraints (cs);

  std::vector <GAME::Mga::Meta::Constraint>::iterator cts;

  std::vector <std::string> all_cardinalities;

  for (cts = cs.begin (); cts < cs.end (); cts++)
    {
      all_cardinalities.push_back ((*cts)->expression ());
    }

  Ocl_Context res;

  // Setting the model in Model_Intelligence_Features
  res.model_object = mod;

  // Iterating over all the cardinalities one by one so as to
  // parse and evaluate them to generate a list of actions
  std::vector <std::string>::iterator iter;

  for (iter = all_cardinalities.begin (); iter < all_cardinalities.end (); iter++)
  {
    std::vector <Boolean_Expr *> ocl;
    OCL_Expr_Parser parser;

    //Parsing the cardinality string
    parser.parse_string ((*iter), ocl);

    // Iterating over the sub-expressions and evaluating them
    std::vector <Boolean_Expr *>::iterator oclitt;

    for (oclitt = ocl.begin (); oclitt < ocl.end (); oclitt++)
      {
        (*oclitt)->evaluate (res);
      }
  }

  // Iterating over the list of actions and executing them
  std::vector <Expr_Command*>::iterator action;

  for (action = res.actions.begin (); action < res.actions.end (); action++)
  {
    (*action)->execute ();
  }

  return 0;

}