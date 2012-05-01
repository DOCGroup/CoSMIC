// $Id:  $

#include "StdAfx.h"

#include "KindName_Method.h"
#include "String_Value.h"
#include "Object_Value.h"

//
// Constructor
//
KindName_Method::KindName_Method (void)
{
}

//
// Destructor
//
KindName_Method::~KindName_Method (void)
{
}

//
// evaluate
//
Value * KindName_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	std::string name = caller->meta()->name ();
	return new String_Value (name);
}

//
// evaluate
//
Value * KindName_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::string name = "";

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
		name = obj->name ();
	}

	return new String_Value (name);
}