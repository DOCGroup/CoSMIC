#ifndef _TYPE_SPEC_IMPL_H_
#define _TYPE_SPEC_IMPL_H_

#include "type_spec.hpp"

template <typename IteratorT>
const char * type_spec <IteratorT>::strlit_[] =
{
  "Aggregate",
  "Member",
  "SwitchedAggregate",
  "Discriminator",
  "Enum",
  "EnumValue",
  "String",
  "Boolean"
};

template <typename IteratorT>
type_spec <IteratorT>::type_spec (void)
: base_type (type_spec_)
{
  this->type_spec_ =
    this->simple_type_spec_ (qi::_r1) |
    this->constr_type_spec_ (qi::_r1);

  this->constr_type_spec_ =
    this->struct_type_ (qi::_r1) |
    this->union_type_ (qi::_r1) |
    this->enum_type_ (qi::_r1);

  this->struct_type_ =
    qi::lit ("struct") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('{') >>
    this->member_list_ (qi::_val) >>
    qi::lit ('}');

  this->enum_type_ =
    qi::lit ("emum") >>
    this->ident_[T3::new_unique_element (this->strlit_[4])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('{') >>
    this->enumerator_ (qi::_val) >>
    * (qi::lit (',') >> this->enumerator_ (qi::_val)) >>
    qi::lit ('}');

  this->enumerator_ =
    this->ident_[T3::new_unique_element (this->strlit_[5])];

  this->union_type_ =
    qi::lit ("union") >>
    this->ident_[T3::new_unique_element (this->strlit_[2])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('(') >>
    this->switch_type_spec_ (qi::_val) >>
    qi::lit (')') >>
    qi::lit ('{') >>
    this->switch_body_ (qi::_val) >>
    qi::lit ('}');

  this->switch_type_spec_ =
    this->integer_type_ (qi::_r1) |
    this->char_type_ (qi::_r1) |
    this->boolean_type_ (qi::_r1) |
    this->enum_type_ (qi::_r1) |
    this->scoped_name_[T3::store_reference ()];

  this->switch_body_ =
    + this->case_ (qi::_r1);

  this->member_list_ =
    + this->member_ (qi::_r1);

  this->member_ =
    this->type_spec_ (qi::_r1) >>
    this->ident_[T3::new_unique_element (this->strlit_[1])] >>
    * (qi::lit (',') >> this->ident_[T3::new_unique_element (this->strlit_[1])]) >>
    qi::lit (';');
}

#endif
