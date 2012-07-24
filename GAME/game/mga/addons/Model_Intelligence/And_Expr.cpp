// $Id: And_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

#include "StdAfx.h"
#include "And_Expr.h"

//
// Constructor
//
And_Expr::And_Expr (Equality_Expr * left, Equality_Expr * right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
And_Expr::~And_Expr (void)
{
}

//
// evaluate
//
bool And_Expr::evaluate (Ocl_Context & res)
{
  // Evaluating both sides
  bool left = this->lhs_->evaluate (res);
  bool right = this->rhs_->evaluate (res);

  if (left && right)
    return true;

  return false;
}

//
// filter_evaluate
//
bool And_Expr::filter_evaluate (Ocl_Context & res, GAME::Mga::FCO & current)
{
  // Setting the current FCO
  res.cur_fco = current;

  // Evaluating both sides
  bool left = this->lhs_->filter_evaluate (res, current);
  bool right = this->rhs_->filter_evaluate (res, current);

  if (left && right)
    return true;

  return false;
}

//
// is_containment
//
bool And_Expr::is_containment (void)
{
  if (this->lhs_->is_containment () && this->rhs_->is_containment ())
    return true;

  return false;
}

//
// is_association
//
bool And_Expr::is_association (void)
{
  if (this->lhs_->is_association () && this->rhs_->is_association ())
    return true;

  return false;
}

//
// is_reference
//
bool And_Expr::is_reference (void)
{
  if (this->lhs_->is_reference () && this->rhs_->is_reference ())
    return true;

  return false;
}
