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

		  // Collect all the connectors of this connection
		  std::vector <GAME::Mga::Meta::ConnectionPoint> connectors;
		  size_t connpoints = conn->connectors (connectors);

		  std::vector <GAME::Mga::Meta::ConnectionPoint>::iterator
				connector = connectors.begin (), connector_end = connectors.end ();

		  for (; connector != connector_end; ++ connector)
		  {
				if ( ((*connector)->get_src ()->name () == atm->meta ()->name ()) || 
					((*connector)->get_src ()->name () == (atm->parent_model()->name() + " " + atm->meta ()->name ())) )					
			  {
				  GAME::Mga::Meta::FCO meta_dst = (*connector)->get_dst ();

				  // Sorting out all the FCOs of metaobject type using a filter
				  GAME::Mga::Filter filter (obj->project ());
					
				  std::vector <GAME::Mga::FCO> objs;
                  GAME::Mga::FCO select;

				  filter.kind (meta_dst->name ());
					filter.apply (atm->parent_model (), objs);

				  if (1 == objs.size ())
				  {
					  select = objs.front ();
				  }
				  else
				  {
					  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

					  // Create the dialog and pass in the data
					  using GAME::Dialogs::Selection_List_Dialog_T;
					  Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd ());

					  const std::string directions = "Please select the target object for the connection " +
						  atm->name () + " object:";

					  dlg.title ("Auto Connection Resolver");
					  dlg.directions (directions.c_str ());
					  dlg.insert (objs);

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