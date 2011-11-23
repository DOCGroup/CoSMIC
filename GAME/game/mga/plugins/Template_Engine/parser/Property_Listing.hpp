// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Lister.hpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _TEMPLATE_ENGINE_PROPERTY_LISTER_HPP_
#define _TEMPLATE_ENGINE_PROPERTY_LISTER_HPP_

#include <set>
#include "Property_Tag.hpp"
#include "boost/spirit/include/phoenix.hpp"

/**
 * @struct Property_Lister_Grammar_T
 *
 * Grammar for listing the set of properties in a context. The
 * listing does contain duplicate values, nor does it return the
 * location of each property in the context.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Lister_Grammar_T :
  public boost::spirit::qi::grammar <IteratorT,
                                     std::set <std::string> (),
                                     SpaceT>
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       map             Source property map
   */
  Property_Lister_Grammar_T (const Property_Tag_Config & config)
    :  Property_Lister_Grammar_T::base_type (content_),
       property_ (config),
       content_ (std::string ("content")),
       text_ (std::string ("text"))
  {
    namespace ascii = boost::spirit::ascii;

    this->content_ %= this->text_ >> * (this->property_ >> this->text_);
    this->text_ = *(ascii::char_ - config.tags_.first);
  }

private:
  /// Rule for parsing the content.
  ::boost::spirit::qi::rule <IteratorT,
                             std::set <std::string> (),
                             SpaceT> content_;

  /// Rule for parsing the text version of the content.
  ::boost::spirit::qi::rule <IteratorT,
                             void (),
                             SpaceT> text_;

  /// Grammar for parsing the property.
  Property_Tag <IteratorT, SpaceT> property_;
};

/**
 * @class Property_Lister
 *
 * Parser that locates properties in a content.
 */
class Property_Lister
{
public:
  /**
   * Evaluate the content. This will construct a set of properties
   * that are in the content. If there are not properties, then the
   * returned set will not be changed.
   */
  template <typename IteratorT>
  bool evaluate (IteratorT begin,
                 IteratorT end,
                 const Property_Tag_Config & config,
                 std::set <std::string> & result)
  {
    Property_Lister_Grammar_T <IteratorT,
                               boost::spirit::ascii::space_type>
                               grammar (config);

    namespace phoenix = boost::phoenix;

    bool retval =
      ::boost::spirit::qi::phrase_parse (begin,
                                         end,
                                         grammar,
                                         boost::spirit::ascii::space,
                                         result);

    return retval;
  }
};

#endif  // !defined _TEMPLATE_ENGINE_PROPERTY_EXPANDER_H_
