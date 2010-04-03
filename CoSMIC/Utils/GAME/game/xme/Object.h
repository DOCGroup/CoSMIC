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
#include "Utils/xercesc/XercesString.h"
#include "Object_Type.h"
#include "Exceptions.h"

namespace GME
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
  void name (const ::Utils::XStr & n);

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
  void attach (xercesc::DOMElement * e, bool validate = true);

  /**
   * Release the current element. The client takes ownership of
   * this element once this method returns.
   *
   * @return        The contained element.
   */
  xercesc::DOMElement * release (void);

  /**
   * Get a pointer to the underlying element.
   *
   * @return        The contained element.
   */
  xercesc::DOMElement * ptr (void) const;

  /**
   * Get the object's type. The returned value will be one of the
   * enumeration values in Object_Type::BITMASK.
   *
   * @return        The object's type.
   */
  int type (void) const;

  static bool _is_type (const std::string & type);

  static bool _is_type (const ::Utils::XStr & type);

protected:
  // Initializing constructor.
  Object (xercesc::DOMElement * parent,
          const ::Utils::XStr & tagname,
          const ::Utils::XStr & id,
          const ::Utils::XStr & kind,
          size_t relid);

  // Initializing constructor.
  Object (xercesc::DOMElement * e, int type);

  // Pointer to the object's implementation.
  xercesc::DOMElement * obj_;

  /// Type information for the object.
  int type_;

private:
  static const ::Utils::XStr ELEMENT_NAME;
  static const ::Utils::XStr ATTR_ID;
  static const ::Utils::XStr ATTR_KIND;
  static const ::Utils::XStr ATTR_RELID;
};

}
}

#if defined (__GME_INLINE__)
#include "Object.inl"
#endif

#endif  // !defined _GAME_XME_OBJECT_H_
