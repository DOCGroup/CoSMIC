// $Id$

#include "StdAfx.h"
#include "Dialogs.h"
#include "resource.h"

//
// DDV_ValidChars
//
static void DDV_ValidChars (CDataExchange * pDX,
                            const ACE_CString & str,
                            const char * invalid_chars)
{
  int pos;

  for (; '\0' != *invalid_chars; ++ invalid_chars)
  {
    // Check for the current character in the string.
    pos = str.find (*invalid_chars);

    if (pos != ACE_CString::npos)
    {
      // Prepare the error message.
      ACE_CString message ("String cannot contain ");
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
static void DDX_Text (CDataExchange * pDX, int id, ACE_CString & str)
{
  // Get the dialog with the specified id.
  CWnd * item = pDX->m_pDlgWnd->GetDlgItem (id);

  if (pDX->m_bSaveAndValidate)
  {
    // Get the size of the text in the window.
    int length = item->GetWindowTextLength () + 1;

    // Allocate a buffer for the text.
    char * buffer = 0;
    ACE_NEW (buffer, char [length]);

    if (0 == buffer)
      pDX->Fail ();

    // Get the text from the window.
    ACE_Auto_Ptr <char> auto_clean (buffer);
    item->GetWindowText (buffer, length);

    // Store the window's text in the string.
    str.set (buffer);
    auto_clean.release ();
  }
  else
  {
    item->SetWindowText (str.c_str ());
  }
}

//
// Component_Name_Dialog
//
Component_Name_Dialog::Component_Name_Dialog (CWnd * parent)
: CDialog (IDD_NEWCOMPONENTNAME, parent)
{

}

//
// DoDataExchange
//
void Component_Name_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);

  // Get the name from the dialog.
  DDX_Text (pDX, IDC_NAME, this->name_);

  // Validate the name (i.e., make sure it contains no spaces).
  DDV_ValidChars (pDX, this->name_, " ");
}
