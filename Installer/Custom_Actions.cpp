// $Id$

#include <winsock2.h>
#include <windows.h>
#include <msiquery.h>

#include "Custom_Actions.h"
#include <sstream>
#include <fstream>

//
// SendErrorMsg
//
static void SendErrorMsg (MSIHANDLE hInstall,
                          const char* svErrorMessage,
                          int nFatal)
{
  int hRec = MsiCreateRecord (1);

  MsiRecordSetString (hRec, 0, "Error occured: [1]");
  MsiRecordSetString (hRec, 1, svErrorMessage);

  MsiProcessMessage (hInstall,
                     INSTALLMESSAGE_ERROR,
                     hRec);
}

//
// get_msi_property
//
static int get_msi_property (MSIHANDLE install,
                             const char * name, 
                             std::string & value)
{
  TCHAR * buffer = 0;
  DWORD bufsize = 0;

  UINT result = ::MsiGetProperty (install, name, TEXT (""), &bufsize);

  if (ERROR_MORE_DATA == result)
  {
    // Allocate a buffer for the property.
    ++ bufsize;
    buffer = new TCHAR[bufsize];

    result = ::MsiGetProperty (install, name, buffer, &bufsize);

    // Save the value of the property.
    if (result == ERROR_SUCCESS)
      value = buffer;

    // Delete the buffer.
    delete [] buffer;
  }

  return result;
}

//
// check_GME_version
//
static HRESULT check_GME_version (const std::string & version)
{
  // Open the GMEVersion.h header file for reading.
  const std::string GME_ROOT = ::getenv ("GME_ROOT");
  const std::string path = GME_ROOT + "/Interfaces/GMEVersion.h";

  std::ifstream infile (path.c_str());

  if (!infile.is_open ())
    return ERROR_INSTALL_FAILURE;

  // Locate each token for the version number in the header file.
  std::string token;
  int major = 0, minor = 0, plevel = 0;

  while (infile >> token)
  {
    if (token == "GME_VERSION_MAJOR")
      infile >> major;
    else if (token == "GME_VERSION_MINOR")
      infile >> minor;
    else if (token == "GME_VERSION_PLEVEL")
    {
      infile >> plevel;
      break;
    }
  }

  // Construct the version number from the tokens, then compare the
  // expected version number with the installed version number.
  std::ostringstream ostr;
  ostr << major << "." << minor << "." << plevel;

  if (ostr.str() == version)
    return ERROR_SUCCESS;
  else
    return ERROR_INSTALL_FAILURE;
}

//
// CheckGMEVersion
//
UINT CheckGMEVersion (MSIHANDLE hInstall)
{
  // Get the property that contains the GME version.
  std::string expected_version;

  if (get_msi_property (hInstall,
                        "CustomActionData",
                        expected_version) != ERROR_SUCCESS)
  {
    SendErrorMsg (hInstall, "Failed to get expected version number of GME installation.", 1);
    return ERROR_INSTALL_FAILURE;
  }

  // Right now, we check the GME version using the GMEVersion.h header
  // file. Below is the *right* way to check the version by using the
  // GME binary since the header file can be corrupted. Unfortunately,
  // the way below does not work since we can't get the GME.Application
  // to load in automation mode. :-(

  if (check_GME_version (expected_version) == ERROR_SUCCESS)
    return ERROR_SUCCESS;

  //CComBSTR progid ("GME.Application");
  //CComPtr <IUnknown> gme_app;
  //HRESULT hr = gme_app.CoCreateInstance (progid);

  //if (SUCCEEDED (hr))
  //{
  //  // Get the version number of the current GME installation.
  //  CComBSTR installed_version;
  //  gme_app->get_Version (&installed_version);

  //  // Compare the expected version with the installed version.
  //  CComBSTR temp_str (expected_version.length (), expected_version.c_str ());

  //  if (installed_version == temp_str)
  //    return ERROR_SUCCESS;
  //}

  // Format the error message.
  std::ostringstream message;
  message << "GME " << expected_version << " is not installed. Please "
          << "verify that the correct version of GME is installed.";

  // Display error message to user.
  SendErrorMsg (hInstall, message.str ().c_str (), 1);
  return ERROR_INSTALL_FAILURE;
}
