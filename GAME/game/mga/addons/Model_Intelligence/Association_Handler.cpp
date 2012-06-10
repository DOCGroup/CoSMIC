// $Id$

#include "StdAfx.h"
#include <vector>
#include <algorithm>
#include <string>
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
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

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
// handle_object_select
//
int Association_Handler::handle_object_select (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::Atom atm = GAME::Mga::Atom::_narrow (obj);

  // Collect all roles of the meta parent model
  GAME::Mga::Meta::Model meta_parent_model = atm->parent_model ()->meta ();

  std::vector <GAME::Mga::Meta::Role> rls;
  meta_parent_model->roles (rls);

  // Collect all Connection FCOs under the parent model
  std::vector <GAME::Mga::Meta::Role>::iterator
		rlit = rls.begin (), rlit_end = rls.end ();

  for (; rlit != rlit_end; ++ rlit)
  {
	  if ((*rlit)->kind ()->type () == OBJTYPE_CONNECTION)
	  {
		  GAME::Mga::Meta::Connection conn = GAME::Mga::Meta::Connection::_narrow ((*rlit)->kind ());

      // Testing line
      std::string c = conn->name ();

		  // Collect all the connectors of this connection
		  std::vector <GAME::Mga::Meta::ConnectionPoint> connectors;
		  size_t connpoints = conn->connectors (connectors);

		  std::vector <GAME::Mga::Meta::ConnectionPoint>::iterator
				connector = connectors.begin (), connector_end = connectors.end ();

		  for (; connector != connector_end; ++ connector)
		  {
        // Testing line
        std::string source = (*connector)->get_src ()->name ();
        std::string me = atm->meta ()->name ();

				if ( (*connector)->get_src ()->name () == atm->meta ()->name () )					
			  {
          // Vector to hold the qualified FCO's
	        std::vector <GAME::Mga::FCO> qual_fcos;

          // Holds all the FCOs
          std::vector <GAME::Mga::FCO> objs;

          // Selects the suitable FCO
          GAME::Mga::FCO select;

          std::vector <std::vector <GAME::Mga::Meta::FCO>> 
            meta_dsts = (*connector)->get_dsts ();

          // If there is just one destination vector
          if (meta_dsts.size () == 1)
          {
            std::vector <GAME::Mga::Meta::FCO> metavector = meta_dsts[0];

            // The subvector just has one element
            if (metavector.size () == 1)
            { 
              //GAME::Mga::Meta::FCO metadst = metavector.begin ()->get ();
              // Sorting out all the FCOs of metaobject type using a filter
				      GAME::Mga::Filter filter (obj->project ());
              filter.kind (meta_dsts[0][0]->name ());
              filter.apply (atm->parent_model (), objs);
            }
            else
            {
              std::vector <GAME::Mga::Model> allmods;

              GAME::Mga::Meta::Model metamodel = GAME::Mga::Meta::Model::_narrow (meta_dsts[0][0]);
              GAME::Mga::Filter filter (obj->project ());
              filter.kind (metamodel->name ());
              filter.apply (atm->parent_model (), allmods);

              std::vector <GAME::Mga::Model>::iterator
                modit = allmods.begin (), modit_end = allmods.end ();

              for (; modit != modit_end ; ++ modit)
              {
                std::vector <GAME::Mga::FCO> mod_specific_elements;
                GAME::Mga::Filter filter (obj->project ());
                filter.kind (meta_dsts[0][1]->name ());
                filter.apply ((*modit), mod_specific_elements);
                std::vector <GAME::Mga::FCO>::iterator
                  it = mod_specific_elements.begin (), it_end = mod_specific_elements.end ();
                for (; it != it_end; ++it)
                  objs.push_back (*it);
              }
            } // end else ( when metavector is more than 1)
          }
          else
          {
            std::vector <std::vector <GAME::Mga::Meta::FCO>>::iterator
              metameta = meta_dsts.begin (), metameta_end = meta_dsts.end ();

            for (; metameta != metameta_end; ++ metameta)
            {
              if ((*metameta).size () == 1)  // If there is only one metavector
              { 
                std::vector <GAME::Mga::FCO> temps;
              
                // Sorting out all the FCOs of metaobject type using a filter
                GAME::Mga::Filter filter (obj->project ());
                filter.kind ((*metameta)[0]->name ());
                filter.apply (atm->parent_model (), temps);

                std::vector <GAME::Mga::FCO>::iterator
                  it = temps.begin (), it_end = temps.end ();

                for (; it != it_end; ++it)
                  objs.push_back (*it);
              }
              else // extra section....not really necessary for now..might be useful in future
              {
                std::vector <GAME::Mga::Model> allmods;

                // Collecting all models of type <Model> i.e. which contains the port
                GAME::Mga::Meta::Model metamodel = GAME::Mga::Meta::Model::_narrow ((*metameta)[0]);
                GAME::Mga::Filter filter (obj->project ());
                filter.kind (metamodel->name ());
                filter.apply (atm->parent_model (), allmods);

                std::vector <GAME::Mga::Model>::iterator
                    modit = allmods.begin (), modit_end = allmods.end ();

                for (; modit != modit_end ; ++ modit)
                {
                  std::vector <GAME::Mga::FCO> mod_specific_elements;
                  GAME::Mga::Filter filter (obj->project ());
                  filter.kind ((*metameta)[1]->name ());
                  filter.apply ((*modit), mod_specific_elements);

                  std::vector <GAME::Mga::FCO>::iterator
                    it = mod_specific_elements.begin (), it_end = mod_specific_elements.end ();

                  /*for (; it != it_end; ++it)
                    objs.push_back (*it);*/
                }

              } // end else when metavector is more than 1
            }
  				    
          } // end else (when meta_dsts is more than 1)
          
          // Filtering the results based on constraints for the dialog box
	        std::vector <GAME::Mga::Meta::Constraint> cs;

	        size_t csize = atm->meta ()->constraints (cs);

          std::vector <std::string> asn_constraints;

          std::for_each (cs.begin (),
	                       cs.end (),
							           boost::bind (&std::vector <std::string>::push_back,
                                      boost::ref (asn_constraints),
														          boost::bind (&GAME::Mga::Meta::Constraint::impl_type::expression,
														                       boost::bind (&GAME::Mga::Meta::Constraint::get, _1))));

          Ocl_Context res;

          res.self = obj;
          res.model_constraint = false;
          res.model_attributes = false;

          std::vector <GAME::Mga::FCO>::iterator 
	          objs_iter = objs.begin (), objs_iter_end = objs.end ();

          for (; objs_iter != objs_iter_end; ++ objs_iter)
          {
	          bool result = true;

	          std::vector <std::string>::iterator 
		          iter = asn_constraints.begin (), iter_end = asn_constraints.end ();

	          for (; iter != iter_end; ++ iter)
	          {
              bool temp = false;
		          //reseting the constraint specific variables
		          res.target_metaroles.clear ();
		          res.locals.clear ();

		          std::vector <Boolean_Expr *> ocl;
		          OCL_Expr_Parser parser;

		          //Parsing the ocl string
  	          parser.parse_string (*(iter), ocl);

		          // Iterating over the sub-expressions and evaluating them
		          std::vector <Boolean_Expr *>::iterator 
			          oclitt = ocl.begin (), oclitt_end = ocl.end ();

		          for (; oclitt != oclitt_end; ++ oclitt)
		          {
                if (result)
                  temp = (*oclitt)->filter_evaluate (res, (*objs_iter));

			          if (!temp)
				          result = false;
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

					  const std::string directions = "Please select the target object for the connection " +
						  atm->name () + " object:";

					  dlg.title ("Auto Connection Resolver");
					  dlg.directions (directions.c_str ());
					  dlg.insert (qual_fcos);

					  if (IDOK != dlg.DoModal ())
						  return 0;

					  select = dlg.selection ();
				  }

				  // Create the connection
				  if (!select.is_nil ())
				  {
					  GAME::Mga::Connection new_conn = GAME::Mga::Connection_Impl::_create (atm->parent_model (),
						                                                                      (*rlit)->name (),
						                                                                      atm,
																																									select);
				  }
			  } 
		  }
	  }
  }

  return 0;

}