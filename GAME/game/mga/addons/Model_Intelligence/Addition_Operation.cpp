// $Id:  $

#include "StdAfx.h"
#include "Addition_Operation.h"
#include "Double_Value.h"

//
// Constructor
//
Addition_Operation::Addition_Operation (Value_Expr *left, Value_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Addition_Operation::~Addition_Operation (void)
{
}

//
// evaluate
//
Value * Addition_Operation::evaluate (Ocl_Context &res)
{
  // Adding the values of both expressions
	double count;
	this->lhs_->evaluate (res)->get_sum (this->rhs_->evaluate (res), count);

  return new Double_Value (count);
}

//
// filter_evaluate
//
Value * Addition_Operation::filter_evaluate (Ocl_Context &res)
{
  // Adding the values of both expressions
  double count;
  this->lhs_->filter_evaluate (res)->get_sum (this->rhs_->filter_evaluate (res), count);

  return new Double_Value (count);
}

//
// is_mutable
//
bool Addition_Operation::is_mutable (void)
{
  return true;
}

//
// is_filter
//
bool Addition_Operation::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Addition_Operation::is_association (void)
{
  return false;
}

//
// is_reference
//
bool Addition_Operation::is_reference (void)
{
  return false;
}

//
// is_containment
//
bool Addition_Operation::is_containment (void)
{
  return true;
}