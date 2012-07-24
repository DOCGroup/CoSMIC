// $Id: Attributes_Handler.cpp 2903 2012-05-10 03:03:08Z tpati $

#include "StdAfx.h"

#include "Attributes_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/MetaConstraint.h"
#include "game/mga/Atom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaBase.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#include "boost/bind.hpp"

#include "Model_Intelligence_Context.h"
#include "Boolean_Expr.h"
#include "OCL_Expr_Parser.h"
#include "Expr_Command.h"

//
// Attributes_Handler
//
Attributes_Handler::Attributes_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~Attributes_Handler
//
Attributes_Handler::~Attributes_Handler (void)
{

}

//
// handle_object_created
//
int Attributes_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  bool flag = false;
  Ocl_Context res;

  // Seting values in the model intelligence context
	res.model_constraint = false;
  res.model_attributes = true;
	res.self = obj;

  // Collecting all constraints on the entered object
  std::vector <GAME::Mga::Meta::Constraint> cs;

  size_t csize = obj->meta ()->constraints (cs);

	std::vector <std::string> all_constraints;

  std::for_each (cs.begin (),
		             cs.end (),
								 boost::bind (&std::vector <std::string>::push_back,
                              boost::ref (all_constraints),
															boost::bind (&GAME::Mga::Meta::Constraint::impl_type::expression,
															             boost::bind (&GAME::Mga::Meta::Constraint::get, _1))));

  // Iterating over all the constraints one by one so as to
  // parse and evaluate them to generate a list of actions
  std::vector <std::string>::const_iterator
    iter = all_constraints.begin (), iter_end = all_constraints.end ();

	for (; iter != iter_end; ++ iter)
  {
    //reseting the constraint specific variables
		res.target_metaroles.clear ();
		res.locals.clear ();

    std::vector <Boolean_Expr *> ocl;
    OCL_Expr_Parser parser;

		//Parsing the constraint string
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