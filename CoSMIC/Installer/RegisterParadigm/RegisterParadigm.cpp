// $Id$

#include "StdAfx.h"
#include "RegisterParadigm.h"
#include "MgaUtil.h"
#include "Gme.h"
#include "boost/bind.hpp"
#include <algorithm>
#include <sstream>

#define PARADIGMCOST 30000

//
// DllMain
//
BOOL WINAPI DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  HRESULT hr;

  switch (fdwReason)
  {
  case DLL_PROCESS_ATTACH:
    // Initialize OLE
    hr = ::CoInitialize (0);

    if (FAILED (hr))
      return FALSE;
    break;

  case DLL_PROCESS_DETACH:
    // Uninitialize OLE
    ::CoUninitialize ();
    break;
  }

  return TRUE;
}

//
// InitProgressBar
//
static void InitProgressBar (MSIHANDLE hInstall,
                             int nSteps,
                             int nStepSize,
                             const char* szActionName,
                             const char* szDescription,
                             const char* szTemplate)
{
  MSIHANDLE nTotalCost = nSteps * nStepSize;
  PMSIHANDLE hRec = MsiCreateRecord (3);

  MsiRecordSetString (hRec, 1, szActionName);  // action name
  MsiRecordSetString (hRec, 2, szDescription);  // description
  MsiRecordSetString (hRec, 3, szTemplate);  // template for ACTIONDATA

  int nResult = ::MsiProcessMessage (hInstall,
                                     INSTALLMESSAGE_ACTIONSTART,
                                     hRec);

  MsiRecordSetInteger (hRec, 1, 0);      // reset PB, set the total ticks
  MsiRecordSetInteger (hRec, 2, nTotalCost); // est. total ticks
  MsiRecordSetInteger (hRec, 3, 0);          // forward direction

  nResult = ::MsiProcessMessage (hInstall,
                                 INSTALLMESSAGE_PROGRESS,
                                 hRec);

  MsiRecordSetInteger (hRec, 1, 1);         // progress setup info
  MsiRecordSetInteger (hRec, 2, nStepSize); // step size
  MsiRecordSetInteger (hRec, 3, 1);         // increment by the prev parameter

  nResult = ::MsiProcessMessage (hInstall,
                                 INSTALLMESSAGE_PROGRESS,
                                 hRec);
}

//
// SendMsgToProgressBar
//
static void SendMsgToProgressBar (MSIHANDLE hInstall,
                                  const char* szMessage)
{
  MSIHANDLE hProgressRec = MsiCreateRecord (3);
  MSIHANDLE hRec = MsiCreateRecord (1);

  MsiRecordSetInteger (hProgressRec, 1, 2);  // increment the PB
  MsiRecordSetInteger (hProgressRec, 2, 1);  // ignored
  MsiRecordSetInteger (hProgressRec, 3, 0);  // unused

  MsiRecordSetString (hRec, 1, szMessage); // set the progress bar message

  int nResult = MsiProcessMessage (hInstall,
                                   INSTALLMESSAGE_ACTIONDATA,
                                   hRec);

  nResult = MsiProcessMessage (hInstall,
                               INSTALLMESSAGE_PROGRESS,
                               hProgressRec);
}

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
int get_msi_property (MSIHANDLE install, const char * name, std::string & value)
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
// get_msi_target_path
//
int get_msi_target_path (MSIHANDLE install, const char * name, std::string & value)
{
  TCHAR * buffer = 0;
  DWORD bufsize = 0;

  UINT result = ::MsiGetTargetPath (install, name, TEXT (""), &bufsize);

  if (ERROR_MORE_DATA == result)
  {
    // Allocate a buffer for the property.
    ++ bufsize;
    buffer = new TCHAR[bufsize];

    result = ::MsiGetTargetPath (install, name, buffer, &bufsize);

    // Save the value of the property.
    if (result == ERROR_SUCCESS)
      value = buffer;

    // Delete the buffer.
    delete [] buffer;
  }
  else
  {
    if (result != ERROR_SUCCESS)
    {
      switch (result)
      {
      case ERROR_INVALID_HANDLE:
        SendErrorMsg (install, "Invalid handle.", 1);
        break;

      case ERROR_MORE_DATA:
        SendErrorMsg (install, "Buffer too small.", 1);
        break;

      case ERROR_INVALID_PARAMETER:
        SendErrorMsg (install, "Invalid parameter.", 1);
        break;
      }

      return ERROR_INSTALL_FAILURE;
    }
  }

  return result;
}

//
// last_error
//
static const TCHAR * last_error (void)
{
  static TCHAR lpMsgBuf[65536];

  ::FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM,
                   0,
                   ::GetLastError (),
                   MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                   lpMsgBuf,
                   sizeof (lpMsgBuf),
                   0);

  return lpMsgBuf;
}

//
// get_registry_value
//
static char* get_registry_value (HKEY key, const char * key_name, const char * name)
{
  HKEY hKeyLocal;

  // Open the registry key key
  if (RegOpenKeyEx (key, key_name, 0, KEY_READ, &hKeyLocal) != ERROR_SUCCESS)
    return 0;

  // Get the maximum length of a value inside this key
  unsigned long len;
  if (RegQueryInfoKey (hKeyLocal, 0, 0, 0, 0, 0, 0, 0,
                       0, &len, 0, 0) != ERROR_SUCCESS)
    return 0;
  len++;
  unsigned char* buf = new unsigned char[len];

  // Query the registry value of name
  if (RegQueryValueEx (hKeyLocal, name, 0, 0, buf, &len) != ERROR_SUCCESS)
    return 0;

  if (RegCloseKey (hKeyLocal) != ERROR_SUCCESS)
    return 0;

  return (char*)buf;
}

//
// get_paradigm_list
//
static void get_paradigm_list (std::vector <std::string> & list)
{
  list.push_back ("PICML");
  list.push_back ("CQML");
}

//
// filter_unregistered_paradigms
//
static std::vector <std::string>
filter_unregistered_paradigms (const std::vector <std::string> &paradigms)
{
  // Only leave those paradigms in the vector that are installed.
  // E.g., If PICML is installed then
  // "HKEY_LOCAL_MACHINE\\SOFTWARE\\ISIS\\CoSMIC\\PICMLParadigm"
  // will be set.
  std::vector <std::string> temp;
  for (std::vector <std::string>::const_iterator iter (paradigms.begin ());
     iter != paradigms.end ();
     ++iter)
  {
    std::ostringstream ostr;
    ostr << *iter << "Paradigm";
    char* value = get_registry_value (HKEY_LOCAL_MACHINE,
                                  "SOFTWARE\\ISIS\\CoSMIC",
                    ostr.str ().c_str());
      if (value != 0)
    {
      // It the registry entry is found then select the
      // paradigm for registration.
      temp.push_back (*iter);
    }
  }
  return temp;
}

/**
 * @struct register_paradigm_t
 *
 * Functor for registering a paradigm with GME.
 */
struct register_paradigm_t
{
  register_paradigm_t (MSIHANDLE install, std::string & cosmic_dir)
    : install_ (install),
      cosmic_dir_ (cosmic_dir),
      errors_ (0)
  {

  }

  register_paradigm_t (const register_paradigm_t & copy)
    : install_ (copy.install_),
      cosmic_dir_ (copy.cosmic_dir_),
      errors_ (copy.errors_)
  {

  }

  void operator () (const std::string & paradigm)
  {
    SendMsgToProgressBar (this->install_, paradigm.c_str ());

    // Load the registration interface.
    CComBSTR progid ("Mga.MgaRegistrar");

    CComPtr <IMgaRegistrar> reg;
    HRESULT hr = reg.CoCreateInstance (progid);

    if (SUCCEEDED (hr))
    {
      std::string target_paradigm =
        "XML=" + std::string (this->cosmic_dir_) + "paradigms\\" +
        paradigm + "\\" + paradigm + ".xmp";

      // Convert the paradigm to a BSTR
      CComBSTR connstr (target_paradigm.length (), target_paradigm.c_str ());

      // Register the paradigm with GME.
      CComBSTR parname;
      hr = reg->RegisterParadigmFromData (connstr, &parname, REGACCESS_SYSTEM);
    }

    if (FAILED (hr))
    {
      // Show an error message to the end-user.
      std::string message =
        "Unable to register " + paradigm + " paradigm. Please " +
        "verify that you have a valid GME installation. " + last_error ();

      SendErrorMsg (this->install_, message.c_str (), 1);
      MessageBox (0, message.c_str (), "", MB_OK);

      ++ this->errors_;
    }
  }

  const register_paradigm_t & operator = (const register_paradigm_t & rhs)
  {
    this->install_ = rhs.install_;
    this->cosmic_dir_ = rhs.cosmic_dir_;
    this->errors_ = rhs.errors_;

    return *this;
  }

  int errors (void) const
  {
    return this->errors_;
  }

private:
  MSIHANDLE & install_;

  std::string & cosmic_dir_;

  int errors_;
};

//
// RegisterParadigms
//
UINT RegisterParadigms (MSIHANDLE hInstall)
{
  // installable paradigm number
  int nParadigmNum = 1;

  // Initialize progress bar
  InitProgressBar (hInstall,
                   nParadigmNum,
                   PARADIGMCOST,
                  "Paradigm Registration",
                  "Registering paradigms with GME...",
                  "Registering [1]");

  std::string install_dir = get_registry_value (HKEY_LOCAL_MACHINE,
                                                "SOFTWARE\\ISIS\\CoSMIC",
                                                "TargetDir");

  if (!install_dir.empty ())
  {
    MsiSetProperty (hInstall, "TARGETDIRACCEPTED", "1");

    std::vector <std::string> paradigms;
    get_paradigm_list (paradigms);

    register_paradigm_t func (hInstall, install_dir);
    func = std::for_each (paradigms.begin (), paradigms.end (), func);

    return func.errors () == 0 ? ERROR_SUCCESS : ERROR_INSTALL_FAILURE;
  }
  else
  {
    MsiSetProperty (hInstall, "TARGETDIRACCEPTED", "0");
    return ERROR_INSTALL_FAILURE;
  }
}

//
// UnregisterParadigm
//
static bool UnregisterParadigm (const std::string & paradigm)
{
  // Load the registration interface.
  CComBSTR progid ("Mga.MgaRegistrar");

  CComPtr <IMgaRegistrar> reg;
  HRESULT hr = reg.CoCreateInstance (progid);

  // Register the paradigm with GME.
  CComBSTR temp (paradigm.length (), paradigm.c_str ());
  hr = reg->UnregisterParadigm (temp, REGACCESS_BOTH);

  return SUCCEEDED (hr);
}

//
// UnregisterParadigms
//
UINT UnregisterParadigms (MSIHANDLE hInstall)
{
  // installable paradigm number
  int nParadigmNum = 1;

  // Initialize progress bar
  InitProgressBar (hInstall, nParadigmNum, PARADIGMCOST,
                  "Paradigm Uninstall",
                  "Unregistering paradigms from GME", "Unregistering [1]");

  std::vector <std::string> paradigms;
  get_paradigm_list (paradigms);

  filter_unregistered_paradigms (paradigms);

  for (std::vector<std::string>::const_iterator iter = paradigms.begin ();
       iter != paradigms.end ();
       ++iter)
    {
      // UnRegister the PICML paradigm
      std::string svParadigmName = *iter;
      SendMsgToProgressBar (hInstall, svParadigmName.c_str());

      if (!UnregisterParadigm (svParadigmName))
        {
          std::string errorMsg ("Unable to unregister Paradigm " +
                                svParadigmName);
          errorMsg += last_error ();
          SendErrorMsg (hInstall, errorMsg.c_str(), 1);
          return ERROR_INSTALL_FAILURE;
        }
    }
  // Don't change this return value or BAD THINGS[TM] will happen.
  return ERROR_SUCCESS;
}

//
// check_GME_version
//
HRESULT check_GME_version (const std::string & version)
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

  // Prepare the expect version string for GME.
  std::replace (expected_version.begin (),
                expected_version.end (),
                '_',
                '.');

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
