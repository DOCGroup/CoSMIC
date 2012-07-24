// $Id$

#include "StdAfx.h"
#include "Self_Method_Call.h"

//
// constructor
//
Self_Method_Call::Self_Method_Call (Method * meth)
: meth_ (meth)
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
Value * Self_Method_Call::evaluate (Ocl_Context & res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.self;

  // Invoking the evaluate method in Method_Call class
	Value * v = Method_Call::evaluate (res);

	return v;
}

//
// filter_evaluate
//
Value * Self_Method_Call::filter_evaluate (Ocl_Context & res)
{
	this->base_meth_ = this->meth_;
	this->caller_ = res.self;

  // Invoking the filter_evaluate method in Method_Call class
  Value * v = Method_Call::filter_evaluate (res);

	return v;
}

//
// is_filter
//
bool Self_Method_Call::is_filter (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_filter method in Method_Call class
  bool flag = Method_Call::is_filter ();
  return flag;
}

//
// is_association
//
bool Self_Method_Call::is_association (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_association method in Method_Call class
  bool flag = Method_Call::is_association ();
  return flag;
}

//
// is_containment
//
bool Self_Method_Call::is_containment (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_containment method in Method_Call class
  bool flag = Method_Call::is_containment ();
  return flag;
}

//
// is_reference
//
bool Self_Method_Call::is_reference (void)
{
  this->base_meth_ = this->meth_;

  // Invoking the is_reference method in Method_Call class
  bool flag = Method_Call::is_reference ();
  return flag;
}
