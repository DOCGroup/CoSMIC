#ifndef _MODEL_METHOD_IMPL_H_
#define _MODEL_METHOD_IMPL_H_

#include "model_method.hpp"

template <typename IteratorT>
model_method <IteratorT>::model_method (void)
: model_method::base_type (model_method_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->model_method_ %=
    this->parts_method_ |
    this->size_method_ |
    this->atomparts_method_ |
    this->modelparts_method_ |
    this->referenceparts_method_ |
    this->connectionparts_method_;

  // GME Model specific methods

  this->parts_method_ = qi::lit("parts") >>
    qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <Parts_Method> (qi::_a)];

  this->atomparts_method_ = (qi::lit("atomParts") | qi::lit("atoms")) >>
    qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <AtomParts_Method> (qi::_a)];

  this->modelparts_method_ = (qi::lit("modelParts") | qi::lit("models")) >>
    qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ModelParts_Method> (qi::_a)];

  this->referenceparts_method_ = qi::lit("referenceParts") >>
    qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ReferenceParts_Method> (qi::_a)];

  this->connectionparts_method_ = qi::lit("connectionParts") >>
    qi::lit ("(") >>
    (this->qs_ | this->id_)[qi::_a = qi::_1] >>
    qi::lit (")")[qi::_val = phoenix::new_ <ConnectionParts_Method> (qi::_a)];

  this->size_method_ = qi::lit("size")[qi::_val = phoenix::new_ <Size_Method> ()];
}

#endif