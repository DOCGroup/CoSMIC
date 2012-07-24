// $Id: Conjunction_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

#include "StdAfx.h"
#include "Conjunction_Expr.h"

//
// Constructor
//
Conjunction_Expr::Conjunction_Expr (void)
{
}

//
// Destructor
//
Conjunction_Expr::~Conjunction_Expr (void)
{
}

//
// dummy method
//
bool Conjunction_Expr::evaluate (Ocl_Context & res)
{
  return true;
}

//
// dummy method
//
bool Conjunction_Expr::filter_evaluate (Ocl_Context & res, 
                                        GAME::Mga::FCO & current)
{
  return true;
}

//
// dummy method
//
bool Conjunction_Expr::is_association (void)
{
  return true;
}

//
// dummy method
//
bool Conjunction_Expr::is_containment (void)
{
  return true;
}

//
// dummy method
//
bool Conjunction_Expr::is_reference (void)
{
  return true;
}