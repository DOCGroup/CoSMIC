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
: GAME::Mga::Object_Event_Handler (eventmask)
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

  // Setting the model spcific attributes in Model_Intelligence_Features for containment
	Ocl_Context res;
	res.model_constraint = true;
  res.model_attributes = false;
	res.self = obj;
	res.model_object = mod;

	// Collecting all constraints on the entered model
  std::vector <GAME::Mga::Meta::Constraint> cs;

  size_t csize = mod->meta ()->constraints (cs);

	std::vector <std::string> all_cardinalities;

	std::for_each (cs.begin (),
		             cs.end (),
								 boost::bind (&std::vector <std::string>::push_back,
                              boost::ref (all_cardinalities),
															boost::bind (&GAME::Mga::Meta::Constraint::impl_type::expression,
															             boost::bind (&GAME::Mga::Meta::Constraint::get, _1))));

	// Iterating over all the cardinalities one by one so as to
  // parse and evaluate them to generate a list of actions
  std::vector <std::string>::const_iterator
    iter = all_cardinalities.begin (), iter_end = all_cardinalities.end ();

	for (; iter != iter_end; ++ iter)
  {
		//reseting the constraint specific variables
		res.target_metaroles.clear ();
		res.locals.clear ();

    std::vector <Boolean_Expr *> ocl;
    OCL_Expr_Parser parser;

		//Parsing the cardinality string
    parser.parse_string ((*iter), ocl);

    // Iterating over the sub-expressions and evaluating them
		std::for_each (ocl.begin (),
			             ocl.end (),
									 boost::bind(&Boolean_Expr::evaluate, _1, boost::ref(res)));

  }

	// Iterating over the list of actions and executing them
	std::for_each (res.actions.begin (),
                 res.actions.end (),
								 boost::bind(&Expr_Command::execute, _1));


  
  return 0;

}