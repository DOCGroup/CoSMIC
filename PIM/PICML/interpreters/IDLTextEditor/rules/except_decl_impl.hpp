#ifndef _EXCEPT_DECL_IMPL_H_
#define _EXCEPT_DECL_IMPL_H_

#include "except_decl.hpp"

template <typename IteratorT>
const char * except_decl <IteratorT>::strlit_[] =
{
  "Exception"
};

template <typename IteratorT>
except_decl <IteratorT>::except_decl (void)
: base_type (except_)
{
  this->except_ =
    this->except_decl_ (qi::_r1);

  this->except_decl_ =
    qi::lit ("exception") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('{') >>
    * this->type_spec_.member_rule () (qi::_val) >>
    qi::lit ('}');
}

#endif
