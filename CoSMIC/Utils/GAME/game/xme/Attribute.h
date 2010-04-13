// -*- C++ -*-

//=============================================================================
/**
 * @file      Attribute.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_ATTRIBUTE_H_
#define _GAME_XME_ATTRIBUTE_H_

#include "xercesc/dom/DOM.hpp"
#include "Utils/xercesc/XercesString.h"
#include "XME_export.h"

namespace GME
{
namespace XME
{
// Forward decl.
class FCO;

/**
 * @class Atom
 *
 * Base class for all the objects
 */
class GAME_XME_Export Attribute
{
public:
  /**
   * Get an attribute on the specified FCO.
   *
   * @param[in]         fco         Target FCO
   * @param[in]         name        Name of the attribute
   */
  static Attribute _create (const FCO & fco, const ::Utils::XStr & name);

  /// Default constructor.
  Attribute (void);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Attribute (const Attribute & attr);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Attribute (xercesc::DOMElement * attr);

  /// Destructor.
  ~Attribute (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Attribute & operator = (const Attribute & attr);

  /// The XML tagname for this element.
  static const ::Utils::XStr TAGNAME;

  /**
   * Get the string value of the attribute.
   */
  const XMLCh * value (void) const;

  /**
   * Get the string value of the attribute.
   */
  void value (const ::Utils::XStr & v);
  void value (bool v);

  void attach (xercesc::DOMElement * attr, bool validate);

  static const ::Utils::XStr TRUE_VALUE;
  static const ::Utils::XStr FALSE_VALUE;

private:
  static const ::Utils::XStr VALUE_TAGNAME;
  static const ::Utils::XStr ATTR_KIND;

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Attribute (const FCO & parent, const ::Utils::XStr & name);

  void get_value_element (void) const;

  /// Pointer to the attribute element.
  xercesc::DOMElement * attr_;

  /// Pointer to the attribute's value element.
  mutable xercesc::DOMElement * value_;
};

}
}

#if defined (__GME_INLINE__)
#include "Attribute.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
