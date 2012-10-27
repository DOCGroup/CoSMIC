#ifndef _CONNECTION_METHOD_IMPL_H_
#define _CONNECTION_METHOD_IMPL_H_

#include "connection_method.hpp"

template <typename IteratorT>
connection_method <IteratorT>::connection_method (void)
: connection_method::base_type (method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %=
    this->connectionpoints_method_ |
    this->connectionpoint_method_ |
    this->target_method_ |
    this->owner_method_;

  // GME Connection specific methods
  this->connectionpoints_method_ = qi::lit ("connectionPoints") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <ConnectionPoints_Method> ()]) |
    (qi::lit ("(") >> this->qs_[qi::_val = phoenix::new_<ConnectionPoints_Method> (qi::_1)] >>
     qi::lit (")")) );

  this->connectionpoint_method_ = qi::lit ("connectionPoint") >>
    qi::lit ("(") >>
    this->qs_[qi::_val = phoenix::new_<ConnectionPoint_Method> (qi::_1)] >>
    qi::lit (")");

  this->target_method_ = qi::lit ("target") >> (qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <Target_Method> ()];

  this->owner_method_ = qi::lit ("owner") >> (qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <Owner_Method> ()];
}

#endif