#include "StdAfx.h"
#include "DeploymentPlan_MainDialog.h"
#include "Configuration.h"
#include "Resource.h"
#include <string>
#include <io.h>

#include "game/mga/Utils.h"

//
// DDX_Text
//
static int DDX_Text (CDataExchange * pDX, int id, std::string & str)
{
  CString text;

  if (pDX->m_bSaveAndValidate)
  {
    pDX->m_pDlgWnd->GetDlgItemTextA (id, text);
    str = text.GetBuffer ();
  }
  else
  {
    pDX->m_pDlgWnd->SetDlgItemTextA (id, str.c_str ());
  }

  return 0;
}

//
// DDX_Check
//
static int DDX_Check (CDataExchange * pDX, int id, bool & value)
{
  if (pDX->m_bSaveAndValidate)
    value = pDX->m_pDlgWnd->IsDlgButtonChecked (id) == BST_UNCHECKED ? false : true;
  else
    pDX->m_pDlgWnd->CheckDlgButton (id, value ? BST_CHECKED : BST_UNCHECKED);

  return 0;
}

//
// DDV_NonEmptyString
//
static int DDV_NonEmptyString (CDataExchange * pDX, const std::string & str)
{
  // No need to continue if we aren't saving anything.
  if (!pDX->m_bSaveAndValidate)
    return -1;

  // Remove all the leading and trailing whitespace.
  if (!str.empty ())
    return 1;

  // Since we are empty, display an error messages.
  ::AfxMessageBox ("Please enter a non-empty string");
  pDX->Fail ();
  return 0;
}

//
// DDV_DirectoryExists
//
static int DDV_DirectoryExists (CDataExchange * pDX, std::string & str)
{
  // Verify we aren't working with an empty string.
  int retval = DDV_NonEmptyString (pDX, str);

  if (retval == 1)
  {
    // Locate the file descriptor for the string.
    _finddata_t finddata;
    int handle = _findfirst (str.c_str (), &finddata);

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

  DDX_Text (pDX, IDC_OUTPUT_DIR, this->config_.output_);
  DDV_DirectoryExists (pDX, this->config_.output_);

  DDX_Check (pDX, IDC_DISABLE_OPTS, this->config_.disable_optimize_);
  DDX_Check (pDX, IDC_HAS_LOCALITY_MANAGER, this->config_.has_locality_manager_);
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

  if (GAME::Utils::get_path ("Select output directory for deployment plan(s)",
                             outdir,                      
                             std::string (temp)))
  {
    this->SetDlgItemText (IDC_OUTPUT_DIR, outdir.c_str ());
  }
}
