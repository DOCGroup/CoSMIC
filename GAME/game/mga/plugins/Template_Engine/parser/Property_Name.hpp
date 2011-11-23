// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Evaluator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_PROPERTY_NAME_HPP_
#define _TEMPLATE_ENGINE_PROPERTY_NAME_HPP_

#include "boost/spirit/include/qi.hpp"

/**
 * @struct Property_Name
 *
 * Grammar for evaluating a property.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Name :
  public ::boost::spirit::qi::grammar <IteratorT,
                                       std::string (),
                                       SpaceT>
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       map             Source property map
   */
  Property_Name (void)
    : Property_Name::base_type (name_, std::string ("Property_Name")),
      name_ (std::string ("name"))
  {
    namespace qi = boost::spirit::qi;

    this->name_ %= qi::lexeme[(qi::alpha >> *(qi::alnum | qi::char_ ('_') | qi::char_ ('.')))];
  }

  void enable_debugging (void)
  {
    debug (name_);
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> name_;
};

#endif  // !defined _TEMPLATE_ENGINE_PROPERTY_NAME_HPP_
