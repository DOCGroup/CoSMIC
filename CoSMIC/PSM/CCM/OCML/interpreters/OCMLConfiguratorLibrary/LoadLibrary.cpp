/**
 * $Id$
 */

#include "LoadLibrary.hpp"
#include "assert.h"
#include <algorithm>
#include <cstdlib>
#include <iterator>

#ifdef _DEBUG
#define OCML_CONFIGURATOR_LIBRARY_NAME "OCMLConfiguratord.dll"
#elif
#define OCML_CONFIGURATOR_LIBRARY_NAME "OCMLConfigurator.dll"
#endif

OCML_Configurator_Library::OCML_Configurator_Library()
{
  char *buffer = getenv("PICML_ROOT");
  
  std::string library_path;
  if (buffer)
    {
      // delete double quotes (if there are any)
      std::remove_copy(buffer, buffer + strlen(buffer),
                       std::back_inserter(library_path), '"');
      library_path += "\\bin\\";
    }
  library_path += OCML_CONFIGURATOR_LIBRARY_NAME;
  
  lib_ = LoadLibrary(library_path.c_str());
  assert(lib_);
  
  DLLFunctionPtr pProc =
    (DLLFunctionPtr)GetProcAddress(lib_, "DLLFunction");
  assert(pProc);

  func_ = pProc;
}

OCML_Configurator_Library::~OCML_Configurator_Library()
{
  FreeLibrary(lib_);
}

char* OCML_Configurator_Library::call_function(std::string& values)
{
  return (func_)(values.c_str(), values.size());
}

