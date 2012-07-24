// $Id$

#include "StdAfx.h"
#include "Local_Value_Method_Call.h"

//
// constructor
//
Local_Value_Method_Call::Local_Value_Method_Call (std::string & var,
																									Method * meth)
: meth_ (meth),
  var_ (var)
{
}

//
// Destructor
//
Local_Value_Method_Call::~Local_Value_Method_Call (void)
{
}

//
// evaluate
//
Value * Local_Value_Method_Call::evaluate (Ocl_Context & res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.locals[this->var_];

  // Invoking the evaluate method on MethodCall
	Value *v = Method_Call::evaluate (res);	

	return v;
}

//
// filter_evaluate
//
Value * Local_Value_Method_Call::filter_evaluate (Ocl_Context &res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.cur_fco;

  // Invoking the filter evaluate method on MethodCall
  Value *v = Method_Call::filter_evaluate (res);	

	return v;
}

//
// is_filter
//
bool Local_Value_Method_Call::is_filter (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_filter method on MethodCall
  bool flag = Method_Call::is_filter ();
  return flag;
}

//
// is_association
//
bool Local_Value_Method_Call::is_association (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_association method on MethodCall
  bool flag = Method_Call::is_association ();
  return flag;
}

//
// is_containment
//
bool Local_Value_Method_Call::is_containment (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_containment method on MethodCall
  bool flag = Method_Call::is_containment ();
  return flag;
}

//
// is_reference
//
bool Local_Value_Method_Call::is_reference (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_reference method on MethodCall
  bool flag = Method_Call::is_reference ();
  return flag;
}