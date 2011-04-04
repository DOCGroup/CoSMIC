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

#ifndef _GAME_MGA_META_FOLDER_H_
#define _GAME_MGA_META_FOLDER_H_

#include <vector>
#include "MetaBase.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Folder_Impl
 *
 * Wrapper class for the IMgaMetaFolder interface.
 */
class GAME_MGA_Export Folder_Impl : public Base_Impl
{
public:
  /// Type definition of the underlying interface.
  typedef IMgaMetaFolder interface_type;

  /// Default constructor.
  Folder_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        The source object.
   */
  Folder_Impl (IMgaMetaFolder * meta);

  /// Destructor.
  virtual ~Folder_Impl (void);

  /**
   * Get all the subfolders defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <Folder> & folders) const;

  /**
   * Get the specified meta Folder object.
   *
   * @param[in]       name            Name of the folder
   * @return          The meta folder object.
   */
  Folder folder (const std::string & name) const;

  /**
   * Get all the meta FCO objects defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <FCO> & fcos) const;

  /**
   * Get the specified meta FCO object.
   *
   * @param[in]       name            Name of the FCO
   * @return          The meta FCO object.
   */
  FCO child (const std::string & name) const;

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
  Folder find_folder (const std::string & name, bool in_scope = true);

private:
  /// Cached pointer to the metafolder.
  mutable CComPtr <IMgaMetaFolder> metafolder_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaFolder.inl"
#endif

#endif  // !defined _GAME_MGA_META_FOLDER_H_
