// $Id$

#include "StdAfx.h"
#include "DT_Controls.h"
#include "PICML/Data_Value.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// DDX_Text
//
void DDX_Text (CDataExchange * pDX, int id,  PICML_Data_Value & value)
{
  if (pDX->m_bSaveAndValidate)
  {
    CString str;
    pDX->m_pDlgWnd->GetDlgItemText (id, str);

    value.value (str.GetBuffer ());
  }
  else
  {
    pDX->m_pDlgWnd->SetDlgItemText (id, value.value ().c_str ());
  }
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Data_Value_Control

//
// PICML_Data_Value_Control
//
PICML_Data_Value_Control::PICML_Data_Value_Control (void)
: value_ (0)
{

}

//
// ~PICML_Data_Value_Control
//
PICML_Data_Value_Control::~PICML_Data_Value_Control (void)
{

}

//
// InitControl
//
void PICML_Data_Value_Control::
InitControl (size_t item, PICML_Data_Value * value)
{
  this->item_ = item;
  this->value_ = value;
}

//
// init
//
size_t PICML_Data_Value_Control::item (void) const
{
  return this->item_;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Simple_DT_Control <CEdit>

//
// PICML_Simple_DT_Control
//
PICML_Simple_DT_Control <CEdit>::PICML_Simple_DT_Control (void)
{

}

//
// ~PICML_Simple_DT_Control
//
PICML_Simple_DT_Control <CEdit>::~PICML_Simple_DT_Control (void)
{

}

//
// Create
//
BOOL PICML_Simple_DT_Control <CEdit>::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  // Store the control id.
  this->id_ = id;

  // Set the required styles.
  style |= WS_VISIBLE | WS_CHILD;

  // Create the control.
  if (CEdit::Create (style, rect, parent, id) == FALSE)
    return FALSE;

  // Set the controls font.
  this->SetFont (parent->GetFont ());

  // Set the text in the window.
  this->SetWindowText (this->value_->value ().c_str ());

  // Get the control focus.
  this->SetFocus ();
  return TRUE;
}

//
// Destroy
//
BOOL PICML_Simple_DT_Control <CEdit>::Destroy (void)
{
  // Get the text from the control's window.
  CString text;
  this->GetWindowText (text);

  // Save the text in the value.
  this->value_->value (text.GetBuffer ());

  // Destroy the control.
  return this->DestroyWindow ();
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Boolean_DT_Control

//
// PICML_Boolean_DT_Control
//
PICML_Boolean_DT_Control::PICML_Boolean_DT_Control (void)
{

}

//
// ~PICML_Boolean_DT_Control
//
PICML_Boolean_DT_Control::~PICML_Boolean_DT_Control (void)
{

}

//
// create
//
BOOL PICML_Boolean_DT_Control::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  LOGFONT logfont;
  parent->GetFont ()->GetLogFont (&logfont);
  size_t font_height = abs (logfont.lfHeight);

  CRect combo_rect (rect.left,
                    rect.top,
                    rect.right,
                    rect.bottom + font_height * 4);

  // Update the style.
  style |= CBS_DROPDOWNLIST | CBS_SORT;

  // Create the control.
  if (PICML_Simple_DT_Control <CComboBox>::Create (style, combo_rect, parent, id) == FALSE)
    return FALSE;

  // Insert the default items into the control.
  this->InsertString (-1, "true");
  this->InsertString (-1, "false");

  // Select the current value.
  if (!this->value_->value ().empty ())
    this->SelectString (-1, this->value_->value ().c_str ());

  // Set the current value.
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Enum_DT_Control

//
// PICML_Enum_DT_Control
//
PICML_Enum_DT_Control::PICML_Enum_DT_Control (void)
{

}

//
// ~PICML_Enum_DT_Control
//
PICML_Enum_DT_Control::~PICML_Enum_DT_Control (void)
{

}

//
// create
//
BOOL PICML_Enum_DT_Control::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  // Calculate the size of the control to compensate the list.
  LOGFONT logfont;
  parent->GetFont ()->GetLogFont (&logfont);
  size_t font_height = abs (logfont.lfHeight);

  CRect combo_rect (rect.left,
                    rect.top,
                    rect.right,
                    rect.bottom + font_height * 5);

  // Update the style.
  style |= CBS_DROPDOWNLIST | CBS_SORT;

  if (PICML_Simple_DT_Control <CComboBox>::Create (style, combo_rect, parent, id) == FALSE)
    return FALSE;

  // Populate the control with the enumeration values.
  PICML_Enum_Data_Value * en =
    dynamic_cast <PICML_Enum_Data_Value *> (this->value_);

  std::for_each (en->options ().begin (),
                 en->options ().end (),
                 boost::bind (&CComboBox::InsertString,
                              this,
                              -1,
                              boost::bind (&std::string::c_str,
                                           _1)));

  // Select the current value.
  if (!en->value ().empty ())
    this->SelectString (-1, en->value ().c_str ());

  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_UShort_DT_Control

//
// PICML_UShort_DT_Control
//
PICML_UShort_DT_Control::PICML_UShort_DT_Control (void)
{

}

//
// PICML_UShort_DT_Control
//
PICML_UShort_DT_Control::~PICML_UShort_DT_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Short_DT_Control

//
// PICML_Short_DT_Control
//
PICML_Short_DT_Control::PICML_Short_DT_Control (void)
{

}

//
// PICML_Short_DT_Control
//
PICML_Short_DT_Control::~PICML_Short_DT_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Long_DT_Control

//
// PICML_Long_DT_Control
//
PICML_Long_DT_Control::PICML_Long_DT_Control (void)
{

}

//
// PICML_Long_DT_Control
//
PICML_Long_DT_Control::~PICML_Long_DT_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_ULong_DT_Control

//
// PICML_ULong_DT_Control
//
PICML_ULong_DT_Control::PICML_ULong_DT_Control (void)
{

}

//
// PICML_ULong_DT_Control
//
PICML_ULong_DT_Control::~PICML_ULong_DT_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Char_DT_Control

//
// PICML_Char_DT_Control
//
PICML_Char_DT_Control::PICML_Char_DT_Control (void)
{

}

//
// ~PICML_Char_DT_Control
//
PICML_Char_DT_Control::~PICML_Char_DT_Control (void)
{

}

//
// create
//
BOOL PICML_Char_DT_Control::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  if (PICML_Simple_DT_Control <CEdit>::Create (style, rect, parent, id) == FALSE)
    return FALSE;

  this->SetLimitText (1);
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_String_DT_Control

//
// PICML_String_DT_Control
//
PICML_String_DT_Control::PICML_String_DT_Control (void)
{

}

//
// ~PICML_String_DT_Control
//
PICML_String_DT_Control::~PICML_String_DT_Control (void)
{

}
