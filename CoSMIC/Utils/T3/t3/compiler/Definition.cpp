// $Id$

#include "Definition.h"
#include "Node.h"

//
// operator =
//
const T3_Definition & T3_Definition::operator = (const T3_Definition & rhs)
{
  if (this == &rhs)
    return *this;

  this->head_ = rhs.head_;
  this->tail_ = rhs.tail_;
  this->size_ = rhs.size_;

  return *this;
}

//
// append_node
//
int T3_Definition::append_node (T3_Node * node)
{
  if (0 == this->head_)
  {
    // This is the first node in the definition.
    this->head_ = node;
    this->tail_ = this->head_;
  }
  else
  {
    // Place the node at the end of the definition.
    this->tail_->next (node);
    this->tail_ = node;
  }

  // Increment the definition's size.
  ++ this->size_;

  return 0;
}
