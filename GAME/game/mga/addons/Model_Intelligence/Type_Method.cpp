// $Id$

#include "StdAfx.h"

#include "Type_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Object_Value.h"

//
// Constructor
//
Type_Method::Type_Method (void)
{
}

//
// Destructor
//
Type_Method::~Type_Method (void)
{
}

//
// evaluate
//
Value * Type_Method::evaluate (Ocl_Context & res, 
                               GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  GAME::Mga::FCO type = obj->instance_type ();
  
  return new Object_Value (type);
	
}

//
// evaluate
//
Value * Type_Method::evaluate (Ocl_Context & res, 
                               Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  GAME::Mga::FCO type;
  
	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();
    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

    type = obj->instance_type ();
  }
 
  return new Object_Value (type);
}

//
// is_filter
//
bool Type_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Type_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Type_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Type_Method::is_reference (void)
{
  return false;
}