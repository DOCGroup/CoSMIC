// $Id: Containment_Check_Handler.cpp 2884 2012-04-24 04:36:05Z hillj $

#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "Containment_Check_Handler.h"
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

#include "boost/bind.hpp"

#include "Boolean_Expr.h"
#include "OCL_Expr_Parser.h"
#include "Model_Intelligence_Context.h"
#include "Expr_Command.h"

//
// Containment_Check_Handler
//
Containment_Check_Handler::Containment_Check_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~Containment_Check_Handler
//
Containment_Check_Handler::~Containment_Check_Handler (void)
{

}

//
// handle_object_created 
//
int Containment_Check_Handler::handle_object_select (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

  Ocl_Context res;

  // Setting the model and current working object
  // in Model_Intelligence_Features
  res.self = fco->parent_model ();
  res.model_object = fco->parent_model ();
  res.checker = true;
  res.model_constraint = false;
  res.model_attributes = false;

  // Collecting all constraints on the parent model of entered object
  std::vector <GAME::Mga::Meta::Constraint> cs;
  size_t csize = res.model_object->meta ()->constraints (cs);

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

    // Checking if the constraint exists in cache
    std::map <std::string, std::vector <Boolean_Expr *>>::iterator
      cacheit = this->cache.begin (), cacheit_end = this->cache.end ();

    bool exists = false;

    for (; cacheit != cacheit_end; ++cacheit)
    {
      if ((*iter) == cacheit->first)
      {
        ocl = cacheit->second;
        exists = true;
        break;
      }
    }

    if (!exists)
    {
      // Parsing the constraint string
      parser.parse_string ((*iter), ocl);
      this->cache[(*iter)] = ocl;
    }

    std::vector <Boolean_Expr *>::iterator
      cont = ocl.begin (), cont_end = ocl.end ();

    int counter = 0;

    // Checking if the constraint is containment constraint
    for (; cont != cont_end; ++cont)
    {
      if ((*cont)->is_containment ())
        counter++;
    }

    if (counter == ocl.size ())
    {
      std::vector <Boolean_Expr *>::iterator
        c = ocl.begin (), c_end = ocl.end ();

      for (; c != c_end; ++c)
        (*c)->evaluate (res);
    }
  }

  return 0;

}