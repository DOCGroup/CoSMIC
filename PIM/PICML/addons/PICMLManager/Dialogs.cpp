#include "StdAfx.h"
#include "Dialogs.h"
#include "resource.h"
#include "Implementation_Configuration.h"
#include "ace/Auto_Ptr.h"

//
// DDV_ValidChars
//
static void DDV_ValidChars (CDataExchange * pDX,
                            const std::string & str,
                            const char * invalid_chars)
{
  int pos;

  for (; '\0' != *invalid_chars; ++ invalid_chars)
  {
    // Check for the current character in the string.
    pos = str.find (*invalid_chars);

    if (pos != std::string::npos)
    {
      // Prepare the error message.
      std::string message ("String cannot contain ");
      message += invalid_chars;
      message += '.';

      // Display the error message.
      ::AfxMessageBox (message.c_str (), MB_OK | MB_ICONERROR);
      pDX->Fail ();
    }
  }

}

//
// DDX_Text
//
static void DDX_Text (CDataExchange * pDX, int id, std::string & str)
{
  // Get the dialog with the specified id.
  CWnd * item = pDX->m_pDlgWnd->GetDlgItem (id);

  if (pDX->m_bSaveAndValidate)
  {
    // Allocate a buffer for the text.
    int length = item->GetWindowTextLength () + 1;
    char * buffer = new char [length];

    if (0 == buffer)
      pDX->Fail ();

    // Get the text from the window.
    ACE_Auto_Array_Ptr <char> auto_clean (buffer);
    item->GetWindowText (buffer, length);

    // Store the window's text in the string.
    str = buffer;
    auto_clean.release ();
  }
  else
  {
    item->SetWindowText (str.c_str ());
  }
}

namespace PICML
{
namespace MI
{

//
// Default_Implementation_Dialog
//
Default_Implementation_Dialog::
Default_Implementation_Dialog (Implementation_Configuration & config, CWnd * parent)
: CDialog (IDD_NEWCOMPONENT, parent),
  config_ (config)
{

}

//
// DoDataExchange
//
void Default_Implementation_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);

  // Get the name from the dialog.
  DDX_Text (pDX, IDC_NAME, this->config_.type_name_);
  DDX_Text (pDX, IDC_EXEC_ARTIFACT_SUFFIX, this->config_.exec_artifact_suffix_);
  DDX_Text (pDX, IDC_SVNT_ARTIFACT_SUFFIX, this->config_.svnt_artifact_suffix_);
  DDX_Check (pDX, IDC_USE_COMPONENT_FILENAME, (int &)this->config_.svnt_artifact_location_based_on_filename_);

  // Validate the name (i.e., make sure it contains no spaces).
  DDV_ValidChars (pDX, this->config_.type_name_, " ");
}

}
}
