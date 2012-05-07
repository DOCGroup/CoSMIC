// $Id$

#include "StdAfx.h"
#include "Local_Value_Method_Call.h"

//
// constructor
//
Local_Value_Method_Call::Local_Value_Method_Call (std::string &var,
																									Method *meth)
: meth_(meth),
  var_(var)
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
Value * Local_Value_Method_Call::evaluate (Ocl_Context &res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.locals[this->var_];
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
  Value *v = Method_Call::filter_evaluate (res);	

	return v;
}

//
// is_filter
//
bool Local_Value_Method_Call::is_filter (void)
{
  this->base_meth_ = this->meth_;
  bool flag = Method_Call::is_filter ();
  return flag;
}
