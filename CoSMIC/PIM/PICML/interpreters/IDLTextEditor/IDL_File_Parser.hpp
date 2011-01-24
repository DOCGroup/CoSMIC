// -*- C++ -*-

//=============================================================================
/**
 * @file          IDL_File_Parser.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_PARSER_HPP_
#define _IDL_FILE_PARSER_HPP_

#include "IDLTextEditor_Core_export.h"
#include <string>
#include "game/GME_fwd.h"

/**
 * @class IDL_File_Parser
 */
class IDLTEXTEDITOR_CORE_Export IDL_File_Parser
{
public:
  bool parse (std::string::const_iterator begin,
              std::string::const_iterator end,
              GAME::Object_in obj);
};

#endif  // !defined _IDL_FILE_PARSER_HPP_
