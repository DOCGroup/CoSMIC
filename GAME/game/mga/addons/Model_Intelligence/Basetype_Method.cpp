// $Id$

#include "StdAfx.h"

#include "Basetype_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Object_Value.h"

//
// Constructor
//
Basetype_Method::Basetype_Method (void)
{
}

//
// Destructor
//
Basetype_Method::~Basetype_Method (void)
{
}

//
// evaluate
//
Value * Basetype_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  GAME::Mga::FCO type = obj->basetype ();
  
  return new Object_Value (type);
	
}

//
// evaluate
//
Value * Basetype_Method::evaluate (Ocl_Context &res, Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  GAME::Mga::FCO type;
  
	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();
    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

    type = obj->basetype ();
  }
 
  return new Object_Value (type);
}

//
// is_filter
//
bool Basetype_Method::is_filter (void)
{
  return false;
}