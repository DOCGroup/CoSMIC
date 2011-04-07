// -*- C++ -*-

//=============================================================================
/**
 *  @file       copy.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_MANIP_COPY_H_
#define _GAME_MANIP_COPY_H_

#include <map>
#include <set>

#include "game/mga/Model.h"
#include "game/mga/Folder.h"

#include "Manipulation_export.h"

namespace GAME
{
namespace Mga
{

GAME_MANIPULATION_Export
FCO copy_attributes (const FCO_in src, FCO_in dst);

GAME_MANIPULATION_Export
void copy_location (const FCO_in src,
                    FCO_in dst,
                    const std::string & aspect = "");

/**
 * @struct copy_config_t
 *
 * Configuration information when copying an element from one model to
 * another model. The default configuration does not define an aspect,
 * and copies location information. Also, the copied elements are returned
 * in the \a mapping_ variable. This is useful if you need to chain more
 * more than on copy () operation.
 */
struct GAME_MANIPULATION_Export copy_config_t
{
  /// Default configuration.
  copy_config_t (void);

  /// The target aspect to copy.
  std::string aspect_;

  /// Mapping of element.
  std::map <FCO, FCO> mapping_;

  /// Copy location information.
  bool location_info_;

  /// Allow objects with duplicate names.
  bool allow_duplicate_names_;

  /// Allow duplicate connections in model.
  bool allow_duplicate_connections_;

  /// Set of ignorable FCOs.
  std::set <FCO> ignorable_fcos_;
};

/**
 * Copy the elements from the \a src model to the \a dst model. This
 * version uses the default configuration.
 */
GAME_MANIPULATION_Export
Model copy (const Model_in src, Model_in dst);

GAME_MANIPULATION_Export
Model copy (const Model_in src,
            Model_in dst,
            copy_config_t & config);

GAME_MANIPULATION_Export
Folder copy (const Folder_in src, Folder_in dst);

GAME_MANIPULATION_Export
Folder copy (const Folder_in src,
             Folder_in dst,
             copy_config_t & config);

GAME_MANIPULATION_Export
Folder copy_into (const std::vector <FCO> & fcos,
                  Folder_in dst,
                  copy_config_t & config);

GAME_MANIPULATION_Export
Model copy_into (const std::vector <FCO> & fcos,
                 Model_in dst,
                 copy_config_t & config);
}
}

#endif  // !defined _GAME_MANIP_COPY_H_
