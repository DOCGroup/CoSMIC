// $Id: Utils.h 598 2006-01-10 03:02:28Z alhad $

#ifndef _GAME_UTILS_H
#define _GAME_UTILS_H

#include <windows.h>
#include <shlobj.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <memory>
#include <cctype>

#include "Mga_export.h"

namespace GAME
{
namespace Utils
{

/**
 * Get the output directory. This will open a dialog box that
 * will allow the user to select a folder on disk, or create
 * one, that will be the output path.
 *
 * @param[in]       prompt      Message to display to the user.
 * @param[out]      path        Path selected by the user.
 * @retval          true        The user selected OK.
 * @retval          false       The user selected Cancel.
 */
GAME_MGA_Export
bool get_path (const std::string & prompt, std::string & path);

/**
 * Get the output directory. This will open a dialog box that
 * will allow the user to select a folder on disk, or create
 * one, that will be the output path.
 *
 * @param[in]       prompt      Message to display to the user.
 * @param[out]      path        Path selected by the user.
 * @param[in]       initdir     Initial directory to select.
 * @retval          true        The user selected OK.
 * @retval          false       The user selected Cancel.
 */
GAME_MGA_Export
bool get_path (const std::string & prompt,
               std::string & path,
              const std::string & initdir);

/**
 * Create a path on disk. If the path does not exist, then all
 * parent directories that do not exist will be created as well.
 *
 * @param[in]       path        Target path to create.
 * @param[in]       seperator   The seperator for directories.
 */
GAME_MGA_Export
bool create_path (const std::string & path, char separator = '\\');

/**
 * Determine if a UUID is valid.
 *
 * @param[in]       uuid        UUID in question
 */
GAME_MGA_Export
bool valid_uuid (const std::string & uuid);

/**
 * Helper method to create a new UUID. The genereate UUID is
 * spec-compliant.
 *
 * @return          Newly generated UUID.
 */
GAME_MGA_Export
std::string create_uuid (void);

/**
 * normalize
 */
GAME_MGA_Export
std::string & normalize (std::string & text);

}
}

#endif // UTILS_UTILS_H
