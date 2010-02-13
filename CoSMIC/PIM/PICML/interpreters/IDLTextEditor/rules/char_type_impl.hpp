#ifndef _CHAR_TYPE_IMPL_H_
#define _CHAR_TYPE_IMPL_H_

#include "char_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * char_type <IteratorT>::strlit_ [] =
{
  "Octet"
};

template <typename IteratorT>
char_type <IteratorT>::char_type (void)
: base_type (char_type_)
{
  this->char_type_ =
    qi::lit ("char")[T3::store_predefined_reference (this->strlit_[0])];
}

#endif
