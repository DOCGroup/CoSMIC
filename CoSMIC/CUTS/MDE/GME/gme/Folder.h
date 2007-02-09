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

#include "GME_fwd.h"
#include "Object.h"
#include <vector>

namespace GME
{
  //===========================================================================
  /**
   * @class Folder
   *
   * Wrapper class for the IMgaFolder interface.
   */
  //===========================================================================

  class GME_Export Folder : public Object
  {
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
     * Attach to a preexisting folder object.
     *
     * @param[in]       folder        The source folder interface.
     */
    void attach (IMgaFolder * folder);

    /**
     * Get all the first-level child folders of this folder.
     *
     * @return      Collection of folder objects.
     */
    std::vector <Folder> folders (void) const;

    /**
     * Get all the root FCOs elements in this folder.
     *
     * @return      Collection of FCO objects.
     */
    std::vector <FCO> fcos (void) const;

    /**
     * Get all the FCOs of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of FCOs of the specified \a type.
     */
    std::vector <FCO> fcos (const std::string & type) const;

    /**
     * Get all the atoms of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of atoms of the specified \a type.
     */
    std::vector <Atom> atoms (const std::string & type) const;

    /**
     * Get all the models of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of models of the specified \a type.
     */
    std::vector <Model> models (const std::string & type) const;

    /**
     * Get all the sets of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of sets of the specified \a type.
     */
    std::vector <Set> sets (const std::string & type) const;

  private:
    /// Helper method to get the correct implementation.
    IMgaFolder * impl (void) const;

    /// Helper method that gets the children of a specified \a type
    /// and returns them as the specified GME type (i.e., Model, FCO,
    /// Atom, and etc). This function can only be used by folders and
    /// models. All other will not compile since they do not define
    /// the appropriate methods.
    template <typename T>
    std::vector <T> get_children (const std::string & type) const;

    /// Underlying COM pointer to the IMgaFolder interface.
    mutable CComPtr <IMgaFolder> folder_;
  };
}

#endif  // !defined _GME_FOLDER_H_
