// $Id$

#include "stdafx.h"
#include "Name_Dialog.h"
#include "resource.h"

#if !defined (__GAME_INLINE__)
#include "Name_Dialog.inl"
#endif

namespace GAME
{
namespace Dialogs
{

//
// Name_Dialog
//
Name_Dialog::
Name_Dialog (Mga::Object_in obj, CWnd * parent)
: CDialog (IDD_GAME_NAME_DIALOG, parent),
  obj_ (obj)
{

}

//
// OnInitDialog
//
BOOL Name_Dialog::OnInitDialog (void)
{
  std::string title = this->obj_->meta ()->name () + " Name";
  this->SetWindowTextA (title.c_str ());

  return FALSE;
}

//
// DoDataExchange
//
void Name_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);
  CString name;

  if (pDX->m_bSaveAndValidate)
  {
    DDX_Text (pDX, IDC_NAME, name);
    this->obj_->name (name.GetBuffer ());
  }
  else
  {
    name = this->obj_->name ().c_str ();
    DDX_Text (pDX, IDC_NAME, name);
  }
}

}
}
