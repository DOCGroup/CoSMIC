// $Id$

#include "StdAfx.h"

#include "Local_Value_Assignment_Expr.h"
//
// Constructor
//
Local_Value_Assignment_Expr::Local_Value_Assignment_Expr (std::string var, Value_Expr *right)
: varname_ (var),
  rhs_ (right)
{
}

//
// Destructor
//
Local_Value_Assignment_Expr::~Local_Value_Assignment_Expr (void)
{
}

//
// evaluate
//
bool Local_Value_Assignment_Expr::evaluate (Ocl_Context &res)
{
  this->value_ = this->rhs_->evaluate (res);

  size_t count = this->value_;

  // Storing it in the map
  res.locals[this->varname_] = this->value_;
  
  return true;
}

//
// value
//
size_t Local_Value_Assignment_Expr::value (void)
{
  return this->value_;
}