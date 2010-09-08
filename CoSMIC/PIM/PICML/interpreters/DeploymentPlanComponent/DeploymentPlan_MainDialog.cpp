// $Id$

#include "StdAfx.h"
#include "DeploymentPlan_MainDialog.h"
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
// DDV_DirectoryExists
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

//
// Message map for the Deployment_Plan_Dialog
//
BEGIN_MESSAGE_MAP (Deployment_Plan_Dialog, CDialog)
  ON_BN_CLICKED (IDC_BROWSE, OnClick_Browse)
END_MESSAGE_MAP ()

//
// Deployment_Plan_Dialog
//
Deployment_Plan_Dialog::
Deployment_Plan_Dialog (Configuration & cfg, CWnd * parent)
: CDialog (IDD_MAINDIALOG, parent),
  config_ (cfg)
{

}

//
// Deployment_Plan_Dialog
//
Deployment_Plan_Dialog::~Deployment_Plan_Dialog (void)
{

}

//
// DoDataExchange
//
void Deployment_Plan_Dialog::DoDataExchange (CDataExchange * pDX)
{
  CDialog::DoDataExchange (pDX);

  DDX_Text (pDX, IDC_OUTPUT_DIR, this->config_.output_path_);
  DDV_DirectoryExists (pDX, this->config_.output_path_);

  DDX_Check (pDX, IDC_DISABLE_OPTS, this->config_.disable_optimize_);
}

//
// OnClick_Browse
//
void Deployment_Plan_Dialog::OnClick_Browse (void)
{
  // Get the current output directory from the edit control.
  CString temp;
  this->GetDlgItemText (IDC_OUTPUT_DIR, temp);

  // Allow the client to select a new directory. If the client
  // select OK, then we are going to save the directory in the
  // dialog.
  std::string outdir;

  if (Utils::getPath ("Select output directory for deployment plan(s)",
                      outdir,
                      std::string (temp)))
  {
    this->SetDlgItemText (IDC_OUTPUT_DIR, outdir.c_str ());
  }
}
