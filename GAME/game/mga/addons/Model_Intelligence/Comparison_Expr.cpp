// $Id: Comparison_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

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
bool Comparison_Expr::evaluate (Ocl_Context & res)
{
  return true;
}

//
// dummy method
//
bool Comparison_Expr::filter_evaluate (Ocl_Context & res, 
                                       GAME::Mga::FCO & current)
{
  return true;
}

//
// dummy method
//
bool Comparison_Expr::is_association (void)
{
  return true;
}

//
// dummy method
//
bool Comparison_Expr::is_containment (void)
{
  return true;
}

//
// dummy method
//
bool Comparison_Expr::is_reference (void)
{
  return true;
}