// $Id: Utils.cpp 607 2006-01-20 20:02:25Z hillj $

#include "ace/UUID.h"
#include "Utils.h"

#include <direct.h>
#include <atlcomcli.h>
#include <commdlg.h>
#include <stack>

namespace Utils
{
//
// BrowseCallbackProc
//
static int CALLBACK
BrowseCallbackProc (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  switch (msg)
  {
  case BFFM_INITIALIZED:
    {
      // Convert the string into a ITEMIDLIST. Then pass the ITEMIDLIST
      // to the browse dialog. This will initialize its selection.
      // Finally, we need to free its allocated memory.
      LPITEMIDLIST ppidl = ::ILCreateFromPath ((LPCTSTR)lparam);

      ::SendMessage (hwnd, BFFM_SETSELECTION, FALSE, (LPARAM)ppidl);
      ::CoTaskMemFree (ppidl);
    }
    break;

  case BFFM_VALIDATEFAILED:
    // We have to return 1 to keep the dialog open.
    return 1;
  }

  return 0;
}

//
// getPath
//
bool getPath (const std::string & prompt, std::string & path)
{
  std::string initdir;
  return getPath (prompt, path, initdir);
}

//
// getPath
//
bool getPath (const std::string & prompt,
              std::string & path,
              const std::string & initdir)
{
  // Initalize the com library
  if (FAILED (::CoInitialize (NULL)))
    return false;

  // Dialog instruction
  char display_buffer[MAX_PATH];
  BROWSEINFO folder_browsinfo;
  ZeroMemory (&folder_browsinfo, sizeof (folder_browsinfo));

  // Initialize the structure.
  folder_browsinfo.hwndOwner = ::GetActiveWindow ();
  folder_browsinfo.pidlRoot = NULL;
  folder_browsinfo.pszDisplayName = &display_buffer[0];
  folder_browsinfo.lpszTitle = prompt.c_str();
  folder_browsinfo.ulFlags   = BIF_RETURNONLYFSDIRS | BIF_USENEWUI;

  // We are going to setup a callback function and pass in the
  // initial directory as a parameter. The callback will use the
  // parameter to initialize the dialog properly.
  folder_browsinfo.lpfn = (BFFCALLBACK)&BrowseCallbackProc;
  folder_browsinfo.lParam = (LPARAM)initdir.c_str ();

  // Show the Browse... folder and save the result.
  LPITEMIDLIST folder_pidl = ::SHBrowseForFolder(&folder_browsinfo);
  bool result = folder_pidl != NULL;

  if (result)
  {
    TCHAR FolderNameBuffer[MAX_PATH];

    // Convert the selection into a path
    if (::SHGetPathFromIDList (folder_pidl, FolderNameBuffer))
      path = FolderNameBuffer;

    // Free the ItemIDList object returned from the call to
    // SHBrowseForFolder using Gawp utility function
    ::CoTaskMemFree (folder_pidl);
  }

  ::CoUninitialize ();
  return result;
}

//
// CreatePath
//
bool CreatePath (const std::string & path, char separator)
{
  int retval;
  size_t index;

  std::stack <size_t> indices;
  std::string tempstr = path;

  do
  {
    // Try to make the directory in <tempstr>. We keep repeating
    // this loop until we reach the deepest subdirectory specified
    // in <tempstr> that actually creates a new directory. Or,
    // until we have reached the top-most level directory.
    retval = _mkdir (tempstr.c_str ());

    if (retval == -1 && errno == ENOENT)
    {
      // Locate the last seperator in the string.
      index = tempstr.rfind (separator);

      // Remove that seperator so that we go up one directory.
      if (index != std::string::npos)
      {
        indices.push (index);
        tempstr[index] = 0;
      }
    }
  } while (retval == -1 && errno == ENOENT && index != std::string::npos);

  // Ok, the path in <tempstr> already exists. So, now we need
  // to create the remaining subdirectories.
  while (!indices.empty ())
  {
    // Restore the next <separator> in <tempstr>.
    tempstr[indices.top ()] = separator;
    indices.pop ();

    // Try to make this directory. We stop on any error.
    if (_mkdir (tempstr.c_str ()) == -1)
      break;
  }

  return indices.empty ();
}

//
// CreateUuid
//
std::string CreateUuid (void)
{
  ACE_Utils::UUID uuid;
  ACE_Utils::UUID_GENERATOR::instance ()->generate_UUID (uuid);

  return std::string (uuid.to_string ()->c_str ());
}

} // namespace PICML
