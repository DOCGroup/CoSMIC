// -*- C++ -*-

//=============================================================================
/**
 * @file        XercesString.h
 *
 * $Id$
 *
 * @author      Krishnakumar Balasubramanian
 */
//=============================================================================

#ifndef _XERCESSTRING_H
#define _XERCESSTRING_H

#include <iosfwd>
#include <memory>
#include <string>
#include "xercesc/util/XMLString.hpp"
#include "Configuration.h"
#include "game/config.h"

namespace GAME
{
namespace Xml
{
/**
 * @class String
 *
 * Wrapper class for working with Xerces strings. This class
 * allows applications to program with Xerces strings as if the8
 * are STL strings.
 */
class GAME_XML_Export String
{
public:
  /**
   * Default constructor.
   *
   * @param[in]         allocator       Pointer to the string's allocator
   */
  String (xercesc::MemoryManager * const allocator = GLOBAL_CONFIGURATION::instance ()->memory_manager ());

  /**
   * Initializing constructor.
   *
   * @param[in]     str         Source string
   */
  String (const char * str,
        xercesc::MemoryManager * const allocator = GLOBAL_CONFIGURATION::instance ()->memory_manager ());

  /**
   * @overload
   */
  String (const std::string & str,
          xercesc::MemoryManager * const allocator = GLOBAL_CONFIGURATION::instance ()->memory_manager ());

  /**
   * @overload
   *
   * @param[in]     release     Take ownership of string
   */
  String (const XMLCh * wstr,
          bool release = true,
          xercesc::MemoryManager * const allocator = GLOBAL_CONFIGURATION::instance ()->memory_manager ());

  /**
   * Copy constructor
   *
   * @param[in]     copy        Source string
   */
  String (const String & copy,
          xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /// Destructor.
  ~String (void);

  const String & operator = (const char * rhs);
  const String & operator = (const XMLCh * rhs);
  const String & operator = (const String & rhs);

  XMLCh * begin (void);
  const XMLCh * begin (void) const;

  XMLCh * end (void);
  const XMLCh * end (void) const;

  void append (const XMLCh * tail);

  // bool erase (const XMLCh * head, const XMLCh * tail);

  /**
   * Get the length of the string.
   *
   * @return      Number of character in string.
   */
  size_t length (void) const;

  /**
   * Get character at the specified index.
   *
   * @param[in]       i       Source index
   * @return          Character of interest
   */
  XMLCh & operator [] (size_t i);

  /**
   * @overload
   */
  const XMLCh & operator [] (size_t i) const;

  /**
   * Convert the object to a XMLCh pointer.
   *
   * @return      Pointer to the string.
   */
  operator const XMLCh * (void) const;
  operator XMLCh * (void);

  /**
   * Get the string value. This will replace the old value
   * and release its resources, if necessary.
   *
   * @param[in]       str           The new string value
   * @param[in]       release       Take ownership of new string
   */
  void set (const XMLCh * str,
            bool release = true,
            xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  void set (const char * str,
            xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  const std::string & to_string (void) const;

  bool operator == (const XMLCh * wstr) const;
  bool operator != (const XMLCh * wstr) const;

  bool operator == (const String & rhs) const;
  bool operator != (const String & rhs) const;

  static const String EMPTY_STRING;

  /// Clear the string's contents.
  void clear (void);

  int find (const XMLCh ch, size_t start = 0);

  /// Test if the string is empty.
  bool empty (void) const;

private:
  /// Pointer to the actual string.
  XMLCh * wstr_;

  /// Release the contained string.
  bool release_;

  /// Pointer to the allocator for this string.
  xercesc::MemoryManager * allocator_;

  /// C string version of the string.
  mutable std::auto_ptr <std::string> as_string_;
};


}
}

GAME_XML_Export std::ostream & operator << (std::ostream & o, const GAME::Xml::String & str);

GAME_XML_Export bool operator == (const XMLCh * lhs, const GAME::Xml::String & rhs);
GAME_XML_Export bool operator != (const XMLCh * lhs, const GAME::Xml::String & rhs);

#if defined (__GAME_INLINE__)
#include "String.inl"
#endif

#endif /* _XERCESSTRING_H */
