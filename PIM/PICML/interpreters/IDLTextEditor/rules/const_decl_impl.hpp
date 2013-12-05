#ifndef _CONST_DECL_H_
#define _CONST_DECL_H_

#include "const_decl.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * const_decl <IteratorT>::strlit_ [] =
{
  "Constant",
  "value"
};

template <typename IteratorT>
const_decl <IteratorT>::const_decl (void)
: base_type (const_)
{
  this->const_ =
    this->const_decl_ (qi::_r1);

  this->const_decl_ =
    this->const_type_ (qi::_r1) >>
    qi::lit ("const") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::lit ('=') >>
    this->const_value_[T3::set_attribute (this->strlit_[1])];

  this->const_type_ =
    this->integer_type_ (qi::_r1) |
    this->char_type_ (qi::_r1) |
    this->boolean_type_ (qi::_r1) |
    this->floating_pt_type_ (qi::_r1) |
    this->string_type_ (qi::_r1) |
    this->wide_string_type_ (qi::_r1) |
    qi::omit[this->scoped_name_] |
    this->octet_ (qi::_r1);

  this->const_value_ %=
    qi::lexeme[(*qi::char_ - ';')];
}

#endif
