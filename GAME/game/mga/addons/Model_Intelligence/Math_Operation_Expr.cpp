// $Id:  $

#include "StdAfx.h"
#include "Math_Operation_Expr.h"
#include "Int_Value.h"

//
// Constructor
//
Math_Operation_Expr::Math_Operation_Expr (void)
{
}

//
// Destructor
//
Math_Operation_Expr::~Math_Operation_Expr (void)
{
}

//
// dummy evaluate method
//
Value * Math_Operation_Expr::evaluate (Ocl_Context & res)
{
  return new Int_Value (0);
}

//
// dummy filter evaluate method
//
Value * Math_Operation_Expr::filter_evaluate (Ocl_Context & res)
{
  return new Int_Value (0);
}

//
// dummy is_mutable method
//
bool Math_Operation_Expr::is_mutable (void)
{
  return true;
}

//
// dummy is_filter method
//
bool Math_Operation_Expr::is_filter (void)
{
  return true;
}

//
// dummy method
//
bool Math_Operation_Expr::is_association (void)
{
  return true;
}

//
// dummy method
//
bool Math_Operation_Expr::is_containment (void)
{
  return true;
}

//
// dummy method
//
bool Math_Operation_Expr::is_reference (void)
{
  return true;
}