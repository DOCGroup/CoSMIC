#ifndef _OP_DECL_IMPL_
#define _OP_DELC_IMPL_

#include "op_decl.hpp"
#include "actors.hpp"

template <typename IteratorT>
const char * op_decl <IteratorT>::strlit_[] =
{
  "OnewayOperation",
  "TwowayOperation",
  "InParameter",
  "OutParameter",
  "InOutParameter",
  "ReturnType"
};

template <typename IteratorT>
op_decl <IteratorT>::op_decl (void)
: base_type (op_decl_)
{
  this->op_decl_ =
    this->oneway_decl_ (qi::_r1) |
    this->twoway_void_decl_ (qi::_r1) |
    this->twoway_decl_ (qi::_r1);

  this->oneway_decl_ =
    qi::lit ("oneway") >>
    qi::lit ("void") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    this->parameter_decls_ (qi::_val);

  this->twoway_decl_ =
    this->param_type_spec_ (qi::_r1)>>
    this->ident_[T3::new_unique_element (this->strlit_[1])] >>
    qi::eps[create_embedded_type (this->strlit_[5])] >>
    this->parameter_decls_ (qi::_val) >>
    - this->raises_expr_ (qi::_val);

  this->twoway_void_decl_ =
    qi::lit ("void") >>
    this->ident_[T3::new_unique_element (this->strlit_[1])] >>
    this->parameter_decls_ (qi::_val) >>
    - this->raises_expr_ (qi::_val);

  this->parameter_decls_ =
    qi::lit ('(') >>
    - (this->param_decl_ (qi::_r1) >>  * (qi::lit (',') >> this->param_decl_ (qi::_r1))) >>
    qi::lit (')');

  this->param_decl_ =
    this->in_param_ (qi::_r1) |
    this->out_param_ (qi::_r1) |
    this->inout_param_ (qi::_r1);

  this->in_param_ =
    qi::lit ("in") >>
    this->param_type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[2])];

  this->out_param_ =
    qi::lit ("out") >>
    this->param_type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[3])];

  this->inout_param_ =
    qi::lit ("inout") >>
    this->param_type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[4])];
}

#endif
