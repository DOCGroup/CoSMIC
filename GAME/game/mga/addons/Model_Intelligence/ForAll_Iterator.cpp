// $Id$

#include "StdAfx.h"
#include "ForAll_Iterator.h"
#include "Boolean_Value.h"

//
// Constructor
//
ForAll_Iterator::ForAll_Iterator (void)
{
}

//
// Destructor
//
ForAll_Iterator::~ForAll_Iterator (void)
{
}

//
// evaluate
//
Value * ForAll_Iterator::evaluate (Ocl_Context & res)
{
  return new Boolean_Value (true);
}