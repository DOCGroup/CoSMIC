#ifndef _TYPE_DECL_IMPL_H_
#define _TYPE_DECL_IMPL_H_

#include "type_decl.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * type_decl <IteratorT>::strlit_[] =
{
  "Alias",
  "Aggregate",
  "SwitchedAggregate",
  "Collection"
};

template <typename IteratorT>
type_decl <IteratorT>::type_decl (void)
: base_type (type_decl_)
{
  this->type_decl_ =
    this->typedef_type_ (qi::_r1) |
    this->sequence_type_ (qi::_r1) |
    this->type_spec_.struct_type () (qi::_r1) |
    this->type_spec_.union_type () (qi::_r1) |
    this->type_spec_.enum_type () (qi::_r1) |
    (qi::lit ("native") >> qi::omit[this->ident_]) |
    this->constr_forward_decl_ (qi::_r1);

  this->typedef_type_ =
    qi::lit ("typedef") >>
    this->type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    * (qi::lit (',') >> this->ident_[T3::new_unique_element (this->strlit_[0])]);

  this->sequence_type_ =
    qi::lit ("typedef") >>
    qi::lit ("sequence") >>
    qi::lit ('<') >>
    this->simple_type_spec_ (qi::_r1) >>
    - qi::omit[qi::uint_] >>
    qi::lit ('>') >>
    this->ident_[T3::new_unique_element (this->strlit_[3])] >>
    qi::eps[T3::create_symbol (this->fq_name_)];

  this->constr_forward_decl_ =
    (qi::lit ("struct") >>
     this->ident_[T3::new_unique_element (this->strlit_[1])] >>
     qi::eps[T3::create_symbol (this->fq_name_)]) |
    (qi::lit ("union") >>
     this->ident_[T3::new_unique_element (this->strlit_[2])] >>
     qi::eps[T3::create_symbol (this->fq_name_)]);
}

#endif
