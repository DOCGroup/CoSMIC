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

#include "Folder_Model_T.h"
#include "RegistryNode.h"
#include "Object.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Folder
   *
   * Wrapper class for the IMgaFolder interface.
   */
  //===========================================================================

  class GME_Export Folder :
    public Folder_Model_T <IMgaFolder, Object>
  {
  public:
    /// Type definition of the base type.
    typedef Folder_Model_T <IMgaFolder, Object> _base_type;

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
    static Folder _create (const std::string & type, Folder & parent);

    /**
     * Extract the folder element from the object.
     *
     * @param[in]       object        The source object.
     */
    static Folder _narrow (const GME::Object & object);

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
     * Get all the first-level child folders of this folder.
     *
     * @return      Collection of folder objects.
     */
    size_t folders (GME::Collection_T <GME::Folder> & folders) const;

    /**
     * Get all the first-level child folders of this folder.
     *
     * @return      Collection of folder objects.
     */
    size_t folders (const std::string & type,
                    GME::Collection_T <GME::Folder> & folders) const;

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
    size_t registry (GME::Collection_T <GME::RegistryNode> & nodes,
                     bool vtypes = false) const;
  };
}

#endif  // !defined _GME_FOLDER_H_
