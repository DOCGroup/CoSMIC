// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Tag.hpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_PROPERTY_TAG_HPP_
#define _TEMPLATE_ENGINE_PROPERTY_TAG_HPP_

#include "Property_Name.hpp"

/**
 * @struct Property_Tag_Config
 *
 * Common configuration for the property grammars/parsers.
 */
struct Property_Tag_Config
{
  /// Defualt constructor.
  Property_Tag_Config (void)
    : use_env_ (true),
      tags_ ("${", "}")
  {

  }

  /// Use environment variables.
  bool use_env_;

  /// The open/close tag for the property.
  std::pair <std::string, std::string> tags_;
};

/**
 * @struct Property_Tag
 *
 * Grammar for evaluating a property.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Tag :
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
  Property_Tag (const Property_Tag_Config & config)
    :  Property_Tag::base_type (property_)
  {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    this->property_ %=
      config.tags_.first >> (this->name_ - config.tags_.second) >>
      config.tags_.second;
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> property_;

  Property_Name <IteratorT, SpaceT> name_;
};

#endif  // !defined _TEMPLATE_ENGINE_PROPERTY_GRAMMAR_HPP_
