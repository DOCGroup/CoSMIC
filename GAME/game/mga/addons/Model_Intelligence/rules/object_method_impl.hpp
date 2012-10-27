#ifndef _OBJECT_METHOD_IMPL_H_
#define _OBJECT_METHOD_IMPL_H_

#include "object_method.hpp"

template <typename IteratorT>
object_method <IteratorT>::object_method (void)
: object_method::base_type (method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %=
    this->name_method_ |
    this->kindname_method_ |
    this->parent_method_ |
    this->isfco_method_;

  // GME Object specific methods
  this->name_method_ = qi::lit ("name") >> -(qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <Name_Method> ()];

  this->kindname_method_ = qi::lit ("kindName") >> -(qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <KindName_Method> ()];

  this->parent_method_ = qi::lit ("parent") >> (qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <Parent_Method> ()];

  this->isfco_method_ = qi::lit ("isFCO") >> (qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <IsFCO_Method> ()];
}

#endif