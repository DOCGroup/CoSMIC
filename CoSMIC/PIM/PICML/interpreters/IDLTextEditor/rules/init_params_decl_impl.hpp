#ifndef _INIT_PARAMS_DECL_IMPL_H_
#define _INIT_PARAMS_DECL_IMPL_H_

#include "init_params_decl.hpp"

template <typename IteratorT>
const char * init_params_decls <IteratorT>::strlit_ [] =
{
  "InParameter"
};

template <typename IteratorT>
init_params_decls <IteratorT>::init_params_decls (void)
: base_type (init_params_decls_)
{
  this->init_params_decls_ =
    this->init_param_decl_ (qi::_r1) >>
    - (qi::lit (',') >> this->init_param_decl_ (qi::_r1));

  this->init_param_decl_ =
    qi::lit ("in") >>
    this->param_type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[0])];
}

#endif
