#include "stdafx.h"
#include "resource.h"
#include "Property_Manager_Dialog.h"

BEGIN_MESSAGE_MAP (PICML_Property_Manager_Dialog, CDialog)

END_MESSAGE_MAP ()

//
// PICML_Property_Manager_Dialog
//
PICML_Property_Manager_Dialog::
PICML_Property_Manager_Dialog (const GAME::Mga::FCO_in prop, CWnd * parent)
: CDialog (IDD_PROPERTY_MANAGER, parent),
  prop_ (prop)
{

}

//
// ~PICML_Property_Manager_Dialog
//
PICML_Property_Manager_Dialog::~PICML_Property_Manager_Dialog (void)
{

}

//
// DoDataExchange
//
void PICML_Property_Manager_Dialog::DoDataExchange (CDataExchange * pDX)
{
  CDialog::DoDataExchange (pDX);
  DDX_Control (pDX, IDC_DATAVALUE, this->listview_);
}

//
// OnInitDialog
//
BOOL PICML_Property_Manager_Dialog::OnInitDialog (void)
{
  // Pass control to the base class.
  CDialog::OnInitDialog ();

  // Set the data value of the list view.
  this->listview_.InitControl ();
  this->listview_.SetProperty (this->prop_);

  return TRUE;
}
