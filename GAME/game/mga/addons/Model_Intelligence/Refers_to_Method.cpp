// $Id$

#include "StdAfx.h"

#include "Refers_to_Method.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Reference.h"

//
// Constructor
//
Refers_to_Method::Refers_to_Method (void)
{
}

//
// Destructor
//
Refers_to_Method::~Refers_to_Method (void)
{
}

//
// evaluate
//
Value * Refers_to_Method::evaluate (Ocl_Context & res, 
                                    GAME::Mga::Object caller)
{
	GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (caller);

	return new Object_Value (ref->refers_to ());
}

//
// evaluate
//
Value * Refers_to_Method::evaluate (Ocl_Context & res, 
                                    Value * caller)
{
	return new Int_Value (0);
}

//
// is_filter
//
bool Refers_to_Method::is_filter (void)
{
  return true;
}

//
// is_association
//
bool Refers_to_Method::is_association (void)
{
  return true;
}

//
// is_containment
//
bool Refers_to_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Refers_to_Method::is_reference (void)
{
  return true;
}