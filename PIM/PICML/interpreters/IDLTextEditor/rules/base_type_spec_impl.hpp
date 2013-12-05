#ifndef _BASE_TYPE_SPEC_IMPL_H_
#define _BASE_TYPE_SPEC_IMPL_H_

#include "base_type_spec.hpp"

template <typename IteratorT>
const char * base_type_spec <IteratorT>::strlit_ [] =
{
  "GenericValue",
  "GenericObject",
  "GenericValueObject"
};

template <typename IteratorT>
base_type_spec <IteratorT>::base_type_spec (void)
: base_type (base_type_spec_)
{
  this->base_type_spec_ =
    this->floating_pt_type_ (qi::_r1) |
    this->integer_type_ (qi::_r1) |
    this->char_type_ (qi::_r1) |
    this->wide_char_type_ (qi::_r1) |
    this->boolean_type_ (qi::_r1) |
    this->octet_type_ (qi::_r1) |
    this->any_type_ (qi::_r1) |
    this->object_type_ (qi::_r1) |
    this->value_base_type_ (qi::_r1);

  this->wide_char_type_ =
    qi::lit ("wchar");

  this->any_type_ =
    qi::lit ("any")[T3::store_predefined_reference (this->strlit_[0])];

  this->object_type_ =
    qi::lit ("Object")[T3::store_predefined_reference (this->strlit_[1])];

  this->value_base_type_ =
      qi::lit ("ValueBase")[T3::store_predefined_reference (this->strlit_[2])];
}

#endif  // !defined _BASE_TYPE_SPEC_IMPL_H_
