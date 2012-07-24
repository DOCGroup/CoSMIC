// $Id$

#include "StdAfx.h"

#include "IsFCO_Method.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Boolean_Value.h"
#include "Object_Value.h"

//
// Constructor
//
IsFCO_Method::IsFCO_Method (void)
{
}

//
// Destructor
//
IsFCO_Method::~IsFCO_Method (void)
{
}

//
// evaluate
//
Value * IsFCO_Method::evaluate (Ocl_Context & res, 
                                GAME::Mga::Object caller)
{
  size_t val = caller->meta ()->type ();

  // Returning true if the invoking object is a FCO
  if ((val == OBJTYPE_MODEL) || (val == OBJTYPE_ATOM) ||
       (val == OBJTYPE_REFERENCE) || (val == OBJTYPE_CONNECTION))
    return new Boolean_Value (true);

  return new Boolean_Value (false);
	
}

//
// evaluate
//
Value * IsFCO_Method::evaluate (Ocl_Context & res, 
                                Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

    size_t val = obj->meta ()->type ();

    if ((val == OBJTYPE_MODEL) || (val == OBJTYPE_ATOM) ||
       (val == OBJTYPE_REFERENCE) || (val == OBJTYPE_CONNECTION))
       return new Boolean_Value (true);    
  }
 
  return new Boolean_Value (false);
}

//
// is_filter
//
bool IsFCO_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool IsFCO_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool IsFCO_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool IsFCO_Method::is_reference (void)
{
  return false;
}