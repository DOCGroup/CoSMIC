// -*- C++ -*-

//=============================================================================
/**
 * @file        Config_List_Parser.hpp
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_LIST_PARSER_HPP_
#define _PROPERTY_LIST_PARSER_HPP_

#include <algorithm>
#include <map>

#include "boost/shared_ptr.hpp"
#include "boost/fusion/include/std_pair.hpp"
#include "boost/spirit/include/phoenix.hpp"

#include "Property_Map.h"
#include "Property_Name.hpp"

/// Type definition of a propert map configuration. This mapping stores
/// different configurations by their name.
typedef std::map <std::string,
                  Property_Map *>
                  Property_Configuration_Map;

/**
 * @class Property_Configuration
 *
 * Grammar for parsing a propery configuration. Given content and a
 * property configuration map, this grammar returns a new Property_Map
 * object. This grammar does not add the new Property_Map to the
 * existing property map configuration object. That is the responsibility
 * of the caller since we want the property configuration map to remain
 * immutable.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Configuration :
  public boost::spirit::qi::grammar <IteratorT,
                                     std::pair <std::string, Property_Map *> (const Property_Configuration_Map &),
                                     boost::spirit::qi::ascii::space_type>
{
  /**
   * @struct lookup_impl
   *
   * Phoenix function object that will lookup a configuration in the
   * configuration map. I would like to do this inline within the grammar,
   * but I was not able to figure it out. So, we have this function
   * object as a consolation prize! :-(
   */
  struct lookup_impl
  {
    //typedef boost::mpl::false_ no_nullary;

    template <typename Arg1, typename Arg2, typename Arg3>
    struct result
    {
      typedef bool type;
    };

    template <typename Arg1, typename Arg2, typename Arg3>
    typename result <Arg1, Arg2, Arg3>::type operator () (const Arg1 & map, const Arg2 & name, Arg3 & ret) const
    {
      namespace phoenix = boost::phoenix;
      using phoenix::arg_names::arg1;

      typedef Property_Configuration_Map::const_iterator const_iterator;
      const_iterator iter = std::find_if (map.begin (), map.end (), phoenix::at_c <0> (arg1) == name);

      if (iter == map.end ())
        return false;

      ret = iter->second;
      return true;
    }
  };

  boost::phoenix::function <lookup_impl> lookup;

  /**
   * Initializing constructor.
   *
   * @param[in]         actor         Actor for handling events.
   */
  Property_Configuration (void)
    : Property_Configuration::base_type (config_, std::string ("Property_Configuration")),
      config_ (std::string ("config")),
      assignments_ (std::string ("assignment")),
      assign_ (std::string ("assign")),
      value_ (std::string ("value")),
      ident_ (std::string ("ident"))
  {
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;

    using phoenix::arg_names::arg1;

    using namespace qi::labels;

    this->config_ =
      qi::lit ("config") > this->ident_[
        // Set the configuration's name, then create a new property map.
        phoenix::at_c <0> (_val) = _1,
        phoenix::at_c <1> (_val) = phoenix::new_ <Property_Map> ()] >
        - (qi::lit (':') >> this->base_list_ (phoenix::at_c <1> (_val), _r1)) >>
      qi::lit ('{') >>
      this->assignments_ (phoenix::at_c <1> (_val)) >>
      qi::lit ('}');

    this->base_list_ =
      this->ident_[
        // First, lookup the base property map in the configuration.
        // map. Then, we can join it with the current property map.
        phoenix::if_ (lookup (_r2, _1, _a))
        [
          phoenix::bind (&Property_Map::join, _r1, *_a, true)
        ]] >>
      *(qi::lit (',') >>
      this->ident_[
        // First, lookup the base property map in the configuration.
        // map. Then, we can join it with the current property map.
        phoenix::if_ (lookup (_r2, _1, _a))
        [
          phoenix::bind (&Property_Map::join, _r1, *_a, true)
        ]]);

    this->assignments_ =
      *(this->assign_[phoenix::bind (&Property_Map::set, _r1, _1)]);

    this->assign_  %= this->name_ > '=' > this->value_;

    this->value_   %= qi::lexeme[*(qi::char_ - qi::eol)];

    this->ident_   %= qi::lexeme[(qi::alpha > *(qi::alnum | qi::char_ ('_')))];

    using phoenix::construct;
    using phoenix::val;

    // Definition of the error handler.
    qi::on_error <qi::fail>
    (
      config_,
      std::cerr << phoenix::val ("*** syntax error: expecting ")
                << qi::labels::_4
                << phoenix::val(" here; \"")
                << construct <std::string> (qi::labels::_3, qi::labels::_2)
                << phoenix::val("\"")
                << std::endl
    );
  }

  void enable_debugging (void)
  {
    debug (config_);
    debug (assignments_);
    debug (assign_);
    debug (value_);
    debug (ident_);

    this->name_.enable_debugging ();
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             std::pair <std::string, Property_Map *> (const Property_Configuration_Map &),
                             SpaceT> config_;

  ::boost::spirit::qi::rule <IteratorT,
                             void (Property_Map *, const Property_Configuration_Map &),
                             ::boost::spirit::qi::locals <Property_Map *>,
                             SpaceT> base_list_;

  ::boost::spirit::qi::rule <IteratorT,
                             void (Property_Map *),
                             SpaceT> assignments_;

  ::boost::spirit::qi::rule <IteratorT,
                             std::pair <std::string, std::string> (),
                             SpaceT> assign_;

  ::Property_Name <IteratorT, SpaceT> name_;

  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> value_;

  ::boost::spirit::qi::rule <IteratorT,
                             std::string (),
                             SpaceT> ident_;
};

/**
 * @class Property_Configurations
 *
 * Grammar for parsing multiple property configuration definition as
 * seen in a file.
 */
template <typename IteratorT, typename SpaceT>
struct Property_Configurations :
  public boost::spirit::qi::grammar <IteratorT,
                                     void (Property_Configuration_Map &),
                                     boost::spirit::qi::ascii::space_type>
{
  /// Default constructor.
  Property_Configurations (void)
    : Property_Configurations::base_type (listing_),
      listing_ (std::string ("listing"))
  {
    namespace phoenix = boost::phoenix;
    namespace qi = boost::spirit::qi;

    using namespace qi::labels;

    using phoenix::at_c;
    using phoenix::val;

    this->listing_ =
      * (this->config_ (_r1)[
          // Add the configuration name to the property map, the
          // insert it into the configuration map.
          phoenix::bind (&Property_Map::set, at_c <1> (_1), val ("config.name"), at_c <0> (_1)),
          phoenix::insert (_r1, _1)]);

    using phoenix::construct;
    using phoenix::val;

    // Definition of the error handler.
    qi::on_error <qi::fail>
    (
      listing_,
      std::cerr << phoenix::val ("*** syntax error: expecting ")
                << qi::labels::_4
                << phoenix::val(" here; \"")
                << construct <std::string> (qi::labels::_3, qi::labels::_2)
                << phoenix::val("\"")
                << std::endl
    );
  }

  void enable_debugging (void)
  {
    debug (listing_);
    this->config_.enable_debugging ();
  }

private:
  ::boost::spirit::qi::rule <IteratorT,
                             void (Property_Configuration_Map &),
                             SpaceT> listing_;

  ::Property_Configuration <IteratorT, SpaceT> config_;
};


#endif  // !defined _PROPERTY_LIST_PARSER_HPP_
