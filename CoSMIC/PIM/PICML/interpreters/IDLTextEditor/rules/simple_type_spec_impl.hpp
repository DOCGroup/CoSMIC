#ifndef _SIMPLE_TYPE_SPEC_IMPL_H_
#define _SIMPLE_TYPE_SPEC_IMPL_H_

#include "simple_type_spec.hpp"

template <typename IteratorT>
simple_type_spec <IteratorT>::simple_type_spec (void)
: base_type (simple_type_spec_)
{
  this->simple_type_spec_ =
    this->base_type_spec_ (qi::_r1) |
    this->template_type_spec_ (qi::_r1) |
    this->scoped_name_[T3::store_reference ()];
}

#endif
