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
#include "Xerces_Utils_export.h"

// Utility class that provides a std::string like facade to XMLString.
// Doesn't implement all of the methods of std::string.

namespace Utils
{
/**
 * @class XStr
 *
 * Wrapper class for working with Xerces strings. This class
 * allows applications to program with Xerces strings as if the8
 * are STL strings.
 */
class COSMIC_XERCES_UTILS_Export XStr
{
public:
  /**
   * Default constructor.
   *
   * @param[in]         allocator       Pointer to the string's allocator
   */
  XStr (xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /**
   * Initializing constructor.
   *
   * @param[in]     str         Source string
   */
  XStr (const char * str, xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /**
   * @overload
   */
  XStr (const std::string & str, xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /**
   * @overload
   *
   * @param[in]     release     Take ownership of string
   */
  XStr (const XMLCh * wstr,
        bool release = true,
        xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /**
   * Copy constructor
   *
   * @param[in]     copy        Source string
   */
  XStr (const XStr & copy,
        xercesc::MemoryManager * const allocator = xercesc::XMLPlatformUtils::fgMemoryManager);

  /// Destructor.
  ~XStr (void);

  const XStr & operator = (const char * rhs);
  const XStr & operator = (const XMLCh * rhs);
  const XStr & operator = (const XStr & rhs);

  XMLCh * begin (void);
  const XMLCh * begin (void) const;

  XMLCh * end (void);
  const XMLCh * end (void) const;

  void append (const XMLCh * tail);

  // bool erase (const XMLCh * head, const XMLCh * tail);

  /**
   * Get the size of the string.
   *
   * @return      Number of character in string.
   */
  size_t size (void) const;

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

  bool operator == (const XStr & rhs) const;
  bool operator != (const XStr & rhs) const;

  static const ::Utils::XStr EMPTY_STRING;

  /// Clear the string's contents.
  void clear (void);

  int find (const XMLCh ch, size_t start = 0);

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

COSMIC_XERCES_UTILS_Export std::ostream & operator << (std::ostream & o, const XStr & str);

}

COSMIC_XERCES_UTILS_Export bool operator == (const XMLCh * lhs, const ::Utils::XStr & rhs);
COSMIC_XERCES_UTILS_Export bool operator != (const XMLCh * lhs, const ::Utils::XStr & rhs);

#include "XercesString.inl"

#endif /* _XERCESSTRING_H */
