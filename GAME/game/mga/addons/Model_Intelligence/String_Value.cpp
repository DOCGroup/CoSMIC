// $Id$

#include "StdAfx.h"
#include "String_Value.h"
#include <string>

//
// Default Constructor
//
String_Value::String_Value (std::string & val)
: val_ (val)
{
}

//
// Destructor
//
String_Value::~String_Value (void)
{
}

//
// is_equal
//
bool String_Value::is_equal (Value * v)
{
	String_Value * iv = dynamic_cast <String_Value *> (v);

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
bool String_Value::is_greater (Value * v)
{
	return false;
}

//
// is_greater_equal
//
bool String_Value::is_greater_equal (Value * v)
{
	String_Value * iv = dynamic_cast <String_Value *> (v);

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
bool String_Value::is_lesser (Value * v)
{
	return false;
}

//
// is_lesser_equal
//
bool String_Value::is_lesser_equal (Value * v)
{
	String_Value * iv = dynamic_cast <String_Value *> (v);

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
bool String_Value::get_diff (Value * v, double & count)
{
	return false;
}

//
// get_sum
//
bool String_Value::get_sum (Value * v, double & count)
{
	return false;
}

//
// value
//
std::string String_Value::value (void)
{
  return this->val_;
}

