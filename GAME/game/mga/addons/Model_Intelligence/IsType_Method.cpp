// $Id$

#include "StdAfx.h"

#include "IsType_Method.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Boolean_Value.h"
#include "Object_Value.h"

//
// Constructor
//
IsType_Method::IsType_Method (void)
{
}

//
// Destructor
//
IsType_Method::~IsType_Method (void)
{
}

//
// evaluate
//
Value * IsType_Method::evaluate (Ocl_Context & res, 
                                 GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  // Checking if the invoking object is a subtype
  bool type = obj->is_subtype ();
  
  return new Boolean_Value (type);
	
}

//
// evaluate
//
Value * IsType_Method::evaluate (Ocl_Context & res, 
                                 Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  bool type = false;
  
	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();
    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

    // Checking if the invoking object is a subtype
    type = obj->is_subtype ();
  }
 
  return new Boolean_Value (type);
}

//
// is_filter
//
bool IsType_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool IsType_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool IsType_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool IsType_Method::is_reference (void)
{
  return false;
}