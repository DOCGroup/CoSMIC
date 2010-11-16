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
#include <memory>
#include "Object.h"
#include "Attribute.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Registry;

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
  Attribute attribute (const GAME::Xml::String & name, bool create = false) const;

  /**
   * Get the registry for this FCO.
   *
   * @return        Registry element
   */
  const Registry & registry (void) const;

  /**
   * @overload
   */
  Registry & registry (void);

protected:
  /// Initalizing constructor. This will create the actual
  /// FCO element and initialize its contents.
  FCO (xercesc::DOMElement * parent,
       const GAME::Xml::String & tagname,
       const GAME::Xml::String & id,
       const GAME::Xml::String & kind,
       const GAME::Xml::String & role,
       size_t relid);

  FCO (xercesc::DOMElement * fco, int type);

  static const GAME::Xml::String ATTR_ROLE;
  static const GAME::Xml::String ATTR_KIND;

private:
  /// Pointer to the object's registry.
  mutable std::auto_ptr <Registry> registry_;
};

}
}

#if defined (__GAME_INLINE__)
#include "FCO.inl"
#endif

#endif  // !defined _GAME_XME_FOLDER_H_
