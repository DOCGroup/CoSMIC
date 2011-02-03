// -*- C++ -*-

//=============================================================================
/**
 * @file        XML_Parser.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_XML_PARSER_H_
#define _GME_XML_PARSER_H_

#if !defined (__ComponentLib_h__)
#include "Parser.h"
#endif

#include "GME_fwd.h"
#include "Exception.h"

namespace GAME
{
namespace Mga
{

/**
 * @struct XML_Info
 *
 * Project infomration about a .xme file.
 */
struct GAME_MGA_Export XML_Info
{
  std::string paradigm_;

  std::string paradigm_version_;

  std::string basename_;

  std::string version_;
};

/**
 * @class XML_Parser
 *
 * Wrapper class for the IMgaParser interface. This class simplifies
 * importing XML documents into an existing GME project.
 */
class GAME_MGA_Export XML_Parser
{
public:
  /// Default constructor.
  XML_Parser (void);

  /// Destructor.
  ~XML_Parser (void);

  /**
   * Get XML information from the specified file.
   *
   * @param[in]     xmlfile       Target XML file
   * @param[out]    info          Extracted XML information.
   */
  void get_info (const std::string & xmlfile, XML_Info & info);

  /**
   * Parser the specified XML file.
   *
   * @param[in]       xmlfile         Target XML file.
   */
  void parse (const std::string & xmlfile, Project & project);

private:
  /// Pointer to the parser's interface.
  CComPtr <IMgaParser> parser_;

  // prevent the following operations
  XML_Parser (const XML_Parser &);
  const XML_Parser & operator = (const XML_Parser &);
};

//=============================================================================
/**
 * @class XML_Parser
 *
 * Wrapper class for the IMgaParser interface. This class simplifies
 * importing XML documents into an existing GME project.
 */
//=============================================================================

class GAME_MGA_Export XML_Dumper
{
public:
  /// Default constructor.
  XML_Dumper (void);

  /// Destructor.
  ~XML_Dumper (void);

  /**
   * Parser the specified XML file.
   *
   * @param[in]       xmlfile         Target XML file.
   */
  void write (const std::string & xmlfile, Project & project);

private:
  /// Pointer to the parser's interface.
  CComPtr <IMgaDumper> dumper_;

  // prevent the following operations
  XML_Dumper (const XML_Dumper &);
  const XML_Dumper & operator = (const XML_Dumper &);
};

}
}

#if defined (__GAME_INLINE__)
#include "XML.inl"
#endif

#endif  // !defined _GME_XML_PARSER_H_
