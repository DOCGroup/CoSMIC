// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_TextEditor.h
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_TEXTEDITOR_H_
#define _IDL_TEXTEDITOR_H_

#include <afxcmn.h>

/**
 * @class DSL_TextEditor
 *
 * Text editor for the domain-specific language (DSL).
 */
class DSL_TextEditor : public CFrameWnd
{
public:
  /// Default constructor.
  DSL_TextEditor (void);

  /**
   * Initializing constructor. This constructor is necessary because
   * the DocTemplate resets the main windows with this one created
   * by CreateNewFrame (). Apparently, someone assumeded that people
   * would never want to create a template view with in a template
   * view!! Or, there is no documentation on how to do so!!
   */
  DSL_TextEditor (CWnd * parent);

  /// Destructor.
  virtual ~DSL_TextEditor (void);

  // Declare this object as a dynamically created one.
  DECLARE_DYNCREATE (DSL_TextEditor);

  /**
   * Run the window in modal mode.
   */
  int DoModal (void);

  /// Handler for the WM_CLOSE event.
  virtual void OnClose (void);

private:
  // Message map for the window.
  DECLARE_MESSAGE_MAP ();

  /// The parent window, since the other do not work!!
  CWnd * parent_;
};

#endif  // !defined _DSL_TEXTEDITOR_H_
