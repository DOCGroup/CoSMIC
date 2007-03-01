// $Id$

#include "Project.h"
#include <atlbase.h>
#include <algorithm>

/// Helper method to verify the success of a COM operation.
#define VERIFY_HRESULT(op) \
  { \
    HRESULT hr = op; \
    if (FAILED (hr)) \
      throw; \
  }

/// Base registry path of the cached output directory.
#define REGISTRY_PATH_OUTDIR      "/__OutDir__/"

namespace Utils
{
  //
  // global_cached_outdir
  //
  std::string Project::global_cached_outdir (IMgaProject * project)
  {
    return Project::cached_outdir (project, "");
  }

  //
  // global_cached_outdir
  //
  void Project::global_cached_outdir (IMgaProject * project,
                                      const std::string & outdir)
  {
    Project::cached_outdir (project, "", outdir);
  }

  //
  // cached_outdir
  //
  void Project::cached_outdir (IMgaProject * proj,
                               const std::string & uuid,
                               const std::string & outdir)
  {
    // Get the root folder for the project.
    CComPtr <IMgaProject> project (proj);
    CComPtr <IMgaFolder> root_folder;
    VERIFY_HRESULT (project->get_RootFolder (&root_folder));

    // Store the output directory inside the model.
    std::string path = REGISTRY_PATH_OUTDIR + uuid;
    std::replace (path.begin (), path.end (), ' ', '_');

    CComBSTR bstrPath (path.size (), path.c_str ());
    CComBSTR bstrOutDir (outdir.size (), outdir.c_str ());

    VERIFY_HRESULT (root_folder->put_RegistryValue (bstrPath, bstrOutDir));
  }

  //
  // cached_outdir
  //
  std::string Project::cached_outdir (IMgaProject * proj,
                                      const std::string & uuid)
  {
    // Get the root folder for the project.
    CComPtr <IMgaProject> project (proj);
    CComPtr <IMgaFolder> root_folder;
    VERIFY_HRESULT (project->get_RootFolder (&root_folder));

    // Get the output directory inside the model.
    CComBSTR bstrOutDir;
    std::string path = REGISTRY_PATH_OUTDIR + uuid;
    std::replace (path.begin (), path.end (), ' ', '_');

    CComBSTR bstrPath (path.size (), path.c_str ());
    VERIFY_HRESULT (root_folder->get_RegistryValue (bstrPath, &bstrOutDir));

    // Convert the wide-string to a C-string.
    CW2A converter (bstrOutDir);
    return converter.m_psz ? converter.m_psz : "";
  }
}
