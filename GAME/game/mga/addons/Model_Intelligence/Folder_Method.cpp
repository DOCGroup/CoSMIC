// $Id$

#include "StdAfx.h"

#include "Folder_Method.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Folder.h"
#include "Object_Value.h"

//
// Constructor
//
Folder_Method::Folder_Method (void)
{
}

//
// Destructor
//
Folder_Method::~Folder_Method (void)
{
}

//
// evaluate
//
Value * Folder_Method::evaluate (Ocl_Context & res, GAME::Mga::Object caller)
{
  // Collecting the parent folder of the invoking object
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  GAME::Mga::Folder folder = obj->parent_folder ();
  
  return new Object_Value (folder);
	
}

//
// evaluate
//
Value * Folder_Method::evaluate (Ocl_Context &res, Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  GAME::Mga::Folder folder;
  
	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();
    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

    folder = obj->parent_folder ();
  }
 
  return new Object_Value (folder);
}

//
// is_filter
//
bool Folder_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Folder_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Folder_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Folder_Method::is_reference (void)
{
  return false;
}