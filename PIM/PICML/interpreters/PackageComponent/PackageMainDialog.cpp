// $Id$

#include "StdAfx.h"
#include "PackageMainDialog.h"
#include "PackageOptions.h"
#include "Resource.h"
#include "Utils/Utils.h"
#include <io.h>

//
// PackageMainDialog
//
static int DDV_NonEmptyString (CDataExchange * pDX, CString & str)
{
  // No need to continue if we aren't saving anything.
  if (!pDX->m_bSaveAndValidate)
    return -1;

  // Remove all the leading and trailing whitespace.
  if (str.Trim ().GetLength () != 0)
    return 1;

  // Since we are empty, display an error messages.
  ::AfxMessageBox ("Please enter a non-empty string");
  pDX->Fail ();
  return 0;
}

//
// DDV_DirExists
//
static int DDV_DirectoryExists (CDataExchange * pDX, CString & str)
{
  // Verify we aren't working with an empty string.
  int retval = DDV_NonEmptyString (pDX, str);

  if (retval == 1)
  {
    // Locate the file descriptor for the string.
    _finddata_t finddata;
    int handle = _findfirst (str.GetBuffer (), &finddata);

    if (handle != -1)
    {
      // Do we have the subdirectory attribute set?? We only care about
      // this attribute. Afterwards, we need to close the descriptor
      // handle.
      retval = ((finddata.attrib & _A_SUBDIR) == 0) ? 0 : 1;
      _findclose (handle);
    }
    else
      retval = 0;
  }

  // Determine if the specified directory is indeed a valid directory. If
  // it is not, then we need to notify the user so that can correct the
  // situation at hand.

  if (retval == 0)
  {
    ::AfxMessageBox ("Please enter a valid directory, not including trailing slash");
    pDX->Fail ();
  }

  return retval;
}

// Message map for the PackageMainDialog
BEGIN_MESSAGE_MAP (PackageMainDialog, CDialog)
  ON_BN_CLICKED (IDC_GENERATE_DESCRIPTORS, OnClick_GenerateDescriptors)
  ON_BN_CLICKED (IDC_GENERATE_PACKAGES, OnClick_GeneratePackages)

  ON_BN_CLICKED (IDC_BROWSE_DESCRIPTOR, OnClick_BrowseDescriptor)
  ON_BN_CLICKED (IDC_BROWSE_IMPL, OnClick_BrowseImplementation)
  ON_BN_CLICKED (IDC_BROWSE_PACKAGE, OnClick_BrowsePackage)
END_MESSAGE_MAP ()

//
// PackageMainDialog
//
PackageMainDialog::
PackageMainDialog (PackageOptions & opts, CWnd * parent)
: CDialog (IDD_MAINDIALOG, parent),
  opts_ (opts)
{

}

//
// PackageMainDialog
//
PackageMainDialog::~PackageMainDialog (void)
{

}

BOOL PackageMainDialog::OnInitDialog (void)
{
  CDialog::OnInitDialog ();

  // Initialize the descriptor controls.
  this->GetDlgItem (IDC_DESCRIPTOR_DIR)->
    EnableWindow (this->opts_.generate_descriptors_);
  this->GetDlgItem (IDC_BROWSE_DESCRIPTOR)->
    EnableWindow (this->opts_.generate_descriptors_);

  // Initialize the packaging controls
  this->GetDlgItem (IDC_IMPLEMENTATION_DIR)->
    EnableWindow (this->opts_.generate_packages_);
  this->GetDlgItem (IDC_BROWSE_IMPL)->
    EnableWindow (this->opts_.generate_packages_);

  this->GetDlgItem (IDC_PACKAGE_DIR)->
    EnableWindow (this->opts_.generate_packages_);
  this->GetDlgItem (IDC_BROWSE_PACKAGE)->
    EnableWindow (this->opts_.generate_packages_);

  return TRUE;
}

//
// DoDataExchange
//
void PackageMainDialog::DoDataExchange (CDataExchange * pDX)
{
  CDialog::DoDataExchange (pDX);

  // Perform data exchaging with the controls related to
  // generating descriptors in the dialog box.
  int state;
  CString descriptor_outdir;

  if (!pDX->m_bSaveAndValidate)
  {
    // Since we are not in save mode, we are putting data into the dialog
    // box. So, we need to update the exchange variables with the correct
    // data we want to display in the dialog box (i.e, the current opts_
    // values).
    state = this->opts_.generate_descriptors_ ? 1 : 0;
    descriptor_outdir = this->opts_.descriptor_directory_.c_str ();
  }

  DDX_Check (pDX, IDC_GENERATE_DESCRIPTORS, state);
  DDX_Text (pDX, IDC_DESCRIPTOR_DIR, descriptor_outdir);

  if (pDX->m_bSaveAndValidate)
  {
    // Determine if we are, or are not, generating descriptor files.
    this->opts_.generate_descriptors_ = state == 0 ? false : true;

    if (this->opts_.generate_descriptors_)
    {
      if (DDV_DirectoryExists (pDX, descriptor_outdir) == 1)
        this->opts_.descriptor_directory_ = descriptor_outdir.GetBuffer ();
    }
  }

  // Perform data exchaging with the controls related to generating
  // packages in the dialog box.
  CString impl_outdir, package_outdir;

  if (!pDX->m_bSaveAndValidate)
  {
    // Since we are not in save mode, we are putting data into the dialog
    // box. So, we need to update the exchange variables with the correct
    // data we want to display in the dialog box (i.e, the current opts_
    // values).
    state = this->opts_.generate_packages_ ? 1 : 0;
    package_outdir = this->opts_.package_directory_.c_str ();
    impl_outdir = this->opts_.implementation_directory_.c_str ();
  }

  DDX_Check (pDX, IDC_GENERATE_PACKAGES, state);

  if (pDX->m_bSaveAndValidate)
    // Determine if we are, or are not, generating component packages.
    this->opts_.generate_packages_ = state == 0 ? false : true;

  // Perform data exchange and validation with the implementation input
  // directory.
  DDX_Text (pDX, IDC_IMPLEMENTATION_DIR, impl_outdir);

  if (this->opts_.generate_packages_)
  {
    if (DDV_DirectoryExists (pDX, impl_outdir) == 1)
      this->opts_.implementation_directory_ = impl_outdir.GetBuffer ();
  }

  // Perform data exchange and validation with the package output
  // directory.
  DDX_Text (pDX, IDC_PACKAGE_DIR, package_outdir);

  if (this->opts_.generate_packages_)
  {
    if (DDV_DirectoryExists (pDX, package_outdir) == 1)
      this->opts_.package_directory_ = package_outdir.GetBuffer ();
  }

  // Bind the checkboxes to controls.
  DDX_Control (pDX,
               IDC_GENERATE_DESCRIPTORS,
               this->generate_descriptors_button_);

  DDX_Control (pDX,
               IDC_GENERATE_PACKAGES,
               this->generate_packages_button_);
}

//
// OnClick_GenerateDescriptors
//
void PackageMainDialog::OnClick_GenerateDescriptors (void)
{
  int state = this->generate_descriptors_button_.GetCheck ();
  this->GetDlgItem (IDC_BROWSE_DESCRIPTOR)->EnableWindow (state);
  this->GetDlgItem (IDC_DESCRIPTOR_DIR)->EnableWindow (state);
}

//
// OnClick_GeneratePackages
//
void PackageMainDialog::OnClick_GeneratePackages (void)
{
  int state = this->generate_packages_button_.GetCheck ();

  this->GetDlgItem (IDC_BROWSE_IMPL)->EnableWindow (state);
  this->GetDlgItem (IDC_BROWSE_PACKAGE)->EnableWindow (state);

  this->GetDlgItem (IDC_IMPLEMENTATION_DIR)->EnableWindow (state);
  this->GetDlgItem (IDC_PACKAGE_DIR)->EnableWindow (state);
}

//
// OnClick_BrowseDescriptor
//
void PackageMainDialog::OnClick_BrowseDescriptor (void)
{
  this->BrowseForFolder ("Select output directory for descriptor files",
                         IDC_DESCRIPTOR_DIR);
}

//
// OnClick_BrowseImplementation
//
void PackageMainDialog::OnClick_BrowseImplementation (void)
{
  this->BrowseForFolder ("Select input directory for implementation files",
                         IDC_IMPLEMENTATION_DIR);
}

//
// OnClick_BrowsePackage
//
void PackageMainDialog::OnClick_BrowsePackage (void)
{
  this->BrowseForFolder ("Select output directory for package files",
                         IDC_PACKAGE_DIR);
}

//
// BrowseForFolder
//
void PackageMainDialog::
BrowseForFolder (const char * prompt, UINT ctrl_id)
{
  // Get the current output directory from the edit control.
  CString temp;
  this->GetDlgItemText (ctrl_id, temp);

  // Allow the client to select a new directory. If the client
  // select OK, then we are going to save the directory in the
  // dialog.
  std::string outdir;

  if (Utils::getPath (prompt, outdir, temp.GetBuffer ()))
    this->SetDlgItemText (ctrl_id, outdir.c_str ());
}

//
// OnCancel
//
void PackageMainDialog::OnCancel (void)
{
  this->opts_.generate_descriptors_ = false;
  this->opts_.generate_packages_ = false;

  CDialog::OnCancel ();
}
