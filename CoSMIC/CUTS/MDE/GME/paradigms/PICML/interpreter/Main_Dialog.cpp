// $Id$

#include "StdAfx.h"
#include "Resource.h"
#include "Main_Dialog.h"
#include "Utils/Utils.h"

#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Manager_Factory_Repo.h"
#include "cuts/be/BE_Manager_Factory.h"

BEGIN_MESSAGE_MAP (Main_Dialog, CDialog)
  ON_LBN_SELCHANGE (IDC_BE_LIST, On_BE_List_SelChange)
END_MESSAGE_MAP ()

//
// Main_Dialog
//
Main_Dialog::Main_Dialog (CUTS_BE_Options * options,
                          const CUTS_BE_Manager_Factory_Repo & factory_repo,
                          CWnd * parent)
: CDialog (IDD_MAINDIALOG, parent),
  options_ (options),
  factory_repo_ (factory_repo),
  manager_factory_ (0)
{

}

//
// ~Main_Dialog
//
Main_Dialog::~Main_Dialog (void)
{

}

//
// OnInitDialog
//
BOOL Main_Dialog::OnInitDialog (void)
{
  // Let the base class perform its initialization.
  CDialog::OnInitDialog ();

  // Initialize the backend list box with the loaded factories.
  int index = 0;
  CUTS_BE_Manager_Factory * factory = 0;

  for (CUTS_BE_Manager_Factory_Set::
        const_iterator iter = this->factory_repo_.factories ().begin ();
       iter != this->factory_repo_.factories ().end ();
       iter ++)
  {
    factory = iter->second;

    if (factory != 0)
    {
      // Insert the name of the manager into the listbox.
      index = this->be_list_.AddString (factory->name ());

      if (index != LB_ERR)
      {
        // Set the listbox's data equal to the factory's address.
        this->be_list_.SetItemData (index, (DWORD_PTR) factory);
      }
      else
      {
        CString message ("Failed to load ");
        message.Append (factory->name ());

        ::AfxMessageBox (message, MB_OK);
      }
    }
  }

  return TRUE;
}

//
// DoDataExchange
//
void Main_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // Let the base class handle its business first.
  CDialog::DoDataExchange (pDX);

  // Exchange all data in the dialog with the necesary controls.
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
    }

    // Save the output directory in the cache.
    CUTS_BE_OPTIONS ()->output_directory_ = outdir;
  }

  // We need to exchange data with the list box control. If we are
  // actually saving data from the control and the user has selected
  // to generate source, we need to save the manager factory.
  DDX_Control (pDX, IDC_BE_LIST, this->be_list_);

  if (CUTS_BE_OPTIONS ()->option_ == CUTS_BE_Options::OPT_GENERATE_SOURCE &&
      pDX->m_bSaveAndValidate)
  {
    int index = this->be_list_.GetCurSel ();

    if (index != LB_ERR)
    {
      this->manager_factory_ =
        (CUTS_BE_Manager_Factory *) this->be_list_.GetItemData (index);
    }
    else
    {
      ::AfxMessageBox ("Please select a backend for generating implementation",
                       MB_OK | MB_ICONEXCLAMATION);

      this->GetDlgItem (IDC_BE_LIST)->SetFocus ();
      pDX->Fail ();
    }
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

    this->GetDlgItem (IDC_BE_LIST)->EnableWindow ();
    this->GetDlgItem (IDC_BE_DESCRIPTION)->EnableWindow ();
    break;

  case IDC_OPERATION:
    // Disable the following controls.
    this->GetDlgItem (IDC_OUTPUTDIR)->EnableWindow (FALSE);
    this->GetDlgItem (IDC_BROWSE)->EnableWindow (FALSE);

    this->GetDlgItem (IDC_BE_LIST)->EnableWindow (FALSE);
    this->GetDlgItem (IDC_BE_DESCRIPTION)->EnableWindow (FALSE);
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

//
// manager_factory
//
CUTS_BE_Manager_Factory * Main_Dialog::manager_factory (void) const
{
  return this->manager_factory_;
}

//
// On_BE_List_SelChange
//
void Main_Dialog::On_BE_List_SelChange (void)
{
  // Get the current selection.
  int index = this->be_list_.GetCurSel ();

  if (index != LB_ERR)
  {
    // Get the data for the select item. The data is actually the
    // factory object we initially stored with the item.
    CUTS_BE_Manager_Factory * factory =
      (CUTS_BE_Manager_Factory *) this->be_list_.GetItemData (index);

    if (factory != 0)
    {
      // Update the description for the select item.
      this->SetDlgItemText (IDC_BE_DESCRIPTION,
                            factory->description ());
    }
    else
    {
      ::AfxMessageBox ("Selected item not properly initialized",
                       MB_OK | MB_ICONERROR);
    }
  }
}
