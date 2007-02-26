#include "stdafx.h"
#include "File.h"

namespace CFILE {

const std::string CFile::include_contents_ = "#include <stdio.h> \n \n";
const std::string CFile::aspect_key_ = " aspect ";
const std::string CFile::left_brace_ = " { \n";
const std::string CFile::right_brace_ = "\n } \n ";
const std::string CFile::semi_colon_ ="; \n ";

CFile::CFile()
{
}

CFile::CFile(std::string file_name)
: file_name_(file_name)
{
}

CFile::~CFile()
{
  if(this->aspect_file_.is_open())
    this->close_file();
}

void CFile::add_include()
{
  this->add_content(include_contents_);
}

void CFile::add_aspect_key_name(std::string aspect_name)
{
  this->add_content(this->aspect_key_);
  this->add_content(aspect_name);
}

void CFile::add_left_brace()
{
  this->add_content(this->left_brace_);
}

void CFile::add_right_brace()
{
  this->add_content(this->right_brace_);
}

void CFile::set_file_name(std::string file_name)
{
  this->file_name_ = file_name;
}

void CFile::close_file()
{
  if (this->aspect_file_.is_open())
  {
    this->put_in_file();
    this->aspect_file_.close();
  }
}


BOOL CFile::open_file()
{
  this->aspect_file_.open (file_name_.c_str ());
  return this->aspect_file_.is_open();
}

void CFile::add_content(const std::string data)
{
  //this->file_data_.append("\n");
  this->file_data_.append(data);
}

void CFile::put_in_file()
{
  AfxMessageBox(this->file_data_.c_str());
  this->aspect_file_ << this->file_data_.c_str();
}

// This method prompts a dialog to allow the user to specify a folder
BOOL CFile::set_path (const std::string& description)
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
          this->output_path_ = FolderNameBuffer;

        // Free the ItemIDList object returned from the call to
        // SHBrowseForFolder using Gawp utility function
        IMalloc * imalloc = 0;
        if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
          {
            imalloc->Free ( folder_pidl );
            imalloc->Release ( );
          }
      }
      this->save_file();
    ::CoUninitialize();
    return true;
  }

BOOL
CFile::save_file ()
{
	OPENFILENAME ofn;

	char szFile[MAX_PATH];
	strcpy(szFile, this->file_name_.c_str());

	// Initialize the OPENFILENAME structure
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = 0;
    ofn.lpstrFile = szFile;
	ofn.lpstrTitle = "Save - Feature Options";

	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "All\0*.*\0"; // "All\0*.*\0Text\0*.txt\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.Flags = OFN_PATHMUSTEXIST;

	// GetSaveFileName() system call shows up the save file dialog
	BOOL result;
	if (result = GetSaveFileName(&ofn))
		file_name_ = szFile;
	
	return result;
}
}