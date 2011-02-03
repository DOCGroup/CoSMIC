// $Id$

#include "stdafx.h"
#include "Image_Resolver.h"

#if !defined (__GAME_INLINE__)
#include "Image_Resolver.inl"
#endif

#include "game/mga/utils/Parser.hpp"

namespace GAME
{
namespace Mga
{
namespace graphics
{

///////////////////////////////////////////////////////////////////////////////
// Image_Resolver

//
// refresh_paths
//
bool Image_Resolver::
refresh (const Project & project,
         const Registrar & r,
         Registrar::ACCESS_MODE mode)
{
  // Extract paths from registrar and tokenize the string.
  std::string path = r.icon_path (mode);

  using boost::phoenix::ref;
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  // Initialize the parser.
  PathParserConfig config (project);
  PathParser <std::string::const_iterator> grammar (config, this->paths_);

  return qi::phrase_parse (path.begin (),
                           path.end (),
                           grammar,
                           ascii::space);
}

//
// lookup_icon
//
bool Image_Resolver::
lookup_icon (const std::string & icon_filename,
             std::string & out_filename)
{
  bool retval = false;
  std::vector <std::string>::const_iterator
    iter = this->paths_.begin (), iter_end = this->paths_.end ();

  std::string filename;
  HANDLE handle = INVALID_HANDLE_VALUE;

  for (; iter != iter_end; ++ iter)
  {
    WIN32_FIND_DATA finddata;
    filename = *iter + "\\" + icon_filename;

    handle = ::FindFirstFile (filename.c_str (), &finddata);

    if (handle != INVALID_HANDLE_VALUE)
    {
      retval = true;
      out_filename = filename;
      break;
    }
  }

  ::FindClose (handle);
  return retval;
}

}
}
}
