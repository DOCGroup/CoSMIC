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

Value * Local_Value_Method_Call::evaluate (Ocl_Context &res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.locals[this->var_];
	Value *v = Method_Call::evaluate (res);	

	return v;
}
