#ifndef STRING_OPTION_EDITOR_HPP
#define STRING_OPTION_EDITOR_HPP

#include "OptionEditor.hpp"
#include "../EditControls/StringEditControl.hpp"
#include "../Options/BasicOptions.hpp"

class StringOptionEditor;

class StringOptionEditorFocusListener
{
public:
  virtual void string_editor_focused(StringOptionEditor* editor) = 0;
};
    
class StringOptionEditor: public OptionEditor,
			  public StringEditControlFocusListener
{
public:
  StringOptionEditor(wxWindow* parent, StringOption* option);
  virtual ~StringOptionEditor();
    
  void add_focus_listener(StringOptionEditorFocusListener* l);
    
  virtual void string_edit_focus_gain(StringEditControl* control);
  virtual void string_edit_focus_lost(StringEditControl* control);
  virtual void clear_button_clicked(ClearButton* control);

private:
  StringEditControl* editor_;

  std::list<StringOptionEditorFocusListener*> focus_listeners_;
};

#endif // STRING_OPTION_EDITOR_HPP
