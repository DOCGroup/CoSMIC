// -*- C++ -*-

//=============================================================================
/**
 * @file          IDL_File_Parser.h
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_PARSER_HPP_
#define _IDL_FILE_PARSER_HPP_

#include <string>
#include "game/mga/GME_fwd.h"

/**
 * @class IDL_File_Parser
 */
class IDL_File_Parser
{
public:
  bool parse (std::string::const_iterator begin,
              std::string::const_iterator end,
              GAME::Mga::Object_in obj);
};

#endif  // !defined _IDL_FILE_PARSER_HPP_
