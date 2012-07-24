// $Id$

#include "StdAfx.h"
#include "Int_Value.h"
#include "Double_Value.h"

//
// Default Constructor
//
Int_Value::Int_Value (unsigned int val)
: val_ (val)
{
}

//
// Destructor
//
Int_Value::~Int_Value (void)
{
}

//
// is_equal
//
bool Int_Value::is_equal (Value *v)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ == iv->val_)
			return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      if (this->val_ == dv->value ())
        return true;
    }
  }
	return false;
}

//
// is_greater
//
bool Int_Value::is_greater (Value * v)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ > iv->val_)
			return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      if (this->val_ > dv->value ())
        return true;
    }
  }

	return false;
}

//
// is_greater_equal
//
bool Int_Value::is_greater_equal (Value * v)
{
	Int_Value * iv = dynamic_cast <Int_Value * > (v);

	if (iv != 0)
	{
		if (this->val_ >= iv->val_)
			return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      if (this->val_ >= dv->value ())
        return true;
    }
  }
	return false;
}

//
// is_lesser
//
bool Int_Value::is_lesser (Value *v)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ < iv->val_)
			return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      if (this->val_ < dv->value ())
        return true;
    }
  }

	return false;
}

//
// is_lesser_equal
//
bool Int_Value::is_lesser_equal (Value * v)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		if (this->val_ <= iv->val_)
			return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      if (this->val_ <= dv->value ())
        return true;
    }
  }

	return false;
}

//
// get_diff
//
bool Int_Value::get_diff (Value * v, double & count)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		count = this->val_ - iv->val_;
		return true;
	}
  else 
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      count = this->val_ - dv->value ();
      return true;
    }
  }
	return false;
}

//
// get_sum
//
bool Int_Value::get_sum (Value * v, double & count)
{
	Int_Value * iv = dynamic_cast <Int_Value *> (v);

	if (iv != 0)
	{
		count = this->val_ + iv->val_;
		return true;
	}
  else
  {
    Double_Value * dv = dynamic_cast <Double_Value *> (v);
    if (dv != 0)
    {
      count = this->val_ + dv->value ();
      return true;
    }
  }
	return false;
}

//
// value
//
int Int_Value::value (void)
{
  return this->val_;
}

