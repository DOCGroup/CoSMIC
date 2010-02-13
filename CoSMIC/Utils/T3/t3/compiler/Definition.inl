// -*- C++ -*-
// $Id$

//
// T3_Definition
//
inline
T3_Definition::T3_Definition (void)
: head_ (0),
  tail_ (0),
  size_ (0)
{

}

//
// T3_Definition
//
inline
T3_Definition::T3_Definition (const T3_Definition & def)
: head_ (def.head_),
  tail_ (def.tail_),
  size_ (def.size_)
{

}

//
// ~T3_Definition
//
inline
T3_Definition::~T3_Definition (void)
{

}

//
// start
//
inline
T3_Node * T3_Definition::start (void) const
{
  return this->head_;
}

////
//// operator +=
////
//inline
//void T3_Definition::operator += (T3_Node * node)
//{
//  this->append_node (node);
//}
