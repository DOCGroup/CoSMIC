// $Id$

#include "StdAfx.h"

#include "Target_Method.h"
#include "String_Value.h"
#include "Object_Value.h"
#include "Connection.h"

//
// Constructor
//
Target_Method::Target_Method (void)
{
}

//
// Destructor
//
Target_Method::~Target_Method (void)
{
}

//
// evaluate
//
Value * Target_Method::evaluate (Ocl_Context & res, 
                                 GAME::Mga::Object caller)
{
  GAME::Mga::ConnectionPoint cpt = GAME::Mga::ConnectionPoint::_narrow (caller);
  GAME::Mga::FCO target = cpt->target ();
	return new Object_Value (target);
}

//
// evaluate
//
Value * Target_Method::evaluate (Ocl_Context & res, 
                                 Value * caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::string name = "";
  GAME::Mga::FCO target;

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
    GAME::Mga::ConnectionPoint cpt = GAME::Mga::ConnectionPoint::_narrow (obj);
    target = cpt->target ();
	}
  
  return new Object_Value (target);
}

//
// is_filter
//
bool Target_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Target_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Target_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Target_Method::is_reference (void)
{
  return false;
}