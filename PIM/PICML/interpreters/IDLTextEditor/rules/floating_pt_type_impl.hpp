#ifndef _FLOATING_PT_TYPE_IMPL_H_
#define _FLOATING_PT_TYPE_IMPL_H_

#include "floating_pt_type.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * floating_pt_type <IteratorT>::strlit_ [] =
{
  "FloatNumber",
  "DoubleNumber"
};

template <typename IteratorT>
floating_pt_type <IteratorT>::floating_pt_type (void)
: base_type (floating_pt_type_)
{
  this->floating_pt_type_ =
    qi::lit ("float")[T3::store_predefined_reference (this->strlit_[0])]  |
    qi::lit ("double")[T3::store_predefined_reference (this->strlit_[1])] |
    (qi::lit ("long") >> qi::lit ("double"))[T3::store_predefined_reference (this->strlit_[1])];
}

#endif
