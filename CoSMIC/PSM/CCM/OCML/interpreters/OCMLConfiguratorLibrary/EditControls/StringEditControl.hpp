/**
 * Definition of the string edit control.
 *
 * @file StringEditControl.hpp
 * @author Emre Turkay <turkaye@dre.vanderbilt.edu>
 */

#ifndef STRING_EDIT_CONTROL_HPP
#define STRING_EDIT_CONTROL_HPP

#include <list>
#include <wx/wx.h>
#include "../extern_declarations.hpp"

class StringEditControl;

/// The classes which listens the focus gain/lost events should be derived
/// from this class.
class OCMLConfigurator_API StringEditControlFocusListener
{
public:
  /// When a focus gain event occurs this method is called.
  virtual void string_edit_focus_gain(StringEditControl* control) = 0;
  /// When a focus lost event occurs this method is called.
  virtual void string_edit_focus_lost(StringEditControl* control) = 0;
};

/**
 * String edit control is a single line text input widget which provides
 * focus listener interface. When a focus event occurs, calls the registered
 * listeners.
 */
class OCMLConfigurator_API StringEditControl: public wxTextCtrl
{
public:
  /// WXWindow focus gain event handler.
  void on_focus_gain(wxFocusEvent&);
  /// WXWindow focus lost event handler.
  void on_focus_lost(wxFocusEvent&);

public:
  /// Constructor.
  StringEditControl(wxWindow* parent);
    
  /// Registers the given FocusListener as a focus listener for this widget.
  void add_focus_listener(StringEditControlFocusListener* l);
    
private:
  /// The container for the focus listeners.
  std::list<StringEditControlFocusListener*> focus_listeners_;
    
  // Declares WXWindow event table.
  DECLARE_EVENT_TABLE()
};    

#endif // STRING_EDIT_CONTROL_HPP
