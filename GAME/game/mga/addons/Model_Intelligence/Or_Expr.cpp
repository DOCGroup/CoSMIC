// $Id: And_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

#include "StdAfx.h"
#include "Or_Expr.h"

//
// Constructor
//
Or_Expr::Or_Expr (Equality_Expr * left, Equality_Expr * right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Or_Expr::~Or_Expr (void)
{
}

//
// evaluate
//
bool Or_Expr::evaluate (Ocl_Context & res)
{
  bool left = this->lhs_->evaluate (res);
  bool right = this->rhs_->evaluate (res);

  if (left || right)
    return true;

  return false;
}

//
// filter_evaluate
//
bool Or_Expr::filter_evaluate (Ocl_Context & res, GAME::Mga::FCO & current)
{
  // Setting the current FCO in model intelligence context
  res.cur_fco = current;
  bool left = this->lhs_->filter_evaluate (res, current);
  bool right = this->rhs_->filter_evaluate (res, current);

  if (left || right)
    return true;

  return false;
}

//
// is_containment
//
bool Or_Expr::is_containment (void)
{
  if (this->lhs_->is_containment () && this->rhs_->is_containment ())
    return true;

  return false;
}

//
// is_association
//
bool Or_Expr::is_association (void)
{
  if (this->lhs_->is_association () && this->rhs_->is_association ())
    return true;

  return false;
}

//
// is_reference
//
bool Or_Expr::is_reference (void)
{
  if (this->lhs_->is_reference () && this->rhs_->is_reference ())
    return true;

  return false;
}

