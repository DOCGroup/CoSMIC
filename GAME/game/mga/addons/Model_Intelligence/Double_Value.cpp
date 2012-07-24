// $Id$

#include "StdAfx.h"
#include "Double_Value.h"
#include "Int_Value.h"

//
// Default Constructor
//
Double_Value::Double_Value (double val)
: val_ (val)
{
}

//
// Destructor
//
Double_Value::~Double_Value (void)
{
}

//
// is_equal
//
bool Double_Value::is_equal (Value * v)
{
	Double_Value * iv = dynamic_cast <Double_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ == iv->val_)
			return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      if (this->val_ == iv->value ())
        return true;
    }
  }
	return false;
}

//
// is_greater
//
bool Double_Value::is_greater (Value * v)
{
	Double_Value * iv = dynamic_cast <Double_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ > iv->val_)
			return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      if (this->val_ > iv->value ())
        return true;
    }
  }
	return false;
}

//
// is_greater_equal
//
bool Double_Value::is_greater_equal (Value * v)
{
	Double_Value * iv = dynamic_cast <Double_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ >= iv->val_)
			return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      if (this->val_ >= iv->value ())
        return true;
    }
  }
	return false;
}

//
// is_lesser
//
bool Double_Value::is_lesser (Value * v)
{
	Double_Value * dv = dynamic_cast <Double_Value *> (v);

	if (dv != 0)
	{
		if (this->val_ < dv->val_)
			return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      if (this->val_ < iv->value ())
        return true;
    }
  }
	return false;
}

//
// is_lesser_equal
//
bool Double_Value::is_lesser_equal (Value * v)
{
	Double_Value * iv = dynamic_cast <Double_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ <= iv->val_)
			return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      if (this->val_ <= iv->value ())
        return true;
    }
  }
	return false;
}

//
// get_diff
//
bool Double_Value::get_diff (Value * v, double & count)
{
	Double_Value * dv = dynamic_cast <Double_Value *> (v);

	if (dv != 0)
	{
		count = this->val_ - dv->val_;
		return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      count = this->val_ - iv->value ();
      return true;
    }
  }
	return false;
}

//
// get_sum
//
bool Double_Value::get_sum (Value * v, double & count)
{
	Double_Value * iv = dynamic_cast <Double_Value *> (v);

	if (iv != 0)
	{
		count = this->val_ + iv->val_;
		return true;
	}
  else
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (v);
    if (iv != 0)
    {
      count = this->val_ + iv->value ();
      return true;
    }
  }
	return false;
}

//
// value
//
double Double_Value::value (void)
{
  return this->val_;
}

