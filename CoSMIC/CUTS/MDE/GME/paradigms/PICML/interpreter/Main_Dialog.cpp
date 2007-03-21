// $Id$

#include "StdAfx.h"
#include "Resource.h"
#include "Main_Dialog.h"
#include "Utils/Utils.h"

//
// Main_Dialog
//
Main_Dialog::Main_Dialog (CUTS_BE_Options * options, CWnd * parent)
: CDialog (IDD_MAINDIALOG, parent),
  options_ (options)
{

}

//
// ~Main_Dialog
//
Main_Dialog::~Main_Dialog (void)
{

}

//
//
//
BOOL Main_Dialog::OnInitDialog (void)
{
  CDialog::OnInitDialog ();

  // @@ Need to vertically align output directory text in
  //    the middle of the text box.
  return TRUE;
}

//
// DoDataExchange
//
void Main_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // Let the base class handle its business first.
  CDialog::DoDataExchange (pDX);

  // Get the selected option(s) from the dialog.
  int option = 0;
  DDX_Radio (pDX, IDC_OPERATION, option);

  CUTS_BE_OPTIONS ()->option_ =
    static_cast <CUTS_BE_Options::Menu_Option> (option);

  // Since we aren't saving the data, we need to initialize
  // <outdir> with the data to store in the control.

  CString outdir;

  if (!pDX->m_bSaveAndValidate)
    outdir = CUTS_BE_OPTIONS ()->output_directory_.c_str ();

  DDX_Text (pDX, IDC_OUTPUTDIR, outdir);

  if (pDX->m_bSaveAndValidate)
  {
    // We need to validate the output directory. The output directory
    // is invalid if it is empty. Eventually, we want to make sure
    // the output directory exists.
    outdir.Trim ();

    if (option == CUTS_BE_Options::OPT_GENERATE_SOURCE &&
        outdir.GetLength () == 0)
    {
      ::AfxMessageBox ("Please select a valid output directory",
                      MB_ICONEXCLAMATION);

      // Set the focus of the control and change to fail state.
      this->GetDlgItem (IDC_OUTPUTDIR)->SetFocus ();
      pDX->Fail ();
      return;
    }

    // Save the output directory in the cache.
    CUTS_BE_OPTIONS ()->output_directory_ = outdir;
  }
}

//
// OnCommand
//
BOOL Main_Dialog::OnCommand (WPARAM wParam, LPARAM lParam)
{
  switch (LOWORD (wParam))
  {
  case IDC_COWORKER_IMPL:
    // Enable the following controls
    this->GetDlgItem (IDC_OUTPUTDIR)->EnableWindow ();
    this->GetDlgItem (IDC_BROWSE)->EnableWindow ();
    break;

  case IDC_OPERATION:
    // Disable the following controls.
    this->GetDlgItem (IDC_OUTPUTDIR)->EnableWindow (FALSE);
    this->GetDlgItem (IDC_BROWSE)->EnableWindow (FALSE);
    break;

  case IDC_BROWSE:
    {
      CString outdir;
      std::string path;

      // Get the current output directory.
      this->GetDlgItemText (IDC_OUTPUTDIR, outdir);

      // Let the user select the new output path and store it back
      // into this dialog if the user clicks <OK>.
      if (Utils::getPath ("Select the output directory:",
                          path,
                          outdir.GetBuffer ()))
      {
        this->SetDlgItemText (IDC_OUTPUTDIR, path.c_str ());
      }
    }
    break;

  default:
    return CDialog::OnCommand (wParam, lParam);
  }

  return TRUE;
}
