// $Id$

#include "StdAfx.h"

#include "Owner_Method.h"
#include "String_Value.h"
#include "Object_Value.h"
#include "Connection.h"

//
// Constructor
//
Owner_Method::Owner_Method (void)
{
}

//
// Destructor
//
Owner_Method::~Owner_Method (void)
{
}

//
// evaluate
//
Value * Owner_Method::evaluate (Ocl_Context & res, 
                                GAME::Mga::Object caller)
{
  GAME::Mga::ConnectionPoint cpt = GAME::Mga::ConnectionPoint::_narrow (caller);
  GAME::Mga::Connection owner = cpt->owner ();
	return new Object_Value (owner);
}

//
// evaluate
//
Value * Owner_Method::evaluate (Ocl_Context & res, 
                                Value * caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::string name = "";
  GAME::Mga::FCO owner;

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
    GAME::Mga::ConnectionPoint cpt = GAME::Mga::ConnectionPoint::_narrow (obj);
    owner = cpt->owner ();
	}
  
  return new Object_Value (owner);
}

//
// is_filter
//
bool Owner_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Owner_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Owner_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Owner_Method::is_reference (void)
{
  return false;
}