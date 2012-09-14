// -*- C++ -*-

//=============================================================================
/**
 * @file      Folder.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_FOLDER_H_
#define _GAME_MGA_FOLDER_H_

#include "Iterator_T.h"
#include "FCO.h"
#include "MetaFolder.h"
#include "RegistryNode.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Folder_Impl
 *
 * Wrapper class for the IMgaFolder interface.
 */
class GAME_MGA_Export Folder_Impl : public virtual Object_Impl
{
public:
  /// Type definition of the interface type.
  typedef IMgaFolder interface_type;

  /// Type definition of the type tag.
  typedef folder_tag_t type_tag;

  /// Default constructor.
  Folder_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       folder        The source folder interface.
   */
  Folder_Impl (IMgaFolder * folder);

  /**
   * Create a folder.
   *
   * @param[in]       type          The folder's type.
   * @param[in]       parent        The parent folder.
   * @return          The newly created folder.
   */
  static Folder _create (const Folder_in parent, const std::string & type);
  static Folder _create (const Folder_in parent,  const Meta::Folder_in type);

  /// Destructor.
  virtual ~Folder_Impl (void);

  /**
   * Get the parent of this folder.
   *
   * @return      The parent folder.
   */
  Folder parent (void) const;

  /**
   * Get the meta information for this folder.
   *
   * @return      The folders meta information.
   */
  Meta::Folder meta (void) const;

  /**
   * Get all the first-level child folders of this folder.
   *
   * @return      Collection of folder objects.
   */
  size_t folders (std::vector <Folder> & items) const;

  /**
   * @overloaded
   */
  Iterator <Folder> folders (void) const;

  /**
   * Get all the first-level child folders of this folder.
   *
   * @return      Collection of folder objects.
   */
  template <typename T>
  size_t folders (const std::string & type, std::vector <T> & items) const;

  /**
   * Get all the first-level child folders of this folder.
   *
   * @return      Collection of folder objects.
   */
  template <typename T>
  size_t folders (std::vector <T> & items) const;

  /**
   * Get all the first-level child folders of this folder.
   *
   * @return      Collection of folder objects.
   */
  template <typename T>
  size_t children (std::vector <T> & items) const;

  /**
   * Get all the first-level child elements of this folder.
   *
   * @return      Collection of folder objects.
   */
  template <typename T>
  size_t children (const std::string & type, std::vector <T> & items) const;

  /// Get child elements of type T.
  template <typename T>
  Iterator <T> children (void) const;

  /// Get child elements of the specified type, and convert them to
  /// elements of type T.
  template <typename T>
  Iterator <T> children (const std::string & type) const;

  /**
   * Get a registry value.
   *
   * @param[in]   path      The path of the value.
   * @return      The value stored at \a path.
   */
  std::string registry_value (const std::string & path) const;

  /**
   * Set a registry value.
   *
   * @param[in]   path      The path of the value.
   * @param[in]   value     The new value of \a path.
   */
  void registry_value (const std::string & path, const std::string & value);

  /**
   * Get the registry node for this folder object.
   *
   * @return      The registry node.
   */
  RegistryNode registry_node (const std::string & path) const;

  /**
   * Get the registry nodes for this object.
   *
   * @param[in]   nodes     The collection of nodes.
   * @param[in]   vtypes    The the virtual nodes as well.
   * @return      Number of elements in \a nodes.
   */
  size_t registry (std::vector <RegistryNode> & nodes, bool vtypes = false) const;

  /// Accept the visitor.
  virtual void accept (Visitor * v);

  /**
   * Attach to an existing folder.
   *
   * @param[in]       folder        The source interface.
   */
  void attach (IMgaFolder * folder);

  /// Helper method to get the correct implementation.
  IMgaFolder * impl (void) const;

private:
  /// Pointer to the underlying COM interface.
  mutable ATL::CComPtr <IMgaFolder> folder_;
};

/**
 * @struct object_type_t
 *
 * Specialization of the object type for Folder_Impl.
 */
template < >
struct object_type_t <Folder_Impl>
{
  static const int result_type = OBJTYPE_FOLDER;
};

}
}

#if defined (__GAME_INLINE__)
#include "Folder.inl"
#endif

#include "Folder_T.cpp"

#endif  // !defined _GME_FOLDER_H_
