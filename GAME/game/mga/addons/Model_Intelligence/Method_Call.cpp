// $Id$

#include "StdAfx.h"

#include "Method_Call.h"

//
// Constructor
//
Method_Call::Method_Call ()
: caller_ (0),
  base_meth_ (0),
	next_(0)
{
}

//
// Destructor
//
Method_Call::~Method_Call (void)
{
}

//
// evaluate
//
Value * Method_Call::evaluate (Ocl_Context &res)
{   
	// Calling the first method with the object
	Value *v = this->base_meth_->evaluate (res, this->caller_);
	
	// Calling the rest of the methods
	std::vector <Method *>::const_iterator
    iter = this->next_.begin (), iter_end = this->next_.end ();

	for (; iter != iter_end; ++ iter)
	{
		v = (*iter)->evaluate (res, v);
	}

	return v;
}

//
// filter_evaluate
//
Value * Method_Call::filter_evaluate (Ocl_Context &res)
{   
	// Calling the first method with the object
	Value *v = this->base_meth_->evaluate (res, this->caller_);
	
	// Calling the rest of the methods
	std::vector <Method *>::const_iterator
    iter = this->next_.begin (), iter_end = this->next_.end ();

	for (; iter != iter_end; ++ iter)
	{
		v = (*iter)->evaluate (res, v);
	}

	return v;
}

//
// set_next
//
void Method_Call::set_next (std::vector <Method *> &next)
{
	this->next_ = next;
}

//
// is_mutable
//
bool Method_Call::is_mutable (void)
{
  return true;
}

//
// is_filter
//
bool Method_Call::is_filter (void)
{
  bool flag = this->base_meth_->is_filter (); 

  if (flag)
    return true;
  else
  {
    // Calling the rest of the methods
    std::vector <Method *>::const_iterator
      iter = this->next_.begin (), iter_end = this->next_.end ();

    for (; iter != iter_end; ++ iter)
    {
      if ((*iter)->is_filter ())
        return true;
    }
  }

  return false;
}