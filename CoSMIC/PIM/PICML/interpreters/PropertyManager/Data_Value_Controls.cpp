// $Id$

#include "stdafx.h"
#include "Data_Value_Controls.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"

#include "boost/bind.hpp"

#include <algorithm>

namespace attr
{
  static const std::string Value ("Value");
}

//
// DDX_Text
//
void DDX_Text (CDataExchange * pDX, int id, GAME::Mga::Reference & value)
{
  GAME::Mga::Attribute attr = value->attribute (attr::Value);

  if (pDX->m_bSaveAndValidate)
  {
    CString str;
    pDX->m_pDlgWnd->GetDlgItemText (id, str);

    attr->string_value (str.GetBuffer ());
  }
  else
  {
    pDX->m_pDlgWnd->SetDlgItemText (id, attr->string_value ().c_str ());
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
void PICML_Data_Value_Control::InitControl (const GAME::Mga::FCO_in value)
{
  this->value_ = value;
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
  const std::string v (this->value_->attribute (attr::Value)->string_value ());
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
  this->value_->attribute (attr::Value)->string_value (text.GetBuffer ());

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
  std::string s (this->value_->attribute (attr::Value)->string_value ());

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
  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (this->value_);
  GAME::Mga::Model e = GAME::Mga::Model::_narrow (ref->refers_to ());
  std::vector <GAME::Mga::Atom> values;

  if (e->children ("EnumValue", values))
    std::for_each (values.begin (),
                   values.end (),
                   boost::bind (&PICML_Enum_Data_Value_Control::visit_enum_value,
                                this,
                                _1));

  // Select the current value.
  const std::string selection =
    this->value_->attribute (attr::Value)->string_value ();

  if (!selection.empty ())
    this->SelectString (-1, selection.c_str ());

  return TRUE;
}

//
// Visit_EnumValue
//
void PICML_Enum_Data_Value_Control::
visit_enum_value (const GAME::Mga::Atom & ev)
{
  this->InsertString (-1, ev->name ().c_str ());
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
// Create
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

//
// Create
//
BOOL PICML_String_Data_Value_Control::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  // Make sure that auto scrolling is enabled. Otherwise, uses will
  // not be able to input more characters than can currently be
  // viewed.
  style |= ES_AUTOHSCROLL;

  return PICML_Simple_Data_Value_Control <CEdit>::Create (style,
                                                          rect,
                                                          parent,
                                                          id);
}
