// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFolder.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METAFOLDER_H_
#define _GME_METAFOLDER_H_

#include "MetaBase.h"
#include <vector>

namespace GME
{
  //===========================================================================
  /**
   * @class MetaFolder
   *
   * Wrapper class for the IMgaMetaFolder interface.
   */
  //===========================================================================

  class GME_Export MetaFolder : public MetaBase
  {
  public:
    /// Default constructor.
    MetaFolder (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     meta        The source object.
     */
    MetaFolder (IMgaMetaFolder * meta);

    /**
     * Copy constructor.
     *
     * @param[in]     meta        The meta folder.
     */
    MetaFolder (const MetaFolder & meta);

    /// Destructor.
    virtual ~MetaFolder (void);

    /**
     * Attach to an existing meta folder.
     *
     * @param[in]     meta        The existing meta folder.
     */
    void attach (IMgaMetaFolder * meta);

    /**
     * Get a meta folder by name.
     *
     * @param[in]       name            The type name of the folder.
     * @return          The meta information for the folder.
     */
    MetaFolder folder (const std::string & type) const;

    /**
     * Get all the subfolders defined by this folder.
     *
     * @param[out]      metafolder      Collection of meta folders
     * @return          Number of folders in \a metafolders.
     */
    size_t folders (std::vector <MetaFolder> & metafolders) const;

    /**
     * Convert the object to an implementation pointer.
     *
     * @return          Pointer to the implementation.
     */
    operator IMgaMetaFolder * (void) const;

    /**
     * Get a pointer to the implementation.
     *
     * @return          Pointer to the implementation.
     */
    IMgaMetaFolder * impl (void) const;

  private:
    /// Cached pointer to the metafolder.
    mutable CComPtr <IMgaMetaFolder> metafolder_;
  };
}

#if defined (__GME_INLINE__)
#include "MetaFolder.inl"
#endif

#endif  // !defined _GME_METAFOLDER_H_
