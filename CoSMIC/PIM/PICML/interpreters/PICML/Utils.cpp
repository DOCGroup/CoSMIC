// $Id$

#include "Utils.h"

namespace PICML
{

  // This method prompts a dialog to allow the user to specify a folder
  PICML_Export bool getPath (const std::string& description, std::string& path)
  {
    // Initalize the com library
    HRESULT hr = ::CoInitialize(NULL);
    if (FAILED(hr))
      return false;

    // Dialog instruction
    char display_buffer[MAX_PATH];
    BROWSEINFO folder_browsinfo;
    memset (&folder_browsinfo, 0, sizeof (folder_browsinfo));

    // Set GME as the owner of the dialog
    folder_browsinfo.hwndOwner = GetForegroundWindow();
    // Start the browse from desktop
    folder_browsinfo.pidlRoot = NULL;
    // Pointer to the folder name display buffer
    folder_browsinfo.pszDisplayName = &display_buffer[0];
    // Dialog instruction string
    folder_browsinfo.lpszTitle = description.c_str();
    // Use new GUI style and allow edit plus file view
    folder_browsinfo.ulFlags = BIF_RETURNONLYFSDIRS|BIF_USENEWUI;
    // No callback function
    folder_browsinfo.lpfn = NULL;
    // No parameter passing into the dialog
    folder_browsinfo.lParam = 0;

    LPITEMIDLIST folder_pidl = SHBrowseForFolder(&folder_browsinfo);

    if(folder_pidl == NULL)
      return false;
    else
      {
        TCHAR FolderNameBuffer[MAX_PATH];

        // Convert the selection into a path
        if (SHGetPathFromIDList (folder_pidl, FolderNameBuffer))
          path = FolderNameBuffer;

        // Free the ItemIDList object returned from the call to
        // SHBrowseForFolder using Gawp utility function
        IMalloc * imalloc = 0;
        if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
          {
            imalloc->Free ( folder_pidl );
            imalloc->Release ( );
          }
      }
    ::CoUninitialize();
    return true;
  }

} // namespace PICML
