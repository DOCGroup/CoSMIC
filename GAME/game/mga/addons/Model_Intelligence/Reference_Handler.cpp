#include "StdAfx.h"

#include "Reference_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaReference.h"
#include "game/mga/Atom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaBase.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#include "boost/bind.hpp"

//
// Library_Reference_Handler
//
Library_Reference_Handler::Library_Reference_Handler (void)
: GAME::Mga::Event_Handler_Impl (eventmask)
{
	
}

//
// ~Library_Reference_Handler
//
Library_Reference_Handler::~Library_Reference_Handler (void)
{

}

//
// handle_object_created
//
int Library_Reference_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
	
	if (this->is_importing_)
		return 0;

	// Find the event sources
	GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (obj);

	// Vector for holding the metaobjects that ref referes to 
	std::vector <GAME::Mga::Meta::FCO> types;	

	// Find out the metaobject to which ref referes
	ref->meta()->targets(types);
	

	// Create a filter for finding all the objects that are of metaobject type
	GAME::Mga::Filter filter_ (obj->project());

  // Vector for holding all the FCO's that ref referes to 
	std::vector <GAME::Mga::FCO> objs;

	GAME::Mga::FCO obj_;

	filter_.kind (types);

  // Apply the filter to store the data in vector objs
  filter_.apply (objs);	
    
	
	if (1 == objs.size ())
	{
		obj_ = objs.front ();
	}
	else
	{
		AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

		// Create the dialog and pass in the data
		using GAME::Dialogs::Selection_List_Dialog_T;
		Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd ());

		dlg.title ("Reference Resolver");
		dlg.directions ("Select the target object for the respective reference");
		dlg.insert (objs);

		if (IDOK != dlg.DoModal ())
			return 0;

		obj_ = dlg.selection ();
	}

	if (!obj_.is_nil ())
	{
		ref->refers_to (obj_);
		ref->name (obj_->name ());
	}

  return 0;
}