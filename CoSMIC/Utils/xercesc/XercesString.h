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
  /// Default constructor.
  XStr (void) : _wstr(0L) { };

  XStr (const char* str);

  XStr (const std::string & str);

  XStr (XMLCh* wstr);

  XStr (const XMLCh* wstr);

  XStr (const XStr& copy);

  XStr& operator= (const XStr& rhs);

  ~XStr();

  const XMLCh* begin() const;

  const XMLCh* end() const;

  bool append(const XMLCh* tail);

  bool erase(const XMLCh* head, const XMLCh* tail);

  int size() const;

  XMLCh operator [] (const int i);

  const XMLCh operator [] (const int i) const;

  operator const XMLCh* () const;

  char* c_str() const;

  bool operator== (const XMLCh* wstr) const;


private:
  /// Internal representation of the string
  XMLCh* _wstr;
};

COSMIC_XERCES_UTILS_Export bool operator == (const XStr& lhs, const XStr& rhs);
COSMIC_XERCES_UTILS_Export bool operator != (const XStr& lhs, const XStr& rhs);

COSMIC_XERCES_UTILS_Export std::ostream& operator << (std::ostream& o, XStr const& str);

}

#endif /* _XERCESSTRING_H */
