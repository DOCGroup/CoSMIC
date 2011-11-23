// $Id$

#include "stdafx.h"
#include "Configuration_File.h"
#include "boost/spirit/include/support_istream_iterator.hpp"
#include <fstream>

//
// read
//
bool Configuration_File::
read (const std::string & filename, Property_Configuration_Map & pcm)
{
  namespace spirit  = boost::spirit;
  namespace qi      = spirit::qi;
  namespace phoenix = boost::phoenix;

  // Open the file for reading.
  std::ifstream input;
  input.open (filename.c_str ());

  if (!input.is_open ())
    return false;

  // Disable whitespace skipping.
  long flags = input.flags ();

  if ((flags & std::ios::skipws) != 0)
    input.unsetf (std::ios::skipws);

  // Adapt the iterator to support Boost backtracking.
  spirit::istream_iterator begin_iter (input);
  spirit::istream_iterator end_iter;

  Property_Configurations <spirit::istream_iterator,
                           spirit::ascii::space_type> grammar;

  // Parse the file contents.
  bool retval =
    qi::phrase_parse (begin_iter,
                      end_iter,
                      grammar (phoenix::ref (pcm)),
                      boost::spirit::ascii::space);

  // Close the file.
  input.close ();

  return retval;
}
