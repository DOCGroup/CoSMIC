#ifndef _STRING_TYPE_IMPL_H_
#define _STRING_TYPE_IMPL_H_

#include "wide_string_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * wide_string_type <IteratorT>::strlit_ [] =
{
  "String"
};

template <typename IteratorT>
wide_string_type <IteratorT>::wide_string_type (void)
: base_type (wide_string_type_)
{
  this->wide_string_type_ =
    qi::lit ("wstring")[T3::store_predefined_reference (this->strlit_[0])] >>
    - (qi::lit ('<') >> qi::uint_ >> qi::lit ('>'));
}

#endif  // !defined _STRING_TYPE_IMPL_H_
