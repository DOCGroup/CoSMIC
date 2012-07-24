// $Id: Constant_Value_Expr.cpp 2902 2012-05-07 03:08:44Z tpati $

#include "StdAfx.h"
#include "Int_Value.h"
#include "String_Value.h"
#include "Constant_Value_Expr.h"

//
// Constructor
//
Constant_Value_Expr::Constant_Value_Expr (unsigned int & value)
: value_ (value)
{
	this->flag = 1;
}

//
// Constructor
//
Constant_Value_Expr::Constant_Value_Expr (std::string & str)
: str_ (str)
{
	this->flag = 2;
}

//
// Destructor
//
Constant_Value_Expr::~Constant_Value_Expr (void)
{
}

//
// evaluate
//
Value * Constant_Value_Expr::evaluate (Ocl_Context & res)
{
	if (this->flag == 1)
		return new Int_Value (this->value_);

	return new String_Value (this->str_);
}

//
// filter_evaluate
//
Value * Constant_Value_Expr::filter_evaluate (Ocl_Context & res)
{
	if (this->flag == 1)
		return new Int_Value (this->value_);

	return new String_Value (this->str_);
}

//
// is_mutable
//
bool Constant_Value_Expr::is_mutable (void)
{
  return false;
}

//
// is_filter
//
bool Constant_Value_Expr::is_filter (void)
{
  return true;
}

//
// is_association
//
bool Constant_Value_Expr::is_association (void)
{
  return true;
}

//
// is_containment
//
bool Constant_Value_Expr::is_containment (void)
{
  return true;
}

//
// is_reference
//
bool Constant_Value_Expr::is_reference (void)
{
  return true;
}