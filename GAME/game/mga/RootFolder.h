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

#ifndef _GAME_MGA_ROOT_FOLDER_H_
#define _GAME_MGA_ROOT_FOLDER_H_

#include "Folder.h"

namespace GAME
{
namespace Mga
{
/**
 * @class RootFolder_Impl
 *
 * The root folder for the project. It is not possible to create a root
 * folder
 */
class GAME_MGA_Export RootFolder_Impl : public virtual Folder_Impl
{
public:
  /// Default constructor.
  RootFolder_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       folder        The source folder interface.
   */
  RootFolder_Impl (IMgaFolder * folder);

  /// Destructor.
  virtual ~RootFolder_Impl (void);

  /// Accept a Visitor object.
  virtual void accept (Visitor * v);
};

/// Type definition of the RootFolder smart pointer.
typedef Smart_Ptr <RootFolder_Impl> RootFolder;

/// Type definition of the RootFolder imput parameter.
typedef RootFolder_Impl * RootFolder_in;
}
}

#if defined (__GAME_INLINE__)
#include "RootFolder.inl"
#endif

#endif
