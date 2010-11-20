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

#ifndef _GME_META_FOLDER_H_
#define _GME_META_FOLDER_H_

#include <vector>
#include "MetaBase.h"
#include "MetaFCO.h"

namespace GAME
{
namespace Meta
{
/**
 * @class Folder
 *
 * Wrapper class for the IMgaMetaFolder interface.
 */
class GAME_Export Folder : public Base
{
public:
  /// Type definition of the underlying interface.
  typedef IMgaMetaFolder interface_type;

  /// Default constructor.
  Folder (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        The source object.
   */
  Folder (IMgaMetaFolder * meta);

  /**
   * Copy constructor.
   *
   * @param[in]     meta        The meta folder.
   */
  Folder (const Folder & meta);

  /// Destructor.
  virtual ~Folder (void);

  /**
   * Get all the subfolders defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <Folder> & folders) const;

  /**
   * Get all the subfolders defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <FCO> & fcos) const;

  FCO child (const std::string & name) const;

  Folder folder (const std::string & name) const;

  /**
   * Get a pointer to the implementation.
   *
   * @return          Pointer to the implementation.
   */
  IMgaMetaFolder * impl (void) const;

  /**
   * Get the meta FCO for the specified name.
   *
   * @param[in]       name        Name of the FCO.
   * @param[in]       in_scope    Scope of the FCO.
   * @return          Meta FCO object.
   */
  FCO find (const std::string & name, bool in_scope = true);

private:
  /// Cached pointer to the metafolder.
  mutable CComPtr <IMgaMetaFolder> metafolder_;
};
}
}

#if defined (__GAME_INLINE__)
#include "MetaFolder.inl"
#endif

#endif  // !defined _GME_METAFOLDER_H_