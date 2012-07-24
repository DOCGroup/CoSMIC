// $Id: Reference_Handler.cpp 2907 2012-06-07 21:35:18Z tpati $

#include "StdAfx.h"

#include "Reference_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaReference.h"
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

//
// Reference_Handler
//
Reference_Handler::Reference_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~Reference_Handler
//
Reference_Handler::~Reference_Handler (void)
{

}

//
// handle_object_created
//
int Reference_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // There is no need to continue if the reference is not nil. This can
  // happen if some other addon creates the reference and sets the object
  // it refers to.
  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (obj);
  
  // Finding the metaobjects that ref referes to
  std::vector <GAME::Mga::Meta::FCO> types;
  ref->meta ()->targets (types);

  // Sorting out all the FCOs of metaobject type using a filter
  GAME::Mga::Filter filter (obj->project ());

  std::vector <GAME::Mga::FCO> objs;
  GAME::Mga::FCO select;

  filter.kind (types);
  filter.apply (objs);

	// Filtering the results based on constraints for the dialog box
	std::vector <GAME::Mga::Meta::Constraint> cs;

	size_t csize = ref->meta ()->constraints (cs);

  std::vector <std::string> ref_constraints;

	std::for_each (cs.begin (),
		             cs.end (),
								 boost::bind (&std::vector <std::string>::push_back,
                              boost::ref (ref_constraints),
															boost::bind (&GAME::Mga::Meta::Constraint::impl_type::expression,
															             boost::bind (&GAME::Mga::Meta::Constraint::get, _1))));

  
	Ocl_Context res;

	res.self = obj;
	res.model_constraint = false;
  res.model_attributes = false;

	std::vector <GAME::Mga::FCO>::iterator 
		objs_iter = objs.begin (), objs_iter_end = objs.end ();

	// Vector to hold the qualified FCO's
	std::vector <GAME::Mga::FCO> qual_fcos;

	for (; objs_iter != objs_iter_end; ++ objs_iter)
	{
		bool result = true;

		std::vector <std::string>::iterator 
			iter = ref_constraints.begin (), iter_end = ref_constraints.end ();

		for (; iter != iter_end; ++ iter)
		{
      bool temp = false;

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
        cont = ocl.begin(), cont_end = ocl.end();

      int counter = 0;

      for (; cont != cont_end; ++cont)
      {
        if ((*cont)->is_reference ())
          counter++;
      }

			// Iterating over the sub-expressions and evaluating them
			std::vector <Boolean_Expr *>::iterator 
				oclitt = ocl.begin (), oclitt_end = ocl.end ();

			for (; oclitt != oclitt_end; ++ oclitt)
			{
        if (counter == ocl.size () && result)
        {
          temp = (*oclitt)->filter_evaluate (res, (*objs_iter));

          if (!temp)
            result = false;
        }
			}
		}

		if (result)
			qual_fcos.push_back ((*objs_iter));
	}

  if (1 == qual_fcos.size ())
  {
    select = qual_fcos.front ();
  }
  else
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // Create the dialog and pass in the data
    using GAME::Dialogs::Selection_List_Dialog_T;
    Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd (), 0);

    const std::string directions =
      "Please select the target object for the " +
      ref->meta ()->display_name () + " reference object:";

    dlg.title ("Auto Reference Resolver");
    dlg.directions (directions.c_str ());
    dlg.insert (qual_fcos);

    if (IDOK != dlg.DoModal ())
      return 0;

    select = dlg.selection ();
  }

  if (!select.is_nil ())
  {
    ref->refers_to (select);
    ref->name (select->name ());
  }

  return 0;
}