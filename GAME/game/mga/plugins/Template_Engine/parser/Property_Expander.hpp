// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Expander.hpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_PROPERTY_EXPANDER_HPP_
#define _TEMPLATE_ENGINE_PROPERTY_EXPANDER_HPP_

#include "boost/spirit/include/phoenix.hpp"
#include "Property_Tag.hpp"
#include "Property_Map.h"

/**
 * @struct Property_Expander_Grammar_T
 *
 * Grammar for evaluating a property.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Expander_Grammar_T :
  public boost::spirit::qi::grammar <IteratorT,
                                     std::string (),
                                     boost::spirit::qi::locals <std::string>,
                                     SpaceT>
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       map             Source property map
   */
  Property_Expander_Grammar_T (const Property_Map & props, const Property_Tag_Config & config)
    :  Property_Expander_Grammar_T::base_type (content_),
       property_ (config),
       content_ (std::string ("content")),
       text_ (std::string ("text"))
  {
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;
    namespace ascii = boost::spirit::ascii;
    using namespace qi::labels;

    this->content_ =
      this->text_[_val = _1] >>
      *(this->property_[phoenix::bind (&Property_Map::get, props, _1, _a), _val += _a] >>
            this->text_[_val += _1]);

    this->text_ %= qi::no_skip[*(ascii::char_ - config.tags_.first)];
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             boost::spirit::qi::locals <std::string>,
                             SpaceT> content_;

  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> text_;

  Property_Tag <IteratorT, SpaceT> property_;
};

/**
 * @class Property_Expander
 *
 * Substitutes variables defined in a string with their expanded value.
 * Variables are defined by enclosing a set of non-whitespace characters
 * in open/close tags specificed in the configuration.
 */
class Property_Expander
{
public:
  /// Initializing constructor.
  Property_Expander (const Property_Tag_Config & config)
    : config_ (config)
  {

  }

  /**
   * Evaluate the content. This will expand the property values
   * with the concrete values.
   */
  template <typename IteratorT>
  bool evaluate (IteratorT begin,
                 IteratorT end,
                 const Property_Map & map,
                 std::string & result)
  {
    namespace ascii = boost::spirit::ascii;

    Property_Expander_Grammar_T <IteratorT,
                                 ascii::space_type>
                                 grammar (map, this->config_);

    bool retval =
      ::boost::spirit::qi::phrase_parse (begin,
                                         end,
                                         grammar,
                                         ascii::space,
                                         result);

    return retval;
  }

private:
  /// Configuration for the expander.
  const Property_Tag_Config & config_;
};

#endif  // !defined _TEMPLATE_ENGINE_PROPERTY_EXPANDER_H_
