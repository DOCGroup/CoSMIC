// $Id: Local_Value_Assignment_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

#include "StdAfx.h"

#include "Local_Value_Assignment_Expr.h"
//
// Constructor
//
Local_Value_Assignment_Expr::Local_Value_Assignment_Expr (std::string & var, 
																													Value_Expr * right)
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
bool Local_Value_Assignment_Expr::evaluate (Ocl_Context & res)
{
  this->value_ = this->rhs_->evaluate (res);

  // Storing it in the map
  res.locals[this->varname_] = this->value_;
  
  return true;
}

//
// filter_evaluate
//
bool Local_Value_Assignment_Expr::filter_evaluate (Ocl_Context & res, 
                                                   GAME::Mga::FCO & current)
{
  res.cur_fco = current;

  if (this->rhs_->is_filter ())
  {
    this->value_ = this->rhs_->filter_evaluate (res);

    // Storing it in the map
    res.locals[this->varname_] = this->value_;

    return true;
  }

  return false;
}

//
// value
//
Value * Local_Value_Assignment_Expr::value (void)
{
  return this->value_;
}

//
// is_association
//
bool Local_Value_Assignment_Expr::is_association (void)
{
  if (this->rhs_->is_association ())
    return true;

  return false;
}

//
// is_containment
//
bool Local_Value_Assignment_Expr::is_containment (void)
{
  if (this->rhs_->is_containment ())
    return true;

  return false;
}

//
// is_reference
//
bool Local_Value_Assignment_Expr::is_reference (void)
{
  if (this->rhs_->is_reference ())
    return true;

  return false;
}