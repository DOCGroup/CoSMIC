// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Impl_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_IMPL_NODE_H_
#define _CUTS_BE_IMPL_NODE_H_

#include "BE_IDL_Node.h"

//=============================================================================
/**
 * @struct CUTS_BE_Impl_Node
 *
 * Dependency information for a implemenation file. This node contains
 * elements that reflect the dependencies of a specific implementation
 * such as include files or import libraries. This node also has the
 * ability to reference stubs, which it is depends. This is useful to
 * workspace generators that need to generate workspace/project files
 * for a project/implementation.
 */
//=============================================================================

struct CUTS_BE_Export CUTS_BE_Impl_Node :
  public CUTS_BE_IDL_Node
{
  CUTS_BE_Impl_Node (const std::string & name);

  /// Collection of include files.
  CUTS_String_Set include_;

  /// Collection of include file paths.
  CUTS_String_Set include_paths_;

  /// Collection of import library paths.
  CUTS_String_Set lib_paths_;

  /// Collection of import libraries.
  CUTS_String_Set lib_;

  enum
  {
    /// The implementation contains an executor.
    IMPL_EXEC   = 0,

    /// The implementation contains a proxy.
    IMPL_PROXY  = 1
  };

  std::bitset <2> impl_flags_;
};

#if defined (__CUTS_INLINE__)
#include "BE_Impl_Node.inl"
#endif

#endif  // !defined _CUTS_BE_IMPL_NODE_H_
