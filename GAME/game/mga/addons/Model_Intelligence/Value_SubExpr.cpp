// $Id:  $

#include "StdAfx.h"
#include "Value_SubExpr.h"
#include "Int_Value.h"

//
// Constructor
//
Value_SubExpr::Value_SubExpr (void)
{
}

//
// Destructor
//
Value_SubExpr::~Value_SubExpr (void)
{
}

//
// dummy evaluate method
//
Value * Value_SubExpr::evaluate (Ocl_Context & res)
{
  return new Int_Value (0);
}

//
// dummy filter evaluate method
//
Value * Value_SubExpr::filter_evaluate (Ocl_Context & res)
{
  return new Int_Value (0);
}

//
// dummy is_mutable method
//
bool Value_SubExpr::is_mutable (void)
{
  return true;
}

//
// dummy is_filter method
//
bool Value_SubExpr::is_filter (void)
{
  return true;
}

//
// dummy method
//
bool Value_SubExpr::is_association (void)
{
  return true;
}

//
// dummy method
//
bool Value_SubExpr::is_containment (void)
{
  return true;
}

//
// dummy method
//
bool Value_SubExpr::is_reference (void)
{
  return true;
}