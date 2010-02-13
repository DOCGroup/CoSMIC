#ifndef _EVENT_IMPL_H_
#define _EVENT_IMPL_H_

#include "event.hpp"

template <typename IteratorT>
const char * idl_event <IteratorT>::strlit_ [] =
{
  "Event",
  "abstract",
  "custom"
};

template <typename IteratorT>
idl_event <IteratorT>::idl_event (void)
: base_type (event_)
{
  this->event_ =
    this->event_decl_ (qi::_r1) |
    this->event_abs_decl_ (qi::_r1) |
    this->event_fwd_decl_ (qi::_r1);

  this->event_fwd_decl_ =
    - qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[1])] >>
    qi::lit ("eventtype") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)];

  this->event_abs_decl_ =
    - qi::lit ("abstract")[T3::store_attribute_bool <true> (this->strlit_[1])] >>
    qi::lit ("eventtype") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('{') >>
    * this->export_ (qi::_val) >>
    qi::lit ('}');

  this->event_decl_ =
    - qi::lit ("custom")[T3::store_attribute_bool <true> (this->strlit_[2])] >>
    qi::lit ("eventtype") >>
    this->ident_[T3::new_unique_element (this->strlit_[0])] >>
    qi::eps[T3::create_symbol (this->fq_name_)] >>
    qi::lit ('{') >>
    * this->value_element_ (qi::_val) >>
    qi::lit ('}');
}

#endif
