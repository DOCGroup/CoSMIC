#ifndef _PARAM_TYPE_SPEC_IMPL_H_
#define _PARAM_TYPE_SPEC_IMPL_H_

#include "param_type_spec.hpp"

template <typename IteratorT>
param_type_spec <IteratorT>::param_type_spec (void)
: base_type (param_type_spec_)
{
  this->param_type_spec_ =
    this->base_type_spec_ (qi::_r1) |
    this->string_type_ (qi::_r1) |
    this->wide_string_type_ (qi::_r1) |
    this->scoped_name_[T3::store_reference ()];
}

#endif  // !defined _PARAM_TYPE_SPEC_IMPL_H_

