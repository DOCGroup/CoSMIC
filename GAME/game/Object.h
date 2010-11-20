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

#ifndef _GME_OBJECT_H_
#define _GME_OBJECT_H_

#include <atlbase.h>
#include <string>
#include <vector>
#include "MetaBase.h"

namespace GAME
{
// Forward decl.
class Visitor;

// Forward decl.
class Project;

/**
 * @class Object
 *
 * Wrapper class for the IMgaObject interface. This is also the base
 * class for all the GME modeling elements, such as Model, FCO, and
 * Folder.
 */
class GAME_Export Object
{
public:
  /// Type definition of the COM pointer type.
  typedef IMgaObject interface_type;

  /// Default constructor.
  Object (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     object        Source object to manage.
   */
  Object (IMgaObject * object);

  /**
   * Copy constructor.
   *
   * @param[in]     object        Source object to copy.
   */
  Object (const Object & object);

  /// Destructor.
  virtual ~Object (void);

  /**
   * Attach to an existing object.
   *
   * @param[in]     object        Source object to manage.
   */
  void attach (IMgaObject * object);

  /// Delete the object from the model.
  void destroy (void);

  /**
   * Assignment operator.
   *
   * @param[in]     object        Source object to copy.
   * @return        Reference to this object.
   */
  const Object & operator = (const Object & object);

  /**
   * Get the id of the object.
   *
   * @return        Id of the object.
   */
  std::string id (void) const;

  /**
   * Get the relative id of the object.
   *
   * @return        The relative id of the object.
   */
  long relative_id (void) const;

  /**
   * Set the relative id of the object.
   *
   * @param[in]     relid   Relative id of the object.
   */
  void relative_id (long relid);

  /**
   * Determine if the object is writable.
   *
   * @retval      true      The object is writable.
   * @retval      false     The object is not writable.
   */
  bool is_writable (void) const;

  /**
   * Determine if the object is a library object.
   *
   * @retval      true      The object is a library object.
   * @retval      false     The object is not a library object.
   */
  bool is_lib_object (void) const;

  /**
   * Get the status of the object.
   *
   * @return      The status of the object.
   */
  long status (void) const;

  /// Check the current object.
  void check (void);

  /// Check the current tree.
  void check_tree (void);

  /**
   * Get the name of the object.
   *
   * @return      The name of the object.
   */
  std::string name (void) const;

  /**
   * Set the name of the object.
   *
   * @param[in]   name      The new name of the object.
   */
  void name (const std::string & name);

  /**
   * Get the full path of the object.
   *
   * @param[in]     separator       The separator character to
   *                                us that appreas between subsequent
   *                                names.
   * @param[in]     leading         Separator appears at the beginning
   *                                of the path.
   * @return        The path of the string.
   */
  std::string path (const std::string & separator, bool leading = true) const;

  /**
   * Get the absolute path of the object.
   *
   * @return        The absolute path of the object.
   */
  std::string absolute_path (void) const;

  /**
   * Get the exempt status for the object.
   *
   * @retval        true          The object is exempt.
   * @retval        false         The object is not exempt.
   */
  bool exempt (void) const;

  /**
   * Set the exempt privileges for the object.
   *
   * @param[in]     exempt        The exempt status.
   */
  void exempt (bool exempt);

  /**
   * Set the read-only access privileges for this object.
   *
   * @param[in]     readonly      The readonly status.
   * @param[in]     propagate     Pass priviledges to all child
   *                              models.
   */
  void readonly_access (bool readonly, bool propagate);

  /**
   * Determine if the object has readonly access.
   *
   * @retval      true      The object is readonly.
   * @retval      false     The object is not readonly.
   */
  bool readonly_access (void) const;

  /**
   * Get the meta information for this object.
   *
   * @return      The meta info for the object.
   */
  Meta::Base meta (void) const;

  /**
   * Get the object's type.
   *
   * @return      The object's type.
   */
  objtype_enum type (void) const;

  /**
   * Get the parent of the object.
   *
   * @return      The parent of this object.
   */
  Object parent (void) const;

  /**
   * Get the underlying implemenation for the object. This returns
   * the actual COM pointer used to manage the object.
   *
   * @return      The IMgaObject pointer to the object.
   */
  IMgaObject * impl (void) const;

  /**
   * Test the equality of an object with this object.
   *
   * @param[in]       object        The source object.
   * @retval          true          The objects are equal.
   * @retval          false         The objects are not equal.
   */
  bool operator == (const Object & object) const;

  /**
   * Test the inequality of an object with this object.
   *
   * @param[in]       object        The source object.
   * @retval          true          The objects are not equal.
   * @retval          false         The objects are equal.
   */
  bool operator != (const Object & object) const;

  /**
   * Determine if the object is NIL.
   *
   * @retval          true          Object is NIL.
   * @retval          false         Object is not NIL.
   */
  bool is_nil (void) const;

  /**
   * Test if an object is equal to another object.
   *
   * @param[in]       obj           Object for comparison.
   */
  bool is_equal_to (const GAME::Object & obj) const;

  /**
   * Find a GME object relative to this location.
   *
   * @param[in]       path          Path name of the object.
   */
  GAME::Object find_object_by_path (const std::string & path) const;

  /**
   * Get the child objects of this object.
   *
   * @param[out]      children     Children of this object.
   * @return          Number of children.
   */
  size_t children (std::vector <GAME::Object> & children) const;

  /// Release the pointer to the object. This does not actually
  /// delete the object. Please see destory () to delete the
  /// object from the model.
  void release (void);

  /**
   * Get the project that owns the object.
   *
   * @return          The GME project that owns the object.
   */
  GAME::Project project (void) const;

  /**
   * Get the child object by its relative id.
   *
   * @param[in]       relid         Relative id of child object.
   * @return          The child object.
   */
  GAME::Object child_by_relative_id (long relid);

  bool operator < (const GAME::Object & obj) const;
  bool operator > (const GAME::Object & obj) const;

  /// Accept the GAME::Visitor object.
  virtual void accept (GAME::Visitor & visitor);

  /// Get the hash value of the object.
  unsigned long hash (void) const;

protected:
  /// The underlying COM pointer.
  ATL::CComPtr <IMgaObject> object_;
};
}

#if defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#endif  // !defined _GME_OBJECT_H_