// $Id$

#include "StdAfx.h"

#include "IsInstance_Method.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Boolean_Value.h"
#include "Object_Value.h"

//
// Constructor
//
IsInstance_Method::IsInstance_Method (void)
{
}

//
// Destructor
//
IsInstance_Method::~IsInstance_Method (void)
{
}

//
// evaluate
//
Value * IsInstance_Method::evaluate (Ocl_Context & res, 
                                     GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  bool type = obj->is_instance ();
  
  return new Boolean_Value (type);
	
}

//
// evaluate
//
Value * IsInstance_Method::evaluate (Ocl_Context & res, 
                                     Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  bool type = false;
  
	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();
    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

    type = obj->is_instance ();
  }
 
  return new Boolean_Value (type);
}

//
// is_filter
//
bool IsInstance_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool IsInstance_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool IsInstance_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool IsInstance_Method::is_reference (void)
{
  return false;
}