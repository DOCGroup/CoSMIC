// $Id$

#include "StdAfx.h"
#include "Long_Value.h"

//
// Default Constructor
//
Long_Value::Long_Value (long val)
: val_ (val)
{
}

//
// Destructor
//
Long_Value::~Long_Value (void)
{
}

//
// is_equal
//
bool Long_Value::is_equal (Value *v)
{
	Long_Value * iv = 0;
	iv = dynamic_cast <Long_Value *> (v);

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
bool Long_Value::is_greater (Value * v)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ > iv->val_)
			return true;
	}
	return false;
}

//
// is_greater_equal
//
bool Long_Value::is_greater_equal (Value * v)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ >= iv->val_)
			return true;
	}
	return false;
}

//
// is_lesser
//
bool Long_Value::is_lesser (Value * v)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ < iv->val_)
			return true;
	}
	return false;
}

//
// is_lesser_equal
//
bool Long_Value::is_lesser_equal (Value * v)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ <= iv->val_)
			return true;
	}
	return false;
}

//
// get_diff
//
bool Long_Value::get_diff (Value * v, double & count)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		count = this->val_ - iv->val_;
		return true;
	}
	return false;
}

//
// get_sum
//
bool Long_Value::get_sum (Value * v, double & count)
{
	Long_Value * iv = dynamic_cast <Long_Value *> (v);

	if (iv != 0)
	{
		count = this->val_ + iv->val_;
		return true;
	}
	return false;
}

