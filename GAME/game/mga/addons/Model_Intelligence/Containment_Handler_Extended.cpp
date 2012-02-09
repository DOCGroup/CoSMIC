// $Id$

#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "Containment_Handler_Extended.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Connection.h"
#include "game/mga/Atom.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaConstraint.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "MetaPart.h"

#include "Model_Intelligence_Context.h"
#include "OCL_Expr_Parser.h"
#include "Boolean_Expr.h"


//
// Containment_Handler
//
Containment_Handler_Extended::Containment_Handler_Extended (void)
: GAME::Mga::Event_Handler_Impl (eventmask)
{
	
}

//
// ~Containment_Handler
//
Containment_Handler_Extended::~Containment_Handler_Extended (void)
{

}

//
// handle_object_created (This functionality is not available yet.)
//
int Containment_Handler_Extended::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
		return 0;

  GAME::Mga::Atom atm = GAME::Mga::Atom::_narrow (obj);

  Ocl_Context res;

  // Setting the model and current working object 
  // in Model_Intelligence_Features
  res.model_object = atm->parent_model ();
  res.atom_object = atm;

  // Collecting all constraints on the parent model of entered object
  std::vector <GAME::Mga::Meta::Constraint> cs;
  size_t csize = res.model_object->meta ()->constraints (cs);

  std::vector <GAME::Mga::Meta::Constraint>::iterator cts;

  std::vector <std::string> all_cardinalities;

  for (cts = cs.begin (); cts < cs.end (); cts++)
    {
      all_cardinalities.push_back ((*cts)->expression ());
    }

  // Iterating over all the cardinalities one by one so as to
  // parse and evaluate them to generate a list of actions
  std::vector <std::string>::iterator iter;

  for (iter = all_cardinalities.begin (); iter < all_cardinalities.end (); iter++)
  {
    std::vector <Boolean_Expr *> ocl;
    OCL_Expr_Parser parser;

    //Parse the cardinality string
    parser.parse_string ((*iter), ocl);

    // Iterating over the sub-expressions and evaluating them
    std::vector <Boolean_Expr *>::iterator oclitt;

    for (oclitt = ocl.begin (); oclitt < ocl.end (); oclitt++)
      {
        (*oclitt)->evaluate (res);
      }
  }

  // Iterating over the list of actions and executing them


  return 0;

}