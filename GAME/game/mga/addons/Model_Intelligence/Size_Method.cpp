// $Id$

#include "StdAfx.h"

#include "Size_Method.h"
#include "Int_Value.h"
#include "Collection_Value_T.h"

//
// Constructor
//
Size_Method::Size_Method (void)
{
}

//
// Destructor
//
Size_Method::~Size_Method (void)
{
}

//
// evaluate
//
Value * Size_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	return new Int_Value (0);
}

//
// evaluate
//
Value * Size_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Collection_Value_T<GAME::Mga::FCO> * iv = dynamic_cast <Collection_Value_T<GAME::Mga::FCO> *> (caller);

	size_t s = iv->size ();

	return new Int_Value (s);
}