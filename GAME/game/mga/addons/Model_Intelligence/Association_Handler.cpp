// $Id: Association_Handler.cpp 2908 2012-06-10 18:21:53Z tpati $

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

  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

  // Collecting all roles of the meta parent model
  GAME::Mga::Meta::Model meta_parent_model = fco->parent_model ()->meta ();

  std::vector <GAME::Mga::Meta::Role> rls;
  meta_parent_model->roles (rls);

  // Collecting all Connection FCOs under the parent model
  std::vector <GAME::Mga::Meta::Role>::iterator
		rlit = rls.begin (), rlit_end = rls.end ();

  for (; rlit != rlit_end; ++ rlit)
  {
	  if ((*rlit)->kind ()->type () == OBJTYPE_CONNECTION)
	  {
		  GAME::Mga::Meta::Connection conn = GAME::Mga::Meta::Connection::_narrow ((*rlit)->kind ());

		  // Collecting all the connectors of this connection
		  std::vector <GAME::Mga::Meta::ConnectionPoint> connectors;
		  size_t connpoints = conn->connectors (connectors);

		  std::vector <GAME::Mga::Meta::ConnectionPoint>::iterator
				connector = connectors.begin (), connector_end = connectors.end ();

		  for (; connector != connector_end; ++ connector)
		  {
        if ( (*connector)->get_src ()->name () == fco->meta ()->name () )					
			  {
          // Vector to hold the qualified FCO's
	        std::vector <GAME::Mga::FCO> qual_fcos;

          // Holds all the FCOs
          std::vector <GAME::Mga::FCO> objs;

          // Selects the suitable FCO
          GAME::Mga::FCO select;

          // Collecting the meta destination elements (which is a vector of vectors)
          std::vector <std::vector <GAME::Mga::Meta::FCO>> 
            meta_dsts = (*connector)->get_dsts ();

          // Collecting valid destinations
          if (meta_dsts.size () == 1)
          {
            std::vector <GAME::Mga::Meta::FCO> metavector = meta_dsts[0];

            // The subvector just has one element
            if (metavector.size () == 1)
            { 
              // Sorting out all the FCOs of metaobject type using a filter
				      GAME::Mga::Filter filter (obj->project ());
              filter.kind (meta_dsts[0][0]->name ());
              filter.apply (fco->parent_model (), objs);
            }
            else
            {
              // Collecting the elements under the submodel (used for ports)
              std::vector <GAME::Mga::Model> allmods;

              GAME::Mga::Meta::Model metamodel = GAME::Mga::Meta::Model::_narrow (meta_dsts[0][0]);
              GAME::Mga::Filter filter (obj->project ());
              filter.kind (metamodel->name ());
              filter.apply (fco->parent_model (), allmods);

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
              // If there is only one metavector
              if ((*metameta).size () == 1)  
              { 
                std::vector <GAME::Mga::FCO> temps;
              
                // Sorting out all the FCOs of metaobject type using a filter
                GAME::Mga::Filter filter (obj->project ());
                filter.kind ((*metameta)[0]->name ());
                filter.apply (fco->parent_model (), temps);

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
                filter.apply (fco->parent_model (), allmods);

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

	        size_t csize = fco->meta ()->constraints (cs);

          std::vector <std::string> asn_constraints;

          std::for_each (cs.begin (),
	                       cs.end (),
							           boost::bind (&std::vector <std::string>::push_back,
                                      boost::ref (asn_constraints),
														          boost::bind (&GAME::Mga::Meta::Constraint::impl_type::expression,
														                       boost::bind (&GAME::Mga::Meta::Constraint::get, _1))));

          Ocl_Context res;

          // Setting the values in the model intelligence context
          res.self = obj;
          res.model_constraint = false;
          res.model_attributes = false;

          std::vector <GAME::Mga::FCO>::iterator 
	          objs_iter = objs.begin (), objs_iter_end = objs.end ();

          // Checking the initial object list for constraint satisfaction
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
                //Parsing the constraint string
                parser.parse_string ((*iter), ocl);
                this->cache[(*iter)] = ocl;
              }

		          // Iterating over the sub-expressions and evaluating them
		          std::vector <Boolean_Expr *>::iterator 
			          asn_check = ocl.begin (), asn_check_end = ocl.end ();

              int counter = 0;

              // Checking if the constraint is an association type of constraint
              // This is to check if all the sub-expression are is_association type
              for (; asn_check != asn_check_end; ++ asn_check)
              {
                if ((*asn_check)->is_association ())
                  counter++;
              }

              std::vector <Boolean_Expr *>::iterator 
			          oclitt = ocl.begin (), oclitt_end = ocl.end ();

		          for (; oclitt != oclitt_end; ++ oclitt)
		          {
                if ((counter == ocl.size ()) && result)
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

					  const std::string directions = "Please select the target object for the connection " +
						  fco->name () + " object:";

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
					  GAME::Mga::Connection new_conn = GAME::Mga::Connection_Impl::_create (fco->parent_model (),
						                                                                      (*rlit)->name (),
						                                                                      fco,
																																									select);
				  }
			  } 
		  }
	  }
  }

  return 0;

}