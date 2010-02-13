#ifndef _STRING_TYPE_IMPL_H_
#define _STRING_TYPE_IMPL_H_

#include "string_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * string_type <IteratorT>::strlit_ [] =
{
  "String"
};

template <typename IteratorT>
string_type <IteratorT>::string_type (void)
: base_type (string_type_)
{
  this->string_type_ =
    qi::lit ("string")[T3::store_predefined_reference (this->strlit_[0])] >>
    - (qi::lit ('<') >> qi::uint_ >> qi::lit ('>'));
}

#endif  // !defined _STRING_TYPE_IMPL_H_
