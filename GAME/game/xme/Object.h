// -*- C++ -*-

//=============================================================================
/**
 * @file      Object.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_OBJECT_H_
#define _GAME_XME_OBJECT_H_

#include "xercesc/dom/DOM.hpp"
#include "game/xml/String.h"
#include "Object_Type.h"
#include "Exceptions.h"

namespace GAME
{
namespace XME
{
/**
 * @class Object
 *
 * Base class for all the GME objects.
 */
class GAME_XME_Export Object
{
public:
  /// Default constructor.
  Object (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     e        Attached to specified element
   */
  Object (xercesc::DOMElement * e, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Object (const Object & obj);

  /// Destructor.
  virtual ~Object (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Object & operator = (const Object & obj);

  /**
   * Retrieve the object's id
   *
   * @return        Id of the object
   */
  const XMLCh * id (void) const;

  /**
   * Get the name of the object.
   *
   * @return        The name of the object.
   */
  const XMLCh * name (void) const;

  /**
   * Set the name of the object.
   *
   * @param[in]     n         Name of the element.
   */
  void name (const GAME::Xml::String & n);

  /**
   * Test objects for equality.
   *
   * @param[in]     rhs       Right-hand side of operator
   * @retval        true      Objects are equal
   * @retval        false     Objects are not equal
   */
  bool operator == (const Object & rhs) const;

  /**
   * Test objects for inequality.
   *
   * @param[in]     rhs       Right-hand side of operator
   * @retval        true      Objects are not equal
   * @retval        false     Objects are equal
   */
  bool operator != (const Object & rhs) const;

  /// Destroy this object. This will remove this object from
  /// the model and release all its resources.
  void destroy (void);

  /**
   * Get the parent of the object. If the object is a Folder, then
   * the parent will be another Folder. If the object is not a
   * Folder, then the parent is either a Model or Folder.
   *
   * @return        Parent of this model.
   */
  Object parent (void) const;

  /// Test if the object is NIL.
  bool is_nil (void) const;

  /**
   * Attach to an existing element.
   *
   * @param[in]     e         Source element.
   */
  virtual void attach (xercesc::DOMElement * e, bool validate = true);

  /**
   * Release the current element. The client takes ownership of
   * this element once this method returns.
   *
   * @return        The contained element.
   */
  virtual xercesc::DOMElement * release (void);

  /**
   * Get a pointer to the underlying element.
   *
   * @return        The contained element.
   */
  xercesc::DOMElement * ptr (void) const;

  /**
   * Set the object as readonly.
   *
   */
  void readonly (bool flag, bool recurse = true);

  /// Get the readonly state of the object.
  bool readonly (void) const;

  /**
   * Get the object's type. The returned value will be one of the
   * enumeration values in Object_Type::BITMASK.
   *
   * @return        The object's type.
   */
  int type (void) const;

  static bool _is_type (const std::string & type);

  static bool _is_type (const GAME::Xml::String & type);

  unsigned long hash (void) const;

  const XMLCh * kind (void) const;

  /**
   * Get the path of the current element. The path of the fully
   * qualified name of the element up to the root folder.
   */
  GAME::Xml::String path (const GAME::Xml::String & separator = L"/") const;

protected:
  // Initializing constructor.
  Object (xercesc::DOMElement * parent,
          const GAME::Xml::String & tagname,
          const GAME::Xml::String & id,
          const GAME::Xml::String & kind,
          size_t relid);

  // Initializing constructor.
  Object (xercesc::DOMElement * e, int type);

  // Pointer to the object's implementation.
  xercesc::DOMElement * obj_;

  /// Type information for the object.
  int type_;

private:
  static const GAME::Xml::String ELEMENT_NAME;
  static const GAME::Xml::String ATTR_ID;
  static const GAME::Xml::String ATTR_KIND;
  static const GAME::Xml::String ATTR_RELID;
  static const GAME::Xml::String ATTR_PERM;
};

}
}

#if defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#endif  // !defined _GAME_XME_OBJECT_H_
