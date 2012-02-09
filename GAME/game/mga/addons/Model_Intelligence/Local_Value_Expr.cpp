// $Id$

#include "StdAfx.h"

#include "Local_Value_Expr.h"

//
// Constructor
//
Local_Value_Expr::Local_Value_Expr (std::string var)
: localvar_ (var)
{
}

//
// Destructor
//
Local_Value_Expr::~Local_Value_Expr (void)
{
}

//
// evaluate
//
unsigned int Local_Value_Expr::evaluate (Ocl_Context &res)
{   
  return res.locals[this->localvar_];
}

//
// ismutable
//
bool Local_Value_Expr::ismutable (void)
{
  return true;
}