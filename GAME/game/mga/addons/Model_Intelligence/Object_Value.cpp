// $Id:  $

#include "StdAfx.h"
#include "Object_Value.h"

//
// Default Constructor
//
Object_Value::Object_Value (GAME::Mga::Object val)
: val_ (val)
{
}

//
// Destructor
//
Object_Value::~Object_Value (void)
{
}

//
// value
//
GAME::Mga::Object Object_Value::value (void)
{
	return this->val_;
}

//
// is_equal
//
bool Object_Value::is_equal (Value * v)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (v);

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
bool Object_Value::is_greater (Value * v)
{
	return false;
}

//
// is_greater_equal
//
bool Object_Value::is_greater_equal (Value * v)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (v);

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
bool Object_Value::is_lesser (Value * v)
{
	return false;
}

//
// is_lesser_equal
//
bool Object_Value::is_lesser_equal (Value * v)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (v);

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
bool Object_Value::get_diff (Value * v, double & count)
{
	return false;
}

//
// get_sum
//
bool Object_Value::get_sum (Value * v, double & count)
{
	return false;
}

