// $Id$

#include "stdafx.h"
#include "Template_Engine_Dialog.h"

#if !defined (__GAME_INLINE__)
#include "Template_Engine_Dialog.inl"
#endif

BEGIN_MESSAGE_MAP (Template_Engine_Dialog, CDialog)
  ON_BN_CLICKED (IDC_BROWSE, on_click_browse)
  ON_BN_CLICKED (IDC_GENERATE, on_generate_click)
  ON_BN_CLICKED (IDC_INTERPRET, on_interpret_click)
END_MESSAGE_MAP ()

//
// OnInitDialog
//
BOOL Template_Engine_Dialog::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  if (0 != this->list_)
  {
    typedef std::map <std::string, std::string> map_type;
    map_type::const_iterator
      iter = this->list_->begin (),
      iter_end = this->list_->end ();

    for ( ; iter != iter_end; ++ iter)
      this->interpreter_list_.InsertString (0, iter->first.c_str ());
  }

  return FALSE;
}

//
// DoDataExchange
//
void Template_Engine_Dialog::DoDataExchange (CDataExchange * pDX)
{
  CDialog::DoDataExchange (pDX);

  DDX_Control (pDX, IDC_INTERPRETER, this->interpreter_list_);
  DDX_Control (pDX, IDC_CONFIG, this->config_);

  DDX_CBString (pDX, IDC_INTERPRETER, this->selected_interpeter_);
  DDX_Text (pDX, IDC_CONFIG, this->config_file_);
  DDX_Text (pDX, IDC_PARAMETERS, this->parameters_);

  DDX_Radio (pDX, IDC_GENERATE, this->option_);
}

//
// on_click_browse
//
void Template_Engine_Dialog::on_click_browse (void)
{
  CFileDialog dialog (1,
                      0,
                      0,
                      OFN_PATHMUSTEXIST,
                      0,
                      this,
                      0);

  dialog.GetOFN ().lpstrTitle = "Open template configuration...";

  if (IDOK == dialog.DoModal ())
    this->config_.SetWindowText (dialog.GetPathName ());
}

//
// on_generate_click
//
void Template_Engine_Dialog::on_generate_click (void)
{
  this->GetDlgItem (IDC_INTERPRETER)->EnableWindow (FALSE);
  this->GetDlgItem (IDC_PARAMETERS)->EnableWindow (FALSE);
}

//
// on_generate_click
//
void Template_Engine_Dialog::on_interpret_click (void)
{
  this->GetDlgItem (IDC_INTERPRETER)->EnableWindow (TRUE);
  this->GetDlgItem (IDC_PARAMETERS)->EnableWindow (TRUE);
}
