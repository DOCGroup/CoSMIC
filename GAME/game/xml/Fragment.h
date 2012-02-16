// -*- C++ -*-

//=============================================================================
/**
 *  @file         Fragment.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _GAME_XML_FRAGMENT_H_
#define _GAME_XML_FRAGMENT_H_

#include "xercesc/dom/DOMElement.hpp"
#include "String.h"

namespace GAME
{
namespace Xml
{
/**
 * @class Fragment
 *
 * Wrapper class for a fragment of an XML document.
 */
class GAME_XML_Export Fragment
{
public:
  /// Default constructor
  Fragment (xercesc::DOMElement * e = 0);

  /// Copy constructor.
  Fragment (const Fragment & f);

  /// Destructor.
  virtual ~Fragment (void);

  /**
   * Helper class for creating a DOM element that has simple
   * content. Simple content is defined as <name>value</name>.
   */
  static
    xercesc::DOMElement *
    create_simple_content (xercesc::DOMElement * parent,
                           const String & name,
                           const String & value);

  static
    xercesc::DOMElement *
    create_simple_content (xercesc::DOMElement * parent,
                           const String & ns,
                           const String & name,
                           const String & value);

  static
    xercesc::DOMElement *
    create_element (xercesc::DOMElement * parent,
                    const String & name);

  static
    xercesc::DOMElement *
    create_element (xercesc::DOMElement * parent,
                    const String & ns,
                    const String & name);

  /**
   * Create an element at the end of the current fragment.
   *
   * @param[in]       name        Name of the element.
   */
  xercesc::DOMElement * create_element (const String & name);
  xercesc::DOMElement * create_element (const String & ns, const String & name);

  /**
   * Create a simple content element at the end of the current
   * fragment.
   *
   * @param[in]       name        Name of the element.
   * @param[in]       value       Text value of the content.
   */
  xercesc::DOMElement * create_simple_content (const String & name, const String & value);
  xercesc::DOMElement * create_simple_content (const String & ns, const String & name, const String & value);

  /// Get a pointer to the fragment.
  xercesc::DOMElement * operator -> (void);
  xercesc::DOMElement * ptr (void);

  operator xercesc::DOMElement * (void);

  void operator = (xercesc::DOMElement * e);

  void set_attribute (const String & name, const String & value);
  void set_attribute (const String & name, bool value);
  void set_attribute (const String & name, double value);
  void set_attribute (const String & name, long value);

protected:
  /// Pointer to the current fragment.
  xercesc::DOMElement * fragment_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Fragment.inl"
#endif

#endif  // !defined _GAME_XML_DOCUMENT_H_
