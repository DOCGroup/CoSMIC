#ifndef _COMPONENT_IMPL_H_
#define _COMPONENT_IMPL_H_

#include "component.hpp"
#include "attribute_decl_impl.hpp"

template <typename IteratorT>
const char * component <IteratorT>::strlit_[] =
{
  "Component",
  "InEventPort",
  "OutEventPort",
  "RequiredRequestPort",
  "ProvidedRequestPort",
  "single_destination",
  "multiple_connections",
  "Supports"
};

template <typename IteratorT>
component <IteratorT>::component (void)
: base_type (component_)
{
  this->component_ =
    this->component_decl_ (qi::_r1) |
    this->component_forward_decl_ (qi::_r1);

  this->component_decl_ =
    qi::lit ("component") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    - this->component_inheritance_spec_ (qi::_val) >>
    - this->supported_interface_spec_ (qi::_val) >>
    qi::lit ('{') >>
    this->component_body_ (qi::_val) >>
    qi::lit ('}');

  this->component_inheritance_spec_ =
    qi::lit (':') >>
    qi::omit[this->scoped_name_];

  this->supported_interface_spec_ =
    qi::lit ("supports") >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[7])] >>
    * (qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[7])]);

  this->component_forward_decl_ =
    qi::lit ("component") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)];

  this->component_body_ =
    * this->component_export_ (qi::_r1);

  this->component_export_ =
    (this->provides_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->uses_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->emits_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->publishes_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->consumes_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->attr_decl_ (qi::_r1) >> qi::lit (';'));

  this->provides_decl_ =
    qi::lit ("provides") >>
    this->scoped_name_[T3::store_reference ()] >>
    this->ident_[T3::new_unique_element (this->strlit_[4])];

  this->uses_decl_ =
    qi::lit ("uses") >>
    - qi::lit ("multiple")[T3::store_attribute_bool <true> (this->strlit_[6])] >>
    this->scoped_name_[T3::store_reference ()] >>
    this->ident_[T3::new_unique_element (this->strlit_[3])];

  this->emits_decl_ =
    qi::lit ("emits") >>
    this->scoped_name_[T3::store_reference ()] >>
    this->ident_[T3::new_unique_element (this->strlit_[2])];

  this->publishes_decl_ =
    qi::lit ("publishes") [T3::store_attribute_bool <true> (this->strlit_[5])] >>
    this->scoped_name_[T3::store_reference ()] >>
    this->ident_[T3::new_unique_element (this->strlit_[2])];

  this->consumes_decl_ =
    qi::lit ("consumes") >>
    this->scoped_name_[T3::store_reference ()] >>
    this->ident_[T3::new_unique_element (this->strlit_[1])];
}

#endif
