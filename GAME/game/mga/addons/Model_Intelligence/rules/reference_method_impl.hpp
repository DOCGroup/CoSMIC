#ifndef _MODEL_METHOD_IMPL_H_
#define _MODEL_METHOD_IMPL_H_

#include "reference_method.hpp"

template <typename IteratorT>
reference_method <IteratorT>::reference_method (void)
: reference_method::base_type (method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %=
    this->refers_to_method_ |
    this->usedbyconnpoints_method_;

  // GME Reference specific methods

  this->refers_to_method_ = qi::lit ("refersTo") >>
    qi::lit ("(") >>
    qi::lit (")")[qi::_val = phoenix::new_ <Refers_to_Method> ()];

  this->usedbyconnpoints_method_ = qi::lit ("usedByConnPoints") >>
    (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <UsedByConnPoints_Method> ()] ) |
    (qi::lit ("(") >>
       this->id_ [qi::_val = phoenix::new_<UsedByConnPoints_Method> (qi::_1)] >>
       qi::lit (")"));
}

#endif