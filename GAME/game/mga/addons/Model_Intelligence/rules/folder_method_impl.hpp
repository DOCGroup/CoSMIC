#ifndef _FOLDER_METHOD_IMPL_H_
#define _FOLDER_METHOD_IMPL_H_

#include "folder_method.hpp"

template <typename IteratorT>
folder_method <IteratorT>::folder_method (void)
: folder_method::base_type (method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->method_ %=
    this->childfolders_method_ |
    this->models_method_ |
    this->atoms_method_;

  // GME Connection specific methods
  this->childfolders_method_ = qi::lit ("childFolders") >> (qi::lit ("(") >> qi::lit (")"))
    [qi::_val = phoenix::new_ <ChildFolders_Method> ()];

  this->models_method_ = qi::lit ("models") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <Models_Method> ()]) |
      (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<Models_Method> (qi::_1)] >>
       qi::lit (")")) );

  this->atoms_method_ = qi::lit ("atoms") >>
    ( (qi::lit ("(") >> qi::lit (")")[qi::_val = phoenix::new_ <Atoms_Method> ()]) |
      (qi::lit ("(") >> this->id_[qi::_val = phoenix::new_<Atoms_Method> (qi::_1)] >>
       qi::lit (")")) );
}

#endif