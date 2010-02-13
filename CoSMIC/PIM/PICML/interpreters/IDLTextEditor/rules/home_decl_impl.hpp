#ifndef _HOME_DECL_IMPL_H_
#define _HOME_DECL_IMPL_H_

#include "home_decl.hpp"

template <typename IteratorT>
const char * home_decl <IteratorT>::strlit_ [] =
{
  "ComponentFactory",
  "ManagesComponent",
  "LookupKey",
  "LookupOperation",
  "FactoryOperation",
  "Inherits",
  "Supports"
};

template <typename IteratorT>
home_decl <IteratorT>::home_decl (void)
: base_type (home_decl_)
{
  this->home_decl_ =
    this->home_decl_inner_ (qi::_r1);

  this->home_decl_inner_ =
    qi::lit ("home") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    - this->home_inheritance_spec_ (qi::_val) >>
    - this->supported_interface_spec_ (qi::_val) >>
    qi::lit ("manages") >>
    this->scoped_name_[T3::create_connection_to (this->strlit_[1])] >>
    - this->primary_key_ (qi::_val) >>
    qi::lit ('{') >>
    * this->home_export_ (qi::_val) >>
    qi::lit ('}');

  this->home_inheritance_spec_ =
    qi::lit (':') >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[5])];

  this->supported_interface_spec_ =
    qi::lit ("supports") >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[6])] >>
    *(qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[6])]);

  this->primary_key_ =
    qi::lit ("primarykey") >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[2])];

  this->home_export_ =
    this->export_ (qi::_r1) |
    this->factory_decl_ (qi::_r1) |
    this->finder_decl_ (qi::_r1);

  this->factory_decl_ =
    qi::lit ("factory") >>
    this->ident_[T3::new_unique_element (this->strlit_[4])] >>
    qi::lit ('(') >>
    - this->init_param_decls_ (qi::_val) >>
    qi::lit (')') >>
    - this->raises_expr_ (qi::_val);

  this->finder_decl_ =
    qi::lit ("finder") >>
    this->ident_[T3::new_unique_element (this->strlit_[3])] >>
    qi::lit ('(') >>
    - this->init_param_decls_ (qi::_val) >>
    qi::lit (')') >>
    - this->raises_expr_ (qi::_val);
}

#endif
