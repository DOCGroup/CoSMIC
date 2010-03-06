#ifndef _BOOLEAN_TYPE_IMPL_H_
#define _BOOLEAN_TYPE_IMPL_H_

#include "boolean_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * boolean_type <IteratorT>::strlit_ [] =
{
  "Boolean"
};

template <typename IteratorT>
boolean_type <IteratorT>::boolean_type (void)
: base_type (boolean_type_)
{
  this->boolean_type_ =
    qi::lit ("boolean")[T3::store_predefined_reference (this->strlit_[0])];
}

#endif  // !defined _BOOLEAN_TYPE_IMPL_H_
