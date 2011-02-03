// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaProject.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_PROJECT_H_
#define _GAME_MGA_META_PROJECT_H_

#include "MetaFolder.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Project
 */
class GAME_MGA_Export Project
{
public:
  /// Default constructor.
  Project (void);

  Project (const Project & r);

  Project (IMgaMetaProject * p);

  /// Destructor.
  virtual ~Project (void);

  /// Get the root folder for the project.
  Folder root_folder (void) const;

  void attach (IMgaMetaProject * p);

  /// Release the current pointer. This will decrement the
  /// current reference count.
  void release (void);

  /// Get a pointer to the implementation.
  IMgaMetaProject * impl (void) const;

private:
  /// Pointer to the meta project.
  ATL::CComPtr <IMgaMetaProject> proj_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaProject.inl"
#endif

#endif
