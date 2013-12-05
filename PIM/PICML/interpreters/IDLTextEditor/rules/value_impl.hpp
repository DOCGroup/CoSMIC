#ifndef _VALUE_IMPL_H_
#define _VALUE_IMPL_H_

#include "value.hpp"

template <typename IteratorT>
const char * value <IteratorT>::strlit_ [] =
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
value <IteratorT>::value (void)
: base_type (value_)
{
  this->value_ =
    this->value_decl_ (qi::_r1) |
    this->value_abs_decl_ (qi::_r1) |
    this->value_box_decl_ (qi::_r1) |
    this->value_fwd_decl_ (qi::_r1);

  this->value_decl_ =
    - qi::lit ("custom") >>
    qi::lit ("valuetype") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    this->value_inheritance_spec_ (qi::_val) >>
    qi::lit ('{') >>
    * this->value_element_ (qi::_val) >>
    qi::lit ('}');

  this->value_fwd_decl_ =
    - qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[5])] >>
      qi::lit ("valuetype") >>
      this->ident_[T3::new_unique_element (this->strlit_[0])] >>
      qi::eps[T3::create_symbol (this->fq_name_)];

  this->value_abs_decl_ =
    qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[5])] >>
    qi::lit ("valuetype") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    - this->value_inheritance_spec_ (qi::_val) >>
    qi::lit ('{') >>
    * this->export_ (qi::_val) >>
    qi::lit ('}');

  this->value_inheritance_spec_ =
    - (qi::lit (':') >> - qi::lit ("truncatable") >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[1])] >>
    * (qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[1])])) >>
    - (qi::lit ("supports") >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[3])] >>
    * (qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[3])]));
}

#endif
