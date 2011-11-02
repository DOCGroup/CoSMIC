// // -*- C++ -*-

//=============================================================================
/**
 * @file      Parameter_Parser.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_AUTOMATION_PARAMETER_PARSER_H_
#define _GAME_AUTOMATION_PARAMETER_PARSER_H_

#include <map>
#include <string>

/**
 * @struct Parameter_Parser
 *
 * Utility class for parsing parameter strings
 */
class Parameter_Parser
{
public:
  Parameter_Parser (void);

  bool parse (const char * str, std::map <std::string, std::string> & out);
};

#endif
