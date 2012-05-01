// $Id$

#include "StdAfx.h"

#include "Local_Value_Expr.h"
#include "Int_Value.h"

//
// Constructor
//
Local_Value_Expr::Local_Value_Expr (std::string &var)
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
Value * Local_Value_Expr::evaluate (Ocl_Context &res)
{   
	return res.locals[this->localvar_];
}

//
// is_mutable
//
bool Local_Value_Expr::is_mutable (void)
{
  return true;
}