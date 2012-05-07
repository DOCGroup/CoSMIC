// $Id$

#include "StdAfx.h"
#include "Comparison_Expr.h"

//
// Constructor
//
Comparison_Expr::Comparison_Expr (void)
{
}

//
// Destructor
//
Comparison_Expr::~Comparison_Expr (void)
{
}

//
// dummy method
//
bool Comparison_Expr::evaluate (Ocl_Context &res)
{
  return true;
}

//
// dummy method
//
bool Comparison_Expr::filter_evaluate (Ocl_Context &res, GAME::Mga::FCO &current)
{
  return true;
}