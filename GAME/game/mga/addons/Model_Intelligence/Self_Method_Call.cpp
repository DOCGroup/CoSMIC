// $Id$

#include "StdAfx.h"
#include "Self_Method_Call.h"

//
// constructor
//
Self_Method_Call::Self_Method_Call (Method *meth)
: meth_(meth)
{
}

//
// Destructor
//
Self_Method_Call::~Self_Method_Call (void)
{
}

//
// evaluate
//
Value * Self_Method_Call::evaluate (Ocl_Context &res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.self;
	Value * v = Method_Call::evaluate (res);

	return v;
}

//
// filter_evaluate
//
Value * Self_Method_Call::filter_evaluate (Ocl_Context &res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.self;
  Value * v = Method_Call::filter_evaluate (res);

	return v;
}

//
// is_filter
//
bool Self_Method_Call::is_filter (void)
{
  this->base_meth_ = this->meth_;
  bool flag = Method_Call::is_filter ();
  return flag;
}
