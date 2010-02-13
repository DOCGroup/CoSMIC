#ifndef _INTERFACE_IMPL_H_
#define _INTERFACE_IMPL_H_

#include "interface.hpp"

template <typename IteratorT>
const char * idl_interface <IteratorT>::strlit_[] =
{
  "Object",
  "local",
  "abstract",
  "Inherits"
};

template <typename IteratorT>
idl_interface <IteratorT>::idl_interface (void)
: base_type (interface_)
{
  using boost::phoenix::ref;

  this->interface_ =
    this->interface_decl_ (qi::_r1) |
    this->forward_decl_ (qi::_r1);

  // (5) <interface_decl>
  this->interface_decl_ =
    - (qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[2])] |
       qi::lit ("local")[T3::store_attribute_bool <true> (this->strlit_[1])]) >>
    qi::lit ("interface") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    - this->interface_inheritance_spec_ (qi::_val) >>
    qi::lit ('{') >>
    this->interface_body_ (qi::_val) >>
    qi::lit ('}');

  // (6) <forward_decl>
  this->forward_decl_ =
    - (qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[2])] |
       qi::lit ("local")[T3::store_attribute_bool <true> (this->strlit_[1])]) >>
       qi::lit ("interface") >>
       this->ident_[T3::new_unique_element (this->strlit_[0])] >>
       qi::eps[T3::create_symbol (this->fq_name_)];

  // (8) <interface_body>
  this->interface_body_ =
    * this->export_ (qi::_r1);

  this->interface_inheritance_spec_ =
    qi::lit (':') >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[3])] >>
    *(qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[3])]);
}

#endif
