// $Id$

#include "StdAfx.h"
#include "And_Expr.h"

//
// Constructor
//
And_Expr::And_Expr (Equality_Expr *left, Equality_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
And_Expr::~And_Expr ()
{
}

//
// evaluate
//
bool And_Expr::evaluate (Ocl_Context &res)
{
  bool left = this->lhs_->evaluate (res);
  bool right = this->rhs_->evaluate (res);

  if (left == right)
    return true;

  return false;
}
