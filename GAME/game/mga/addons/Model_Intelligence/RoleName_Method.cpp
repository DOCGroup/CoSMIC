// $Id$

#include "StdAfx.h"

#include "RoleName_Method.h"
#include "String_Value.h"
#include "Object_Value.h"

//
// Constructor
//
RoleName_Method::RoleName_Method (void)
{
}

//
// Destructor
//
RoleName_Method::~RoleName_Method (void)
{
}

//
// evaluate
//
Value * RoleName_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	GAME::Mga::FCO nar = GAME::Mga::FCO::_narrow (caller);
	std::string name = nar->role ()->name ();
	return new String_Value (name);
}

//
// evaluate
//
Value * RoleName_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::string name = "";

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
		GAME::Mga::FCO nar = GAME::Mga::FCO::_narrow (obj);
		name = nar->role ()->name ();
	}

	return new String_Value (name);
}

//
// is_filter
//
bool RoleName_Method::is_filter (void)
{
  return false;
}