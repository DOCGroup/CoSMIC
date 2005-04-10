// $Id$

#ifndef PICML_UTILS_H
#define PICML_UTILS_H

#include <windows.h>
#include <shlobj.h>
#include <stdlib.h>
#include <string>
#include "PICML_Export.h"

namespace PICML
{

  // This method prompts a dialog to allow the user to specify a folder
  PICML_Export bool getPath (const std::string& description, std::string& path);
} // namespace PICML

#endif // PICML_UTILS_H
