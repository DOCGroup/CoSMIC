// $Id$

#include "StdAfx.h"

#include "Size_Method_Expr.h"

Size_Method_Expr::Size_Method_Expr (Collection_Expr *coll)
: coll_(coll)
{
}

Size_Method_Expr::~Size_Method_Expr (void)
{
}

//
// evaluate
//
unsigned int Size_Method_Expr::evaluate (Ocl_Context &res)
{
  // Create an empty vector and have it hold the collection
  std::vector <GAME::Mga::FCO> parts;
  this->coll_->evaluate (parts, res);

  return parts.size ();
}

//
// ismutable
//
bool Size_Method_Expr::ismutable (void)
{
  return true;
}