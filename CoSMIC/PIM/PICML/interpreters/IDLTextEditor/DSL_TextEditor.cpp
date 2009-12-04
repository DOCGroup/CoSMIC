// $Id$

#include "StdAfx.h"
#include "DSL_TextEditor.h"

IMPLEMENT_DYNCREATE (DSL_TextEditor, CFrameWnd);

BEGIN_MESSAGE_MAP (DSL_TextEditor, CFrameWnd)
  ON_WM_CLOSE ()

  ON_COMMAND (ID_APP_EXIT, OnClose)
END_MESSAGE_MAP ()

//
// DSL_TextEditor
//
DSL_TextEditor::DSL_TextEditor (void)
: parent_ (0)
{
}

//
// DSL_TextEditor
//
DSL_TextEditor::DSL_TextEditor (CWnd * parent)
: parent_ (parent)
{
}

//
// ~DSL_TextEditor
//
DSL_TextEditor::~DSL_TextEditor (void)
{

}

//
// OnClose
//
void DSL_TextEditor::OnClose (void)
{
  this->EndModalLoop (0);
}

//
// DoModal
//
int DSL_TextEditor::DoModal (void)
{
  if (0 != this->parent_)
    this->parent_->EnableWindow (0);

  int retval = this->RunModalLoop (MLF_SHOWONIDLE);

  // Hide this window before showing the parent window.
  long flags = SWP_HIDEWINDOW |
               SWP_NOSIZE |
               SWP_NOMOVE |
               SWP_NOACTIVATE |
               SWP_NOZORDER;

  this->SetWindowPos (0, 0, 0, 0, 0, flags);

  // Re-enable the parent window.
  if (0 != this->parent_)
    this->parent_->EnableWindow (1);

  return retval;
}
