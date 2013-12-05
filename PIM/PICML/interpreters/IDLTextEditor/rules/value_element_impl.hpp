#ifndef _VALUE_ELEMENT_IMPL_H_
#define _VALUE_ELEMENT_IMPL_H_

#include "value_element.hpp"

template <typename IteratorT>
const char * value_element <IteratorT>::strlit_ [] =
{
  "ValueObject",
  "Inherits",
  "Member",
  "Supports",
  "FactoryOperation",
  "abstract",
  "InParameter"
};

template <typename IteratorT>
value_element <IteratorT>::value_element (void)
: base_type (value_element_)
{
  this->value_element_ =
    this->export_ (qi::_r1) |
    this->state_member_ (qi::_r1) |
    this->init_decl_ (qi::_r1);

  this->state_member_ =
    (qi::lit ("public") | qi::lit ("private")) >>
    this->type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[2])] >>
    * (qi::lit (',') >> this->ident_[T3::new_unique_element (this->strlit_[2])]) >>
    qi::lit (';');

  this->init_decl_ =
    qi::lit ("factory") >>
    this->ident_[T3::new_unique_element (this->strlit_[4])] >>
    qi::lit ('(') >>
    - this->init_params_decls_ (qi::_val) >>
    qi::lit (')') >>
    - this->raises_expr_ (qi::_val) >>
    qi::lit (';');
}


#endif
