// $Id: Utils.h 598 2006-01-10 03:02:28Z hillj $

#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

#include <windows.h>
#include <shlobj.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <memory>
#include <cctype>
#include "Utils_export.h"

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
Utils_Export
bool getPath (const std::string & prompt, std::string & path);

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
Utils_Export
bool getPath (const std::string & prompt,
              std::string & path,
              const std::string & initdir);

/**
 * Create a path on disk. If the path does not exist, then all
 * parent directories that do not exist will be created as well.
 *
 * @param[in]       path        Target path to create.
 * @param[in]       seperator   The seperator for directories.
 */
Utils_Export
bool CreatePath (const std::string & path, char separator = '\\');

/**
 * Determine if a UUID is valid.
 *
 * @param[in]       uuid        UUID in question
 */
Utils_Export
bool ValidUuid (const std::string & uuid);

/**
 * Helper method to create a new UUID. The genereate UUID is
 * spec-compliant.
 *
 * @return          Newly generated UUID.
 */
Utils_Export
std::string CreateUuid (void);
}

#endif // UTILS_UTILS_H
