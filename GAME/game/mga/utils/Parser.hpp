// -*- C++ -*-

//=============================================================================
/**
 * @file      Parser.hpp
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_UTIL_PARSER_HPP_
#define _GAME_UTIL_PARSER_HPP_

#include <string>
#include <vector>
#include "game/mga/Project.h"
#include "boost/spirit/include/qi.hpp"

#include "GAME_Utils_export.h"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

namespace GAME
{
namespace Mga
{

/**
 * @class PathParserConfig
 *
 * Configuration for the PathParser class.
 */
class GAME_UTILS_Export PathParserConfig
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       project       Source project
   */
  PathParserConfig (const Project & project);

  /// The project's paradigm directory.
  std::string paradigm_dir_;

  /// The project's project directory.
  std::string project_dir_;

private:
  /// Helper method to get a connection string path.
  static void get_connstr_path (std::string & out, const std::string & conn);
};

/**
 * @struct PathParser
 *
 * Boost grammar for parsing identifiers.
 */
template <typename IteratorT>
struct PathParser : qi::grammar <IteratorT, void (), ascii::space_type>
{
private:
  struct push_back
  {
    push_back (std::vector <std::string> & v, std::string & value)
      : v_ (v),
        value_ (value)
    {

    }

    void operator () (qi::unused_type, qi::unused_type, qi::unused_type) const
    {
      this->v_.push_back (this->value_);
    }

  private:
    std::vector <std::string> & v_;

    std::string & value_;
  };

  struct expand
  {
    expand (const PathParserConfig & config, std::string & value)
      : config_ (config),
        value_ (value)
    {

    }

    void operator () (std::string const & val, qi::unused_type, qi::unused_type) const
    {
      if (val == "PARADIGMDIR")
        this->value_.append (this->config_.paradigm_dir_);
      else if (val == "PROJECTDIR")
        this->value_.append (this->config_.project_dir_);
      else
        this->value_ += std::string ("$") + val;
    }

  private:
    const PathParserConfig & config_;

    std::string & value_;
  };

  struct append
  {
    append (std::string & value)
      : value_ (value)
    {

    }

    void operator () (std::string const & v, qi::unused_type, qi::unused_type) const
    {
      this->value_.append (v);
    }

  private:
    std::string & value_;
  };

  struct reset
  {
    reset (std::string & value)
      : value_ (value)
    {

    }

    void operator () (qi::unused_type, qi::unused_type, qi::unused_type) const
    {
      this->value_.clear ();
    }

  private:
    std::string & value_;
  };

public:
  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  PathParser (const PathParserConfig & config, std::vector <std::string> & paths)
    : PathParser::base_type (this->parser_),
      config_ (config),
      paths_ (paths),
      parser_ (std::string ("parser")),
      path_ (std::string ("path"))
  {
    this->parser_ =
      this->path_[push_back (this->paths_, this->value_)] >>
      *(qi::lit (';')[reset(this->value_)] >> this->path_[push_back (this->paths_, this->value_)]);

    this->path_ =
      this->envvar_[expand (this->config_, this->value_)] >>
      this->text_[append (this->value_)];

    this->envvar_ %= qi::lexeme[qi::lit ('$') >> +(qi::char_ - (qi::lit ('$') | '\\' | '/'))];

    this->text_ %= *(qi::char_ - (qi::lit (';')));
  }

private:
  const PathParserConfig & config_;

  std::vector <std::string> & paths_;

  std::string value_;

  qi::rule <IteratorT, void (), ascii::space_type> parser_;

  qi::rule <IteratorT, void (), ascii::space_type> path_;

  qi::rule <IteratorT, std::string (), ascii::space_type> text_;

  qi::rule <IteratorT, std::string (), ascii::space_type> envvar_;
};

}
}

#endif
