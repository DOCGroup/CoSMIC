#ifndef _METHODCALL_IMPL_H_
#define _METHODCALL_IMPL_H_

#include "methodcall.hpp"

template <typename IteratorT>
methodcall <IteratorT>::methodcall (void)
: methodcall::base_type (method_call_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->method_call_ = this->self_method_call_ | this->lv_method_call_;

   this->self_method_call_ = qi::lit ("self")>>
     (qi::lit (".") | qi::lit ("->")) >>
		 this->method_ [qi::_val = phoenix::new_ <Self_Method_Call> (qi::_1)] >>
		 this->method_list_ [phoenix::bind (&Method_Call::set_next, qi::_val, qi::_1)];

	 this->lv_method_call_ = this->ident_ [qi::_a = qi::_1] >>
	   (qi::lit (".") | qi::lit ("->")) >>
		 this->method_ [qi::_val = phoenix::new_ <Local_Value_Method_Call> (qi::_a, qi::_1)] >>
		 this->method_list_ [phoenix::bind (&Method_Call::set_next, qi::_val, qi::_1)];

	 this->method_list_ = *( (qi::lit ("->") | qi::lit (".")) >>
		                       this->method_[phoenix::push_back (qi::_val, qi::_1)] ); 
}

#endif