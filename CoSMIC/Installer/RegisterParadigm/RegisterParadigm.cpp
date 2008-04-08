// $Id$
// RegisterParadigm.cpp : Defines the entry point for the DLL application.
//

#include <windows.h>
#include <msiquery.h>
#include <objbase.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "mgautil.h"

#define PARADIGMCOST 30000

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call,
                      LPVOID lpReserved)
{
  return TRUE;
}


const TCHAR* LastError()
{
  static TCHAR lpMsgBuf[65536];
  FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, ::GetLastError(),
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                lpMsgBuf, sizeof(lpMsgBuf), NULL);
  return lpMsgBuf;
}


void InitProgressBar(MSIHANDLE hInstall, int nSteps, int nStepSize,
                     const char* szActionName,
                     const char* szDescription,
                     const char* szTemplate)
{
  MSIHANDLE nTotalCost = nSteps * nStepSize;
  PMSIHANDLE hRec = MsiCreateRecord(3);

  MsiRecordSetString(hRec, 1, szActionName);	// action name
  MsiRecordSetString(hRec, 2, szDescription);	// description
  MsiRecordSetString(hRec, 3, szTemplate);	// template for ACTIONDATA
  int nResult = MsiProcessMessage(hInstall,
                                  INSTALLMESSAGE_ACTIONSTART,
                                  hRec);

  MsiRecordSetInteger(hRec, 1, 0);	    // reset PB, set the total ticks
  MsiRecordSetInteger(hRec, 2, nTotalCost); // est. total ticks
  MsiRecordSetInteger(hRec, 3, 0);          // forward direction
  nResult = MsiProcessMessage(hInstall,
                              INSTALLMESSAGE_PROGRESS,
                              hRec);

  MsiRecordSetInteger(hRec, 1, 1);         // progress setup info
  MsiRecordSetInteger(hRec, 2, nStepSize); // step size
  MsiRecordSetInteger(hRec, 3, 1);         // increment by the prev parameter
  nResult = MsiProcessMessage(hInstall,
                              INSTALLMESSAGE_PROGRESS,
                              hRec);
}


void SendMsgToProgressBar(MSIHANDLE hInstall,
                          const char* szMessage)
{
  MSIHANDLE hProgressRec = MsiCreateRecord(3);
  MSIHANDLE hRec = MsiCreateRecord(1);

  MsiRecordSetInteger(hProgressRec, 1, 2);	// increment the PB
  MsiRecordSetInteger(hProgressRec, 2, 1);	// ignored
  MsiRecordSetInteger(hProgressRec, 3, 0);	// unused

  MsiRecordSetString(hRec, 1, szMessage); // set the progress bar message

  int nResult = MsiProcessMessage(hInstall,
                                  INSTALLMESSAGE_ACTIONDATA,
                                  hRec);
  nResult = MsiProcessMessage(hInstall,
                              INSTALLMESSAGE_PROGRESS,
                              hProgressRec);
}


void SendErrorMsg(MSIHANDLE hInstall, const char* svErrorMessage, int nFatal)
{
  int hRec = MsiCreateRecord(1);
  MsiRecordSetString(hRec, 0, "Error occured: [1]");
  MsiRecordSetString(hRec, 1, svErrorMessage);
  MsiProcessMessage(hInstall,
                    INSTALLMESSAGE_ERROR,
                    hRec);
}

char* GetRegistryValue (HKEY key, const char* keyName, const char* name)
{
  HKEY hKeyLocal;

  // Open the registry key key
  if (RegOpenKeyEx (key, keyName, 0, KEY_READ, &hKeyLocal) != ERROR_SUCCESS)
    return 0;

  // Get the maximum length of a value inside this key
  unsigned long len;
  if (RegQueryInfoKey (hKeyLocal, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                       NULL, &len, NULL, NULL) != ERROR_SUCCESS)
    return 0;
  len++;
  unsigned char* buf = new unsigned char[len];

  // Query the registry value of name
  if (RegQueryValueEx(hKeyLocal, name, NULL, NULL, buf, &len) != ERROR_SUCCESS)
    return 0;

  if (RegCloseKey (hKeyLocal) != ERROR_SUCCESS)
    return 0;

  return (char*)buf;
}

std::vector <std::string> create_paradigms_vector ()
{
  /* Add any new DSML paradigm names here. 
     You should not need to modify any other
	 parts of this source file.
  */

  std::vector <std::string> paradigms;
  paradigms.push_back ("PICML");
  paradigms.push_back ("CQML");
  paradigms.push_back ("POSAML");

  return paradigms;
}

std::vector <std::string>
filter_unregistered_paradigms (const std::vector <std::string> &paradigms)
{
  // Only leave those paradigms in the vector that are installed.
  // E.g., If PICML is installed then 
  // "HKEY_LOCAL_MACHINE\\SOFTWARE\\ISIS\\CoSMIC\\PICMLParadigm"
  // will be set.
  std::vector <std::string> temp;
  for (std::vector <std::string>::const_iterator iter (paradigms.begin());
	   iter != paradigms.end ();
	   ++iter)
  {
	  std::ostringstream ostr;
	  ostr << *iter << "Paradigm";
	  char* value = GetRegistryValue (HKEY_LOCAL_MACHINE,
		                              "SOFTWARE\\ISIS\\CoSMIC",
									  ostr.str().c_str());
      if (value != 0)
	  {   
		  // It the registry entry is found then select the 
		  // paradigm for registration.
		  temp.push_back (*iter);
	  }
  }
  return temp;
}

bool RegisterParadigm (const std::string& paradigm)
{
  //Initialize the OLE libraries
  HRESULT hr = ::CoInitialize(NULL);
  if (FAILED(hr))
    return false;

  CLSID clsid;

  hr = ::CLSIDFromProgID(OLESTR("Mga.MgaRegistrar"), &clsid);
  if (FAILED(hr))
    return false;

  IMgaRegistrar *reg;
  hr = ::CoCreateInstance(clsid, NULL, CLSCTX_ALL, __uuidof(IMgaRegistrar),
                          reinterpret_cast<void**>(&reg));
  if (FAILED(hr))
    return false;

  UINT cp = GetACP ();
  int len = ::MultiByteToWideChar (cp, 0, paradigm.c_str(), -1, 0, 0);
  wchar_t *wstr = new wchar_t[len];
  ::MultiByteToWideChar (cp, 0, paradigm.c_str(), -1, wstr, len);
  BSTR connstr = ::SysAllocString(wstr);
  BSTR parname = NULL;

  hr = reg->RegisterParadigmFromData(connstr, &parname,
                                     REGACCESS_SYSTEM);
  if (FAILED(hr))
    return false;

  ::SysFreeString(connstr);
  ::SysFreeString(parname);

  reg->Release();

  ::CoUninitialize();
  return true;
}



UINT __stdcall RegisterParadigms(MSIHANDLE hInstall)
{
  // installable paradigm number
  int nParadigmNum = 1;

  // Initialize progress bar
  InitProgressBar(hInstall, nParadigmNum, PARADIGMCOST,
                  "Paradigm Install",
                  "Registering Paradigms into GME.", "Registering [1]");
  char* value = GetRegistryValue (HKEY_LOCAL_MACHINE,
                                  "SOFTWARE\\ISIS\\CoSMIC",
                                  "TargetDir");

  if (value == 0)
    {
      SendErrorMsg (hInstall, "Unable to access Registry Key "
                    "HKEY_LOCAL_MACHINE\\SOFTWARE\\ISIS\\CoSMIC\\TargetDir", 1);
	  MsiSetProperty (hInstall, "TARGETDIRACCEPTED", "0");
      return ERROR_INSTALL_FAILURE;
    }

  MsiSetProperty (hInstall, "TARGETDIRACCEPTED", "1");

  std::vector<std::string> paradigms 
	  = filter_unregistered_paradigms (create_paradigms_vector());

  std::string paradigm_ext (".xmp");

  for (std::vector<std::string>::const_iterator iter = paradigms.begin();
       iter != paradigms.end();
       ++iter)
    {
      // Register the PICML paradigm
      std::string svParadigmName = *iter;
      SendMsgToProgressBar(hInstall, svParadigmName.c_str());
      std::string targetParadigm ("XML=");
      targetParadigm += std::string(value) + "paradigms\\" 
		             + svParadigmName + "\\" + svParadigmName + paradigm_ext;
      if (!RegisterParadigm (targetParadigm))
      {
        std::string errorMsg ("Unable to register Paradigm " + targetParadigm);
        errorMsg += ". Please check if you have a valid GME installation. \n";
        errorMsg += LastError();
        SendErrorMsg (hInstall, errorMsg.c_str(), 1);
        return ERROR_INSTALL_FAILURE;
      }
    }
  // Don't change this return value or BAD THINGS[TM] will happen.
  return ERROR_SUCCESS;
}

bool UnRegisterParadigm (const std::string& paradigmName)
{
  //Initialize the OLE libraries
  HRESULT hr = ::CoInitialize(NULL);
  if (FAILED(hr))
    return false;

  CLSID clsid;

  hr = ::CLSIDFromProgID(OLESTR("Mga.MgaRegistrar"), &clsid);
  if (FAILED(hr))
    return false;

  IMgaRegistrar *reg;
  hr = ::CoCreateInstance(clsid, NULL, CLSCTX_ALL, __uuidof(IMgaRegistrar),
                          reinterpret_cast<void**>(&reg));
  if (FAILED(hr))
    return false;

  UINT cp = GetACP ();
  int len = ::MultiByteToWideChar (cp, 0, paradigmName.c_str(), -1, 0, 0);
  wchar_t *wstr = new wchar_t[len];
  ::MultiByteToWideChar (cp, 0, paradigmName.c_str(), -1, wstr, len);
  BSTR name = ::SysAllocString(wstr);

  hr = reg->UnregisterParadigm(name, REGACCESS_BOTH);

  if (FAILED(hr))
    return false;

  ::SysFreeString(name);

  reg->Release();

  ::CoUninitialize();

  return true;
}

UINT __stdcall UnRegisterParadigms (MSIHANDLE hInstall)
{
  // installable paradigm number
  int nParadigmNum = 1;

  // Initialize progress bar
  InitProgressBar(hInstall, nParadigmNum, PARADIGMCOST,
                  "Paradigm Uninstall",
                  "UnRegistering Paradigms from GME.", "UnRegistering [1]");

  std::vector<std::string> paradigms 
	  = filter_unregistered_paradigms (create_paradigms_vector());

  for (std::vector<std::string>::const_iterator iter = paradigms.begin();
       iter != paradigms.end();
       ++iter)
    {
      // UnRegister the PICML paradigm
      std::string svParadigmName = *iter;
      SendMsgToProgressBar(hInstall, svParadigmName.c_str());
      if (!UnRegisterParadigm (svParadigmName))
        {
          std::string errorMsg ("Unable to unregister Paradigm " +
                                svParadigmName);
          errorMsg += LastError();
          SendErrorMsg (hInstall, errorMsg.c_str(), 1);
          return ERROR_INSTALL_FAILURE;
        }
    }
  // Don't change this return value or BAD THINGS[TM] will happen.
  return ERROR_SUCCESS;
}

UINT check_GME_version (std::string const & version)
{
	const char * const GME_ROOT = getenv("GME_ROOT");
	std::string path = GME_ROOT;
	path += "\\Interfaces\\GMEVersion.h";

	std::ifstream infile(path.c_str());
	if (infile)
	{
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
		std::ostringstream ostr;
		ostr << major << "." << minor << "." << plevel;
		if (ostr.str() == version)
			return ERROR_SUCCESS;
		else
			return ERROR_INSTALL_FAILURE;
	}
	else
	{
		return ERROR_INSTALL_FAILURE;
	}
}


UINT __stdcall CheckGMEVersion_6_11_9 (MSIHANDLE hInstall)
{
	if (check_GME_version ("6.11.9") == ERROR_INSTALL_FAILURE)
	{
		MessageBox(NULL, 
			       TEXT("GME version 6.11.9 is not installed or could not determine "
			       "its version. Please check %GME_ROOT%\\Interfaces\\GMEVersion.h"),
				   TEXT("CoSMIC Installer Error"), 
				   MB_OK);
		return ERROR_INSTALL_FAILURE;
	}
	else
		return ERROR_SUCCESS;
}

UINT __stdcall CheckGMEVersion_7_6_29 (MSIHANDLE hInstall)
{
	if (check_GME_version ("7.6.29") == ERROR_INSTALL_FAILURE)
	{
		MessageBox(NULL, 
			       TEXT("GME version 7.6.29 is not installed or could not determine "
			       "its version. Please check %GME_ROOT%\\Interfaces\\GMEVersion.h"),
				   TEXT("CoSMIC Installer Error"), 
				   MB_OK);
		return ERROR_INSTALL_FAILURE;
	}
	else
		return ERROR_SUCCESS;
}

