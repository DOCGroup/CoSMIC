// $Id$

#include "StdAfx.h"

#include "Constant_Value_Expr.h"

//
// Constructor
//
Constant_Value_Expr::Constant_Value_Expr (unsigned int value)
: value_ (value)
{
}

//
// Destructor
//
Constant_Value_Expr::~Constant_Value_Expr (void)
{
}

//
// evaluate
//
unsigned int Constant_Value_Expr::evaluate (Ocl_Context &res)
{
  return this->value_;
}

//
// ismutable
//
bool Constant_Value_Expr::ismutable (void)
{
  return false;
}
