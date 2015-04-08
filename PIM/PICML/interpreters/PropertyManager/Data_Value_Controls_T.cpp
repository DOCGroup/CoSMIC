#include "game/mga/Attribute.h"

void DDX_Text (CDataExchange * , int , GAME::Mga::Reference & );

//
// PICML_Simple_Data_Value_Control
//
template <typename CONTROL>
PICML_Simple_Data_Value_Control <CONTROL>::PICML_Simple_Data_Value_Control (void)
{

}

//
// ~PICML_Simple_Data_Value_Control
//
template <typename CONTROL>
PICML_Simple_Data_Value_Control <CONTROL>::~PICML_Simple_Data_Value_Control (void)
{

}

//
// create_i
//
template <typename CONTROL>
BOOL PICML_Simple_Data_Value_Control <CONTROL>::
Create (DWORD style, const RECT & rect, CWnd * parent, UINT id)
{
  // Store the control id.
  this->id_ = id;

  // Set the required styles.
  style |= WS_VISIBLE | WS_CHILD;

  // Create the control.
  if (CONTROL::Create (style, rect, parent, id) == FALSE)
    return FALSE;

  // Set the controls font.
  CONTROL::SetFont (parent->GetFont ());
  return TRUE;
}

//
// Destroy
//
template <typename CONTROL>
BOOL PICML_Simple_Data_Value_Control <CONTROL>::Destroy (void)
{
  // Get the text from the control's window.
  CString text;
  CONTROL::GetWindowText (text);

  // Save the text in the value.
  this->value_->attribute ("Value")->string_value (text.GetBuffer ());

  // Destroy the control.
  return CONTROL::DestroyWindow ();
}
