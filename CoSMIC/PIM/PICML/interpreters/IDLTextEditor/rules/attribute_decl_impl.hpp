#ifndef _ATTRIBUTE_DECL_IMPL_H_
#define _ATTRIBUTE_DECL_IMPL_H_

#include "attribute_decl.hpp"
#include "actors.hpp"

template <typename IteratorT>
const char * attribute_decl <IteratorT>::strlit_[] =
{
  "Attribute",
  "ReadonlyAttribute",
  "AttributeMember"
};

template <typename IteratorT>
attribute_decl <IteratorT>::attribute_decl (void)
: base_type (attribute_decl_)
{
  this->attribute_decl_ =
    this->readonly_attr_spec_ (qi::_r1) |
    this->attr_spec_ (qi::_r1);

  this->readonly_attr_spec_ =
    qi::lit ("readonly") >>
    qi::lit ("attribute") >>
    this->param_type_spec_ (qi::_r1) >>
    this->readonly_attr_declarator_ (qi::_r1);

  this->attr_spec_ =
    qi::lit ("attribute") >>
    this->param_type_spec_ (qi::_r1) >>
    this->attr_declarator_ (qi::_r1);

  this->attr_declarator_ =
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[create_embedded_type (this->strlit_[2])] >>
    (this->attr_raises_expr_ (qi::_val) | * (qi::lit (',') >> this->ident_[T3::new_unique_element (this->strlit_[0])]));

  this->readonly_attr_declarator_ =
    this->ident_[T3::new_unique_element (this->strlit_[1])] >>
    qi::eps[create_embedded_type (this->strlit_[2])] >>
    (this->raises_expr_ (qi::_val) | * (qi::lit (',') >> this->ident_[T3::new_unique_element (this->strlit_[1])]));
}

#endif
