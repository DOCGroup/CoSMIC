// $Id$

#include "StdAfx.h"

#include "Size_Method.h"
#include "Int_Value.h"
#include "Collection_Value_T.h"
#include "game/mga/Connection.h"

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
Value * Size_Method::evaluate (Ocl_Context & res, 
                               GAME::Mga::Object caller)
{
	return new Int_Value (0);
}

//
// evaluate
//
Value * Size_Method::evaluate (Ocl_Context & res, 
                               Value * caller)
{
  size_t s;
	Collection_Value_T <GAME::Mga::FCO> * iv = 
    dynamic_cast <Collection_Value_T <GAME::Mga::FCO> *> (caller);

  if (iv != 0)
    s = iv->size ();
  else
  {
    Collection_Value_T <GAME::Mga::Connection> * conn = 
      dynamic_cast <Collection_Value_T <GAME::Mga::Connection> *> (caller);

    s = conn->size ();
  }

	return new Int_Value (s);
}

//
// is_filter
//
bool Size_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Size_Method::is_association (void)
{
  return true;
}

//
// is_containment
//
bool Size_Method::is_containment (void)
{
  return true;
}

//
// is_reference
//
bool Size_Method::is_reference (void)
{
  return false;
}