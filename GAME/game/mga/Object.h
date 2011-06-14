// -*- C++ -*-

//=============================================================================
/**
 * @file      Object_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_OBJECT_H_
#define _GAME_MGA_OBJECT_H_

#include <atlbase.h>
#include <string>
#include <vector>

#include "GME_fwd.h"
#include "MetaBase.h"
#include "Refcountable.h"
#include "Tags.h"

namespace GAME
{
namespace Mga
{

template <typename T>
struct object_type_t
{
  static const int result_type = OBJTYPE_NULL;
};

/**
 * @class Object_Impl
 *
 * Wrapper class for the IMgaObject interface. This is also the base
 * class for all the GME modeling elements, such as Model_Impl, FCO_Impl, and
 * Folder_Impl.
 */
class GAME_MGA_Export Object_Impl : public virtual Refcountable
{
public:
  /// Type definition of the COM pointer type.
  typedef IMgaObject interface_type;

  /// Type definition of the type tag.
  typedef object_tag_t type_tag;

  /// Default constructor.
  Object_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     object        Source object to manage.
   */
  Object_Impl (IMgaObject * object);

  /// Destructor.
  virtual ~Object_Impl (void);

  /**
   * Attach to an existing object.
   *
   * @param[in]     object        Source object to manage.
   */
  void attach (IMgaObject * object);

  /// Delete the object from the model.
  void destroy (void);

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
   * Set_Impl the relative id of the object.
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
   * Set_Impl the name of the object.
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
   * Set_Impl the exempt privileges for the object.
   *
   * @param[in]     exempt        The exempt status.
   */
  void exempt (bool exempt);

  /**
   * Set_Impl the read-only access privileges for this object.
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
   * Test if an object is equal to another object.
   *
   * @param[in]       obj           Implementation for comparison.
   */
  bool is_equal_to (const Object_in obj) const;

  /**
   * Find a GME object relative to this location.
   *
   * @param[in]       path          Path name of the object.
   */
  Object find_object_by_path (const std::string & path) const;

  /**
   * Get the child objects of this object.
   *
   * @param[out]      children     Children of this object.
   * @return          Number of children.
   */
  size_t children (std::vector <Object> & children) const;

  /// Release the pointer to the object. This does not actually
  /// delete the object. Please see destory () to delete the
  /// object from the model.
  void release (void);

  /**
   * Get the project that owns the object.
   *
   * @return          The GME project that owns the object.
   */
  Project project (void) const;

  /**
   * Get the child object by its relative id.
   *
   * @param[in]       relid         Relative id of child object.
   * @return          The child object.
   */
  Object child_by_relative_id (long relid);

  /// Get the hash value of the object.
  unsigned long hash (void) const;

  /// Force all objects to implement an accept method.
  virtual void accept (Visitor * v) = 0;

  /// Test of the object is mutable. An object is mutable if it
  /// is not readonly or it is not a library object. This means
  /// the object can be changed.
  bool is_mutable (void) const;

protected:
  /// The underlying COM pointer.
  ATL::CComPtr <IMgaObject> object_;

private:
  // prevent the following operations
  Object_Impl (const Object_Impl &);
  const Object_Impl & operator = (const Object_Impl &);
};

}
}

#if defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#endif  // !defined _GME_OBJECT_H_
