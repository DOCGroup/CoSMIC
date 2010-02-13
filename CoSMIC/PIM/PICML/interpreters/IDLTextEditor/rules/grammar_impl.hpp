#ifndef _GRAMMAR_IMPL_H_
#define _GRAMMAR_IMPL_H_

#include "grammar.hpp"

template <typename IteratorT>
const char * idl_grammar <IteratorT>::strlit_ [] =
{
  "Package"
};

template <typename IteratorT>
idl_grammar <IteratorT>::idl_grammar (void)
: base_type (specification_)
{
  // (1) <specification>
  this->specification_ =
    + this->definition_ (qi::_r1);

  //// (2) <definition>
  this->definition_ =
     this->preprocessor_ (qi::_r1) |
    (this->interface_ (qi::_r1) >> qi::lit (';')) |
    (this->module_ (qi::_r1) >> qi::lit (';')) |
    (this->component_ (qi::_r1) >> qi::lit (";")) |
    (this->value_ (qi::_r1) >> qi::lit (';')) |
    (this->event_ (qi::_r1) >> qi::lit (';')) |
    (this->type_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->except_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->const_decl_ (qi::_r1) >> qi::lit (';')) |
    (this->home_decl_ (qi::_r1) >> qi::lit (';'));

  // (3) <module>
  this->module_ =
    qi::lit ("module") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::lit ('{') >>
    + this->definition_ (qi::_val) >>
    qi::lit ('}');
}

#endif
