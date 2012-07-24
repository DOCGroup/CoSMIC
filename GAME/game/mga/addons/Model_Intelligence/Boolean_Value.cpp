// $Id$

#include "StdAfx.h"
#include "Boolean_Value.h"

//
// Default Constructor
//
Boolean_Value::Boolean_Value (bool val)
: val_ (val)
{
}

//
// Destructor
//
Boolean_Value::~Boolean_Value (void)
{
}

//
// is_equal
//
bool Boolean_Value::is_equal (Value * v)
{
	Boolean_Value * iv = dynamic_cast <Boolean_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ == iv->val_)
			return true;
	}
	return false;
}

//
// is_greater
//
bool Boolean_Value::is_greater (Value * v)
{
	return false;
}

//
// is_greater_equal
//
bool Boolean_Value::is_greater_equal (Value *v)
{
	Boolean_Value * iv = dynamic_cast <Boolean_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ == iv->val_)
			return true;
	}
	return false;
}

//
// is_lesser
//
bool Boolean_Value::is_lesser (Value * v)
{
	return false;
}

//
// is_lesser_equal
//
bool Boolean_Value::is_lesser_equal (Value * v)
{
	Boolean_Value * iv = dynamic_cast <Boolean_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ == iv->val_)
			return true;
	}
	return false;
}

//
// get_diff
//
bool Boolean_Value::get_diff (Value * v, double & count)
{
	return false;
}

//
// get_sum
//
bool Boolean_Value::get_sum (Value * v, double & count)
{
	return false;
}

//
// value
//
bool Boolean_Value::value (void)
{
  return this->val_;
}