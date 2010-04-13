// -*- C++ -*-

//=============================================================================
/**
 * @file      FCO.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_FCO_H_
#define _GAME_XME_FCO_H_

#include <vector>
#include "Object.h"
#include "Attribute.h"

namespace GME
{
namespace XME
{
/**
 * @class FCO
 *
 * Base class for all the objects
 */
class GAME_XME_Export FCO : public Object
{
public:
  /// Default constructor.
  FCO (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  FCO (xercesc::DOMElement * fco, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  FCO (const FCO & fco);

  /// Destructor.
  ~FCO (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const FCO & operator = (const FCO & fco);

  void attach (xercesc::DOMElement * fco, bool validate = true);

  size_t attributes (std::vector <Attribute> & attrs) const;
  Attribute attribute (const ::Utils::XStr & name, bool create = false) const;

protected:
  /// Initalizing constructor. This will create the actual
  /// FCO element and initialize its contents.
  FCO (xercesc::DOMElement * parent,
       const ::Utils::XStr & tagname,
       const ::Utils::XStr & id,
       const ::Utils::XStr & kind,
       const ::Utils::XStr & role,
       size_t relid);

  FCO (xercesc::DOMElement * fco, int type);

  static const ::Utils::XStr ATTR_ROLE;
  static const ::Utils::XStr ATTR_KIND;
};

}
}

#if defined (__GME_INLINE__)
#include "FCO.inl"
#endif

#endif  // !defined _GAME_XME_FOLDER_H_
