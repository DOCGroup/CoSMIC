// -*- C++ -*-
// $Id$

//
// T3_Node
//
inline
T3_Node::T3_Node (void)
: next_ (0)
{

}

//
// ~T3_Node
//
inline
T3_Node::~T3_Node (void)
{

}

//
// next
//
inline
T3_Node * T3_Node::next (void) const
{
  return this->next_;
}

//
// next
//
inline
void T3_Node::next (T3_Node * next)
{
  this->next_ = next;
}

//
// is_end
//
inline
bool T3_Node::is_end (void) const
{
  return 0 == this->next_;
}

//
// length
//
inline
size_t T3_Node::length (void) const
{
  return this->is_end () ? 1 : 1 + this->next_->length ();
}
