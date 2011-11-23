// -*- C++ -*-

//=============================================================================
/**
 * @file          Property_Value_Setter.hpp
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_PROPERTY_VALUE_SETTER_HPP_
#define _TEMPLATE_ENGINE_PROPERTY_VALUE_SETTER_HPP_

#include "Property_Name.hpp"
#include "boost/fusion/include/std_pair.hpp"

/**
 * @struct Property_Value
 *
 * Grammar for evaluating a property.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Value_Setter :
  public ::boost::spirit::qi::grammar <IteratorT,
                                       std::pair <std::string, std::string> (),
                                       SpaceT>
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       map             Source property map
   */
  Property_Value_Setter (void)
    :  Property_Value_Setter::base_type (assign_)
  {
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;

    using namespace qi::labels;

    this->assign_ %= this->name_ >> '=' >> this->value_;
    this->value_  %= qi::lexeme[*(qi::char_ - qi::eol)];
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             std::pair <std::string, std::string> (),
                             SpaceT> assign_;

  Property_Name <IteratorT, SpaceT> name_;

  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> value_;
};



#endif  // !defined _TEMPLATE_ENGINE_PROPERTY_VALUE_HPP_
