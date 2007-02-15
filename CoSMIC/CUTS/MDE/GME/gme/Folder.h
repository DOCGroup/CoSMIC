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
#include "MetaFolder.h"

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
    /// Type definition of the base type.
    typedef Folder_Model_T <IMgaFolder, Object> _base_type;

  public:
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
    Folder _create (const std::string & type, Folder & parent);

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
    size_t folders (std::vector <Folder> & folders) const;

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
    MetaFolder meta (void) const;
  };
}

#endif  // !defined _GME_FOLDER_H_
