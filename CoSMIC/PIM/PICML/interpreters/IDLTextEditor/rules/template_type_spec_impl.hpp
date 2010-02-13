#ifndef _TEMPLATE_TYPE_SPEC_IMPL_H_
#define _TEMPLATE_TYPE_SPEC_IMPL_H_

#include "template_type_spec.hpp"

template <typename IteratorT>
template_type_spec <IteratorT>::template_type_spec (void)
: base_type (template_type_spec_)
{
  this->template_type_spec_ =
    this->string_type_ (qi::_r1) |
    this->wide_string_type_ (qi::_r1) |
    this->fixed_pt_type_ (qi::_r1);
}

#endif
