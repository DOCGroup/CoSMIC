#ifndef _INTEGER_TYPE_IMPL_H_
#define _INTEGER_TYPE_IMPL_H_

#include "integer_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * integer_type <IteratorT>::strlit_ [] =
{
  "ShortInteger",
  "LongInteger"
};

template <typename IteratorT>
integer_type <IteratorT>::integer_type (void)
: base_type (integer_type_)
{
  // == interger types
  this->integer_type_ =
    this->signed_int_ (qi::_r1) |
    this->unsigned_int_ (qi::_r1);

  // == signed integer types
  this->signed_int_ =
    this->signed_short_int_ (qi::_r1) |
    this->signed_long_int_ (qi::_r1) |
    this->signed_longlong_int_ (qi::_r1);

  this->signed_short_int_ =
    qi::lit ("short")[T3::store_predefined_reference (this->strlit_[0])] ;

  this->signed_long_int_ =
    qi::lit ("long")[T3::store_predefined_reference (this->strlit_[1])];

  this->signed_longlong_int_ =
    qi::lit ("long") >> qi::lit ("long")[T3::store_predefined_reference (this->strlit_[1])];

  // == unsigned integer types
  this->unsigned_int_ =
    this->unsigned_short_int_ (qi::_r1) |
    this->unsigned_long_int_ (qi::_r1) |
    this->unsigned_longlong_int_ (qi::_r1);

  this->unsigned_short_int_ =
    qi::lit ("unsigned") >> qi::lit ("short")[T3::store_predefined_reference (this->strlit_[0])];

  this->unsigned_long_int_ =
    qi::lit ("unsigned") >> qi::lit ("long")[T3::store_predefined_reference (this->strlit_[1])];

  this->unsigned_longlong_int_ =
    qi::lit ("unsigned") >> qi::lit ("long") >> qi::lit ("long")[T3::store_predefined_reference (this->strlit_[1])];
}

#endif
