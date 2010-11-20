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

#ifndef _GME_FOLDER_H_
#define _GME_FOLDER_H_

#include "Object.h"
#include "MetaFolder.h"
#include "RegistryNode.h"

namespace GAME
{
/**
 * @class Folder
 *
 * Wrapper class for the IMgaFolder interface.
 */
class GAME_Export Folder : public Object
{
public:
  /// Type definition of the interface type.
  typedef IMgaFolder interface_type;

  /// Default constructor.
  Folder (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       folder        The source folder interface.
   */
  Folder (IMgaFolder * folder);

  /**
   * Copy constructor.
   *
   * @param[in]       folder        The source folder object.
   */
  Folder (const Folder & folder);

  /**
   * Create a folder.
   *
   * @param[in]       type          The folder's type.
   * @param[in]       parent        The parent folder.
   * @return          The newly created folder.
   */
  static Folder _create (Folder & parent, const std::string & type);
  static Folder _create (Folder & parent, const Meta::Folder & type);

  /**
   * Extract the folder element from the object.
   *
   * @param[in]       object        The source object.
   */
  static Folder _narrow (const GAME::Object & object);

  /// Destructor.
  virtual ~Folder (void);

  /**
   * Assignment operator.
   *
   * @param[in]       folder        The source folder object.
   * @return          Reference to this object.
   */
  const Folder & operator = (const Folder & folder);

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
  size_t children (std::vector <GAME::Folder> & folders) const;

  /**
   * Get all the first-level child folders of this folder.
   *
   * @return      Collection of folder objects.
   */
  size_t children (const std::string & type,
                   std::vector <GAME::Folder> & folders) const;

  size_t children (std::vector <GAME::FCO> & children) const;

  size_t children (const std::string & type,
                   std::vector <GAME::Atom> & children) const;

  size_t children (const std::string & type,
                   std::vector <GAME::Model> & children) const;

  size_t children (const std::string & type,
                   std::vector <GAME::Reference> & children) const;

  size_t children (const std::string & type,
                   std::vector <GAME::Set> & children) const;

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
  size_t registry (std::vector <GAME::RegistryNode> & nodes, bool vtypes = false) const;

  virtual void accept (GAME::Visitor & visitor);

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

}

#if defined (__GAME_INLINE__)
#include "Folder.inl"
#endif

#endif  // !defined _GME_FOLDER_H_