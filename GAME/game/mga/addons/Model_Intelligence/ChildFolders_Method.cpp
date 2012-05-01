// $Id$

#include "StdAfx.h"

#include "ChildFolders_Method.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"
#include "game/mga/Folder.h"

//
// Constructor
//
ChildFolders_Method::ChildFolders_Method (void)
{
}

//
// Destructor
//
ChildFolders_Method::~ChildFolders_Method (void)
{
}

//
// evaluate
//
Value * ChildFolders_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	std::vector <GAME::Mga::Folder> child;
	GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (caller);
	fld->folders (child);
	return new Collection_Value_T<GAME::Mga::Folder> (child);
}

//
// evaluate
//
Value * ChildFolders_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::vector <GAME::Mga::Folder> child;

	if (iv != 0)
	{
		GAME::Mga::Folder fld = GAME::Mga::Folder::_narrow (iv->value ());
		fld->folders (child);
	}

	return new Collection_Value_T<GAME::Mga::Folder> (child);
}