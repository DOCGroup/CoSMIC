// $Id$

#include "stdafx.h"
#include "Data_Value_Controls.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// DDX_Text
//
void DDX_Text (CDataExchange * pDX, int id, PICML::DataValue & value)
{
  if (pDX->m_bSaveAndValidate)
  {
    // We are saving the controls contents. This means we need to
    // get it in string format, and store it in the <value>
    CString str;
    pDX->m_pDlgWnd->GetDlgItemText (id, str);

    value.Value () = str.GetBuffer ();
  }
  else
  {
    // We are not saving the control. We therefore need to store
    // the data value's content in the control.
    std::string v (value.Value ());
    pDX->m_pDlgWnd->SetDlgItemText (id, v.c_str ());
  }
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Data_Value_Control

//
// PICML_Data_Value_Control
//
PICML_Data_Value_Control::PICML_Data_Value_Control (void)
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
InitControl (size_t item, const PICML::DataValue & value)
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
// PICML_Simple_Data_Value_Control <CEdit>

//
// PICML_Simple_Data_Value_Control
//
PICML_Simple_Data_Value_Control <CEdit>::PICML_Simple_Data_Value_Control (void)
{

}

//
// ~PICML_Simple_Data_Value_Control
//
PICML_Simple_Data_Value_Control <CEdit>::~PICML_Simple_Data_Value_Control (void)
{

}

//
// Create
//
BOOL PICML_Simple_Data_Value_Control <CEdit>::
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
  std::string v (this->value_.Value ());
  this->SetWindowText (v.c_str ());

  // Get the control focus.
  this->SetFocus ();
  return TRUE;
}

//
// Destroy
//
BOOL PICML_Simple_Data_Value_Control <CEdit>::Destroy (void)
{
  // Get the text from the control's window.
  CString text;
  this->GetWindowText (text);

  // Save the text in the value.
  this->value_.Value () = text.GetBuffer ();

  // Destroy the control.
  return this->DestroyWindow ();
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Boolean_Data_Value_Control

//
// PICML_Boolean_Data_Value_Control
//
PICML_Boolean_Data_Value_Control::PICML_Boolean_Data_Value_Control (void)
{

}

//
// ~PICML_Boolean_Data_Value_Control
//
PICML_Boolean_Data_Value_Control::~PICML_Boolean_Data_Value_Control (void)
{

}

//
// create
//
BOOL PICML_Boolean_Data_Value_Control::
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
  if (PICML_Simple_Data_Value_Control <CComboBox>::Create (style, combo_rect, parent, id) == FALSE)
    return FALSE;

  // Insert the default items into the control.
  this->InsertString (-1, "true");
  this->InsertString (-1, "false");

  // Select the current value.
  std::string s (this->value_.Value ());

  if (!s.empty ())
    this->SelectString (-1, s.c_str ());

  // Set the current value.
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Enum_Data_Value_Control

//
// PICML_Enum_Data_Value_Control
//
PICML_Enum_Data_Value_Control::PICML_Enum_Data_Value_Control (void)
{

}

//
// ~PICML_Enum_Data_Value_Control
//
PICML_Enum_Data_Value_Control::~PICML_Enum_Data_Value_Control (void)
{

}

//
// create
//
BOOL PICML_Enum_Data_Value_Control::
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

  if (PICML_Simple_Data_Value_Control <CComboBox>::Create (style, combo_rect, parent, id) == FALSE)
    return FALSE;

  // Populate the control with the enumeration values.
  PICML::Enum e = PICML::Enum::Cast (this->value_.ref ());
  std::vector <PICML::EnumValue> evs = e.EnumValue_children ();

  std::for_each (evs.begin (),
                 evs.end (),
                 boost::bind (&PICML::EnumValue::Accept, 
                              _1,
                              boost::ref (*this)));

  // Select the current value.
  std::string v = this->value_.Value ();

  if (!v.empty ())
    this->SelectString (-1, v.c_str ());

  return TRUE;
}

//
// Visit_EnumValue
//
void PICML_Enum_Data_Value_Control::
Visit_EnumValue (const PICML::EnumValue & ev)
{
  std::string s (ev.name ());
  this->InsertString (-1, s.c_str ());
}

///////////////////////////////////////////////////////////////////////////////
// PICML_UShort_Data_Value_Control

//
// PICML_UShort_Data_Value_Control
//
PICML_UShort_Data_Value_Control::PICML_UShort_Data_Value_Control (void)
{

}

//
// PICML_UShort_Data_Value_Control
//
PICML_UShort_Data_Value_Control::~PICML_UShort_Data_Value_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Short_Data_Value_Control

//
// PICML_Short_Data_Value_Control
//
PICML_Short_Data_Value_Control::PICML_Short_Data_Value_Control (void)
{

}

//
// PICML_Short_Data_Value_Control
//
PICML_Short_Data_Value_Control::~PICML_Short_Data_Value_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Long_Data_Value_Control

//
// PICML_Long_Data_Value_Control
//
PICML_Long_Data_Value_Control::PICML_Long_Data_Value_Control (void)
{

}

//
// PICML_Long_Data_Value_Control
//
PICML_Long_Data_Value_Control::~PICML_Long_Data_Value_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_ULong_Data_Value_Control

//
// PICML_ULong_Data_Value_Control
//
PICML_ULong_Data_Value_Control::PICML_ULong_Data_Value_Control (void)
{

}

//
// PICML_ULong_Data_Value_Control
//
PICML_ULong_Data_Value_Control::~PICML_ULong_Data_Value_Control (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// PICML_Char_Data_Value_Control

//
// PICML_Char_Data_Value_Control
//
PICML_Char_Data_Value_Control::PICML_Char_Data_Value_Control (void)
{

}

//
// ~PICML_Char_Data_Value_Control
//
PICML_Char_Data_Value_Control::~PICML_Char_Data_Value_Control (void)
{

}

//
// create
//
BOOL PICML_Char_Data_Value_Control::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  if (PICML_Simple_Data_Value_Control <CEdit>::Create (style, rect, parent, id) == FALSE)
    return FALSE;

  this->SetLimitText (1);
  return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// PICML_String_Data_Value_Control

//
// PICML_String_Data_Value_Control
//
PICML_String_Data_Value_Control::PICML_String_Data_Value_Control (void)
{

}

//
// ~PICML_String_Data_Value_Control
//
PICML_String_Data_Value_Control::~PICML_String_Data_Value_Control (void)
{

}
