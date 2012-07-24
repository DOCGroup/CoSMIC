// $Id$

#include "StdAfx.h"

#include "Parent_Method.h"
#include "Object_Value.h"

//
// Constructor
//
Parent_Method::Parent_Method (void)
{
}

//
// Destructor
//
Parent_Method::~Parent_Method (void)
{
}

//
// evaluate
//
Value * Parent_Method::evaluate (Ocl_Context & res, 
                                 GAME::Mga::Object caller)
{
	GAME::Mga::Object parent = caller->parent();
	return new Object_Value (parent);
}

//
// evaluate
//
Value * Parent_Method::evaluate (Ocl_Context & res, 
                                 Value * caller)
{
	GAME::Mga::Object parent;
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	
	if (iv != 0)
	{
		parent = iv->value ()->parent ();
	}

	return new Object_Value (parent);
}

//
// is_filter
//
bool Parent_Method::is_filter (void)
{
  return true;
}

//
// is_association
//
bool Parent_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Parent_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Parent_Method::is_reference (void)
{
  return true;
}